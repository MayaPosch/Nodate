/*
	gpio.cpp - Implementation file for the GPIO class.
*/


#include "gpio.h"


#ifdef NODATE_GPIO_ENABLED

const int gpioCount = 12;


// --- GPIO HANDLES ---
GPIO_instance* GPIO_instances() {
	GPIO_instance instance;
	static GPIO_instance instancesStatic[gpioCount];
	for (int i = 0; i < gpioCount; ++i) {
		instancesStatic[i] = instance;
	}
	
#if defined RCC_AHBENR_GPIOAEN || defined RCC_AHB1ENR_GPIOAEN || defined RCC_APB2ENR_IOPAEN
	instancesStatic[GPIO_PORT_A].regs = GPIOA;
#endif

#if defined RCC_AHBENR_GPIOBEN || defined RCC_AHB1ENR_GPIOBEN || defined RCC_APB2ENR_IOPBEN
	instancesStatic[GPIO_PORT_B].regs = GPIOB;
#endif

#if defined RCC_AHBENR_GPIOCEN || defined RCC_AHB1ENR_GPIOCEN || defined RCC_APB2ENR_IOPCEN
	instancesStatic[GPIO_PORT_C].regs = GPIOC;
#endif

#if defined RCC_AHBENR_GPIODEN || defined RCC_AHB1ENR_GPIODEN || defined RCC_APB2ENR_IOPDEN
	instancesStatic[GPIO_PORT_D].regs = GPIOD;
#endif

#if defined RCC_AHBENR_GPIOEEN || defined RCC_AHB1ENR_GPIOEEN || defined RCC_APB2ENR_IOPEEN
	instancesStatic[GPIO_PORT_E].regs = GPIOE;
#endif

#if defined RCC_AHBENR_GPIOFEN || defined RCC_AHB1ENR_GPIOFEN
	instancesStatic[GPIO_PORT_F].regs = GPIOF;
#endif
	
	return instancesStatic;
}

//GPIO_instance* instancesStatic = GPIO_instances();

bool afio_enabled = false;


// --- SET INPUT ---
bool GPIO::set_input(GPIO_ports port, uint8_t pin, GPIO_pupd pupd) {
	// Validate port & pin.
	if (pin > 15) { return false; }
	
	GPIO_instance* instancesStatic = GPIO_instances();
	GPIO_instance &instance = instancesStatic[port];
	
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
#ifdef STM32F1
	// Input/output registers are spread over two registers (CRL, CRH).
	if (pin < 8) {
		// Set CRL register (CNF 0x2 & MODE 0x0).
		uint8_t pinmode = pin * 4;
		uint8_t pincnf = pinmode + 2;
		instance.regs->CRL &= ~(0xF << pinmode);
		if (pupd == GPIO_FLOATING) {
			instance.regs->CRL |= (0x1 << pincnf);
		}
		else {
			instance.regs->CRL |= (0x2 << pincnf);
			if (pupd == GPIO_PULL_UP) {
				instance.regs->ODR |= (1 << pin);
			}
			else {
				instance.regs->ODR &= ~(1 << pin);
			}
		}
	}
	else {
		// Set CRH register.
		uint8_t pinmode = (pin - 8) * 4;
		uint8_t pincnf = pinmode + 2;
		instance.regs->CRH &= ~(0xF << pinmode);
		if (pupd == GPIO_FLOATING) {
			instance.regs->CRH |= (0x1 << pincnf);
		}
		else {
			instance.regs->CRH |= (0x2 << pincnf);
			if (pupd == GPIO_PULL_UP) {
				instance.regs->ODR |= (1 << (pin - 8));
			}
			else {
				instance.regs->ODR &= ~(1 << (pin - 8));
			}
		}
	}
#else
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
#endif

	return true;
}


