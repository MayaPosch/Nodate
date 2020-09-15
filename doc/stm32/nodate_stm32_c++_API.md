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

[ToC](#toc)

<a id="gpio"></a>
## GPIO ##

```cpp
enum GPIO_mode {
	GPIO_INPUT	= 0,
	GPIO_OUTPUT	= 1,
	GPIO_ALTERNATE = 2,
	GPIO_ANALOG = 3
};
```

```cpp
enum GPIO_pupd {
	GPIO_FLOATING = 0,
	GPIO_PULL_UP = 1,
	GPIO_PULL_DOWN = 2
};
```

```cpp
enum GPIO_out_speed {
	GPIO_LOW = 0,
	GPIO_MID = 1,
	GPIO_HIGH = 2
};
```

```cpp
enum GPIO_out_type {
	GPIO_PUSH_PULL = 0,
	GPIO_OPEN_DRAIN = 1
};
```

```cpp
enum GPIO_level {
	GPIO_LEVEL_UNKNOWN = 0,
	GPIO_LEVEL_LOW = 1,
	GPIO_LEVEL_HIGH = 2
};
```

```cpp
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
```

```cpp
class GPIO {
public:
	GPIO();
	~GPIO();
	
	bool set_input(GPIO_ports port, uint8_t pin, GPIO_pupd pupd);
	bool set_output(GPIO_ports port, uint8_t pin, GPIO_pupd pupd = GPIO_FLOATING, 
							GPIO_out_type type = GPIO_PUSH_PULL, GPIO_out_speed speed = GPIO_LOW);
	bool set_af(GPIO_ports port, uint8_t pin, uint8_t af);
	bool set_output_parameters(GPIO_ports port, uint8_t pin, GPIO_pupd pupd = GPIO_FLOATING, 
							GPIO_out_type type = GPIO_PUSH_PULL, GPIO_out_speed speed = GPIO_LOW);
	bool write(GPIO_ports port, uint8_t pin, GPIO_level level);
	bool write(GPIO_ports port, uint8_t pin, uint32_t level);
	uint8_t read(GPIO_ports port, uint8_t pin);
	uint32_t readAnalog(GPIO_ports port, uint8_t pin);
};
```

To use this class, create an instance.

[ToC](#toc)

<a id="usart"></a>
## USART ##

```cpp
enum USART_devices {
	USART_1,
	USART_2,
	USART_3,
	USART_4,
	USART_5,
	USART_6
};
```

```cpp
class USART {
	static GPIO gpio;
	
public:
	static bool startUart(USART_devices device, GPIO_ports tx_port, uint8_t tx_pin, uint8_t tx_af,
											GPIO_ports rx_port, uint8_t rx_pin, uint8_t rx_af,
											uint32_t baudrate, std::function<void(char)> callback);
	static bool sendUart(USART_devices device, char &ch);
	static bool stopUart(USART_devices device);
};
```

[ToC](#toc)

<a id="timer"></a>
## Timer ##

```cpp
class Timer {
public:
	Timer();
	~Timer();

	void delay(uint32_t ms);
};
```

[ToC](#toc)

<a id="clock"></a>
## Clock ##

```cpp
class Clock {
	//
	
public:
	Clock();
	~Clock();
	
	bool enableMaxClock();
	uint32_t currentSysClock();
};
```

[ToC](#toc)

<a id="io"></a>
## IO ##

```cpp
class IO {
	static bool stdout_active;
	
public:
	static USART_devices usart;
	
	static bool setStdOutTarget(USART_devices device);
};
```

[ToC](#toc)
