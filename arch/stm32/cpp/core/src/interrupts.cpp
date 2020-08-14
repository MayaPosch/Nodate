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
uint8_t Interrupts::exti0_1_pwr = 0;
uint8_t Interrupts::exti2_3_pwr = 0;
uint8_t Interrupts::exti4_15_pwr = 0;


// ---
/* std::queue<uint8_t>& Interrupts::freeExti() {
	static std::queue<uint8_t>* freeExtis = new std::queue<uint8_t>();
	
	for (int i = 0; i < exti_lines; ++i) {
		freeExtis->push(i);
	}
	
	return *freeExtis;
} */

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
		src.reg = (&(SYSCFG->EXTICR[crcnt]) + (crpos++ * 4));
		
		if (crpos >= 4) { crpos = 0; crcnt++; }
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
// 
void EXTI0_1_IRQHandler() {
	//static std::vector<InterruptSource>* sources = interruptList();
	
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

void EXTI2_3_IRQHandler() {
	//static std::vector<InterruptSource>* sources = interruptList();
	
	if (EXTI->PR & (1 << 2)) {
		EXTI->PR |= (1 << 2);	// Clear the EXTI status flag.
		(*sources)[2].callback();	// Call the custom callback function.
	}
	else {
		EXTI->PR |= (1 << 3);
		(*sources)[3].callback();
	}
}

void EXTI4_15_IRQHandler() {
	//static std::vector<InterruptSource>* sources = interruptList();
	
	for (uint8_t i = 4; i < exti_lines; ++i) {
		if (EXTI->PR & (1 << i)) {
			EXTI->PR |= (1 << i);	// Clear the EXTI status flag.
			(*sources)[i].callback();	// Call the custom callback function.
		}
	}
}


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
	// Set free EXTICRX register in SYSCFG peripheral to the port in question.
	// This requires that we first check for an existing & valid entry in the queue of free entries.
	//static std::vector<uint8_t>* freeExtis = Interrupts::freeExti();
	//static std::vector<InterruptSource>* sources = interruptList();
	
	/* if (freeExtis->empty()) {
		// No free interrupts available any more.
		// TODO: set reason.
		return false;
	} */
	
	//handle = freeExtis->front();
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
	*(src.reg) |= (1 << (uint8_t) port);
	
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
	src.irqType = EXTI4_15_IRQn;
	if (pin == 0 || pin == 1) { src.irqType = EXTI0_1_IRQn; exti0_1_pwr++; }
	else if (pin == 2 || pin == 3) { src.irqType = EXTI2_3_IRQn; exti2_3_pwr++; }
	else { exti4_15_pwr++; }
		
	NVIC_SetPriority(src.irqType, priority);
	NVIC_EnableIRQ(src.irqType);
	
	// Remove the now unavailable EXTI entry from the queue and mark it as active.
	//freeExtis->pop();
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
	//static std::vector<uint8_t>* freeExtis = Interrupts::freeExti();
	//static std::vector<InterruptSource>* sources = interruptList();
	
	// Obtain and validate reference to interrupt source record.
	InterruptSource &src = (*sources)[handle];
	if (!src.active) {
		// Set reason.
		return false;
	}
	
	// Set record to non-active.
	src.active = false;
	
	// Disable the interrupt, starting with the NVIC.
	bool nvic_disable = false;
	if (src.irqType = EXTI0_1_IRQn) { 
		if (--exti0_1_pwr == 0) { nvic_disable = true; }
	}
	else if (src.irqType = EXTI2_3_IRQn) {
		if (--exti2_3_pwr == 0) { nvic_disable = true; }
	}
	else if (--exti4_15_pwr == 0) { nvic_disable = true; }
	
	if (nvic_disable) {	NVIC_DisableIRQ(src.irqType); }
	
	// Next reset the EXTI registers.
	EXTI->IMR &= ~(1 << src.pin);
	EXTI->FTSR &= ~(1 << src.pin);
	EXTI->RTSR &= ~(1 << src.pin);
	
	// Finally reset the SYSCFG registers.
	*(src.reg) &= ~(1 << (uint8_t) src.port);
	
	// Add record ID back into the queue.
	//freeExtis->push(handle);
	
	return true;
}
