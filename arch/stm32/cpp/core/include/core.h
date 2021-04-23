/*
	core.h - Header file for the Cortex-M core functionality.
	
	2021/04/12, Maya Posch
*/


#ifndef NODATE_CORE_H
#define NODATE_CORE_H

#include <common.h>


class McuCore {
	static bool systick_active;
	static uint32_t uwTickPrio;
	static uint32_t uwTickFreq;
	
public:
	static __IO uint32_t uwTick;
	
	static bool initSysTick(uint32_t tickPriority = 0x0F);
	static bool stopSysTick();
	static uint32_t getSysTick();
};


#endif
