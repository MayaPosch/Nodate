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
#include <iostream>


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
	
	// --- Sysclock/Flash ---
	// - if RCC_CR_HSION == 1 -> set RCC_CR_HSIRDY to 1
	if ((RCC->CR & RCC_CR_HSION) && !(RCC->CR & RCC_CR_HSIRDY)) { 
		RCC->CR |= RCC_CR_HSIRDY; std::cout << "Set HSERDY.\n";
	}
	
	// - if RCC_CR_HSEON == 1 -> set RCC_CR_HSERDY to 1
	if ((RCC->CR & RCC_CR_HSEON) && !(RCC->CR & RCC_CR_HSERDY)) { 
		RCC->CR |= RCC_CR_HSERDY; std::cout << "Set HSERDY.\n";
	}
	
	// - if RCC_CR_PLLON == 1 -> set RCC_CR_PLLRDY to 1.
	if ((RCC->CR & RCC_CR_PLLON) && !(RCC->CR & RCC_CR_PLLRDY)) { 
		RCC->CR |= RCC_CR_PLLRDY; std::cout << "Set PLLRDY.\n"; 
	}
	
	// - if RCC_CFGR_SW_PLL == 1 -> set RCC_CFGR_SWS_PLL to 1.
	if ((RCC->CFGR & RCC_CFGR_SW_PLL) && !(RCC->CFGR & RCC_CFGR_SWS_PLL)) {
		RCC->CFGR |= RCC_CFGR_SWS_PLL; std::cout << "Set SWS PLL.\n";
	}
}
