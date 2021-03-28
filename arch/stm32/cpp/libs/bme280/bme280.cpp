


#include "bme280.h"


volatile bool I2C_wait = false;
volatile uint8_t I2C_byte = 0;

void bmeCallback(uint8_t byte) {
	I2C_byte = byte;
	I2C_wait = false;
}


// --- CONSTRUCTOR ---
BME280::BME280(I2C_devices device, uint8_t address) {
	// Try to set the target I2C peripheral in master mode.
	ready = I2C::startMaster(device, I2C_MODE_FM, bmeCallback);
	this->device = device;
	this->address = address;
	
	I2C::setSlaveTarget(device, address);
	
	// Read calibration data from device and store it.
	uint8_t ctrl_meas_reg = (osrs_t << 5) | (osrs_p << 2) | BME280_OperationMode;
	uint8_t ctrl_hum_reg  = osrs_h;

	uint8_t config_reg    = (t_sb << 5) | (filter << 2) | spi3w_en;

	I2C::sendToSlave(device, &controlHumidity, ctrl_hum_reg);
	I2C::sendToSlave(device, &reg_Control, ctrl_meas_reg);
	I2C::sendToSlave(device, &reg_Config, config_reg);

	I2C::sendToSlave(device, &reg_CalibrationTStart, 1);
	uint8_t buffer[64];
	I2C::receiveFromSlave(device, reg_CalibrationTEnd - reg_CalibrationTStart + 1, buffer);
	
	// This data is in Big Endian format from the BME280.
    BME280_REGISTER_DIG_T1 = (buffer[1] << 8) | buffer[0];
    BME280_REGISTER_DIG_T2 = (buffer[3] << 8) | buffer[2];
    BME280_REGISTER_DIG_T3 = (buffer[5] << 8) | buffer[4];

	I2C::sendToSlave(device, &reg_CalibrationPStart, 1);
	I2C::receiveFromSlave(device, reg_CalibrationPEnd - reg_CalibrationPStart + 1, buffer);

    BME280_REGISTER_DIG_P1 = (buffer[1] << 8) | buffer[0];
    BME280_REGISTER_DIG_P2 = (buffer[3] << 8) | buffer[2];
    BME280_REGISTER_DIG_P3 = (buffer[5] << 8) | buffer[4];
    BME280_REGISTER_DIG_P4 = (buffer[7] << 8) | buffer[6];
    BME280_REGISTER_DIG_P5 = (buffer[9] << 8) | buffer[8];
    BME280_REGISTER_DIG_P6 = (buffer[11] << 8) | buffer[10];
    BME280_REGISTER_DIG_P7 = (buffer[13] << 8) | buffer[12];
    BME280_REGISTER_DIG_P8 = (buffer[15] << 8) | buffer[14];
	BME280_REGISTER_DIG_P9 = (buffer[17] << 8) | buffer[16];

	I2C::sendToSlave(device, &BME280_REG_DIG_H1, 1);
	I2C::receiveFromSlave(device, 1, buffer);
	BME280_REGISTER_DIG_H1 = buffer[0];
	
	I2C::sendToSlave(device, &BME280_REG_DIG_H2, 1);
	I2C::receiveFromSlave(device, 2, buffer);
    BME280_REGISTER_DIG_H2 = (buffer[1] << 8) | buffer[0];
	
	I2C::sendToSlave(device, &BME280_REG_DIG_H3, 1);
	I2C::receiveFromSlave(device, 1, buffer);
    BME280_REGISTER_DIG_H3 = buffer[0];
	
	I2C::sendToSlave(device, &BME280_REG_DIG_H4, 1);
	I2C::receiveFromSlave(device, 4, buffer);
    BME280_REGISTER_DIG_H4 = (buffer[0] << 4) | (buffer[1]&0x0F);
	
    BME280_REGISTER_DIG_H5 = (buffer[2]<<4) | ((buffer[1] & 0xF0)>>4);
	BME280_REGISTER_DIG_H6 = buffer[3];
}


// --- IS READY ---
// Returns true if the sensor instance has been fully configured and is ready for read/write.
bool BME280::isReady() {
	return ready;
}


// --- READ ID ---
// Reads the sensor's fixed ID.
bool BME280::readID(uint8_t &id) {
	// Send register to read to the device.
	uint8_t data = 0xd0;
	I2C::sendToSlave(device, &data, 1);
	I2C_wait = true;
    
    // Initiate the read sequence
    if (!(I2C::receiveFromSlave(device, 1))) {
        return false;
    }
	
	// Read the response once it comes in.
	uint32_t to = 1000000;
	while (I2C_wait && to > 1) {
		// TODO: elegantly handle timeout.
		to--;
	}
	
	id = I2C_byte;
	
	return true;
}


float BME280::temperature() {
	return compensateTemperature(rawTemperature());
}


float BME280::pressure() {
	//
	
	return 0.0;
}


float BME280::humidity() {
	//
	
	return 0.0;
}


int32_t BME280::rawTemperature() {
	// Send register to read to the device.
	uint8_t data = 0xFA;
	I2C::sendToSlave(device, &data, 1);
    
    // Initiate the read sequence
	uint8_t buffer[3];
    if (!(I2C::receiveFromSlave(device, 3, buffer))) {
        return false;
    }
	
 	int32_t value = ((buffer[0] << 12) | (buffer[1] << 4) | (buffer[2] >> 4));

    return value;
}


// FIXME: BME280 datasheet suggests returning int32_t type, not float. Replace?
float BME280::compensateTemperature(int32_t rawTemp) {
	int32_t var1, var2;
	var1 = ((((rawTemp >> 3) - ((int32_t) BME280_REGISTER_DIG_T1 << 1))) * ((int32_t) BME280_REGISTER_DIG_T2)) >> 11;
	var2 = (((((rawTemp >> 4) - ((int32_t) BME280_REGISTER_DIG_T1)) * ((rawTemp >> 4) - ((int32_t) BME280_REGISTER_DIG_T1))) >> 12) * ((int32_t) BME280_REGISTER_DIG_T3)) >> 14;
	int32_t t_fine = var1 + var2;
	float temperature = (t_fine * 5 + 128) >> 8;  /* temperature in 0.01 deg C*/

	return temperature / 100;
}
