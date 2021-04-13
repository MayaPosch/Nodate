/*
	lwip.h - Header file for the LwIP library module.
	
	2021/04/08, Maya Posch
*/


#ifndef NODATE_LWIP_H
#define NODATE_LWIP_H

#include <common.h>

#include "LwIP/src/include/lwip/netif.h"
#include "LwIP/src/include/lwip/tcpip.h"


// MAC ADDRESS: MAC_ADDR0:MAC_ADDR1:MAC_ADDR2:MAC_ADDR3:MAC_ADDR4:MAC_ADDR5.
// FIXME: make definable.
#define MAC_ADDR0   2U
#define MAC_ADDR1   0U
#define MAC_ADDR2   0U
#define MAC_ADDR3   0U
#define MAC_ADDR4   0U
#define MAC_ADDR5   0U


struct ipv4_address {
	uint8_t ip0;
	uint8_t ip1;
	uint8_t ip2;
	uint8_t ip3;
};


enum DHCP_state {
	DHCP_OFF 				= 0,
	DHCP_START              = 1,
	DHCP_WAIT_ADDRESS       = 2,
	DHCP_ADDRESS_ASSIGNED	= 3,
	DHCP_TIMEOUT    		= 4,
	DHCP_LINK_DOWN         	= 5
};


class LwIP {
	static bool initialized;
	static struct netif gnetif;
	static DHCP_state dhcp_state;
	static const uint8_t dhcp_max_tries;
	static ip_addr_t ipv4;
	static ip_addr_t netmask;
	static ip_addr_t gateway;
	static osSemaphoreId s_xSemaphore;
	
	static err_t ethernetif_init(struct netif* netif);
	static void low_level_init(struct netif* netif);
	static err_t low_level_output(struct netif* netif, struct pbuf* p);
	static void ethernetif_input(void const* argument);
	static struct pbuf* low_level_input(struct netif* netif);
	
public:
	static bool init();
	static bool init(ipv4_address ipv4, ipv4_address netmask, ipv4_address gateway);
	static void setStaticAddress(ipv4_address ipv4, ipv4_address netmask, ipv4_address gateway);
	
	static void dhcpThread(void const* argument);
};


#endif
