/*
	rcc.cpp - Implementation for RCC functionality.
	
*/


#include "rcc.h"


// Static initialisations.
std::vector<RccPortHandle>& RCC::portHandles {
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


// --- ENABLE ---
// Enable the target peripheral. 
// Returns true if the peripheral was successfully turned on, or if the peripheral was already on.
// Returns false if the peripheral could not be turned on. 
bool RCC::enable(RccPeripheral peripheral) {
	//
	
	return true;
}


// --- DISABLE ---
// Disable the target peripheral.
// Returns true if the disable request was received but not processed due to outstanding handles, or
// if the peripheral was successfully disabled.
// Returns false if the request was rejected or disabling the peripheral failed.
bool RCC::disable(RccPeripheral peripheral) {
	//
	
	return true;
}


// --- ENABLE PORT ---
// Returns true if the port was already enabled, or was successfully enabled.
// Returns false if the port could not be enabled.
bool RCC::enablePort(RccPort port) {
	static std::vector<RccPortHandle> &portHandlesStatic = RCC::portHandles();
	uint8_t portNum = (uint8_t) port;
	
	if (portHandlesStatic[portNum].exists == false) {
		// TODO: set reason.
		return false; 
	}
	
	// Check the current port status.
	if (portHandlesStatic[portNum].count > 0) {
		// Increase handler count by one.
		portHandlesStatic[(uint8_t) port].count++;
	}
	else {
		// Activate the port.
		portHandlesStatic[portNum].count = 1;
		RCC->AHBENR |= portHandlesStatic[portNum].enable;
	}
	
	return true;
}


// --- DISABLE PORT ---
// Returns true if the port is already disabled, if the request was accepted, or the port disabled.
// Returns false if the requested was rejected, or the port could not be disabled.
bool RCC::disablePort(RccPort port) {
	static std::vector<RccPortHandle> &portHandlesStatic = RCC::portHandles();
	uint8_t portNum = (uint8_t) port;
	
	if (portHandlesStatic[portNum].exists == false) {
		// TODO: set reason.
		return false; 
	}
	
	// Check the current port status.
	if (portHandlesStatic[portNum].count > 1) {
		// Decrease handler count by one.
		portHandlesStatic[portNum].count++;
	}
	else {
		// Deactivate the port.
		portHandlesStatic[portNum].count = 0;
		RCC->AHBENR &= ~(portHandlesStatic[portNum].enable);
	}
	
	return true;
}
