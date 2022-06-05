/*
	board_definition.h - board definition file for the ST Nucleo-F334R8 board.
	
	MCU: STM32F334R8
	
	2021/02/24, Maya Posch
*/




#include "../board_types.h"
#include <rcc.h>
#include <usart.h>


RccSysClockConfig maxSysClockCfg;
BoardLED boardLEDs[1];
BoardButton boardButtons[1];
USART_def boardUSARTs[2];

uint8_t boardLEDs_count = 1;
uint8_t boardButtons_count = 1;

uint8_t boardUSART_count = 3;
static GpioPinDef usartTxDef[3];
static GpioPinDef usartRxDef[3];

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
	bl.pin.port = GPIO_PORT_A;
	bl.pin.pin = 5;
	bl.pin.pupd = GPIO_PULL_UP;
	bl.pin.type = GPIO_PUSH_PULL;
	bl.pin.speed = GPIO_LOW;
	bl.rgb = { 0, 0xff, 0 };
	boardLEDs[0] = bl;

	BoardButton bb;
	bb.pin = { GPIO_PORT_C, 13, GPIO_PULL_UP };
	boardButtons[0] = bb;
	
	USART_def usart;
	usart.usart = USART_1;
	usart.configs = 2;
	usartTxDef[0] = { .port = GPIO_PORT_A, .pin = 9, .af = 7 };
	usartTxDef[1] = { .port = GPIO_PORT_C, .pin = 4, .af = 7 };
	usart.tx = usartTxDef;
	usartRxDef[0] = { .port = GPIO_PORT_A, .pin = 10, .af = 7 };
	usartRxDef[1] = { .port = GPIO_PORT_C, .pin = 5, .af = 7 };
	usart.rx = usartRxDef;
	boardUSARTs[0] = usart;
	
	usart.usart = USART_2;
	usart.configs = 2;
	usartTxDef[0] = { .port = GPIO_PORT_A, .pin = 2, .af = 7 };
	usartTxDef[1] = { .port = GPIO_PORT_B, .pin = 3, .af = 7 };
	usart.tx = usartTxDef;
	usartRxDef[0] = { .port = GPIO_PORT_A, .pin = 3, .af = 7 };
	usartRxDef[1] = { .port = GPIO_PORT_B, .pin = 4, .af = 7 };
	usart.rx = usartRxDef;
	boardUSARTs[1] = usart;
	
	usart.usart = USART_3;
	usart.configs = 3;
	usartTxDef[0] = { .port = GPIO_PORT_B, .pin = 9, .af = 7 };
	usartTxDef[1] = { .port = GPIO_PORT_B, .pin = 10, .af = 7 };
	usartTxDef[2] = { .port = GPIO_PORT_C, .pin = 10, .af = 7 };
	usart.tx = usartTxDef;
	usartRxDef[0] = { .port = GPIO_PORT_B, .pin = 8, .af = 7 };
	usartRxDef[1] = { .port = GPIO_PORT_B, .pin = 11, .af = 7 };
	usartRxDef[2] = { .port = GPIO_PORT_C, .pin = 11, .af = 7 };
	usart.rx = usartRxDef;
	boardUSARTs[2] = usart;
	
	
	return true;
}

bool initialized = init();
