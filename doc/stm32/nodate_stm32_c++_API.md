# Nodate STM32 C++ API #

This document contains the documentation for the current C++ STM32 APIs, as available in the Nodate framework. These should be up to date if this file is part of an official release, otherwise be sure to look in the header files for the relevant modules for any new updates.

Each section in this document describes a particular module, its functions and possible values for each argument.

<a id="toc"></a>
**Table of Contents**

1. [RCC](#rcc)
2. [GPIO](#gpio)
3. [USART](#usart)
4. [Timer](#timer)
5. [Clock](#clock)
6. [IO](#io)



<a id="rcc"></a>
## RCC ##

**Peripherals**

```cpp

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

```

**Ports**

```cpp
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
```

**Rcc class**

```cpp
	class Rcc {
	public:
		static bool enable(RccPeripheral peripheral);
		static bool disable(RccPeripheral peripheral);
		static bool enablePort(RccPort port);
		static bool disablePort(RccPort port);
	};
```


<a id="gpio"></a>
## GPIO ##

-

<a id="usart"></a>
## USART ##

-

<a id="timer"></a>
## Timer ##

-

<a id="clock"></a>
## Clock ##

-

<a id="io"></a>
## IO ##

-

