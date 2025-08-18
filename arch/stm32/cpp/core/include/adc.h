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


typedef void (*ADC_cb)();


struct ADC_interrupts {
	ADC_cb watchdog = 0;	// Analogue watchdog
	ADC_cb overrun = 0;		// Overrun event.
	ADC_cb eoseq = 0;		// End of conversion sequence.
	ADC_cb eoc = 0;			// End of conversion.
	ADC_cb eosmp = 0;		// End of sampling.
	ADC_cb ready = 0;		// ADC ready.
};


struct ADC_device {
	bool active = false;
	bool sampling = false;
	bool calibrated = false;
	ADC_TypeDef* regs;
	RccPeripheral per;
	IRQn_Type irqType;
	uint8_t conversions = 0;
	//std::function<void(uint8_t)> callback;
	ADC_interrupts cbs;
};


class ADC {
	static bool calibrate(ADC_devices device);
#ifndef STM32F1
	static ADC_Common_TypeDef* common;
#endif
	
public:
	static bool configure(ADC_devices device, ADC_modes mode);
	static bool channel(ADC_devices device, uint8_t channel, GPIO_ports port, uint8_t pin, uint8_t time = 0);
	static bool channel(ADC_devices device, ADC_internal channel, uint8_t time = 0);
	static bool finishChannelConfig(ADC_devices device);
	static bool enableInterrupt(ADC_devices device, ADC_interrupts isr);
	static bool disableInterrupts(ADC_devices device);
#ifdef NODATE_DMA_ENABLED
	static bool configureDMA(ADC_devices device, uint32_t* buffer, uint16_t count, DMA_callbacks cb);
	static bool stopDMA(ADC_devices device);
#endif
	static bool start(ADC_devices device);
	static bool startSampling(ADC_devices device);
	static bool getValue(ADC_devices device, uint16_t &val);
	static bool stop(ADC_devices device);
};


#endif
