/*
	bme280.h - BME 280 module declaration.
	
	Revision 0
	
	Notes:
			- 
			
	2020/10/23, Maya Posch
*/


#include <i2c.h>


class BME280 {
	I2C_devices device;
	uint8_t address;
	
public:
	BME280(I2C_devices device, uint8_t address);
	bool readID(uint8_t &id);
};
