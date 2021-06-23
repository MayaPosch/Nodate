/*
	lwip.cpp - Implementation file for the LwIP library module.
	
	2021/04/08, Maya Posch
*/


#include "lwip.h"

#include <nodate.h>

#include <cstring>

#include <cmsis_os.h>

#include <lwip/dhcp.h>
#include <lwip/err.h>
#include <netif/ethernet.h>
#include <netif/etharp.h>


// Static initialisations.
bool LwIP::initialized = false;
struct netif LwIP::gnetif;
DHCP_state LwIP::dhcp_state = DHCP_OFF;
const uint8_t LwIP::dhcp_max_tries = 5;
ip_addr_t LwIP::ipv4;
ip_addr_t LwIP::netmask;
ip_addr_t LwIP::gateway;
osSemaphoreId LwIP::rxSemaphore = 0;


// LwIP sys_now() implementation.
extern "C" {
uint32_t sys_now(void) {
	McuCore::getSysTick();
	
	return 0;
}
}


// --- INIT ---
// Initialise the LwIP library for DHCP mode in MT OS mode.
bool LwIP::init() {
	if (initialized) { return false; }
	
	// Create TCP/IP stack thread.
	tcpip_init(0, 0);
  
	// Set up LwIP stack.
	ip_addr_set_zero_ip4(&ipv4);
	ip_addr_set_zero_ip4(&netmask);
	ip_addr_set_zero_ip4(&gateway);
	
	// Add the network interface.
	netif_add(&gnetif, &ipv4, &netmask, &gateway, NULL, &ethernetif_init, &tcpip_input);
  
	// Registers the default network interface.
	netif_set_default(&gnetif);
  
	if (netif_is_link_up(&gnetif)) {
		// When the netif is fully configured this function must be called.
		netif_set_up(&gnetif);
	}
	else {
		// The netif link is down.
		netif_set_down(&gnetif);
	}
	
	initialized = true;
	
	return true;
}


// Initialise the LwIP library for a static address in MT OS mode.
bool LwIP::init(ipv4_address ipv4, ipv4_address netmask, ipv4_address gateway) {
	if (initialized) { return false; }
	
	// Create TCP/IP stack thread.
	tcpip_init(0, 0);
  
	// Set up LwIP stack.
	IP_ADDR4(&LwIP::ipv4, ipv4.ip0, ipv4.ip1, ipv4.ip2, ipv4.ip3);
	IP_ADDR4(&LwIP::netmask, netmask.ip0, netmask.ip1, netmask.ip2, netmask.ip3);
	IP_ADDR4(&LwIP::gateway, gateway.ip0, gateway.ip1, gateway.ip2, gateway.ip3);
	
	// Add the network interface.
	netif_add(&gnetif, &LwIP::ipv4, &LwIP::netmask, &LwIP::gateway, 0, &ethernetif_init, &tcpip_input);
  
	// Registers the default network interface.
	netif_set_default(&gnetif);
  
	if (netif_is_link_up(&gnetif)) {
		// When the netif is fully configured this function must be called.
		netif_set_up(&gnetif);
	}
	else {
		// The netif link is down.
		netif_set_down(&gnetif);
	}
	
	initialized = true;
	
	return true;
}


void LwIP::setStaticAddress(ipv4_address ipv4, ipv4_address netmask, ipv4_address gateway) {
	IP_ADDR4(&LwIP::ipv4, ipv4.ip0, ipv4.ip1, ipv4.ip2, ipv4.ip3);
	IP_ADDR4(&LwIP::netmask, netmask.ip0, netmask.ip1, netmask.ip2, netmask.ip3);
	IP_ADDR4(&LwIP::gateway, gateway.ip0, gateway.ip1, gateway.ip2, gateway.ip3);
}


