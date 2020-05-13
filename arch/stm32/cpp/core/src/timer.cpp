/*
	timer.cpp - Implementation file for the Timer class.
*/


#include "timer.h"


// Delay counter
static __IO uint32_t DelayCounter;


// SysTick interrupt handler
void SysTick_Handler() {
	DelayCounter++;
}


// --- CONSTRUCTOR ---
Timer::Timer() {
	// Configure the SysTick for ms resolution.
	
	// Set reload register to generate IRQ every millisecond
	SysTick->LOAD = (uint32_t)(SystemCoreClock / (1000UL - 1UL));

	// Set priority for SysTick IRQ
	NVIC_SetPriority(SysTick_IRQn,(1 << __NVIC_PRIO_BITS) - 1);

	// Set the SysTick counter value
	SysTick->VAL = 0UL;

	// Set SysTick source and IRQ
	SysTick->CTRL = (SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk);
}


// --- DESTRUCTOR ---
Timer::~Timer() {
	//
}


// --- DELAY ---
void Timer::delay(uint32_t ms) {
	// Enable the SysTick timer
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

	// Wait for a specified number of milliseconds
	DelayCounter = 0;
	while (DelayCounter < ms);

	// Disable the SysTick timer
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}
