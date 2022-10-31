/*
	adc.h - Header file for the ADC module.
	
	2021/04/26, Maya Posch
*/


#ifndef NODATE_ADC_H
#define NODATE_ADC_H

#include <common.h>
#include <nodate.h>

#include <functional>

// The DAC preprocessor definition from CMSIS exists for legacy purposes. Here we undefine it
// if it's defined so that we can reuse it.
#ifdef DAC
#undef DAC
#endif


enum DAC_devices {
	DAC_1,
	DAC_2,
	DAC_3
};


enum DAC_channel {
	DAC_CH_1,
	DAC_CH_2
};


enum DAC_trigger {
	DAC_TRIG_SOFTWARE,
	DAC_TRIG_TIMER,
	DAC_TRIG_EXT
};


enum DAC_wave {
	DAC_WAVE_NOISE,
	DAC_WAVE_TRIANGLE
};


struct DAC_ch_cfg {
	DAC_trigger	triggerSource = DAC_TRIG_SOFTWARE;
	uint32_t 	trigger;	// Set if EXT or TIMER
	bool 		waveGen = false;
	DAC_wave 	waveGenCfg = DAC_WAVE_NOISE;
	uint32_t 	outputBuffer;
	GpioPinDef	pin;
};


struct DAC_device {
	bool active = false;
	bool ch1_active = false;
	bool ch2_active = false;
	SPI_TypeDef* regs;
	RccPeripheral per;
	//IRQn_Type irqType;
	//std::function<void(uint8_t)> callback;
};


class DAC {
	//
	
public:
	bool start(DAC_devices device, DAC_channel ch, DAC_ch_cfg ch_cfg);
	bool write(DAC_devices device, uint16_t data);
};

#endif
