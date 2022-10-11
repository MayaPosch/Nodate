


#include "bme280.h"


// --- CONSTRUCTOR ---
BME280::BME280(I2C_devices device, uint8_t address) {
	ready = true;
	spi = false;
	this->i2c_device = device;
	this->address = address;
}


BME280::BME280(SPI_devices device, GpioPinDef cs) {
	ready = true;
	spi = true;
	this->spi_device = device;
	this->cs = cs;
	
	if (!GPIO::set_output(cs, GPIO_PULL_UP, GPIO_PUSH_PULL, GPIO_HIGH)) {
		ready = false;
	}
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
	/* I2C::setSlaveTarget(device, address);
	I2C::sendToSlave(device, &data, 1); */
	start();
	send(&data, 1);
    
    // Initiate the read sequence
	//return I2C::receiveFromSlave(device, 1, &id);
	bool res = receive(&id, 1);
	//bool res = transceive(&data, 1, &id, 1);
	end();
	
	return res;
}


bool BME280::initialize() {
	// Set the configuration for the device.
	uint8_t ctrl_meas_reg = (osrs_t << 5) | (osrs_p << 2) | BME280_OperationMode;
	uint8_t ctrl_hum_reg  = osrs_h;
	uint8_t config_reg    = (t_sb << 5) | (filter << 2) | spi3w_en;
	
	//I2C::setSlaveTarget(device, address);
	start();

	uint8_t data[2];
	data[0] = controlHumidity;
	data[1] = ctrl_hum_reg;
	//if (!I2C::sendToSlave(device, data, 2)) { return false; }
	if (!write(data, 2)) { return false; }
	
	data[0] = reg_Control;
	data[1] = ctrl_meas_reg;
	//if (!I2C::sendToSlave(device, data, 2)) { return false; }
	if (!write(data, 2)) { return false; }
	
	data[0] = reg_Config;
	data[1] = config_reg;
	//if (!I2C::sendToSlave(device, data, 2)) { return false; }
	if (!write(data, 2)) { return false; }
	
	end();

	// Read calibration data from device and store it.
	//I2C::sendToSlave(device, &reg_CalibrationTStart, 1);
	start();
	send(&reg_CalibrationTStart, 1);
	uint8_t buffer[64];
	//I2C::receiveFromSlave(device, reg_CalibrationTEnd - reg_CalibrationTStart + 1, buffer);
	receive(buffer, reg_CalibrationTEnd - reg_CalibrationTStart + 1);
	//transceive(&reg_CalibrationTStart, 1, buffer, reg_CalibrationTEnd - reg_CalibrationTStart + 1);
	end();
	
	// This data is in Big Endian format from the BME280.
    dig_T1 = (buffer[1] << 8) | buffer[0];
    dig_T2 = (buffer[3] << 8) | buffer[2];
    dig_T3 = (buffer[5] << 8) | buffer[4];

	//I2C::sendToSlave(device, &reg_CalibrationPStart, 1);
	start();
	send(&reg_CalibrationPStart, 1);
	//I2C::receiveFromSlave(device, reg_CalibrationPEnd - reg_CalibrationPStart + 1, buffer);
	receive(buffer, reg_CalibrationPEnd - reg_CalibrationPStart + 1);
	//transceive(&reg_CalibrationPStart, 1, buffer, reg_CalibrationPEnd - reg_CalibrationPStart + 1);
	end();

    dig_P1 = (buffer[1] << 8) | buffer[0];
    dig_P2 = (buffer[3] << 8) | buffer[2];
    dig_P3 = (buffer[5] << 8) | buffer[4];
    dig_P4 = (buffer[7] << 8) | buffer[6];
    dig_P5 = (buffer[9] << 8) | buffer[8];
    dig_P6 = (buffer[11] << 8) | buffer[10];
    dig_P7 = (buffer[13] << 8) | buffer[12];
    dig_P8 = (buffer[15] << 8) | buffer[14];
	dig_P9 = (buffer[17] << 8) | buffer[16];

	//I2C::sendToSlave(device, &reg_H1, 1);
	start();
	send(&reg_H1, 1);
	//I2C::receiveFromSlave(device, 1, buffer);
	receive(buffer, 1);
	end();
	//transceive(&reg_H1, 1, buffer, 1);
	dig_H1 = buffer[0];
	
	//I2C::sendToSlave(device, &reg_H2, 1);
	//I2C::receiveFromSlave(device, 2, buffer);
	start();
	send(&reg_H2, 1);
	receive(buffer, 2);
	end();
	//transceive(&reg_H2, 1, buffer, 2);
    dig_H2 = (buffer[1] << 8) | buffer[0];
	
	//I2C::sendToSlave(device, &reg_H3, 1);
	//I2C::receiveFromSlave(device, 1, buffer);
	start();
	send(&reg_H3, 1);
	receive(buffer, 1);
	end();
    dig_H3 = buffer[0];
	
	//I2C::sendToSlave(device, &reg_H4, 1);
	//I2C::receiveFromSlave(device, 4, buffer);
	start();
	send(&reg_H4, 1);
	receive(buffer, 4);
	//transceive(&reg_H4, 1, buffer, 4);
	end();
    dig_H4 = (buffer[0] << 4) | (buffer[1]&0x0F);
	
    dig_H5 = (buffer[2]<<4) | ((buffer[1] & 0xF0)>>4);
	dig_H6 = buffer[3];
	
	return true;
}