// --- SET OUTPUT ---
bool GPIO::set_output(GPIO_ports port, uint8_t pin, GPIO_pupd pupd, GPIO_out_type type, 
																	GPIO_out_speed speed) {
	// Validate port & pin.
	if (pin > 15) { return false; }
	
	GPIO_instance* instancesStatic = GPIO_instances();
	GPIO_instance &instance = instancesStatic[port];
	
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
#ifdef STM32F1
	// Input/output registers are spread over two combined registers (CRL, CRH).
	if (pin < 8) {
		// Set CRL register (CNF & MODE).
		uint8_t pinmode = pin * 4;
		uint8_t pincnf = pinmode + 2;
		
		if (speed == GPIO_LOW) {		instance.regs->CRL |= (0x2 << pinmode); }
		else if (speed == GPIO_MID) {	instance.regs->CRL |= (0x1 << pinmode);	}
		else if (speed == GPIO_HIGH) {	instance.regs->CRL |= (0x3 << pinmode);	}
	
		if (type == GPIO_PUSH_PULL) {		instance.regs->CRL &= ~(0x1 << pincnf);	}
		else if (type == GPIO_OPEN_DRAIN) {	instance.regs->CRL |= (0x1 << pincnf);	}
	}
	else {
		// Set CRH register.
		uint8_t pinmode = (pin - 8) * 4;
		uint8_t pincnf = pinmode + 2;
		
		if (speed == GPIO_LOW) {		instance.regs->CRH |= (0x2 << pinmode); }
		else if (speed == GPIO_MID) {	instance.regs->CRH |= (0x1 << pinmode);	}
		else if (speed == GPIO_HIGH) {	instance.regs->CRH |= (0x3 << pinmode);	}
	
		if (type == GPIO_PUSH_PULL) {		instance.regs->CRH &= ~(0x1 << pincnf);	}
		else if (type == GPIO_OPEN_DRAIN) {	instance.regs->CRH |= (0x1 << pincnf);	}
	}
#else
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
#endif
	
	return true;
}


// --- SET AF ---
// Set alternate function mode on a pin.
bool GPIO::set_af(GPIO_ports port, uint8_t pin, uint8_t af) {
	// Validate port & pin.
	if (pin > 15) { return false; }
	if (af > 15) { return false; }
	
	GPIO_instance* instancesStatic = GPIO_instances();
	GPIO_instance &instance = instancesStatic[port];
	
	// Check if port is active, if not, try to activate it.
	if (!instance.active) {
		if (!Rcc::enablePort((RccPort) port)) { return false; }
		instance.active = true;
	}
	
	// Set parameters.
#ifdef STM32F1
	// STM32F1 Details:
	// Input/output registers are spread over two combined registers (CRL, CRH).
	// A call to GPIO::set_af(RccPeripheral per, uint8_t af) is also required
	// to fully enable an Alternate Function
	if (pin < 8) {
		// Set CRL register (CNF).
		uint8_t pincnf = (pin * 4) + 3;
		instance.regs->CRL |= (0x1 << pincnf);
	}
	else {
		// Set CRH register (CNF).
		uint8_t pincnf = ((pin - 8) * 4) + 3;
		instance.regs->CRH |= (0x1 << pincnf);
	}

#else
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
#endif
	return true;
}


// --- SET AF ---
// Set alternate function mode on a pin.
bool GPIO::set_af(RccPeripheral per, uint8_t af) {
#ifdef STM32F1
	// For STM32F1, only two possible values are possible for AF: remapped (1) or not remapped (0).
	if (af > 1) { return false; }
	
	// Ensure the AFIO peripheral is enabled.
	if (!afio_enabled) {
		if (!Rcc::enable(RCC_AFIO)) {
			// TODO: set error.
			return false;
		}
		
		afio_enabled = true;
	}
	
	// Set correct value in AFIO_MAPR register.
	uint8_t pos = 0;
	if (per == RCC_SPI1) 		{ pos = AFIO_MAPR_SPI1_REMAP_Pos; }
	else if (per == RCC_I2C1)	{ pos = AFIO_MAPR_I2C1_REMAP_Pos; }
	else if (per == RCC_USART1)	{ pos = AFIO_MAPR_USART1_REMAP_Pos; }
	else if (per == RCC_USART2)	{ pos = AFIO_MAPR_USART2_REMAP_Pos; }
	//else if (per == RCC_USART3)	{ pos = AFIO_MAPR_USART3_REMAP_Pos; }
	else if (per == RCC_TIM1)	{ pos = AFIO_MAPR_TIM1_REMAP_Pos; }
	else if (per == RCC_TIM2)	{ pos = AFIO_MAPR_TIM2_REMAP_Pos; }
	else if (per == RCC_TIM3)	{ pos = AFIO_MAPR_TIM3_REMAP_Pos; }
	//else if (per == RCC_TIM4)	{ pos = AFIO_MAPR_TIM4_REMAP_Pos; }
	else if (per == RCC_CAN)	{ pos = AFIO_MAPR_CAN_REMAP_Pos; }
	else { return false; } // TODO: refactor.
	
	if (af == 1) {
		AFIO->MAPR |= (1 << pos);
	}
	else {
		AFIO->MAPR &= ~(1 << pos);
	}
	
	return true;
#else
	return false;
#endif
}


