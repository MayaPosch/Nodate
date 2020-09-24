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
#if defined __stm32f4
	if (rtc_enabled) { return true; }
	
	// Use LSI for the RTC. Ensure it's enabled.
	RCC->CSR |= RCC_CSR_LSION;
	while ((RCC->CSR & RCC_CSR_LSIRDY) != RCC_CSR_LSIRDY) {
		// TODO: handle time-out.
	}
	
	// Enable PWR.
	if (!Rcc::enable(RCC_PWR)) { return false; }
	
	// Enable PWR backup access.
	PWR->CR |= PWR_CR_DBP;
	
	// Wait for DBP to be enabled.
	while (!(PWR->CR & PWR_CR_DBP)) {
		// TODO: handle time-out.
	}
	
	// Reset backup domain.
	//RCC->BDCR |= RCC_BDCR_BDRST;
	
	// Configure LSI as RTC clock source.
	// Enable RTC clock.
	RCC->BDCR = (RCC->BDCR & ~RCC_BDCR_RTCSEL) | RCC_BDCR_RTCEN | RCC_BDCR_RTCSEL_1;
	
	// Disable PWR.
	if (!Rcc::disable(RCC_PWR)) { return false; }
	
	// RTC init phase.
	
	// Unlock RTC write protection.
	RTC->WPR = 0xCA;
	RTC->WPR = 0x53;
	
	// Enable RTC init phase.
	RTC->ISR |= RTC_ISR_INIT;
	while ((RTC->ISR & RTC_ISR_INITF) != RTC_ISR_INITF) {
		// TODO: handle time-out.
	}
	
	// End backup domain reset.
	//RCC->BDCR &= ~(RCC_BDCR_BDRST);
	
	// Clear RTC init state.
	RTC->ISR &= ~(RTC_ISR_INIT);
	
	// Disable write access.
	RTC->WPR = 0xFE;
	RTC->WPR = 0x64; 
	
	// Wait for RTC APB register synchronisation.
	/* int i = 10000;
	while (!(RTC->ISR & RTC_ISR_RSF) || i < 1) {
		// TODO: handle time-out.
		i--;
	} */
	
	rtc_enabled = true;
	
	return true;
#else
	// No usable RTC peripheral exists. Return -1.
	return false;
#endif 
}


// --- DISABLE RTC ---
bool Rtc::disableRTC() {
	if (!rtc_enabled) { return true; }
	
	RCC->BDCR &= ~(RCC_BDCR_RTCEN);
	
	rtc_enabled = false;
	
	return true;
}