bool BME280::softReset() {
	uint8_t data[] = { reg_SoftReset, softResetInstruction };
	/* I2C::setSlaveTarget(device, address);
	I2C::sendToSlave(device, data, 2); */
	start();
	send(data, 2);
	end();
	
	return true;
}


bool BME280::temperature(float &t) {
	int32_t temp;
	if (!rawTemperature(temp)) { return false; }
	t = compensateTemperature(temp);
	return true;
}


float BME280::pressure() {
	//
	
	return 0.0;
}


float BME280::humidity() {
	//
	
	return 0.0;
}


bool BME280::rawTemperature(int32_t &t) {
	// Send register to read to the device.
	uint8_t data = 0xFA;
	//I2C::setSlaveTarget(device, address);
	//I2C::sendToSlave(device, &data, 1);
	start();
	send(&data, 1);
    
    // Initiate the read sequence
	uint8_t buffer[3];
    //if (!(I2C::receiveFromSlave(device, 3, buffer))) {
    if (!(receive(buffer, 3))) {
		end();
        return false;
    }
	
	end();
 	t = ((buffer[0] << 12) | (buffer[1] << 4) | (buffer[2] >> 4));

    return true;
}


// FIXME: BME280 datasheet suggests returning int32_t type, not float. Replace?
float BME280::compensateTemperature(int32_t rawTemp) {
	int32_t var1, var2;
	var1 = ((((rawTemp >> 3) - ((int32_t) dig_T1 << 1))) * ((int32_t) dig_T2)) >> 11;
	var2 = (((((rawTemp >> 4) - ((int32_t) dig_T1)) * ((rawTemp >> 4) - ((int32_t) dig_T1))) >> 12) * ((int32_t) dig_T3)) >> 14;
	t_fine = var1 + var2;
	float temperature = (t_fine * 5 + 128) >> 8;  /* temperature in 0.01 deg C*/

	return temperature / 100;
}


// --- START ---
// Take any actions to enable communication with the device.
bool BME280::start() {
	if (spi) {
		// Set the chip select line to active low.
		if (!GPIO::write(cs, GPIO_LEVEL_LOW)) { return false; }
	}
	
	return true;
}


// --- END ---
// Take any actions to disable communication with the device.
bool BME280::end() {
	if (spi) {
		// Set the chip select line to high (high-Z).
		if (!GPIO::write(cs, GPIO_LEVEL_HIGH)) { return false; }
	}
	
	return true;
}


// --- SEND ---
// Perform a read request on a register.
bool BME280::send(uint8_t* data, uint16_t len) {
	if (spi) {
#ifdef NODATE_SPI_ENABLED
		// Use SPI send.
		// Ensure the first bit is set to the 'read' state (1).
		*data |= 0x80;
		if (!SPI::sendData(spi_device, data, len)) { return false; }
#endif
	}
	else {
#ifdef NODATE_I2C_ENABLED
		// Use I2C send.
		I2C::setSlaveTarget(i2c_device, address);
		I2C::sendToSlave(i2c_device, data, len);
#endif
	}
	
	return true;
}


// --- WRITE ---
// Perform a write action to a register.
bool BME280::write(uint8_t* data, uint16_t len) {
	if (spi) {
#ifdef NODATE_SPI_ENABLED
		// Use SPI send.
		// Ensure we set the first bit to the 'write' state (0)
		*data &= ~0x80;
		if (!SPI::sendData(spi_device, data, len)) { return false; }
#endif
	}
	else {
#ifdef NODATE_I2C_ENABLED
		// Use I2C send.
		I2C::setSlaveTarget(i2c_device, address);
		I2C::sendToSlave(i2c_device, data, len);
#endif
	}
	
	return true;
}


// --- RECEIVE ---
bool BME280::receive(uint8_t* data, uint16_t len) {
	if (spi) {
#ifdef NODATE_SPI_ENABLED
		// Use SPI receive.
		if (!SPI::receiveData(spi_device, data, len)) {
			return false;
		}
#endif
	}
	else {
#ifdef NODATE_I2C_ENABLED
		// Use I2C receive.
		I2C::receiveFromSlave(i2c_device, len, data);
#endif
	}
	
	return true;
}


// --- TRANSCEIVE ---
// Combined send/receive.
bool BME280::transceive(uint8_t* txdata, uint16_t txlen, uint8_t* rxdata, uint16_t rxlen) {
	if (spi) {
#ifdef NODATE_SPI_ENABLED
		// Use SPI transceive.
		if (!SPI::transceiveData(spi_device, txdata, txlen, rxdata, rxlen)) {
			return false;
		}
#endif
	}
	else {
#ifdef NODATE_I2C_ENABLED
		// Use I2C send and receive.
		I2C::setSlaveTarget(i2c_device, address);
		I2C::sendToSlave(i2c_device, txdata, txlen);
		I2C::receiveFromSlave(i2c_device, rxlen, rxdata);
#endif
	}
	
	return true;
}
