/*
	clock.cpp - Implementation file for the Clock class.
*/


#include <clock.h>
//#include <rcc.h>
//#include <rtc.h>

//#include <nodate.h>

#include <sys/times.h>

// Debug
#include <printf.h>


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


// --- BCD conversion --- -> Moved to utils.cpp
/* uint8_t bcd2dec8(uint8_t bcd) {
	uint8_t dec = (bcd >> 4) * 10 + (bcd & 0x0f);
	return dec;
}

uint8_t dec2bcd8(uint8_t dec) {
	uint8_t bcd = (dec % 10) | (dec / 10) << 4;
	return bcd;
}

uint16_t bcd2dec16(uint16_t bcd) {
	return bcd2dec8(bcd >> 8) * 100 + bcd2dec8(bcd & 0xff);
}

uint16_t dec2bcd16(uint16_t dec) {
	return dec2bcd8(dec % 100) | dec2bcd8(dec / 100) << 8;
}

uint32_t bcd2dec32(uint32_t bcd) {
	return bcd2dec16(bcd >> 16) * 10000 + bcd2dec16(bcd & 0xffff);
}

uint32_t dec2bcd32(uint32_t dec) {
	return dec2bcd16(dec % 10000) | dec2bcd16(dec / 10000) << 16;
} */
// ---

// Forward declaration. Implementation is in rtc.cpp.
extern "C" {
	int _gettimeofday (struct timeval * tp, void * tzvp);
}

int _times(struct tms* buf) {
	timeval tp;
	_gettimeofday(&tp, NULL);
	
	uint32_t ticks = (uint32_t) tp.tv_sec;
	buf->tms_utime = ticks;
	buf->tms_stime = ticks;
	buf->tms_cutime = ticks;
	buf->tms_cstime = ticks;
	
	return (int) ticks;
/* #if defined RTC_TR_SU
	if (!rtc_pwr_enabled) {
		if (!Rtc::enableRTC()) { return -1; }
		rtc_pwr_enabled = true;
	}
	
	// Fill tms struct from RTC registers.
	// struct tms {
	//		clock_t tms_utime;  // user time 
	//		clock_t tms_stime;  // system time 
	//		clock_t tms_cutime; // user time of children 
	//		clock_t tms_cstime; // system time of children 
	//	};
	uint32_t tTR = RTC->TR;
	uint32_t ticks = (uint8_t) RTC_Bcd2ToByte(tTR & (RTC_TR_ST | RTC_TR_SU));
	ticks = ticks * SystemCoreClock;
	buf->tms_utime = ticks;
	buf->tms_stime = ticks;
	buf->tms_cutime = ticks;
	buf->tms_cstime = ticks;
	
	return ticks; // Return clock ticks.
#elif defined __stm32f1
	// Get value.
	register uint16_t high = 0, low = 0;

	high = RTC->CNTH & RTC_CNTH_RTC_CNT;
	low  = RTC->CNTL & RTC_CNTL_RTC_CNT;
	uint32_t ticks =  (uint32_t)(((uint32_t) high << 16U) | low);
	ticks = ticks * SystemCoreClock;
	buf->tms_utime = ticks;
	buf->tms_stime = ticks;
	buf->tms_cutime = ticks;
	buf->tms_cstime = ticks;
	
	return ticks;
#else
	// No usable RTC peripheral exists. Return -1.
	return -1;
#endif  */
}


// --- CONFIGURE AHB ---
bool Clock::configureAHB(RccSysClockConfig cfg) {
#if defined __stm32f1
	// Set AHB prescaler.
	uint32_t ahb_div = 1;
	if 		(cfg.AHB_prescale == 2)		{ ahb_div = 8; 	}
	else if (cfg.AHB_prescale == 4) 	{ ahb_div = 9; 	}
	else if (cfg.AHB_prescale == 8) 	{ ahb_div = 10; }
	else if (cfg.AHB_prescale == 16) 	{ ahb_div = 11;	}
	else if (cfg.AHB_prescale == 64) 	{ ahb_div = 12; }
	else if (cfg.AHB_prescale == 128) 	{ ahb_div = 13; }
	else if (cfg.AHB_prescale == 256) 	{ ahb_div = 14; }
	else if (cfg.AHB_prescale == 512) 	{ ahb_div = 15; }
	RCC->CFGR |= (ahb_div << RCC_CFGR_HPRE_Pos);
	
	return true;
#endif
	return false;
}


