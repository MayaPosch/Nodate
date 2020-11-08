// BME280 example for Nodate's STM32 framework.

#include <usart.h>
#include <io.h>
#include <i2c.h>
#include <bme280/bme280.h>


void uartCallback(char ch) {
	// Copy character into send buffer.
	//USART::sendUart(USART_2, ch);
	USART::sendUart(USART_1, ch);
}


int main () {
	// Initialise UART.
	// Nucleo-F042K6 (STM32F042): USART2 (TX: PA2 (AF1), RX: PA15 (AF1)).
	// USART2 is normally connected to USB (ST-Link) on the Nucleo board.
	//USART::startUart(USART_2, GPIO_PORT_A, 2, 1, GPIO_PORT_A, 15, 1, 9600, uartCallback);
	// USART 1, (TX) PA9:1 [D1], (RX) PA10:1 [D0].
	USART::startUart(USART_1, GPIO_PORT_A, 9, 1, GPIO_PORT_A, 10, 1, 9600, uartCallback);
	
	// STM32F4-Discovery (STM32F407): USART2, (TX) PA2:7, (RX) PA3:7.
	//USART::startUart(USART_2, GPIO_PORT_A, 2, 7, GPIO_PORT_A, 3, 7, 9600, uartCallback);
	
	// Set up stdout.
	IO::setStdOutTarget(USART_1);
	
	printf("Starting I2C BME280 example...\n");
	
	// Start i2c
	// Nucleo-F042K6: I2C_1, SCL -> PA11:5, SDA -> PA12:5.
	I2C::startI2C(I2C_1, GPIO_PORT_A, 11, 5, GPIO_PORT_A, 12, 5);
	
	// Create BME280 sensor instance, on the first I2C bus, slave address 0x76 (default).
	BME280 sensor(I2C_1, 0x76);
	
	// Read and print out sensor ID.
	uint8_t id = 0;
	if (!sensor.readID(id)) {
		printf("Error reading ID.\n");
	}
	else {
		printf("Sensor ID: %d\n", id);
	}
	
	printf("Done.\n");
	
	while(1) {
		//
	}
	
	return 0;
}