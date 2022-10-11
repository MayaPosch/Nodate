// BME280 example for Nodate's STM32 framework.

#include <nodate.h>
#include <printf.h>
#include <bme280/bme280.h>


void uartCallback(char ch) {
	// Copy character into send buffer.
	USART::sendUart(USART_2, ch);
	//USART::sendUart(USART_1, ch);
}


void i2cCallback(uint8_t byte) {
	// Unused.
}


int main () {
	// 1. Set up UART
	USART_def& ud = boardUSARTs[1];
	//usartTarget = ud.usart;
	USART::startUart(ud.usart, ud.tx[0].port, ud.tx[0].pin, ud.tx[0].af, 
								ud.rx[0].port, ud.rx[0].pin, ud.rx[0].af, 115200, uartCallback);
	
	// Set up stdout.
	IO::setStdOutTarget(USART_2);
	
	// Start SysTick.
	McuCore::initSysTick();
	
	printf("Starting SPI BME280 example...\n");
	
	// This example shows a demo sequence on an attached ST7735-based LCD display.
	// Uses:
	// * GPIO pin for the first LED on the board, if any, to indicate when setup is complete.
	// * SPI to connect to the display.
	// * ST7735 library to communicate with the display.
	
	// 1. Set up LED.
	uint8_t 	led_pin;
	GPIO_ports 	led_port;
	bool		led_enable = true;
	if (boardLEDs_count > 0) {
		led_pin = boardLEDs[0].pin.pin;
		led_port = boardLEDs[0].pin.port;
	}
	else {
		led_enable = false;
	}
	
	// Set the pin mode on the LED pin and turn it off.
	GPIO::set_output(led_port, led_pin, GPIO_PULL_UP);
	GPIO::write(led_port, led_pin, GPIO_LEVEL_LOW);
	
	// 2. Set up SPI.
	// Note: this targets SPI 1 on the STM32F411CE MCU
	/* SPI_pins spins;
	spins.miso = { GPIO_PORT_A, 6, 5 };
	spins.mosi = { GPIO_PORT_A, 7, 5 };
	spins.sclk = { GPIO_PORT_A, 5, 5 };
	spins.nss = { GPIO_PORT_A, 4, 5 }; */
	// Note: this set targets SPI 1 (no remap) on STM32F103.
	/* SPI_pins spins;
	spins.miso = { GPIO_PORT_A, 6, 0 };
	spins.mosi = { GPIO_PORT_A, 7, 0 };
	spins.sclk = { GPIO_PORT_A, 5, 0 };
	spins.nss = { GPIO_PORT_A, 4, 0 }; */
	// Note: this set targets SPI 1 on STM32F042.
	SPI_pins spins;
	spins.miso = { GPIO_PORT_A, 6, 0 };
	spins.mosi = { GPIO_PORT_A, 7, 0 };
	spins.sclk = { GPIO_PORT_A, 5, 0 };
	spins.nss = { GPIO_PORT_A, 4, 0 };
	if (!SPI::startSPIMaster(SPI_1, spins)) {
		// Handle error.
		printf("SPI master init error.\n");
		while (1) { }
	}
	
	// Create BME280 sensor instance.
	//BME280 sensor(I2C_1, 0x76);
	GpioPinDef cs = { GPIO_PORT_B, 3, 0 };
	BME280 sensor(SPI_1, cs);
	if (!sensor.isReady()) {
		printf("Sensor not ready.\n");
		while (1) { }
	}
	
	printf("Created sensor instance.\n");
	
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
	sensor.softReset();
	
	Timer timer;
	timer.delay(1000);
	
	// Initialize the sensor.
	// This fetches the calibration factors from the sensor device.
	if (!sensor.initialize()) {
		printf("Sensor init failed!\n");
		while (1) { }
	}
	
	timer.delay(2000);
	
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
		timer.delay(2000);
	
		// Get raw temperature.
		if (!sensor.rawTemperature(raw)) {
			printf("Reading raw temperature failed.\n");
			while (1) { }
		}
		
		printf("Raw temp: %d.\n", raw);
		
		// Read temperature.
		if (!sensor.temperature(t)) {
			printf("Reading temperature failed.\n");
			while (1) { }
		}
	
		printf("Temp: %f.\n", t);
	}
	
	return 0;
}
