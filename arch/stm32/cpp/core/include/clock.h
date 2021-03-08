/*
	clock.h - Header to provide access to GPIO functionality.
	
*/


#ifndef CLOCK_H
#define CLOCK_H


#include "common.h"

class Clock {
	//
	
public:
	static bool enableMaxClock();
	static uint32_t currentSysClock();
	static bool enableLSE();
};

#endif
