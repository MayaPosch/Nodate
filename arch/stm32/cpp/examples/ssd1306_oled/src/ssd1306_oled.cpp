// SSD1306 OLED display example for the Nodate framework

#include <nodate.h>
#include <ssd1306/ssd1306.h>


int main() {
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
	}
	
	// 3. Set up SSD1306 library instance.
	SSD1306 display(I2C_1, 0x78);
	
	// TODO: Check connected?
	
	if (!display.init()) {
		// Handle error.
	}
	
	// Light up LED.
	if (led_enable) {
		GPIO::write(led_port, led_pin, GPIO_LEVEL_HIGH);
	}
	
	// TODO: Display something useful.
	// Display the default splash screen.
	display.display();
	//display.show_text("Hello Nodate!");
	
	
	while (1) {
		//
	}
	
	return 0;
}
