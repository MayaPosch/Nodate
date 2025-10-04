/*
	rtc_test.cpp - Tests the RTC class.
	
	Revision 0.
	
*/



#include "../core/include/clock.h"
//#include "../core/include/utils.h"


#include <iostream>
#include <cstdio>
#include <iomanip>
#include <bitset>

//#include <ctime>

#include "peripherals/rcc_mock.h"


int main() {
	std::cout << "Running SysClock test..." << std::endl;
	
	// Create the mock peripheral instances.
	RCC_mock rcc_mock;
	
	// Try to enable the max sysclock.
	if (!Clock::enableMaxClock()) {
		std::cout << "Failed to set max clock.\n";
		return 1;
	}
	
	// Check that the new sysclock matches.
	// Here we assume the PLL is used as the SW input.
	uint32_t newSysClock;
#if defined __stm32f1
	newSysClock = (maxSysClockCfg.base_freq * maxSysClockCfg.PLLM);
#elif defined __stm32f4
	newSysClock = ((maxSysClockCfg.base_freq / maxSysClockCfg.PLLM) * maxSysClockCfg.PLLN)
						/ maxSysClockCfg.PLLP;
#endif
	uint32_t sysclock = Clock::currentSysClock();
	std::cout << "target clock - current clock: " <<  newSysClock << " - " << sysclock << std::endl;
	
	return 0;
}