/*
	chip_tester.cpp - Main file of the IC-testing system.
	
	Revision 0
	
	Features:
		- 
	
	2018/05/24, Maya Posch
	(c) Nyanko.ws
*/


#include <wiring.h>			// For GPIO.
#include <SPI.h>
#include <SD.h>


#include "serialcomm.h"


void readIndex() {
	// Read the index file.
	// This file is a simple line-based text-file, with one chip name per line.
	File sdFile = SD.open("chips.idx");
	if (!sdFile) {
		// Error opening index file.
		Serial.println("Failed to open IC index file.");
		Serial.println("Please check SD card and try again.");
		while(1);
	}
	
	// Display index.
	Serial.println("Available chips:");
	while (sdFile.available()) {
		Serial.write(sdFile.read());
	}
	
	sdFile.close();
}


// Request the name of a chip from the user.
// Read the chip details from a file on the SD card.
// If config is valid, proceed to testing.
void readChipConfig() {
	// User picks a specific IC. 
	Serial.println("Chip name?");
	Serial.print("> ");
	String chip;
	while (!SerialComm::readLine(chip)) { } // Block until we get a command we can use.
	
	// Read in IC configuration.
	File sdFile = SD.open(chip + ".ic");	
	if (!sdFile) {
		// Error opening IC file.
		Serial.println("Failed to open IC file.");
		Serial.println("Please check SD card and try again.");
		return;
	}
	
	String name = sdFile.readStringUntil('\n');
	String desc = sdFile.readStringUntil('\n');
	
	// Display IC details.
	Serial.println("Found IC:");
	Serial.println("Name: " + name);
	Serial.println("Description: " + desc);	
	
	// Show connection instructions/checklist.
	String pins = sdFile.readStringUntil('\n');
	Serial.println(pins);
	
	// User starts test. Run test.
	Serial.println("Type 'start' and press <enter> to start test.");
	Serial.print("> ");
	String conf;
	while (!SerialComm::readLine(conf)) { } // Block until we get a command we can use.
	if (conf != "start") {
		Serial.println("Aborting test.");
		return;
	}
	
	int result_pin, result_val;
	while (sdFile.available()) {
		// Read line, format:
		// <pin>:<value>,<pin>:<value>,[..]=<pin>:<value>
		pins = sdFile.readStringUntil('=');
		result_pin = sdFile.readStringUntil(':').toInt();
		result_val = sdFile.readStringUntil('\n').toInt();
		Serial.print("Result pin: ");
		Serial.print(result_pin);
		Serial.print(", expecting: ");
		Serial.println(result_val);
		
		// Set the result pin to input mode.
		pinMode(result_pin, INPUT);
		
		// Now traverse through each pin/value combination in the 'pins' string.
		// This will allow us to set the specified pins to the indicated value,
		// prior to reading out the result pin and comparing it to the expected result.
		int idx = 0;
		unsigned int pos = 0;
		while ((idx = pins.indexOf(':', pos)) > 0) {
			// We got the double colon position, which precedes the pin number. 
			// Convert it to an integer.
			// TODO: validate pin number.
			int pin = pins.substring(pos, idx).toInt();
			pos = idx + 1; // Move to character beyond the double colon.
			
			// Get the value (first ',' or end of string).
			// TODO: check for valid value.
			bool val = false;
			if ((idx = pins.indexOf(",", pos)) > 0) {
				val = pins.substring(pos, idx).toInt();
				pos = idx + 1;
			}
			else {
				val = pins.substring(pos).toInt();
			}
			
			// Set pin value.
			Serial.print("Setting pin ");
			Serial.print(pin);
			Serial.print(" to ");
			Serial.println(val);
			pinMode(pin, OUTPUT);
			digitalWrite(pin, val);
		}
			
		// Wait briefly to let the output settle.
		delay(10);
			
		// Read result.
		int res_val = digitalRead(result_pin);
		if (res_val != result_val) {
			Serial.print("Error: got value ");
			Serial.print(res_val);
			Serial.println(" on the output.");
		}
		else {
			Serial.println("Pass.");
		}
	}
		
	// Done with test. Close file.
	sdFile.close();
}


int main () {
	// Initialise.
	init(); // for wiring.h
	initVariant();
	
	// Start UART.
	Serial.begin(9600);
	
	// Start SPI.
	SPI.begin();
	
	// Initial output.
	Serial.print("IC tester - V0.1\n");
	Serial.print("(c) Maya Posch\n");
	Serial.print("www.mayaposch.com\n");
	Serial.print("-----------------\n\n");
	
	// Read the list of available IC configurations.
	// These are stored on an SD card (accessed via SPI).
	Serial.println("Initializing SD card...");

	if (!SD.begin(53)) {
		Serial.println("Initialization failed!");
		while (1);
	}
	
	Serial.println("initialization done.");
	
	// List available commands.
	Serial.println("Commands: index, chip");
	Serial.print("> ");
	
	// Enter command loop.	
	while (1) {
		// Wait for the new full line to arrive. If we get a 'false' back, the buffer was filled
		// without a newline character. Dismiss this input.
		String cmd;
		if (!SerialComm::readLine(cmd)) { continue; }
		
		if (cmd == "index") { readIndex(); }
		else if (cmd == "chip") { readChipConfig(); }
		else { Serial.println("Unknown command.");	}
		
		Serial.print("> ");
	}
	
	return 0;
}
