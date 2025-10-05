/*
	rtc_test.cpp - Tests the RTC class.
	
	Revision 0.
	
*/



#include "../core/include/rtc.h"
#include "../core/include/utils.h"


#include <iostream>
#include <cstdio>
#include <iomanip>
#include <bitset>

#include <ctime>

#include "peripherals/rcc_mock.h"
#include "peripherals/rtc_mock.h"


int suseconds_t;

/* struct timeval {
	time_t      tv_sec;     // seconds
	suseconds_t tv_usec;    // microseconds
 }; */
		   

extern "C" {
	int _gettimeofday (struct timeval * tp, void * tzvp);
}


int main() {
	std::cout << "Running GPIO test..." << std::endl;
	
	// Create the mock peripheral instances.
	RCC_mock rcc_mock;
	RTC_mock rtc_mock;
	
	// Start RTC, using the LSE clock source.
	if (!Rtc::enableRTC(RTC_CLOCK_LSE)) {
		std::cout << "Starting RTC failed.\n";
		return 1;
	}
	
	// Set RTC defaults.
	// This uses the decimal (not BCD) format.
	uint32_t dectime = 60; // in seconds.
	Rtc::setTime(dectime);
	
	// Get time and print out.
	// For STM32F1 with its primitive (first-gen) RTC this always returns zeroes. 
	RtcTime time;
	Rtc::getTime(time);
	printf("Time: %d%d:%d%d:%d%d\n", time.hour_tens, time.hour_units, time.minute_tens, 
									time.minute_units, time.second_tens, time.second_units);
									
	// Check with C-style time functions.
	// Signature: int _gettimeofday (struct timeval * tp, void * tzvp);
	// When using newlib's date functions, this function gets called, so we validate it directly.
	timeval tp;
	if (_gettimeofday(&tp, NULL) != 0) {
		std::cout << "Error calling gettimeofday.\n";
		return 1;
	}
	
	time_t result = tp.tv_sec; //time(NULL);
    if (result != (time_t)(-1)) {
		
        printf("The asctime is %s\n", asctime(localtime(&result)));
        printf("The current gmtime is %s(%jd seconds since the Epoch)\n",
               asctime(gmtime(&result)), (intmax_t)result);
	}
	else {
		std::cout << "Failed to get C time.\n";
		return 1;
	}
	
	return 0;
}