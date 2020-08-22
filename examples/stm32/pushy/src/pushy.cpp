// Basic Pushy example for Nodate's STM32 framework.

#include <gpio.h>


int main () {
	// Initialise.
	GPIO gpio;
	
	// FIXME: Dynamically updated LED_BUILTIN value.
	//const uint8_t LED_BUILTIN = 3; // Nucleo-f042k6: Port B, pin 3.
	const uint8_t LED_BUILTIN = 13; // STM32F4-Discovery: Port D, pin 13 (orange)
	const uint8_t BUTTON_PIN = 0;
	
	// Set the pin mode on the built-in LED.
	gpio.set_output(GPIO_PORT_D, LED_BUILTIN, GPIO_PULL_UP);
	gpio.write(GPIO_PORT_D, LED_BUILTIN, GPIO_LEVEL_LOW);
	
	// Set input mode on PB1 pin. (Nucleo-f042k6)
	//gpio.set_input(GPIO_PORT_B, 1, GPIO_PULL_UP);
	
	// Set input mode on PA0 pin. (STM32F4-Discovery)
	gpio.set_input(GPIO_PORT_A, 0, GPIO_FLOATING);
	
	// If the button pulls down to ground (high to low), 'button_down' is low when pushed.
	// If the button is pulled up to Vdd (low to high), 'button_down' is high when pushed.
	uint8_t button_down;
	while (1) {
		button_down = gpio.read(GPIO_PORT_A, BUTTON_PIN);
		if (button_down == 1) {
			gpio.write(GPIO_PORT_D, LED_BUILTIN, GPIO_LEVEL_HIGH);
		}
		else {
			gpio.write(GPIO_PORT_D, LED_BUILTIN, GPIO_LEVEL_LOW);
		}
	}
	
	return 0;
}
