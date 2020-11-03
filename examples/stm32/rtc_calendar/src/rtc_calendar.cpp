/*
	rtc_calendar.cpp - Nodate STM32 RTC Calendar example.
	
*/


#include <rtc.h>
#include <usart.h>
#include <io.h>
#include <timer.h>


void uartCallback(char ch) {
	// Copy character into send buffer.
	USART::sendUart(USART_2, ch);
	//USART::sendUart(USART_1, ch);
}


int main() {
	Timer timer;
	
	// Start UART.
	// Nucleo-F042K6 (STM32F042): USART2 (TX: PA2 (AF1), RX: PA15 (AF1)).
	// USART2 is normally connected to USB (ST-Link) on the Nucleo board.
	//USART::startUart(USART_2, GPIO_PORT_A, 2, 1, GPIO_PORT_A, 15, 1, 9600, uartCallback);
	// USART 2, (TX) PA2:1 [A7], (RX) PA3:1 [A2].
	//USART::startUart(USART_2, GPIO_PORT_A, 2, 1, GPIO_PORT_A, 3, 1, 9600, uartCallback);
	// USART 1, (TX) PA9:1 [D1], (RX) PA10:1 [D0].
	//USART::startUart(USART_1, GPIO_PORT_A, 9, 1, GPIO_PORT_A, 10, 1, 9600, uartCallback);
	// USART 1, (TX) PB6:0 [D5], (RX) PB7:0 [D4].
	//USART::startUart(USART_1, GPIO_PORT_B, 6, 0, GPIO_PORT_B, 7, 0, 9600, uartCallback);
	
	// STM32F4-Discovery (STM32F407).
	// USART2, (TX) PA2:7, (RX) PA3:7.
	USART::startUart(USART_2, GPIO_PORT_A, 2, 7, GPIO_PORT_A, 3, 7, 9600, uartCallback);
	
	// Set up stdout.
	IO::setStdOutTarget(USART_2);
	
	printf("Starting RTC Calendar example...\n");
	
	// Start RTC
	Rtc::enableRTC();
	
	// Wait 1 second to give the RTC time to start.
	timer.delay(1000);
	
	// Get time.
	RtcTime time;
	Rtc::getTime(time);
	
	// Format and send on UART.
	printf("Time: %d%d:%d%d:%d%d\n", time.hour_tens, time.hour_units, time.minute_tens, 
									time.minute_units, time.second_tens, time.second_units);
						
	// Wait 10 seconds.
	timer.delay(10000);
	
	// Check time again.
	Rtc::getTime(time);
	printf("Time: %d%d:%d%d:%d%d\n", time.hour_tens, time.hour_units, time.minute_tens, 
									time.minute_units, time.second_tens, time.second_units);
									
	printf("Done.\n");
	
	while(1) {
		//
	}
	
	return 0;
}
