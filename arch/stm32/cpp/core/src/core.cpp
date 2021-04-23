/*
	core.cpp - Core Cortex-M functionality.
	
	2021/04/12, Maya Posch
*/


#include <nodate.h>
#include <core.h>


// Static initialisations.
bool McuCore::systick_active = false;
__IO uint32_t McuCore::uwTick;
uint32_t McuCore::uwTickPrio = (1UL << __NVIC_PRIO_BITS);
uint32_t McuCore::uwTickFreq = 1; // 1 KHz


// SysTick interrupt handler
extern "C" {
	void SysTick_Handler(void);
}

void SysTick_Handler() {
	McuCore::uwTick++;
}


bool McuCore::initSysTick(uint32_t tickPriority) {
	if (systick_active) { return true; }
	
	// Configure the SysTick to have interrupt in 1ms time basis.
	//(HAL_SYSTICK_Config(SystemCoreClock / (1000U / uwTickFreq)) > 0U)
	uint32_t ticks = SystemCoreClock / (1000U / uwTickFreq);
    if ((ticks - 1UL) > SysTick_LOAD_RELOAD_Msk) {
		return false; // Reload value impossible.
	}

	SysTick->LOAD  = (uint32_t) (ticks - 1UL);			// set reload register
	NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL); // set Priority for Systick interrupt
	SysTick->VAL   = 0UL;                                             // Load the SysTick Counter Value
	SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_TICKINT_Msk   |
                   SysTick_CTRL_ENABLE_Msk;                         // Enable SysTick IRQ and SysTick Timer

	// Configure the SysTick IRQ priority.
	if (tickPriority < (1UL << __NVIC_PRIO_BITS))   {
		uint32_t prioritygroup = NVIC_GetPriorityGrouping();
		NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(prioritygroup, tickPriority, 0));
		uwTickPrio = tickPriority;
	}
	else {
		return false;
	}
	
	systick_active = true;

	return true;
}


bool McuCore::stopSysTick() {
	// Disable the SysTick timer
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
	systick_active = false;
	
	return true;
}


uint32_t McuCore::getSysTick() {
	return uwTick;
}
