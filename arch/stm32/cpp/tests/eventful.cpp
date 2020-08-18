// Basic Event example for Nodate's STM32 framework.

#include <gpio.h>
#include <interrupts.h>

#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>


volatile bool led_on;


void callBack_A() {
	led_on = !led_on;
}


void callBack_B() {
	led_on = !led_on;
}


void callBack_button() {
	//led_on = !led_on;
	led_on = true;
}


void error(std::string err) {
	std::cout << err << std::endl;
}


int main () {
	// Initialise.
	GPIO gpio;
	Interrupts itrs;
	
	// FIXME: Dynamically updated LED_BUILTIN value.
	uint8_t LED_BUILTIN = 3;
	
	// Set the pin mode on the built-in LED.
	if (!gpio.set_output(GPIO_PORT_B, LED_BUILTIN, GPIO_PULL_UP)) { error("B.3.PU fail."); }
	if (!gpio.write(GPIO_PORT_B, LED_BUILTIN, GPIO_LEVEL_LOW)) { error("B.3 := 0 fail."); }
	
	// Set the pin mode on the interrupt pins.
	if (!gpio.set_input(GPIO_PORT_B, 0, GPIO_PULL_UP)) { error("B.0.PU fail."); }
	if (!gpio.set_input(GPIO_PORT_B, 1, GPIO_PULL_UP)) { error("B.1.PU fail."); }
	if (!gpio.set_input(GPIO_PORT_B, 4, GPIO_PULL_UP)) { error("B.4.PU fail."); }
	
	// Set the interrupts for the rotary encoder.
	// A: Port B, pin 0 (D3 on Nucleo-32).
	// B: Port B, pin 1 (D6 on Nucleo-32).
	// Button: Port B, pin 4 (D12 on Nucleo-32).
	uint8_t handleA, handleB, handleC;
	itrs.setInterrupt(0, GPIO_PORT_B, INTERRUPT_TRIGGER_FALLING, callBack_A, 0, handleA);
	itrs.setInterrupt(1, GPIO_PORT_B, INTERRUPT_TRIGGER_FALLING, callBack_B, 0, handleB);
	itrs.setInterrupt(4, GPIO_PORT_B, INTERRUPT_TRIGGER_FALLING, callBack_button, 0, handleC);
	
	/* while (1) {
		if (led_on) {
			gpio.write(GPIO_PORT_B, LED_BUILTIN, GPIO_LEVEL_HIGH);
		}
		else {
			gpio.write(GPIO_PORT_B, LED_BUILTIN, GPIO_LEVEL_LOW);
		}
	} */
	
	// Print out the AHB, APB1 and APB2 registers.
	std::cout << "RCC" << std::endl;
	std::cout << "AHBENR:\t\t" << std::bitset<32>(RCC->AHBENR) << std::endl;
	std::cout << "APB1ENR:\t" << std::bitset<32>(RCC->APB1ENR) << std::endl;
	std::cout << "APB2ENR:\t" << std::bitset<32>(RCC->APB2ENR) << std::endl;
	std::cout << std::endl;
	
	// Print out the SYSCFG EXTICR registers.
	std::cout << "SYSCFG" << std::endl;
	std::cout << "EXTICR1:\t" << std::bitset<32>(SYSCFG->EXTICR[0]) << std::endl;
	std::cout << "EXTICR2:\t" << std::bitset<32>(SYSCFG->EXTICR[1]) << std::endl;
	std::cout << "EXTICR3:\t" << std::bitset<32>(SYSCFG->EXTICR[2]) << std::endl;
	std::cout << "EXTICR4:\t" << std::bitset<32>(SYSCFG->EXTICR[3]) << std::endl;
	std::cout << std::endl;
	
	// Print out the EXTI IMR, RTSR, FTSR & PR registers.
	std::cout << "EXTI" << std::endl;
	std::cout << "IMR:\t" << std::bitset<32>(EXTI->IMR) << std::endl;
	std::cout << "RTSR:\t" << std::bitset<32>(EXTI->RTSR) << std::endl;
	std::cout << "FTSR:\t" << std::bitset<32>(EXTI->FTSR) << std::endl;
	std::cout << "PR:\t" << std::bitset<32>(EXTI->PR) << std::endl;
	std::cout << std::endl;
	
	// Print out the GPIOA MODER, PUPDR, OTYPER, OSPEEDR, IDR and ODR registers.
	std::cout << "GPIOA" << std::endl;
	std::cout << "MODER:  \t" << std::bitset<32>(GPIOA->MODER) << std::endl;
	std::cout << "PUPDR:  \t" << std::bitset<32>(GPIOA->PUPDR) << std::endl;
	std::cout << "OTYPER: \t" << std::bitset<32>(GPIOA->OTYPER) << std::endl;
	std::cout << "OSPEEDR:\t" << std::bitset<32>(GPIOA->OSPEEDR) << std::endl;
	std::cout << "IDR:    \t" << std::bitset<32>(GPIOA->IDR) << std::endl;
	std::cout << "ODR:    \t" << std::bitset<32>(GPIOA->ODR) << std::endl;
	std::cout << std::endl;
	
	// Print out the GPIOB MODER, PUPDR, OTYPER, OSPEEDR, IDR and ODR registers.
	std::cout << "GPIOB" << std::endl;
	std::cout << "MODER:  \t" << std::bitset<32>(GPIOB->MODER) << std::endl;
	std::cout << "PUPDR:  \t" << std::bitset<32>(GPIOB->PUPDR) << std::endl;
	std::cout << "OTYPER: \t" << std::bitset<32>(GPIOB->OTYPER) << std::endl;
	std::cout << "OSPEEDR:\t" << std::bitset<32>(GPIOB->OSPEEDR) << std::endl;
	std::cout << "IDR:    \t" << std::bitset<32>(GPIOB->IDR) << std::endl;
	std::cout << "ODR:    \t" << std::bitset<32>(GPIOB->ODR) << std::endl;
	std::cout << std::endl;
	
	return 0;
}
