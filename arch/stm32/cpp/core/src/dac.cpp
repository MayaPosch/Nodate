/*
	dac.cpp - Implementation file for the SPI class.
*/


#include <dac.h>


#ifdef NODATE_DAC_ENABLED


const int dac_count = 3;

// --- SPI DEVICES ---
SPI_device* SPI_list() {
	SPI_device item;
	static SPI_device dac_devices[dac_count];
	for (int i = 0; i < dac_count; ++i) {
		dac_devices[i] = item;
	}
	
#ifdef RCC_APB1ENR_DAC1EN
	dac_devices[DAC_1].regs = DAC1;
	//dac_devices[DAC_1].irqType = DAC1_IRQn;
#endif

#ifdef RCC_APB1ENR_DAC2EN
	dac_devices[DAC_2].regs = DAC2;
	//dac_devices[DAC_2].irqType = DAC2_IRQn;
#endif

#ifdef RCC_APB1ENR_DAC3EN
	dac_devices[DAC_3].regs = DAC3;
	//dac_devices[DAC_3].irqType = DAC3_IRQn;
#endif
	
	return dac_devices;
}


DAC_device* dacList = DAC_list();


// --- START ---
bool DAC::start(DAC_devices device, DAC_channel ch, DAC_ch_cfg ch_cfg) {
	DAC_device &instance = dacList[device];
	
	// Check status. Set parameters.
	// TODO: set active status per channel.
	if (instance.active) { return true; } // Already active.
	if (device == DAC_1) 		{ instance.per = RCC_DAC1; }
	else if (device == DAC_2)	{ instance.per = RCC_DAC2; }
	//else if (device == DAC_3)	{ instance.per = RCC_DAC3; }
	
	// Enable the peripheral clock.
	// Start DAC device if needed.
	if (!instance.active) {
		if (!Rcc::enable(instance.per)) {
			// TODO: set status.
			return false;
		}
	}
	
#ifdef STM32F3
	// Channel should be inactive at this point so that it can be configured.
	// TODO: allow configuration of a second channel (if present) and channel bonding.
	uint32_t creg = 0;
	if (ch_cfg.triggerSource == DAC_TRIG_SOFTWARE) 		{ creg |= 7 << DAC_CR_TSEL1; }
	else if (ch_cfg.triggerSource == DAC_TRIG_TIMER) 	{ 
		creg |= ch_cfg.trigger << DAC_CR_TSEL1;
	}
	else if (ch_cfg.triggerSource == DAC_TRIG_EXT) {
		creg |= ch_cfg.trigger << DAC_CR_TSEL1;
	}
	
	if (!ch_cfg.waveGen) {
		// DAC_WAVEx: leave at default 0x00 to disable this feature.
		
		// On F334 DAC1 CR[1] is BOFF1, on DAC2 it is OUTEN1.
		// For channel 2 it is always OUTEN2.
		// Leave at the default 0 to enable output buffering on DAC1_CH1.
		
	}
	else {
		// Set wave type.
		if (ch_cfg.waveGenCfg == DAC_WAVE_NOISE) 			{ creg |= 1 << DAC_CR_WAVE1; }
		else if (ch_cfg.waveGenCfg == DAC_WAVE_TRIANGLE) 	{ creg |= 2 << DAC_CR_WAVE1; }
		
		// TODO: Allow configuring of DAC_MAMP1.
		// Leaving on b0000 for unmask bit 0 default (amplitude == 1).
	}
	
	// Enable the channel.
	creg |= DAC_CR_EN1;
	
	instance.regs->CR = creg;
	
	
	instance.active = true;
	
#elif defined STM32F4
	//
	
#endif
	
	return false;
}


// --- WRITE ---
bool DAC::write(DAC_devices device, uint16_t data) {
	DAC_device &instance = dacList[device];
	
	// Check status. Set parameters.
	// TODO: set active status per channel.
	if (!instance.active) { return false; } // Unconfigured DAC.
	
#ifdef STM32F3
	// Write the provided data as right-aligned 12-bit data (DAC_DRH12R1).
	instance.regs->DRH12R1 = data;
	
	return true;
#endif
	
	return false;
}


#endif