// -- CONFIGURE APB ---
bool Clock::configureAPB(RccSysClockConfig cfg) {
#if defined __stm32f1
	// Set APB prescalers.
	uint32_t apb1_div = 1;
	if 		(cfg.APB1_prescale == 2)	{ apb1_div = 4;	}
	else if (cfg.APB1_prescale == 4) 	{ apb1_div = 5;	}
	else if (cfg.APB1_prescale == 8) 	{ apb1_div = 6;	}
	else if (cfg.APB1_prescale == 16)	{ apb1_div = 7;	}
	RCC->CFGR |= (apb1_div << RCC_CFGR_PPRE1_Pos);
	
	uint32_t apb2_div = 1;
	if 		(cfg.APB2_prescale == 2)	{ apb2_div = 4;	}
	else if (cfg.APB2_prescale == 4) 	{ apb2_div = 5;	}
	else if (cfg.APB2_prescale == 8) 	{ apb2_div = 6;	}
	else if (cfg.APB2_prescale == 16)	{ apb2_div = 7;	}
	RCC->CFGR |= (apb2_div << RCC_CFGR_PPRE2_Pos);
	
	return true;
	
#endif
	return false;
};


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
	//RCC->CFGR |= (RCC_CFGR_PLLSRC_HSI_PREDIV | RCC_CFGR_PPRE_DIV1 | RCC_CFGR_PLLMUL6);
	
	// Turn PLL back on.
	RCC->CR |= RCC_CR_PLLON;
	while (!(RCC->CR & RCC_CR_PLLRDY)) {}	// Wait for PLL to turn on.
	
	// Set PLL as sysclock source.
	RCC->CFGR &= ~(RCC_CFGR_SW);
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)) { }	// Wait for PLL to stabilise.
	SystemCoreClock = 48000000;	// 48 MHz.
#endif
#endif

