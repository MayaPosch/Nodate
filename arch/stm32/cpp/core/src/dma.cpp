/*
	dma.cpp - Implementation of the DMA module.
	
	2021/04/26, Maya Posch
*/


#ifdef NODATE_DMA_ENABLED

const int dma_count = 2;

// --- DMA DEVICES ---
DMA_device* DMA_list() {
	DMA_device item;
	static DMA_device dma_devices[dma_count];
	for (int i = 0; i < dma_count; ++i) {
		dma_devices[i] = item;
	}
	
#ifdef RCC_APB2ENR_ADC1EN
	dma_devices[DMA_1].regs = DMA1;
#if defined __stm32f4 || defined __stm32f1 || defined __stm32f7
	dma_devices[DMA_1].irqType = ADC_IRQn;
#else
	dma_devices[DMA_1].irqType = ;
#ifdef __stm32f0
	dma_devices[DMA_1].channels[0].regs = DMA1_Channel1;
	dma_devices[DMA_1].channels[0].irqType = DMA1_Channel1_IRQn;
	dma_devices[DMA_1].channels[1].regs = DMA1_Channel2;
	dma_devices[DMA_1].channels[1].irqType = DMA1_Channel2_3_IRQn;
	dma_devices[DMA_1].channels[2].regs = DMA1_Channel3;
	dma_devices[DMA_1].channels[2].irqType = DMA1_Channel2_3_IRQn;
	dma_devices[DMA_1].channels[3].regs = DMA1_Channel4;
	dma_devices[DMA_1].channels[3].irqType = DMA1_Channel4_5_IRQn;
	dma_devices[DMA_1].channels[4].regs = DMA1_Channel5;
	dma_devices[DMA_1].channels[4].irqType = DMA1_Channel4_5_IRQn;
	/* dma_devices[DMA_1].channels[5].regs = DMA1_Channel6; // For F07x+ devices.
	dma_devices[DMA_1].channels[5].irqType = DMA1_Channel4_5_IRQn;
	dma_devices[DMA_1].channels[6].regs = DMA1_Channel7;
	dma_devices[DMA_1].channels[6].irqType = DMA1_Channel4_5_IRQn; */
#endif
#endif
#endif

#ifdef RCC_APB2ENR_ADC2EN
	dma_devices[DMA_2].regs = ADC2;
#if defined __stm32f4 || defined __stm32f1 || defined __stm32f7
	dma_devices[DMA_2].irqType = ADC_IRQn;
#else
	dma_devices[DMA_2].irqType = ADC2_IRQn;
#endif
#endif
	
	return dma_devices;
}

DMA_device* dmaList = DMA_list();


// --- ISRs ---
#ifdef __stm32f0
extern "C" {
	void DMA1_Channel1_IRQn(void);
	void DMA1_Channel2_3_IRQn(void);
	void DMA1_Channel4_5_IRQn(void);
}


void DMA1_Channel1_IRQn(void) {
	DMA_device &instance = dmaList[0];
	DMA_channel &ch = instance.channels[0];
	
	// Check for flag states. Handle callbacks.
	if (instance.regs->ISR & DMA_ISR_HTIF1) {	// half-transfer interrupt.
        instance.regs->IFCR |= DMA_IFCR_CHTIF1;
		ch.cb.half();
	}
	else if (instance.regs->ISR & DMA_ISR_TCIF1) { // transfer complete.
		instance.regs->IFCR |= DMA_IFCR_CTCIF1;
		ch.cb.filled();
	}
	else if (instance.regs->ISR & DMA_ISR TEIF1) { // transfer error.
		instance.regs->IFCR |= DMA_IFCR_CTEIF1;
		ch.cb.error();
	}
}


void DMA1_Channel2_3_IRQn(void) {
	// Determine the channel with the active ISR.
	DMA_device &instance = dmaList[0];
	if (instance.regs->ISR & DMA_ISR_HTIF2) {	// half-transfer interrupt.
        instance.regs->IFCR |= DMA_IFCR_CHTIF2;
		DMA_channel &ch = instance.channels[1];
		ch.cb.half();
	}
	else if (instance.regs->ISR & DMA_ISR_TCIF2) { // transfer complete.
		instance.regs->IFCR |= DMA_IFCR_CTCIF2;
		DMA_channel &ch = instance.channels[1];
		ch.cb.filled();
	}
	else if (instance.regs->ISR & DMA_ISR TEIF2) { // transfer error.
		instance.regs->IFCR |= DMA_IFCR_CTEIF2;
		DMA_channel &ch = instance.channels[1];
		ch.cb.error();
	}
	
	if (instance.regs->ISR & DMA_ISR_HTIF3) {	// half-transfer interrupt.
        instance.regs->IFCR |= DMA_IFCR_CHTIF3;
		DMA_channel &ch = instance.channels[2];
		ch.cb.half();
	}
	else if (instance.regs->ISR & DMA_ISR_TCIF3) { // transfer complete.
		instance.regs->IFCR |= DMA_IFCR_CTCIF3;
		DMA_channel &ch = instance.channels[2];
		ch.cb.filled();
	}
	else if (instance.regs->ISR & DMA_ISR TEIF3) { // transfer error.
		instance.regs->IFCR |= DMA_IFCR_CTEIF3;
		DMA_channel &ch = instance.channels[2];
		ch.cb.error();
	}
}


