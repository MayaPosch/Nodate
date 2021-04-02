/*
	nucleo_f746zg.h - board definition file for the ST Nucleo-F746ZG board.
	
	MCU: STM32F746ZG
	
	2021/02/24, Maya Posch
*/




#include "../board_types.h"
#include <rcc.h>


RccSysClockConfig maxSysClockCfg;
BoardLED boardLEDs[3];
BoardButton boardButtons[1];

uint8_t boardLEDs_count = 3;
uint8_t boardButtons_count = 1;

bool init() {
	maxSysClockCfg.source 		= RCC_SYSCLOCK_SRC_PLL;
	maxSysClockCfg.HSE_bypass 	= true;
	maxSysClockCfg.HSI_enabled	= false;
	maxSysClockCfg.PLL_enabled = true;
	maxSysClockCfg.PLL_source	= RCC_PLLCLOCK_SRC_HSE;
	maxSysClockCfg.PLLM		= 8;
	maxSysClockCfg.PLLN		= 432;
	maxSysClockCfg.PLLP		= 2;
	maxSysClockCfg.PLLQ		= 9;
	maxSysClockCfg.AHB_prescale	= 1;
	maxSysClockCfg.APB1_prescale	= 4;
	maxSysClockCfg.APB2_prescale	= 2;
	maxSysClockCfg.FLASH_latency	= 7;

	BoardLED bl;
	bl.pin.port = GPIO_PORT_B;
	bl.pin.pin = 0;
	bl.pin.pupd = GPIO_PULL_UP;
	bl.pin.type = GPIO_PUSH_PULL;
	bl.pin.speed = GPIO_LOW;
	bl.rgb = { 0, 0xff, 0 };
	boardLEDs[0] = bl;

	bl.pin.pin = 7;
	bl.rgb = { 0, 0, 0xff };
	boardLEDs[1] = bl;

	bl.pin.pin = 14;
	bl.rgb = { 0xff, 0, 0 };
	boardLEDs[2] = bl;


	BoardButton bb;
	bb.pin = { GPIO_PORT_C, 13, GPIO_PULL_UP };
	boardButtons[0] = bb;
	
	return true;
}

bool initialized = init();
