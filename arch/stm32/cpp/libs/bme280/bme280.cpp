


#include "bme280.h"



void bmeCallback(uint8_t byte) {
	//
}


// --- CONSTRUCTOR ---
BME280::BME280(I2C_devices device, uint8_t address) {
	// Try to set the target I2C peripheral in master mode.
	I2C::startMaster(device, I2C_MODE_FM, bmeCallback);
	this->device = device;
	this->address = address;
}


// --- READ ID ---
// Reads the sensor's fixed ID.
bool BME280::readID(uint8_t &id) {
	// 
}
