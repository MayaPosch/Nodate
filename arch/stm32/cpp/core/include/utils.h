/*
	utils.h - Common utility functions for the Nodate project.
	
*/

#include <cstdint>

// --- BCD conversion ---
uint8_t bcd2dec8(uint8_t bcd);
uint8_t dec2bcd8(uint8_t dec);
uint16_t bcd2dec16(uint16_t bcd);
uint16_t dec2bcd16(uint16_t dec);
uint32_t bcd2dec32(uint32_t bcd);
uint32_t dec2bcd32(uint32_t dec);

// --- Time things ---
// Defined in utils_time.cpp.
#include <utils_time.h>
