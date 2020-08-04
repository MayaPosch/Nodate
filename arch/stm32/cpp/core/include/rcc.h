/*
	rcc.h - Header to provide access to RCC functionality.
	
*/


#ifndef GPIO_H
#define GPIO_H


#include "common.h"

#include <vector>


enum RccPeripheral {
	RCC_TSC = 0,	// AHB peripherals
	RCC_CRC,
	RCC_FLITF,
	RCC_SRAM,
	RCC_DMA2,
	RCC_DMA,
	RCC_SYSCFG,		// APB peripherals
	
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
	uint32_t enable;
};


class RCC {
	static std::vector<RccPortHandle>& portHandles();
	
	static bool initPorts();
	
public:
	static bool enable(RccPeripheral peripheral);
	static bool disable(RccPeripheral peripheral);
	static bool enablePort(RccPort port);
	static bool disablePort(RccPort port);
}


#endif