#if defined __stm32f1
	// Set Flash latency. Set pre-fetch buffer enabled.
	// TODO: check whether PFB is needed.
	// - 0 wait states, if 0 < SYSCLK  24 MHz
	// - 1 wait state, if 24 MHz < SYSCLK  48 MHz
	// - 2 wait states, if 48 MHz < SYSCLK  72 MHz
	FLASH->ACR |= (maxSysClockCfg.FLASH_latency << FLASH_ACR_LATENCY_Pos);
	FLASH->ACR |= FLASH_ACR_PRFTBE;
	
	// Configure sysclock.
	uint32_t newSysClock;
	if (maxSysClockCfg.source == RCC_SYSCLOCK_SRC_PLL) {
		if (maxSysClockCfg.PLL_source == RCC_PLLCLOCK_SRC_HSI) {
			if ((RCC->CR & RCC_CR_HSION) != RCC_CR_HSION) {
				// Enable HSI clock.
				RCC->CR |= RCC_CR_HSION;
				while ((RCC->CR & RCC_CR_HSIRDY) != RCC_CR_HSIRDY) {
					// TODO: Handle timeout.
				}
			}
			
			RCC->CFGR &= ~RCC_CFGR_PLLSRC;	// PLL source is HSI.
			
			// Disable HSE.
			//RCC->CR &= ~RCC_CR_HSEON;
		}
		else if (maxSysClockCfg.PLL_source == RCC_PLLCLOCK_SRC_HSE) {
			if ((RCC->CR & RCC_CR_HSEON) != RCC_CR_HSEON) {
				// Enable HSE clock.
				RCC->CR |= RCC_CR_HSEON;
				printf("HSEON set.\n");
				//while ((RCC->CR & RCC_CR_HSERDY) != RCC_CR_HSERDY) {
				while ((RCC->CR & RCC_CR_HSERDY) == 0) {
					// TODO: Handle timeout.
				}
				
				printf("HSERDY check.\n");
			}
			
			RCC->CFGR |= RCC_CFGR_PLLSRC;	// PLL source is HSE.
			
			// Disable HSI.
			//RCC->CR &= ~RCC_CR_HSION;
		}
		else {
			return false;
		}
		
		// Set AHB & APB prescalers.
		if (!configureAHB(maxSysClockCfg)) { return false; }		
		printf("Configured AHB.\n");		
		if (!configureAPB(maxSysClockCfg)) { return false; }		
		printf("Set PLL..\n");
		
		// Make sure PLL is disabled.
		RCC->CR &= ~RCC_CR_PLLON;
		while ((RCC->CR & RCC_CR_PLLRDY)) {
			// TODO: Timeout handling.
		}
		
		// Set PLL configuration parameters.
		uint32_t pllmul = 0;
		if (maxSysClockCfg.PLLM >= 2) { pllmul = maxSysClockCfg.PLLM - 2; }
		RCC->CFGR |= pllmul << RCC_CFGR_PLLMULL_Pos;
		
		printf("Enable PLL..\n");
		
		// Turn on PLL.
		RCC->CR |= RCC_CR_PLLON;
		while (!(RCC->CR & RCC_CR_PLLRDY)) {
			// TODO: Timeout handling.
		}
		
		printf("PLLRDY check.\n");
		
		// Enable PLL as input.
		RCC->CFGR &= ~(RCC_CFGR_SW);
		RCC->CFGR |= RCC_CFGR_SW_PLL;
		while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)) { }	// Wait for PLL to stabilise.
		
		printf("PLL stable.\n");
		
		printf("Set new clock...\n");
		
		newSysClock = (maxSysClockCfg.base_freq * maxSysClockCfg.PLLM);
	}
	else if (maxSysClockCfg.source == RCC_SYSCLOCK_SRC_HSI) {
		if ((RCC->CR & RCC_CR_HSION) != RCC_CR_HSION) {
			// Enable HSI clock.
			RCC->CR |= RCC_CR_HSION;
			while ((RCC->CR & RCC_CR_HSIRDY) != RCC_CR_HSIRDY) {
				// TODO: Handle timeout.
			}
		}
		
		// Set Flash latency. Set pre-fetch buffer enabled.
		//FLASH->ACR |= (maxSysClockCfg.FLASH_latency << FLASH_ACR_LATENCY | FLASH_ACR_PRFTBE);
		
		// Set AHB speeds.
		if (!configureAHB(maxSysClockCfg)) { return false; }
		
		RCC->CFGR &= ~(RCC_CFGR_SW);
		RCC->CFGR |= RCC_CFGR_SW_HSI;
		while (!(RCC->CFGR & RCC_CFGR_SWS_HSI)) { }	// Wait for clock to stabilise.
		
		if (!configureAPB(maxSysClockCfg)) { return false; }
		newSysClock = maxSysClockCfg.base_freq;
	}
	else if (maxSysClockCfg.source == RCC_SYSCLOCK_SRC_HSE) {
		if ((RCC->CR & RCC_CR_HSEON) != RCC_CR_HSEON) {
			// Enable HSI clock.
			RCC->CR |= RCC_CR_HSEON;
			while ((RCC->CR & RCC_CR_HSERDY) != RCC_CR_HSERDY) {
				// TODO: Handle timeout.
			}
		}
		
		// Set Flash latency. Set pre-fetch buffer enabled.
		//FLASH->ACR |= (maxSysClockCfg.FLASH_latency << FLASH_ACR_LATENCY | FLASH_ACR_PRFTBE);
		
		// Set AHB speeds.
		if (!configureAHB(maxSysClockCfg)) { return false; }
		
		RCC->CFGR &= ~(RCC_CFGR_SW);
		RCC->CFGR |= RCC_CFGR_SW_HSE;
		while (!(RCC->CFGR & RCC_CFGR_SWS_HSE)) { }	// Wait for clock to stabilise.
		
		if (!configureAPB(maxSysClockCfg)) { return false; }
		newSysClock = maxSysClockCfg.base_freq;
	}
	else {
		return false;
	}
	
	// Update System core clock variable and systick.
	McuCore::initSysTick();
	SystemCoreClock = newSysClock;
