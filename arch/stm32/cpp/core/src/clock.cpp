/*
	clock.cpp - Implementation file for the Clock class.
*/


#include <clock.h>
#include <rtc.h>

#include <sys/times.h>


extern "C" {
	int _times(struct tms* buf);
}

bool rtc_pwr_enabled = false;


/**
  * @brief  Converts from 2 digit BCD to Binary.
  * @param  Value BCD value to be converted
  * @retval Converted word
  */
uint8_t RTC_Bcd2ToByte(uint8_t Value) {
  uint32_t tmp = 0U;
  tmp = ((uint8_t)(Value & (uint8_t)0xF0) >> (uint8_t)0x4) * 10;
  return (tmp + (Value & (uint8_t)0x0F));
}


int _times(struct tms* buf) {
#if defined RTC_TR_SU
	if (!rtc_pwr_enabled) {
		if (!Rtc::enableRTC()) { return -1; }
		rtc_pwr_enabled = true;
	}
	
	// Fill tms struct from RTC registers.
	// struct tms {
	//		clock_t tms_utime;  /* user time */
	//		clock_t tms_stime;  /* system time */
	//		clock_t tms_cutime; /* user time of children */
	//		clock_t tms_cstime; /* system time of children */
	//	};
	int ticks = SystemCoreClock * (RTC_Bcd2ToByte(RTC->TR & (RTC_TR_ST | RTC_TR_SU)));
	buf->tms_utime = ticks;
	buf->tms_stime = ticks;
	buf->tms_cutime = ticks;
	buf->tms_cstime = ticks;
	
	return ticks; // Return clock ticks.
#else
	// No usable RTC peripheral exists. Return -1.
	return -1;
#endif 
}


bool Clock::enableMaxClock() {
#if defined __stm32f0
	// STM32F0:
#if defined RCC_HSI48_SUPPORT
	// Use HSI48 if available. Do not use PLL in this case.
	// Flash latency: 1.Pre-fetch buffer enabled.
	FLASH->ACR |= (FLASH_ACR_LATENCY | FLASH_ACR_PRFTBE);
	RCC->CR2 |= RCC_CR2_HSI48ON;
	while (!(RCC->CR2 & RCC_CR2_HSI48RDY)) { }
	RCC->CFGR |= RCC_CFGR_SW_HSI48;
	SystemCoreClock = 48000000;
#else
	// Use HSI (assume already enabled), PLL on, PLL PreDiv 1, Mul 6.
	// Flash latency: 1. Pre-fetch buffer enabled.
	FLASH->ACR |= (FLASH_ACR_LATENCY | FLASH_ACR_PRFTBE);
	
	// Disable PLL if it's set. This way we can update its settings.
	// If PLL is selected as sysclock source, switch to HSI.
	if ((RCC->CFGR & RCC_CFGR_SWS) == RCC_CFGR_SWS_PLL) {
		RCC->CFGR &= (uint32_t) (~RCC_CFGR_SW);
		while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI) {
			// TODO: handle time-outs.
		}
	}
	
	// Disable PLL and ensure it's off.
	RCC->CR &= (uint32_t) ~(RCC_CR_PLLON);
	while((RCC->CR & RCC_CR_PLLRDY) != 0) {
		// TODO: handle time-outs.
	}
	
	// Clear any old settings, set new settings.
	RCC->CFGR &= ~(RCC_CFGR_PLLMUL | RCC_CFGR_PLLSRC);
	RCC->CFGR |= (RCC_CFGR_PLLSRC_HSI_PREDIV | RCC_CFGR_PPRE_DIV1 | RCC_CFGR_PLLMUL6);
	
	// Turn PLL back on.
	RCC_CR |= RCC_CR_PLLON;
	while (!(RCC->CR & RCC_CR_PLLRDY)) {}	// Wait for PLL to turn on.
	
	// Set PLL as sysclock source.
	RCC->CFGR &= ~(RCC_CFGR_SW);
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)) { }	// Wait for PLL to stabilise.
	SystemCoreClock = 48000000;	// 48 MHz.
#endif
#endif

#if defined __stm32f4
	// Use HSI (assume already enabled), PLL on, PLL PreDiv ?, Mul ?.
	// Flash latency: 1. Pre-fetch buffer enabled.
	FLASH->ACR |= (FLASH_ACR_LATENCY_5WS | FLASH_ACR_PRFTEN);
	
	RCC->CFGR &= ~(RCC_CFGR_SW);
	RCC->CFGR |= RCC_CFGR_SW_HSI;
	
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSI | (8 << RCC_PLLCFGR_PLLM_Pos)
						| (336 << RCC_PLLCFGR_PLLN_Pos) | (2 << RCC_PLLCFGR_PLLP_Pos)
						| (7 << RCC_PLLCFGR_PLLQ_Pos);
	
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)) { }	// Wait for PLL to stabilise.
	SystemCoreClock = 48000000;	// 48 MHz.
#endif

	return true;
}
