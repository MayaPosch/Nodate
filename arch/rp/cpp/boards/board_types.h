/*
	board_types.h - definitions of common types used by Nodate board definitions.
	
	2021/02/25, Maya Posch
*/


#ifndef BOARD_TYPES_H
#define BOARD_TYPES_H

#include <gpio.h>

#include <cstdint>


struct RGB {
	uint8_t r;
	uint8_t g;
	uint8_t b;
};


struct BoardLED {
	GpioOutputDef pin;
	RGB rgb;
};


struct BoardButton {
	GpioInputDef pin;
};


#endif
