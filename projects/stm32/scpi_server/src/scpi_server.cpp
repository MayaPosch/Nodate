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
#include <cmsis_rtos.h>
#include <lwip.h>
extern "C" {
#include "scpi_server.h"
}


void uartCallback(char ch) {
	// Copy character into send buffer.
	USART::sendUart(USART_3, ch);
}

//static void startThread(void const* argument);
void startTasks() {
	//
	scpi_server_init();
}


int main() {
	// 0. Hardware configuration.
	// We wish to set up the UART for debug output, and a LED to indicate status.
	
	// 1. Set up UART
	// Nucleo-F746ZG.
	// USART3, (TX) PD8:7, (RX) PD9:7.
	USART::startUart(USART_3, GPIO_PORT_D, 8, 7, GPIO_PORT_D, 9, 7, 9600, uartCallback);
	
	// Set up stdout.
	IO::setStdOutTarget(USART_3);
	
	// Start SysTick.
	McuCore::initSysTick();
	
	printf("Starting SCPI server...\n");
	
	// 1. Set up LED.
	uint8_t 	led_pin;
	GPIO_ports 	led_port;
	bool		led_enable = true;
	if (boardLEDs_count > 0) {
		led_pin = boardLEDs[0].pin.pin;
		led_port = boardLEDs[0].pin.port;
		
		// Set the pin mode on the LED pin and turn it off.
		GPIO::set_output(led_port, led_pin, GPIO_PULL_UP);
		GPIO::write(led_port, led_pin, GPIO_LEVEL_LOW);
	}
	else {
		led_enable = false;
	}
	
	printf("Start Ethernet...\n");
	
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
	if (!Ethernet::startEthernet(eth)) {
		printf("Starting Ethernet failed...\n");
		while (1) { }
	}
	
	printf("Start LwIP and RTOS...\n");
	
	// 2. Start RTOS with LwIP.
	// 		Our callback is called to start additional tasks.
	CmsisRTOS_config config;
	config.cb = startTasks;
	CmsisRTOS::start(config);
	
	// Light up LED.
	if (led_enable) {
		GPIO::write(led_port, led_pin, GPIO_LEVEL_HIGH);
	}
	
	printf("Ready...\n");
	
	while (1) {
		//
	}
	
	return 1;
}
