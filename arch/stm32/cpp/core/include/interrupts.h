/*
	interrupts.h - Header to provide access to interrupt (NVIC & EXTI) functionality.
	
*/


#ifndef INTERRUPTS_H
#define INTERRUPTS_H


#include <common.h>

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
	GPIO_ports port;
	uint8_t pin;
	InterruptTrigger trigger;
	IRQn_Type irqType;
	uint8_t priority;
	uint8_t reg;
	uint32_t offset;
	std::function<void()> callback;
};


class Interrupts {
#ifdef __stm32f0
	static uint8_t exti0_1_pwr;
	static uint8_t exti2_3_pwr;
	static uint8_t exti4_15_pwr;
#elif defined __stm32f1 || defined __stm32f4 || defined __stm32f7
	static uint8_t exti5_9_pwr;
	static uint8_t exti10_15_pwr;
#endif
	
public:
	Interrupts();
	~Interrupts();

	bool setInterrupt(uint8_t pin, GPIO_ports port, InterruptTrigger trigger, 
						std::function<void()> callback, uint8_t priority, uint8_t &handle);
	void triggerInterrupt();
	bool removeInterrupt(uint8_t handle);
};

#endif
