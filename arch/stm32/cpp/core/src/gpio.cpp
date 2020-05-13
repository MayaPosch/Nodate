/*
	gpio.cpp - Implementation file for the GPIO class.
*/


#include "gpio.h"


// --- CONSTRUCTOR ---
GPIO::GPIO() {
	// Enable all GPIO banks.
#ifdef GPIOA_BASE
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
#endif

#ifdef GPIOB_BASE
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
#endif

#ifdef GPIOC_BASE
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
#endif

#ifdef GPIOF_BASE
	RCC->AHBENR |= RCC_AHBENR_GPIOFEN;
#endif
}


// --- DESTRUCTOR ---
GPIO::~GPIO() {
	// Disable all GPIO banks.
#ifdef GPIOA_BASE
	RCC->AHBENR &= ~(RCC_AHBENR_GPIOAEN);
#endif

#ifdef GPIOB_BASE
	RCC->AHBENR &= ~(RCC_AHBENR_GPIOBEN);
#endif

#ifdef GPIOC_BASE
	RCC->AHBENR &= ~(RCC_AHBENR_GPIOCEN);
#endif

#ifdef GPIOF_BASE
	RCC->AHBENR &= ~(RCC_AHBENR_GPIOFEN);
#endif
}


// --- SET INPUT ---
bool GPIO::set_input(GPIO_ports port, uint8_t pin, GPIO_pupd pupd) {
	// Validate port & pin.
	if (pin > 15) { return false; }
#ifdef GPIOA
	else if (port == GPIO_PORT_A) {
		// Set parameters.
		GPIOA->MODER &= ~(0x3 << (pin * 2));
		GPIOA->PUPDR &= ~(0x3 << (pin * 2));
		if (pupd == GPIO_PULL_UP) {
			GPIOA->PUPDR |= (0x1 << (pin * 2));
		}
		else if (pupd == GPIO_PULL_DOWN) {
			GPIOA->PUPDR |= (0x2 << (pin * 2));
		}
	}
#endif
#ifdef GPIOB
	else if (port == GPIO_PORT_B) {
		// Set parameters.
		GPIOB->MODER &= ~(0x3 << (pin * 2));
		GPIOB->PUPDR &= ~(0x3 << (pin * 2));
		if (pupd == GPIO_PULL_UP) {
			GPIOB->PUPDR |= (0x1 << (pin * 2));
		}
		else if (pupd == GPIO_PULL_DOWN) {
			GPIOB->PUPDR |= (0x2 << (pin * 2));
		}
	}
#endif
#ifdef GPIOC
	else if (port == GPIO_PORT_C) {
		// Set parameters.
		GPIOC->MODER &= ~(0x3 << (pin * 2));
		GPIOC->PUPDR &= ~(0x3 << (pin * 2));
		if (pupd == GPIO_PULL_UP) {
			GPIOC->PUPDR |= (0x1 << (pin * 2));
		}
		else if (pupd == GPIO_PULL_DOWN) {
			GPIOC->PUPDR |= (0x2 << (pin * 2));
		}
	}
#endif
#ifdef GPIOF
	else if (port == GPIO_PORT_F) {
		// Set parameters.
		GPIOF->MODER &= ~(0x3 << (pin * 2));
		GPIOF->PUPDR &= ~(0x3 << (pin * 2));
		if (pupd == GPIO_PULL_UP) {
			GPIOF->PUPDR |= (0x1 << (pin * 2));
		}
		else if (pupd == GPIO_PULL_DOWN) {
			GPIOF->PUPDR |= (0x2 << (pin * 2));
		}
	}
#endif
	else {
		return false;
	}
	
	return true;
}


