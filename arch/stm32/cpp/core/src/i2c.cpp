/*
	i2c.cpp - Implementation file for the I2C class.
*/


#include <i2c.h>

#include <gpio.h>


// Callback handlers.
extern "C" {
	void I2C1_IRQHandler(void);
}


void I2C1_IRQHandler(void) {
	//
}


const int i2c_count = 2;

// --- I2C DEVICES ---
I2C_device* I2C_list() {
	I2C_device item;
	static I2C_device devices[i2c_count];
	for (int i = 0; i < i2c_count; ++i) {
		devices[i] = item;
	}
	
#ifdef RCC_APB1ENR_I2C1EN
	devices[I2C_1].regs = I2C1;
	devices[I2C_1].irqType = I2C1_IRQn;
#endif

#ifdef RCC_APB1ENR_I2C2EN
	devices[I2C_2].regs = I2C2;
	devices[I2C_2].irqType = I2C2_IRQn;
#endif
	
	return devices;
}


// FIXME: hard-coding I2C timings isn't ideal. Neither is dynamically calculating them.
uint32_t i2c_timings_8[4];
uint32_t i2c_timings_16[4];
uint32_t i2c_timings_48[4];

void I2C_timings() {
#if defined STM32F0	
	i2c_timings_8[0] = 0x1042C3C7;
	i2c_timings_8[1] = 0x10420F13;
	i2c_timings_8[2] = 0x00310309;
	i2c_timings_8[3] = 0x00100306;
	i2c_timings_16[0] = 0x3042C3C7;
	i2c_timings_16[1] = 0x30420F13;
	i2c_timings_16[2] = 0x10320309;
	i2c_timings_16[3] = 0x00200204;
	i2c_timings_48[0] = 0xB042C3C7;
	i2c_timings_48[1] = 0xB0420F13;
	i2c_timings_48[2] = 0x50330309;
	i2c_timings_48[3] = 0x50100103;
#endif
}


I2C_device* i2cList = I2C_list();


// --- START I2C ---
// Perform basic initialisation of I2C peripheral. After this the device can be further configured
// as Master or Slave device using the appropriate method.
bool I2C::startI2C(I2C_devices device, GPIO_ports scl_port, uint8_t scl_pin, uint8_t scl_af,
											GPIO_ports sda_port, uint8_t sda_pin, uint8_t sda_af) {
	I2C_device &instance = i2cList[device];
	
	// Check status. Set parameters.
	if (instance.active) { return true; } // Already active.
	if (device == I2C_1) 		{ instance.per = RCC_I2C1; }
	else if (device == I2C_2)	{ instance.per = RCC_I2C2; }
	
	// Configure SDA & SCL pins.
#ifdef __stm32f1
	if (!GPIO::set_af(instance.per, scl_af)) {
		Rcc::disablePort((RccPort) scl_port);
		return false;
	}
#else
	if (!GPIO::set_af(scl_port, scl_pin, scl_af)) {
		Rcc::disablePort((RccPort) scl_port);
		return false;
	}
	
	if (!GPIO::set_af(sda_port, sda_pin, sda_af)) {
		Rcc::disablePort((RccPort) scl_port);
		Rcc::disablePort((RccPort) sda_port);
		return false;
	}
#endif
	
	if (!GPIO::set_output_parameters(scl_port, scl_pin, GPIO_FLOATING, GPIO_OPEN_DRAIN, GPIO_HIGH)) {
		Rcc::disablePort((RccPort) scl_port);
		Rcc::disablePort((RccPort) sda_port);
		return false;
	}
	
	if (!GPIO::set_output_parameters(sda_port, sda_pin, GPIO_FLOATING, GPIO_OPEN_DRAIN, GPIO_HIGH)) {
		Rcc::disablePort((RccPort) scl_port);
		Rcc::disablePort((RccPort) sda_port);
		return false;
	}
	
	// Reset peripheral.
	instance.regs->CR1 &= ~I2C_CR1_PE;	// Disable peripheral.
	instance.regs->CR1 |= I2C_CR1_SWRST;
	instance.regs->CR1 &= ~I2C_CR1_SWRST;
	
	// Start I2C device if needed.
	if (!Rcc::enable(instance.per)) {
		// TODO: set status.
		return false; 
	}
	
	// Register interrupt.
	NVIC_SetPriority(instance.irqType, 0);
	NVIC_EnableIRQ(instance.irqType); 
	
	instance.active = true;
	return true;
}


