
#ifndef STM32_H
#define STM32_H


#include <common.h>



// --- RCC ---

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


//RccPortHandle* portHandles();
//RccPeripheralHandle* peripheralHandles();

extern RccPortHandle* portHandlesStatic;
extern RccPeripheralHandle* perHandlesStatic;

extern const int portCount;
extern const int peripheralCount;


// --- GPIO ---

enum GPIO_mode {
	GPIO_INPUT	= 0,
	GPIO_OUTPUT	= 1,
	GPIO_ALTERNATE = 2,
	GPIO_ANALOG = 3
};


enum GPIO_pupd {
	GPIO_FLOATING = 0,
	GPIO_PULL_UP = 1,
	GPIO_PULL_DOWN = 2
};


enum GPIO_out_speed {
	GPIO_LOW = 0,
	GPIO_MID = 1,
	GPIO_HIGH = 2
};


enum GPIO_out_type {
	GPIO_PUSH_PULL = 0,
	GPIO_OPEN_DRAIN = 1
};


enum GPIO_level {
	GPIO_LEVEL_UNKNOWN = 0,
	GPIO_LEVEL_LOW = 1,
	GPIO_LEVEL_HIGH = 2
};


enum GPIO_ports {
	GPIO_PORT_A = 0,
	GPIO_PORT_B,
	GPIO_PORT_C,
	GPIO_PORT_D,
	GPIO_PORT_E,
	GPIO_PORT_F,
	GPIO_PORT_G,
	GPIO_PORT_H,
	GPIO_PORT_I,
	GPIO_PORT_J,
	GPIO_PORT_K,
	GPIO_PORT_L
};


struct GPIO_instance {
	bool active = false;
	GPIO_TypeDef* regs;
};


//GPIO_instance* GPIO_instances();

extern GPIO_instance* instancesStatic;

extern const int gpioCount;


// --- 


#endif
