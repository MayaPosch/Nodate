/*
	generic_board.h - Generic board profile.
	
	MCU: -
	
*/

#ifndef BOARD_DEFINITION
#define BOARD_DEFINITION

//#include <rcc.h>

#include "../board_types.h"

//RccSysClockConfig maxSysClockCfg;

extern uint8_t boardLEDs_count;
extern BoardLED boardLEDs[0];

extern uint8_t boardButtons_count;
extern BoardButton boardButtons[0];

#endif
