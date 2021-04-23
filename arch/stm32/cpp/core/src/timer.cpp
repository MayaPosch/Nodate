/*
	timer.cpp - Implementation file for the Timer class.
*/


#include "timer.h"

#include <nodate.h>


#ifdef NODATE_TIMER_ENABLED


// Delay counter
//static volatile uint32_t DelayCounter;


// SysTick interrupt handler
/* extern "C" {
	void SysTick_Handler(void);
}

void SysTick_Handler() {
	DelayCounter++;
} */


// --- CONSTRUCTOR ---
Timer::Timer() {
	// Ensure we got a running SysTick.
	McuCore::initSysTick();
	
	// Set reload register to generate an interrupt every millisecond.
	/* SysTick->LOAD = (uint32_t)((SystemCoreClock / 1000) - 1);

	// Set priority for SysTick IRQ
	//NVIC_SetPriority(SysTick_IRQn,(1 << __NVIC_PRIO_BITS) - 1);

	// Reset the SysTick counter value.
	SysTick->VAL = 0UL;

	// Set SysTick source and IRQ.
	SysTick->CTRL = (SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk); */
}


// --- DESTRUCTOR ---
Timer::~Timer() {
	//
}


// --- DELAY ---
void Timer::delay(uint32_t ms) {
	uint32_t start = McuCore::getSysTick();
	uint32_t delay = ms;
	
	// TODO: if () { }
	
	while ((McuCore::getSysTick() - start) < delay) { }
	
	// Enable the SysTick timer
	//SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

	// Wait for a specified number of milliseconds
	//DelayCounter = 0;
	//while (DelayCounter < ms);

	// Disable the SysTick timer
	//SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

#endif