#endif

#if defined __stm32f4
	// Set Flash latency. Set pre-fetch buffer enabled.
	FLASH->ACR |= (maxSysClockCfg.FLASH_latency << FLASH_ACR_LATENCY | FLASH_ACR_PRFTEN);
	
	// Set the SW sys clock switch to the right input type.
	uint32_t newSysClock;
	RCC->CFGR &= ~(RCC_CFGR_SW);
	if (maxSysClockCfg.source == RCC_SYSCLOCK_SRC_PLL) {
		uint32_t reg = 0;
		if (maxSysClockCfg.PLL_source == RCC_PLLCLOCK_SRC_HSI) {
			if ((RCC->CR & RCC_CR_HSION) != RCC_CR_HSION) {
				// Enable HSI clock.
				RCC->CR |= RCC_CR_HSION;
				while ((RCC->CR & RCC_CR_HSIRDY) == 0) {
					// TODO: Handle timeout.
				}
			}
			
			reg |= RCC_PLLCFGR_PLLSRC_HSI;	// PLL source is HSI.
			
			// Disable HSE.
			//RCC->CR &= ~RCC_CR_HSEON;
		}
		else if (maxSysClockCfg.PLL_source == RCC_PLLCLOCK_SRC_HSE) {
			if ((RCC->CR & RCC_CR_HSEON) == 0) {
				// Enable HSI clock.
				RCC->CR |= RCC_CR_HSEON;
				while ((RCC->CR & RCC_CR_HSERDY) != RCC_CR_HSERDY) {
					// TODO: Handle timeout.
				}
			}
			
			reg |= RCC_PLLCFGR_PLLSRC_HSE;	// PLL source is HSE.
			
			// Disable HSI.
			//RCC->CR &= ~RCC_CR_HSION;
		}
		else {
			return false;
		}
		
		// Set PLL configuration parameters.
		reg |= (maxSysClockCfg.PLLM << RCC_PLLCFGR_PLLM_Pos)
				| (maxSysClockCfg.PLLN << RCC_PLLCFGR_PLLN_Pos) 
				| (maxSysClockCfg.PLLP << RCC_PLLCFGR_PLLP_Pos)
				| (maxSysClockCfg.PLLQ << RCC_PLLCFGR_PLLQ_Pos);
		RCC->PLLCFGR = reg;
		
		// Turn on PLL.
		RCC->CR |= RCC_CR_PLLON;
		while (!(RCC->CR & RCC_CR_PLLRDY)) {
			// TODO: Timeout handling.
		}
		
		// Enable PLL.
		RCC->CFGR |= RCC_CFGR_SW_PLL;
		while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)) { }	// Wait for PLL to stabilise.
		
		newSysClock = ((maxSysClockCfg.base_freq / maxSysClockCfg.PLLM) * maxSysClockCfg.PLLN)
						/ maxSysClockCfg.PLLP;
	}
	else if (maxSysClockCfg.source == RCC_SYSCLOCK_SRC_HSI) {
		if ((RCC->CR & RCC_CR_HSION) != RCC_CR_HSION) {
			// Enable HSI clock.
			RCC->CR |= RCC_CR_HSION;
			while ((RCC->CR & RCC_CR_HSIRDY) == 0) {
				// TODO: Handle timeout.
			}
		}
			
		RCC->CFGR |= RCC_CFGR_SW_HSI;
		while (!(RCC->CFGR & RCC_CFGR_SWS_HSI)) { }	// Wait for clock to stabilise.
		newSysClock = maxSysClockCfg.base_freq;
	}
	else if (maxSysClockCfg.source == RCC_SYSCLOCK_SRC_HSE) {
		if ((RCC->CR & RCC_CR_HSEON) == 0) {
			// Enable HSI clock.
			RCC->CR |= RCC_CR_HSEON;
			while ((RCC->CR & RCC_CR_HSERDY) == 0) {
				// TODO: Handle timeout.
			}
		}
			
		RCC->CFGR |= RCC_CFGR_SW_HSE;
		while (!(RCC->CFGR & RCC_CFGR_SWS_HSE)) { }	// Wait for clock to stabilise.
		newSysClock = maxSysClockCfg.base_freq;
	}
	else {
		return false;
	}
	
	// Set AHB prescaler.
	uint32_t ahb_div = 1;
	if 		(maxSysClockCfg.AHB_prescale == 2)		{ ahb_div = 8; 	}
	else if (maxSysClockCfg.AHB_prescale == 4) 		{ ahb_div = 9; 	}
	else if (maxSysClockCfg.AHB_prescale == 8) 		{ ahb_div = 10; }
	else if (maxSysClockCfg.AHB_prescale == 16) 	{ ahb_div = 11;	}
	else if (maxSysClockCfg.AHB_prescale == 64) 	{ ahb_div = 12; }
	else if (maxSysClockCfg.AHB_prescale == 128) 	{ ahb_div = 13; }
	else if (maxSysClockCfg.AHB_prescale == 256) 	{ ahb_div = 14; }
	else if (maxSysClockCfg.AHB_prescale == 512) 	{ ahb_div = 15; }
	RCC->CFGR |= (ahb_div << RCC_CFGR_HPRE_Pos);
	
	// Set APB prescalers.
	uint32_t apb1_div = 1;
	uint32_t apb2_div = 1;
	if 		(maxSysClockCfg.APB1_prescale == 2)		{ apb1_div = 4; 	}
	else if (maxSysClockCfg.APB1_prescale == 4) 	{ apb1_div = 5; 	}
	else if (maxSysClockCfg.APB1_prescale == 8) 	{ apb1_div = 6; 	}
	else if (maxSysClockCfg.APB1_prescale == 16)	{ apb1_div = 7; 	}
	
	if 		(maxSysClockCfg.APB2_prescale == 2)		{ apb2_div = 4; 	}
	else if (maxSysClockCfg.APB2_prescale == 4) 	{ apb2_div = 5; 	}
	else if (maxSysClockCfg.APB2_prescale == 8) 	{ apb2_div = 6; 	}
	else if (maxSysClockCfg.APB2_prescale == 16)	{ apb2_div = 7; 	}
	RCC->CFGR |= (apb1_div << RCC_CFGR_PPRE1_Pos);
	RCC->CFGR |= (apb2_div << RCC_CFGR_PPRE2_Pos);
	
	// Update System core clock variable.
	SystemCoreClock = newSysClock;
#endif

#if defined __stm32f7
	// Adjust Flash latency as needed.
	if (maxSysClockCfg.FLASH_latency > 15) { return false; }
	FLASH->ACR = FLASH_ACR_PRFTEN | (uint32_t) (maxSysClockCfg.FLASH_latency << FLASH_ACR_LATENCY_Pos);
#elif defined __stm32f0
	if (maxSysClockCfg.FLASH_latency > 15) { return false; }
	FLASH->ACR = FLASH_ACR_PRFTBE | (uint32_t) (maxSysClockCfg.FLASH_latency << FLASH_ACR_LATENCY_Pos);
#endif
	
	// Configure system clock.	
	//Rcc::configureSysClock(maxSysClockCfg);

	// Update SystemCoreClock variable.
	//SystemCoreClockUpdate();
	
	return true;
}


// --- CURRENT SYS CLOCK ---
// Returns the currently configured system clock.
uint32_t Clock::currentSysClock() {
	return SystemCoreClock;
}


// --- ENABLE LSE ---
// Switch from LSI to LSE if available.
bool Clock::enableLSE() {
	return Rcc::enableLSE(true);
}
