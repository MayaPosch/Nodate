/*
	rtc.cpp - Real-Time Clock module.
	
	Revision 0
	
	Features:
			-
			
	Notes:
			-
			
	2020/09/23, Maya Posch
*/


#include <rtc.h>
#include <rcc.h>

bool rtc_enabled = false;


// --- ENABLE RTC ---
bool Rtc::enableRTC() {
	//
#if defined RTC_TR_SU
	if (rtc_enabled) { return true; }
	if (!Rcc::enable(RCC_PWR)) { return false; }
	
	// Enable PWR backup access.
	PWR->CR |= PWR_CR_DBP;
	
	// Wait for DBP to be enabled.
	while (!(PWR->CR & PWR_CR_DBP)) {
		// TODO: handle time-out.
	}
	
	// TODO: configure RTC.
	
	// Enable RTC clock.
	RCC->BDCR |= RCC_BDCR_RTCEN;
	while (!(RCC->BDCR & RCC_BDCR_RTCEN)) {
		// TODO: handle time-out.
	}
	
	rtc_enabled = true;
	
	return true;
#else
	// No usable RTC peripheral exists. Return -1.
	return false;
#endif 
}


// --- DISABLE RTC ---
bool Rtc::disableRTC() {
	//
	
	return true;
}
