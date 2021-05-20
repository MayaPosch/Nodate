/*
	adc.cpp - Implementation of the ADC module.
	
	20201/04/26, Maya Posch
*/


#ifdef NODATE_ADC_ENABLED

const int adc_count = 3;

// --- ADC DEVICES ---
ADC_device* ADC_list() {
	ADC_device item;
	static ADC_device adc_devices[adc_count];
	for (int i = 0; i < adc_count; ++i) {
		adc_devices[i] = item;
	}
	
#ifdef RCC_APB2ENR_ADC1EN
	adc_devices[ADC_1].regs = ADC1;
#if defined __stm32f4 || defined __stm32f1 || defined __stm32f7
	adc_devices[ADC_1].irqType = ADC_IRQn;
#else
	adc_devices[ADC_1].irqType = ADC1_IRQn;
#endif
#endif

#ifdef RCC_APB2ENR_ADC2EN
	adc_devices[ADC_2].regs = ADC2;
#if defined __stm32f4 || defined __stm32f1 || defined __stm32f7
	adc_devices[ADC_2].irqType = ADC_IRQn;
#else
	adc_devices[ADC_2].irqType = ADC2_IRQn;
#endif
#endif

#ifdef RCC_APB2ENR_ADC3EN
	adc_devices[ADC_3].regs = ADC3;
#if defined __stm32f4 || defined __stm32f1 || defined __stm32f7
	adc_devices[ADC_3].irqType = ADC_IRQn;
#else
	adc_devices[ADC_3].irqType = ADC3_IRQn;
#endif
#endif
	
	return adc_devices;
}

ADC_device* adcList = ADC_list();


bool ADC::calibrate(ADC_devices device) {
	ADC_device &instance = adcList[device];
#ifdef __stm32f0
	// Ensure that the ADC is disabled.
	if ((instance.regs->CR & ADC_CR_ADEN) != 0) {
		instance.regs->CR &= (uint32_t)(~ADC_CR_ADEN);
	}
	
	// Enable ADCAL to start the calibration.
	// The hardware will toggle the bit to off once it is complete.
	instance.regs->CR |= ADC_CR_ADCAL;
	while ((instance.regs->CR & ADC_CR_ADCAL) != 0) {
		/* For robust implementation, add here time-out management */
	}
	
	__NOP();__NOP();   // 2 NOPs ensure 2 ADC Cycles before setting ADEN bit
						
	instance.calibrated = true;
	
	return true;
#else
	return false;
#endif
}


// --- CONFIGURE ---
// Perform basic setup on an ADC device.
bool ADC::configure(ADC_devices device, ADC_modes mode) {
	ADC_device &instance = adcList[device];
	if (instance.active) { return true; } // Already active.
	if (!instance.calibrated) { calibrate(); }
	
#ifdef __stm32f0
	// Check status. Set parameters.
	if (device == ADC_1) 		{ instance.per = RCC_ADC1; }
	else if (device == ADC_2)	{ instance.per = RCC_ADC2; }
	else if (device == ADC_3)	{ instance.per = RCC_ADC3; }
	
	// Start ADC device if needed.
	if (!instance.active) {
		if (!Rcc::enable(instance.per)) {
			// TODO: set status.
			return false;
		}
	}
	
	// Select PCLK/2 by writing 01 in CKMODE.
	instance.regs->CFGR2 |= ADC_CFGR2_CKMODE_0;
	
	// Select the continuous or single mode.
	if (mode == ADC_MODE_SINGLE) {
		instance.regs->CFGR1 &= ~ADC_CFGR1_CONT;
	}
	else {
		instance.regs->CFGR1 |= ADC_CFGR1_CONT;
	}
	
	instance.active = true;
	
	return true;
#else
	return false;
#endif
}


// --- CHANNEL ---
// Configure a specific channel.
bool ADC::channel(ADC_devices device, uint8_t channel, GPIO_ports port, uint8_t pin, uint8_t time) {
	ADC_device &instance = adcList[device];
	if (instance.sampling) { return false; } // Can't change channels while sampling.
	
#ifdef __stm32f0
	if (pin > 18) { return false; } // Only 19 channels available.
	
	// Set the target pin to analogue mode.
	GPIO::set_analog(device, port, pin);
	
	// Select the channel as active.
	instance.regs->CHSELR |= (1 << pin);
	
	// Set the sampling time. On F0 this is the same for all channels.
	if (time > 7) { return false; } // three bits value.
	instance.regs->SMPR = time;
	
	return true;
#else
	return false;
#endif
}


// --- ENABLE INTERRUPT ---
//
bool ADC::enableInterrupt(ADC_devices device, bool enable) {
	ADC_device &instance = adcList[device];
	if (instance.sampling) { return false; } // Can't change channels while sampling.
	
#ifdef __stm32f0
	if (enable) {
		// Enable interrupt on overrrun
		instance.regs->IER |= ADC_IER_OVRIE;

		// Configure NVIC for ADC:
		// - Enable Interrupt.
		// - Set priority.
		NVIC_EnableIRQ(instance.irqType);
		NVIC_SetPriority(instance.irqType, 0);
	}
	else {
		NVIC_DisableIRQ(instance.irqType);
		instance.regs->IER &= ~ADC_IER_OVRIE;
	}
	
	return true;
#else
	return false;
#endif
}
	

// --- START ---
// Start the ADC device.
bool ADC::start(ADC_devices device) {
	ADC_device &instance = adcList[device];
	if (!instance.active) { return false; }
	if (!instance.calibrated) { return false; }
	
#ifdef __stm32f0
	instance.regs->CR |= ADC_CR_ADEN;
	while ((instance.regs->ISR & ADC_ISR_ADRDY) == 0) {
		// TODO: handle timeout.
	}
	
	// Start sampling.
	instance.regs->CR |= ADC_CR_ADSTART;
	
	return true;
#else
	return false;
#endif
}


// --- STOP ---
// Stop the ADC device.
bool ADC::stop(ADC_devices device) {
	ADC_device &instance = adcList[device];
	if (!instance.active) { return false; }
	if (!instance.calibrated) { return false; }
	
#ifdef __stm32f0
	instance.regs->CR |= ADC_CR_ADSTP;
	instance.regs->CR |= ADC_CR_ADDIS;
	
	return true;
#else
	return false;
#endif
}


// ---
bool configureDMA(ADC_devices device, uint16_t buffer[], uint16_t count) {
	ADC_device &instance = adcList[device];
	if (!instance.active) { return false; }
	if (!instance.calibrated) { return false; }
	
#ifdef __stm32f0
	// Enable DMA transfer on ADC and circular mode.
	instance.regs->CFGR1 |= ADC_CFGR1_DMAEN | ADC_CFGR1_DMACFG;
	
	DMA::start(DMA_1);
	DMA::configureChannel(DMA_1, 1, &(instance.regs->DR), &buffer, count);
	
	return true;
#else
	return false;
#endif
}


#endif
