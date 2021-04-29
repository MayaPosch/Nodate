/*
	ssd1306.h - Header file for the SSD1306 OLED display library.
	
	Revision 0
	
	2021/04/18, Maya Posch
*/


#ifndef NODATE_SSD1306_H
#define NODATE_SSD1306_H


#include <common.h>
#include <nodate.h>


enum SSD1306_commands {
	SSD1306_MEMORY_ADDR_MODE		= 0x20,	//
	SSD1306_SET_COLUMN_ADDR 		= 0x21,	// See datasheet
	SSD1306_SET_PAGE_ADDR 			= 0x22, // See datasheet
	SSD1306_SET_CONTRAST_CONTROL	= 0x81, // See datasheet
	SSD1306_CHARGE_PUMP				= 0x8D, // See datasheet
	SSD1306_SET_SEGMENT_REMAP		= 0xA0, // See datasheet
	SSD1306_DISPLAY_ALL_ON_RESUME 	= 0xA4,	// See datasheet
	SSD1306_DISPLAY_ALL_ON 			= 0xA5, // Not currently used
	SSD1306_NORMAL_DISPLAY 			= 0xA6, // See datasheet
	SSD1306_INVERTDISPLAY 			= 0xA7, // See datasheet
	SSD1306_SET_MULTIPLEX_RATIO		= 0xA8, // See datasheet
	SSD1306_DISPLAY_OFF				= 0xAE, // See datasheet
	SSD1306_DISPLAY_ON 				= 0xAF,	// See datasheet
	SSD1306_COM_SCAN_DIR_INC 		= 0xC0, // Not currently used
	SSD1306_COM_SCAN_DIR_DEC		= 0xC8, // See datasheet
	SSD1306_SET_DISPLAY_OFFSET 		= 0xD3, // See datasheet
	SSD1306_SET_PRECHARGE_PERIOD	= 0xD9, // See datasheet
	SSD1306_SET_COM_PINS			= 0xDA, // See datasheet
	SSD1306_SET_VCOM_DESELECT 		= 0xDB, // See datasheet
	SSD1306_SET_LOWER_COLUMN 		= 0x00, // Not currently used
	SSD1306_SET_HIGHER_COLUMN 		= 0x10, // Not currently used
	SSD1306_SET_START_LINE 		= 0x40, // See datasheet
	SSD1306_EXTERNALVCC 		= 0x01, // External display voltage source
	SSD1306_SWITCHCAPVCC 		= 0x02, // Gen. display voltage from 3.3V
	SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO 			= 0xD5, // See datasheet
	SSD1306_RIGHT_HORIZONTAL_SCROLL					= 0x26, // Init rt scroll
	SSD1306_LEFT_HORIZONTAL_SCROLL 					= 0x27, // Init left scroll
	SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL	= 0x29, // Init diag scroll
	SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 	= 0x2A, // Init diag scroll
	SSD1306_DEACTIVATE_SCROLL 						= 0x2E, // Stop scroll
	SSD1306_ACTIVATE_SCROLL 						= 0x2F, // Start scroll
	SSD1306_SET_VERTICAL_SCROLL_AREA 				= 0xA3  // Set scroll range
};


struct SSD1306_command {
	SSD1306_commands cmd;
	uint8_t* payload;
	uint8_t length;
};


class SSD1306 {
	I2C_devices i2c_bus;
	uint8_t address;
	uint8_t* buffer = 0;
	uint8_t rotation = 0;
	bool ready;
	
	void send_command(SSD1306_commands cmd);
	void send_data(uint8_t byte);
	void send_data(uint8_t* bytes, uint16_t len);
	
public:
	SSD1306(I2C_devices device, uint8_t slave_address);
	bool isReady();
	bool init();
	bool display();
	void clearDisplay();
	
	void drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[],
												int16_t width, int16_t height, uint16_t color);
	void drawPixel(int16_t x, int16_t y, uint16_t color);
};


#endif
