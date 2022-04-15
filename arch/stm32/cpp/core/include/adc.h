/*
	adc.h - Header file for the ADC module.
	
	2021/04/26, Maya Posch
*/


#ifndef NODATE_ADC_H
#define NODATE_ADC_H

#include <common.h>
#include <nodate.h>

#include <functional>

// The ADC preprocessor definition from CMSIS exists for legacy purposes. Here we undefine it
// if it's defined so that we can reuse it.
#ifdef ADC
#undef ADC
#endif


enum ADC_devices {
	ADC_1,
	ADC_2,
	ADC_3
};


enum ADC_channels {
	ADC_CHANNEL_EXTERNAL,
	ADC_CHANNEL_VREF,
	ADC_CHANNEL_VBAT,
	ADC_CHANNEL_TEMP
};


enum ADC_modes {
	ADC_MODE_SINGLE,
	ADC_MODE_CONTINUOUS
};


enum ADC_internal {
	ADC_VSENSE,
	ADC_VREFINT,
	ADC_VBAT
};


struct ADC_channel {
	//
};
	


struct ADC_device {
	bool active = false;
	bool sampling = false;
	bool calibrated = false;
	ADC_TypeDef* regs;
	RccPeripheral per;
	IRQn_Type irqType;
	std::function<void(uint8_t)> callback;
};


class ADC {
	static bool calibrate(ADC_devices device);
	
public:
	static bool configure(ADC_devices device, ADC_modes mode);
	static bool channel(ADC_devices device, uint8_t channel, GPIO_ports port, uint8_t pin, uint8_t time = 0);
	static bool channel(ADC_devices device, ADC_internal channel, uint8_t time = 0);
	static bool enableInterrupt(ADC_devices device, bool enable = true);
#ifdef NODATE_DMA_ENABLED
	static bool configureDMA(ADC_devices device, uint32_t* buffer, uint16_t count, DMA_callbacks cb);
#endif
	static bool start(ADC_devices device);
	static bool stop(ADC_devices device);
};


#endif
