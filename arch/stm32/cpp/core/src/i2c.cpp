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
#if defined __stm32f0
	i2c_devices[I2C_1].irqType = I2C1_IRQn;
#else
	i2c_devices[I2C_1].irqType = I2C1_EV_IRQn;
#endif
#elif defined RCC_APB1ENR1_I2C1EN
	i2c_devices[I2C_1].regs = I2C1;
	i2c_devices[I2C_1].irqType = I2C1_EV_IRQn;
#endif

#ifdef RCC_APB1ENR_I2C2EN
	i2c_devices[I2C_2].regs = I2C2;
#if defined __stm32f0
	i2c_devices[I2C_2].irqType = I2C2_IRQn;
#else
	i2c_devices[I2C_2].irqType = I2C2_EV_IRQn;
#endif
#elif defined RCC_APB1ENR1_I2C2EN
	i2c_devices[I2C_2].regs = I2C2;
	i2c_devices[I2C_2].irqType = I2C2_EV_IRQn;
#endif

#ifdef RCC_APB1ENR_I2C3EN
	i2c_devices[I2C_3].regs = I2C3;
#if defined __stm32f0
	i2c_devices[I2C_3].irqType = I2C3_IRQn;
#else
	i2c_devices[I2C_3].irqType = I2C3_EV_IRQn;
#endif
#elif defined RCC_APB1ENR1_I2C3EN
	i2c_devices[I2C_3].regs = I2C3;
	i2c_devices[I2C_3].irqType = I2C3_EV_IRQn;
#endif
	
	return i2c_devices;
}


// FIXME: hard-coding I2C timings isn't ideal. Neither is dynamically calculating them.
uint32_t i2c_timings_4[4];
uint32_t i2c_timings_8[4];
uint32_t i2c_timings_16[4];
uint32_t i2c_timings_48[4];
uint32_t i2c_timings_54[4];

