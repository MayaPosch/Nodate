// Basic Blinky example for Nodate's STM32 framework.

#include <nodate.h>


void delay(void) {
    volatile uint32_t cnt_down = 1200000;
    while (cnt_down--) {
        __NOP();
    }
}


int main () {
	// Initialise.
	//Timer timer;
	
	// Set LED & button.
	uint8_t 	led_pin;
	GPIO_ports 	led_port;
	if (boardLEDs_count > 0) {
		led_pin = boardLEDs[led_idx].pin.pin;
		led_port = boardLEDs[led_idx].pin.port;
	}
	else {
		led_pin = 25; // RPi-Pico: Port A, pin 25.
		led_port = GPIO_PORT_A;
	}
	
	// Set the pin mode on the LED pin.
	GPIO::set_output(led_port, led_pin, GPIO_PULL_UP);
	GPIO::write(led_port, led_pin, GPIO_LEVEL_LOW);
	
	while (1) {
		GPIO::write(led_port, led_pin, GPIO_LEVEL_HIGH);
		//timer.delay(1000);
		delay(1000);
		GPIO::write(led_port, led_pin, GPIO_LEVEL_LOW);
		//timer.delay(1000);
		delay(1000);
	}
	
	return 0;
}
