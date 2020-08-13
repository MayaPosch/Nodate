/*
	rcc.cpp - Implementation for RCC functionality.
	
*/


#include "rcc.h"

#include <limits>


// The maximum handles per port or peripheral is determined by the counter type in the item struct.
// If changed, the counter type should be updated both in the type definition and here.
static const uint8_t handle_max = std::numeric_limits<uint8_t>::max();


// Private methods:

// --- PORT HANDLES ---
std::vector<RccPortHandle>& Rcc::portHandles() {
	static std::vector<RccPortHandle>* portHandlesStatic = new std::vector<RccPortHandle>();
	
	RccPortHandle handle;
#ifdef RCC_AHBENR_GPIOAEN
	handle.exists = true;
	handle.enable = RCC_AHBENR_GPIOAEN;
#else
	handle.exists = false;
#endif
	portHandlesStatic->push_back(handle);

#ifdef RCC_AHBENR_GPIOBEN
	handle.exists = true;
	handle.enable = RCC_AHBENR_GPIOBEN;
#else
	handle.exists = false;
#endif
	portHandlesStatic->push_back(handle);

#ifdef RCC_AHBENR_GPIOCEN
	handle.exists = true;
	handle.enable = RCC_AHBENR_GPIOCEN;
#else
	handle.exists = false;
#endif
	portHandlesStatic->push_back(handle);

#ifdef RCC_AHBENR_GPIODEN
	handle.exists = true;
	handle.enable = RCC_AHBENR_GPIODEN;
#else
	handle.exists = false;
#endif
	portHandlesStatic->push_back(handle);

#ifdef RCC_AHBENR_GPIOEEN
	handle.exists = true;
	handle.enable = RCC_AHBENR_GPIOEEN;
#else
	handle.exists = false;
#endif
	portHandlesStatic->push_back(handle);

#ifdef RCC_AHBENR_GPIOFEN
	handle.exists = true;
	handle.enable = RCC_AHBENR_GPIOFEN;
#else
	handle.exists = false;
#endif
	portHandlesStatic->push_back(handle);
	
	return *portHandlesStatic;
}


// --- PERIPHERAL HANDLES ---
std::vector<RccPeripheralHandle>& Rcc::peripheralHandles() {
	static std::vector<RccPeripheralHandle>* peripheralHandlesStatic = new std::vector<RccPeripheralHandle>();
	
	// AHB
	
	RccPeripheralHandle handle;
#ifdef RCC_AHBENR_TSCEN
	handle.exists = true;
	handle.enr = &(RCC->AHBENR);
	handle.enable = RCC_AHBENR_TSCEN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_AHBENR_CRCEN
	handle.exists = true;
	handle.enr = &(RCC->AHBENR);
	handle.enable = RCC_AHBENR_CRCEN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_AHBENR_FLITFEN
	handle.exists = true;
	handle.enr = &(RCC->AHBENR);
	handle.enable = RCC_AHBENR_FLITFEN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_AHBENR_SRAMEN
	handle.exists = true;
	handle.enr = &(RCC->AHBENR);
	handle.enable = RCC_AHBENR_SRAMEN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_AHBENR_DMA2EN
	handle.exists = true;
	handle.enr = &(RCC->AHBENR);
	handle.enable = RCC_AHBENR_DMA2EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_AHBENR_DMAEN
	handle.exists = true;
	handle.enr = &(RCC->AHBENR);
	handle.enable = RCC_AHBENR_DMAEN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);
	
	// APB2

#ifdef RCC_APB2ENR_SYSCFGCOMPEN
	handle.exists = true;
	handle.enr = &(RCC->APB2ENR);
	handle.enable = RCC_APB2ENR_SYSCFGCOMPEN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB2ENR_USART6EN
	handle.exists = true;
	handle.enr = &(RCC->APB2ENR);
	handle.enable = RCC_APB2ENR_USART6EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB2ENR_USART7EN
	handle.exists = true;
	handle.enr = &(RCC->APB2ENR);
	handle.enable = RCC_APB2ENR_USART7EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB2ENR_USART8EN
	handle.exists = true;
	handle.enr = &(RCC->APB2ENR);
	handle.enable = RCC_APB2ENR_USART8EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB2ENR_ADCEN
	handle.exists = true;
	handle.enr = &(RCC->APB2ENR);
	handle.enable = RCC_APB2ENR_ADCEN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB2ENR_TIM1EN
	handle.exists = true;
	handle.enr = &(RCC->APB2ENR);
	handle.enable = RCC_APB2ENR_TIM1EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB2ENR_SPI1EN
	handle.exists = true;
	handle.enr = &(RCC->APB2ENR);
	handle.enable = RCC_APB2ENR_SPI1EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB2ENR_USART1EN
	handle.exists = true;
	handle.enr = &(RCC->APB2ENR);
	handle.enable = RCC_APB2ENR_USART1EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB2ENR_TIM15EN
	handle.exists = true;
	handle.enr = &(RCC->APB2ENR);
	handle.enable = RCC_APB2ENR_TIM15EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB2ENR_TIM16EN
	handle.exists = true;
	handle.enr = &(RCC->APB2ENR);
	handle.enable = RCC_APB2ENR_TIM16EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB2ENR_TIM17EN
	handle.exists = true;
	handle.enr = &(RCC->APB2ENR);
	handle.enable = RCC_APB2ENR_SYSCFGCOMPEN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB2ENR_DBGMCUEN
	handle.exists = true;
	handle.enr = &(RCC->APB2ENR);
	handle.enable = RCC_APB2ENR_DBGMCUEN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);
	
	// APB1