bool I2C_timings() {
#if !defined __stm32f1 && !defined __stm32f4
	// 4khz and 54khz timings are based on max rise and fall times
	i2c_timings_4[0] = 0x004091F3;
	i2c_timings_4[1] = 0x00400D10;
	i2c_timings_4[2] = 0x00100002;
	i2c_timings_4[3] = 0x00000001;
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
	i2c_timings_54[0] = 0xD0417BFF;
	i2c_timings_54[1] = 0x40D32A31;
	i2c_timings_54[2] = 0x10A60D20;
	i2c_timings_54[3] = 0x00900916;
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

extern "C" {
	void I2C2_IRQHandler(void);
}

extern "C" {
	void I2C3_IRQHandler(void);
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

void I2C2_IRQHandler(void) {
	I2C_device &instance = i2cList[1];

	// Verify interrupt status.
	if ((instance.regs->ISR & I2C_ISR_RXNE) == I2C_ISR_RXNE) {
		// Read byte (which clears RXNE flag).
		i2c_rxb = instance.regs->RXDR;
		instance.callback(i2c_rxb);
	}
}

void I2C3_IRQHandler(void) {
	I2C_device &instance = i2cList[2];

	// Verify interrupt status.
	if ((instance.regs->ISR & I2C_ISR_RXNE) == I2C_ISR_RXNE) {
		// Read byte (which clears RXNE flag).
		i2c_rxb = instance.regs->RXDR;
		instance.callback(i2c_rxb);
	}
}

#elif defined __stm32f1 || defined __stm32f4
extern "C" {
	void I2C1_EV_IRQHandler(void);
	void I2C2_EV_IRQHandler(void);
	void I2C3_EV_IRQHandler(void);
}

// three counters are used as all I2Cx peripheral may be used simultaneously
volatile uint8_t NumByteToReadI2C1;
volatile uint8_t NumByteToReadI2C2;
volatile uint8_t NumByteToReadI2C3;
volatile uint8_t Address;
volatile uint8_t Rx_Idx1 = 0;
volatile uint8_t Rx_Idx2 = 0;
volatile uint8_t Rx_Idx3 = 0;
volatile uint8_t Buffer_Rx1[255];
volatile uint8_t Buffer_Rx2[255];
volatile uint8_t Buffer_Rx3[255];

/**
 * \brief       Interrupt service routine for I2C1
 *
 * Adapted from STMicro Application Note AN2824, "STM32F10xxx
 * I2C optimized examples"
 *
 */

void I2C1_EV_IRQHandler(void) {
	I2C_device &instance = i2cList[0];
	/* The following must remain volatile.  Optimization may result in unexpected
	 * register reads that can cause unplanned interrupts
	 */
	volatile uint32_t SR1Register = 0;
	volatile uint32_t SR2Register = 0;
	/* Read the SR1 and SR2 status registers */
	SR1Register = instance.regs->SR1;
	SR2Register = instance.regs->SR2;

	/* If SB = 1, I2C1 master sent a START on the bus: EV5) */
	if ((SR1Register & 0x0001) == 0x0001) {

		/* Send the slave address for transmssion or for reception (according to the configured value
		 in the write master write routine */
		instance.regs->DR = Address;
		SR1Register = 0;
		SR2Register = 0;
	}
	/* If I2C1 is Master (MSL flag = 1) */

	if ((SR2Register & 0x0001) == 0x0001) {
		/* If ADDR = 1, EV6 */
		if ((SR1Register & 0x0002) == 0x0002) {
			/* Master Receiver */
			/* Initialize Receive counter */
			Rx_Idx1 = 0;
			/* At this stage, ADDR is cleared because both SR1 and SR2 were read.*/
			/* EV6_1: used for single byte reception. The ACK disable and the STOP
			 Programming should be done just after ADDR is cleared. */
			if (NumByteToReadI2C1 == 1) {
				/* Clear ACK */
				instance.regs->CR1 &= ~I2C_CR1_ACK;
				/* Program the STOP */
				instance.regs->CR1 |= I2C_CR1_STOP;
			}
			SR1Register = 0;
			SR2Register = 0;

		}
		/* If RXNE is set */
		if ((SR1Register & 0x0040) == 0x0040) {
			/* Read the data register */
			Buffer_Rx1[Rx_Idx1++] = instance.regs->DR;
			/* Decrement the number of bytes to be read */
			NumByteToReadI2C1--;
			/* If it remains only one byte to read, disable ACK and program the STOP (EV7_1) */
			if (NumByteToReadI2C1 == 1) {
				/* Clear ACK */
				instance.regs->CR1 &= ~I2C_CR1_ACK;
				/* Program the STOP */
				instance.regs->CR1 |= I2C_CR1_STOP;
			}
			SR1Register = 0;
			SR2Register = 0;
		}

	}

	// Verify interrupt status.
	if ((instance.regs->SR1 & I2C_SR1_RXNE) == I2C_SR1_RXNE) {
		// Read byte (which clears RXNE flag).
		i2c_rxb = instance.regs->DR;
		instance.callback(i2c_rxb);
	}
}


/**
 * \brief       Interrupt service routine for I2C2
 *
 * Adapted from STMicro Application Note AN2824, "STM32F10xxx
 * I2C optimized examples"
 *
 */
void I2C2_EV_IRQHandler(void) {
	I2C_device &instance = i2cList[1];
	/* The following must remain volatile.  Optimization may result in unexpected
	 * register reads that can cause unplanned interrupts
	 */
	volatile uint32_t SR1Register = 0;
	volatile uint32_t SR2Register = 0;
	/* Read the SR1 and SR2 status registers */
	SR1Register = instance.regs->SR1;
	SR2Register = instance.regs->SR2;

	/* If SB = 1, I2C2 master sent a START on the bus: EV5) */
	if ((SR1Register & 0x0001) == 0x0001) {

		/* Send the slave address for transmssion or for reception (according to the configured value
		 in the write master write routine */
		instance.regs->DR = Address;
		SR1Register = 0;
		SR2Register = 0;
	}
	/* If I2C2 is Master (MSL flag = 1) */

	if ((SR2Register & 0x0001) == 0x0001) {
		/* If ADDR = 1, EV6 */
		if ((SR1Register & 0x0002) == 0x0002) {
			/* Master Receiver */
			/* Initialize Receive counter */
			Rx_Idx2 = 0;
			/* At this stage, ADDR is cleared because both SR1 and SR2 were read.*/
			/* EV6_1: used for single byte reception. The ACK disable and the STOP
			 Programming should be done just after ADDR is cleared. */
			if (NumByteToReadI2C2 == 1) {
				/* Clear ACK */
				instance.regs->CR1 &= ~I2C_CR1_ACK;
				/* Program the STOP */
				instance.regs->CR1 |= I2C_CR1_STOP;
			}
			SR1Register = 0;
			SR2Register = 0;

		}
		/* If RXNE is set */
		if ((SR1Register & 0x0040) == 0x0040) {
			/* Read the data register */
			Buffer_Rx2[Rx_Idx2++] = instance.regs->DR;
			/* Decrement the number of bytes to be read */
			NumByteToReadI2C2--;
			/* If it remains only one byte to read, disable ACK and program the STOP (EV7_1) */
			if (NumByteToReadI2C2 == 1) {
				/* Clear ACK */
				instance.regs->CR1 &= ~I2C_CR1_ACK;
				/* Program the STOP */
				instance.regs->CR1 |= I2C_CR1_STOP;
			}
			SR1Register = 0;
			SR2Register = 0;
		}

	}

	// Verify interrupt status.
	if ((instance.regs->SR1 & I2C_SR1_RXNE) == I2C_SR1_RXNE) {
		// Read byte (which clears RXNE flag).
		i2c_rxb = instance.regs->DR;
		instance.callback(i2c_rxb);
	}
}


/**
 * \brief       Interrupt service routine for I2C3
 *
 * Adapted from STMicro Application Note AN2824, "STM32F10xxx
 * I2C optimized examples"
 *
 */
void I2C3_EV_IRQHandler(void) {
	I2C_device &instance = i2cList[2];
	/* The following must remain volatile.  Optimization may result in unexpected
	 * register reads that can cause unplanned interrupts
	 */
	volatile uint32_t SR1Register = 0;
	volatile uint32_t SR2Register = 0;
	/* Read the SR1 and SR2 status registers */
	SR1Register = instance.regs->SR1;
	SR2Register = instance.regs->SR2;

	/* If SB = 1, I2C3 master sent a START on the bus: EV5) */
	if ((SR1Register & 0x0001) == 0x0001) {

		/* Send the slave address for transmssion or for reception (according to the configured value
		 in the write master write routine */
		instance.regs->DR = Address;
		SR1Register = 0;
		SR2Register = 0;
	}
	/* If I2C3 is Master (MSL flag = 1) */

	if ((SR2Register & 0x0001) == 0x0001) {
		/* If ADDR = 1, EV6 */
		if ((SR1Register & 0x0002) == 0x0002) {
			/* Master Receiver */
			/* Initialize Receive counter */
			Rx_Idx3 = 0;
			/* At this stage, ADDR is cleared because both SR1 and SR2 were read.*/
			/* EV6_1: used for single byte reception. The ACK disable and the STOP
			 Programming should be done just after ADDR is cleared. */
			if (NumByteToReadI2C3 == 1) {
				/* Clear ACK */
				instance.regs->CR1 &= ~I2C_CR1_ACK;
				/* Program the STOP */
				instance.regs->CR1 |= I2C_CR1_STOP;
			}
			SR1Register = 0;
			SR2Register = 0;

		}
		/* If RXNE is set */
		if ((SR1Register & 0x0040) == 0x0040) {
			/* Read the data register */
			Buffer_Rx3[Rx_Idx3++] = instance.regs->DR;
			/* Decrement the number of bytes to be read */
			NumByteToReadI2C3--;
			/* If it remains only one byte to read, disable ACK and program the STOP (EV7_1) */
			if (NumByteToReadI2C3 == 1) {
				/* Clear ACK */
				instance.regs->CR1 &= ~I2C_CR1_ACK;
				/* Program the STOP */
				instance.regs->CR1 |= I2C_CR1_STOP;
			}
			SR1Register = 0;
			SR2Register = 0;
		}

	}

	// Verify interrupt status.
	if ((instance.regs->SR1 & I2C_SR1_RXNE) == I2C_SR1_RXNE) {
		// Read byte (which clears RXNE flag).
		i2c_rxb = instance.regs->DR;
		instance.callback(i2c_rxb);
	}
}

#else
extern "C" {
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
}
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
	if (!GPIO::set_af(scl_port, scl_pin, instance.per, scl_af, GPIO_OPEN_DRAIN)) {
		Rcc::disablePort((RccPort) scl_port);
		return false;
	}

	if (!GPIO::set_af(sda_port, sda_pin, instance.per, sda_af, GPIO_OPEN_DRAIN)) {
		Rcc::disablePort((RccPort) scl_port);
		Rcc::disablePort((RccPort) sda_port);
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

	if (!GPIO::set_output_parameters(scl_port, scl_pin, GPIO_PULL_UP, GPIO_OPEN_DRAIN, GPIO_HIGH)) {
		Rcc::disablePort((RccPort) scl_port);
		Rcc::disablePort((RccPort) sda_port);
		return false;
	}
	
	if (!GPIO::set_output_parameters(sda_port, sda_pin, GPIO_PULL_UP, GPIO_OPEN_DRAIN, GPIO_HIGH)) {
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

	// Software Reset.
	instance.regs->CR1 &= ~I2C_CR1_PE;	// Disable peripheral.

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
#if defined STM32F0 || defined STM32F1
	#define HSI_VALUE    ((uint32_t)8000000)
#elif defined STM32F4 || defined STM32L4 || defined STM32F7
	#define HSI_VALUE    ((uint32_t)16000000)
#endif

	// Note that the STM32F1 and STM32F4 (with one exception) series do not support Fast+ mode
#if defined STM32F1 || defined STM32F4
	// Disable I2C
	instance.regs->CR1 &= ~(I2C_CR1_PE);
	/*Reset I2C*/
	instance.regs->CR1 |= I2C_CR1_SWRST;
	instance.regs->CR1 &= ~(I2C_CR1_SWRST);
	// Get PCLK1 frequency
	uint32_t pclk1 = SystemCoreClock >> APBPrescTable[((RCC->CFGR & RCC_CFGR_PPRE1) >> RCC_CFGR_PPRE1_Pos)];
	// Calculate peripheral frequency range in Mhz
	uint32_t freqrange = pclk1/1000000U;
	if (freqrange > 50U) return false;  // max freq is 50 Mhz
	// Check the minimum allowed PCLK1 frequency (dependent on I2C speed)
	switch (mode) {
	case I2C_MODE_SM10:
	case I2C_MODE_SM100:
		if (freqrange < 2U)
			return false;
		break;
	case I2C_MODE_FM:
		if (freqrange < 4U)
			return false;
		break;
	default:
		return false;
	}
	// configure the frequency range in the CR2 register
	instance.regs->CR2 &= ~(I2C_CR2_FREQ);
	instance.regs->CR2 |= (freqrange << I2C_CR2_FREQ_Pos);
	// configure rise time in TRISE register
	uint32_t riseTime;
	switch (mode) {
	case I2C_MODE_SM10:
	case I2C_MODE_SM100:
		instance.regs->TRISE &= ~(I2C_TRISE_TRISE);
		instance.regs->TRISE |= (freqrange + 1) << I2C_TRISE_TRISE_Pos;
		break;
	case I2C_MODE_FM:
		instance.regs->TRISE &= ~(I2C_TRISE_TRISE);
		instance.regs->TRISE |= (((freqrange * 300) / 1000) + 1) << I2C_TRISE_TRISE_Pos;
		break;
	default:
		return false;
	}
	// configure Speed in CCR register
	instance.regs->CCR &= ~(I2C_CCR_FS);
	uint32_t pclk1Period;
	uint32_t ccr;
	switch(mode) {
		case I2C_MODE_SM10:
			// at 10 Khz and a default duty cycle of 50%, Thigh = Tlow = ~50us = 50000ns
			pclk1Period = 1000/freqrange;
			ccr = (50000u / pclk1Period)+1;  // round up to prevent overspeed
			if (ccr < 4u) ccr = 4u;
		case I2C_MODE_SM100:
			// at 100 Khz and a default duty cycle of 50%, Thigh = Tlow = ~5us =  5000ns
			// these are acceptable per datasheet
			pclk1Period = 1000/freqrange;
			ccr = (5000u / pclk1Period)+1;  // round up to prevent overspeed
			if (ccr < 4u) ccr = 4u;
			break;
		case I2C_MODE_FM:
			instance.regs->CCR |= I2C_CCR_FS;
			instance.regs->CCR |= I2C_CCR_DUTY;
			// at 400 Khz and Thigh/Tlow = 19/6, I2C period = Thigh+Tlow = 250 ns
			pclk1Period = 1000/freqrange;
			ccr = (250u / ((19+6)*pclk1Period))+1;  // round up to prevent overspeed
			if (ccr < 1u) ccr = 1u;
			break;
		default:
			// should have already been caught by earlier case statements, but just in case ...
			return false;
	}
	instance.regs->CCR &= ~(I2C_CCR_CCR);
	instance.regs->CCR |= ccr << I2C_CCR_CCR_Pos;
	// Enable I2C
	instance.regs->CR1 |= I2C_CR1_PE;
#else
	uint32_t i2cClock;
	uint32_t divisor;
	// Check status. Set parameters.
	if (!instance.active) { return false; } // Interface isn't active yet.
	
	// Determine I2C clock source and frequency
	divisor = (RCC->CFGR & RCC_CFGR_HPRE_Msk) >> RCC_CFGR_HPRE_Pos;
	if (divisor != 0) {
		divisor = divisor - 7;
		if (divisor > 4) divisor++;
		i2cClock = SystemCoreClock >> divisor;
	}
	else {
		i2cClock = SystemCoreClock;
	}
#if defined STM32F0
	divisor = (RCC->CFGR & RCC_CFGR_PPRE_Msk) >> RCC_CFGR_PPRE_Pos;
#else
	divisor = (RCC->CFGR & RCC_CFGR_PPRE1_Msk) >> RCC_CFGR_PPRE1_Pos;
#endif
	if (divisor != 0) {
		divisor = divisor - 3;
		i2cClock = i2cClock >> divisor;
	}
#if defined STM32F0
	if (device == I2C_1) {
		i2cClock = HSI_VALUE;
	}
#endif
	// Set timing register.
	if (i2cClock == 4000000) {
		instance.regs->TIMINGR = i2c_timings_4[mode];
	}
	else if (i2cClock == 8000000) {
		instance.regs->TIMINGR = i2c_timings_8[mode];
	}
	else if (i2cClock == 16000000) {
		instance.regs->TIMINGR = i2c_timings_16[mode];
	}
	else if (i2cClock == 48000000) {
		instance.regs->TIMINGR = i2c_timings_48[mode];
	}
	else if (i2cClock == 54000000) {
		instance.regs->TIMINGR = i2c_timings_54[mode];
	}
	else {
		// Unavailable timing for this system clock.
		return false;
	}
	// Enable interrupts on peripheral.
	instance.regs->CR1 |= I2C_CR1_RXIE;
#endif

	// Enable peripheral.
	instance.regs->CR1 |= I2C_CR1_PE;
	
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


//#include <printf.h>


// --- SEND TO SLAVE ---
// Send length bytes on the I2C bus to the set Slave address.
bool I2C::sendToSlave(I2C_devices device, uint8_t* data, uint16_t len) {
	I2C_device &instance = i2cList[device];
#if defined STM32F1 || defined STM32F4
	/*
	 * Adapted from STMicro Application Note AN2824, "STM32F10xxx
	 * I2C optimized examples"
	 */
	
	/* Save EVT IT state and disable temporarily */
	uint32_t CR2Saved = instance.regs->CR2 & I2C_CR2_ITEVTEN;
	instance.regs->CR2 &= ~(I2C_CR2_ITEVTEN);

	uint32_t temp = 0;
	uint32_t Timeout;
	uint8_t SlaveAddress = instance.slaveTarget << 1;
	uint8_t Address;
	Timeout = 0xFFFF;
	uint32_t NumByteToWrite = len;
	/* Send START condition */
	instance.regs->CR1 |= I2C_CR1_START;
	/* Wait until SB flag is set: EV5 */
	while ((instance.regs->SR1&0x0001) != 0x0001)
	{
		if (Timeout-- == 0)
			return false;
	}

	/* Send slave address */
	/* Reset the address bit0 for write*/
	SlaveAddress &= ~I2C_OAR1_ADD0;
	Address = SlaveAddress;
	/* Send the slave address */
	instance.regs->DR = Address;
	Timeout = 0xFFFF;
	/* Wait until ADDR is set: EV6 */
	while ((instance.regs->SR1 &0x0002) != 0x0002)
	{
		if (Timeout-- == 0)
			return false;
	}

	/* Clear ADDR flag by reading SR2 register */
	temp = instance.regs->SR2;
	/* Write the first data in DR register (EV8_1) */
	instance.regs->DR = *data;
	/* Increment */
	data++;
	/* Decrement the number of bytes to be written */
	NumByteToWrite--;
	/* While there is data to be written */
	while (NumByteToWrite--)
	{
		/* Poll on BTF to receive data because in polling mode we can not guarantee the
		  EV8 software sequence is managed before the current byte transfer completes */
		while ((instance.regs->SR1 & 0x00004) != 0x000004);
		/* Send the current byte */
		instance.regs->DR = *data;
		/* Point to the next byte to be written */
		data++;
	}
	/* EV8_2: Wait until BTF is set before programming the STOP */
	while ((instance.regs->SR1 & 0x00004) != 0x000004);
	/* Send STOP condition */
	instance.regs->CR1 |= I2C_CR1_STOP;
	/* Make sure that the STOP bit is cleared by Hardware */
	while ((instance.regs->CR1&0x200) == 0x200);
	
	/* Restore EVT IT state  */
	instance.regs->CR2 &= CR2Saved;

#else
	uint32_t cr2_reg = 0;
    cr2_reg |= (instance.slaveTarget << 1);
	if (len > 0xff) {
		// Set RELOAD so that we can transmit more data after finishing a transfer cycle.
		// Set NBYTES to the max value (0xff).
		cr2_reg |= I2C_CR2_RELOAD;
		cr2_reg |= (0xff << 16);
		//printf("Set reload.\n");
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
			//instance.regs->CR2 |= I2C_CR2_AUTOEND;
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
					//printf("I2C TXIS timeout.\n");
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
		if (bytesToWrite == 0) {
			// 5. Transfer complete. Wait for STOP flag & clear it.
			uint32_t timeout = 400; // TODO: make configurable.
			uint32_t ts = McuCore::getSysTick();
			while ((instance.regs->ISR & I2C_ISR_STOPF) != I2C_ISR_STOPF) {
				// Handle timeout.
				if (((McuCore::getSysTick() - ts) > timeout) || timeout == 0) {
					// TODO: set status.
					//printf("I2C STOPF timeout.\n");
					return false;
				}
			}
			
			instance.regs->ICR |= I2C_ICR_STOPCF;
			instance.regs->CR2 = 0x0; // Reset CR2 register.
			
			return true;
		}
		else {
			// Restart session since data is left. Transfer Complete Reload.
			//if ((instance.regs->ISR & I2C_ISR_TCR) == I2C_ISR_TCR) {
			
			// Remaining data fits in a single transfer. Disable reload.
			if (bytesToWrite < 256 && bytesToWrite > 0) {
				instance.regs->CR2 &= ~I2C_CR2_RELOAD;
				instance.regs->CR2 &= ~(0xff << 16);
				instance.regs->CR2 |= I2C_CR2_AUTOEND | (uint32_t) (bytesToWrite << 16);
				//printf("Unset reload.\n");
			}
			else if (bytesToWrite > 256) {
				// Set reload and NBYTES.
				instance.regs->CR2 |= I2C_CR2_RELOAD | (0xff << 16);
			}	
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
#if defined STM32F1 || defined STM32F4
	I2C::sendToSlave(device, &data, 1);
#else
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
			//printf("I2C timeout.\n");
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
#if defined STM32F1 || defined STM32F4
	I2C::sendToSlave(device, data, len);
#else
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
				//printf("I2C timeout. Return false.\n");
				return false;
			}
		}
		
		// 3. Write data into TXDR.
		instance.regs->TXDR = data[i];
	}
	
	return true;
#endif
	return false;
}


// --- SEND TO SLAVE END ---
bool I2C::sendToSlaveEnd(I2C_devices device) {
	I2C_device &instance = i2cList[device];
#if defined STM32F1 || defined STM32F4
	instance.regs->CR1 |= I2C_CR1_STOP;
#else
	// If ISR_TC == 1, we're done. (Transfer Complete).
	uint32_t timeout = 400; // TODO: make configurable.
	uint32_t ts = McuCore::getSysTick();
	while ((instance.regs->ISR & I2C_ISR_TC) != I2C_ISR_TC) {
		// Handle timeout.
		if (((McuCore::getSysTick() - ts) > timeout) || timeout == 0) {
			// TODO: set status.
			//printf("I2C TC timeout.\n");
			return false;
		}
	}
	
	// Transfer complete. Set STOP flag, wait for it to be set & clear it.
	instance.regs->CR2 |= I2C_CR2_STOP;

	ts = McuCore::getSysTick();
	while ((instance.regs->ISR & I2C_ISR_STOPF) != I2C_ISR_STOPF) {
		// Handle timeout.
		if (((McuCore::getSysTick() - ts) > timeout) || timeout == 0) {
			// TODO: set status.
			//printf("I2C timeout.\n");
			return false;
		}
	}
	
	instance.regs->ICR |= I2C_ICR_STOPCF;
	instance.regs->CR2 = 0x0;
#endif
	return true;
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
	
	/* Disable interrupt if is enabled. An active interrupt handler that reads the RXDR register field will automatically
	   reset the RXNE flag, preventing this routine from being notified that data is ready in the data register.
	*/
	bool reEnableIRQ = false;
	if (NVIC_GetEnableIRQ(instance.irqType) == 1) {
		NVIC_DisableIRQ(instance.irqType);
		reEnableIRQ = true;
	}
	
#if defined STM32F1 || defined STM32F4
	/*
	 * Adapted from STMicro Application Note AN2824, "STM32F10xxx
	 * I2C optimized examples"
	 */
	uint32_t NumByteToRead = count;
	uint32_t temp = 0;
	uint32_t Timeout = 0;
	uint8_t SlaveAddress = instance.slaveTarget << 1;
	uint8_t Address;
	if (NumByteToRead == 1)
	{
		Timeout = 0xFFFF;
		/* Send START condition */
		instance.regs->CR1 |= I2C_CR1_START;
		/* Wait until SB flag is set: EV5  */
		while ((instance.regs->SR1&0x0001) != 0x0001)
		{
			if (Timeout-- == 0)
				return false;
		}
		/* Send slave address */
		/* Set the address bit0 for read */
		SlaveAddress |= I2C_OAR1_ADD0;
		Address = SlaveAddress;
		/* Send the slave address */
		instance.regs->DR = Address;
		/* Wait until ADDR is set: EV6_3, then program ACK = 0, clear ADDR
		and program the STOP just after ADDR is cleared. The EV6_3
		software sequence must complete before the current byte end of transfer.*/
		/* Wait until ADDR is set */
		Timeout = 0xFFFF;
		while ((instance.regs->SR1&0x0002) != 0x0002)
		{
			if (Timeout-- == 0)
				return false;
		}
		/* Clear ACK bit */
		instance.regs->CR1 &= ~I2C_CR1_ACK;
		/* Disable all active IRQs around ADDR clearing and STOP programming because the EV6_3
		software sequence must complete before the current byte end of transfer */
		__disable_irq();
		/* Clear ADDR flag */
		temp = instance.regs->SR2;
		/* Program the STOP */
		instance.regs->CR1 |= I2C_CR1_STOP;
		/* Re-enable IRQs */
		__enable_irq();
		/* Wait until a data is received in DR register (RXNE = 1) EV7 */
		while ((instance.regs->SR1 & 0x00040) != 0x000040);
		/* Read the data */
		*buffer = instance.regs->DR;
		/* Make sure that the STOP bit is cleared by Hardware before CR1 write access */
		while ((instance.regs->CR1&0x200) == 0x200);
		/* Enable Acknowledgement to be ready for another reception */
		instance.regs->CR1 |= I2C_CR1_ACK;

	}

	else if (NumByteToRead == 2)
	{
		/* Set POS bit */
		instance.regs->CR1 |= I2C_CR1_POS;
		Timeout = 0xFFFF;
		/* Send START condition */
		instance.regs->CR1 |= I2C_CR1_START;
		/* Wait until SB flag is set: EV5 */
		while ((instance.regs->SR1&0x0001) != 0x0001)
		{
			if (Timeout-- == 0)
				return false;
		}
		Timeout = 0xFFFF;
		/* Send slave address */
		/* Set the address bit0 for read */
		SlaveAddress |= I2C_OAR1_ADD0;
		Address = SlaveAddress;
		/* Send the slave address */
		instance.regs->DR = Address;
		/* Wait until ADDR is set: EV6 */
		while ((instance.regs->SR1&0x0002) != 0x0002)
		{
			if (Timeout-- == 0)
				return false;
		}
		/* EV6_1: The acknowledge disable should be done just after EV6,
		that is after ADDR is cleared, so disable all active IRQs around ADDR clearing and
		ACK clearing */
		__disable_irq();
		/* Clear ADDR by reading SR2 register  */
		temp = instance.regs->SR2;
		/* Clear ACK */
		instance.regs->CR1 &= ~I2C_CR1_ACK;
		/*Re-enable IRQs */
		__enable_irq();
		/* Wait until BTF is set */
		while ((instance.regs->SR1 & 0x00004) != 0x000004);
		/* Disable IRQs around STOP programming and data reading because of the limitation ?*/
		__disable_irq();
		/* Program the STOP */
		instance.regs->CR1 |= I2C_CR1_STOP;
		/* Read first data */
		*buffer = instance.regs->DR;
		/* Re-enable IRQs */
		__enable_irq();
		/**/
		buffer++;
		/* Read second data */
		*buffer = instance.regs->DR;
		/* Make sure that the STOP bit is cleared by Hardware before CR1 write access */
		while ((instance.regs->CR1&0x200) == 0x200);
		/* Enable Acknowledgement to be ready for another reception */
		instance.regs->CR1  |= I2C_CR1_ACK;
		/* Clear POS bit */
		instance.regs->CR1  &= ~I2C_CR1_POS;

	}

	else

	{

		Timeout = 0xFFFF;
		/* Send START condition */
		instance.regs->CR1 |= I2C_CR1_START;
		/* Wait until SB flag is set: EV5 */
		while ((instance.regs->SR1&0x0001) != 0x0001)
		{
			if (Timeout-- == 0)
				return false;
		}
		Timeout = 0xFFFF;
		/* Send slave address */
		/* Set the address bit0 for read */
		SlaveAddress |= I2C_OAR1_ADD0;;
		Address = SlaveAddress;
		/* Send the slave address */
		instance.regs->DR = Address;
		/* Wait until ADDR is set: EV6 */
		while ((instance.regs->SR1&0x0002) != 0x0002)
		{
			if (Timeout-- == 0)
				return false;
		}
		/* Clear ADDR by reading SR2 status register */
		temp = instance.regs->SR2;
		/* While there is data to be read */
		while (NumByteToRead)
		{
			/* Receive bytes from first byte until byte N-3 */
			if (NumByteToRead != 3)
			{
				/* Poll on BTF to receive data because in polling mode we can not guarantee the
				EV7 software sequence is managed before the current byte transfer completes */
				while ((instance.regs->SR1 & 0x00004) != 0x000004);
				/* Read data */
				*buffer = instance.regs->DR;
				/* */
				buffer++;
				/* Decrement the read bytes counter */
				NumByteToRead--;
			}

			/* it remains to read three data: data N-2, data N-1, Data N */
			if (NumByteToRead == 3)
			{

				/* Wait until BTF is set: Data N-2 in DR and data N -1 in shift register */
				while ((instance.regs->SR1 & 0x00004) != 0x000004);
				/* Clear ACK */
				instance.regs->CR1 &= ~I2C_CR1_ACK;

				/* Disable IRQs around data reading and STOP programming because of the
				limitation ? */
				__disable_irq();
				/* Read Data N-2 */
				*buffer = instance.regs->DR;
				/* Increment */
				buffer++;
				/* Program the STOP */
				instance.regs->CR1 |= I2C_CR1_STOP;
				/* Read DataN-1 */
				*buffer = instance.regs->DR;
				/* Re-enable IRQs */
				__enable_irq();
				/* Increment */
				buffer++;
				/* Wait until RXNE is set (DR contains the last data) */
				while ((instance.regs->SR1 & 0x00040) != 0x000040);
				/* Read DataN */
				*buffer = instance.regs->DR;
				/* Reset the number of bytes to be read by master */
				NumByteToRead = 0;

			}
		}
		/* Make sure that the STOP bit is cleared by Hardware before CR1 write access */
		while ((instance.regs->CR1&0x200) == 0x200);
		/* Enable Acknowledgement to be ready for another reception */
		instance.regs->CR1 |= I2C_CR1_ACK;

	}
#else
    
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
	/* if ((instance.regs->ISR & I2C_ISR_TC) == I2C_ISR_TC) {
		// TODO: restart session.
	} */
	
	// Wait for the STOP condition to be generated and flag set.
	uint32_t timeout = 400;
	uint32_t ts = McuCore::getSysTick();
	while ((instance.regs->ISR & I2C_ISR_STOPF) != I2C_ISR_STOPF) {
		// Handle timeout.
		if (((McuCore::getSysTick() - ts) > timeout) || timeout == 0) {
			// TODO: set status.
			//printf("I2C STOPF timeout.\n");
			return false;
		}
	}
	
	// Clear STOP flag and clear CR2 register.
	instance.regs->ICR |= I2C_ICR_STOPCF;
	instance.regs->CR2 = 0x0;
#endif
	
	// Re-enable interrupt.
	if (reEnableIRQ) {
		NVIC_EnableIRQ(instance.irqType);
	}
	return true;
}


// --- RECEIVE FROM SLAVE ---
bool I2C::receiveFromSlave(I2C_devices device, uint8_t len) {
    uint32_t timeOut = (uint32_t) 0x1000;
    I2C_device &instance = i2cList[device];
#if defined STM32F1 || defined STM32F4
	uint8_t SlaveAddress = instance.slaveTarget << 1;
	/* Enable EVT IT*/
	instance.regs->CR2 |= I2C_CR2_ITEVTEN;
	/* Enable BUF IT */
	instance.regs->CR2 |= I2C_CR2_ITBUFEN;
	/* Set the I2C direction to reception */
	//I2CDirection = I2C_DIRECTION_RX;
	SlaveAddress |= I2C_OAR1_ADD0;
	Address = SlaveAddress;
	if (instance.regs == I2C1)    NumByteToReadI2C1 = len;
	else if (instance.regs == I2C2)    NumByteToReadI2C2 = len;
	else NumByteToReadI2C3 = len;
	/* Send START condition */
	instance.regs->CR1 |= I2C_CR1_START;
	/* Wait until the START condition is generated on the bus: START bit is cleared by hardware */
	while ((instance.regs->CR1&0x100) == 0x100);
	/* Wait until BUSY flag is reset (until a STOP is generated) */
	while ((instance.regs->SR2 &0x0002) == 0x0002);
	/* Enable Acknowledgement to be ready for another reception */
	instance.regs->CR1 |= I2C_CR1_ACK;
#else
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
	instance.regs->CR1 &= ~I2C_CR1_PE;

	// Disable interrupt.
	NVIC_DisableIRQ(instance.irqType);
	
	return true;
}


#endif
