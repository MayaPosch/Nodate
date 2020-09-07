/*
	uart_test.cpp - Tests the USART class.
	
	Revision 0.
	
*/



#include "../core/include/usart.h"


#include <iostream>
#include <iomanip>
#include <bitset>


void uartCallback(char ch) {
	std::cout << "Received character: " << ch << std::endl;
}


int main() {
	std::cout << "Running USART test..." << std::endl;
	
	// Start UART devices.
	if (USART::startUart(USART_1, GPIO_PORT_A, 2, 1, 
								GPIO_PORT_A, 3, 1, 
								9600, uartCallback)) { std::cout << "Start USART1." << std::endl; }
	if (USART::startUart(USART_2, GPIO_PORT_B, 0, 1, 
								GPIO_PORT_B, 8, 1, 
								9600, uartCallback)) { std::cout << "Start USART2." << std::endl; }
	
	// Print out the RCC AHB & APB1/2 registers.
	std::cout << std::endl;
	std::cout << "RCC" << std::endl;
	std::cout << "AHBENR: \t" << std::bitset<32>(RCC->AHBENR) << std::endl;
	//std::cout << "AHB1ENR:\t" << std::bitset<32>(RCC->AHB1ENR) << std::endl;
	std::cout << "APB1ENR:\t" << std::bitset<32>(RCC->APB1ENR) << std::endl;
	std::cout << "APB2ENR:\t" << std::bitset<32>(RCC->APB2ENR) << std::endl;
	std::cout << std::endl;
	
	// Print out the GPIOA MODER, PUPDR, OTYPER, OSPEEDR, IDR and ODR registers.
	std::cout << "GPIOA" << std::endl;
	std::cout << "MODER:  \t" << std::bitset<32>(GPIOA->MODER) << std::endl;
	std::cout << "PUPDR:  \t" << std::bitset<32>(GPIOA->PUPDR) << std::endl;
	std::cout << "OTYPER: \t" << std::bitset<32>(GPIOA->OTYPER) << std::endl;
	std::cout << "OSPEEDR:\t" << std::bitset<32>(GPIOA->OSPEEDR) << std::endl;
	std::cout << "IDR:    \t" << std::bitset<32>(GPIOA->IDR) << std::endl;
	std::cout << "ODR:    \t" << std::bitset<32>(GPIOA->ODR) << std::endl;
	std::cout << "AFRL:   \t" << std::bitset<32>(GPIOA->AFR[0]) << std::endl;
	std::cout << "AFRH:   \t" << std::bitset<32>(GPIOA->AFR[1]) << std::endl;
	std::cout << std::endl;
	
	// Print out the GPIOB MODER, PUPDR, OTYPER, OSPEEDR, IDR and ODR registers.
	std::cout << "GPIOB" << std::endl;
	std::cout << "MODER:  \t" << std::bitset<32>(GPIOB->MODER) << std::endl;
	std::cout << "PUPDR:  \t" << std::bitset<32>(GPIOB->PUPDR) << std::endl;
	std::cout << "OTYPER: \t" << std::bitset<32>(GPIOB->OTYPER) << std::endl;
	std::cout << "OSPEEDR:\t" << std::bitset<32>(GPIOB->OSPEEDR) << std::endl;
	std::cout << "IDR:    \t" << std::bitset<32>(GPIOB->IDR) << std::endl;
	std::cout << "ODR:    \t" << std::bitset<32>(GPIOB->ODR) << std::endl;
	std::cout << "AFRL:   \t" << std::bitset<32>(GPIOB->AFR[0]) << std::endl;
	std::cout << "AFRH:   \t" << std::bitset<32>(GPIOB->AFR[1]) << std::endl;
	std::cout << std::endl;
	
	// Print out the USART1 CR1, BRR registers.
	std::cout << "USART1" << std::endl;
	std::cout << "CR1:  \t" << std::bitset<32>(USART1->CR1) << std::endl;
	std::cout << "BRR:  \t" << std::bitset<32>(USART1->BRR) << std::endl;
	std::cout << std::endl;
	
	// Print out the USART2 CR1, BRR registers.
	std::cout << "USART2" << std::endl;
	std::cout << "CR1:  \t" << std::bitset<32>(USART2->CR1) << std::endl;
	std::cout << "BRR:  \t" << std::bitset<32>(USART2->BRR) << std::endl;
	std::cout << std::endl;
	
	return 0;
}
	