void DMA1_Channel4_5_IRQn(void) {
	// Determine the channel with the active ISR.
	DMA_device &instance = dmaList[0];
	if (instance.regs->ISR & DMA_ISR_HTIF4) {	// half-transfer interrupt.
        instance.regs->IFCR |= DMA_IFCR_CHTIF4;
		DMA_channel &ch = instance.channels[3];
		ch.cb.half();
	}
	else if (instance.regs->ISR & DMA_ISR_TCIF4) { // transfer complete.
		instance.regs->IFCR |= DMA_IFCR_CTCIF4;
		DMA_channel &ch = instance.channels[3];
		ch.cb.filled();
	}
	else if (instance.regs->ISR & DMA_ISR TEIF4) { // transfer error.
		instance.regs->IFCR |= DMA_IFCR_CTEIF4;
		DMA_channel &ch = instance.channels[3];
		ch.cb.error();
	}
	
	if (instance.regs->ISR & DMA_ISR_HTIF5) {	// half-transfer interrupt.
        instance.regs->IFCR |= DMA_IFCR_CHTIF5;
		DMA_channel &ch = instance.channels[4];
		ch.cb.half();
	}
	else if (instance.regs->ISR & DMA_ISR_TCIF5) { // transfer complete.
		instance.regs->IFCR |= DMA_IFCR_CTCIF5;
		DMA_channel &ch = instance.channels[4];
		ch.cb.filled();
	}
	else if (instance.regs->ISR & DMA_ISR TEIF5) { // transfer error.
		instance.regs->IFCR |= DMA_IFCR_CTEIF5;
		DMA_channel &ch = instance.channels[4];
		ch.cb.error();
	}
}
#endif


// --- START ---
bool DMA::start(DMA_devices device) {
	DMA_device &instance = dmaList[device];
#ifdef __stm32f0
	// Check status. Set parameters.
	if (instance.active) { return true; } // Already active.
	if (device == DMA_1) 		{ instance.per = RCC_DMA1; }
	else if (device == DMA_2)	{ instance.per = RCC_DMA2; }
	
	// Start device if needed.
	if (!instance.active) {
		if (!Rcc::enable(instance.per)) {
			// TODO: set status.
			return false;
		}
	}
  
	instance.active = true;
	
	return true;
#else
	return false;
#endif
}
	

// --- CONFIGURE CHANNEL ---
bool DMA::configureChannel(DMA_devices device, DMA_config config, DMA_callbacks cb) {
	DMA_device &instance = dmaList[device];
#ifdef __stm32f0
	// No more than 7 channels support on DMA 1, and 5 on F042.
	// TODO: per-MCU variation check.
	if (config.channel > 7) { return false; }
	
	DMA_channel &ch = instance.channels[config.channel - 1];
	
	// Set the target peripheral data register address.
	// Set the target memory address.
	// Set the number of transfers per cycle.
	ch.regs->CPAR = config.source;
	ch.regs->CMAR = config.target;
	ch.regs->CNDTR = config.count;
	
	// Configure increment, size, priority, interrupts and circular mode.
	uint32_t ccr_reg = 0;
	if (cfg.prio != DMA_PRIO_LOW) { ccr_reg |= ((uint8_t) cfg.prio) << DMA_CCR_PL_Pos; }
	if (config.src_incr) { ccr_reg |= DMA_CCR_MINC; }
	if (config.des_incr) { ccr_reg |= DMA_CCR_PINC; }
	if (config.circular) { ccr_reg |= DMA_CCR_CIRC; }
	if (config.src_size > 3 || config.des_size > 3) { return false; }
	if (config.src_size > 1) { ccr_reg |= ((config.src_size - 1) << DMA_CCR_MSIZE_Pos; }
	if (config.des_size > 1) { ccr_reg |= ((config.des_size - 1) << DMA_CCR_PSIZE_Pos; }
	if (cb.half) 	{ ccr_reg |= DMA_CCR_HTIE; }
	if (cb.filled) 	{ ccr_reg |= DMA_CCR_TCIE; }
	if (cb.error)	{ ccr_reg |= DMA_CCR_TEIE; }
	
	// Copy to channel register.
	ch.regs->CCR = ccr_reg;
	
	// Save configuration & callbacks.
	ch.config = config;
	ch.cb = cb;

	// Enable channel.
	ch.regs->CCR |= DMA_CCR_EN;
 
	// Configure NVIC for DMA.
	NVIC_EnableIRQ(ch.irqType);
	NVIC_SetPriority(ch.irqType, 0);
	
	return true;
#else
	return false;
#endif
}

#endif
