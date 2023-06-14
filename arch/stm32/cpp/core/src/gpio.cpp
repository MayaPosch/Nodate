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
	
#if defined RCC_AHBENR_GPIOAEN || defined RCC_AHB1ENR_GPIOAEN || defined RCC_APB2ENR_IOPAEN || RCC_AHB2ENR_GPIOAEN
	instancesStatic[GPIO_PORT_A].regs = GPIOA;
#endif

#if defined RCC_AHBENR_GPIOBEN || defined RCC_AHB1ENR_GPIOBEN || defined RCC_APB2ENR_IOPBEN || RCC_AHB2ENR_GPIOBEN
	instancesStatic[GPIO_PORT_B].regs = GPIOB;
#endif

#if defined RCC_AHBENR_GPIOCEN || defined RCC_AHB1ENR_GPIOCEN || defined RCC_APB2ENR_IOPCEN || RCC_AHB2ENR_GPIOCEN
	instancesStatic[GPIO_PORT_C].regs = GPIOC;
#endif

#if defined RCC_AHBENR_GPIODEN || defined RCC_AHB1ENR_GPIODEN || defined RCC_APB2ENR_IOPDEN || RCC_AHB2ENR_GPIODEN
	instancesStatic[GPIO_PORT_D].regs = GPIOD;
#endif

#if defined RCC_AHBENR_GPIOEEN || defined RCC_AHB1ENR_GPIOEEN || defined RCC_APB2ENR_IOPEEN || RCC_AHB2ENR_GPIOEEN
	instancesStatic[GPIO_PORT_E].regs = GPIOE;
#endif

#if defined RCC_AHBENR_GPIOFEN || defined RCC_AHB1ENR_GPIOFEN || defined RCC_APB2ENR_IOPFEN  || RCC_AHB2ENR_GPIOFEN
	instancesStatic[GPIO_PORT_F].regs = GPIOF;
#endif

#if defined RCC_AHBENR_GPIOGEN || defined RCC_AHB1ENR_GPIOGEN || defined RCC_APB2ENR_IOPGEN  || RCC_AHB2ENR_GPIOGEN
	instancesStatic[GPIO_PORT_G].regs = GPIOG;
#endif

#if defined RCC_AHBENR_GPIOHEN || defined RCC_AHB1ENR_GPIOHEN || defined RCC_APB2ENR_IOPHEN  || RCC_AHB2ENR_GPIOHEN
	instancesStatic[GPIO_PORT_H].regs = GPIOH;
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
#ifdef __stm32f1
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
#ifdef __stm32f1
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


// --- SET OUTPUT ---
bool GPIO::set_output(GpioPinDef def, GPIO_pupd pupd, GPIO_out_type type, GPIO_out_speed speed) {
	return set_output(def.port, def.pin, pupd, type, speed);
}


// --- SET AF ---
/**
 * \brief       Set alternate function mode for a pin
 *
 * Configures an MCU pin for alternate function mode.  Use with STM32F1
 * requires an additional call to GPIO::set_af(per, af) to fully
 * implement the alternate function.
 *
 * \param[in]   port: GPIO port
 * \param[in]   pin: pin to be modified
 * \return      true on success, false otherwise
 */
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
#ifdef __stm32f1
	// STM32F1 Details:
	// Input/output registers are spread over two combined registers (CRL, CRH).
	// A call to GPIO::set_af(RccPeripheral per, uint8_t af) is also required
	// to fully enable an Alternate Function
	/* if (pin < 8) {
		// Set CRL register (CNF).
		uint8_t pincnf = (pin * 4) + 3;
		instance.regs->CRL |= (0x1 << pincnf);
	}
	else {
		// Set CRH register (CNF).
		uint8_t pincnf = ((pin - 8) * 4) + 3;
		instance.regs->CRH |= (0x1 << pincnf);
	} */
	
	return false;

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
bool GPIO::set_af(GpioPinDef def) {
	return set_af(def.port, def.pin, def.af);
}


// --- SET AF ---
/**
 * \brief       Set alternate function mode for a peripheral
 *
 * Configures an MCU peripheral for alternate function mode.  Applies only to STM32F1.
 * Acceptable values of the af parameter is dependent on the peripheral selected.
 * Returns true if peripheral is set to alternate function mode or if peripheral has
 * no alternate function option available.  Returns false if improper alternate
 * function mode value is requested or if MCU is not in the STM32F1 line.
 * See the MCU documentation for additional details.
 *
 * \param[in]   per: peripheral
 * \param[in]   af: alternate function mode value
 * \return      true on success, false otherwise
 */
