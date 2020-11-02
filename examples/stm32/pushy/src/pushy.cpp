// Basic Pushy example for Nodate's STM32 framework.

#include <gpio.h>


int main () {
	//const uint8_t led_pin = 3; // Nucleo-f042k6: Port B, pin 3.
	//const GPIO_ports led_port = GPIO_PORT_B;
	//const uint8_t led_pin = 13; // STM32F4-Discovery: Port D, pin 13 (orange)
	//const GPIO_ports led_port = GPIO_PORT_D;
	//const uint8_t led_pin = 7; // Nucleo-F746ZG: Port B, pin 7 (blue)
	//const GPIO_ports led_port = GPIO_PORT_B;
	//const uint8_t led_pin = 13;	// Blue Pill: Port C, pin 13.
	//const GPIO_ports led_port = GPIO_PORT_C;
	//const uint8_t led_pin = 13;	// Otter Pill: Port B, pin 13.
	//const GPIO_ports led_port = GPIO_PORT_B;
	//const uint8_t led_pin = 9;	// STM32F0-Discovery (PC9, green).
	//const GPIO_ports led_port = GPIO_PORT_C;
	const uint8_t led_pin = 1;	// Maple Mini
	const GPIO_ports led_port = GPIO_PORT_B;
	
	//const uint8_t button_pin = 1; // Nucleo-f042k6 (PB1)
	//const GPIO_ports button_port = GPIO_PORT_B;
	//const uint8_t button_pin = 0; // STM32F0-Discovery / STM32F4-Discovery (PA0)
	//const GPIO_ports button_port = GPIO_PORT_A;
	//const uint8_t button_pin = 13; // Nucleo-F746ZG (PC13)
	//const GPIO_ports button_port = GPIO_PORT_C;
	//const uint8_t button_pin = 10; // Blue Pill / Otter Pill
	//const GPIO_ports button_port = GPIO_PORT_B;
	const uint8_t button_pin = 8;	// Maple Mini
	const GPIO_ports button_port = GPIO_PORT_B;
	
	// Set the pin mode on the LED pin.
	GPIO::set_output(led_port, led_pin, GPIO_PULL_UP);
	GPIO::write(led_port, led_pin, GPIO_LEVEL_LOW);
	
	// Set input mode on button pin.
	GPIO::set_input(button_port, button_pin, GPIO_FLOATING);
	
	// If the button pulls down to ground (high to low), 'button_down' is low when pushed.
	// If the button is pulled up to Vdd (low to high), 'button_down' is high when pushed.
	uint8_t button_down;
	while (1) {
		button_down = GPIO::read(button_port, button_pin);
		if (button_down == 1) {
			GPIO::write(led_port, led_pin, GPIO_LEVEL_HIGH);
		}
		else {
			GPIO::write(led_port, led_pin, GPIO_LEVEL_LOW);
		}
	}
	
	return 0;
}
