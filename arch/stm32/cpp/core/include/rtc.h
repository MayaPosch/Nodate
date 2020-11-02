/*
	rtc.h - Real-Time Clock module.
	
	Revision 0.
	
	Features:
			- 
			
	Notes:
			- 
	
	2020/09/23, Maya Posch
*/


#ifndef RTC_H
#define RTC_H

#include <common.h>


struct RtcTime {
	uint8_t hour_tens;
	uint8_t hour_units;
	uint8_t minute_tens;
	uint8_t minute_units;
	uint8_t second_tens;
	uint8_t second_units;
};


class Rtc {
	//
	
public:
	static bool enableRTC();
	static bool setTime(uint32_t time);
	static bool getTime(RtcTime &time);
	static bool getTime(char* t, uint8_t &len);
	static bool getDate();
	static bool getDate(char* t, uint8_t &len);
	static bool disableRTC();
};

#endif
