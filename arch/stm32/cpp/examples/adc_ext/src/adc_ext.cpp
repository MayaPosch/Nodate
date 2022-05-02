/*
	adc_ext.cpp - Implementation of ADC to UART for external input example.
	
	2022/04/28, Maya Posch
*/


#include <nodate.h>
#include <printf.h>


void uartCallback(char ch) {
	//USART::sendUart(usartTarget, ch);
}


int main() {
	// 1. Set up UART
	USART_def& ud = boardUSARTs[1];
	//usartTarget = ud.usart;
	USART::startUart(ud.usart, ud.tx[0].port, ud.tx[0].pin, ud.tx[0].af, 
								ud.rx[0].port, ud.rx[0].pin, ud.rx[0].af, 115200, uartCallback);
								
	IO::setStdOutTarget(ud.usart);
	
	// Start SysTick.
	McuCore::initSysTick();
	
	printf("Starting ADC & USART example...\n");
	
	// 2. Set up ADC.
	ADC::configure(ADC_1, ADC_MODE_SINGLE);
	ADC::channel(ADC_1, 0, GPIO_PORT_A, 0);	// Port A, pin 0 (A0). Default sampling time.
	
	// 3. Start the ADC.
	if (!ADC::start(ADC_1)) {
		printf("ADC start fail.\n");
		while (1) { }
	}
	
	Timer timer;
	while (1) {
		timer.delay(5000);
	
		// 4. Start sampling.
		ADC::startSampling(ADC_1);
		
		// 4. Get the sampled value.
		uint16_t raw;
		if (!ADC::getValue(ADC_1, raw)) {
			printf("ADC get value failed.\n");
			while (1) { }
		}
		
		// 5. Format and send to UART.
		printf("Raw: %d.\n", raw);
	}
}