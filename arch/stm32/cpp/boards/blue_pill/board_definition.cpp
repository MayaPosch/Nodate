/*
	board_definition.cpp - board definition file for the STM32F103 'Blue Pill' board.
	
	MCU: STM32F103C8T6
	
	2021/02/24, Maya Posch
*/




#include "../board_types.h"
#include <rcc.h>
#include <usart.h>


RccSysClockConfig maxSysClockCfg;
BoardLED boardLEDs[1];
BoardButton boardButtons[1];
USART_def boardUSARTs[3];

uint8_t boardLEDs_count = 1;
uint8_t boardButtons_count = 0;

uint8_t boardUSART_count = 3;

// TODO: Finish clock configuration.
bool init() {
	maxSysClockCfg.source 		= RCC_SYSCLOCK_SRC_PLL;
	maxSysClockCfg.base_freq	= 8000000;
	maxSysClockCfg.HSE_bypass 	= false;
	maxSysClockCfg.HSI_enabled	= false;
	maxSysClockCfg.PLL_enabled = true;
	maxSysClockCfg.PLL_source	= RCC_PLLCLOCK_SRC_HSE;
	maxSysClockCfg.PLLM		= 9;	// PLLMul for F1, ignore other PLL factors.
	maxSysClockCfg.PLLN		= 1;
	maxSysClockCfg.PLLP		= 1;
	maxSysClockCfg.PLLQ		= 1;
	maxSysClockCfg.AHB_prescale	= 1;
	maxSysClockCfg.APB1_prescale	= 2;
	maxSysClockCfg.APB2_prescale	= 1;
	maxSysClockCfg.FLASH_latency	= 2;

	BoardLED bl;
	bl.pin.port = GPIO_PORT_C;
	bl.pin.pin = 13;
	bl.pin.pupd = GPIO_PULL_UP;
	bl.pin.type = GPIO_PUSH_PULL;
	bl.pin.speed = GPIO_LOW;
	bl.rgb = { 0xff, 0, 0 };
	boardLEDs[0] = bl;

	BoardButton bb;
	// Zero buttons.
	//bb.pin = { GPIO_PORT_C, 13, GPIO_PULL_UP };
	
	USART_def usart;
	usart.usart = USART_1;
	usart.configs = 2;
	usart.tx = new GpioPinDef[2];
	usart.tx[0] = { .port = GPIO_PORT_A, .pin = 9, .af = 0 };
	usart.tx[1] = { .port = GPIO_PORT_B, .pin = 6, .af = 1 };
	usart.rx = new GpioPinDef[2];
	usart.rx[0] = { .port = GPIO_PORT_A, .pin = 10, .af = 0 };
	usart.rx[1] = { .port = GPIO_PORT_B, .pin = 7, .af = 1 };
	boardUSARTs[0] = usart;
	
	usart.usart = USART_2;
	usart.configs = 2;
	usart.tx = new GpioPinDef[2];
	usart.tx[0] = { .port = GPIO_PORT_A, .pin = 2, .af = 0 };
	usart.tx[1] = { .port = GPIO_PORT_D, .pin = 5, .af = 1 };
	usart.rx = new GpioPinDef[2];
	usart.rx[0] = { .port = GPIO_PORT_A, .pin = 3, .af = 0 };
	usart.rx[1] = { .port = GPIO_PORT_D, .pin = 6, .af = 1 };
	boardUSARTs[1] = usart;
	
	usart.usart = USART_3;
	usart.configs = 2;
	usart.tx = new GpioPinDef[3];
	usart.tx[0] = { .port = GPIO_PORT_B, .pin = 10, .af = 0 };
	usart.tx[1] = { .port = GPIO_PORT_C, .pin = 10, .af = 1 };
	usart.tx[2] = { .port = GPIO_PORT_D, .pin = 8, .af = 3 };
	usart.rx = new GpioPinDef[3];
	usart.rx[0] = { .port = GPIO_PORT_B, .pin = 11, .af = 0 };
	usart.rx[1] = { .port = GPIO_PORT_C, .pin = 11, .af = 1 };
	usart.rx[2] = { .port = GPIO_PORT_D, .pin = 9, .af = 3 };
	boardUSARTs[2] = usart;
	
	
	return true;
}

bool initialized = init();
