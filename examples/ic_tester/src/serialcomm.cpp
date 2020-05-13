/*
	serialcomm.h - Serial communications utility wrapper class.
	
	Revision 0
	
	Features:
		- 
	
	2018/05/24, Maya Posch
	(c) Nyanko.ws
*/


#include "serialcomm.h"


// Static initialisations.
char SerialComm::charbuff[CHARBUFFERSIZE];


bool SerialComm::readLine(String &str) {
	int index = 0;
 
	while (1) {
		// Make this a blocking read.
		while (Serial.available() == 0) { }
		
		// Read and echo character.
		// TODO: implement backspace.
		char rc = Serial.read();
		Serial.print(rc);
		
		if (rc == '\n') {
			// Newline found: add terminator 
			// and return true.
			charbuff[index] = 0;
			str = charbuff;
			return true;
		}
		
		// Next check that the character we received is 
		// not a control character.
		if (rc >= 0x20) {
			charbuff[index++] = rc;
			if (index > CHARBUFFERSIZE) {
				// Buffer is full, but no newline found.
				// Return false.
				return false;
			}
		}
	}
	
	return false;
}
