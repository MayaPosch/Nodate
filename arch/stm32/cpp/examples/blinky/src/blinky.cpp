// Basic Blinky example for Nodate's STM32 framework.

#include <gpio.h>
#include <timer.h>


int main () {
	// Initialise.
	Timer timer;
	
	//const uint8_t led_pin = 3; // Nucleo-f042k6: Port B, pin 3.
	//const GPIO_ports led_port = GPIO_PORT_B;
	//const uint8_t led_pin = 13; // STM32F4-Discovery: Port D, pin 13 (orange)
	//const GPIO_ports led_port = GPIO_PORT_D;
	//const uint8_t led_pin = 7; // Nucleo-F746ZG: Port B, pin 7 (blue)
	//const GPIO_ports led_port = GPIO_PORT_B;
	const uint8_t led_pin = 13;	// Blue Pill: Port C, pin 13.
	const GPIO_ports led_port = GPIO_PORT_C;
	
	// Set the pin mode on the LED pin.
	GPIO::set_output(led_port, led_pin, GPIO_PULL_UP);
	GPIO::write(led_port, led_pin, GPIO_LEVEL_HIGH);
	
	while (1) {
		GPIO::write(led_port, led_pin, GPIO_LEVEL_LOW);
		timer.delay(1000);
		GPIO::write(led_port, led_pin, GPIO_LEVEL_HIGH);
		timer.delay(1000);
	}
	
	return 0;
}
