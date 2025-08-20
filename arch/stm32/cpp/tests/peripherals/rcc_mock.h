/*
	rcc_mock.h - header for the Nodate mock RCC peripheral.
	
*/


#include "chronotrigger.h"


class RCC_mock {
	ChronoTrigger ct;
	
	static void callback(int value);
	
public:
	RCC_mock();
	~RCC_mock();
};
