// Basic Blinky example for Nodate's STM32 framework.

#include <gpio.h>
#include <timer.h>


int main () {
	// Initialise.
	GPIO gpio;
	Timer timer;
	
	// FIXME: Dynamically updated LED_BUILTIN value.
	uint8_t LED_BUILTIN = 3;
	
	// Set the pin mode on the built-in LED.
	gpio.set_output(GPIO_PORT_B, LED_BUILTIN, GPIO_PULL_UP);
	gpio.write(GPIO_PORT_B, LED_BUILTIN, GPIO_LEVEL_LOW);
	
	while (1) {
		gpio.write(GPIO_PORT_B, LED_BUILTIN, GPIO_LEVEL_HIGH);
		timer.delay(1000);
		gpio.write(GPIO_PORT_B, LED_BUILTIN, GPIO_LEVEL_LOW);
		timer.delay(1000);
	}
	
	return 0;
}
