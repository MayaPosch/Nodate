// Basic Event example for Nodate's STM32 framework.

#include <gpio.h>
#include <interrupts.h>


volatile bool led_on;


void callBack_A() {
	led_on = !led_on;
}


void callBack_B() {
	led_on = !led_on;
}


void callBack_button() {
	//led_on = !led_on;
	led_on = true;
}


int main () {
	// Initialise.
	Interrupts itrs;
	
	//const uint8_t led_pin = 3; // Nucleo-f042k6: Port B, pin 3.
	//const GPIO_ports led_port = GPIO_PORT_B;
	//const uint8_t led_pin = 13; // STM32F4-Discovery: Port D, pin 13 (orange)
	//const GPIO_ports led_port = GPIO_PORT_D;
	//const uint8_t led_pin = 7; // Nucleo-F746ZG: Port B, pin 7 (blue)
	//const GPIO_ports led_port = GPIO_PORT_B;
	const uint8_t led_pin = 13;	// Blue Pill: Port C, pin 13.
	const GPIO_ports led_port = GPIO_PORT_C;
	
	// Set the pin mode on the target LED pin.
	GPIO::set_output(led_port, led_pin, GPIO_PULL_UP);
	GPIO::write(led_port, led_pin, GPIO_LEVEL_LOW);
	
	//const uint8_t button_pin = 1; // Nucleo-f042k6 (PB1)
	//const GPIO_ports button_port = GPIO_PORT_B;
	const uint8_t button_pin = 10; // Blue Pill
	const GPIO_ports button_port = GPIO_PORT_B;
	
	// Set the pin mode on the interrupt pins.
	GPIO::set_input(GPIO_PORT_B, 0, GPIO_PULL_UP);
	GPIO::set_input(GPIO_PORT_B, 4, GPIO_PULL_UP);
	GPIO::set_input(button_port, button_pin, GPIO_PULL_UP);
	
	// Set the interrupts for the rotary encoder.
	// A: Port B, pin 0 (D3 on Nucleo-32).
	// B: Port B, pin 4 (D12 on Nucleo-32).
	// Button: Port B, pin 6 (D6 on Nucleo-32).
	uint8_t handleA, handleB, handleC;
	itrs.setInterrupt(GPIO_PORT_B, 0, INTERRUPT_TRIGGER_FALLING, callBack_A, 0, handleA);
	itrs.setInterrupt(GPIO_PORT_B, 4, INTERRUPT_TRIGGER_FALLING, callBack_B, 0, handleB);
	itrs.setInterrupt(button_port, button_pin, INTERRUPT_TRIGGER_FALLING, callBack_button, 0, handleC);
	
	while (1) {
		if (led_on) {
			GPIO::write(led_port, led_pin, GPIO_LEVEL_HIGH);
		}
		else {
			GPIO::write(led_port, led_pin, GPIO_LEVEL_LOW);
		}
	}
	
	return 0;
}
