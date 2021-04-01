/*
	generic_board.h - Generic board profile.
	
	MCU: -
	
*/

#ifndef BOARD_GENERIC_H
#define BOARD_GENERIC_H

#include <vector>

#include <rcc.h>

#include "../board_types.h"

RccSysClockConfig maxSysClockCfg;
std::vector<BoardLED> boardLEDs;
std::vector<BoardButton> boardButtons;

#endif
