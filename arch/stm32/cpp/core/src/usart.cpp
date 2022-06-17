/*
	usart.h - Implementation of the USART functionality.
	
*/


#include <usart.h>


#ifdef NODATE_USART_ENABLED

const uint8_t usartCount = 8;


// --- USART DEVICES ---
USART_device* USART_list() {
	USART_device device;
	static USART_device devicesStatic[usartCount];
	for (int i = 0; i < usartCount; ++i) {
		devicesStatic[i] = device;
	}

#if defined RCC_APB2ENR_USART1EN
	devicesStatic[USART_1].regs = USART1;
	devicesStatic[USART_1].irqType = USART1_IRQn;
#endif

#if defined RCC_APB1ENR_USART2EN
	devicesStatic[USART_2].regs = USART2;
	devicesStatic[USART_2].irqType = USART2_IRQn;
#elif defined RCC_APB1ENR1_USART2EN
	devicesStatic[USART_2].regs = USART2;
	devicesStatic[USART_2].irqType = USART2_IRQn;
#endif

#if defined RCC_APB1ENR_USART3EN
#if defined __stm32f0
	devicesStatic[USART_3].regs = USART3;
	devicesStatic[USART_3].irqType = USART3_4_IRQn;
#else
	devicesStatic[USART_3].regs = USART3;
	devicesStatic[USART_3].irqType = USART3_IRQn;
#endif
#elif defined RCC_APB1ENR1_USART3EN
	devicesStatic[USART_2].regs = USART3;
	devicesStatic[USART_2].irqType = USART3_IRQn;
#endif

#if defined RCC_APB1ENR_UART4EN
#if defined __stm32f0
	devicesStatic[USART_4].regs = UART4;
	devicesStatic[USART_4].irqType = USART3_4_IRQn;
#else
	devicesStatic[USART_4].regs = UART4;
	devicesStatic[USART_4].irqType = UART4_IRQn;
#endif
#elif defined RCC_APB1ENR1_UART4EN
	devicesStatic[USART_2].regs = UART4;
	devicesStatic[USART_2].irqType = UART4_IRQn;
#endif

#if defined RCC_APB1ENR_UART5EN
	devicesStatic[USART_5].regs = UART5;
	devicesStatic[USART_5].irqType = UART5_IRQn;
#endif

#if defined RCC_APB2ENR_USART6EN
	devicesStatic[USART_6].regs = USART6;
	devicesStatic[USART_6].irqType = USART6_IRQn;
#endif

#if defined RCC_APB1ENR_UART7EN
	devicesStatic[USART_7].regs = UART7;
	devicesStatic[USART_7].irqType = UART7_IRQn;
#endif

#if defined RCC_APB1ENR_UART8EN
	devicesStatic[USART_8].regs = UART8;
	devicesStatic[USART_8].irqType = UART8_IRQn;
#endif
	
	return devicesStatic;
}


USART_device* devicesStatic = USART_list();


GPIO USART::gpio;


// Callback handlers.
// Overrides the default handlers and allows the use of custom callback functions.
#if defined __stm32f0
extern "C" {
	void USART1_IRQHandler(void);
	void USART2_IRQHandler(void);
	void USART3_4_IRQHandler(void);
}
#else
extern "C" {
	void USART1_IRQHandler(void);
	void USART2_IRQHandler(void);
	void USART3_IRQHandler(void);
	void USART4_IRQHandler(void);
	void USART5_IRQHandler(void);
	void USART6_IRQHandler(void);
	void USART7_IRQHandler(void);
	void USART8_IRQHandler(void);
}
#endif

volatile char rxb = 'a';

#if defined __stm32f0

void USART1_IRQHandler(void) {
	USART_device &instance = devicesStatic[0];
	if (instance.regs->ISR & USART_ISR_RXNE) {
		rxb = instance.regs->RDR;
		instance.callback(rxb);
	}
}

void USART2_IRQHandler(void) {
	USART_device &instance = devicesStatic[1];
	if (instance.regs->ISR & USART_ISR_RXNE) {
		rxb = instance.regs->RDR;
		instance.callback(rxb);
	}
}

void USART3_4_IRQHandler(void) {
	USART_device &instance = devicesStatic[2];
	USART_device &instance2 = devicesStatic[3];
	if (instance.regs->ISR & USART_ISR_RXNE) {
		rxb = instance.regs->RDR;
		instance.callback(rxb);
	}
	else if (instance2.regs->ISR & USART_ISR_RXNE) {
		rxb = instance2.regs->RDR;
		instance2.callback(rxb);
	}
}

#elif defined __stm32f1 || defined __stm32f4

void USART1_IRQHandler(void) {
	USART_device &instance = devicesStatic[0];
	if (instance.regs->SR & USART_SR_RXNE) {
		rxb = instance.regs->DR;
		instance.callback(rxb);
	}
}

