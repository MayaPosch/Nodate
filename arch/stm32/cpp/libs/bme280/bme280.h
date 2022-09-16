/*
	bme280.h - BME 280 module declaration.
	
	Revision 1
	
	Notes:
			- 
			
	2020/10/23, Maya Posch
	2022/04/09, Maya Posch
*/

#ifndef LIB_BME280_H
#define LIB_BME280_H

#include <nodate.h>


#define BME280_MODE_NORMAL			0x03 // Reads sensor at set interval.
#define BME280_MODE_FORCED			0x01 // Reads sensor after write to register.


class BME280 {
	bool spi = false;
	I2C_devices i2c_device;
	SPI_devices spi_device;
	uint8_t address;
	bool ready;
	GpioPinDef cs;
	
	uint16_t dig_T1;
	int16_t dig_T2;
	int16_t dig_T3;

	uint16_t dig_P1;
	int16_t dig_P2;
	int16_t dig_P3;
	int16_t dig_P4;
	int16_t dig_P5;
	int16_t dig_P6;
	int16_t dig_P7;
	int16_t dig_P8;
	int16_t dig_P9;

	uint8_t dig_H1;
	int16_t dig_H2;
	uint8_t dig_H3;
	int16_t dig_H4;
	int16_t dig_H5;
	int8_t dig_H6;
	
	uint8_t reg_H1	= 0xA1;
	uint8_t reg_H2   = 0xE1;
	uint8_t reg_H3   = 0xE3;
	uint8_t reg_H4   = 0xE4;
	uint8_t reg_H5   = 0xE5;
	uint8_t reg_H6   = 0xE7;
	
	uint8_t osrs_t = 1;             //Temperature oversampling x 1
	uint8_t osrs_p = 1;             //Pressure oversampling x 1
	uint8_t osrs_h = 1;             //Humidity oversampling x 1

	uint8_t t_sb = 4;               //Tstandby, 5=1000ms, 4=500ms
	uint8_t filter = 0;             //Filter off
	uint8_t spi3w_en = 0;           //3-wire SPI Disable
	uint8_t BME280_OperationMode = BME280_MODE_NORMAL;
	
	uint8_t measureHumidity = 0xFD;
	uint8_t controlHumidity = 0xF2;
	uint8_t reg_Control = 0xF4;
	uint8_t reg_Config = 0xF5;
	uint8_t reg_CalibrationTStart = 0x88;
	uint8_t reg_CalibrationTEnd = 0x8D;

	uint8_t reg_CalibrationPStart = 0x8E;
	uint8_t reg_CalibrationPEnd = 0x9F;
	
	uint8_t reg_SoftReset = 0xE0;
	uint8_t softResetInstruction = 0xB6;
	
	int32_t t_fine;
	
public:
	BME280(I2C_devices device, uint8_t address);
	BME280(SPI_devices device, GpioPinDef cs);
	bool isReady();
	bool readID(uint8_t &id);
	bool initialize();
	bool softReset();
	
	bool temperature(float &t);
	float pressure();
	float humidity();
	
	bool rawTemperature(int32_t &t);
	
	float compensateTemperature(int32_t rawTemp);
	
	bool start();	// Start communication.
	bool end();	// Stop communication.
	bool send(uint8_t* data, uint16_t len);
	bool receive(uint8_t* data, uint16_t len);
};

#endif
