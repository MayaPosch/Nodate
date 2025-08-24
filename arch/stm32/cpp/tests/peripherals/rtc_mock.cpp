/*
	rtc_mock.cpp - Nodate mock RTC peripheral implementation.
	
	Features:
		- Simulates an STM32 RTC peripheral by updating the relevant registers.
			
	Notes:
		- 
*/


#include "rtc_mock.h"

#include "../common.h"

#include <functional>


// --- CONSTRUCTOR ---
RTC_mock::RTC_mock() {
	// We need to monitor a few registers which require a response. 
	// Set up a polling loop for this using a ChronoTrigger callback.
	// The integer parameter is currently unused.
	//ct.setCallback(std::bind(&RTC_mock::callback, this, 0));
	ct.setCallback(RTC_mock::callback, 0);
	ct.start(100); // Trigger every 100 ms.
}


// --- DESTRUCTOR ---
RTC_mock::~RTC_mock() {
	// Stop the timer.
	ct.stop();
}


// --- CALLBACK ---
void RTC_mock::callback(int value) {
	// Registers to monitor:
#ifdef __stm32f1
	// - if RTC_CRL_RSF 	== 0 -> set RTC_CRL_RSF to 1
	if ((RTC->CRL & RTC_CRL_RSF) == 0) { RTC->CRL |= RTC_CRL_RSF; }	// Sync complete.

	// - if RTC_CRL_RTOFF 	== 0 -> set RTC_CRL_RTOFF  to 1
	if ((RTC->CRL & RTC_CRL_RTOFF) == 0) { RTC->CRL |= RTC_CRL_RTOFF; }
	
#else
	
#ifdef RTC_ISR_INIT
	// - if RTC_ISR_INIT 	== 0 -> set RTC_ISR_INITF to 1
	if ((RTC->ISR & RTC_ISR_INIT) == 1) { RTC->ISR |= RTC_ISR_INITF; }	// Init mode started.
	else { RTC->ISR &= RTC_ISR_INITF; }
#else
	if ((RTC->ICSR & RTC_ICSR_INIT) == 1) { RTC->ISR |= RTC_ISR_INITF; }	// Init mode started.
	else { RTC->ICSR &= RTC_ICSR_INITF; }
#endif
	
	
#endif
}