#ifdef RCC_APB1ENR_TIM2EN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_TIM2EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_TIM3EN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_TIM3EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_TIM6EN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_TIM6EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_TIM7EN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_TIM7EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_TIM14EN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_TIM14EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_WWDGEN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_WWDGEN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_SPI2EN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_SPI2EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_USART2EN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_USART2EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_USART3EN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_USART3EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_USART4EN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_USART4EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_USART5EN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_USART5EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_I2C1EN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_I2C1EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_I2C2EN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_I2C2EN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_USBEN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_USBEN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_CANEN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_CANEN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_CRSEN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_CRSEN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_PWREN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_PWREN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_DACEN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_DACEN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);

#ifdef RCC_APB1ENR_CECEN
	handle.exists = true;
	handle.enr = &(RCC->APB1ENR);
	handle.enable = RCC_APB1ENR_CECEN;
#else
	handle.exists = false;
#endif
	peripheralHandlesStatic->push_back(handle);
	
	
	return *peripheralHandlesStatic;
}


// Public methods:

// --- ENABLE ---
// Enable the target peripheral. 
// Returns true if the peripheral was successfully turned on, or if the peripheral was already on.
// Returns false if the peripheral could not be turned on. 
bool Rcc::enable(RccPeripheral peripheral) {
	static std::vector<RccPeripheralHandle> &perHandlesStatic = Rcc::peripheralHandles();
	uint8_t perNum = (uint8_t) peripheral;
	RccPeripheralHandle &ph = perHandlesStatic[perNum];
	
	if (ph.exists == false) {
		// TODO: set reason.
		return false;
	}
	
	// Check the current peripheral status.
	if (ph.count > 0) {
		if (ph.count >= handle_max) {
			// Reached maximum handles. Return false to prevent counter overflow.
			// TODO: set reason.
			return false;
		}
		
		// Increase handler count by one.
		ph.count++;
	}
	else {
		// Activate the peripheral.
		ph.count = 1;
		(*ph.enr) |= ph.enable;
	}
	
	return true;
}


// --- DISABLE ---
// Disable the target peripheral.
// Returns true if the disable request was received but not processed due to outstanding handles, or
// if the peripheral was successfully disabled.
// Returns false if the request was rejected or disabling the peripheral failed.
bool Rcc::disable(RccPeripheral peripheral) {
	static std::vector<RccPeripheralHandle> &perHandlesStatic = Rcc::peripheralHandles();
	uint8_t perNum = (uint8_t) peripheral;
	RccPeripheralHandle &ph = perHandlesStatic[perNum];
	
	if (ph.exists == false) {
		// TODO: set reason.
		return false;
	}
	
	if (ph.count > 1) {
		// Decrease handler count by one.
		ph.count--;
	}
	else {
		// Deactivate the peripheral.
		ph.count = 0;
		(*ph.enr) &= ~(ph.enable);
	}
	
	return true;
}


// --- ENABLE PORT ---
// Returns true if the port was already enabled, or was successfully enabled.
// Returns false if the port could not be enabled.
bool Rcc::enablePort(RccPort port) {
	static std::vector<RccPortHandle> &portHandlesStatic = Rcc::portHandles();
	uint8_t portNum = (uint8_t) port;
	RccPortHandle &ph = portHandlesStatic[portNum];
	
	if (ph.exists == false) {
		// TODO: set reason.
		return false; 
	}
	
	// Check the current port status.
	if (ph.count > 0) {
		if (ph.count >= handle_max) {
			// Reached maximum handles. Return false to prevent counter overflow.
			// TODO: set reason.
			return false;
		}
		
		// Increase handler count by one.
		ph.count++;
	}
	else {
		// Activate the port.
		ph.count = 1;
		RCC->AHBENR |= ph.enable;
	}
	
	return true;
}


// --- DISABLE PORT ---
// Returns true if the port is already disabled, if the request was accepted, or the port disabled.
// Returns false if the requested was rejected, or the port could not be disabled.
bool Rcc::disablePort(RccPort port) {
	static std::vector<RccPortHandle> &portHandlesStatic = Rcc::portHandles();
	uint8_t portNum = (uint8_t) port;
	RccPortHandle &ph = portHandlesStatic[portNum];
	
	if (ph.exists == false) {
		// TODO: set reason.
		return false; 
	}
	
	// Check the current port status.
	if (ph.count > 1) {
		// Decrease handler count by one.
		ph.count--;
	}
	else {
		// Deactivate the port.
		ph.count = 0;
		RCC->AHBENR &= ~(ph.enable);
	}
	
	return true;
}