// --- DHCP THREAD ---
void LwIP::dhcpThread(void const* argument) {
	struct dhcp* dhcp;
	while (1) {
		switch (dhcp_state) {
			case DHCP_START: {
				ip_addr_set_zero_ip4(&gnetif.ip_addr);
				ip_addr_set_zero_ip4(&gnetif.netmask);
				ip_addr_set_zero_ip4(&gnetif.gw);       
				dhcp_start(&gnetif);
				dhcp_state = DHCP_WAIT_ADDRESS;
			}
			break;
			case DHCP_WAIT_ADDRESS: {                
				if (dhcp_supplied_address(&gnetif)) {
					dhcp_state = DHCP_ADDRESS_ASSIGNED;
				}
				else {
					dhcp = (struct dhcp*) netif_get_client_data(&gnetif, LWIP_NETIF_CLIENT_DATA_INDEX_DHCP);
		
					// DHCP time-out.
					if (dhcp->tries > dhcp_max_tries) {
						dhcp_state = DHCP_TIMEOUT;
				
						// Stop DHCP
						dhcp_stop(&gnetif);
				
						// Use the static address as fallback.
						netif_set_addr(&gnetif, ip_2_ip4(&ipv4), ip_2_ip4(&netmask), ip_2_ip4(&gateway));
					}
					else {
						// No time-out.
					}
				}
			}
			
			break;
			case DHCP_LINK_DOWN: {
				// Stop DHCP.
				dhcp_stop(&gnetif);
				dhcp_state = DHCP_OFF; 
			}
			break;
			default: break;
		}
    }
    
    // wait 250 ms.
    osDelay(250);
}


#define IFNAME0 's'
#define IFNAME1 't'


err_t LwIP::ethernetif_init(struct netif* netif) {
	LWIP_ASSERT("netif != NULL", (netif != 0));

#if LWIP_NETIF_HOSTNAME
	// Initialize interface hostname.
	netif->hostname = "lwip";
#endif

	netif->name[0] = IFNAME0;
	netif->name[1] = IFNAME1;

	/* We directly use etharp_output() here to save a function call.
	* You can instead declare your own function an call etharp_output()
	* from it if you have to do some checks before sending (e.g. if link
	* is available...) */
	netif->output = etharp_output;
	netif->linkoutput = LwIP::low_level_output;

	/* initialize the hardware */
	low_level_init(netif);

	return ERR_OK;
}


/* Stack size of the interface thread */
#define INTERFACE_THREAD_STACK_SIZE            ( 350 )

extern "C" {
void ETH_RxCompleteCallback() {
	osSemaphoreRelease(LwIP::rxSemaphore);
}
}


/**
  * @brief In this function, the hardware should be initialized.
  * Called from ethernetif_init().
  *
  * @param netif the already initialized lwip network interface structure
  *        for this ethernetif
  */
void LwIP::low_level_init(struct netif* netif) {
	Ethernet_RMII rmii;
	rmii.macAddress[0] = MAC_ADDR0;
	rmii.macAddress[1] = MAC_ADDR1;
	rmii.macAddress[2] = MAC_ADDR2;
	rmii.macAddress[3] = MAC_ADDR3;
	rmii.macAddress[4] = MAC_ADDR4;
	rmii.macAddress[5] = MAC_ADDR5;
	rmii.autonegotiate 	= true;
	rmii.speed 			= ETH_SPEED_100M;
	rmii.duplexMode 	= ETH_MODE_FULLDUPLEX;
	rmii.hardwareChecksum 	= true;
	rmii.interruptMode 		= true;
  
	// Configure Ethernet peripheral (GPIOs, clocks, MAC, DMA).
	if (!Ethernet::startEthernet(rmii)) {
		// TODO: handle error.
	}
	
    // Set netif link flag.
    netif->flags |= NETIF_FLAG_LINK_UP;
  
	// Set netif MAC hardware address length.
	netif->hwaddr_len = 6;

	// Set netif MAC hardware address.
	netif->hwaddr[0] =  MAC_ADDR0;
	netif->hwaddr[1] =  MAC_ADDR1;
	netif->hwaddr[2] =  MAC_ADDR2;
	netif->hwaddr[3] =  MAC_ADDR3;
	netif->hwaddr[4] =  MAC_ADDR4;
	netif->hwaddr[5] =  MAC_ADDR5;

	// Set netif maximum transfer unit.
	netif->mtu = 1500;

	// Accept broadcast address and ARP traffic.
	netif->flags |= NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP;

	// create a binary semaphore used for informing ethernetif of frame reception */
	osSemaphoreDef(SEM);
	rxSemaphore = osSemaphoreCreate(osSemaphore(SEM), 1);

	// Create the task which handles the ETH_MAC.
	osThreadDef(EthIf, &LwIP::ethernetif_input, osPriorityRealtime, 0, INTERFACE_THREAD_STACK_SIZE);
	osThreadCreate(osThread(EthIf), netif);
}


