/*
	cmsis_rtos - Header file for CMSIS-RTOS module in Nodate.
	
	Features:
			- Provides access to the FreeRTOS library using CMSIS-RTOS APIs.
			
	Notes:
			- 
			
	2021/04/09 - Maya Posch
*/


#include "cmsis_rtos.h"
#include <cmsis_os.h> 


void CmsisRTOS::startTasks(void const* argument) {
	//
	CmsisRTOS_config* config = (CmsisRTOS_config*) argument;
	
	if (config->useDHCP) { 
		LwIP::init(); 
	}
	else {
		LwIP::init(config->ipv4, config->netmask, config->gateway);
	}
	
	// Call the custom callback if defined.
	if (config->cb) { config->cb(); }
	
	if (config->useDHCP) {
		osThreadDef(DHCP, LwIP::dhcpThread, osPriorityBelowNormal, 0, configMINIMAL_STACK_SIZE * 2);
		osThreadCreate (osThread(DHCP), 0);
	}
}


bool CmsisRTOS::start(CmsisRTOS_config &config) {
	// Create thread to configure the RTOS & start tasks like LwIP configuration.
	osThreadDef(Start, startTasks, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 5);
	osThreadCreate (osThread(Start), (void*) &config);
	
	
	return true;
}


/* bool CmsisRTOS::startWithLwIP(bool dhcp, RtosInitCallback cb) {
	//
	osThreadDef(Start, StartLwIP, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 5);
	osThreadCreate (osThread(Start), NULL);
	
	// Init LwIP.
	LwIP::init(dhcp);
	
	// Call the custom callback if defined.
	if (cb) { cb(); }
	
	// Start the scheduler.
	osKernelStart();
	
	return true;
} */


/* bool CmsisRTOS::startWithLwIP(ipv4_address ipv4, ipv4_address netmask, ipv4_address gateway, RtosInitCallback cb) {
	//
	osThreadDef(Start, StartLwIP, osPriorityNormal, 0, configMINIMAL_STACK_SIZE * 5);
	osThreadCreate (osThread(Start), NULL);
	
	// Init LwIP.
	LwIP::init(ipv4, netmask, gateway);
	
	// Call the custom callback if defined.
	if (cb) { cb(); }
	
	// Start the scheduler.
	osKernelStart();
	
	return true;
} */
