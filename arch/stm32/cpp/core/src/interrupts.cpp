/*
	interrupts.cpp - Implementation of the Interrupts class.
	
	Revision 0.
	
	Features:
			- 
			
	2020/07/27, Maya Posch
*/


#include "interrupts.h"

#include "rcc.h"


// Static initialisations.
const int exti_lines = 16;

#ifdef __stm32f0
uint8_t Interrupts::exti0_1_pwr = 0;
uint8_t Interrupts::exti2_3_pwr = 0;
uint8_t Interrupts::exti4_15_pwr = 0;
#elif defined __stm32f4 || defined __stm32f7
uint8_t Interrupts::exti5_9_pwr = 0;
uint8_t Interrupts::exti10_15_pwr = 0;
#endif


// --- INTERRUPT LIST ---
// Creates and returns a list of the interrupt entries.
std::vector<InterruptSource>* interruptList() {
	InterruptSource src;
	static std::vector<InterruptSource>* itrSrcs = new std::vector<InterruptSource>(exti_lines, src);
	
	// Each interrupt sources list item refers to a single EXTI line, starting at EXTI0 ([0]).
	const uint8_t exticrs = 4;
	uint8_t crcnt = 0;
	uint8_t crpos = 0;
	for (int i = 0; i < exti_lines; ++i) {
		(*itrSrcs)[i].reg = crcnt;
		(*itrSrcs)[i].offset = crpos * 4;
		if (++crpos >= 4) { crpos = 0; crcnt++; }
		if (crcnt >= exticrs) {
			// Error, somehow more EXTI lines were defined than there are EXTICR entries.
			// TODO: set error.
			break;
		}
	}
	
	return itrSrcs;
}

static std::vector<InterruptSource>* sources = interruptList();


// Callback handlers.
// Overrides the default handlers and allows the use of custom callback functions.
// Forward declare the IRQ handlers in an 'extern C' block to disable C++ name mangling for these.
#ifdef __stm32f0
extern "C" {
	void EXTI0_1_IRQHandler(void);
	void EXTI2_3_IRQHandler(void);
	void EXTI4_15_IRQHandler(void);
}

void EXTI0_1_IRQHandler(void) {
	// Determine whether pin 0 or 1 was triggered.
	if (EXTI->PR & (1 << 1)) {
		EXTI->PR |= (1 << 1);	// Clear the EXTI status flag.
		(*sources)[1].callback();	// Call the custom callback function.
	}
	else {
		EXTI->PR |= 1;
		(*sources)[0].callback();
	}
}

void EXTI2_3_IRQHandler(void) {
	if (EXTI->PR & (1 << 2)) {
		EXTI->PR |= (1 << 2);	// Clear the EXTI status flag.
		(*sources)[2].callback();	// Call the custom callback function.
	}
	else {
		EXTI->PR |= (1 << 3);
		(*sources)[3].callback();
	}
}

void EXTI4_15_IRQHandler(void) {
	for (uint8_t i = 4; i < exti_lines; ++i) {
		if (EXTI->PR & (1 << i)) {
			EXTI->PR |= (1 << i);	// Clear the EXTI status flag.
			(*sources)[i].callback();	// Call the custom callback function.
		}
	}
}
#elif defined __stm32f4 || defined __stm32f7
extern "C" {
	void EXTI0_IRQHandler(void);
	void EXTI1_IRQHandler(void);
	void EXTI2_IRQHandler(void);
	void EXTI3_IRQHandler(void);
	void EXTI4_IRQHandler(void);
	void EXTI9_5_IRQHandler(void);
	void EXTI15_10_IRQHandler(void);
}

void EXTI0_IRQHandler(void) {
	(*sources)[0].callback();
}

void EXTI1_IRQHandler(void) {
	(*sources)[1].callback();
}

void EXTI2_IRQHandler(void) {
	(*sources)[2].callback();
}

void EXTI3_IRQHandler(void) {
	(*sources)[3].callback();
}

void EXTI4_IRQHandler(void) {
	(*sources)[4].callback();
}

void EXTI9_5_IRQHandler(void) {
	for (uint8_t i = 5; i < 10; ++i) {
		if (EXTI->PR & (1 << i)) {
			EXTI->PR |= (1 << i);	// Clear the EXTI status flag.
			(*sources)[i].callback();	// Call the custom callback function.
		}
	}
}

void EXTI15_10_IRQHandler(void) {
	for (uint8_t i = 10; i < 16; ++i) {
		if (EXTI->PR & (1 << i)) {
			EXTI->PR |= (1 << i);	// Clear the EXTI status flag.
			(*sources)[i].callback();	// Call the custom callback function.
		}
	}
}
#endif


// Public.

// --- CONSTRUCTOR ---
Interrupts::Interrupts() {
	// Ensure that the SysConfig peripheral is set to active in the RCC. 
	// RCC register: RCC_APB2ENR, bit 0.
	Rcc::enable(RCC_SYSCFGCOMP);
}


