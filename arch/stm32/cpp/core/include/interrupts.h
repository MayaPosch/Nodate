/*
	interrupts.h - Header to provide access to interrupt (NVIC & EXTI) functionality.
	
*/


#ifndef INTERRUPTS_H
#define INTERRUPTS_H


#include "common.h"

#include "gpio.h"

#include <vector>
#include <functional>


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
	IRQn_Type irqType;
	uint8_t priority;
	uint8_t* reg;
	std::function<void> callback;
};


class Interrupts {
	static const uint8_t exti_lines;
	static uint8_t exti0_1_pwr;
	static uint8_t exti2_3_pwr;
	static uint8_t exti4_15_pwr;
	
	//static std::queue<uint8_t>& freeExti();
	static std::vector<InterruptSource>& interruptList();
	
public:
	Interrupts();
	~Interrupts();

	bool setInterrupt(uint8_t pin, Gpio_ports port, InterruptTrigger trigger, 
						std::function<void>() callback, uint8_t priority, uint8_t &handle);
	void triggerInterrupt();
	bool removeInterrupt(uint8_t handle);
};

#endif
