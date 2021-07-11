/*
	ssd1306.cpp - Implementation of SSD1306 display driver library.
	
	2021/04/20, Maya Posch
*/


#include "ssd1306.h"

#include "splash.h"

#include <cstring>


void ssd1306Callback(uint8_t byte) {
	//
}


// --- CONSTRUCTOR ---
SSD1306::SSD1306(I2C_devices device, uint8_t slave_address) {
	// Try to set the target I2C peripheral in master mode.
	ready = I2C::startMaster(device, I2C_MODE_SM100, ssd1306Callback);
	
	i2c_bus = device;
	address = slave_address;
}


// --- IS READY ---
// Returns true if the display instance has been fully configured and is ready.
bool SSD1306::isReady() {
	return ready;
}


// --- INIT ---
bool SSD1306::init(uint32_t width, uint32_t height) {
	this->width = width;
	this->height = height;
	if ((!buffer) && !(buffer = (uint8_t*) malloc(width * (height / 8)))) {
		return false;
	}

	clearDisplay();
	if (height > 32) {
		drawBitmap((width - splash1_width) / 2, (height - splash1_height) / 2,
				splash1_data, splash1_width, splash1_height, white);
	} 
	else {
		drawBitmap((width - splash2_width) / 2, (height - splash2_height) / 2,
				splash2_data, splash2_width, splash2_height, white);
	}
	
	send_command(SSD1306_DISPLAY_OFF);
	
	// Timing and driving.
	send_command(SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO);
	send_command(0x80);
	send_command(SSD1306_SET_PRECHARGE_PERIOD);
	send_command(0x22);
	send_command(SSD1306_SET_VCOM_DESELECT);
	send_command(0x40);
	
	send_command(SSD1306_SET_CONTRAST_CONTROL);
	send_command(0x7F);
	
	send_command(SSD1306_SET_DISPLAY_OFFSET);
	send_command(0x0);
	
	// Scrolling
	send_command(SSD1306_DEACTIVATE_SCROLL);
	
	// Addressing
	send_command(SSD1306_MEMORY_ADDR_MODE);
	send_command(0x10);		// Page addressing mode.
	send_command(SSD1306_SET_START_LINE);
	
	// Hardware config
	send_command(SSD1306_SET_SEGMENT_REMAP_INV);
	send_command(SSD1306_SET_MULTIPLEX_RATIO);
	send_command(height - 1);
	send_command(SSD1306_COM_SCAN_DIR_DEC);
	send_command(SSD1306_SET_COM_PINS);
	send_command(0x12);
	
	// Charge pump.
	send_command(SSD1306_CHARGE_PUMP);
	send_command(0x14);
	
	// Display back on.
	send_command(SSD1306_DISPLAY_ALL_ON_RESUME);
	send_command(SSD1306_NORMAL_DISPLAY);
	send_command(SSD1306_DISPLAY_ON);
	
	//send_command(SSD1306_SET_PAGE_START_ADDDR);	// 0xB0, first page.
	//send_command(SSD1306_SET_LOWER_COLUMN);
	//send_command(SSD1306_SET_HIGHER_COLUMN);
	
	return true;
}


void SSD1306::drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[],
                              int16_t width, int16_t height, SSD1306_colors color) {
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


#define ssd1306_swap(a, b)                                                     \
  (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b))) ///< No-temp-var swap operation


void SSD1306::drawPixel(int16_t x, int16_t y, SSD1306_colors color) {
	if (x >= width || y >= height) {
		// Outside bounds.
		return;
	}
	
	// Check if pixel should be inverted
    if (inverted) {
        color = (SSD1306_colors) !color;
    }

    // Draw in the correct color
    if (color == white) {
        buffer[x + (y / 8) * width] |= 1 << (y % 8);
    }
    else {
        buffer[x + (y / 8) * width] &= ~(1 << (y % 8));
    }	
}


