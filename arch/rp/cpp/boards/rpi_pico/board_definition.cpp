
#include "../board_definition.h"

//RccSysClockConfig maxSysClockCfg;
BoardLED boardLEDs[1];
BoardButton boardButtons[0];

uint8_t boardLEDs_count = 1;
uint8_t boardButtons_count = 0;

// TODO: Finish clock configuration.
bool init() {
	/* maxSysClockCfg.source 		= RCC_SYSCLOCK_SRC_PLL;
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
	maxSysClockCfg.FLASH_latency	= 1; */

	BoardLED bl;
	bl.pin.port = GPIO_PORT_A;
	bl.pin.pin = 25;
	bl.pin.pupd = GPIO_PULL_UP;
	bl.pin.type = GPIO_PUSH_PULL;
	bl.pin.speed = GPIO_LOW;
	bl.rgb = { 0, 0xff, 0 };
	boardLEDs[0] = bl;


	BoardButton bb;
	// Zero buttons.
	//bb.pin = { GPIO_PORT_C, 13, GPIO_PULL_UP };
	
	return true;
}

bool initialized = init();
