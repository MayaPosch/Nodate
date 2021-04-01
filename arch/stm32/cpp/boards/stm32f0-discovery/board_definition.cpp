/*
	board_definition.cpp - board definition file for the ST STM32F0-Discovery board.
	
	MCU: STM32F051R8T6
	
	2021/02/24, Maya Posch
*/




#include "../board_types.h"
#include <vector>
#include <rcc.h>


RccSysClockConfig maxSysClockCfg;
std::vector<BoardLED> boardLEDs;
std::vector<BoardButton> boardButtons;

bool init() {
	maxSysClockCfg.source 		= RCC_SYSCLOCK_SRC_PLL;
	maxSysClockCfg.HSE_bypass 	= true;
	maxSysClockCfg.HSI_enabled	= false;
	maxSysClockCfg.PLL_enabled = true;
	maxSysClockCfg.PLL_source	= RCC_PLLCLOCK_SRC_HSE;
	maxSysClockCfg.PLLM		= 2;	// Prediv.
	maxSysClockCfg.PLLN		= 12;	// PLL Multiplier.
	maxSysClockCfg.PLLP		= 2;
	maxSysClockCfg.PLLQ		= 9;
	maxSysClockCfg.AHB_prescale	= 1;
	maxSysClockCfg.APB1_prescale	= 2;
	maxSysClockCfg.APB2_prescale	= 2;
	maxSysClockCfg.FLASH_latency	= 1;
	
	BoardLED bl;
	bl.pin.port = GPIO_PORT_C;
	bl.pin.pin = 9;
	bl.pin.pupd = GPIO_PULL_UP;
	bl.pin.type = GPIO_PUSH_PULL;
	bl.pin.speed = GPIO_LOW;
	bl.rgb = { 0, 0xff, 0 };
	boardLEDs.push_back(bl);
	
	bl.pin.port = GPIO_PORT_C;
	bl.pin.pin = 8;
	bl.rgb = { 0, 0, 0xff };
	boardLEDs.push_back(bl);


	BoardButton bb;
	bb.pin = { GPIO_PORT_A, 0, GPIO_PULL_UP };
	boardButtons.push_back(bb);
	
	return true;
}

bool initialized = init();
