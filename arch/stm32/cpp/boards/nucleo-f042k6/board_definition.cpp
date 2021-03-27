/*
	nucleo_f746zg.h - board definition file for the ST Nucleo-F746ZG board.
	
	MCU: STM32F746ZG
	
	2021/02/24, Maya Posch
*/




#include "../board_types.h"
#include <vector>
#include <rcc.h>


RccSysClockConfig maxSysClockCfg;
std::vector<BoardLED> boardLEDs;
std::vector<BoardButton> boardButtons;

// TODO: Finish clock configuration.
bool init() {
	maxSysClockCfg.source 		= RCC_SYSCLOCK_SRC_PLL;
	maxSysClockCfg.HSE_bypass 	= false;
	maxSysClockCfg.HSI_enabled	= false;
	maxSysClockCfg.PLL_enabled = true;
	maxSysClockCfg.PLL_source	= RCC_PLLCLOCK_SRC_HSI;
	maxSysClockCfg.PLLM		= 1;
	maxSysClockCfg.PLLN		= 1;
	maxSysClockCfg.PLLP		= 1;
	maxSysClockCfg.PLLQ		= 1;
	maxSysClockCfg.AHB_prescale	= 1;
	maxSysClockCfg.APB1_prescale	= 1;
	maxSysClockCfg.APB2_prescale	= 1;
	maxSysClockCfg.FLASH_latency	= 1;

	BoardLED bl;
	bl.pin.port = GPIO_PORT_B;
	bl.pin.pin = 3;
	bl.pin.pupd = GPIO_PULL_UP;
	bl.pin.type = GPIO_PUSH_PULL;
	bl.pin.speed = GPIO_LOW;
	bl.rgb = { 0, 0xff, 0 };
	boardLEDs.push_back(bl);


	BoardButton bb;
	// Zero buttons.
	//bb.pin = { GPIO_PORT_C, 13, GPIO_PULL_UP };
	//boardButtons.push_back(bb);
	
	return true;
}

bool initialized = init();
