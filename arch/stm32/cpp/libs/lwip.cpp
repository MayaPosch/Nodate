/*
	lwip.cpp - Implementation file for the LwIP library module.
	
	2021/04/08, Maya Posch
*/


#include "lwip.h"

#include <nodate.h>

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
osSemaphoreId LwIP::s_xSemaphore = 0;


// LwIP sys_now() implementation.
extern "C" {
uint32_t sys_now(void) {
	
	// TODO: Implement.
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
	s_xSemaphore = osSemaphoreCreate(osSemaphore(SEM), 1);

	// Create the task which handles the ETH_MAC.
	osThreadDef(EthIf, LwIP::ethernetif_input, osPriorityRealtime, 0, INTERFACE_THREAD_STACK_SIZE);
	osThreadCreate (osThread(EthIf), netif);
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
err_t LwIP::low_level_output(struct netif* netif, struct pbuf* p) {
	//err_t errval;
	struct pbuf* q;
	for (q = p; q != 0; q = q->next) {
		/* if (!Ethernet::sendData(q->payload, )) {
			return ERR_USE;
		} */
		
		// 
	}
		
  
  /*struct pbuf *q;
  uint8_t *buffer = (uint8_t *)(EthHandle.TxDesc->Buffer1Addr);
  __IO ETH_DMADescTypeDef *DmaTxDesc;
  uint32_t framelength = 0;
  uint32_t bufferoffset = 0;
  uint32_t byteslefttocopy = 0;
  uint32_t payloadoffset = 0;

  DmaTxDesc = EthHandle.TxDesc;
  bufferoffset = 0;
  
  // copy frame from pbufs to driver buffers
  for(q = p; q != NULL; q = q->next)
  {
    // Is this buffer available? If not, goto error
    if ((DMATxDscrTab.Status & ETH_DMATXDESC_OWN) != (uint32_t) RESET)
    {
      errval = ERR_USE;
      goto error;
    }
    
    // Get bytes in current lwIP buffer
    byteslefttocopy = q->len;
    payloadoffset = 0;
    
    // Check if the length of data to copy is bigger than Tx buffer size
    while( (byteslefttocopy + bufferoffset) > ETH_TX_BUF_SIZE )
    {
      // Copy data to Tx buffer
      memcpy( (uint8_t*)((uint8_t*)buffer + bufferoffset), (uint8_t*)((uint8_t*)q->payload + payloadoffset), (ETH_TX_BUF_SIZE - bufferoffset) );
      
      // Point to next descriptor
      DmaTxDesc = (ETH_DMADescTypeDef *)(DmaTxDesc->Buffer2NextDescAddr);
      
      // Check if the buffer is available 
      if((DmaTxDesc->Status & ETH_DMATXDESC_OWN) != (uint32_t)RESET)
      {
        errval = ERR_USE;
        goto error;
      }
      
      buffer = (uint8_t *)(DmaTxDesc->Buffer1Addr);
      
      byteslefttocopy = byteslefttocopy - (ETH_TX_BUF_SIZE - bufferoffset);
      payloadoffset = payloadoffset + (ETH_TX_BUF_SIZE - bufferoffset);
      framelength = framelength + (ETH_TX_BUF_SIZE - bufferoffset);
      bufferoffset = 0;
    }
    
    // Copy the remaining bytes
    memcpy( (uint8_t*)((uint8_t*)buffer + bufferoffset), (uint8_t*)((uint8_t*)q->payload + payloadoffset), byteslefttocopy );
    bufferoffset = bufferoffset + byteslefttocopy;
    framelength = framelength + byteslefttocopy;
  }
  
  // Prepare transmit descriptors to give to DMA *
  HAL_ETH_TransmitFrame(&EthHandle, framelength);
  
  errval = ERR_OK;
  
error:
  
  // When Transmit Underflow flag is set, clear it and issue a Transmit Poll Demand to resume transmission 
  if ((EthHandle.Instance->DMASR & ETH_DMASR_TUS) != (uint32_t)RESET)
  {
    // Clear TUS ETHERNET DMA flag
    EthHandle.Instance->DMASR = ETH_DMASR_TUS;
    
    // Resume DMA transmission
    EthHandle.Instance->DMATPDR = 0;
  }
  return errval; */
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
  struct pbuf *p = NULL, *q = NULL;
  uint16_t len = 0;
  uint8_t *buffer;
  /* __IO ETH_DMADescTypeDef *dmarxdesc;
  uint32_t bufferoffset = 0;
  uint32_t payloadoffset = 0;
  uint32_t byteslefttocopy = 0;
  uint32_t i=0;
  
  // get received frame 
  if(HAL_ETH_GetReceivedFrame_IT(&EthHandle) != HAL_OK)
    return NULL;
  
  // Obtain the size of the packet and put it into the "len" variable. 
  len = EthHandle.RxFrameInfos.length;
  buffer = (uint8_t *)EthHandle.RxFrameInfos.buffer;
  
  if (len > 0)
  {
    // We allocate a pbuf chain of pbufs from the Lwip buffer pool 
    p = pbuf_alloc(PBUF_RAW, len, PBUF_POOL);
  }
  
  if (p != NULL)
  {
    dmarxdesc = EthHandle.RxFrameInfos.FSRxDesc;
    bufferoffset = 0;
    
    for(q = p; q != NULL; q = q->next)
    {
      byteslefttocopy = q->len;
      payloadoffset = 0;
      
      // Check if the length of bytes to copy in current pbuf is bigger than Rx buffer size 
      while( (byteslefttocopy + bufferoffset) > ETH_RX_BUF_SIZE )
      {
        // Copy data to pbuf 
        memcpy( (uint8_t*)((uint8_t*)q->payload + payloadoffset), (uint8_t*)((uint8_t*)buffer + bufferoffset), (ETH_RX_BUF_SIZE - bufferoffset));
        
        // Point to next descriptor 
        dmarxdesc = (ETH_DMADescTypeDef *)(dmarxdesc->Buffer2NextDescAddr);
        buffer = (uint8_t *)(dmarxdesc->Buffer1Addr);
        
        byteslefttocopy = byteslefttocopy - (ETH_RX_BUF_SIZE - bufferoffset);
        payloadoffset = payloadoffset + (ETH_RX_BUF_SIZE - bufferoffset);
        bufferoffset = 0;
      }
      
      // Copy remaining data in pbuf 
      memcpy( (uint8_t*)((uint8_t*)q->payload + payloadoffset), (uint8_t*)((uint8_t*)buffer + bufferoffset), byteslefttocopy);
      bufferoffset = bufferoffset + byteslefttocopy;
    }
  }
    
  // Release descriptors to DMA 
  // Point to first descriptor 
  dmarxdesc = EthHandle.RxFrameInfos.FSRxDesc;
  // Set Own bit in Rx descriptors: gives the buffers back to DMA 
  for (i=0; i< EthHandle.RxFrameInfos.SegCount; i++)
  {  
    dmarxdesc->Status |= ETH_DMARXDESC_OWN;
    dmarxdesc = (ETH_DMADescTypeDef *)(dmarxdesc->Buffer2NextDescAddr);
  }
    
  // Clear Segment_Count 
  EthHandle.RxFrameInfos.SegCount =0;
  
  // When Rx Buffer unavailable flag is set: clear it and resume reception 
  if ((EthHandle.Instance->DMASR & ETH_DMASR_RBUS) != (uint32_t)RESET)  
  {
    // Clear RBUS ETHERNET DMA flag 
    EthHandle.Instance->DMASR = ETH_DMASR_RBUS;
    // Resume DMA reception
    EthHandle.Instance->DMARPDR = 0;
  } */
  return p;
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
	struct pbuf *p;
	struct netif *netif = (struct netif *) argument;
  
	for ( ;; ) {
    /*if (osSemaphoreWait( s_xSemaphore, TIME_WAITING_FOR_INPUT)==osOK)
    {
      do
      {
        LOCK_TCPIP_CORE();

        p = low_level_input( netif );
        if (p != NULL)
        {
          if (netif->input( p, netif) != ERR_OK )
          {
            pbuf_free(p);
          }
        }

        UNLOCK_TCPIP_CORE();

      }while(p!=NULL);
    }*/
	}
}
