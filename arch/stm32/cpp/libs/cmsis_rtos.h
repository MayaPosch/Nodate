/*
	cmsis_rtos - Header file for CMSIS-RTOS module in Nodate.
	
	Features:
			- Provides access to the FreeRTOS library using CMSIS-RTOS APIs.
			
	Notes:
			- 
			
	2021/04/09 - Maya Posch
*/


#ifndef NODATE_CMSIS_RTOS_H
#define NODATE_CMSIS_RTOS_H


#include "lwip.h"


typedef void (*RtosInitCallback)(void);


struct CmsisRTOS_config {
	RtosInitCallback cb = 0;
	bool startLwIP = false;
	bool useDHCP = true;
	ipv4_address ipv4;
	ipv4_address netmask;
	ipv4_address gateway;
};


class CmsisRTOS {
	static void startTasks(void const* argument);
	
public:
	static bool start(CmsisRTOS_config &config);
	//static bool startWithLwIP(bool dhcp = true, RtosInitCallback cb = 0);
	//static bool startWithLwIP(ipv4_address ipv4, ipv4_address netmask, ipv4_address gateway, RtosInitCallback = 0);
};


#endif
