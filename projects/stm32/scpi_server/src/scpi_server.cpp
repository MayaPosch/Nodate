/*
	scpi_server.cpp - Basic SCPI server based on libscpi
	
	Revision 0.
	
	Features:
			- Uses LibSCPI for parsing and handling of SCPI responses.
			- Uses FreeRTOS for multi-threading support.
			- Uses lwIP for TCP/IP networking access.
			
	2021/02/09, Maya Posch
*/


#include <nodate.h>
//#include <freertos/FreeRTOS/Source/include/FreeRTOS.h>
//#include <cmsis_os.h>
#include <cmsis_rtos.h>
//#include <LwIP/src/include/lwip/netif.h>
//#include <LwIP/src/include/lwip/tcpip.h>
#include <lwip.h>
//#include <libscpi/libscpi.h>
extern "C" {
#include "scpi_server.h"
}


void uartCallback(char ch) {
	// Copy character into send buffer.
	//USART::sendUart(USART_2, ch);
	USART::sendUart(USART_3, ch);
	//USART::sendUart(USART_1, ch);
}

//static void startThread(void const* argument);
void startTasks() {
	//
	scpi_server_init();
}


int main() {
	// 1. Hardware configuration.
	// We wish to set up the UART for debug output, and a LED to indicate status.
	
	// Start UART.
	// Nucleo-F042K6 (STM32F042): USART2 (TX: PA2 (AF1), RX: PA15 (AF1)).
	// USART2 is normally connected to USB (ST-Link) on the Nucleo board.
	//USART::startUart(USART_2, GPIO_PORT_A, 2, 1, GPIO_PORT_A, 15, 1, 9600, uartCallback);
	// USART 2, (TX) PA2:1 [A7], (RX) PA3:1 [A2].
	//USART::startUart(USART_2, GPIO_PORT_A, 2, 1, GPIO_PORT_A, 3, 1, 9600, uartCallback);
	// USART 1, (TX) PA9:1 [D1], (RX) PA10:1 [D0].
	//USART::startUart(USART_1, GPIO_PORT_A, 9, 1, GPIO_PORT_A, 10, 1, 9600, uartCallback);
	
	// STM32F4-Discovery (STM32F407).
	// USART2, (TX) PA2:7, (RX) PA3:7.
	//USART::startUart(USART_2, GPIO_PORT_A, 2, 7, GPIO_PORT_A, 3, 7, 9600, uartCallback);
	
	// Nucleo-F746ZG.
	// USART3, (TX) PD8:7, (RX) PD9:7.
	USART::startUart(USART_3, GPIO_PORT_D, 8, 7, GPIO_PORT_D, 9, 7, 9600, uartCallback);
	
	//const uint8_t led_pin = 3; // Nucleo-f042k6: Port B, pin 3.
	//const GPIO_ports led_port = GPIO_PORT_B;
	//const uint8_t led_pin = 13; // STM32F4-Discovery: Port D, pin 13 (orange)
	//const GPIO_ports led_port = GPIO_PORT_D;
	const uint8_t led_pin = 7; // Nucleo-F746ZG: Port B, pin 7 (blue)
	const GPIO_ports led_port = GPIO_PORT_B;
	//const uint8_t led_pin = 13;	// Blue Pill: Port C, pin 13.
	//const GPIO_ports led_port = GPIO_PORT_C;
	
	// Set up LwIP and Ethernet.
	// Nucleo-F746ZG Ethernet:
	/* 
		RMII_REF_CLK -------> PA1
		RMII_MDIO ----------> PA2
        RMII_MDC -----------> PC1
        RMII_MII_CRS_DV ----> PA7
        RMII_MII_RXD0 ------> PC4
        RMII_MII_RXD1 ------> PC5
        RMII_MII_RXER ------> PG2
        RMII_MII_TX_EN -----> PG11
        RMII_MII_TXD0 ------> PG13
		RMII_MII_TXD1 ------> PB13
		
		AF: 11
	*/
	Ethernet_RMII eth;
	eth.REF_CLK	= { GPIO_PORT_A, 1, 11 };
	eth.TXD0 	= { GPIO_PORT_G, 13, 11 };
	eth.TXD1 	= { GPIO_PORT_B, 13, 11 };
	eth.TX_EN 	= { GPIO_PORT_G, 11, 11 };
	eth.RXD0 	= { GPIO_PORT_C, 4, 11 };
	eth.RXD1 	= { GPIO_PORT_C, 5, 11 };
	eth.CRS_DV 	= { GPIO_PORT_A, 7, 11 };
	eth.RX_ER 	= { GPIO_PORT_G, 2, 11 };
	eth.MDIO 	= { GPIO_PORT_A, 2, 11 };
	eth.MDC 	= { GPIO_PORT_C, 1, 11 };
	Ethernet::startEthernet(eth);
	
	// 2. Start RTOS with LwIP.
	// 		Our callback is called to start additional tasks.
	CmsisRTOS_config config;
	config.cb = startTasks;
	CmsisRTOS::start(config);
	
	while (1) {
		//
	}
	
	return 1;
}
