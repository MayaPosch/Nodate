/*
	rcc.h - Header to provide access to RCC functionality.
	
*/


#ifndef RCC_H
#define RCC_H


#include <common.h>

#include <vector>


enum RccPeripheral {
	RCC_TSC = 0,	// AHB peripherals
	RCC_CRC,
	RCC_FLITF,
	RCC_SRAM,
	RCC_DMA2,
	RCC_DMA,
	RCC_SYSCFGCOMP,		// APB2 peripherals
	RCC_USART6,
	RCC_USART7,
	RCC_USART8,
	RCC_ADC,
	RCC_TIM1,
	RCC_SPI1,
	RCC_USART1,
	RCC_TIM15,
	RCC_TIM16,
	RCC_TIM17,
	RCC_DBGMCU,
	RCC_TIM2,		// APB1 peripherals
	RCC_TIM3,
	RCC_TIM6,
	RCC_TIM7,
	RCC_TIM14,
	RCC_WWDG,
	RCC_SPI2,
	RCC_USART2,
	RCC_USART3,
	RCC_USART4,
	RCC_USART5,
	RCC_I2C1,
	RCC_I2C2,
	RCC_USB,
	RCC_CAN,
	RCC_CRS,
	RCC_PWR,
	RCC_DAC,
	RCC_CEC
};


struct RccPeripheralHandle {
	uint8_t count = 0;
	bool exists = false;
	volatile uint32_t* enr;
	uint32_t enable;
};


enum RccPort {
	RCC_PORT_A = 0,
	RCC_PORT_B,
	RCC_PORT_C,
	RCC_PORT_D,
	RCC_PORT_E,
	RCC_PORT_F
};


struct RccPortHandle {
	uint8_t count = 0;
	bool exists = false;
	volatile uint32_t* enr;
	uint32_t enable;
};


class Rcc {
	//
	
public:
	static bool enable(RccPeripheral peripheral);
	static bool disable(RccPeripheral peripheral);
	static bool enablePort(RccPort port);
	static bool disablePort(RccPort port);
};


#endif