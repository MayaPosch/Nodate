// Basic Blinky example for Nodate framework.
// This uses the same API calls as with the Arduino framework.

#include <wiring.h>


int main () {
	// Initialise.
	init(); // for wiring.h
	initVariant();
	
	// Set the pin mode on the built-in LED.
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, LOW);
	
	while (1) {
		digitalWrite(LED_BUILTIN, HIGH);
		delay(1000);
		digitalWrite(LED_BUILTIN, LOW);
		delay(1000);
	}
	
	return 0;
}
