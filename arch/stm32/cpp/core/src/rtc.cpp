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
	// TODO: instead of the LSI, the LSE should be available as optional RTC clock source.
#if defined __stm32f4 || defined __stm32f7
	if (rtc_enabled) { return true; }
	
	// Use LSI for the RTC. Ensure it's enabled.
	RCC->CSR |= RCC_CSR_LSION;
	while ((RCC->CSR & RCC_CSR_LSIRDY) != RCC_CSR_LSIRDY) {
		// TODO: handle time-out.
	}
	
	// Enable PWR.
	if (!Rcc::enable(RCC_PWR)) { return false; }
	
	// Enable PWR backup access.
#if defined __stm32f7
	PWR->CR1 |= PWR_CR1_DBP;
#else
	PWR->CR |= PWR_CR_DBP;
#endif
	
	// Wait for DBP to be enabled.
	/* while (!(PWR->CR & PWR_CR_DBP)) {
		// TODO: handle time-out.
	} */
	
	// Reset backup domain.
	//RCC->BDCR |= RCC_BDCR_BDRST;
	
	// Configure LSI as RTC clock source.
	// Enable RTC clock.
	RCC->BDCR = (RCC->BDCR & ~RCC_BDCR_RTCSEL) | RCC_BDCR_RTCEN | RCC_BDCR_RTCSEL_1;
	
	// Disable PWR.
	if (!Rcc::disable(RCC_PWR)) { return false; }
	
	// Disable alarm A to modify it.
	// Wait for the action to complete.
	RTC->CR &=~ RTC_CR_ALRAE;
	while((RTC->ISR & RTC_ISR_ALRAWF) != RTC_ISR_ALRAWF) {
		// TODO: handle time-out.
	}
	
	// Have alarm A generate interrupt each 1 Hz.
	RTC->ALRMAR = RTC_ALRMAR_MSK4 | RTC_ALRMAR_MSK3 | RTC_ALRMAR_MSK2 | RTC_ALRMAR_MSK1;
	
	// Enable alarm A and its interrupt.
	RTC->CR = RTC_CR_ALRAIE | RTC_CR_ALRAE;
	
	// Disable write access.
	RTC->WPR = 0xFE;
	RTC->WPR = 0x64; 
	
	// Configure interrupts.
	EXTI->IMR |= EXTI_IMR_MR17;		// Unmask line 17.
	EXTI->RTSR |= EXTI_RTSR_TR17;	// Trigger on rising edge.
#if defined __stm32f0
	NVIC_SetPriority(RTC_IRQn, 0);	// RTC IRQ priority.
	NVIC_EnableIRQ(RTC_IRQn);		// Enable IRQ in NVIC.
#else
	NVIC_SetPriority(RTC_Alarm_IRQn, 0);	// RTC IRQ priority.
	NVIC_EnableIRQ(RTC_Alarm_IRQn);			// Enable IRQ in NVIC.
#endif
	
	// End configuration phase.
	
	// RTC init phase.
	Rtc::setTime(0); // Set time to 0.
	
	
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


// --- SET TIME ---
bool Rtc::setTime(uint32_t time) {
#if defined __stm32f4 || defined __stm32f7
	// Unlock RTC write protection.
	RTC->WPR = 0xCA;
	RTC->WPR = 0x53;
	
	// Enable RTC init phase.
	RTC->ISR |= RTC_ISR_INIT;
	while ((RTC->ISR & RTC_ISR_INITF) != RTC_ISR_INITF) {
		// TODO: handle time-out.
	}
	
	RTC->PRER = 0x007F0137;	// Set prescaler: 40 kHz / 128 = 312 kHz, 312 / 312 = 1 Hz.
	RTC->TR = RTC_TR_PM | time;
	
	// Clear RTC init state.
	RTC->ISR &= ~(RTC_ISR_INIT);
	
	// Disable write access.
	RTC->WPR = 0xFE;
	RTC->WPR = 0x64; 
#endif
	
	return true;
}



/**
  * @brief  Converts from 2 digit BCD to Binary.
  * @param  Value BCD value to be converted
  * @retval Converted word
  */
uint8_t bcd2ToByte(uint8_t value) {
  uint32_t tmp = 0U;
  tmp = ((uint8_t)(value & (uint8_t) 0xF0) >> (uint8_t) 0x4) * 10;
  return (tmp + (value & (uint8_t) 0x0F));
}


// --- GET TIME ---
bool Rtc::getTime(RtcTime &time) {
#if defined __stm32f4
	uint32_t currentTime = RTC->TR;
	//time.hour_tens = (uint8_t) (((currentTime & RTC_TR_HT) >> 20) + 48);
	time.hour_tens = (uint8_t) bcd2ToByte(((currentTime & RTC_TR_HT) >> 20));
	time.hour_units = (uint8_t) bcd2ToByte(((currentTime & RTC_TR_HU) >> 16));
	time.minute_tens = (uint8_t) bcd2ToByte(((currentTime & RTC_TR_MNT) >> 12));
	time.minute_units = (uint8_t) bcd2ToByte(((currentTime & RTC_TR_MNU) >> 8));
	time.second_tens = (uint8_t) bcd2ToByte(((currentTime & RTC_TR_ST) >> 4));
	time.second_units = (uint8_t) bcd2ToByte(((currentTime & RTC_TR_SU)));
#endif
	
	return true;
}


// --- GET TIME ---
bool Rtc::getTime(char* t, uint8_t &len) {
	//
	
	return true;
}


// --- GET DATE ---
bool Rtc::getDate() {
	//
	
	return true;
}


// --- GET DATE ---
bool Rtc::getDate(char* date, uint8_t &len) {
	//
	
	return true;
}


// --- DISABLE RTC ---
bool Rtc::disableRTC() {
	if (!rtc_enabled) { return true; }
	
#if defined __stm32f0
	NVIC_DisableIRQ(RTC_IRQn);
#else
	NVIC_DisableIRQ(RTC_Alarm_IRQn);
#endif
	
#if defined __stm32f4
	RCC->BDCR &= ~(RCC_BDCR_RTCEN);
#endif
	
	rtc_enabled = false;
	
	return true;
}
