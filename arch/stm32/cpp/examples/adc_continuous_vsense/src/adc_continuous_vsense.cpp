/*
	adc_continuous_vsense.cpp - Implementation of Continuous ADC example.
	
	Description:
		This example samples the Vsense (temperature) channel & a GPIO pin. This sequence
		generates two ISRs: conversion complete and sequence complete.
		
		These ISRs are used to transfer the data to a buffer and output the values on the UART.
		
		Starting/ending conversion by the ADC is begun/stopped by receiving a character on UART RX.
	
	2022/05/05, Maya Posch
*/


#include <nodate.h>


USART_devices usartTarget = USART_1;
volatile bool sampling_toggle = false;
volatile bool sampling_adc = false;
volatile bool tx_ready = false;
volatile bool led_on = true;


void uartCallback(char ch) {
	sampling_toggle = true;
	USART::sendUart(usartTarget, ch);
}


// ADC sample buffer for two channels.
const uint32_t buf_len = 2;
uint16_t ADC_array[buf_len];
uint16_t shadow_buffer[buf_len];
uint16_t* buffer_pos = ADC_array;

USART_def& ud = boardUSARTs[1];
uint8_t 	led_pin;
GPIO_ports 	led_port;


void conversion_complete_cb() {
	// Copy converted data to the buffer.
	ADC::getValue(ADC_1, *buffer_pos);
	buffer_pos++;
}


void sequence_complete_cb() {
	// Copy sequence data to shadow buffer, set toggle.
	for (uint32_t i = 0; i < buf_len; ++i) {
		shadow_buffer[i] = ADC_array[i];
	}
	
	if (led_on) {	GPIO::write(led_port, led_pin, GPIO_LEVEL_LOW); }
	else { 			GPIO::write(led_port, led_pin, GPIO_LEVEL_HIGH); }
	led_on = !led_on;
	tx_ready = true;
	buffer_pos = ADC_array;	// Reset to beginning.
}


void adc_overrun() {
	// Send error code, stop ADC.
	char ch = 'o';
	USART::sendUart(usartTarget, ch);
	ADC::stop(ADC_1);
}


int main() {
	// 1. Set up UART
	usartTarget = ud.usart;
	USART::startUart(ud.usart, ud.tx[0].port, ud.tx[0].pin, ud.tx[0].af, 
								ud.rx[0].port, ud.rx[0].pin, ud.rx[0].af, 115200, uartCallback);
	
	// 1. Set up LED.
	bool		led_enable = true;
	if (boardLEDs_count > 0) {
		led_pin = boardLEDs[0].pin.pin;
		led_port = boardLEDs[0].pin.port;
	}
	else {
		led_enable = false;
	}
	
	// Set the pin mode on the LED pin and turn it off.
	GPIO::set_output(led_port, led_pin, GPIO_PULL_UP);
	GPIO::write(led_port, led_pin, GPIO_LEVEL_LOW);
	
	char ch = '1';
	USART::sendUart(ud.usart, ch);
	
	// 2. Set up ADC.
	// Configure for continuous mode, multiple channels.
	// STM32F042K6 (Nucleo-F042K6): PA0, PA1 => Ch0, Ch1
	// Sample Vsense to obtain the MCU temperature.
	ADC::configure(ADC_1, ADC_MODE_CONTINUOUS);
	//ADC::channel(ADC_1, 0, GPIO_PORT_A, 0, 7);
	//ADC::channel(ADC_1, 1, GPIO_PORT_A, 1, 7);
	ADC::channel(ADC_1, ADC_VSENSE, 7);	// Sample Vsense temperature sensor. Long sampling time.
	ADC::channel(ADC_1, 0, GPIO_PORT_A, 0, 7);	// Port A, pin 0 (A0). Long sampling time.
	ADC_interrupts isr;
	isr.eoc		= conversion_complete_cb;
	isr.eoseq 	= sequence_complete_cb;
	isr.overrun = adc_overrun;
	ADC::enableInterrupt(ADC_1, isr);
	
	ch = '2';
	USART::sendUart(ud.usart, ch);
	
	// 4. Start sampling.
	while (1) {
		// 5. Stop sampling if a character is received on the USART & sampling.
		// Else start sampling.
		if (sampling_toggle) {
			//ch = 't';
			//USART::sendUart(ud.usart, ch);
			if (sampling_adc) {
				ADC::stop(ADC_1);
				sampling_adc = false;
			}
			else {
				ch = 's';
				USART::sendUart(ud.usart, ch);
				
				// Start the ADC.
				if (!ADC::start(ADC_1)) {
					ch = 'f'; // ADC start fail.
					USART::sendUart(ud.usart, ch);
					while (1) { }
				}
				
				// Start sampling.
				ADC::startSampling(ADC_1);
				
				sampling_adc = true;
			}
			
			sampling_toggle = false;
		}
		
		if (tx_ready) {
			// Transmit contents of shadow buffer on UART.
			for (uint32_t i = 0; i < buf_len; ++i) {
				uint16_t val = shadow_buffer[i];
				uint8_t* p = (uint8_t*) &val;
				char c = *p;
				USART::sendUart(ud.usart, c);
				p++;
				c = *p;
				USART::sendUart(ud.usart, c);
			}
			
			tx_ready = false;
		}
	}
}
