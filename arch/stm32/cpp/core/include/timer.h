/*
	timer.h - Header to provide access to Timer functionality.
	
	Features:
			- Core timer (SysTick) for delay functionality.
			- Peripheral timers features for timing, PWM, etc.
	
*/


#ifndef TIMER_H
#define TIMER_H


#include "common.h"


enum TimerDevice {
	TIMER_1,
	TIMER_2,
	TIMER_3,
	TIMER_4,
	TIMER_5,
	TIMER_6,
	TIMER_7,
	TIMER_8
};


class Timer {
	//
	
public:
	Timer();
	~Timer();

	static void delay(uint32_t ms);
	//bool startPWM(TimerDevice device, 
};

#endif
