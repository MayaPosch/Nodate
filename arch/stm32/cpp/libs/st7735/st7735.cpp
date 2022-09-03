/*
	st7735.cpp - ST7735 TFT LCD library for Nodate framework.
	
	Revision 0.
	
	Notes:
			- 
			
	Features:
			-
			
	2022/08/18, Maya Posch
*/


#include "st7735.h"


enum ST7735S_Command {
	NOP			= 0x00,
	SWRESET		= 0x01, /* Software Reset */
	RDDID		= 0x04, /* Read Display ID */
	RDDST		= 0x09, /* Read Display Status */
	RDDPM		= 0x0a, /* Read Display Power Mode */
	RDDMADCTL	= 0x0b, /* Read Display MADCTL */
	RDDCOLMOD	= 0x0c, /* Read Display Pixel Format */
	RDDIM		= 0x0d, /* Read Display Image Mode */
	RDDSM		= 0x0e, /* Read Display Signal Mode */
	RDDSDR		= 0x0f, /* Read Display Self-Diagnostic Result */
	SLPIN		= 0x10, /* Sleep In */
	SLPOUT		= 0x11, /* Sleep Out */
	PTLON		= 0x12, /* Partial Display Mode On */
	NORON		= 0x13, /* Normal Display Mode On */
	INVOFF		= 0x20, /* Display Inversion Off */
	INVON		= 0x21, /* Display Inversion On */
	GAMSET		= 0x26, /* Gamma Set */
	DISPOFF		= 0x28, /* Display Off */
	DISPON		= 0x29, /* Display On */
	CASET		= 0x2a, /* Column Address Set */
	RASET		= 0x2b, /* Row Address Set */
	RAMWR		= 0x2c, /* Memory Write */
	RGBSET		= 0x2d, /* Color Setting 4k, 65k, 262k */
	RAMRD		= 0x2e, /* Memory Read */
	PTLAR		= 0x30, /* Partial Area */
	SCRLAR		= 0x33, /* Scroll Area Set */
	TEOFF		= 0x34, /* Tearing Effect Line OFF */
	TEON		= 0x35, /* Tearing Effect Line ON */
	MADCTL		= 0x36, /* Memory Data Access Control */
	VSCSAD		= 0x37, /* Vertical Scroll Start Address of RAM */
	IDMOFF		= 0x38, /* Idle Mode Off */
	IDMON		= 0x39, /* Idle Mode On */
	COLMOD		= 0x3a, /* Interface Pixel Format */
	RDID1		= 0xda, /* Read ID1 Value */
	RDID2		= 0xdb, /* Read ID2 Value */
	RDID3		= 0xdc, /* Read ID3 Value */
	FRMCTR1		= 0xb1, /* Frame Rate Control in normal mode, full colors */
	FRMCTR2		= 0xb2, /* Frame Rate Control in idle mode, 8 colors */
	FRMCTR3		= 0xb3, /* Frame Rate Control in partial mode, full colors */
	INVCTR		= 0xb4, /* Display Inversion Control */
	PWCTR1		= 0xc0, /* Power Control 1 */
	PWCTR2		= 0xc1, /* Power Control 2 */
	PWCTR3		= 0xc2, /* Power Control 3 in normal mode, full colors */
	PWCTR4		= 0xc3, /* Power Control 4 in idle mode 8colors */
	PWCTR5		= 0xc4, /* Power Control 5 in partial mode, full colors */
	VMCTR1		= 0xc5, /* VCOM Control 1 */
	VMOFCTR		= 0xc7, /* VCOM Offset Control */
	WRID2		= 0xd1, /* Write ID2 Value */
	WRID3		= 0xd2, /* Write ID3 Value */
	NVFCTR1		= 0xd9, /* NVM Control Status */
	NVFCTR2		= 0xde, /* NVM Read Command */
	NVFCTR3		= 0xdf, /* NVM Write Command */
	GMCTRP1		= 0xe0, /* Gamma '+'Polarity Correction Characteristics Setting */
	GMCTRN1		= 0xe1, /* Gamma '-'Polarity Correction Characteristics Setting */
	GCV			= 0xfc, /* Gate Pump Clock Frequency Variable */
};


