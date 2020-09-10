/*
	gpio.cpp - Implementation file for the GPIO class.
*/


#include "gpio.h"

#include "rcc.h"

#include <vector>


// --- GPIO HANDLES ---
std::vector<GPIO_instance>* GPIO_instances() {
	GPIO_instance instance;
	static std::vector<GPIO_instance>* instancesStatic = new std::vector<GPIO_instance>(12, instance);
	
#if defined RCC_AHBENR_GPIOAEN || defined RCC_AHB1ENR_GPIOAEN
	((*instancesStatic))[GPIO_PORT_A].regs = GPIOA;
#endif

#if defined RCC_AHBENR_GPIOBEN || defined RCC_AHB1ENR_GPIOBEN
	((*instancesStatic))[GPIO_PORT_B].regs = GPIOB;
#endif

#if defined RCC_AHBENR_GPIOCEN || defined RCC_AHB1ENR_GPIOCEN
	((*instancesStatic))[GPIO_PORT_C].regs = GPIOC;
#endif

#if defined RCC_AHBENR_GPIODEN || defined RCC_AHB1ENR_GPIODEN
	((*instancesStatic))[GPIO_PORT_D].regs = GPIOD;
#endif

#if defined RCC_AHBENR_GPIOEEN || defined RCC_AHB1ENR_GPIOEEN
	((*instancesStatic))[GPIO_PORT_E].regs = GPIOE;
#endif

#if defined RCC_AHBENR_GPIOFEN || defined RCC_AHB1ENR_GPIOFEN
	((*instancesStatic))[GPIO_PORT_F].regs = GPIOF;
#endif
	
	return instancesStatic;
}

static std::vector<GPIO_instance>* instancesStatic = GPIO_instances();



// --- CONSTRUCTOR ---
GPIO::GPIO() {
	//
}


// --- DESTRUCTOR ---
GPIO::~GPIO() {
	// 
}


// --- SET INPUT ---
bool GPIO::set_input(GPIO_ports port, uint8_t pin, GPIO_pupd pupd) {
	// Validate port & pin.
	if (pin > 15) { return false; }
	
	GPIO_instance &instance = (*instancesStatic)[port];
	
	// Check if port is active, if not, try to activate it.
	if (!instance.active) {
		if (Rcc::enablePort((RccPort) port)) {
			instance.active = true;
		}
		else {
			return false;
		}
	}
	
	// Set parameters.
	// MODER is set to '00' for input mode.
	uint8_t pin2 = pin * 2;
	instance.regs->MODER &= ~(0x3 << pin2);
	instance.regs->PUPDR &= ~(0x3 << pin2);
	if (pupd == GPIO_PULL_UP) {
		instance.regs->PUPDR |= (0x1 << pin2);
	}
	else {
		instance.regs->PUPDR |= (0x2 << pin2);
	}

	return true;
}


// --- SET OUTPUT ---
bool GPIO::set_output(GPIO_ports port, uint8_t pin, GPIO_pupd pupd, GPIO_out_type type, 
																	GPIO_out_speed speed) {
	// Validate port & pin.
	if (pin > 15) { return false; }
	
	GPIO_instance &instance = (*instancesStatic)[port];
	
	// Check if port is active, if not, try to activate it.
	if (!instance.active) {
		if (Rcc::enablePort((RccPort) port)) {
			instance.active = true;
		}
		else {
			return false;
		}
	}
	
	// Set parameters.
	uint8_t pin2 = pin * 2;
	instance.regs->MODER &= ~(0x3 << pin2);
	instance.regs->MODER |= (0x1 << pin2);
	
	instance.regs->PUPDR &= ~(0x3 << pin2);
	if (pupd == GPIO_PULL_UP) {
		instance.regs->PUPDR |= (0x1 << pin2);
	}
	else if (pupd == GPIO_PULL_DOWN) {
		instance.regs->PUPDR |= (0x2 << pin2);
	}
	
	if (type == GPIO_PUSH_PULL) {
		instance.regs->OTYPER &= ~(0x1 << pin);
	}
	else if (type == GPIO_OPEN_DRAIN) {
		instance.regs->OTYPER |= (0x1 << pin);
	}
	
	if (speed == GPIO_LOW) {
		instance.regs->OSPEEDR &= ~(0x3 << pin2);
	}
	else if (speed == GPIO_MID) {
		instance.regs->OSPEEDR &= ~(0x3 << pin2);
		instance.regs->OSPEEDR |= (0x1 << pin2);
	}
	else if (speed == GPIO_HIGH) {
		instance.regs->OSPEEDR &= ~(0x3 << pin2);
		instance.regs->OSPEEDR |= (0x3 << pin2);
	}
	
	return true;
}


