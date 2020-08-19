// Basic Pushy example for Nodate's STM32 framework.

#include <gpio.h>


int main () {
	// Initialise.
	GPIO gpio;
	
	// FIXME: Dynamically updated LED_BUILTIN value.
	const uint8_t LED_BUILTIN = 3;
	const uint8_t BUTTON_PIN = 1;
	
	// Set the pin mode on the built-in LED.
	gpio.set_output(GPIO_PORT_B, LED_BUILTIN, GPIO_PULL_UP);
	gpio.write(GPIO_PORT_B, LED_BUILTIN, GPIO_LEVEL_LOW);
	
	// Set input mode on PB1 pin.
	gpio.set_input(GPIO_PORT_B, BUTTON_PIN, GPIO_PULL_UP);
	
	uint8_t button_down;
	while (1) {
		button_down = gpio.read(GPIO_PORT_B, BUTTON_PIN);
		if (button_down == 0) {
			gpio.write(GPIO_PORT_B, LED_BUILTIN, GPIO_LEVEL_HIGH);
		}
		else {
			gpio.write(GPIO_PORT_B, LED_BUILTIN, GPIO_LEVEL_LOW);
		}
	}
	
	return 0;
}
