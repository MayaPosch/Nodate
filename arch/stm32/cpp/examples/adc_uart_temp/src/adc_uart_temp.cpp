/*
	adc_uart_temp.cpp - Implementation of ADC to UART for MCU temperature example.
	
	2022/04/20, Maya Posch
*/


#include <nodate.h>
#include <printf.h>

#ifdef __stm32f0
// Reference: RM0091, A.7.16.
// Note: calibration address may differ for other MCUs.
#define TEMP30_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7B8))
#define TEMP110_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7C2))
#define VDD_CALIB ((uint16_t) (330))
#define VDD_APPLI ((uint16_t) (330))
#elif defined __stm32f3
#define TS_CAL_30 ((uint16_t*) ((uint32_t) 0x1FFFF7B8))
#define TS_CAL_110 ((uint16_t*) ((uint32_t) 0x1FFFF7C2))
#elif defined __stm32f4
#define TS_CAL_30 ((uint16_t*) ((uint32_t) 0x1FFF7A2C))
#define TS_CAL_110 ((uint16_t*) ((uint32_t) 0x1FFF7A2E))
#endif


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
	if (!ADC::configure(ADC_1, ADC_MODE_SINGLE)) {
		printf("ADC configure failed.\n");
		while (1) { }
	}
	
	if (!ADC::channel(ADC_1, ADC_VSENSE, 7)) {	// Sample Vsense temperature sensor. Long sampling time
		printf("ADC channel configure failed.\n");
		while (1) { }
	}
	
	ADC::finishChannelConfig(ADC_1);
	
	// 3. Start the ADC.
	if (!ADC::start(ADC_1)) {
		printf("ADC start fail.\n");
		while (1) { }
	}
	
	Timer timer;
	while (1) {
		timer.delay(5000);
	
		// 4. Start sampling.
		if (!ADC::startSampling(ADC_1)) {
			printf("ADC start sampling failed.\n");
			while (1) { }
		}
		
		// 4. Get the sampled value.
		uint16_t raw;
		if (!ADC::getValue(ADC_1, raw)) {
			printf("ADC get value failed.\n");
			while (1) { }
		}
		
		// 5. Format and send to UART.
		printf("Raw: %d.\n", raw);
		
		// Debug
#ifdef __stm32f0
		printf("C30: %d.\n", *TEMP30_CAL_ADDR);
		printf("C110: %d.\n", *TEMP110_CAL_ADDR);
#else
		printf("C30: %d.\n", *TS_CAL_30);
		printf("C110: %d.\n", *TS_CAL_110);
#endif
		
		// 6. Calculate Celsius value.
		// Ref.: RM0091, A.7.16. Adapt for other MCUs.
		int32_t temperature;
#ifdef __stm32f0
		//temperature = (((int32_t) raw * VDD_APPLI / VDD_CALIB) - (int32_t) *TEMP30_CAL_ADDR);
		temperature = (((int16_t) raw) - *TEMP30_CAL_ADDR);
		temperature = temperature * (int32_t)(110 - 30);
		temperature = temperature / (int32_t)(*TEMP110_CAL_ADDR - *TEMP30_CAL_ADDR);
		temperature = temperature + 30;
		//temperature = (((110 - 30) * ((int32_t) raw - (int32_t) *TEMP30_CAL_ADDR)) / ((int32_t) *TEMP110_CAL_ADDR - (int32_t) *TEMP30_CAL_ADDR)) + 30;
#else
		temperature = (((int16_t) raw) - *TS_CAL_30);
		temperature = temperature * (int32_t)(110 - 30);
		temperature = temperature / (int32_t)(*TS_CAL_110 - *TS_CAL_30);
		temperature = temperature + 30;
#endif
		
		// 7. Print out value.
		printf("Temp: %d °C.\n", temperature);
	}
}