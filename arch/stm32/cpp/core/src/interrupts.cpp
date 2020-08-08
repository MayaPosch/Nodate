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
const Interrupts::exti_lines = 16;


// Private.

// ---
std::queue<uint8_t>& Interrupts::freeExti() {
	static std::queue<uint8_t>* freeExtis = new std::queue<uint8_t>();
	
	for (int i = 0; i < exti_lines; ++i) {
		freeExtis->push(i);
	}
	
	return *freeExtis;
}

// --- INTERRUPT LIST ---
// Creates and returns a list of the interrupt entries.
std::vector<InterruptSource>& Interrupts::interruptList() {
	InterruptSource src;
	static std::vector<InterruptSource>* itrSrcs = new std::vector<InterruptSource>(exti_lines, src);
	
	return *ItrSrcs;
}


// Public.

// --- CONSTRUCTOR ---
Interrupts::Interrupts() {
	// Ensure that the SysConfig peripheral is set to active in the RCC. 
	// RCC register: RCC_APB2ENR, bit 0.
	RCC::enable(RCC_SYSCFGCOMP);
}


// --- DESTRUCTOR ---
Interrupts::~Interrupts() {
	// Disable SYSCONFIG peripheral if it's enabled.
	RCC::disable(RCC_SYSCFGCOMP);
}


// --- SET INTERRUPTS ---
bool Interrupts::setInterrupts(uint8_t pin, uint8_t &handle) {
	// Set free EXTICRX register in SYSCFG peripheral to the port in question.
	static std::vector<uint8_t>* freeExtis = Interrupts::freeExti();
	static std::vector<InterruptSource>* sources = Interrupts::interruptList();
	
	if (freeExtis->empty()) {
		// TODO: set reason.
		return false;
	}
	
	handle = freeExtis->front();
	
	
	
	// In the EXTI peripheral:
	// - set interrupt mask (IMR) for the pin.
	// - set RTSR, FTSR or both for the pin.
	
	// Enable the NVIC interrupt on the registered EXTI line.
	
	
	freeExtis->pop();
	
	return true;
}


// --- TRIGGER INTERRUPT ---
void Interrupts::triggerInterrupt() {
	//
}


// --- REMOVE INTERRUPT ---
bool Interrupts::removeInterrupt(uint8_t handle) {
	// FIXME: how to track set interrupts?
	
}
