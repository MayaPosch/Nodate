/*
	spi.h - Header for SPI/I2S module.
	
*/


#ifndef SPI_H
#define SPI_H

#include <common.h>
#include <nodate.h>

#include <functional>


enum SPI_devices {
	SPI_1,
	SPI_2,
	SPI_3,
	SPI_4,
	SPI_5
};


struct SPI_pins {
	GpioPinDef miso;
	GpioPinDef mosi;
	GpioPinDef sclk;
	GpioPinDef nss;
};


struct I2S_pins {
	GpioPinDef sd;
	GpioPinDef ws;
	GpioPinDef ck;
	GpioPinDef mck;
};


struct SPI_device {
	bool active = false;
	bool master = false;
	bool i2s	= false;
	SPI_TypeDef* regs;
	RccPeripheral per;
	IRQn_Type irqType;
	std::function<void(uint8_t)> callback;
};


class SPI {
	//
	
public:
	static bool startSPIMaster(SPI_devices device, SPI_pins pins);
	static bool startI2SMaster(SPI_devices device, I2S_pins pins);
	static bool startSPISlave(SPI_devices device, SPI_pins pins);
	static bool startI2SSlave(SPI_devices device, I2S_pins pins);
	//static bool startMaster(I2C_devices device, I2C_modes mode, 
		//									std::function<void(uint8_t)> callback);
	//static bool setSlaveTarget(I2C_devices device, uint8_t slave);
	//static bool startSlave(I2C_devices device, uint8_t address);
	static bool sendData(SPI_devices device, uint8_t* data, uint16_t len);
	static bool receiveData(SPI_devices device, uint8_t* data, uint16_t count);
	static bool transceiveData(SPI_devices device, uint8_t* txdata, uint16_t txcount,
													uint8_t* rxdata, uint16_t rxcount);
	//static bool sendToSlaveBegin(I2C_devices device, uint8_t len);
	//static bool sendToSlaveByte(I2C_devices device, uint8_t data);
	//static bool sendToSlaveBytes(I2C_devices device, uint8_t* data, uint8_t len);
	//static bool sendToSlaveEnd(I2C_devices device);
	//static bool sendToMaster(I2C_devices device, uint8_t* data, uint8_t len);
	//static bool receiveFromSlave(I2C_devices device, uint32_t count, uint8_t* buffer);
    //static bool receiveFromSlave(I2C_devices device, uint8_t len);
	//static bool receiveFromMaster(I2C_devices device, uint32_t count, uint8_t* buffer);
	static bool stop(SPI_devices device);
};

#endif
