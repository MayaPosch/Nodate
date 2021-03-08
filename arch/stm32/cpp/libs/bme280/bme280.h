/*
	bme280.h - BME 280 module declaration.
	
	Revision 0
	
	Notes:
			- 
			
	2020/10/23, Maya Posch
*/

#ifndef LIB_BME280_H
#define LIB_BME280_H

#include <i2c.h>


class BME280 {
	I2C_devices device;
	uint8_t address;
	bool ready;
	
public:
	BME280(I2C_devices device, uint8_t address);
	bool isReady();
	bool readID(uint8_t &id);
	
	float GetTemperature();
	float GetPressure();
	float GetHumidity();
};

#endif