// --- SET AF ---
// Set alternate function mode on a pin.
bool GPIO::set_af(GPIO_ports port, uint8_t pin, uint8_t af) {
	// Validate port & pin.
	if (pin > 15) { return false; }
	if (af > 7) { return false; }
	
	GPIO_instance &instance = (*instancesStatic)[port];
	
	// Check if port is active, if not, try to activate it.
	if (!instance.active) {
		if (!Rcc::enablePort((RccPort) port)) { return false; }
		instance.active = true;
	}
	
	// Set parameters.
	uint8_t pin2 = pin * 2;
	instance.regs->MODER &= ~(0x3 << pin2);
	instance.regs->MODER |= (0x2 << pin2);		// AF mode.
	
	// Set AF mode in appropriate (high/low) register.
	if (pin < 8) {
		uint8_t pin4 = pin * 4;
		instance.regs->AFR[0] &= ~(0xF << pin4);
		instance.regs->AFR[0] |= (af << pin4);
	}
	else {
		uint8_t pin4 = (pin - 8) * 4;
		instance.regs->AFR[1] &= ~(0xF << pin4);
		instance.regs->AFR[1] |= (af << pin4);
	}
	
	return true;
}


bool GPIO::set_output_parameters(GPIO_ports port, uint8_t pin, GPIO_pupd pupd, 
							GPIO_out_type type, GPIO_out_speed speed) {
	// Validate port & pin.
	if (pin > 15) { return false; }
	
	GPIO_instance &instance = (*instancesStatic)[port];
	
	// Check if port is active, if not, try to activate it.
	if (!instance.active) {
		if (!Rcc::enablePort((RccPort) port)) { return false; }
		instance.active = true;
	}
	
	uint8_t pin2 = pin * 2;
	
	instance.regs->PUPDR &= ~(0x3 << pin2);
	if (pupd == GPIO_PULL_UP) {
		instance.regs->PUPDR |= (0x1 << pin2);
	}
	else if (pupd == GPIO_PULL_DOWN) {
		instance.regs->PUPDR |= (0x2 << pin2);
	}
	
	if (type == GPIO_PUSH_PULL) {
		instance.regs->OTYPER &= ~(0x1 << pin);
	}
	else if (type == GPIO_OPEN_DRAIN) {
		instance.regs->OTYPER |= (0x1 << pin);
	}
	
	if (speed == GPIO_LOW) {
		instance.regs->OSPEEDR &= ~(0x3 << pin2);
	}
	else if (speed == GPIO_MID) {
		instance.regs->OSPEEDR &= ~(0x3 << pin2);
		instance.regs->OSPEEDR |= (0x1 << pin2);
	}
	else if (speed == GPIO_HIGH) {
		instance.regs->OSPEEDR &= ~(0x3 << pin2);
		instance.regs->OSPEEDR |= (0x3 << pin2);
	}
	
	return true;
}


/* bool GPIO::mode(uint32_t pin, GPIO_mode mode) {
	if (mode == GPIO_MODE_INPUT) {
		//
	}
	else if (mode == GPIO_MODE_OUTPUT) {
		//
	}
	else {
		return false;
	}
	
	return true;
} */


// --- WRITE ---
// Write a digital value to the pin.
bool GPIO::write(GPIO_ports port, uint8_t pin, GPIO_level level) {
	// TODO: ensure pin is in output mode.
	
	if (pin > 15) { return false; }
	
	GPIO_instance &instance = (*instancesStatic)[port];
	
	// Check if port is active, if not, try to activate it.
	if (!instance.active) {
		if (Rcc::enablePort((RccPort) port)) {
			instance.active = true;
		}
		else {
			return false;
		}
	}
	
	// Write to pin.
	if (level == GPIO_LEVEL_LOW) {
		instance.regs->ODR &= ~(0x1 << pin);
	}
	else if (level == GPIO_LEVEL_HIGH) {
		instance.regs->ODR |= (0x1 << pin);
	}
	
	return true;
}


// --- WRITE ---
// Write an analogue value to the pin.
bool GPIO::write(GPIO_ports port, uint8_t pin, uint32_t level) {
	//
	
	return true;
}


// --- READ ---
uint8_t  GPIO::read(GPIO_ports port, uint8_t pin) {
	uint8_t out = 0;
	if (pin > 15) { return false; }
	
	GPIO_instance &instance = (*instancesStatic)[port];
	
	// Check if port is active, if not, try to activate it.
	if (!instance.active) {
		if (Rcc::enablePort((RccPort) port)) {
			instance.active = true;
		}
		else {
			return false;
		}
	}
	
	// Read from pin.
	uint32_t idr = instance.regs->IDR;
	out = (idr >> pin) & 1U;	// Read out desired bit.
	
	return out;
}


// --- READ ANALOG ---
uint32_t GPIO::readAnalog(GPIO_ports port, uint8_t pin) {
	return 0; 
}
