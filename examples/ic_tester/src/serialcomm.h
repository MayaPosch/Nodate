/*
	serialcomm.h - Serial communications utility wrapper class.
	
	Revision 0
	
	Features:
		- 
	
	2018/05/24, Maya Posch
	(c) Nyanko.ws
*/


#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include <HardwareSerial.h>	// UART.


#define CHARBUFFERSIZE 64


class SerialComm {
	static char charbuff[CHARBUFFERSIZE];
	
public:
	static bool readLine(String &str);
};



#endif
