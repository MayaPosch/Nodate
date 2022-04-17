/*
	adc_uart_dma.cpp - Implementation of ADC to UART with DMA example.
	
	2021/04/13, Maya Posch
*/


#include <nodate.h>
//#include <printf.h>


USART_devices usartTarget = USART_1;
volatile bool sampling_toggle = false;
volatile bool sampling_adc = false;


void uartCallback(char ch) {
	sampling_toggle = !sampling_toggle;
	//USART::sendUart(usartTarget, ch);
}


// ADC sample buffer for two channels.
const uint32_t buf_len = 1024;
const uint32_t half_buf = 512;
uint16_t ADC_array[buf_len];

USART_def& ud = boardUSARTs[1];


void buffer_half_filled_cb() {
	// Copy first half of the buffer to the USART with DMA.
	DMA_callbacks cbs;
	USART::configureDMAT(ud.usart, (uint32_t*) (&ADC_array), half_buf, cbs);
}


void buffer_end_filled_cb() {
	// Copy second half of the buffer to the USART with DMA.
	DMA_callbacks cbs;
	USART::configureDMAT(ud.usart, (uint32_t*) (&ADC_array) + half_buf, half_buf, cbs);
}


void buffer_error_cb() {
	// Handle a DMA error.
	
}


int main() {
	// 1. Set up UART
	usartTarget = ud.usart;
	USART::startUart(ud.usart, ud.tx[0].port, ud.tx[0].pin, ud.tx[0].af, 
								ud.rx[0].port, ud.rx[0].pin, ud.rx[0].af, 115200, uartCallback);
								
	//IO::setStdOutTarget(ud.usart);
	
	//printf("Starting ADC & USART DMA example...\n");
	//printf("Send any character to toggle sampling.\n");
	
	// 2. Set up ADC & DMA.
	// Configure for continuous mode, single pin/channel.
	// STM32F042K6 (Nucleo-F042K6): PA0, PA1 => Ch0, Ch1
	// Sample Vsense to obtain the MCU temperature.
	ADC::configure(ADC_1, ADC_MODE_CONTINUOUS);
	//ADC::channel(ADC_1, 0, GPIO_PORT_A, 0, 7);
	//ADC::channel(ADC_1, 1, GPIO_PORT_A, 1, 7);
	ADC::channel(ADC_1, ADC_VSENSE);	// Sample Vsense temperature sensor. Default sampling time.
	//ADC::enableInterrupt(ADC_1);
	DMA_callbacks cbs;
	cbs.half = &buffer_half_filled_cb;
	cbs.filled = &buffer_end_filled_cb;
	cbs.error = &buffer_error_cb;
	ADC::configureDMA(ADC_1, (uint32_t*) &ADC_array, buf_len, cbs);
	
	
	// 4. Start sampling.
	sampling_adc = true;
	ADC::start(ADC_1);
	
	
	while (1) {
		// 5. Stop sampling if a character is received on the USART & sampling.
		// Else restart sampling.
		if (sampling_toggle) {
			if (sampling_adc) {
				ADC::stop(ADC_1);
				sampling_adc = false;
			}
			else {
				ADC::start(ADC_1);
				sampling_adc = true;
			}
			
			sampling_toggle = false;
		}
	}
	
	return 0;
}
