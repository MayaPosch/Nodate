/*
	interrupts.h - Header to provide access to interrupt (NVIC & EXTI) functionality.
	
*/


#ifndef INTERRUPTS_H
#define INTERRUPTS_H


#include "common.h"

#include "gpio.h"


#include <vector>


enum InterruptTrigger {
	INTERRUPT_TRIGGER_NONE = 0,
	INTERRUPT_TRIGGER_RISING,
	INTERRUPT_TRIGGER_FALLING,
	INTERRUPT_TRIGGER_BOTH
};


struct InterruptSource {
	bool active = false;
	Gpio_ports port;
	uint8_t pin;
	InterruptTrigger trigger;
	uint8_t* reg;
};


class Interrupts {
	static const exti_lines;
	
	static std::queue<uint8_t>& freeExti();
	static std::vector<InterruptSource>& interruptList();
	
public:
	Interrupts();
	~Interrupts();

	bool setInterrupt(uint8_t pin);
	void triggerInterrupt();
	bool removeInterrupt(uint8_t handle);
};

#endif
