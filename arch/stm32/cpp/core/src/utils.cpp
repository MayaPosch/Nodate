/*
	utils.cpp - Utility function implementations for Nodate.
	
*/


#include "utils.h"


uint8_t bcd2dec8(uint8_t bcd) {
	uint8_t dec = (bcd >> 4) * 10 + (bcd & 0x0f);
	return dec;
}

uint8_t dec2bcd8(uint8_t dec) {
	uint8_t bcd = (dec % 10) | (dec / 10) << 4;
	return bcd;
}

uint16_t bcd2dec16(uint16_t bcd) {
	return bcd2dec8(bcd >> 8) * 100 + bcd2dec8(bcd & 0xff);
}

uint16_t dec2bcd16(uint16_t dec) {
	return dec2bcd8(dec % 100) | dec2bcd8(dec / 100) << 8;
}

uint32_t bcd2dec32(uint32_t bcd) {
	return bcd2dec16(bcd >> 16) * 10000 + bcd2dec16(bcd & 0xffff);
}

uint32_t dec2bcd32(uint32_t dec) {
	return dec2bcd16(dec % 10000) | dec2bcd16(dec / 10000) << 16;
}
