


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
	
	// Read the response once it comes in.
	uint32_t to = 1000000;
	while (I2C_wait || to < 1) {
		// TODO: elegantly handle timeout.
		to--;
	}
	
	id = I2C_byte;
	
	return true;
}


float BME280::GetTemperature() {
	//
}


float BME280::GetPressure() {
	//
}


float BME280::GetHumidity() {
	//
}
