/*
	ssd1306.cpp - Implementation of SSD1306 display driver library.
	
	2021/04/20, Maya Posch
*/


#include "ssd1306.h"

// TODO: replace with external configuration option.
// This is just used for the splash image right now.
const uint8_t HEIGHT = 64;
const uint8_t WIDTH = 82;
#include "splash.h"

#include <cstring>

// Debug
#include <printf.h>


void ssd1306Callback(uint8_t byte) {
	//
}


// --- CONSTRUCTOR ---
SSD1306::SSD1306(I2C_devices device, uint8_t slave_address) {
	// Try to set the target I2C peripheral in master mode.
	ready = I2C::startMaster(device, I2C_MODE_FM, ssd1306Callback);
	
	i2c_bus = device;
	address = slave_address;
}


// --- IS READY ---
// Returns true if the display instance has been fully configured and is ready.
bool SSD1306::isReady() {
	return ready;
}


// --- INIT ---
bool SSD1306::init() {
	if ((!buffer) && !(buffer = (uint8_t*) malloc(WIDTH * ((HEIGHT + 7) / 8)))) {
		return false;
	}
	
	printf("init: 0\n");

	clearDisplay();
	if (HEIGHT > 32) {
		drawBitmap((WIDTH - splash1_width) / 2, (HEIGHT - splash1_height) / 2,
				splash1_data, splash1_width, splash1_height, 1);
	} 
	else {
		drawBitmap((WIDTH - splash2_width) / 2, (HEIGHT - splash2_height) / 2,
				splash2_data, splash2_width, splash2_height, 1);
	}
	
	printf("init: 1\n");
	
	// TODO: configuring for 128x64 display here. Make configurable for 32 tall displays.
	send_command(SSD1306_DISPLAY_OFF);
	
	printf("init: 2\n");
	
	send_command(SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO);
	send_data(0x80);
	
	printf("init: 3\n");
	
	send_command(SSD1306_SET_MULTIPLEX_RATIO);
	send_data(HEIGHT - 1);
	send_command(SSD1306_SET_DISPLAY_OFFSET);
	send_data(0x0);
	send_data((uint8_t) SSD1306_SET_START_LINE | 0x0);
	send_command(SSD1306_CHARGE_PUMP);
	send_data(0x14);
	send_command(SSD1306_MEMORY_ADDR_MODE);
	send_data(0x00);
	send_data((uint8_t) SSD1306_SET_SEGMENT_REMAP | 0x1);
	send_command(SSD1306_COM_SCAN_DIR_DEC);
	send_command(SSD1306_SET_COM_PINS);
	send_data(0x12);
	send_command(SSD1306_SET_CONTRAST_CONTROL);
	send_data(0xCF);
	send_command(SSD1306_SET_PRECHARGE_PERIOD);
	send_data(0xF1);
	send_command(SSD1306_SET_VCOM_DESELECT);
	send_data(0x40);
	send_command(SSD1306_DISPLAY_ALL_ON_RESUME);
	send_command(SSD1306_NORMAL_DISPLAY);
	send_command(SSD1306_DEACTIVATE_SCROLL);
	send_command(SSD1306_DISPLAY_ON);
	
	return true;
}


void SSD1306::drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[],
                              int16_t width, int16_t height, uint16_t color) {
	int16_t byteWidth = (width + 7) / 8; // Bitmap scanline pad = whole byte
	uint8_t byte = 0;

	for (int16_t j = 0; j < height; j++, y++) {
		for (int16_t i = 0; i < width; i++) {
			if (i & 7) 	{ byte <<= 1; }
			else 		{ byte = bitmap[j * byteWidth + i / 8]; }
		
			if (byte & 0x80) {
				drawPixel(x + i, y, color);
			}
		}
	}
}


#define SSD1306_BLACK 0   ///< Draw 'off' pixels
#define SSD1306_WHITE 1   ///< Draw 'on' pixels
#define SSD1306_INVERSE 2 ///< Invert pixels

#define ssd1306_swap(a, b)                                                     \
  (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b))) ///< No-temp-var swap operation


void SSD1306::drawPixel(int16_t x, int16_t y, uint16_t color) {
	// FIXME: shouldn't be hardcoded.
	uint8_t width = 128;
	uint8_t height = 64;
	if ((x >= 0) && (x < width) && (y >= 0) && (y < height)) {
		// Pixel is in-bounds. Rotate coordinates if needed.
		switch (rotation) {
			case 1:
				ssd1306_swap(x, y);
				x = WIDTH - x - 1;
				break;
			case 2:
				x = WIDTH - x - 1;
				y = HEIGHT - y - 1;
				break;
			case 3:
				ssd1306_swap(x, y);
				y = HEIGHT - y - 1;
				break;
		}
		
		switch (color) {
			case SSD1306_WHITE:
				buffer[x + (y / 8) * WIDTH] |= (1 << (y & 7));
				break;
			case SSD1306_BLACK:
				buffer[x + (y / 8) * WIDTH] &= ~(1 << (y & 7));
				break;
			case SSD1306_INVERSE:
				buffer[x + (y / 8) * WIDTH] ^= (1 << (y & 7));
				break;
		}
	}	
}


bool SSD1306::display() {
	uint8_t dlist1[] = {
		(uint8_t) SSD1306_SET_PAGE_ADDR,
		0,                      // Page start address
		0xFF,                   // Page end (not really, but works here)
		(uint8_t) SSD1306_SET_COLUMN_ADDR, 0};		// Column start address
		
	send_data(dlist1, sizeof(dlist1));
	send_data((uint8_t) WIDTH - 1); // Column end address

	uint16_t count = WIDTH * ((HEIGHT + 7) / 8);
	
	send_data(buffer, count);
	
	// Write buffer in lines, starting a new line at the beginning, writing the data for the line,
	// then send a new line command before writing the data for that line, ad nauseam.
	/* uint8_t* ptr = buffer;
	for (uint8_t i = 0; i < HEIGHT; ++i) {
		send_command(SSD1306_SET_START_LINE);
		send_data(ptr, WIDTH);
		ptr += WIDTH;
	} */
	
	return true;
	
	/* 
	uint8_t *ptr = buffer;
	wire->beginTransmission(i2caddr);
	WIRE_WRITE((uint8_t)0x40);
	uint16_t bytesOut = 1;
	while (count--) {
		if (bytesOut >= WIRE_MAX) {
			wire->endTransmission();
			wire->beginTransmission(i2caddr);
			WIRE_WRITE((uint8_t)0x40);
			bytesOut = 1;
		}
	
		WIRE_WRITE(*ptr++);
		bytesOut++;
	}
	
	wire->endTransmission(); */
}


void SSD1306::clearDisplay() {
	memset(buffer, 0, WIDTH * ((HEIGHT + 7) / 8));
}


void SSD1306::send_command(SSD1306_commands cmd) {
	I2C::setSlaveTarget(i2c_bus, address);
	I2C::sendToSlave(i2c_bus, ((uint8_t*) &cmd), 1);
}


void SSD1306::send_data(uint8_t byte) {
	I2C::setSlaveTarget(i2c_bus, address);
	I2C::sendToSlave(i2c_bus, &(byte), 1);
}


void SSD1306::send_data(uint8_t* bytes, uint16_t len) {
	I2C::setSlaveTarget(i2c_bus, address);
	I2C::sendToSlave(i2c_bus, bytes, len);
}