void USART2_IRQHandler(void) {
	USART_device &instance = devicesStatic[1];
	if (instance.regs->SR & USART_SR_RXNE) {
		rxb = instance.regs->DR;
		instance.callback(rxb);
	}
}

void USART3_IRQHandler(void) {
	USART_device &instance = devicesStatic[2];
	if (instance.regs->SR & USART_SR_RXNE) {
		rxb = instance.regs->DR;
		instance.callback(rxb);
	}
}

void USART4_IRQHandler(void) {
	USART_device &instance = devicesStatic[3];
	if (instance.regs->SR & USART_SR_RXNE) {
		rxb = instance.regs->DR;
		instance.callback(rxb);
	}
}

void USART5_IRQHandler(void) {
	USART_device &instance = devicesStatic[4];
	if (instance.regs->SR & USART_SR_RXNE) {
		rxb = instance.regs->DR;
		instance.callback(rxb);
	}
}

void USART6_IRQHandler(void) {
	USART_device &instance = devicesStatic[5];
	if (instance.regs->SR & USART_SR_RXNE) {
		rxb = instance.regs->DR;
		instance.callback(rxb);
	}
}

void USART7_IRQHandler(void) {
	USART_device &instance = devicesStatic[6];
	if (instance.regs->SR & USART_SR_RXNE) {
		rxb = instance.regs->DR;
		instance.callback(rxb);
	}
}

void USART8_IRQHandler(void) {
	USART_device &instance = devicesStatic[7];
	if (instance.regs->SR & USART_SR_RXNE) {
		rxb = instance.regs->DR;
		instance.callback(rxb);
	}
}


#else

void USART1_IRQHandler(void) {
	USART_device &instance = devicesStatic[0];
	if (instance.regs->ISR & USART_ISR_RXNE) {
		rxb = instance.regs->RDR;
		instance.callback(rxb);
	}
}

void USART2_IRQHandler(void) {
	USART_device &instance = devicesStatic[1];
	if (instance.regs->ISR & USART_ISR_RXNE) {
		rxb = instance.regs->RDR;
		instance.callback(rxb);
	}
}

void USART3_IRQHandler(void) {
	USART_device &instance = devicesStatic[2];
	if (instance.regs->ISR & USART_ISR_RXNE) {
		rxb = instance.regs->RDR;
		instance.callback(rxb);
	}
}

void USART4_IRQHandler(void) {
	USART_device &instance = devicesStatic[3];
	if (instance.regs->ISR & USART_ISR_RXNE) {
		rxb = instance.regs->RDR;
		instance.callback(rxb);
	}
}

void USART5_IRQHandler(void) {
	USART_device &instance = devicesStatic[4];
	if (instance.regs->ISR & USART_ISR_RXNE) {
		rxb = instance.regs->RDR;
		instance.callback(rxb);
	}
}

void USART6_IRQHandler(void) {
	USART_device &instance = devicesStatic[5];
	if (instance.regs->ISR & USART_ISR_RXNE) {
		rxb = instance.regs->RDR;
		instance.callback(rxb);
	}
}

void USART7_IRQHandler(void) {
	USART_device &instance = devicesStatic[6];
	if (instance.regs->ISR & USART_ISR_RXNE) {
		rxb = instance.regs->RDR;
		instance.callback(rxb);
	}
}

void USART8_IRQHandler(void) {
	USART_device &instance = devicesStatic[7];
	if (instance.regs->ISR & USART_ISR_RXNE) {
		rxb = instance.regs->RDR;
		instance.callback(rxb);
	}
}

#endif


