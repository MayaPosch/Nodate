/*
	i2c.cpp - Implementation file for the I2C class.
*/


#include <i2c.h>


#ifdef NODATE_I2C_ENABLED


#include <gpio.h>


const int i2c_count = 3;

// --- I2C DEVICES ---
I2C_device* I2C_list() {
	I2C_device item;
	static I2C_device i2c_devices[i2c_count];
	for (int i = 0; i < i2c_count; ++i) {
		i2c_devices[i] = item;
	}
	
#ifdef RCC_APB1ENR_I2C1EN
	i2c_devices[I2C_1].regs = I2C1;
#if defined __stm32f4 || defined __stm32f1 || defined __stm32f7
	i2c_devices[I2C_1].irqType = I2C1_EV_IRQn;
#else
	i2c_devices[I2C_1].irqType = I2C1_IRQn;
#endif
#endif

#ifdef RCC_APB1ENR_I2C2EN
	i2c_devices[I2C_2].regs = I2C2;
#if defined __stm32f4 || defined __stm32f1 || defined __stm32f7
	i2c_devices[I2C_2].irqType = I2C2_EV_IRQn;
#else
	i2c_devices[I2C_2].irqType = I2C2_IRQn;
#endif
#endif

#ifdef RCC_APB1ENR_I2C3EN
	i2c_devices[I2C_3].regs = I2C3;
#if defined __stm32f4 || defined __stm32f1 || defined __stm32f7
	i2c_devices[I2C_3].irqType = I2C3_EV_IRQn;
#else
	i2c_devices[I2C_3].irqType = I2C3_IRQn;
#endif
#endif
	
	return i2c_devices;
}


// FIXME: hard-coding I2C timings isn't ideal. Neither is dynamically calculating them.
uint32_t i2c_timings_8[4];
uint32_t i2c_timings_16[4];
uint32_t i2c_timings_48[4];

bool I2C_timings() {
#if defined __stm32f0	
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

	return true;
}


I2C_device* i2cList = I2C_list();

// Populate I2C timings.
bool i2c_init = I2C_timings();


// Callback handlers.
volatile uint8_t i2c_rxb = 0;
#if defined __stm32f0
extern "C" {
	void I2C1_IRQHandler(void);
}


void I2C1_IRQHandler(void) {
	I2C_device &instance = i2cList[0];
	
	// Verify interrupt status.
	if ((instance.regs->ISR & I2C_ISR_RXNE) == I2C_ISR_RXNE) {
		// Read byte (which clears RXNE flag).
		i2c_rxb = instance.regs->RXDR;
		instance.callback(i2c_rxb);
	}
}

#elif defined __stm32f4
/* extern "C" {
	void I2C1_EV_IRQHandler(void);
	void I2C2_EV_IRQHandler(void);
	void I2C3_EV_IRQHandler(void);
}


void I2C1_EV_IRQHandler(void) {
	I2C_device &instance = i2cList[0];
	
	// Verify interrupt status.
	if ((instance.regs->ISR & I2C_ISR_RXNE) == I2C_ISR_RXNE) {
		// Read byte (which clears RXNE flag).
		i2c_rxb = instance.regs->RXDR;
		instance.callback(i2c_rxb);
	}
}


void I2C2_EV_IRQHandler(void) {
	I2C_device &instance = i2cList[1];
	if ((instance.regs->ISR & I2C_ISR_RXNE) == I2C_ISR_RXNE) {
		i2c_rxb = instance.regs->RXDR;
		instance.callback(i2c_rxb);
	}
}


void I2C3_EV_IRQHandler(void) {
	I2C_device &instance = i2cList[2];
	if ((instance.regs->ISR & I2C_ISR_RXNE) == I2C_ISR_RXNE) {
		i2c_rxb = instance.regs->RXDR;
		instance.callback(i2c_rxb);
	}
} */
#endif


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
	
	// Start I2C device if needed.
	if (!instance.active) {
		if (!Rcc::enable(instance.per)) {
			// TODO: set status.
			return false;
		}
	}

