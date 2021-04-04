// BME280 example for Nodate's STM32 framework.

#include <usart.h>
#include <io.h>
#include <i2c.h>
#include <bme280/bme280.h>

#include "printf.h"


void uartCallback(char ch) {
	// Copy character into send buffer.
	USART::sendUart(USART_2, ch);
	//USART::sendUart(USART_1, ch);
}


int main () {
	// Initialise UART.
	// Nucleo-F042K6 (STM32F042): USART2 (TX: PA2 (AF1), RX: PA15 (AF1)).
	// USART2 is normally connected to USB (ST-Link) on the Nucleo board.
	USART::startUart(USART_2, GPIO_PORT_A, 2, 1, GPIO_PORT_A, 15, 1, 9600, uartCallback);
	// USART 1, (TX) PA9:1 [D1], (RX) PA10:1 [D0].
	//USART::startUart(USART_1, GPIO_PORT_A, 9, 1, GPIO_PORT_A, 10, 1, 9600, uartCallback);
	
	// STM32F4-Discovery (STM32F407): USART2, (TX) PA2:7, (RX) PA3:7.
	//USART::startUart(USART_2, GPIO_PORT_A, 2, 7, GPIO_PORT_A, 3, 7, 9600, uartCallback);
	
	const uint8_t led_pin = 3; // Nucleo-f042k6: Port B, pin 3.
	const GPIO_ports led_port = GPIO_PORT_B;
	//const uint8_t led_pin = 13; // STM32F4-Discovery: Port D, pin 13 (orange)
	//const GPIO_ports led_port = GPIO_PORT_D;
	//const uint8_t led_pin = 7; // Nucleo-F746ZG: Port B, pin 7 (blue)
	//const GPIO_ports led_port = GPIO_PORT_B;
	//const uint8_t led_pin = 13;	// Blue Pill: Port C, pin 13.
	//const GPIO_ports led_port = GPIO_PORT_C;
	
	// Set the pin mode on the LED pin.
	GPIO::set_output(led_port, led_pin, GPIO_PULL_UP);
	GPIO::write(led_port, led_pin, GPIO_LEVEL_LOW);
	
	// Set up stdout.
	IO::setStdOutTarget(USART_2);
	
	printf("Starting I2C BME280 example...\n");
	char ch = 'c';
	USART::sendUart(USART_2, ch);
	
	// Start i2c
	// Nucleo-F042K6: I2C_1, SCL -> PA11:5, SDA -> PA12:5.
	if (!I2C::startI2C(I2C_1, GPIO_PORT_A, 11, 5, GPIO_PORT_A, 12, 5)) {
		ch = 'f';
		USART::sendUart(USART_2, ch);
		while (1) { }
	}
	
	ch = 's';
	USART::sendUart(USART_2, ch);
	
	// Create BME280 sensor instance, on the first I2C bus, slave address 0x76 (default).
    // Note that, depending on the design of the BME280 carrier board (if any), the
    //      slave address may default to 0x76 or 0x77.
	BME280 sensor(I2C_1, 0x76);
	if (!sensor.isReady()) {
		ch = 'f';
		USART::sendUart(USART_2, ch);
		while (1) { }
	}
	
	ch = 'r';
	USART::sendUart(USART_2, ch);
	
	// Read and print out sensor ID.
	uint8_t id = 0;
	ch = 'f';
	if (!sensor.readID(id)) {
		printf("Error reading ID.\n");
	}
	else {
		ch = 't';
		GPIO::write(led_port, led_pin, GPIO_LEVEL_HIGH);
		printf("Sensor ID: %d\n", id);

		if (id == 0x60) {
			ch = 'm';
		}
	}
	
	// Read temperature.
	float t = sensor.temperature();
	printf("Temp: %f.\n", t);
	
	USART::sendUart(USART_2, ch);
	//printf("Done.\n");
	
	while(1) {
		//
	}
	
	return 0;
}
