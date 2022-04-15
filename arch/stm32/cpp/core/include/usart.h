/*
	usart.h - Header to provide access to USART functionality.
	
*/


#ifndef USART_H
#define USART_H


#include <common.h>
#include <gpio.h>
#include <rcc.h>

#include <functional>


enum USART_devices {
	USART_1,
	USART_2,
	USART_3,
	USART_4,
	USART_5,
	USART_6,
	USART_7,
	USART_8
};


struct USART_device {
	bool active = false;
	USART_TypeDef* regs;
	GPIO_ports tx_port;
	uint8_t tx_pin;
	uint8_t tx_af;
	GPIO_ports rx_port;
	uint8_t rx_pin;
	uint8_t rx_af;
	uint32_t baudrate;
	RccPeripheral per;
	IRQn_Type irqType;
	std::function<void(char)> callback;
};


struct USART_def {
	USART_devices usart;
	uint8_t configs;
	GpioPinDef* tx;
	GpioPinDef* rx;
};


class USART {
	static GPIO gpio;
	
public:
	static bool startUart(USART_devices device, GPIO_ports tx_port, uint8_t tx_pin, uint8_t tx_af,
											GPIO_ports rx_port, uint8_t rx_pin, uint8_t rx_af,
											uint32_t baudrate, std::function<void(char)> callback);
#ifdef NODATE_DMA_ENABLED
	static bool configureDMAT(USART_devices device, uint32_t* buffer, uint16_t count);
	static bool configureDMAR(USART_devices device, uint32_t* buffer, uint16_t count);
#endif
	static bool sendUart(USART_devices device, char &ch);
	static bool stopUart(USART_devices device);
};

#endif
