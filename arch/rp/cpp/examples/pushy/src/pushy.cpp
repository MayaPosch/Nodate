// Basic Pushy example for Nodate's RP framework.

#include <nodate.h>


int main () {
	// Set LED & button.
	uint8_t 	led_pin;
	GPIO_ports 	led_port;
	bool 		led_iterate = false;
	uint32_t 	led_idx = 0;
	if (boardLEDs_count > 0) {
		if (boardLEDs_count > 1) { led_iterate = true; led_idx = 1; }
		led_pin = boardLEDs[led_idx].pin.pin;
		led_port = boardLEDs[led_idx].pin.port;
	}
	else {
		led_pin = 25; // RPi-Pico: Port A, pin 25.
		led_port = GPIO_PORT_A;
	}
	
	uint8_t 	button_pin;
	GPIO_ports 	button_port;
	if (boardButtons_count > 0) {
		button_pin = boardButtons[0].pin.pin;
		button_port = boardButtons[0].pin.port;
	}
	else {
		button_pin = 22; // RPi-Pico
		button_port = GPIO_PORT_A;
	}
	
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
