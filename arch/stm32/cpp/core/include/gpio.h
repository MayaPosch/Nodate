/*
	gpio.h - Header to provide access to GPIO functionality.
	
*/


#ifndef GPIO_H
#define GPIO_H


#include <common.h>


enum GPIO_mode {
	GPIO_INPUT	= 0,
	GPIO_OUTPUT	= 1,
	GPIO_ALTERNATE = 2,
	GPIO_ANALOG = 3
};


enum GPIO_pupd {
	GPIO_FLOATING = 0,
	GPIO_PULL_UP = 1,
	GPIO_PULL_DOWN = 2
};


enum GPIO_out_speed {
	GPIO_LOW = 0,
	GPIO_MID = 1,
	GPIO_HIGH = 2
};


enum GPIO_out_type {
	GPIO_PUSH_PULL = 0,
	GPIO_OPEN_DRAIN = 1
};


enum GPIO_level {
	GPIO_LEVEL_UNKNOWN = 0,
	GPIO_LEVEL_LOW = 1,
	GPIO_LEVEL_HIGH = 2
};


enum GPIO_ports {
	GPIO_PORT_A = 0,
	GPIO_PORT_B,
	GPIO_PORT_C,
	GPIO_PORT_D,
	GPIO_PORT_E,
	GPIO_PORT_F,
	GPIO_PORT_G,
	GPIO_PORT_H,
	GPIO_PORT_I,
	GPIO_PORT_J,
	GPIO_PORT_K,
	GPIO_PORT_L
};


struct GPIO_instance {
	bool active = false;
	GPIO_TypeDef* regs;
};


class GPIO {
	struct ports {
		bool exists;
	};
	
public:
	GPIO();
	~GPIO();
	
	bool set_input(GPIO_ports port, uint8_t pin, GPIO_pupd pupd);
	bool set_output(GPIO_ports port, uint8_t pin, GPIO_pupd pupd = GPIO_FLOATING, 
							GPIO_out_type type = GPIO_PUSH_PULL, GPIO_out_speed speed = GPIO_LOW);
	//bool mode(uint32_t pin, GPIO_mode mode);
	bool write(GPIO_ports port, uint8_t pin, GPIO_level level);
	bool write(GPIO_ports port, uint8_t pin, uint32_t level);
	uint8_t read(GPIO_ports port, uint8_t pin);
	uint32_t readAnalog(GPIO_ports port, uint8_t pin);
};

#endif