// --- START MASTER ---
// Start I2C master mode on the target I2C peripheral.
bool I2C::startMaster(I2C_devices device, I2C_modes mode) {
	I2C_device &instance = i2cList[device];
	
	// Check status. Set parameters.
	if (instance.active) { return true; } // Already active.
#if defined STM32F0
	// Set timing register.
	//instance.regs->TIMINGR = (uint32_t) 0x00B01A4B;
	if (SystemCoreClock == 8000000) {
		instance.regs->TIMINGR = i2c_timings_8[mode];
	}
	else if (SystemCoreClock == 16000000) {
		instance.regs->TIMINGR = i2c_timings_16[mode];
	}
	else if (SystemCoreClock == 48000000) {
		instance.regs->TIMINGR = i2c_timings_48[mode];
	}
	else {
		// Unavailable timing for this system clock.
		return false;
	}
	
	// Enable peripheral.
	instance.regs->CR1 |= I2C_CR1_PE;
#endif
	
	instance.master = true;
	
	return true;
}
	

// --- SET SLAVE TARGET ---
// Set the slave address to target (Master mode).
// TODO: add support for 10-bit addresses.
bool I2C::setSlaveTarget(I2C_devices device, uint8_t slave) {
	I2C_device &instance = i2cList[device];
	instance.slaveTarget = slave;
	
	return true;
}


// --- START SLAVE ---
// Start I2C device in Slave mode.
bool I2C::startSlave(I2C_devices device, uint8_t address) {
	//
	
	return true;
}


// --- SEND TO SLAVE ---
// Send length bytes on the I2C bus to the set Slave address.
bool I2C::sendToSlave(I2C_devices device, uint8_t* data, uint8_t len) {
	I2C_device &instance = i2cList[device];
	instance.regs->CR2 =  I2C_CR2_AUTOEND | (len << 16) | (instance.slaveTarget << 1);
	
	for (int i = 0; i < len; i++) {
		// Check that the transmit data register (TXDR) is empty.
		if ((instance.regs->ISR & I2C_ISR_TXE) == (I2C_ISR_TXE)) {
			instance.regs->TXDR = data[i];
			instance.regs->CR2 |= I2C_CR2_START; // Transmit.
			
			// TODO: handle transmit errors.
		}
	}
	
	return true;
}


// --- SEND TO MASTER ---
// Send data to the Master on the I2C device.
bool I2C::sendToMaster(I2C_devices device, uint8_t* data, uint8_t len) {
	//
	
	return true;
}


// --- RECEIVE FROM SLAVE ---
// Configure Master to receive data from a Slave device.
bool I2C::receiveFromSlave(I2C_devices device, uint32_t count, uint8_t* buffer) {
	//
	
	return true;
}


// ---- RECEIVE FROM MASTER ---
bool I2C::receiveFromMaster(I2C_devices device, uint32_t count, uint8_t* buffer) {
	//
	
	return true;
}


// --- STOP I2C ---
// Stop I2C device and reset in preparation for new initialisation.
bool I2C::stop(I2C_devices device) {
	I2C_device &instance = i2cList[device];
#if defined STM32F0
	instance.regs->CR1 &= ~I2C_CR1_PE;
#endif

	// Disable interrupt.
	NVIC_DisableIRQ(instance.irqType);
	
	return true;
}
