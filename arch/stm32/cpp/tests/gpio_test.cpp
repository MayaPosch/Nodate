/*
	gpio_test.cpp - Tests the GPIO class.
	
	Revision 0.
	
*/



#include "../core/include/gpio.h"


#include <iostream>
#include <iomanip>
#include <bitset>


int main() {
	std::cout << "Running GPIO test..." << std::endl;
	
	// Set pins in GPIO class.
	GPIO gpio;
	if (gpio.set_output(GPIO_PORT_A, 3, GPIO_PULL_UP)) { std::cout << "Set output." << std::endl; }
	if (gpio.write(GPIO_PORT_A, 3, GPIO_LEVEL_HIGH)) { std::cout << "Wrote HIGH." << std::endl; }
	if (gpio.set_output(GPIO_PORT_B, 1, GPIO_PULL_UP)) { std::cout << "Set output." << std::endl; }
	if (gpio.write(GPIO_PORT_B, 1, GPIO_LEVEL_HIGH)) { std::cout << "Wrote HIGH." << std::endl; }
	
	if (gpio.set_input(GPIO_PORT_A, 1, GPIO_PULL_UP)) { std::cout << "Set input." << std::endl; }
	if (gpio.set_input(GPIO_PORT_B, 3, GPIO_PULL_UP)) { std::cout << "Set input." << std::endl; }
	if (gpio.set_input(GPIO_PORT_D, 1, GPIO_PULL_UP)) { std::cout << "Set input." << std::endl; }
	
	// Print out the RCC AHB register.
	std::cout << std::endl;
	std::cout << "RCC" << std::endl;
#ifdef STM32F1
	std::cout << "APB2ENR:\t" << std::bitset<32>(RCC->APB2ENR) << std::endl;
#elif defined STM32F0
	std::cout << "AHBENR:\t" << std::bitset<32>(RCC->AHBENR) << std::endl;
#else
	std::cout << "AHB1ENR:\t" << std::bitset<32>(RCC->AHB1ENR) << std::endl;
#endif
	std::cout << std::endl;
	
#ifdef STM32F1
	// Print out the GPIOA CRL & CRH registers plus IDR and ODR.
	std::cout << "GPIOA" << std::endl;
	std::cout << "CRL:  \t" << std::bitset<32>(GPIOA->CRL) << std::endl;
	std::cout << "CRH:  \t" << std::bitset<32>(GPIOA->CRH) << std::endl;
	std::cout << "IDR:  \t" << std::bitset<32>(GPIOA->IDR) << std::endl;
	std::cout << "ODR:  \t" << std::bitset<32>(GPIOA->ODR) << std::endl;
#else
	// Print out the GPIOA MODER, PUPDR, OTYPER, OSPEEDR, IDR and ODR registers.
	std::cout << "GPIOA" << std::endl;
	std::cout << "MODER:  \t" << std::bitset<32>(GPIOA->MODER) << std::endl;
	std::cout << "PUPDR:  \t" << std::bitset<32>(GPIOA->PUPDR) << std::endl;
	std::cout << "OTYPER: \t" << std::bitset<32>(GPIOA->OTYPER) << std::endl;
	std::cout << "OSPEEDR:\t" << std::bitset<32>(GPIOA->OSPEEDR) << std::endl;
	std::cout << "IDR:    \t" << std::bitset<32>(GPIOA->IDR) << std::endl;
	std::cout << "ODR:    \t" << std::bitset<32>(GPIOA->ODR) << std::endl;
#endif
	std::cout << std::endl;
	
#ifdef STM32F1
	// Print out the GPIOB CRL & CRH registers plus IDR and ODR.
	std::cout << "GPIOB" << std::endl;
	std::cout << "CRL:  \t" << std::bitset<32>(GPIOB->CRL) << std::endl;
	std::cout << "CRH:  \t" << std::bitset<32>(GPIOB->CRH) << std::endl;
	std::cout << "IDR:  \t" << std::bitset<32>(GPIOB->IDR) << std::endl;
	std::cout << "ODR:  \t" << std::bitset<32>(GPIOB->ODR) << std::endl;
#else
	// Print out the GPIOB MODER, PUPDR, OTYPER, OSPEEDR, IDR and ODR registers.
	std::cout << "GPIOB" << std::endl;
	std::cout << "MODER:  \t" << std::bitset<32>(GPIOB->MODER) << std::endl;
	std::cout << "PUPDR:  \t" << std::bitset<32>(GPIOB->PUPDR) << std::endl;
	std::cout << "OTYPER: \t" << std::bitset<32>(GPIOB->OTYPER) << std::endl;
	std::cout << "OSPEEDR:\t" << std::bitset<32>(GPIOB->OSPEEDR) << std::endl;
	std::cout << "IDR:    \t" << std::bitset<32>(GPIOB->IDR) << std::endl;
	std::cout << "ODR:    \t" << std::bitset<32>(GPIOB->ODR) << std::endl;
#endif
	std::cout << std::endl;
	
#ifdef STM32F1
	// Print out the GPIOD CRL & CRH registers plus IDR and ODR.
	std::cout << "GPIOD" << std::endl;
	std::cout << "CRL:  \t" << std::bitset<32>(GPIOD->CRL) << std::endl;
	std::cout << "CRH:  \t" << std::bitset<32>(GPIOD->CRH) << std::endl;
	std::cout << "IDR:  \t" << std::bitset<32>(GPIOD->IDR) << std::endl;
	std::cout << "ODR:  \t" << std::bitset<32>(GPIOD->ODR) << std::endl;
#else
	// Print out the GPIOD MODER, PUPDR, OTYPER, OSPEEDR, IDR and ODR registers.
	std::cout << "GPIOD" << std::endl;
	std::cout << "MODER:  \t" << std::bitset<32>(GPIOD->MODER) << std::endl;
	std::cout << "PUPDR:  \t" << std::bitset<32>(GPIOD->PUPDR) << std::endl;
	std::cout << "OTYPER: \t" << std::bitset<32>(GPIOD->OTYPER) << std::endl;
	std::cout << "OSPEEDR:\t" << std::bitset<32>(GPIOD->OSPEEDR) << std::endl;
	std::cout << "IDR:    \t" << std::bitset<32>(GPIOD->IDR) << std::endl;
	std::cout << "ODR:    \t" << std::bitset<32>(GPIOD->ODR) << std::endl;
#endif
	std::cout << std::endl;
	
	return 0;
}