// --- SET ANALOG ---
// Set the specified pin to analogue mode.
bool set_analog(GPIO_ports port, uint8_t pin) {
	if (pin > 15) { return false; }
	
	GPIO_instance* instancesStatic = GPIO_instances();
	GPIO_instance &instance = instancesStatic[port];
	
	// Check if port is active, if not, try to activate it.
	if (!instance.active) {
		if (!Rcc::enablePort((RccPort) port)) { return false; }
		instance.active = true;
	}

	// Set parameters
#ifdef STM32F1
	// TODO: implement.
	return false;
	
#else
	uint8_t pin2 = pin * 2;
	instance.regs->MODER |= (0x3 << pin2);		// analogue mode.
	return true;
#endif
}


bool GPIO::set_output_parameters(GPIO_ports port, uint8_t pin, GPIO_pupd pupd, 
							GPIO_out_type type, GPIO_out_speed speed) {
	// Validate port & pin.
	if (pin > 15) { return false; }
	
	GPIO_instance* instancesStatic = GPIO_instances();
	GPIO_instance &instance = instancesStatic[port];
	
	// Check if port is active, if not, try to activate it.
	if (!instance.active) {
		if (!Rcc::enablePort((RccPort) port)) { return false; }
		instance.active = true;
	}

#ifdef STM32F1
	// Input/output registers are spread over two combined registers (CRL, CRH).
	if (pin < 8) {
		// Set CRL register (CNF & MODE).
		uint8_t pinmode = pin * 4;
		uint8_t pincnf = pinmode + 2;
		
		if (speed == GPIO_LOW) {		instance.regs->CRL |= (0x2 << pinmode); }
		else if (speed == GPIO_MID) {	instance.regs->CRL |= (0x1 << pinmode);	}
		else if (speed == GPIO_HIGH) {	instance.regs->CRL |= (0x3 << pinmode);	}
	
		if (type == GPIO_PUSH_PULL) {		instance.regs->CRL &= ~(0x1 << pincnf);	}
		else if (type == GPIO_OPEN_DRAIN) {	instance.regs->CRL |= (0x1 << pincnf);	}
	}
	else {
		// Set CRH register.
		uint8_t pinmode = (pin - 8) * 4;
		uint8_t pincnf = pinmode + 2;
		
		if (speed == GPIO_LOW) {		instance.regs->CRH |= (0x2 << pinmode); }
		else if (speed == GPIO_MID) {	instance.regs->CRH |= (0x1 << pinmode);	}
		else if (speed == GPIO_HIGH) {	instance.regs->CRH |= (0x3 << pinmode);	}
	
		if (type == GPIO_PUSH_PULL) {		instance.regs->CRH &= ~(0x1 << pincnf);	}
		else if (type == GPIO_OPEN_DRAIN) {	instance.regs->CRH |= (0x1 << pincnf);	}
	}
#else
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
#endif
	
	return true;
}


// --- WRITE ---
// Write a digital value to the pin.
bool GPIO::write(GPIO_ports port, uint8_t pin, GPIO_level level) {
	// TODO: ensure pin is in output mode.
	
	if (pin > 15) { return false; }
	
	GPIO_instance* instancesStatic = GPIO_instances();
	GPIO_instance &instance = instancesStatic[port];
	
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
	
	GPIO_instance* instancesStatic = GPIO_instances();
	GPIO_instance &instance = instancesStatic[port];
	
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


#endif