#ifdef __stm32f0	
	// Reset peripheral.
	instance.regs->CR1 &= ~I2C_CR1_PE;	// Disable peripheral.
	instance.regs->CR1 |= I2C_CR1_SWRST;
	instance.regs->CR1 &= ~I2C_CR1_SWRST;
#else

#endif
	
	// Register interrupt.
	NVIC_SetPriority(instance.irqType, 0);
	NVIC_EnableIRQ(instance.irqType);
	
	// Save parameters.	
	instance.active = true;
	
	return true;
}


// --- START MASTER ---
// Start I2C master mode on the target I2C peripheral.
bool I2C::startMaster(I2C_devices device, I2C_modes mode, std::function<void(uint8_t)> callback) {
	I2C_device &instance = i2cList[device];
	
	// Check status. Set parameters.
	if (!instance.active) { return false; } // Interface isn't active yet.
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
	
	// Enable interrupts on peripheral.
	instance.regs->CR1 |= I2C_CR1_RXIE;
	
	// Enable peripheral.
	instance.regs->CR1 |= I2C_CR1_PE;
#endif
	
	// Save parameters.
	instance.callback = callback;
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


#include <printf.h>


// --- SEND TO SLAVE ---
// Send length bytes on the I2C bus to the set Slave address.
bool I2C::sendToSlave(I2C_devices device, uint8_t* data, uint16_t len) {
	I2C_device &instance = i2cList[device];
#if defined STM32F0
	uint32_t cr2_reg = 0;
    cr2_reg |= (instance.slaveTarget << 1);
	if (len > 0xff) {
		// Set RELOAD so that we can transmit more data after finishing a transfer cycle.
		// Set NBYTES to the max value (0xff).
		cr2_reg |= I2C_CR2_RELOAD;
		cr2_reg |= (0xff << 16);
		printf("Set reload.\n");
	}
	else {
		// Set AUTOEND and the data byte size.
		cr2_reg |= I2C_CR2_AUTOEND | (uint32_t) (len << 16);
	}
	
	cr2_reg |= I2C_CR2_START;
	instance.regs->CR2 = cr2_reg;
	
	uint16_t bytesToWrite = len;
	while (bytesToWrite > 0) {
		uint8_t write = 0xff;
		if (bytesToWrite < 256) {
			// Prepare for final data transmission.
			write = bytesToWrite;
			instance.regs->CR2 |= I2C_CR2_AUTOEND;
		}
		
		for (uint8_t i = 0; i < write; i++) {
			// 1. If ISR_NACKF == 1, abort. Not Acknowledge receive Flag. 
			if ((instance.regs->ISR & I2C_ISR_NACKF) == I2C_ISR_NACKF) {
				return false;
			}
			
			// 2. Check that ISR_TXIS == 1. Transmit Interrupt Status.
			uint32_t ts = McuCore::getSysTick();
			uint32_t timeout = 400; // TODO: make configurable.
			while ((instance.regs->ISR & I2C_ISR_TXIS) != I2C_ISR_TXIS) {
				// Handle timeout.
				if (((McuCore::getSysTick() - ts) > timeout) || timeout == 0) {
					// TODO: set status.
					printf("I2C timeout.\n");
					return false;
				}
			}
			
			// 3. Write data into TXDR.
			instance.regs->TXDR = data[i];
		}
		
		bytesToWrite -= write;
			
		// 4. If ISR_TC == 1, we're done. (Transfer Complete).
		// 		Else check if ISR_TCR == 1. (Transfer Complete Reload).
		// 		If true, start new transfer cycle.
		if ((instance.regs->ISR & I2C_ISR_TC) == I2C_ISR_TC) {
			// Transfer complete.
			break;
		}
		
		// Restart session if data left. Transfer Complete Reload.
		//if ((instance.regs->ISR & I2C_ISR_TCR) == I2C_ISR_TCR) {
			//printf("TCR true.\n");
			
			// Remaining data fits in a single transfer. Disable reload.
			if (bytesToWrite < 256 && bytesToWrite > 0) {
				instance.regs->CR2 &= ~I2C_CR2_RELOAD;
				instance.regs->CR2 &= ~(0xff << 16);
				instance.regs->CR2 |= I2C_CR2_AUTOEND | (uint32_t) (bytesToWrite << 16);
				printf("Unset reload.\n");
			}
			else if (bytesToWrite > 256) {
				// Set reload and NBYTES.
				instance.regs->CR2 |= I2C_CR2_RELOAD | (0xff << 16);
			}
		//}
		else {
			// Stop transmission.
			break;
		}
	}
#endif
	
	return true;
}


// --- SEND TO SLAVE BEGIN ---
bool I2C::sendToSlaveBegin(I2C_devices device, uint8_t len) {
	I2C_device &instance = i2cList[device];
#if defined STM32F0
	uint32_t reg = 0;
	reg |= (instance.slaveTarget << 1) | I2C_CR2_START | len << 16;
	instance.regs->CR2 = reg;

	return true;
#endif
	return false;
}


// -- SEND TO SLAVE BYTE ---
bool sendToSlaveByte(I2C_devices device, uint8_t data) {
	I2C_device &instance = i2cList[device];
#if defined STM32F0
	// 1. If ISR_NACKF == 1, abort. Not Acknowledge receive Flag.
	if ((instance.regs->ISR & I2C_ISR_NACKF) == I2C_ISR_NACKF) {
		return false;
	}
	
	// 2. Check that ISR_TXIS == 1. Transmit Interrupt Status.
	uint32_t ts = McuCore::getSysTick();
	uint32_t timeout = 400; // TODO: make configurable.
	while ((instance.regs->ISR & I2C_ISR_TXIS) != I2C_ISR_TXIS) {
		// Handle timeout.
		if (((McuCore::getSysTick() - ts) > timeout) || timeout == 0) {
			// TODO: set status.
			printf("I2C timeout.\n");
			return false;
		}
	}
	
	// 3. Write data into TXDR.
	instance.regs->TXDR = data;
	
	return true;
#endif
	return false;
}


// --- SEND TO SLAVE BYTES ---
bool I2C::sendToSlaveBytes(I2C_devices device, uint8_t* data, uint8_t len) {
	I2C_device &instance = i2cList[device];
#if defined STM32F0
	for (uint8_t i = 0; i < len; i++) {
		// 1. If ISR_NACKF == 1, abort. Not Acknowledge receive Flag.
		if ((instance.regs->ISR & I2C_ISR_NACKF) == I2C_ISR_NACKF) {
			return false;
		}
		
		// 2. Check that ISR_TXIS == 1. Transmit Interrupt Status.
		uint32_t ts = McuCore::getSysTick();
		uint32_t timeout = 400; // TODO: make configurable.
		while ((instance.regs->ISR & I2C_ISR_TXIS) != I2C_ISR_TXIS) {
			// Handle timeout.
			if (((McuCore::getSysTick() - ts) > timeout) || timeout == 0) {
				// TODO: set status.
				printf("I2C timeout. Return false.\n");
				return false;
			}
		}
		
		// 3. Write data into TXDR.
		instance.regs->TXDR = data[i];
	}
	
	printf("Return true...\n");
	
	return true;
#endif
	return false;
}


// --- SEND TO SLAVE END ---
bool I2C::sendToSlaveEnd(I2C_devices device) {
	I2C_device &instance = i2cList[device];
#if defined STM32F0
	instance.regs->CR2 |= I2C_CR2_STOP;
	
	return true;
#endif
	return false;
}



// --- SEND TO MASTER ---
// Send data to the Master on the I2C device.
bool I2C::sendToMaster(I2C_devices device, uint8_t* data, uint8_t len) {
	I2C_device &instance = i2cList[device];
#if defined STM32F0
	//
	
	return true;
#endif
	return false;
}


// --- RECEIVE FROM SLAVE ---
// Configure Master to receive data from a Slave device.
bool I2C::receiveFromSlave(I2C_devices device, uint32_t count, uint8_t* buffer) {
	I2C_device &instance = i2cList[device];
    uint32_t timeOut = (uint32_t) 0x1000;
#if defined STM32F0 
    /* Disable interrupt if is enabled. An active interrupt handler that reads the RXDR register field will automatically
       reset the RXNE flag, preventing this routine from being notified that data is ready in the data register.
    */
    bool reEnableIRQ = false;
    if (NVIC_GetEnableIRQ(instance.irqType) == 1) {
        NVIC_DisableIRQ(instance.irqType);
        reEnableIRQ = true;
    }
    
    while ((instance.regs->ISR & I2C_ISR_BUSY) == I2C_ISR_BUSY) {  // wait for the bus to become "unbusy"
        if ((timeOut--) == 0) {
			if (reEnableIRQ) {
				NVIC_EnableIRQ(instance.irqType);
			}
			
			return false; 
		}
    }

    instance.regs->CR2 =  I2C_CR2_RD_WRN | I2C_CR2_AUTOEND | (count << 16) | (instance.slaveTarget << 1) | (I2C_CR2_START);
	
	for (uint8_t i = 0; i < count; ++i) {
        timeOut = (uint32_t) 0x1000;
        // 1. Check ISR_RXNE == 1. (Receive data register Not Empty).
        while ((instance.regs->ISR & I2C_ISR_RXNE) != I2C_ISR_RXNE) {
            if ((timeOut--) == 0) { return false; }
            if (((instance.regs->ISR & I2C_ISR_BERR) == I2C_ISR_BERR) || ((instance.regs->ISR & I2C_ISR_ARLO) == I2C_ISR_ARLO)) {
				if (reEnableIRQ) {
					NVIC_EnableIRQ(instance.irqType);
				}
                return false;  // dumpster fire has occurred
            }
        }
        // 2. Read RXDR into buffer.
		buffer[i] = (uint8_t) instance.regs->RXDR;
	}
	
	// 3. If ISR_TC == 1, we're done. (Transfer Complete).
	// 		Else check if ISR_TCR == 1. (Transfer Complete Reload).
	// 		If true, start new transfer cycle.
	if ((instance.regs->ISR & I2C_ISR_TC) == I2C_ISR_TC) {
		// TODO: restart session.
	}
    // Re-enable interrupt.
    if (reEnableIRQ) {
        NVIC_EnableIRQ(instance.irqType);
    }
#endif
	
	return true;
}


// --- RECEIVE FROM SLAVE ---
bool I2C::receiveFromSlave(I2C_devices device, uint8_t len) {
    uint32_t timeOut = (uint32_t) 0x1000;
    I2C_device &instance = i2cList[device];
#if defined STM32F0
    while ((instance.regs->ISR & I2C_ISR_BUSY) == I2C_ISR_BUSY) {  // wait for the bus to become "unbusy"
        if ((timeOut--) == 0) { return false; }
    }
	
    instance.regs->CR2 &= ~(I2C_CR2_SADD_Msk | I2C_CR2_RD_WRN_Msk | I2C_CR2_NBYTES_Msk | I2C_CR2_RELOAD | I2C_CR2_AUTOEND_Msk | \
                            I2C_CR2_START_Msk | I2C_CR2_START | I2C_CR2_STOP);  // clear the CR2 fields
    instance.regs->CR2 |= ((instance.slaveTarget << 1) << I2C_CR2_SADD_Pos);
    instance.regs->CR2 |= I2C_CR2_RD_WRN;
    instance.regs->CR2 |= (0x1UL << I2C_CR2_NBYTES_Pos);
    instance.regs->CR2 |= I2C_CR2_AUTOEND;

    instance.regs->CR2 |= I2C_CR2_START;  // Transmit
    

#endif
    
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

	// Disable interrupt.
	NVIC_DisableIRQ(instance.irqType);
#endif
	
	return true;
}


#endif