// --- START UART ---
// Configures and starts the USART as a UART device.
bool USART::startUart(USART_devices device, GPIO_ports tx_port, uint8_t tx_pin, uint8_t tx_af,
											GPIO_ports rx_port, uint8_t rx_pin, uint8_t rx_af,
											uint32_t baudrate, std::function<void(char)> callback) {
	// Check input parameters.
	// If device is already active, return false.
	// Otherwise try to activate it.
	if (tx_pin > 15 || rx_pin > 15) { return false;}
	if (tx_af > 15 || rx_af > 15) { return false; }
	USART_device &instance = devicesStatic[device];
	RccPeripheral per;
	if (device == USART_1) 		{ per = RCC_USART1; }
	else if (device == USART_2) { per = RCC_USART2; }
	else if (device == USART_3) { per = RCC_USART3; }
	else if (device == USART_4) { per = RCC_USART4; }
	else if (device == USART_5) { per = RCC_USART5; }
	else if (device == USART_6) { per = RCC_USART6; }
	
	if (instance.active) { return true; }
	
	// Set TX as high speed, push-pull.
	if (!gpio.set_output_parameters(tx_port, tx_pin, GPIO_PULL_UP, GPIO_PUSH_PULL, GPIO_HIGH)) {
		Rcc::disablePort((RccPort) tx_port);
		return false;
	}
	
	// Set AF mode on the specified pins.
#ifdef __stm32f1
	// STM32F1 requires setting AF mode in the peripheral register
	// as well as setting the MODEx1 pin in the CRL or CRH
	// register, as appropriate
	if (!gpio.set_af(per, tx_af)) {
		Rcc::disablePort((RccPort) tx_port);
		Rcc::disablePort((RccPort) rx_port);
		return false;
	}
#endif
	if (!gpio.set_af(tx_port, tx_pin, tx_af)) {
		Rcc::disablePort((RccPort) tx_port);
		return false;
	}
	
	if (!gpio.set_af(rx_port, rx_pin, rx_af)) {
		Rcc::disablePort((RccPort) tx_port);
		Rcc::disablePort((RccPort) rx_port);
		return false;
	}
		
	if (!gpio.set_output_parameters(rx_port, rx_pin, GPIO_PULL_UP, GPIO_PUSH_PULL, GPIO_HIGH)) {
		Rcc::disablePort((RccPort) tx_port);
		Rcc::disablePort((RccPort) rx_port);
		return false;
	}
	
	// Set up and enable the USART peripheral.
	if (!Rcc::enable(per)) { 
		Rcc::disablePort((RccPort) tx_port);
		Rcc::disablePort((RccPort) rx_port);
		return false;
	}
	
	instance.active = true;
	
#ifndef __stm32f3
	// Configure CR1 register.
	// TODO: Enable configuring of other registers.
	instance.regs->CR1 |= (USART_CR1_RE | USART_CR1_TE);
#endif
	
	// Set the baud rate (BR register).
	// TODO: adjust for STM32F1.
	//instance.regs->BRR = SystemCoreClock / baudrate;
	//uint16_t uartdiv = SystemCoreClock / baudrate;
	
	// Retrieve the APBx clock prescaler divisor and determine the PCLKx frequency
	uint32_t tmp;
#if defined STM32F0
	tmp = APBPrescTable[((RCC->CFGR & RCC_CFGR_PPRE_Msk) >> RCC_CFGR_PPRE_Pos)];
#else
	if ((device == USART_1) || (device == USART_6)) {
		tmp = APBPrescTable[((RCC->CFGR & RCC_CFGR_PPRE2_Msk) >> RCC_CFGR_PPRE2_Pos)];
	}
	else {
		tmp = APBPrescTable[((RCC->CFGR & RCC_CFGR_PPRE1_Msk) >> RCC_CFGR_PPRE1_Pos)];
	}
#endif
	uint32_t usartClock = SystemCoreClock >> tmp;
	uint16_t uartdiv = usartClock / baudrate;
	
#if defined __stm32f0 || defined __stm32f7 || defined __stm32l4
	instance.regs->BRR = (((uartdiv / 16) << USART_BRR_DIV_MANTISSA_Pos) |
							((uartdiv % 16) << USART_BRR_DIV_FRACTION_Pos));
#elif defined __stm32f4 || defined __stm32f1
	instance.regs->BRR = (((uartdiv / 16) << USART_BRR_DIV_Mantissa_Pos) |
							((uartdiv % 16) << USART_BRR_DIV_Fraction_Pos));
#elif defined __stm32f3
	// Assuming sampling by 16.
	instance.regs->BRR = (((usartClock) + ((baudrate) / 2U)) / (baudrate));
#endif
	
	// Enable the USART via its CR1 register.
#ifndef __stm32f3
	//instance.regs->CR1 |= (USART_CR1_RE | USART_CR1_TE | USART_CR1_UE | USART_CR1_RXNEIE);
	instance.regs->CR1 |= USART_CR1_UE;
#else
	instance.regs->CR1 |= (USART_CR1_RE | USART_CR1_TE | USART_CR1_UE);
#endif
	
	// Save parameters.
	instance.tx_pin 	= tx_pin;
	instance.tx_port 	= tx_port;
	instance.tx_af 		= tx_af;
	instance.rx_pin 	= rx_pin;
	instance.rx_port 	= rx_port;
	instance.rx_af 		= rx_af;
	instance.baudrate 	= baudrate;
	instance.per		= per;
	instance.callback	= callback;
	
	// Configure interrupt.
	instance.regs->CR1 |= USART_CR1_RXNEIE;
	NVIC_SetPriority(instance.irqType, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 1));
	NVIC_EnableIRQ(instance.irqType);
	
	return true;
}

