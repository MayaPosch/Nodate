/*
	board_definition.h - board definition file for the F411-based 'Black Pill' board.
	
	MCU: STM32F411CE
	
	2021/02/24, Maya Posch
*/

#ifndef BOARD_DEFINITION
#define BOARD_DEFINITION

#include <rcc.h>
#include <usart.h>

#include "../board_types.h"

// --- CLOCKS ---

// >> Max SysClock Profile <<
// Maximum System Clock speed configuration.
extern RccSysClockConfig maxSysClockCfg;


// --- UARTS ---

// Define the number and features of the U(S)ARTs on the board.
extern uint8_t boardUSART_count;
extern USART_def boardUSARTs[3];

// --- LEDS ---

// Define the number and features of the user-addressable LEDs on the board.
extern uint8_t boardLEDs_count;
extern BoardLED boardLEDs[1];


// --- BUTTONS ---

// Define the user-defined buttons on the board.
extern uint8_t boardButtons_count;
extern BoardButton boardButtons[1];


#endif