/**
  * @brief This function should do the actual transmission of the packet. The packet is
  * contained in the pbuf that is passed to the function. This pbuf
  * might be chained.
  *
  * @param netif the lwip network interface structure for this ethernetif
  * @param p the MAC packet to send (e.g. IP packet including MAC addresses and type)
  * @return ERR_OK if the packet could be sent
  *         an err_t value if the packet couldn't be sent
  *
  * @note Returning ERR_MEM here if a DMA queue of your MAC is full can lead to
  *       strange results. You might consider waiting for space in the DMA queue
  *       to become available since the stack doesn't retry to send a packet
  *       dropped because of memory failure (except for the TCP timers).
  */
err_t LwIP::low_level_output(struct netif* netif, struct pbuf* pbuf_start) {
	//err_t errval;
	
	// Allocate a new buffer to copy the pbuf buffer data into.
	uint8_t* buffer = (uint8_t*) malloc(pbuf_start->tot_len);
	if (buffer == 0) {
		// TODO: report error.
		return ERR_USE;
	}
	
	// Fill buffer.
	pbuf* pbuf_idx;
	uint32_t offset = 0;
	for (pbuf_idx = pbuf_start; pbuf_idx != 0; pbuf_idx = pbuf_idx->next) {
		memcpy(buffer + offset, pbuf_idx->payload, pbuf_idx->len);
		offset += pbuf_idx->len;
	}
		
	// Send buffer data.
	if (!Ethernet::sendData(buffer, pbuf_start->tot_len)) {
		return ERR_USE;
	}
	
	// Delete buffer.
	free(buffer);
	
	return ERR_OK;
}

/**
  * @brief Should allocate a pbuf and transfer the bytes of the incoming
  * packet from the interface into the pbuf.
  *
  * @param netif the lwip network interface structure for this ethernetif
  * @return a pbuf filled with the received packet (including MAC header)
  *         NULL on memory error
  */
struct pbuf* LwIP::low_level_input(struct netif* netif) {
	uint32_t len = 0;
	uint8_t* buffer;
	if (!Ethernet::receiveData(buffer, len)) {
		// TODO: report error.
		return 0;
	}
	
	// Allocate pbuf instances.
	pbuf* pbuf_start = 0, *pbuf_idx = 0;
	if (len > 0) {
		// We allocate a pbuf chain of pbufs from the Lwip buffer pool 
		pbuf_start = pbuf_alloc(PBUF_RAW, len, PBUF_POOL);
	}
	
	if (!pbuf_start) {
		// TODO: report error.
		return 0;
	}
	
	// Copy the buffer data into pbuf instances.
	uint32_t bytesLeft = len;
	uint32_t offset = 0;
	for (pbuf_idx = pbuf_start; pbuf_idx != 0; pbuf_idx = pbuf_idx->next) {
		if (bytesLeft > ETH_RX_BUF_SIZE) {
			memcpy(pbuf_idx->payload, buffer + offset, ETH_RX_BUF_SIZE);
			bytesLeft -= ETH_RX_BUF_SIZE;
			offset += ETH_RX_BUF_SIZE;
		}
		else {
			memcpy(pbuf_idx->payload, buffer + offset, bytesLeft);
			offset += bytesLeft;
			bytesLeft = 0;
		}
	}
  
	// Free the buffer.
	free(buffer);
	
	return pbuf_start;
}


/* The time to block waiting for input. */
#define TIME_WAITING_FOR_INPUT                 ( osWaitForever )


/**
  * @brief This function is the ethernetif_input task, it is processed when a packet 
  * is ready to be read from the interface. It uses the function low_level_input() 
  * that should handle the actual reception of bytes from the network
  * interface. Then the type of the received packet is determined and
  * the appropriate input function is called.
  *
  * @param netif the lwip network interface structure for this ethernetif
  */
void LwIP::ethernetif_input(void const* argument) {
	struct pbuf* p;
	struct netif* netif = (struct netif*) argument;
  
	while (1) {
		if (osSemaphoreWait(rxSemaphore, TIME_WAITING_FOR_INPUT) == osOK) {
			do {
				LOCK_TCPIP_CORE();
				p = low_level_input(netif);
				if (p != 0) {
					if (netif->input(p, netif) != ERR_OK) {
						pbuf_free(p);
					}
				}

				UNLOCK_TCPIP_CORE();
			}
			while(p != 0);
		}
	}
}
