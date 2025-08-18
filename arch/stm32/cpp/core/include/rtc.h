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
#include <nodate.h>


struct RtcTime {
	uint8_t hour_tens;
	uint8_t hour_units;
	uint8_t minute_tens;
	uint8_t minute_units;
	uint8_t second_tens;
	uint8_t second_units;
};


enum RtcClock {
	RTC_CLOCK_LSI,
	RTC_CLOCK_LSE,
	RTC_CLOCK_HSE
};

struct RTC_TimeTypeDef {
  uint8_t Hours;            /*!< Specifies the RTC Time Hour.
                                 This parameter must be a number between Min_Data = 0 and Max_Data = 23 */

  uint8_t Minutes;          /*!< Specifies the RTC Time Minutes.
                                 This parameter must be a number between Min_Data = 0 and Max_Data = 59 */

  uint8_t Seconds;          /*!< Specifies the RTC Time Seconds.
                                 This parameter must be a number between Min_Data = 0 and Max_Data = 59 */

};


class Rtc {
	//
	
public:
	static bool enableRTC(RtcClock clk = RTC_CLOCK_LSE);
	static bool setTime(uint32_t time);
	static bool getTime(RtcTime &time);
	static bool getTime(char* t, uint8_t &len);
	static bool getDate();
	static bool getDate(char* t, uint8_t &len);
	static bool disableRTC();
};

#endif
