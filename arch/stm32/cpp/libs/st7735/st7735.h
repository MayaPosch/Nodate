/*
	st7735.h - Header of ST7735 TFT LCD library for Nodate framework.
	
	Revision 0.
	
	Notes:
			- 
			
	Features:
			-
			
	2022/08/18, Maya Posch
*/


#include <nodate.h>


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
	color565_t* frame;
	
public:
	ST7735(SPI_devices device, GpioPinDef reset, GpioPinDef cs, GpioPinDef dc);
	
	bool init(uint32_t width, uint32_t height);
};
