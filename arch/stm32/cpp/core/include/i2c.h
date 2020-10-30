/*
	i2c.h - Header for I2C module.
	
*/


#ifndef I2C_H
#define I2C_H

#include <common.h>
#include <gpio.h>
#include <rcc.h>


enum I2C_devices {
	I2C_1,
	I2C_2
};


enum I2C_modes {
	I2C_MODE_SM10 = 0,
	I2C_MODE_SM100,
	I2C_MODE_FM,
	I2C_MODE_FMP
};


struct I2C_device {
	bool active = false;
	bool master = false;
	uint8_t slaveTarget;
	I2C_TypeDef* regs;
	RccPeripheral per;
	IRQn_Type irqType;
};


class I2C {
	//
	
public:
	static bool startI2C(I2C_devices device, GPIO_ports scl_port, uint8_t scl_pin, uint8_t scl_af,
											GPIO_ports sda_port, uint8_t sda_pin, uint8_t sda_af);
	static bool startMaster(I2C_devices device, I2C_modes mode);
	static bool setSlaveTarget(I2C_devices device, uint8_t slave);
	static bool startSlave(I2C_devices device, uint8_t address);
	static bool sendToSlave(I2C_devices device, uint8_t* data, uint8_t len);
	static bool sendToMaster(I2C_devices device, uint8_t* data, uint8_t len);
	static bool receiveFromSlave(I2C_devices device, uint32_t count, uint8_t* buffer);
	static bool receiveFromMaster(I2C_devices device, uint32_t count, uint8_t* buffer);
	static bool stop(I2C_devices device);
};

#endif
