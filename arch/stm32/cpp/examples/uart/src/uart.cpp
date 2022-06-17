// Basic UART example for Nodate framework (STM32).

#include <nodate.h>


volatile bool led_on = false;
USART_devices usartTarget = USART_1;


void uartCallback(char ch) {
	// Copy character into send buffer.
	USART::sendUart(USART_2, ch);
	//USART::sendUart(usartTarget, ch);
	
	led_on = !led_on;
}


int main () {
	// Nucleo-F042K6 (STM32F042): USART2 (TX: PA2 (AF1), RX: PA15 (AF1)).
	// USART2 is normally connected to USB (ST-Link) on the Nucleo board.
	//USART::startUart(USART_2, GPIO_PORT_A, 2, 1, GPIO_PORT_A, 15, 1, 9600, uartCallback);
	// USART 2, (TX) PA2:1 [A7], (RX) PA3:1 [A2].
	//USART::startUart(USART_2, GPIO_PORT_A, 2, 1, GPIO_PORT_A, 3, 1, 9600, uartCallback);
	// USART 1, (TX) PA9:1 [D1], (RX) PA10:1 [D0].
	//USART::startUart(USART_1, GPIO_PORT_A, 9, 1, GPIO_PORT_A, 10, 1, 9600, uartCallback);
	// USART 1, (TX) PB6:0 [D5], (RX) PB7:0 [D4].
	//USART::startUart(USART_1, GPIO_PORT_B, 6, 0, GPIO_PORT_B, 7, 0, 9600, uartCallback);
	// STM32F103: USART 1, PB6:0 (TX), PB7:0 (RX).
	//USART::startUart(USART_1, GPIO_PORT_B, 6, 0, GPIO_PORT_B, 7, 0, 9600, uartCallback);
	
	// 1. Set up UART
	USART_def& ud = boardUSARTs[1];
	usartTarget = ud.usart;
	bool ret = USART::startUart(ud.usart, ud.tx[0].port, ud.tx[0].pin, ud.tx[0].af, 
								ud.rx[0].port, ud.rx[0].pin, ud.rx[0].af, 9600, uartCallback);
								
	if (!ret) {
		while (1) { }
	}
	
	// 2. Set up LED.
	uint8_t 	led_pin;
	GPIO_ports 	led_port;
	//bool 		led_iterate = false;
	uint32_t 	led_idx = 0;
	if (boardLEDs_count > 0) {
		//if (boardLEDs_count > 1) { led_iterate = true; led_idx = 1; }
		led_pin = boardLEDs[led_idx].pin.pin;
		led_port = boardLEDs[led_idx].pin.port;
	}
	else {
		//led_pin = 3; // Nucleo-f042k6: Port B, pin 3.
		//led_port = GPIO_PORT_B;
		//led_pin = 13; // STM32F4-Discovery: Port D, pin 13 (orange)
		//led_port = GPIO_PORT_D;
		//led_pin = 7; // Nucleo-F746ZG: Port B, pin 7 (blue)
		//led_port = GPIO_PORT_B;
		//led_pin = 13;	// Blue Pill: Port C, pin 13.
		//led_port = GPIO_PORT_C;
		//led_pin = 13;	// Otter Pill: Port B, pin 13.
		//led_port = GPIO_PORT_B;
		led_pin = 9;	// STM32F0-Discovery (PC9, green).
		led_port = GPIO_PORT_C;
		//led_pin = 1;	// Maple Mini
		//led_port = GPIO_PORT_B;
	}
		
	// Set the pin mode on the LED pin.
	GPIO::set_output(led_port, led_pin, GPIO_PULL_UP);
	GPIO::write(led_port, led_pin, GPIO_LEVEL_LOW);
	
	char ch = 'a';
	if (!USART::sendUart(usartTarget, ch)) {
		while (1) { }
	}
	
	while (1) {
		// The interrupt handler will handle things from here.
		
		
		// The LED is used to indicate reception of data.
		if (led_on) {
			GPIO::write(led_port, led_pin, GPIO_LEVEL_HIGH);
		}
		else {
			GPIO::write(led_port, led_pin, GPIO_LEVEL_LOW);
		}
	}
	
	return 0;
}
