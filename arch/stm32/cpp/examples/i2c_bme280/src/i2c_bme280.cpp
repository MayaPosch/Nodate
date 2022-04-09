// BME280 example for Nodate's STM32 framework.

#include <usart.h>
#include <io.h>
#include <i2c.h>
#include <timer.h>
#include <bme280/bme280.h>

#include "printf.h"


void uartCallback(char ch) {
	// Copy character into send buffer.
	USART::sendUart(USART_2, ch);
	//USART::sendUart(USART_1, ch);
}


void i2cCallback(uint8_t byte) {
	// Unused.
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
	char ch = 's';
	USART::sendUart(USART_2, ch);
	
	// Start I2C.
	// Nucleo-F042K6: I2C_1, SCL -> PA11:5, SDA -> PA12:5.
	if (!I2C::startI2C(I2C_1, GPIO_PORT_A, 11, 5, GPIO_PORT_A, 12, 5)) {
		ch = 'f';
		USART::sendUart(USART_2, ch);
		while (1) { }
	}
	
	// Start I2C in master mode.
	// Use Fast Mode. The BME280 sensor supports this and slower speeds.
	if (!I2C::startMaster(I2C_1, I2C_MODE_FM, i2cCallback)) {
		ch = 'g';
		USART::sendUart(USART_2, ch);
		while (1) { }
	}
	
	ch = 'r';
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
	
	ch = 'i';
	USART::sendUart(USART_2, ch);
	
	// Read and print out sensor ID.
	uint8_t id = 0;
	if (!sensor.readID(id)) {
		printf("Error reading ID.\n");
		
		while (1) { }
	}
	
	GPIO::write(led_port, led_pin, GPIO_LEVEL_HIGH);
	printf("Sensor ID: %d\n", id);
	
	if (id == 0x60) {
		printf("Matches BME280 ID.\n");
	}
	
	// Soft reset sensor.
	// Note: enabling this results in the calibration data from the sensor to be zero.
	// 			May take a longer delay after reset?
	//sensor.softReset();
	
	Timer timer;
	timer.delay(1000);
	
	// Initialize the sensor.
	// This fetches the calibration factors from the sensor device.
	if (!sensor.initialize()) {
		printf("Sensor init failed!\n");
		while (1) { }
	}
	
	timer.delay(2000);
	
	ch = 'c';
	USART::sendUart(USART_2, ch);
	
	// Get raw temperature.
	int32_t raw;
	if (!sensor.rawTemperature(raw)) {
		printf("Reading raw temperature failed.\n");
		while (1) { }
	}
	
	printf("Raw temp: %d.\n", raw);
	
	// Read temperature.
	float t;
	if (!sensor.temperature(t)) {
		printf("Reading temperature failed.\n");
		while (1) { }
	}
	
	printf("Temp: %f.\n", t);
	
	//printf("Done.\n");
	
	while(1) {
		//
	}
	
	return 0;
}