// --- DESTRUCTOR ---
Interrupts::~Interrupts() {
	// Disable SYSCONFIG peripheral if it's enabled.
	Rcc::disable(RCC_SYSCFGCOMP);
}


// --- SET INTERRUPTS ---
bool Interrupts::setInterrupt(uint8_t pin, GPIO_ports port, InterruptTrigger trigger, 
								std::function<void()> callback, uint8_t priority, uint8_t &handle) {
	handle = pin;
	InterruptSource &src = (*sources)[handle];
	if (src.active) {
		// Already active EXICRx entry. Possibly due to a pin on another port in use.
		// TODO: set reason.
		return false;
	}
	
	// Assign the new entry information and set the requested port in the SYSCFG EXTICR.
	src.port = port;
	src.pin = pin;
	src.trigger = trigger;
	src.callback = callback;
	src.priority = priority;
	SYSCFG->EXTICR[src.reg] |= (((uint32_t) port) << src.offset);
	
	// In the EXTI peripheral:
	// - set interrupt mask (IMR) for the pin.
	// - set RTSR, FTSR or both for the pin.
	// The pin corresponds to the EXTI line.
	EXTI->IMR |= (1 << pin);
	
	if (trigger == INTERRUPT_TRIGGER_RISING) {
		EXTI->RTSR |= (1 << pin);
		EXTI->FTSR &= ~(1 << pin);
	}
	else if (trigger == INTERRUPT_TRIGGER_FALLING) {
		EXTI->RTSR &= ~(1 << pin);
		EXTI->FTSR |= (1 << pin);
	}
	else if (trigger == INTERRUPT_TRIGGER_BOTH) {
		EXTI->RTSR |= (1 << pin);
		EXTI->FTSR |= (1 << pin);
	}
	
	// Enable the NVIC interrupt on the registered EXTI line.
	// Priority level 0 is the highest, with M0 supporting up to 192.
	// Cortex M3, M4 and M7 support 255 levels.
#ifdef __stm32f0
	src.irqType = EXTI4_15_IRQn;
	if (pin == 0 || pin == 1) { src.irqType = EXTI0_1_IRQn; exti0_1_pwr++; }
	else if (pin == 2 || pin == 3) { src.irqType = EXTI2_3_IRQn; exti2_3_pwr++; }
	else { exti4_15_pwr++; }
#elif defined __stm32f4 || defined __stm32f7
	src.irqType = EXTI15_10_IRQn;
	if (pin == 0) { src.irqType = EXTI0_IRQn; }
	else if (pin == 1) { src.irqType = EXTI1_IRQn; }
	else if (pin == 2) { src.irqType = EXTI2_IRQn; }
	else if (pin == 3) { src.irqType = EXTI3_IRQn; }
	else if (pin == 4) { src.irqType = EXTI4_IRQn; }
	else if (pin > 4 && pin < 10) { src.irqType = EXTI9_5_IRQn; exti5_9_pwr++; }
	else if (pin > 9 && pin < 16) { src.irqType = EXTI15_10_IRQn; exti10_15_pwr++; }
#endif
		
	NVIC_SetPriority(src.irqType, priority);
	NVIC_EnableIRQ(src.irqType);
	
	// Mark the EXTI entry as active.
	src.active = true;
	
	return true;
}


// --- TRIGGER INTERRUPT ---
void Interrupts::triggerInterrupt() {
	//
}


// --- REMOVE INTERRUPT ---
// Use the provided handle to disable the interrupt.
bool Interrupts::removeInterrupt(uint8_t handle) {
	// Obtain and validate reference to interrupt source record.
	InterruptSource &src = (*sources)[handle];
	if (!src.active) {
		// Set reason.
		return false;
	}
	
	// Set record to non-active.
	src.active = false;
	
	// Disable the interrupt, starting with the NVIC.
	bool nvic_disable = true;

#ifdef __stm32f0
	if (src.irqType == EXTI0_1_IRQn) { 
		if (--exti0_1_pwr != 0) { nvic_disable = false; }
	}
	else if (src.irqType == EXTI2_3_IRQn) {
		if (--exti2_3_pwr != 0) { nvic_disable = false; }
	}
	else if (--exti4_15_pwr != 0) { nvic_disable = false; }
#elif defined __stm32f4 || defined __stm32f7
	if (src.irqType == EXTI9_5_IRQn) {
		if (--exti5_9_pwr != 0) { nvic_disable == false; }
	}
	else if (src.irqType == EXTI15_10_IRQn) {
		if (--exti10_15_pwr != 0) { nvic_disable == false; }
	}
#endif
	
	if (nvic_disable) {	NVIC_DisableIRQ(src.irqType); }
	
	// Next reset the EXTI registers.
	EXTI->IMR &= ~(1 << src.pin);
	EXTI->FTSR &= ~(1 << src.pin);
	EXTI->RTSR &= ~(1 << src.pin);
	
	// Finally reset the SYSCFG registers.
	SYSCFG->EXTICR[src.reg] &= ~(0xF << src.offset);
	
	return true;
}
