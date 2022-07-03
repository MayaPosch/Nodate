/*
	dma.h - Header file for the DMA module.
	
	2021/04/26, Maya Posch
*/


#ifndef NODATE_DMA_H
#define NODATE_DMA_H


#include <common.h>
#include <rcc.h>


enum DMA_devices {
	DMA_1,
	DMA_2
};


enum DMA_priority {
	DMA_PRIO_LOW = 0,
	DMA_PRIO_MEDIUM,
	DMA_PRIO_HIGH,
	DMA_PRIO_VERY_HIGH
};


struct DMA_config {
	uint8_t channel;
	uint32_t* source;
	uint32_t* target;
	DMA_priority prio;	// Channel priority.
	uint16_t count;		// Number of elements to transfer.
	uint8_t src_size;	// Single source element size in bytes.
	uint8_t des_size;	// Single destination element size in bytes.
	bool circular;		// Enable circular mode.
	bool src_incr;		// Source pointer increment.
	bool des_incr;		// Destination pointer increment.
};


typedef void (*DMA_cb)();


struct DMA_callbacks {
	DMA_cb half = 0;
	DMA_cb filled = 0;
	DMA_cb error = 0;
};


struct DMA_channel {
#ifdef __stm32f4
	DMA_Stream_TypeDef* regs;
#else
	DMA_Channel_TypeDef* regs;
#endif
	IRQn_Type irqType;
	DMA_config config;
	DMA_callbacks cb;
	bool active = false;
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
	static bool configureChannel(DMA_devices device, DMA_config config, DMA_callbacks cb);
	static bool abort(DMA_devices device, uint8_t channel);
};


#endif
