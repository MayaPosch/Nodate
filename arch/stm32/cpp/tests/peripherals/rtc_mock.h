/*
	rtc_mock.h - header for the Nodate mock RTC peripheral.
	
*/


#include "chronotrigger.h"


class RTC_mock {
	ChronoTrigger ct;
	
	static void callback(int value);
	
public:
	RTC_mock();
	~RTC_mock();
};