//#define FRAMESIZE (defWIDTH*defHEIGHT)
//color565_t frame[FRAMESIZE] = {0};


// --- CONSTRUCTOR ---
ST7735::ST7735(SPI_devices device, GpioPinDef reset, GpioPinDef cs, GpioPinDef dc) {
	this->device = device;
	this->reset = reset;
	this->cs = cs;
	this->dc = dc;
}


// --- INIT ---
bool ST7735::init(uint32_t width, uint32_t height, uint32_t xstart, uint32_t ystart) {
	this->width = width;
	this->height = height;
	this->xstart = xstart;
	this->ystart = ystart;
	
	// TODO: backlight pin is driven by PWM signal. Update when timers are implemented.
	// Manually set a fixed high (100% duty) signal on the backlight pin to enable backlight.
	
	
	// Configure reset, CS & DC pins.
	bool res;
	res = GPIO::set_output(reset);
	res = GPIO::set_output(cs, GPIO_PULL_UP);
	res = GPIO::set_output(dc);
	
	if (!res) { return false; }
	
	// Run sequence:
	// - Reset HIGH
	// - CS, DC LOW
	// - Reset LOW
	// - Reset HIGH
	// - CS HIGH
	res = GPIO::write(reset, GPIO_LEVEL_HIGH);
	res = GPIO::write(cs, GPIO_LEVEL_LOW);
	res = GPIO::write(dc, GPIO_LEVEL_LOW);
	
	if (!res) { return false; }
	
	Timer::delay(1); // 10 microseconds minimum.
	res = GPIO::write(reset, GPIO_LEVEL_LOW);
	
	Timer::delay(1); // 10 microseconds minimum.
	res = GPIO::write(reset, GPIO_LEVEL_HIGH);
	
	Timer::delay(1);
	res = GPIO::write(cs, GPIO_LEVEL_HIGH); // TODO: only set CS high when writing to slave?
	
	if (!res) { return false; }
	
	/* columns: 1 = # of params, 2 = command, 3 .. = params */
	uint8_t init_cmd[] = {
		1, SWRESET, /* software reset */
		1,  SLPOUT, /* sleep out, turn off sleep mode */
		1, DISPOFF,  /*  output from frame mem disabled */
		4, FRMCTR1, 0x00, 0b111111, 0b111111, /* frame frequency normal mode (highest frame rate in normal mode) */
		4, FRMCTR2, 0b1111, 0x01, 0x01, /* frame frequency idle mode */
		7, FRMCTR3, 0x05, 0x3c, 0x3c, 0x05, 0x3c, 0x3c,  /* frame freq partial mode: 1-3 dot inv, 4-6 col inv */
		2,  INVCTR, 0x03, /* display inversion control: 3-bit 0=dot, 1=col */
		4,  PWCTR1, 0b11111100, 0x08, 0b10, /* power control */
		2,  PWCTR2, 0xc0,
		3,  PWCTR3, 0x0d, 0x00,
		3,  PWCTR4, 0x8d, 0x2a,
		3,  PWCTR5, 0x8d, 0xee, /* partial */
		/* display brightness and gamma */
		2,	 GCV, 0b11011000, /* auto gate pump freq, max power save */
		2, NVFCTR1, 0b01000000, /* automatic adjust gate pumping clock for saving power consumption */
		2,  VMCTR1, 0b001111,  /* VCOM voltage setting */
		2, VMOFCTR, 0b10000, /* ligthness of black color 0-0x1f */
		2,  GAMSET, 0x08, /* gamma 1, 2, 4, 8 */
		2,  MADCTL, 0b01100000, /* row oder, col order, row colum xchange, vert refr order, rgb/bgr, hor refr order, 0, 0 */
		2,  COLMOD, 0x05, /* 3=12bit, 5=16-bit, 6=18-bit  pixel color mode */
		17, GMCTRP1,0x02, 0x1c, 0x07, 0x12, 0x37, 0x32, 0x29, 0x2c,
					0x29, 0x25, 0x2b, 0x39, 0x00, 0x01, 0x03, 0x10,
		17, GMCTRN1,0x03, 0x1d, 0x07, 0x06, 0x2E, 0x2C, 0x29, 0x2c,
					0x2e, 0x2e, 0x37, 0x3f, 0x00, 0x00, 0x02, 0x10,
		5,	CASET, 0, 0, 0, (uint8_t) ((uint8_t) height - (uint8_t) 1),
		5,	RASET, 0, 0, 0, (uint8_t) ((uint8_t) width - (uint8_t) 1),
		1,	INVON, /* display inversion on/off */
		1,  IDMOFF, /* idle mode off */
		1,	NORON,  /* normal display mode on */
		1,  DISPON,  /* recover from display off, output from frame mem enabled */
	};
	
	// Run init sequence.
	uint8_t args;

	for (uint16_t i = 0; i < sizeof(init_cmd); i += args + 1) {
		args = init_cmd[i];

		send(&init_cmd[i + 1], args);
	}
	
	// Create framebuffer.
	frame = new color565_t[(width * height)];
	
	resetWindow();
	
	return true;
}