#ifdef NODATE_DMA_ENABLED
// --- CONFIGURE DMA T ---
// Configure DMA for transmitting.
bool USART::configureDMAT(USART_devices device, uint32_t* buffer, uint16_t count, DMA_callbacks cb) {
	USART_device &instance = devicesStatic[device];
	if (!instance.active) { return false; }
#if defined __stm32f0
	// Disable transmission/reception.
	instance.regs->CR1 &= ~(USART_CR1_RE | USART_CR1_TE | USART_CR1_UE | USART_CR1_RXNEIE);
	
	// Enable DMA on USART. Enable for TX.
	instance.regs->CR3 |= USART_CR3_DMAT;
	
	// Re-enable transmission/reception.
	instance.regs->CR1 |= (USART_CR1_RE | USART_CR1_TE | USART_CR1_UE | USART_CR1_RXNEIE);

	DMA_config cfg;
	cfg.source = buffer;
	cfg.target = (uint32_t*) &(instance.regs->TDR);
	cfg.prio = DMA_PRIO_MEDIUM;
	cfg.count = count;
	cfg.src_size = 1;
	cfg.des_size = 1;
	cfg.circular = false;
	cfg.src_incr = true;
	cfg.des_incr = false;
	if (device == USART_1) {
		cfg.channel = 2;
		DMA::configureChannel(DMA_1, cfg, cb);
	}
	else if (device == USART_2) {
		cfg.channel = 4;
		DMA::configureChannel(DMA_1, cfg, cb);
	}
	else {
		return false; // TODO: define other USARTs.
	}
	
	DMA::start(DMA_1);
	return true;
#else
	
	return false;
#endif
}


// --- CONFIGURE DMA R ---
// Configure DMA for reception.
bool USART::configureDMAR(USART_devices device, uint32_t* buffer, uint16_t count, DMA_callbacks cb) {
	USART_device &instance = devicesStatic[device];
	if (!instance.active) { return false; }
#if defined __stm32f0
	// Disable transmission/reception.
	instance.regs->CR1 &= ~(USART_CR1_RE | USART_CR1_TE | USART_CR1_UE | USART_CR1_RXNEIE);
	
	// Enable DMA on USART. Enable for RX.
	instance.regs->CR3 |= USART_CR3_DMAR;
	
	// Re-enable transmission/reception.
	instance.regs->CR1 |= (USART_CR1_RE | USART_CR1_TE | USART_CR1_UE | USART_CR1_RXNEIE);
	
	DMA_config cfg;
	cfg.source = (uint32_t*) &(instance.regs->RDR);
	cfg.target = buffer;
	cfg.prio = DMA_PRIO_MEDIUM;
	cfg.count = count;
	cfg.src_size = 1;
	cfg.des_size = 1;
	cfg.circular = false;
	cfg.src_incr = false;
	cfg.des_incr = true;
	if (device == USART_1) {
		cfg.channel = 3;
		DMA::configureChannel(DMA_1, cfg, cb);
	}
	else if (device == USART_2) {
		cfg.channel = 5;
		DMA::configureChannel(DMA_1, cfg, cb);
	}
	else {
		return false; // TODO: define other USARTS.
	}
	
	DMA::start(DMA_1);
	return true;
#else
	
	return false;
#endif
}
#endif


// --- SEND UART ---
bool USART::sendUart(USART_devices device, char &ch) {
	USART_device &instance = devicesStatic[device];
	if (!instance.active) { return false; }
	
	// Copy bit to the device's transmission register.
#if defined __stm32f0 || defined __stm32f3 || defined __stm32f7 || defined __stm32l4
	while (!(instance.regs->ISR & USART_ISR_TXE)) {}; // TODO: add timeout.
	instance.regs->TDR = (uint8_t) ch;
#elif defined __stm32f4 || defined __stm32f1
	while (!(instance.regs->SR & USART_SR_TXE)) {}; // TODO: add timeout.
	instance.regs->DR = (uint8_t) ch;
#else
	return false;
#endif
	
	return true;
}


// --- STOP UART ---
bool USART::stopUart(USART_devices device) {
	USART_device &instance = devicesStatic[device];
	if (!instance.active) { return false; }
	
	// Disable interrupt.
	instance.regs->CR1 &= ~USART_CR1_RXNEIE;
	NVIC_DisableIRQ(instance.irqType);
	
	// Disable USART & ativated ports.
	instance.regs->CR1 &= ~(USART_CR1_RE | USART_CR1_TE | USART_CR1_UE | USART_CR1_RXNEIE);
	if (!Rcc::disable(instance.per)) { return false; }
	if (!Rcc::disablePort((RccPort) instance.tx_port)) { return false; }
	if (!Rcc::disablePort((RccPort) instance.rx_port)) { return false; }
	
	return true;
}


#endif
