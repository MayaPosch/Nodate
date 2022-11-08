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
#if defined __stm32f4 || defined __stm32f7 || defined __stm32f1
	if (rtc_enabled) { return true; }
	
#ifndef __stm32f1
	// Use LSI for the RTC. Ensure it's enabled.
	/* RCC->CSR |= RCC_CSR_LSION;
	while ((RCC->CSR & RCC_CSR_LSIRDY) != RCC_CSR_LSIRDY) {
		// TODO: handle time-out.
	} */
#endif
	
	// Enable PWR and the backup domain (BKP)
	if (!Rcc::enable(RCC_PWR)) { return false; }
	if (!Rcc::enable(RCC_BKP)) { return false; }
	
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
	
#ifdef __stm32f1
	
	// TODO: Allow selecting RTC clock source.
	// Configure LSI as RTC clock source.
	// Enable RTC clock.
	// (RCC->BDCR & ~RCC_BDCR_RTCSEL)
	//RCC->BDCR |= RCC_BDCR_RTCEN | RCC_BDCR_RTCSEL_LSI;
	
	// Enable the LSE as input.
	// First reset the backup domain.
	RCC->BDCR |= RCC_BDCR_BDRST;
	RCC->BDCR &= ~RCC_BDCR_BDRST;
	RCC->BDCR |= RCC_BDCR_LSEON; // Enable LSE
	while ((RCC->BDCR & RCC_BDCR_LSERDY) == 0) { } // External Low Speed oscillator Ready?
	RCC->BDCR |= RCC_BDCR_RTCSEL_LSE; 	// Select Source
	
	// Enable the RTC.
	RCC->BDCR |= RCC_BDCR_RTCEN;
	
	//RTC->CRL &= ~RTC_CRL_RSF; // Clear RSF
	//while ((RTC->CRL & RTC_CRL_RSF) == 0) { } // wait for sync
	
	// Disable PWR.
	//if (!Rcc::disable(RCC_PWR)) { return false; }
	
	// Poll RTOFF to ensure RTC is ready.
	while ((RTC->CRL & RTC_CRL_RTOFF) != RTC_CRL_RTOFF) {
		// TODO: Handle timeout.
	}
	
	// Set CNF to enter configuration mode.
	RTC->CRL |= RTC_CRL_CNF;
	
	//RTC->PRLL = 0x7FFF; //signal period of 1sec.
	//RTC->PRLL = 0x32; 
	//signal period of 1sec.
	
	// Set prescaler.
	RTC->PRLH = 0x0000;
	RTC->PRLL = 0x7FFF; // Signal period of 1 sec.
	 
	// Reset 32bit counter
	//RTC->CNTH = 0x0000;
	//RTC->CNTL = 0x0000;
	
	// Configure interrupts.
	EXTI->IMR |= EXTI_IMR_MR17;		// Unmask line 17.
	EXTI->RTSR |= EXTI_RTSR_TR17;	// Trigger on rising edge.
	
	// Set the alarm time. Resolution is 1 second.
	//uint32_t alarmval = 1;
	//RTC->ALRH = alarmval >> 16;				// Set the ALARM MSB word.
	//RTC->ALRL = (alarmval & RTC_ALRL_RTC_ALR); 	// Set the ALARM LSB word.
	
	// Enable alarm interrupt.
	// TODO: implement.
	//RTC->CRH |= RTC_CRH_ALRIE;
	
#else
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
#endif

#if defined __stm32f0 || defined __stm32f1
	NVIC_SetPriority(RTC_IRQn, 0);	// RTC IRQ priority.
	NVIC_EnableIRQ(RTC_IRQn);		// Enable IRQ in NVIC.
#else
 	NVIC_SetPriority(RTC_Alarm_IRQn, 0);	// RTC IRQ priority.
	NVIC_EnableIRQ(RTC_Alarm_IRQn);			// Enable IRQ in NVIC.
#endif
	
	// End configuration phase.
#if defined __stm32f1
	// Unset CNF to leave configuration mode.
	RTC->CRL &= ~RTC_CRL_CNF;
	
	// Poll RTOFF to ensure RTC is ready.
	while ((RTC->CRL & RTC_CRL_RTOFF) != RTC_CRL_RTOFF) {
		// TODO: Handle timeout.
	}
#endif
	
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
	// No usable RTC peripheral exists.
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
#if defined __stm32f1
	// Get value in BCD format.
	register uint16_t high = 0, low = 0;

	high = RTC->CNTH & RTC_CNTH_RTC_CNT;
	low  = RTC->CNTL & RTC_CNTL_RTC_CNT;
	//uint32_t ticks =  bcd2dec32((uint32_t)(((uint32_t) high << 16U) | low));
	uint32_t ticks =  (uint32_t)(((uint32_t) high << 16U) | low);
#endif
	
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
