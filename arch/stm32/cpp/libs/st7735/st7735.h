/*
	st7735.h - Header of ST7735 TFT LCD library for Nodate framework.
	
	Revision 0.
			
	Features:
			-
	
	Notes:
			- Inspired by: https://github.com/bersch/ST7735S
			
	2022/08/18, Maya Posch
*/


#include <nodate.h>


// Display orientation in degrees.
enum ST7735_orientation {
	ST7735_ORIENTATION_0 = 0,
	ST7735_ORIENTATION_90 = 1,
	ST7735_ORIENTATION_180 = 2,
	ST7735_ORIENTATION_270 = 3
};


typedef struct  {
    union {
        struct {
            uint16_t r:5;
            uint16_t g:6;
            uint16_t b:5;
        } __attribute__((packed));
        uint8_t u[2];
    };
} __attribute__((packed)) color565_t;


class ST7735 {
	SPI_devices device;
	GpioPinDef reset;
	GpioPinDef cs;	// Chip Select.
	GpioPinDef dc;	// Data/Command.
	uint32_t width;
	uint32_t height;
	uint32_t xstart;
	uint32_t ystart;
	uint32_t buffer_width;
	uint32_t buffer_height;
	uint32_t buffer_xstart;
	uint32_t buffer_ystart;
	color565_t* frame;
	uint16_t xmin, xmax, ymin, ymax;
	uint8_t madctl;	// Memory Data Access Control state.
	color565_t color;
	color565_t bg_color;
	
	bool send(uint8_t* data, uint16_t len);
	bool sendData(uint8_t* data, uint16_t len);
	bool sendCommand(uint8_t* data, uint16_t len);
	
	void _LineLow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
	void _LineHigh(uint16_t x0,uint16_t y0, uint16_t x1, uint16_t y1);
	
public:
	ST7735(SPI_devices device, GpioPinDef reset, GpioPinDef cs, GpioPinDef dc);
	
	bool init(uint32_t width, uint32_t height, uint32_t xstart = 0, uint32_t ystart = 0);
	bool setOrientation(ST7735_orientation orientation);
	
	bool setBackgroundColor(uint8_t r, uint8_t g, uint8_t b);
	bool setColor(uint8_t r, uint8_t g, uint8_t b);
	void fillScreen();
	void filledRectangle(uint16_t x, uint16_t y, uint16_t x2, uint16_t y2);
	void drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
	void drawPixel(uint16_t x, uint16_t y);
	void drawBackgroundPixel(uint16_t x, uint16_t y);
	void updateWindow(uint16_t x, uint16_t y);
	void setFont(uint8_t* font);
	
	bool display();
	void resetWindow();
};
