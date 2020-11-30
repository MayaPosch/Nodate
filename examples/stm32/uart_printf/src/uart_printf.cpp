// Basic UART & printf() example for Nodate framework (STM32).


#include <usart.h>
#include <timer.h>
#include <io.h>


void uartCallback(char ch) {
	printf("That tickles!\n");
}


int main () {
	// Start UART.
	// Nucleo-F042K6 (STM32F042): USART2 (TX: PA2 (AF1), RX: PA15 (AF1)).
	// USART2 is normally connected to USB (ST-Link) on the Nucleo board.
	//USART::startUart(USART_2, GPIO_PORT_A, 2, 1, GPIO_PORT_A, 15, 1, 9600, uartCallback);
	// USART 2, (TX) PA2:1 [A7], (RX) PA3:1 [A2].
	//USART::startUart(USART_2, GPIO_PORT_A, 2, 1, GPIO_PORT_A, 3, 1, 9600, uartCallback);
	// USART 1, (TX) PA9:1 [D1], (RX) PA10:1 [D0].
	USART::startUart(USART_1, GPIO_PORT_A, 9, 1, GPIO_PORT_A, 10, 1, 9600, uartCallback);
	
	const uint8_t led_pin = 3; // Nucleo-f042k6: Port B, pin 3.
	const GPIO_ports led_port = GPIO_PORT_B;
	//const uint8_t led_pin = 13; // STM32F4-Discovery: Port D, pin 13 (orange)
	//const GPIO_ports led_port = GPIO_PORT_D;
	//const uint8_t led_pin = 7; // Nucleo-F746ZG: Port B, pin 7 (blue)
	//const GPIO_ports led_port = GPIO_PORT_B;
	
	// Set up stdout.
	IO::setStdOutTarget(USART_1);
	
	GPIO gpio;
	Timer timer;
	
	// Set the pin mode on the LED pin.
	gpio.set_output(led_port, led_pin, GPIO_PULL_UP);
	gpio.write(led_port, led_pin, GPIO_LEVEL_LOW);
	
	printf("Hello.\n");
	timer.delay(1000);
	printf("I'm an MCU.\n");
	timer.delay(1000);
	
	while (1) {
		// The interrupt handler will handle things from here.
		
		gpio.write(led_port, led_pin, GPIO_LEVEL_HIGH);
		timer.delay(1000);
		gpio.write(led_port, led_pin, GPIO_LEVEL_LOW);
		timer.delay(1000);
	}
	
	return 0;
}
