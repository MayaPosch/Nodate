/*
	rcc_test.cpp - Tests the RCC class.
	
	Revision 0.
	
*/



#include "../core/include/rcc.h"


#include <iostream>
#include <iomanip>
#include <bitset>


int main() {
	std::cout << "Running RCC test..." << std::endl;
	
	// Enable peripherals in RCC class.
	Rcc::enable(RCC_SYSCFGCOMP);
	Rcc::enablePort(RCC_PORT_A);
	
	// Print out the AHB, APB1 and APB2 registers.
	std::cout << "AHB1ENR:\t" << std::bitset<32>(RCC->AHB1ENR) << std::endl;
	std::cout << "APB1ENR:\t" << std::bitset<32>(RCC->APB1ENR) << std::endl;
	std::cout << "APB2ENR:\t" << std::bitset<32>(RCC->APB2ENR) << std::endl;
	
	return 0;
}
