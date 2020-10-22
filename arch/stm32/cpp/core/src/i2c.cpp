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
#endif

#ifdef RCC_APB1ENR_I2C2EN
	devices[I2C_2].regs = I2C2;
#endif
	
	return devices;
}


// FIXME: hard-coding I2C timings isn't ideal. Neither is dynamically calculating them.
uint32_t* i2c_timings_8[4];
uint32_t* i2c_timings_16[4];
uint32_t* i2c_timings_48[4];

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

// Static initialisations.
GPIO I2C::gpio;


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
	if (!gpio.set_af(instance.per, scl_af)) {
		Rcc::disablePort((RccPort) scl_port);
		return false;
	}
#else
	if (!gpio.set_af(scl_port, scl_pin, scl_af)) {
		Rcc::disablePort((RccPort) scl_port);
		return false;
	}
	
	if (!gpio.set_af(sda_port, sda_pin, sda_af)) {
		Rcc::disablePort((RccPort) scl_port);
		Rcc::disablePort((RccPort) sda_port);
		return false;
	}
#endif
	
	if (!gpio.set_output_parameters(scl_port, scl_pin, GPIO_FLOATING, GPIO_OPEN_DRAIN, GPIO_HIGH)) {
		Rcc::disablePort((RccPort) scl_port);
		Rcc::disablePort((RccPort) sda_port);
		return false;
	}
	
	if (!gpio.set_output_parameters(sda_port, sda_pin, GPIO_FLOATING, GPIO_OPEN_DRAIN, GPIO_HIGH)) {
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
	
	instance.active = true;
	return true;
}


// --- START MASTER ---
// Start I2C master mode on the target I2C peripheral.
static bool startMaster(I2C_devices device, I2C_modes mode) {
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
	instance.regs->CR1 = I2C_CR1_PE;
#endif
	
	return true;
}
	
	
	static bool setSlaveTarget(I2C_devices, uint8_t slave);
	static bool startSlave(I2C_devices device, uint8_t address);
	static bool sendI2C(I2C_devices, uint8_t byte);
	static bool stopI2C(I2C_devices);
