/*
	spi.cpp - Implementation file for the SPI class.
*/


#include <spi.h>


#ifdef NODATE_SPI_ENABLED


#include <gpio.h>


const int spi_count = 5;

// --- SPI DEVICES ---
SPI_device* SPI_list() {
	SPI_device item;
	static SPI_device spi_devices[spi_count];
	for (int i = 0; i < spi_count; ++i) {
		spi_devices[i] = item;
	}
	
#ifdef RCC_APB2ENR_SPI1EN
	spi_devices[SPI_1].regs = SPI1;
	spi_devices[SPI_1].irqType = SPI1_IRQn;
/* #elif defined RCC_APB1ENR1_I2C1EN
	spi_devices[SPI_1].regs = I2C1;
	spi_devices[SPI_1].irqType = I2C1_EV_IRQn; */
#endif

#ifdef RCC_APB1ENR_SPI2EN
	spi_devices[SPI_2].regs = SPI2;
	spi_devices[SPI_2].irqType = SPI2_IRQn;
/* #elif defined RCC_APB1ENR1_I2C2EN
	spi_devices[I2C_2].regs = I2C2;
	spi_devices[I2C_2].irqType = I2C2_EV_IRQn; */
#endif

#ifdef RCC_APB1ENR_SPI3EN
	spi_devices[SPI_3].regs = SPI3;
	spi_devices[SPI_3].irqType = SPI3_IRQn;
/* #elif defined RCC_APB1ENR1_I2C3EN
	spi_devices[I2C_3].regs = I2C3;
	spi_devices[I2C_3].irqType = I2C3_EV_IRQn; */
#endif

#ifdef RCC_APB2ENR_SPI4EN
	//
#endif

#ifdef RCC_APB2ENR_SPI5EN
	//
#endif
	
	return spi_devices;
}


SPI_device* spiList = SPI_list();


// --- START SPI MASTER ---
// Start the device in SPI mode.
bool SPI::startSPIMaster(SPI_devices device, SPI_pins pins) {
	SPI_device &instance = spiList[device];
	
	// Check status. Set parameters.
	if (instance.active) { return true; } // Already active.
	if (device == SPI_1) 		{ instance.per = RCC_SPI1; }
	else if (device == SPI_2)	{ instance.per = RCC_SPI2; }
	else if (device == SPI_3)	{ instance.per = RCC_SPI3; }
	else if (device == SPI_4)	{ instance.per = RCC_SPI4; }
	else if (device == SPI_5)	{ instance.per = RCC_SPI5; }
	
#if defined STM32F0 || defined STM32F1 || defined STM32F4
	// Configure GPIO pins: MOSI, MISO, SCLK, SS.
#ifdef STM32F1
	if (!GPIO::set_af(instance.per, pins.miso.af)) {
		return false;
	}
#endif

	if (!GPIO::set_af(pins.miso) || 
		!GPIO::set_af(pins.mosi) || 
		!GPIO::set_af(pins.sclk) || 
		!GPIO::set_af(pins.nss)) {
		return false;
	}
	
	// Set the pin parameters.
	if (!GPIO::set_output_parameters(pins.miso, GPIO_PULL_UP, GPIO_PUSH_PULL, GPIO_HIGH)) {
		return false;
	}
	
	if (!GPIO::set_output_parameters(pins.mosi, GPIO_FLOATING, GPIO_PUSH_PULL, GPIO_HIGH)) {
		return false;
	}
	
	if (!GPIO::set_output_parameters(pins.sclk, GPIO_FLOATING, GPIO_PUSH_PULL, GPIO_HIGH)) {
		return false;
	}
	
	if (!GPIO::set_output_parameters(pins.nss, GPIO_PULL_UP, GPIO_PUSH_PULL, GPIO_HIGH)) {
		return false;
	}
	
	// Enable the peripheral clock.
	// Start SPI device if needed.
	if (!instance.active) {
		if (!Rcc::enable(instance.per)) {
			// TODO: set status.
			return false;
		}
	}
	
	// Configure SPI peripheral.
	// TODO: enable configuring of CR1_BR for baud rates. Defaulting to Pclk/2.
#ifdef STM32F0
	uint32_t reg_cr1 = 0;
	reg_cr1 |= SPI_CR1_BR; // Use Fpclk / 256.
	instance.regs->CR1 = reg_cr1;
	
	// Use 8-bit mode.
	uint32_t reg_cr2 = 0;
	reg_cr2 = SPI_CR2_FRXTH | SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0;
	instance.regs->CR2 = reg_cr2;
#else
	// Configure CPOL & CPHA.
	// TODO: enable configuration. Use default (0 & 0) for now.
	
	// Configure DFF (data frame format). Default is 0x0 (8-bit).
	
	// Configure LSBFIRST. Default is 0x0 (MSB first).
	
	// Set CR2_FRF.
	// FIXME: make configurable. Default is 0x0 (Motorola). Other option is TI (0x1).
	
#endif
	// Set MSTR.
	// MSTR has to be set to enable Master mode. Default is slave mode.
	instance.regs->CR1 |= SPI_CR1_MSTR;
	
	// Set NSS as output. Disables multi-master mode.
	instance.regs->CR2 |= SPI_CR2_SSOE;
	
	// Enable peripheral (SPE).
	instance.regs->CR1 |= SPI_CR1_SPE;
	instance.active = true;
	
	return true;
#else
	return false;
#endif
}


