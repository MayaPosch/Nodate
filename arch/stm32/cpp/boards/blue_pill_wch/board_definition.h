/*
	board_definition.h - board definition file for the WCH F103 'Blue Pill' board.
	
	MCU: CH32F103C8T6
	
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
// HSE in bypass mode (using 8 MHz clock from ST-Link side).
// PLLP: 8 / 8 = 1 => 1 * 432 / 2 = 216 MHz SysClock.
// PLLQ: 432 / 9 = 48 MHz (USB clock).
// Configures APB & AHB clocks to match SysClock.
extern RccSysClockConfig maxSysClockCfg;


// --- UARTS ---

// Define the number and features of the U(S)ARTs on the board.
extern uint8_t boardUSART_count;
extern USART_def boardUSARTs[2];

// --- LEDS ---

// Define the number and features of the user-addressable LEDs on the board.
extern uint8_t boardLEDs_count;
extern BoardLED boardLEDs[1];


// --- BUTTONS ---

// Define the user-defined buttons on the board.
extern uint8_t boardButtons_count;
extern BoardButton boardButtons[1];

#endif
