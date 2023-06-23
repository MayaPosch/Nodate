/*
	gpio.h - Header to provide access to GPIO functionality.
	
*/


#ifndef GPIO_H
#define GPIO_H


#include <common.h>

#include "rcc.h"


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


struct GpioPinDef {
	GPIO_ports port;
	uint8_t pin;
	uint8_t af;
};


struct GpioOutputDef {
	GPIO_ports port;
	uint8_t pin;
	GPIO_pupd pupd			= GPIO_FLOATING;
	GPIO_out_type type 		= GPIO_PUSH_PULL;
	GPIO_out_speed speed 	= GPIO_LOW;
};


struct GpioInputDef {
	GPIO_ports port;
	uint8_t pin;
	GPIO_pupd pupd;
};


struct GPIO_instance {
	bool active = false;
	GPIO_TypeDef* regs;
};


class GPIO {
	//
	
public:
	static bool set_input(GPIO_ports port, uint8_t pin, GPIO_pupd pupd);
	static bool set_output(GPIO_ports port, uint8_t pin, GPIO_pupd pupd = GPIO_FLOATING, 
							GPIO_out_type type = GPIO_PUSH_PULL, GPIO_out_speed speed = GPIO_LOW);
	static bool set_output(GpioPinDef def, GPIO_pupd pupd = GPIO_FLOATING, 
							GPIO_out_type type = GPIO_PUSH_PULL, GPIO_out_speed speed = GPIO_LOW);
	static bool set_af(GPIO_ports port, uint8_t pin, uint8_t af);
	static bool set_af(GpioPinDef def);
	static bool set_af(GPIO_ports port, uint8_t pin, RccPeripheral per, uint8_t af, GPIO_out_type type = GPIO_PUSH_PULL);
	static bool set_af(RccPeripheral per, uint8_t af);
	static bool set_analog(GPIO_ports port, uint8_t pin); // Not implemented for STM32F1
	static bool set_output_parameters(GPIO_ports port, uint8_t pin, GPIO_pupd pupd = GPIO_FLOATING, 
							GPIO_out_type type = GPIO_PUSH_PULL, GPIO_out_speed speed = GPIO_LOW);
	static bool set_output_parameters(GpioPinDef def, GPIO_pupd pupd = GPIO_FLOATING, 
							GPIO_out_type type = GPIO_PUSH_PULL, GPIO_out_speed speed = GPIO_LOW);
	static bool write(GPIO_ports port, uint8_t pin, GPIO_level level);
	static bool write(GpioPinDef def, GPIO_level level);
	static bool write(GPIO_ports port, uint8_t pin, uint32_t level); // No actions in definition (return true).
	static uint8_t read(GPIO_ports port, uint8_t pin);
	static uint32_t readAnalog(GPIO_ports port, uint8_t pin);
};

#endif
