/*
	dma.h - Header file for the DMA module.
	
	2021/04/26, Maya Posch
*/


#ifndef NODATE_DMA_H
#define NODATE_DMA_H


#include <common.h>


enum DMA_devices {
	DMA_1,
	DMA_2
};


struct DMA_channel {
	DMA_Channel_TypeDef* regs;
	IRQn_Type irqType;
};


struct DMA_device {
	bool active = false;
	DMA_TypeDef* regs;
	RccPeripheral per;
#ifdef __stm32f0
	DMA_channel channels[7];
#endif
};


class DMA {
	//
	
public:
	static bool start(DMA_devices device);
	static bool configureChannel(DMA_devices device, uint8_t channel, uint32_t source, 
									uint32_t target, uint16_t count);
};


#endif