// --- WRITE CHAR ---
//  Draw 1 char to the screen buffer
//  ch      => Character to write
//  Font    => Font to use
//  color   => black or white
char SSD1306::writeChar(char ch, FontDef Font, SSD1306_colors color) {
    uint32_t i, b, j;

    // Check remaining space on current line
    if (width <= (currentX + Font.FontWidth) ||
        height <= (currentY + Font.FontHeight)) {
        // Not enough space on current line
        return 0;
    }

    // Translate font to screenbuffer
    for (i = 0; i < Font.FontHeight; i++) {
        b = Font.data[(ch - 32) * Font.FontHeight + i];
        for (j = 0; j < Font.FontWidth; j++) {
            if ((b << j) & 0x8000) {
                drawPixel(currentX + j, (currentY + i), (SSD1306_colors) color);
            }
            else {
                drawPixel(currentX + j, (currentY + i), (SSD1306_colors)!color);
            }
        }
    }

    // The current space is now taken
    currentX += Font.FontWidth;

    // Return written char for validation
    return ch;
}


// --- WRITE STRING ---
//  Write full string to buffer
uint32_t SSD1306::writeString(char* str, FontDef Font, SSD1306_colors color) {
    // Write until null-byte
	uint32_t count = 0;
    while (*str) {
        if (writeChar(*str, Font, color) != *str) {
            // Char could not be written.
            return count;
        }

        // Next char
        str++;
		count++;
    }

    // Everything ok
    return count;
}


// --- SET CURSOR --
void SSD1306::setCursor(uint8_t x, uint8_t y) {
    currentX = x;
    currentY = y;
}


bool SSD1306::display() {
	uint8_t cmd = 0xB0; // Page address.
	for (uint8_t i = 0; i < 8; i++) {
		send_command(cmd++);
		send_command(0x00);
		send_command(0x10);

		if (!send_data(&(buffer[width * i]), width)) {
			return false;
		}
	}
	
	return true;
}


void SSD1306::clearDisplay() {
	memset(buffer, 0, width * (height / 8));
}


void SSD1306::invertColors() {
	inverted = !inverted;
}


void SSD1306::displayFullOn(bool on) {
	if (on) { 	send_command(SSD1306_DISPLAY_ALL_ON); }
	else {		send_command(SSD1306_DISPLAY_ALL_ON_RESUME); }
}


void SSD1306::send_command(SSD1306_commands cmd) {
	I2C::setSlaveTarget(i2c_bus, address);
	uint8_t bytes[] = { 0x0, (uint8_t) cmd };
	I2C::sendToSlave(i2c_bus, bytes, 2);
}


void SSD1306::send_command(uint8_t cmd) {
	I2C::setSlaveTarget(i2c_bus, address);
	uint8_t bytes[] = { 0x0, cmd };
	I2C::sendToSlave(i2c_bus, bytes, 2);
}


void SSD1306::send_command(SSD1306_commands cmd, uint8_t data) {
	I2C::setSlaveTarget(i2c_bus, address);
	uint8_t bytes[] = { 0x0, (uint8_t) cmd, data };
	I2C::sendToSlave(i2c_bus, bytes, 3);
}


void SSD1306::send_commands(uint8_t* data, uint8_t len) {
	I2C::setSlaveTarget(i2c_bus, address);
	I2C::sendToSlaveBegin(i2c_bus, len + 1);
	uint8_t byte = 0x00;
	I2C::sendToSlaveBytes(i2c_bus, &byte, 1);
	I2C::sendToSlaveBytes(i2c_bus, data, len);
	I2C::sendToSlaveEnd(i2c_bus);
}


void SSD1306::send_data(uint8_t byte) {
	I2C::setSlaveTarget(i2c_bus, address);
	uint8_t bytes[] = { 0x40, byte };
	I2C::sendToSlave(i2c_bus, bytes, 2);
}


bool SSD1306::send_data(uint8_t* bytes, uint16_t len) {
	I2C::setSlaveTarget(i2c_bus, address);
	I2C::sendToSlaveBegin(i2c_bus, len + 1);
	uint8_t data = 0x40;
	if (!I2C::sendToSlaveBytes(i2c_bus, &data, 1)) {
		I2C::sendToSlaveEnd(i2c_bus);
		return false;
	}
	
	if (!I2C::sendToSlaveBytes(i2c_bus, bytes, len)) {
		I2C::sendToSlaveEnd(i2c_bus);
		return false;
	}
	
	I2C::sendToSlaveEnd(i2c_bus);
	
	return true;
}
