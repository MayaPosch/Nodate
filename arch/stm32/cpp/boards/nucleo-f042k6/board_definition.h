/*
	nucleo_f746zg.h - board definition file for the ST Nucleo-F746ZG board.
	
	MCU: STM32F746ZG
	
	2021/02/24, Maya Posch
*/

#ifndef BOARD_DEFINITION
#define BOARD_DEFINITION

#include <vector>

#include <rcc.h>

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
//std::vector<
//uint8_t board_USART_count = 

// --- LEDS ---

// Define the number and features of the user-addressable LEDs on the board.
extern std::vector<BoardLED> boardLEDs;


// --- BUTTONS ---

// Define the user-defined buttons on the board.
extern std::vector<BoardButton> boardButtons;

// UART
#include <lan8742a/phy_definition.h>

#endif
