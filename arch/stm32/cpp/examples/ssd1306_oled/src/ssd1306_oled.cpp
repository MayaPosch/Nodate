// SSD1306 OLED display example for the Nodate framework

#include <nodate.h>
#include <printf.h>
#include <ssd1306/ssd1306.h>


void uartCallback(char ch) {
	// Copy character into send buffer.
	USART::sendUart(USART_2, ch);
}


int main() {
	// Initialise UART.
	// Nucleo-F042K6 (STM32F042): USART2 (TX: PA2 (AF1), RX: PA15 (AF1)).
	// USART2 is normally connected to USB (ST-Link) on the Nucleo board.
	USART::startUart(USART_2, GPIO_PORT_A, 2, 1, GPIO_PORT_A, 15, 1, 9600, uartCallback);
	
	// Set up stdout.
	IO::setStdOutTarget(USART_2);
	
	// Start SysTick.
	McuCore::initSysTick();
	
	printf("Starting I2C SSD1306 OLED example...\n");
	
	// This example shows a demo sequence on an attached SSD1306-based OLED display.
	// Uses:
	// * GPIO pin for the first LED on the board, if any, to indicate when setup is complete.
	// * I2C to connect to the display.
	// * SSD1306 library to communicate with the display.
	
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
	
	// 2. Set up I2C.
	// Note: this targets I2C 1 on the STM32F042K6 MCU
	if (!I2C::startI2C(I2C_1, GPIO_PORT_A, 11, 5, GPIO_PORT_A, 12, 5)) {
		// Handle error.
		printf("I2C init error.\n");
		while (1) { }
	}
	
	// 3. Set up SSD1306 library instance.
	// SSD1306 has two possible addresses:
	// * 0x3C (0x78 after left-shift).
	// * 0x3D (0x7A after left-shift).
	SSD1306 display(I2C_1, 0x3C);
	
	printf("Created display instance.\n");
	
	// Check connected.
	if (!display.isReady()) {
		printf("Instance not ready.\n");
		while(1) { }
	}
	
	if (!display.init()) {
		// Handle error.
		printf("Display init error.\n");
		while (1) { }
	}
	
	// Display the default splash screen.
	//display.display();
	
	// Light up LED.
	if (led_enable) {
		GPIO::write(led_port, led_pin, GPIO_LEVEL_HIGH);
	}
	
	// Clear the buffer
	display.clearDisplay();
	
	printf("Display on/off.\n");
	
	// Light up whole display.
	display.displayFullOn();
	Timer::delay(2000);
	display.displayFullOn(false);
	
	printf("Pixel@20x20\n");

	// Draw a single lit pixel at 10x10.
	display.drawPixel(20, 20, 1);
	display.display();
	
	/*printf("Pixel@10x10\n");

	// Draw a single lit pixel at 10x10.
	display.drawPixel(10, 10, 1);
	display.display(); */
	
	// Clear the buffer
	//display.clearDisplay();
	
	// TODO: Display something useful.
	//display.show_text("Hello Nodate!");
	
	while (1) {
		//
	}
	
	return 0;
}
