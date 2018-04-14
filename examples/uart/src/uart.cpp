// Basic UART example for Nodate framework.
// This uses the same API calls as with the Arduino framework.

#include <wiring.h> 		// For GPIO.
#include <HardwareSerial.h>	// UART.


int main () {
	// Initialise.
	init(); // for wiring.h
	initVariant();
	
	// Start UART.
	Serial.begin(9600);
	
	// Set the pin mode on the built-in LED.
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, LOW);
	
	while (1) {
		Serial.print("Blinking LED...\n");
		digitalWrite(LED_BUILTIN, HIGH);
		delay(1000);
		digitalWrite(LED_BUILTIN, LOW);
		delay(1000);
		
		if (serialEventRun) { serialEventRun(); } // Run the serial event queue.
	}
	
	return 0;
}
