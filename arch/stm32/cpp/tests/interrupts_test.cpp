/*
	interrupts_test.cpp - Tests the Interrupts class.
	
	Revision 0.
	
*/



#include "../core/include/interrupts.h"


#include <iostream>
#include <iomanip>
#include <bitset>


void callBack_A() {
	std::cout << "CallBack_A triggered." << std::endl;
}


int main() {
	std::cout << "Running Interrupts test..." << std::endl;
	
	// Create Interrupts class instance.
	Interrupts itrs;
	
	// Set interrupt.
	uint8_t handleA;
	itrs.setInterrupt(0, GPIO_PORT_B, INTERRUPT_TRIGGER_FALLING, callBack_A, 0, handleA);
	
	// Print out the RCC AHB, APB1 and APB2 registers.
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
	
	return 0;
}