// --- SEND ---
bool ST7735::send(uint8_t* data, uint16_t len) {
	sendCommand(data++, 1);
	if (--len > 0) {
		sendData(data, len);
	}
	
	return true;
}


// --- SEND DATA ---
bool ST7735::sendData(uint8_t* data, uint16_t len) {
	// Set the DC pin HIGH to indicate that we're sending data.
	GPIO::write(dc, GPIO_LEVEL_HIGH);
	
	// Transfer the data.
	return SPI::sendData(device, data, len);
}


// --- SEND COMMAND ---
bool ST7735::sendCommand(uint8_t* data, uint16_t len) {
	// Set the DC pin LOW to indicate that we're sending data.
	GPIO::write(dc, GPIO_LEVEL_LOW);
	
	// Transfer the data.
	return SPI::sendData(device, data, len);
}


// --- SET ORIENTATION ---
// Set the orientation of the display.
bool ST7735::setOrientation(ST7735_orientation orientation) {
	switch (orientation) {
		case ST7735_ORIENTATION_0: { 
			madctl = 0b01100000;
			buffer_width = width;
			buffer_height = height;
			buffer_xstart = xstart; 
			buffer_ystart = ystart;
			break;
		}
		case ST7735_ORIENTATION_90: { 
			madctl = 0b11000000;
			buffer_width = height; 
			buffer_height = width;
			buffer_xstart = ystart; 
			buffer_ystart = xstart;
			break;
		}
		case ST7735_ORIENTATION_180: { 
			madctl = 0b10100000;
			buffer_width = width; 
			buffer_height = height;
			buffer_xstart = xstart; 
			buffer_ystart = ystart;
			break;
		}
		case ST7735_ORIENTATION_270: { 
			madctl = 0b01000000;
			buffer_width = height; 
			buffer_height = width;
			buffer_xstart = ystart; 
			buffer_ystart = xstart;
			break;
		}
	}

	uint8_t cmd[] = { MADCTL, madctl };
	send(cmd, 2);
	
	return true;
}


// --- DISPLAY ---
// Transfer the framebuffer to the display.
bool ST7735::display() {
	//
	uint8_t xm = xmin + buffer_xstart, ym = ymin + buffer_ystart;
	uint8_t xx = xmax + buffer_xstart, yx = ymax + buffer_ystart;

	uint8_t cas[] = { CASET, (uint8_t) (xm >> 8), xm, (uint8_t) (xx >> 8), xx };
	uint8_t ras[] = { RASET, (uint8_t) (ym >> 8), ym, (uint8_t) (yx >> 8), yx };
	uint8_t ram[] = { RAMWR };

	send(cas, sizeof(cas));
	send(ras, sizeof(ras));
	sendCommand(ram, 1);

	uint16_t len  = (xmax - xmin + 1) * 2;
	for (uint16_t y = ymin; y <= ymax; y++) {
		sendData((uint8_t*) &frame[buffer_width * y + xmin], len);
	}

	resetWindow();
	
	return true;
}


// --- RESET WINDOW ---
void ST7735::resetWindow() {
	xmin = buffer_width - 1;
	xmax = 0;
	ymin = buffer_height - 1;
	ymax = 0;
}


