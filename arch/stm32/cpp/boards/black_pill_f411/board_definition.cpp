/*
	board_definition.cpp - board definition file for the F411-based 'Black Pill' board.
	
	MCU: STM32F411CE
	
	2021/02/24, Maya Posch
*/




#include "../board_types.h"
#include <rcc.h>
#include <usart.h>


RccSysClockConfig maxSysClockCfg;
BoardLED boardLEDs[1];
BoardButton boardButtons[1];
USART_def boardUSARTs[3];

uint8_t boardLEDs_count = 3;
uint8_t boardButtons_count = 1;
uint8_t boardUSART_count = 3;

bool init() {
	// Target frequency: 100 MHz.
	// Input: 25 MHz HSE, no bypass.
	maxSysClockCfg.source 		= RCC_SYSCLOCK_SRC_PLL;
	maxSysClockCfg.HSE_bypass 	= false;
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

	// LED
	BoardLED bl;
	bl.pin.port = GPIO_PORT_C;
	bl.pin.pin = 13;
	bl.pin.pupd = GPIO_PULL_UP;
	bl.pin.type = GPIO_PUSH_PULL;
	bl.pin.speed = GPIO_LOW;
	bl.rgb = { 0, 0xff, 0 };
	boardLEDs[0] = bl;

	// Button
	BoardButton bb;
	bb.pin = { GPIO_PORT_A, 0, GPIO_PULL_UP };
	boardButtons[0] = bb;
	
	// USART
	USART_def usart;
	usart.usart = USART_1;
	usart.configs = 3;
	usart.tx = new GpioPinDef[3];
	usart.tx[0] = { .port = GPIO_PORT_A, .pin = 9, .af = 7 };
	usart.tx[1] = { .port = GPIO_PORT_A, .pin = 15, .af = 7 };
	usart.tx[1] = { .port = GPIO_PORT_B, .pin = 6, .af = 7 };
	usart.rx = new GpioPinDef[3];
	usart.rx[0] = { .port = GPIO_PORT_A, .pin = 10, .af = 7 };
	usart.rx[1] = { .port = GPIO_PORT_B, .pin = 3, .af = 7 };
	usart.rx[1] = { .port = GPIO_PORT_B, .pin = 7, .af = 7 };
	boardUSARTs[0] = usart;
	
	usart.usart = USART_2;
	usart.configs = 2;
	usart.tx = new GpioPinDef[2];
	usart.tx[0] = { .port = GPIO_PORT_A, .pin = 2, .af = 7 };
	usart.tx[1] = { .port = GPIO_PORT_D, .pin = 5, .af = 7 };
	usart.rx = new GpioPinDef[2];
	usart.rx[0] = { .port = GPIO_PORT_A, .pin = 3, .af = 7 };
	usart.rx[1] = { .port = GPIO_PORT_D, .pin = 6, .af = 7 };
	boardUSARTs[1] = usart;
	
	usart.usart = USART_6;
	usart.configs = 2;
	usart.tx = new GpioPinDef[2];
	usart.tx[0] = { .port = GPIO_PORT_A, .pin = 11, .af = 8 };
	usart.tx[1] = { .port = GPIO_PORT_C, .pin = 6, .af = 8 };
	usart.rx = new GpioPinDef[2];
	usart.rx[0] = { .port = GPIO_PORT_A, .pin = 12, .af = 8 };
	usart.rx[1] = { .port = GPIO_PORT_C, .pin = 7, .af = 8 };
	boardUSARTs[2] = usart;
	
	return true;
}

bool initialized = init();