bool GPIO::set_af(GPIO_ports port, uint8_t pin, RccPeripheral per, uint8_t af, GPIO_out_type type) {
#ifdef __stm32f1
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
	
	// First set the GPIO parameters.
	// Input/output registers are spread over two combined registers (CRL, CRH).
	if (pin < 8) {
		// Set CRL register (CNF & MODE).
		uint8_t pinmode = pin * 4; // Offset into register.
		uint8_t pincnf = pinmode + 2;
		
		/* if (speed == GPIO_LOW) {		instance.regs->CRL |= (0x2 << pinmode); }
		else if (speed == GPIO_MID) {	instance.regs->CRL |= (0x1 << pinmode);	}
		else if (speed == GPIO_HIGH) {	instance.regs->CRL |= (0x3 << pinmode);	} */
	
		// Set AF version, not the general output PU/PD.
		instance.regs->CRL &= ~(0x3 << pincnf); // Reset.
		if (type == GPIO_PUSH_PULL) {		instance.regs->CRL |= (0x2 << pincnf);	}
		else if (type == GPIO_OPEN_DRAIN) {	instance.regs->CRL |= (0x3 << pincnf);	}
	}
	else {
		// Set CRH register.
		uint8_t pinmode = (pin - 8) * 4;
		uint8_t pincnf = pinmode + 2;
		
		/* if (speed == GPIO_LOW) {		instance.regs->CRH |= (0x2 << pinmode); }
		else if (speed == GPIO_MID) {	instance.regs->CRH |= (0x1 << pinmode);	}
		else if (speed == GPIO_HIGH) {	instance.regs->CRH |= (0x3 << pinmode);	} */
	
		instance.regs->CRH &= ~(0x3 << pincnf);
		if (type == GPIO_PUSH_PULL) {		instance.regs->CRH |= (0x2 << pincnf);	}
		else if (type == GPIO_OPEN_DRAIN) {	instance.regs->CRH |= (0x3 << pincnf);	}
	}
	
	if (af == 0) {
		// No remapping requested, we are done here.
		return true;
	}
	
	uint32_t field_mask = 0x3;
	if ((per == RCC_USART3) || (per == RCC_TIM1) || (per == RCC_TIM2) || (per == RCC_TIM3) || (per == RCC_CAN)) {
		// four values are possible for AF
		if (af > 3) { return false; }
	}
	else {
		// two values are possible for AF: remapped (1) or not remapped (0).
		if (af > 1) { return false; }
		field_mask = 0x1;
	}
	
	// Ensure the AFIO peripheral is enabled.
	if (!afio_enabled) {
		if (!Rcc::enable(RCC_AFIO)) {
			return false;
		}
		afio_enabled = true;
	}
	
	// Set correct value in AFIO_MAPR register.
	// Not all peripherals are available on all MCU's
	// Not all peripherals available on an MCU have remappable alternate functions
	// spi1 and i2c1 are not bracketed by an #if define because they always exist
	// and are remappable
	uint8_t pos = 0;
	if (per == RCC_SPI1) 		{ pos = AFIO_MAPR_SPI1_REMAP_Pos; }
	else if (per == RCC_I2C1)	{ pos = AFIO_MAPR_I2C1_REMAP_Pos; }
#if defined AFIO_MAPR_USART1_REMAP_Pos
	else if (per == RCC_USART1)	{ pos = AFIO_MAPR_USART1_REMAP_Pos; }
#endif
#if defined AFIO_MAPR_USART2_REMAP_Pos
	else if (per == RCC_USART2)	{ pos = AFIO_MAPR_USART2_REMAP_Pos; }
#endif
#if defined AFIO_MAPR_USART3_REMAP_Pos
	else if (per == RCC_USART3)	{ pos = AFIO_MAPR_USART3_REMAP_Pos; }
#endif
	else if (per == RCC_TIM1)	{ pos = AFIO_MAPR_TIM1_REMAP_Pos; }
	else if (per == RCC_TIM2)	{ pos = AFIO_MAPR_TIM2_REMAP_Pos; }
	else if (per == RCC_TIM3)	{ pos = AFIO_MAPR_TIM3_REMAP_Pos; }
#if defined AFIO_MAPR_TIM4_REMAP_Pos
	else if (per == RCC_TIM4)	{ pos = AFIO_MAPR_TIM4_REMAP_Pos; }
#endif
#if defined AFIO_MAPR_CAN_REMAP_Pos
	else if (per == RCC_CAN)	{ pos = AFIO_MAPR_CAN_REMAP_Pos; }
#endif
	else {
		// per is not a remappable peripheral; return true as there
		// is no work to be done
		return true;
		
	}

	// clear and set the appropriate field
	AFIO->MAPR &= ~(field_mask << pos);
	AFIO->MAPR |= (af << pos);
	return true;
#else
	// Default for MCUs other than STM32F1 series
	return false;
#endif
}


// --- SET ANALOG ---
// Set the specified pin to analogue mode.
bool GPIO::set_analog(GPIO_ports port, uint8_t pin) {
	if (pin > 15) { return false; }
	
	GPIO_instance* instancesStatic = GPIO_instances();
	GPIO_instance &instance = instancesStatic[port];
	
	// Check if port is active, if not, try to activate it.
	if (!instance.active) {
		if (!Rcc::enablePort((RccPort) port)) { return false; }
		instance.active = true;
	}

	// Set parameters
#ifdef __stm32f1
	// TODO: implement.
	return false;
	
#else
	uint8_t pin2 = pin * 2;
	instance.regs->MODER |= (0x3 << pin2);		// analogue mode.
	return true;
#endif
}


// --- SET OUTPUT PARAMETERS ---
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

#ifdef __stm32f1
	// Input/output registers are spread over two combined registers (CRL, CRH).
	if (pin < 8) {
		// Set CRL register (CNF & MODE).
		uint8_t pinmode = pin * 4; // Offset into register.
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


// --- SET OUTPUT PARAMETERS ---
bool GPIO::set_output_parameters(GpioPinDef def, GPIO_pupd pupd, GPIO_out_type type, 
																GPIO_out_speed speed) {
	return set_output_parameters(def.port, def.pin, pupd, type, speed);
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
bool GPIO::write(GpioPinDef def, GPIO_level level) {
	return write(def.port, def.pin, level);
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