// --- SET BACKGROUND COLOR ---
bool ST7735::setBackgroundColor(uint8_t r, uint8_t g, uint8_t b) {
	//setbgColorC((color565_t){ .r = r, .g = g, .b = b });
	color565_t c = { r, g, b };
	bg_color.u[0] = c.u[1];
	bg_color.u[1] = c.u[0];
	
	return true;
}


// --- SET COLOR ---
bool ST7735::setColor(uint8_t r, uint8_t g, uint8_t b) {
	//setbgColorC((color565_t){ .r = r, .g = g, .b = b });
	color565_t c = { r, g, b };
	color.u[0] = c.u[1];
	color.u[1] = c.u[0];
	
	return true;
}


// --- FILL SCREEN ---
void ST7735::fillScreen() {
	filledRectangle(0, 0, buffer_width, buffer_height);
}


// --- FILLED RECTANGLE ---
void ST7735::filledRectangle(uint16_t x, uint16_t y, uint16_t x2, uint16_t y2) {
	if (x > x2) { uint16_t tmp = x; x = x2; x2 = tmp; }
	if (y > y2) { uint16_t tmp = y; y = y2; y2 = tmp; }

	/* fast ergonomic grid fill */
	if (abs(x - x2) < abs(y - y2)) {
		uint16_t xl = x2 - ((abs(x - x2) & 1) ? 0 : 1);
		while (x < x2) {
			drawLine(x, y, x, y2);
			drawLine(xl, y, xl, y2);
			x += 2;
			xl -= 2;
		}
	} 
	else {
		uint16_t yl = y2 - ((abs(y - y2) & 1) ? 0 : 1);
		while (y < y2) {
			drawLine(x, y, x2, y);
			drawLine(x, yl, x2, yl);
			y += 2;
			yl -= 2;
		}
	}
}


// --- DRAW LINE ---
void ST7735::drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
	uint16_t abs_y = abs(y1 - y0);
	uint16_t abs_x = abs(x1 - x0);

	if (abs_y <= abs_x) {
		if (x0 > x1)
			_LineLow(x1, y1, x0, y0);
		else
			_LineLow(x0, y0, x1, y1);
	}
	
	if (abs_y >= abs_x) {
		if (y0 > y1)
			_LineHigh(x1, y1, x0, y0);
		else
			_LineHigh(x0, y0, x1, y1);
	}
}


// --- LINE LOW ---
void ST7735::_LineLow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
	int16_t dx = x1 - x0;
	int16_t dy = y1 - y0;
	int16_t yi = 1;

	if (dy < 0) {
		yi = -1;
		dy = -dy;
	}

	int16_t D = 2 * dy - dx;
	uint16_t y = y0;

	for (uint16_t x = x0; x <= x1; x++) {
		drawPixel(x,y);
		if (D > 0) {
			y += yi;
			D -= 2 * dx;
		}
		
		D += 2 * dy;
	}
}


// --- LINE HIGH ---
void ST7735::_LineHigh(uint16_t x0,uint16_t y0, uint16_t x1, uint16_t y1) {
	int16_t dx = x1 - x0;
	int16_t dy = y1 - y0;
	int16_t xi = 1;

	if (dx < 0) {
		xi = -1;
		dx = -dx;
	}

	int16_t D = 2*dx - dy;
	uint16_t x = x0;

	for (uint16_t y = y0; y < y1; y++) {
		drawPixel(x,y);
		if (D > 0) {
			x += xi;
			D -= 2*dy;
		}
		
		D += 2 * dx;
	}
}


// --- DRAW PIXEL ---
void ST7735::drawPixel(uint16_t x, uint16_t y) {
	if (x < buffer_width && y < buffer_height) {
		frame[buffer_width * y + x] = color;
		updateWindow(x, y);
	}
}


// --- DRAW BACKGROUND PIXEL ---
void ST7735::drawBackgroundPixel(uint16_t x, uint16_t y) {
	if (x < buffer_width && y < buffer_height) {
		frame[buffer_width * y + x] = bg_color;
		updateWindow(x, y);
	}
}


// --- UPDATE WINDOW ---
void ST7735::updateWindow(uint16_t x, uint16_t y) {
    if (x < buffer_width && y < buffer_height) {
        if (x < xmin) xmin = x;
        if (x > xmax) xmax = x;
        if (y < ymin) ymin = y;
        if (y > ymax) ymax = y;
    }
}
