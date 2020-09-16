/*
	io.h - Definition of the Nodate STM32 IO module.
	
	Revision 0
	
	Features:
			-
			
	Notes:
			- 
	
	2020/09/11, Maya Posch
*/


#ifndef IO_H
#define IO_H

#include <usart.h>


class IO {
	//
	
public:
	static USART_devices usart;
	
	static bool setStdOutTarget(USART_devices device);
};


#endif