// --- SET OUTPUT ---
bool GPIO::set_output(GPIO_ports port, uint8_t pin, GPIO_pupd pupd, GPIO_out_type type, 
																	GPIO_out_speed speed) {
	// Validate port & pin.
	if (pin > 15) { return false; }
#ifdef GPIOA
	else if (port == GPIO_PORT_A) {
		// Set parameters.
		GPIOA->MODER &= ~(0x3 << (pin * 2));
		GPIOA->MODER |= (0x1 << (pin * 2));
		
		GPIOA->PUPDR &= ~(0x3 << (pin * 2));
		if (pupd == GPIO_PULL_UP) {
			GPIOA->PUPDR |= (0x1 << (pin * 2));
		}
		else if (pupd == GPIO_PULL_DOWN) {
			GPIOA->PUPDR |= (0x2 << (pin * 2));
		}
		
		if (type == GPIO_PUSH_PULL) {
			GPIOA->OTYPER &= ~(0x1 << pin);
		}
		else if (type == GPIO_OPEN_DRAIN) {
			GPIOA->OTYPER |= (0x1 << pin);
		}
		
		if (speed == GPIO_LOW) {
			GPIOA->OSPEEDR &= ~(0x3 << (pin * 2));
		}
		else if (speed == GPIO_MID) {
			GPIOA->OSPEEDR &= ~(0x3 << (pin * 2));
			GPIOA->OSPEEDR |= (0x1 << (pin * 2));
		}
		else if (speed == GPIO_HIGH) {
			GPIOA->OSPEEDR &= ~(0x3 << (pin * 2));
			GPIOA->OSPEEDR |= (0x3 << (pin * 2));
		}
	}
#endif
#ifdef GPIOB
	else if (port == GPIO_PORT_B) {
		// Set parameters.
		GPIOB->MODER &= ~(0x3 << (pin * 2));
		GPIOB->MODER |= (0x1 << (pin * 2));
		
		GPIOB->PUPDR &= ~(0x3 << (pin * 2));
		if (pupd == GPIO_PULL_UP) {
			GPIOB->PUPDR |= (0x1 << (pin * 2));
		}
		else if (pupd == GPIO_PULL_DOWN) {
			GPIOB->PUPDR |= (0x2 << (pin * 2));
		}
		
		if (type == GPIO_PUSH_PULL) {
			GPIOB->OTYPER &= ~(0x1 << pin);
		}
		else if (type == GPIO_OPEN_DRAIN) {
			GPIOB->OTYPER |= (0x1 << pin);
		}
		
		if (speed == GPIO_LOW) {
			GPIOB->OSPEEDR &= ~(0x3 << (pin * 2));
		}
		else if (speed == GPIO_MID) {
			GPIOB->OSPEEDR &= ~(0x3 << (pin * 2));
			GPIOB->OSPEEDR |= (0x1 << (pin * 2));
		}
		else if (speed == GPIO_HIGH) {
			GPIOB->OSPEEDR &= ~(0x3 << (pin * 2));
			GPIOB->OSPEEDR |= (0x3 << (pin * 2));
		}
	}
#endif
#ifdef GPIOC
	else if (port == GPIO_PORT_C) {
		// Set parameters.
		GPIOC->MODER &= ~(0x3 << (pin * 2));
		GPIOC->MODER |= (0x1 << (pin * 2));
		
		GPIOC->PUPDR &= ~(0x3 << (pin * 2));
		if (pupd == GPIO_PULL_UP) {
			GPIOC->PUPDR |= (0x1 << (pin * 2));
		}
		else if (pupd == GPIO_PULL_DOWN) {
			GPIOC->PUPDR |= (0x2 << (pin * 2));
		}
		
		if (type == GPIO_PUSH_PULL) {
			GPIOC->OTYPER &= ~(0x1 << pin);
		}
		else if (type == GPIO_OPEN_DRAIN) {
			GPIOC->OTYPER |= (0x1 << pin);
		}
		
		if (speed == GPIO_LOW) {
			GPIOC->OSPEEDR &= ~(0x3 << (pin * 2));
		}
		else if (speed == GPIO_MID) {
			GPIOC->OSPEEDR &= ~(0x3 << (pin * 2));
			GPIOC->OSPEEDR |= (0x1 << (pin * 2));
		}
		else if (speed == GPIO_HIGH) {
			GPIOC->OSPEEDR &= ~(0x3 << (pin * 2));
			GPIOC->OSPEEDR |= (0x3 << (pin * 2));
		}
	}
#endif
#ifdef GPIOF
	else if (port == GPIO_PORT_F) {
		// Set parameters.
		GPIOF->MODER &= ~(0x3 << (pin * 2));
		GPIOF->MODER |= (0x1 << (pin * 2));
		
		GPIOF->PUPDR &= ~(0x3 << (pin * 2));
		if (pupd == GPIO_PULL_UP) {
			GPIOF->PUPDR |= (0x1 << (pin * 2));
		}
		else if (pupd == GPIO_PULL_DOWN) {
			GPIOF->PUPDR |= (0x2 << (pin * 2));
		}
		
		if (type == GPIO_PUSH_PULL) {
			GPIOF->OTYPER &= ~(0x1 << pin);
		}
		else if (type == GPIO_OPEN_DRAIN) {
			GPIOF->OTYPER |= (0x1 << pin);
		}
		
		if (speed == GPIO_LOW) {
			GPIOF->OSPEEDR &= ~(0x3 << (pin * 2));
		}
		else if (speed == GPIO_MID) {
			GPIOF->OSPEEDR &= ~(0x3 << (pin * 2));
			GPIOF->OSPEEDR |= (0x1 << (pin * 2));
		}
		else if (speed == GPIO_HIGH) {
			GPIOF->OSPEEDR &= ~(0x3 << (pin * 2));
			GPIOF->OSPEEDR |= (0x3 << (pin * 2));
		}
	}
#endif
	else {
		return false;
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
#ifdef GPIOA
	else if (port == GPIO_PORT_A) {	
		if (level == GPIO_LEVEL_LOW) {
			GPIOA->ODR &= ~(0x1 << pin);
		}
		else if (level == GPIO_LEVEL_HIGH) {
			GPIOA->ODR |= (0x1 << pin);
		}
	}
#endif
#ifdef GPIOB
	else if (port == GPIO_PORT_B) {	
		if (level == GPIO_LEVEL_LOW) {
			GPIOB->ODR &= ~(0x1 << pin);
		}
		else if (level == GPIO_LEVEL_HIGH) {
			GPIOB->ODR |= (0x1 << pin);
		}
	}
#endif
#ifdef GPIOC
	else if (port == GPIO_PORT_C) {	
		if (level == GPIO_LEVEL_LOW) {
			GPIOC->ODR &= ~(0x1 << pin);
		}
		else if (level == GPIO_LEVEL_HIGH) {
			GPIOC->ODR |= (0x1 << pin);
		}
	}
#endif
#ifdef GPIOF
	else if (port == GPIO_PORT_F) {	
		if (level == GPIO_LEVEL_LOW) {
			GPIOF->ODR &= ~(0x1 << pin);
		}
		else if (level == GPIO_LEVEL_HIGH) {
			GPIOF->ODR |= (0x1 << pin);
		}
	}
#endif
	
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
#ifdef GPIOA
	else if (port == GPIO_PORT_A) {
		uint32_t idr = GPIOA->IDR;
		out = (idr >> pin) & 1U; // Read out desired bit.
	}
#endif
#ifdef GPIOB
	else if (port == GPIO_PORT_B) {
		uint32_t idr = GPIOB->IDR;
		out = (idr >> pin) & 1U; // Read out desired bit.
	}
#endif
#ifdef GPIOC
	else if (port == GPIO_PORT_C) {
		uint32_t idr = GPIOC->IDR;
		out = (idr >> pin) & 1U; // Read out desired bit.
	}
#endif
#ifdef GPIOF
	else if (port == GPIO_PORT_F) {
		uint32_t idr = GPIOF->IDR;
		out = (idr >> pin) & 1U; // Read out desired bit.
	}
#endif

	
	return out;
}


// --- READ ANALOG ---
uint32_t GPIO::readAnalog(GPIO_ports port, uint8_t pin) {
	return 0; 
}
