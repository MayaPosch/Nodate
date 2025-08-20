/*
	rtc.cpp - Real-Time Clock module.
	
	Revision 0
	
	Features:
			-
			
	Notes:
			-
			
	2020/09/23, Maya Posch
*/


#include "rtc.h"

#ifdef NODATE_RTC_ENABLED

#include <time.h>

// DEBUG
#include <printf.h>

uint32_t bcd2dec32(uint32_t bcd); // Defined in utils.cpp

#define RTC_BKP_DATE_TIME_UPDATED ((uint32_t) 0x32F2)

bool rtc_enabled = false;

// Newlib implementation of _gettimeofday()
//int _gettimeofday (struct timeval * tp, void * tzvp)
extern "C" {
	int _gettimeofday (struct timeval * tp, void * tzvp);
}

int _gettimeofday (struct timeval * tp, void * tzvp) {
	// Timeval implementation:
	// struct timeval {
	//	time_t      tv_sec;
	//	suseconds_t tv_usec;
	//};
#if defined RTC_TR_SU
	if (!rtc_enabled) {
		if (!Rtc::enableRTC()) { return -1; }
		rtc_enabled = true;
	}
	
	// Fill tms struct from RTC registers.
	// struct tms {
	//		clock_t tms_utime;  /* user time */
	//		clock_t tms_stime;  /* system time */
	//		clock_t tms_cutime; /* user time of children */
	//		clock_t tms_cstime; /* system time of children */
	//	};
	uint32_t tTR = RTC->TR;
	uint32_t ticks = (uint8_t) bcd2dec32(tTR & (RTC_TR_ST | RTC_TR_SU));
	ticks = ticks * SystemCoreClock;
	
	tp->tv_sec = ticks;
	tp->tv_usec = 0;
	
	//return ticks; // Return clock ticks.
	return 0;
#elif defined __stm32f1
	if (!rtc_enabled) {
		if (!Rtc::enableRTC()) { return -1; }
		//rtc_pwr_enabled = true;
	}
	
	// Get value in BCD format.
	register uint16_t high = 0, low = 0;
	
	// TODO: check RSF flag

	high = RTC->CNTH & RTC_CNTH_RTC_CNT;
	low  = RTC->CNTL & RTC_CNTL_RTC_CNT;
	
	// Debug
	printf("H/L: %d - %d.\n", high, low);
	
	uint32_t ticks = bcd2dec32((uint32_t)(((uint32_t) high << 16U) | low));
	//ticks = ticks * SystemCoreClock;
	tp->tv_sec = ticks;
	tp->tv_usec = 0;
	
	return 0;
#else
	// No usable RTC peripheral exists. Return -1.
	return -1;
#endif 
}


#ifdef STM32F1
	// 
	/* extern "C" {
		void RTC_IRQHandler(void);
	}
	
	void RTC_IRQHandler(void) {
		if (LL_RTC_IsEnabledIT_SEC(RTC) != 0) {
			// Clear the RTC Second interrupt.
			LL_RTC_ClearFlag_SEC(RTC);
			Calendar_Callback();
			// Wait until last write operation on RTC registers has finished.
			LL_RTC_WaitForSynchro(RTC);
		}
		
		// Clear the EXTI's Flag for RTC Alarm.
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_17);
	} */
#endif