// -- START I2S MASTER ---
// Starts the device in I2S configuration.
bool SPI::startI2SMaster(SPI_devices device, I2S_pins pins) {
	//
	
	return false;
}


// --- START SPI SLAVE ---
bool SPI::startSPISlave(SPI_devices device, SPI_pins pins) {
	//
	
	return false;
}


// --- START I2S SLAVE ---
bool SPI::startI2SSlave(SPI_devices device, I2S_pins pins) {
	//
	
	return false;
}


// -- SEND DATA ---
bool SPI::sendData(SPI_devices device, uint8_t* data, uint16_t len) {
	SPI_device &instance = spiList[device];
	
	// Write each byte into the DR register to transfer it.
	for (uint16_t i = 0; i < len; ++i) {
		// Check that the TX buffer is empty.
		uint32_t ts = McuCore::getSysTick();
		uint32_t timeout = 400; // TODO: make configurable.
		while ((instance.regs->SR & SPI_SR_TXE) != SPI_SR_TXE) {
			// Handle timeout.
			if (((McuCore::getSysTick() - ts) > timeout) || timeout == 0) {
				// TODO: set status.
				//printf("SPI TXE time-out.\n");
				return false;
			}
		}
		
		instance.regs->DR = data[i];
	}
	
	return true;
}


// --- RECEIVE DATA ---
bool SPI::receiveData(SPI_devices device, uint8_t* data, uint16_t count) {
	SPI_device &instance = spiList[device];
	
	for (uint8_t i = 0; i < count; ++i) {
        uint32_t timeout = 400;
		uint32_t ts = McuCore::getSysTick();
        // 1. Check SR_RXNE == 1. (Receive data register Not Empty).
        while ((instance.regs->SR & SPI_SR_RXNE) != SPI_SR_RXNE) {
			// Handle timeout.
			if (((McuCore::getSysTick() - ts) > timeout) || timeout == 0) {
				// TODO: set status.
				return false;
			}
        }
		
        // 2. Read DR contents into buffer.
		data[i] = (uint8_t) instance.regs->DR;
	}
	
	return false;
}


// --- STOP ---
// Stop the peripheral.
bool stop(SPI_devices device) {
	SPI_device &instance = spiList[device];
	
	// Check status.
	if (!instance.active) { return true; } // Already stopped.
	
	// Disable peripheral.
	instance.regs->CR1 &= ~SPI_CR1_SPE;
	
	return false;
}

#endif
