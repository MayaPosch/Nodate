/*
	rcc.h - Header to provide access to RCC functionality.
	
*/


#ifndef RCC_H
#define RCC_H


#include <common.h>


enum RccPeripheral {
	RCC_TSC = 0,	// AHB peripherals
	RCC_CRC,
	RCC_FLITF,
	RCC_SRAM,
	RCC_DMA2,
	RCC_DMA1,
	RCC_ETH,
	RCC_SYSCFGCOMP,		// APB2 peripherals
	RCC_USART6,
	RCC_USART7,
	RCC_USART8,
	RCC_ADC1,
	RCC_ADC2,
	RCC_ADC3,
	RCC_TIM1,
	RCC_SPI1,
	RCC_USART1,
	RCC_TIM15,
	RCC_TIM16,
	RCC_TIM17,
	RCC_DBGMCU,
	RCC_AFIO,
	RCC_TIM2,		// APB1 peripherals
	RCC_TIM3,
	RCC_TIM4,
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
	RCC_DAC1,
	RCC_DAC2,
	RCC_CEC,
	RCC_SPI3,
	RCC_SPI4,
	RCC_SPI5
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
	RCC_PORT_F,
	RCC_PORT_G,
	RCC_PORT_H,
	RCC_PORT_I,
	RCC_PORT_J,
	RCC_PORT_K
};


struct RccPortHandle {
	uint8_t count = 0;
	bool exists = false;
	volatile uint32_t* enr;
	uint32_t enable;
};


enum RccSysClockSrc {
	RCC_SYSCLOCK_SRC_HSI = 0,
	RCC_SYSCLOCK_SRC_HSE,
	RCC_SYSCLOCK_SRC_PLL
};


enum RccPllClockSrc {
	RCC_PLLCLOCK_SRC_HSI = 0,
	RCC_PLLCLOCK_SRC_HSE
};


struct RccSysClockConfig {
	RccSysClockSrc source;
	uint32_t base_freq;		// Frequency (Hz) of the HSE/HSI source.
	bool HSE_bypass = false;
	bool HSI_enabled = true;
	bool PLL_enabled = false;
	RccPllClockSrc PLL_source;
	uint32_t PLLM;
	uint32_t PLLN;
	uint32_t PLLP;
	uint32_t PLLQ;
	uint32_t AHB_prescale;
	uint32_t APB1_prescale;
	uint32_t APB2_prescale;
	uint8_t FLASH_latency;	// Wait states.
};


class Rcc {
	//
	
public:
	static bool enable(RccPeripheral peripheral);
	static bool disable(RccPeripheral peripheral);
	static bool enablePort(RccPort port);
	static bool disablePort(RccPort port);
	
	static bool configureSysClock(RccSysClockConfig cfg);
	static bool enableLSE(bool on);
};


#endif