// --- ENABLE RTC ---
bool Rtc::enableRTC(RtcClock clk) {
	// TODO: instead of the LSI, the LSE should be available as optional RTC clock source.
#if defined __stm32f4 || defined __stm32f7 || defined __stm32f1
	if (rtc_enabled) { return true; }
	
	printf("Enabling PWR, BKP...");
	
	// Enable PWR and the backup domain (BKP)
	if (!Rcc::enable(RCC_PWR)) { return false; }
	if (!Rcc::enable(RCC_BKP)) { return false; }
	
	printf("Check data...");
	
	// TODO: Check that no data is stored in the backup register. In this case the RTC is already
	// configured and should not be reconfigured.
	//if ((BKP->DR1 & BKP_DR1_D) == RTC_BKP_DATE_TIME_UPDATED) {
	if (BKP->DR1 == RTC_BKP_DATE_TIME_UPDATED) {
		// RTC is configured already.
		return true;
	}
	
#ifndef __stm32f1
	// Use LSI for the RTC. Ensure it's enabled.
	/* RCC->CSR |= RCC_CSR_LSION;
	while ((RCC->CSR & RCC_CSR_LSIRDY) != RCC_CSR_LSIRDY) {
		// TODO: handle time-out.
	} */
#endif
	
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
	
	// Configure RTC clock source.
	// Enable RTC clock.
	
	printf("Reset BKP domain...");
	
	// First reset the backup domain.
	RCC->BDCR |= RCC_BDCR_BDRST;
	RCC->BDCR &= ~RCC_BDCR_BDRST;
	
	if (clk == RTC_CLOCK_LSE) {	
		printf("Enable LSE...");
		
		// Enable the LSE as input.
		RCC->BDCR |= RCC_BDCR_LSEON; // Enable LSE
		while ((RCC->BDCR & RCC_BDCR_LSERDY) == 0) { } // External Low Speed oscillator Ready?
		RCC->BDCR |= RCC_BDCR_RTCSEL_LSE; 	// Select Source
	}
	else if (clk == RTC_CLOCK_LSI) {
		printf("Select LSI...");
		RCC->CSR |= RCC_CSR_LSION; // Enable LSI
		while ((RCC->CSR & RCC_CSR_LSIRDY) == 0) { } // Wait until ready. TODO: timeout.
		RCC->BDCR |= RCC_BDCR_RTCSEL_LSI;	// Set source.
	}
	
	printf("Enable RTC...");
	
	// Enable the RTC.
	RCC->BDCR |= RCC_BDCR_RTCEN;
	
	//RTC->CRL &= ~RTC_CRL_RSF; // Clear RSF
	while ((RTC->CRL & RTC_CRL_RSF) == 0) { } // wait for sync
	
	// Disable PWR.
	//if (!Rcc::disable(RCC_PWR)) { return false; }
	
	// Poll RTOFF to ensure RTC is ready.
	while ((RTC->CRL & RTC_CRL_RTOFF) != RTC_CRL_RTOFF) {
		// TODO: Handle timeout.
	}
	
	// Enable RTC second global interrupt.
	RTC->CRH |= RTC_CRH_SECIE;
	
	// Poll for ready.
	while ((RTC->CRL & RTC_CRL_RTOFF) != RTC_CRL_RTOFF) {
		// TODO: Handle timeout.
	}
	
	printf("Disable write protect...");
	
	// Disable write protection and enter configuration mode.
	RTC->CRL |= RTC_CRL_CNF;
	
	printf("Prescaler...");
	
	// Set prescaler.
	if (clk == RTC_CLOCK_LSE) {
		// 32,768 Hz input, ox7FFF gets 1 Hz.
		RTC->PRLH = 0x0000;
		RTC->PRLL = 0x7FFF;
	}
	else if (clk == RTC_CLOCK_LSI) {
		// 40 kHz input.
		RTC->PRLH = 0x0000;
		RTC->PRLL = 0x9C3F;
	}
	 
	// Reset 32bit counter
	RTC->CNTH = 0x0000;
	RTC->CNTL = 0x0000;
	
	printf("Interrupts...");
	
	// Configure interrupts.
	//EXTI->IMR |= EXTI_IMR_MR17;		// Unmask line 17.
	//EXTI->RTSR |= EXTI_RTSR_TR17;	// Trigger on rising edge.
	
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
	//printf("IRQs...");
	//NVIC_SetPriority(RTC_IRQn, 0);	// RTC IRQ priority.
	//NVIC_EnableIRQ(RTC_IRQn);		// Enable IRQ in NVIC.
#else
 	NVIC_SetPriority(RTC_Alarm_IRQn, 0);	// RTC IRQ priority.
	NVIC_EnableIRQ(RTC_Alarm_IRQn);			// Enable IRQ in NVIC.
#endif
	
	// RTC init phase.
	//Rtc::setTime(0); // Set time to 0.
	
	
	// Wait for RTC APB register synchronisation.
	/* int i = 10000;
	while (!(RTC->ISR & RTC_ISR_RSF) || i < 1) {
		// TODO: handle time-out.
		i--;
	} */
	
	// End configuration phase.
#if defined __stm32f1
	// Unmask RTC second interrupt.
	//RTC->CRH |= RTC_CRH_SECIE;
	
	printf("Leave conf mode...");
	
	// Unset CNF to leave configuration mode.
	RTC->CRL &= ~RTC_CRL_CNF;
	
	printf("Poll RTOFF...");
	
	// Poll RTOFF to ensure RTC is ready.
	uint32_t timeout = 1000; // TODO: make configurable.
	uint32_t ts = McuCore::getSysTick();
	while ((RTC->CRL & RTC_CRL_RTOFF) != RTC_CRL_RTOFF) {
		// Handle timeout.
		if (((McuCore::getSysTick() - ts) > timeout) || timeout == 0) {
				// TODO: set status.
				printf("RTC ready timeout.\n");
				return false;
			}
	}
#endif

	printf("RTC enabled.");
	
	rtc_enabled = true;
	BKP->DR1 = RTC_BKP_DATE_TIME_UPDATED; // Set magic number in Backup register.
	
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
#elif defined __stm32f1
	// Unlock write protection and enter configuration mode.
	RTC->CRL |= RTC_CRL_CNF;
	
	// Set time.
	RTC->CNTH = time >> 16U;
	RTC->CNTL = time & RTC_CNTL_RTC_CNT;
	
	// Unset CNF to leave configuration mode.
	RTC->CRL &= ~RTC_CRL_CNF;
	
	// Poll RTOFF to ensure RTC is ready.
	while ((RTC->CRL & RTC_CRL_RTOFF) != RTC_CRL_RTOFF) {
		// TODO: Handle timeout.
	}
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

#endif
