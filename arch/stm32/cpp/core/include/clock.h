/*
	clock.h - Header to provide access to GPIO functionality.
	
*/


#ifndef CLOCK_H
#define CLOCK_H


#include "nodate.h"

class Clock {
	static bool configureAHB(RccSysClockConfig cfg);
	static bool configureAPB(RccSysClockConfig cfg);
	
public:
	static bool enableMaxClock();
	static uint32_t currentSysClock();
	static bool enableLSE();
};

#endif
