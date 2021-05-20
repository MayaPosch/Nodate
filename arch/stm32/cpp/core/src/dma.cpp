/*
	dma.cpp - Implementation of the DMA module.
	
	20201/04/26, Maya Posch
*/


#ifdef NODATE_DMA_ENABLED

const int dma_count = 2;

// --- ADC DEVICES ---
DMA_device* DMA_list() {
	DMA_device item;
	static DMA_device dma_devices[dma_count];
	for (int i = 0; i < dma_count; ++i) {
		dma_devices[i] = item;
	}
	
#ifdef RCC_APB2ENR_ADC1EN
	dma_devices[DMA_1].regs = ADC1;
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
// TODO: make further modes configurable.
bool DMA::configureChannel(DMA_devices device, uint8_t channel, uint32_t source, uint32_t target,
							uint16_t count) {
	DMA_device &instance = dmaList[device];
#ifdef __stm32f0
	// No more than 7 channels support on DMA 1, and 5 on F042.
	// TODO: per-MCU variation check.
	if (channel > 7) { return false; }
	
	DMA_channel &ch = instance.channels[channel];
	
	// Set the target peripheral data register address.
	// Set the target memory address.
	// Set the number of transfers per cycle.
	ch.regs->CPAR = source;
	ch.regs->CMAR = target;
	ch.regs->CNDTR = count;
	
	// Configure increment, size, interrupts and circular mode.
	ch.regs->CCR |= DMA_CCR_MINC | DMA_CCR_MSIZE_0 | DMA_CCR_PSIZE_0 \
                      | DMA_CCR_TEIE | DMA_CCR_CIRC;

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
