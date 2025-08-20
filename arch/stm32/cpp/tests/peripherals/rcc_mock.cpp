/*
	rcc_mock.cpp - Nodate mock RCC peripheral implementation.
	
	Features:
		- Simulates an STM32 RCC peripheral by updating the relevant registers.
			
	Notes:
		- 
*/


#include "rcc_mock.h"

#include "../common.h"

#include <functional>


// --- CONSTRUCTOR ---
RCC_mock::RCC_mock() {
	// We need to monitor a few registers which require a response. 
	// Set up a polling loop for this using a ChronoTrigger callback.
	// The integer parameter is currently unused.
	//ct.setCallback(std::bind(&RCC_mock::callback, this, 0));
	ct.setCallback(RCC_mock::callback, 0);
	ct.start(100); // Trigger every 100 ms.
}


// --- DESTRUCTOR ---
RCC_mock::~RCC_mock() {
	// Stop the timer.
	ct.stop();
}


// --- CALLBACK ---
void RCC_mock::callback(int value) {
	// Registers to monitor:
	// - if RCC_BDCR_LSEON 	== 1 -> set RCC_BDCR_LSERDY to 1
	if (RCC->BDCR & RCC_BDCR_LSEON) { RCC->BDCR |= RCC_BDCR_LSERDY; }

	// - if RCC_CSR_LSION 	== 1 -> set RCC_CSR_LSIRDY  to 1
	if (RCC->CSR & RCC_CSR_LSION) { RCC->CSR |= RCC_CSR_LSIRDY; }
	
	// - if RCC_BDCR_RTCEN	== 1
}
