// Basic Event example for Nodate's STM32 framework.

#include <gpio.h>
#include <interrupts.h>


volatile bool led_on;


void callBack_A() {
	//led_on = !led_on;
}


void callBack_B() {
	//led_on = !led_on;
}


void callBack_button() {
	//led_on = !led_on;
	led_on = true;
}


int main () {
	// Initialise.
	GPIO gpio;
	Interrupts itrs;
	
	// FIXME: Dynamically updated LED_BUILTIN value.
	uint8_t LED_BUILTIN = 3;
	
	// Set the pin mode on the built-in LED.
	gpio.set_output(GPIO_PORT_B, LED_BUILTIN, GPIO_PULL_UP);
	gpio.write(GPIO_PORT_B, LED_BUILTIN, GPIO_LEVEL_LOW);
	
	// Set the interrupts for the rotary encoder.
	// A: Port B, pin 0 (D3 on Nucleo-32).
	// B: Port B, pin 1 (D6 on Nucleo-32).
	// Button: Port B, pin 4 (D12 on Nucleo-32).
	uint8_t handleA, handleB, handleC;
	itrs.setInterrupt(0, GPIO_PORT_B, INTERRUPT_TRIGGER_FALLING, callBack_A, 0, handleA);
	itrs.setInterrupt(1, GPIO_PORT_B, INTERRUPT_TRIGGER_FALLING, callBack_B, 0, handleB);
	itrs.setInterrupt(4, GPIO_PORT_B, INTERRUPT_TRIGGER_FALLING, callBack_button, 0, handleC);
	
	// Set the pin mode on the interrupt pins.
	gpio.set_output(GPIO_PORT_B, 0, GPIO_PULL_UP);
	gpio.set_output(GPIO_PORT_B, 1, GPIO_PULL_UP);
	gpio.set_output(GPIO_PORT_B, 4, GPIO_PULL_UP);
	
	while (1) {
		if (led_on) {
			gpio.write(GPIO_PORT_B, LED_BUILTIN, GPIO_LEVEL_HIGH);
		}
		else {
			gpio.write(GPIO_PORT_B, LED_BUILTIN, GPIO_LEVEL_LOW);
		}
	}
	
	return 0;
}
