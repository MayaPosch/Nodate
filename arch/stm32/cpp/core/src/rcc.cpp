/*
	rcc.cpp - Implementation for RCC functionality.
	
*/


#include <rcc.h>

#include <limits>


// The maximum handles per port or peripheral is determined by the counter type in the item struct.
// If changed, the counter type should be updated both in the type definition and here.
static const uint8_t handle_max = std::numeric_limits<uint8_t>::max();


const int portCount = 11;
const int peripheralCount = 47;
bool getAHBprescaler(uint32_t divisor, uint32_t &AHBfield);
bool getAPB1prescaler(uint32_t divisor, uint32_t &APB1field);
bool getAPB2prescaler(uint32_t divisor, uint32_t &APB2field);

// Private methods:

// --- PORT HANDLES ---
RccPortHandle* portHandles() {
	RccPortHandle handle;
	static RccPortHandle portHandlesStatic[portCount];
	for (int i = 0; i < portCount; ++i) {
		portHandlesStatic[i] = handle;
	}
	
#ifdef RCC_AHBENR_GPIOAEN
	portHandlesStatic[RCC_PORT_A].exists = true;
	portHandlesStatic[RCC_PORT_A].enr = &(RCC->AHBENR);
	portHandlesStatic[RCC_PORT_A].enable = RCC_AHBENR_GPIOAEN_Pos;
#elif defined RCC_AHB1ENR_GPIOAEN
	portHandlesStatic[RCC_PORT_A].exists = true;
	portHandlesStatic[RCC_PORT_A].enr = &(RCC->AHB1ENR);
	portHandlesStatic[RCC_PORT_A].enable = RCC_AHB1ENR_GPIOAEN_Pos;
#elif defined RCC_APB2ENR_IOPAEN
	portHandlesStatic[RCC_PORT_A].exists = true;
	portHandlesStatic[RCC_PORT_A].enr = &(RCC->APB2ENR);
	portHandlesStatic[RCC_PORT_A].enable = RCC_APB2ENR_IOPAEN_Pos;
#elif defined RCC_AHB2ENR_GPIOAEN
	portHandlesStatic[RCC_PORT_A].exists = true;
	portHandlesStatic[RCC_PORT_A].enr = &(RCC->AHB2ENR);
	portHandlesStatic[RCC_PORT_A].enable = RCC_AHB2ENR_GPIOAEN_Pos;
#endif

#ifdef RCC_AHBENR_GPIOBEN
	portHandlesStatic[RCC_PORT_B].exists = true;
	portHandlesStatic[RCC_PORT_B].enr = &(RCC->AHBENR);
	portHandlesStatic[RCC_PORT_B].enable = RCC_AHBENR_GPIOBEN_Pos;
#elif defined RCC_AHB1ENR_GPIOBEN
	portHandlesStatic[RCC_PORT_B].exists = true;
	portHandlesStatic[RCC_PORT_B].enr = &(RCC->AHB1ENR);
	portHandlesStatic[RCC_PORT_B].enable = RCC_AHB1ENR_GPIOBEN_Pos;
#elif defined RCC_APB2ENR_IOPBEN
	portHandlesStatic[RCC_PORT_B].exists = true;
	portHandlesStatic[RCC_PORT_B].enr = &(RCC->APB2ENR);
	portHandlesStatic[RCC_PORT_B].enable = RCC_APB2ENR_IOPBEN_Pos;
#elif defined RCC_AHB2ENR_GPIOBEN
	portHandlesStatic[RCC_PORT_B].exists = true;
	portHandlesStatic[RCC_PORT_B].enr = &(RCC->AHB2ENR);
	portHandlesStatic[RCC_PORT_B].enable = RCC_AHB2ENR_GPIOBEN_Pos;
#endif

#ifdef RCC_AHBENR_GPIOCEN
	portHandlesStatic[RCC_PORT_C].exists = true;
	portHandlesStatic[RCC_PORT_C].enr = &(RCC->AHBENR);
	portHandlesStatic[RCC_PORT_C].enable = RCC_AHBENR_GPIOCEN_Pos;
#elif defined RCC_AHB1ENR_GPIOCEN
	portHandlesStatic[RCC_PORT_C].exists = true;
	portHandlesStatic[RCC_PORT_C].enr = &(RCC->AHB1ENR);
	portHandlesStatic[RCC_PORT_C].enable = RCC_AHB1ENR_GPIOCEN_Pos;
#elif defined RCC_APB2ENR_IOPCEN
	portHandlesStatic[RCC_PORT_C].exists = true;
	portHandlesStatic[RCC_PORT_C].enr = &(RCC->APB2ENR);
	portHandlesStatic[RCC_PORT_C].enable = RCC_APB2ENR_IOPCEN_Pos;
#elif defined RCC_AHB2ENR_GPIOCEN
	portHandlesStatic[RCC_PORT_C].exists = true;
	portHandlesStatic[RCC_PORT_C].enr = &(RCC->AHB2ENR);
	portHandlesStatic[RCC_PORT_C].enable = RCC_AHB2ENR_GPIOCEN_Pos;
#endif

#ifdef RCC_AHBENR_GPIODEN
	portHandlesStatic[RCC_PORT_D].exists = true;
	portHandlesStatic[RCC_PORT_D].enr = &(RCC->AHBENR);
	portHandlesStatic[RCC_PORT_D].enable = RCC_AHBENR_GPIODEN_Pos;
#elif defined RCC_AHB1ENR_GPIODEN
	portHandlesStatic[RCC_PORT_D].exists = true;
	portHandlesStatic[RCC_PORT_D].enr = &(RCC->AHB1ENR);
	portHandlesStatic[RCC_PORT_D].enable = RCC_AHB1ENR_GPIODEN_Pos;
#elif defined RCC_APB2ENR_IOPDEN
	portHandlesStatic[RCC_PORT_D].exists = true;
	portHandlesStatic[RCC_PORT_D].enr = &(RCC->APB2ENR);
	portHandlesStatic[RCC_PORT_D].enable = RCC_APB2ENR_IOPDEN_Pos;
#elif defined RCC_AHB2ENR_GPIODEN
	portHandlesStatic[RCC_PORT_D].exists = true;
	portHandlesStatic[RCC_PORT_D].enr = &(RCC->AHB2ENR);
	portHandlesStatic[RCC_PORT_D].enable = RCC_AHB2ENR_GPIODEN_Pos;
#endif

#ifdef RCC_AHBENR_GPIOEEN
	portHandlesStatic[RCC_PORT_E].exists = true;
	portHandlesStatic[RCC_PORT_E].enr = &(RCC->AHBENR);
	portHandlesStatic[RCC_PORT_E].enable = RCC_AHBENR_GPIOEEN_Pos;
#elif defined RCC_AHB1ENR_GPIOEEN
	portHandlesStatic[RCC_PORT_E].exists = true;
	portHandlesStatic[RCC_PORT_E].enr = &(RCC->AHB1ENR);
	portHandlesStatic[RCC_PORT_E].enable = RCC_AHB1ENR_GPIOEEN_Pos;
#elif defined RCC_APB2ENR_IOPEEN
	portHandlesStatic[RCC_PORT_E].exists = true;
	portHandlesStatic[RCC_PORT_E].enr = &(RCC->APB2ENR);
	portHandlesStatic[RCC_PORT_E].enable = RCC_APB2ENR_IOPEEN_Pos;
#elif defined RCC_AHB2ENR_GPIOeEN
	portHandlesStatic[RCC_PORT_E].exists = true;
	portHandlesStatic[RCC_PORT_E].enr = &(RCC->AHB2ENR);
	portHandlesStatic[RCC_PORT_E].enable = RCC_AHB2ENR_GPIOEEN_Pos;
#endif

#ifdef RCC_AHBENR_GPIOFEN
	portHandlesStatic[RCC_PORT_F].exists = true;
	portHandlesStatic[RCC_PORT_F].enr = &(RCC->AHBENR);
	portHandlesStatic[RCC_PORT_F].enable = RCC_AHBENR_GPIOFEN_Pos;
#elif defined RCC_AHB1ENR_GPIOFEN
	portHandlesStatic[RCC_PORT_F].exists = true;
	portHandlesStatic[RCC_PORT_F].enr = &(RCC->AHB1ENR);
	portHandlesStatic[RCC_PORT_F].enable = RCC_AHB1ENR_GPIOFEN_Pos;
#elif defined RCC_AHB2ENR_GPIOFEN
	portHandlesStatic[RCC_PORT_F].exists = true;
	portHandlesStatic[RCC_PORT_F].enr = &(RCC->AHB2ENR);
	portHandlesStatic[RCC_PORT_F].enable = RCC_AHB2ENR_GPIOFEN_Pos;
#endif

#ifdef RCC_AHBENR_GPIOGEN
	portHandlesStatic[RCC_PORT_G].exists = true;
	portHandlesStatic[RCC_PORT_G].enr = &(RCC->AHBENR);
	portHandlesStatic[RCC_PORT_G].enable = RCC_AHBENR_GPIOGEN_Pos;
#elif defined RCC_AHB1ENR_GPIOGEN
	portHandlesStatic[RCC_PORT_G].exists = true;
	portHandlesStatic[RCC_PORT_G].enr = &(RCC->AHB1ENR);
	portHandlesStatic[RCC_PORT_G].enable = RCC_AHB1ENR_GPIOGEN_Pos;
#elif defined RCC_AHB2ENR_GPIOGEN
	portHandlesStatic[RCC_PORT_G].exists = true;
	portHandlesStatic[RCC_PORT_G].enr = &(RCC->AHB2ENR);
	portHandlesStatic[RCC_PORT_G].enable = RCC_AHB2ENR_GPIOGEN_Pos;
#endif

#ifdef RCC_AHBENR_GPIOHEN
	portHandlesStatic[RCC_PORT_H].exists = true;
	portHandlesStatic[RCC_PORT_H].enr = &(RCC->AHBENR);
	portHandlesStatic[RCC_PORT_H].enable = RCC_AHBENR_GPIOHEN_Pos;
#elif defined RCC_AHB1ENR_GPIOHEN
	portHandlesStatic[RCC_PORT_H].exists = true;
	portHandlesStatic[RCC_PORT_H].enr = &(RCC->AHB1ENR);
	portHandlesStatic[RCC_PORT_H].enable = RCC_AHB1ENR_GPIOHEN_Pos;
#elif defined RCC_AHB2ENR_GPIOHEN
	portHandlesStatic[RCC_PORT_H].exists = true;
	portHandlesStatic[RCC_PORT_H].enr = &(RCC->AHB2ENR);
	portHandlesStatic[RCC_PORT_H].enable = RCC_AHB2ENR_GPIOHEN_Pos;
#endif

#ifdef RCC_AHBENR_GPIOIEN
	portHandlesStatic[RCC_PORT_I].exists = true;
	portHandlesStatic[RCC_PORT_I].enr = &(RCC->AHBENR);
	portHandlesStatic[RCC_PORT_I].enable = RCC_AHBENR_GPIOIEN_Pos;
#elif defined RCC_AHB1ENR_GPIOIEN
	portHandlesStatic[RCC_PORT_I].exists = true;
	portHandlesStatic[RCC_PORT_I].enr = &(RCC->AHB1ENR);
	portHandlesStatic[RCC_PORT_I].enable = RCC_AHB1ENR_GPIOIEN_Pos;
#elif defined RCC_AHB2ENR_GPIOIEN
	portHandlesStatic[RCC_PORT_I].exists = true;
	portHandlesStatic[RCC_PORT_I].enr = &(RCC->AHB2ENR);
	portHandlesStatic[RCC_PORT_I].enable = RCC_AHB2ENR_GPIOIEN_Pos;
#endif

#ifdef RCC_AHBENR_GPIOJEN
	portHandlesStatic[RCC_PORT_J].exists = true;
	portHandlesStatic[RCC_PORT_J].enr = &(RCC->AHBENR);
	portHandlesStatic[RCC_PORT_J].enable = RCC_AHBENR_GPIOJEN_Pos;
#elif defined RCC_AHB1ENR_GPIOJEN
	portHandlesStatic[RCC_PORT_J].exists = true;
	portHandlesStatic[RCC_PORT_J].enr = &(RCC->AHB1ENR);
	portHandlesStatic[RCC_PORT_J].enable = RCC_AHB1ENR_GPIOJEN_Pos;
#elif defined RCC_AHB2ENR_GPIOJEN
	portHandlesStatic[RCC_PORT_J].exists = true;
	portHandlesStatic[RCC_PORT_J].enr = &(RCC->AHB2ENR);
	portHandlesStatic[RCC_PORT_J].enable = RCC_AHB2ENR_GPIOJEN_Pos;
#endif

#ifdef RCC_AHBENR_GPIOKEN
	portHandlesStatic[RCC_PORT_K].exists = true;
	portHandlesStatic[RCC_PORT_K].enr = &(RCC->AHBENR);
	portHandlesStatic[RCC_PORT_K].enable = RCC_AHBENR_GPIOKEN_Pos;
#elif defined RCC_AHB1ENR_GPIOKEN
	portHandlesStatic[RCC_PORT_K].exists = true;
	portHandlesStatic[RCC_PORT_K].enr = &(RCC->AHB1ENR);
	portHandlesStatic[RCC_PORT_K].enable = RCC_AHB1ENR_GPIOKEN_Pos;
#elif defined RCC_AHB2ENR_GPIOKEN
	portHandlesStatic[RCC_PORT_K].exists = true;
	portHandlesStatic[RCC_PORT_K].enr = &(RCC->AHB2ENR);
	portHandlesStatic[RCC_PORT_K].enable = RCC_AHB2ENR_GPIOKEN_Pos;
#endif
	
	return portHandlesStatic;
}

//RccPortHandle* portHandlesStatic = portHandles();


// --- PERIPHERAL HANDLES ---
RccPeripheralHandle* peripheralHandles() {
	RccPeripheralHandle handle;
	static RccPeripheralHandle peripheralHandlesStatic[peripheralCount];
	for (int i = 0; i < peripheralCount; ++i) {
		peripheralHandlesStatic[i] = handle;
	}
	
	// AHB
	
#ifdef RCC_AHBENR_TSCEN
	peripheralHandlesStatic[RCC_TSC].exists = true;
	peripheralHandlesStatic[RCC_TSC].enr = &(RCC->AHBENR);
	peripheralHandlesStatic[RCC_TSC].enable = RCC_AHBENR_TSCEN_Pos;
#endif

#ifdef RCC_AHBENR_CRCEN
	peripheralHandlesStatic[RCC_CRC].exists = true;
	peripheralHandlesStatic[RCC_CRC].enr = &(RCC->AHBENR);
	peripheralHandlesStatic[RCC_CRC].enable = RCC_AHBENR_CRCEN_Pos;
#elif defined RCC_AHB1ENR_CRCEN
	peripheralHandlesStatic[RCC_CRC].exists = true;
	peripheralHandlesStatic[RCC_CRC].enr = &(RCC->AHB1ENR);
	peripheralHandlesStatic[RCC_CRC].enable = RCC_AHB1ENR_CRCEN_Pos;
#endif

#ifdef RCC_AHBENR_FLITFEN
	peripheralHandlesStatic[RCC_FLITF].exists = true;
	peripheralHandlesStatic[RCC_FLITF].enr = &(RCC->AHBENR);
	peripheralHandlesStatic[RCC_FLITF].enable = RCC_AHBENR_FLITFEN_Pos;
#endif

#ifdef RCC_AHBENR_SRAMEN
	peripheralHandlesStatic[RCC_SRAM].exists = true;
	peripheralHandlesStatic[RCC_SRAM].enr = &(RCC->AHBENR);
	peripheralHandlesStatic[RCC_SRAM].enable = RCC_AHBENR_SRAMEN_Pos;
#endif

#ifdef RCC_AHBENR_DMA2EN
	peripheralHandlesStatic[RCC_DMA2].exists = true;
	peripheralHandlesStatic[RCC_DMA2].enr = &(RCC->AHBENR);
	peripheralHandlesStatic[RCC_DMA2].enable = RCC_AHBENR_DMA2EN_Pos;
#elif defined RCC_AHB1ENR_DMA2EN
	peripheralHandlesStatic[RCC_DMA2].exists = true;
	peripheralHandlesStatic[RCC_DMA2].enr = &(RCC->AHB1ENR);
	peripheralHandlesStatic[RCC_DMA2].enable = RCC_AHB1ENR_DMA2EN_Pos;
#endif

#ifdef RCC_AHBENR_DMAEN
	peripheralHandlesStatic[RCC_DMA1].exists = true;
	peripheralHandlesStatic[RCC_DMA1].enr = &(RCC->AHBENR);
	peripheralHandlesStatic[RCC_DMA1].enable = RCC_AHBENR_DMAEN_Pos;
#elif defined RCC_AHB1ENR_DMA1EN
	peripheralHandlesStatic[RCC_DMA1].exists = true;
	peripheralHandlesStatic[RCC_DMA1].enr = &(RCC->AHB1ENR);
	peripheralHandlesStatic[RCC_DMA1].enable = RCC_AHB1ENR_DMA1EN_Pos;
#endif

#ifdef RCC_AHB1ENR_ETHMACEN
	peripheralHandlesStatic[RCC_ETH].exists = true;
	peripheralHandlesStatic[RCC_ETH].enr = &(RCC->AHB1ENR);
	peripheralHandlesStatic[RCC_ETH].enable = RCC_AHB1ENR_ETHMACEN_Pos;
#endif

#ifdef RCC_AHBENR_ADC12EN
	peripheralHandlesStatic[RCC_ADC1].exists = true;
	peripheralHandlesStatic[RCC_ADC1].enr = &(RCC->AHBENR);
	peripheralHandlesStatic[RCC_ADC1].enable = RCC_AHBENR_ADC12EN_Pos;
	peripheralHandlesStatic[RCC_ADC2].exists = true;
	peripheralHandlesStatic[RCC_ADC2].enr = &(RCC->AHBENR);
	peripheralHandlesStatic[RCC_ADC2].enable = RCC_AHBENR_ADC12EN_Pos;
#endif

	// APB2

#ifdef RCC_APB2ENR_SYSCFGCOMPEN
	peripheralHandlesStatic[RCC_SYSCFGCOMP].exists = true;
	peripheralHandlesStatic[RCC_SYSCFGCOMP].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_SYSCFGCOMP].enable = RCC_APB2ENR_SYSCFGCOMPEN_Pos;
#elif defined RCC_APB2ENR_SYSCFGEN
	peripheralHandlesStatic[RCC_SYSCFGCOMP].exists = true;
	peripheralHandlesStatic[RCC_SYSCFGCOMP].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_SYSCFGCOMP].enable = RCC_APB2ENR_SYSCFGEN_Pos;
#endif

#ifdef RCC_APB2ENR_USART6EN
	peripheralHandlesStatic[RCC_USART6].exists = true;
	peripheralHandlesStatic[RCC_USART6].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_USART6].enable = RCC_APB2ENR_USART6EN_Pos;
#endif

#ifdef RCC_APB2ENR_USART7EN
	peripheralHandlesStatic[RCC_USART7].exists = true;
	peripheralHandlesStatic[RCC_USART7].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_USART7].enable = RCC_APB2ENR_USART7EN_Pos;
#endif

#ifdef RCC_APB2ENR_USART8EN
	peripheralHandlesStatic[RCC_USART8].exists = true;
	peripheralHandlesStatic[RCC_USART8].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_USART8].enable = RCC_APB2ENR_USART8EN_Pos;
#endif

#ifdef RCC_APB2ENR_ADCEN
	peripheralHandlesStatic[RCC_ADC1].exists = true;
	peripheralHandlesStatic[RCC_ADC1].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_ADC1].enable = RCC_APB2ENR_ADCEN_Pos;
#elif defined RCC_APB2ENR_ADC1EN
	peripheralHandlesStatic[RCC_ADC1].exists = true;
	peripheralHandlesStatic[RCC_ADC1].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_ADC1].enable = RCC_APB2ENR_ADC1EN_Pos;
#elif defined RCC_AHB2ENR_ADCEN
	peripheralHandlesStatic[RCC_ADC1].exists = true;
	peripheralHandlesStatic[RCC_ADC1].enr = &(RCC->AHB2ENR);
	peripheralHandlesStatic[RCC_ADC1].enable = RCC_AHB2ENR_ADCEN_Pos;
#endif

#ifdef RCC_APB2ENR_ADC2EN
	peripheralHandlesStatic[RCC_ADC2].exists = true;
	peripheralHandlesStatic[RCC_ADC2].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_ADC2].enable = RCC_APB2ENR_ADC2EN_Pos;
#endif

#ifdef RCC_APB2ENR_ADC3EN
	peripheralHandlesStatic[RCC_ADC3].exists = true;
	peripheralHandlesStatic[RCC_ADC3].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_ADC3].enable = RCC_APB2ENR_ADC3EN_Pos;
#endif

#ifdef RCC_APB2ENR_TIM1EN
	peripheralHandlesStatic[RCC_TIM1].exists = true;
	peripheralHandlesStatic[RCC_TIM1].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_TIM1].enable = RCC_APB2ENR_TIM1EN_Pos;
#endif

#ifdef RCC_APB2ENR_SPI1EN
	peripheralHandlesStatic[RCC_SPI1].exists = true;
	peripheralHandlesStatic[RCC_SPI1].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_SPI1].enable = RCC_APB2ENR_SPI1EN_Pos;
#endif

#ifdef RCC_APB2ENR_SPI4EN
	peripheralHandlesStatic[RCC_SPI4].exists = true;
	peripheralHandlesStatic[RCC_SPI4].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_SPI4].enable = RCC_APB2ENR_SPI4EN_Pos;
#endif

#ifdef RCC_APB2ENR_SPI5EN
	peripheralHandlesStatic[RCC_SPI5].exists = true;
	peripheralHandlesStatic[RCC_SPI5].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_SPI5].enable = RCC_APB2ENR_SPI5EN_Pos;
#endif

#ifdef RCC_APB2ENR_USART1EN
	peripheralHandlesStatic[RCC_USART1].exists = true;
	peripheralHandlesStatic[RCC_USART1].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_USART1].enable = RCC_APB2ENR_USART1EN_Pos;
#endif

#ifdef RCC_APB2ENR_TIM15EN
	peripheralHandlesStatic[RCC_TIM15].exists = true;
	peripheralHandlesStatic[RCC_TIM15].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_TIM15].enable = RCC_APB2ENR_TIM15EN_Pos;
#endif

#ifdef RCC_APB2ENR_TIM16EN
	peripheralHandlesStatic[RCC_TIM16].exists = true;
	peripheralHandlesStatic[RCC_TIM16].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_TIM16].enable = RCC_APB2ENR_TIM16EN_Pos;
#endif

#ifdef RCC_APB2ENR_TIM17EN
	peripheralHandlesStatic[RCC_TIM17].exists = true;
	peripheralHandlesStatic[RCC_TIM17].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_TIM17].enable = RCC_APB2ENR_TIM17EN_Pos;
#endif

#ifdef RCC_APB2ENR_DBGMCUEN
	peripheralHandlesStatic[RCC_DBGMCU].exists = true;
	peripheralHandlesStatic[RCC_DBGMCU].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_DBGMCU].enable = RCC_APB2ENR_DBGMCUEN_Pos;
#endif

#ifdef RCC_APB2ENR_AFIOEN
	peripheralHandlesStatic[RCC_AFIO].exists = true;
	peripheralHandlesStatic[RCC_AFIO].enr = &(RCC->APB2ENR);
	peripheralHandlesStatic[RCC_AFIO].enable = RCC_APB2ENR_AFIOEN_Pos;
#endif
	
	// APB1

#ifdef RCC_APB1ENR_TIM2EN
	peripheralHandlesStatic[RCC_TIM2].exists = true;
	peripheralHandlesStatic[RCC_TIM2].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_TIM2].enable = RCC_APB1ENR_TIM2EN_Pos;
#elif defined RCC_APB1ENR1_TIM2EN
	peripheralHandlesStatic[RCC_TIM2].exists = true;
	peripheralHandlesStatic[RCC_TIM2].enr = &(RCC->APB1ENR1);
	peripheralHandlesStatic[RCC_TIM2].enable = RCC_APB1ENR1_TIM2EN_Pos;
#endif

#ifdef RCC_APB1ENR_TIM3EN
	peripheralHandlesStatic[RCC_TIM3].exists = true;
	peripheralHandlesStatic[RCC_TIM3].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_TIM3].enable = RCC_APB1ENR_TIM3EN_Pos;
#elif defined RCC_APB1ENR1_TIM3EN
	peripheralHandlesStatic[RCC_TIM3].exists = true;
	peripheralHandlesStatic[RCC_TIM3].enr = &(RCC->APB1ENR1);
	peripheralHandlesStatic[RCC_TIM3].enable = RCC_APB1ENR1_TIM3EN_Pos;
#endif

#ifdef RCC_APB1ENR_TIM4EN
	peripheralHandlesStatic[RCC_TIM4].exists = true;
	peripheralHandlesStatic[RCC_TIM4].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_TIM4].enable = RCC_APB1ENR_TIM4EN_Pos;
#endif

#ifdef RCC_APB1ENR_TIM6EN
	peripheralHandlesStatic[RCC_TIM6].exists = true;
	peripheralHandlesStatic[RCC_TIM6].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_TIM6].enable = RCC_APB1ENR_TIM6EN_Pos;
#elif defined RCC_APB1ENR1_TIM6EN
	peripheralHandlesStatic[RCC_TIM6].exists = true;
	peripheralHandlesStatic[RCC_TIM6].enr = &(RCC->APB1ENR1);
	peripheralHandlesStatic[RCC_TIM6].enable = RCC_APB1ENR1_TIM6EN_Pos;
#endif

#ifdef RCC_APB1ENR_TIM7EN
	peripheralHandlesStatic[RCC_TIM7].exists = true;
	peripheralHandlesStatic[RCC_TIM7].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_TIM7].enable = RCC_APB1ENR_TIM7EN_Pos;
#elif defined RCC_APB1ENR1_TIM7EN
	peripheralHandlesStatic[RCC_TIM7].exists = true;
	peripheralHandlesStatic[RCC_TIM7].enr = &(RCC->APB1ENR1);
	peripheralHandlesStatic[RCC_TIM7].enable = RCC_APB1ENR1_TIM7EN_Pos;
#endif

#ifdef RCC_APB1ENR_TIM14EN
	peripheralHandlesStatic[RCC_TIM14].exists = true;
	peripheralHandlesStatic[RCC_TIM14].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_TIM14].enable = RCC_APB1ENR_TIM14EN_Pos;
#endif

#ifdef RCC_APB1ENR_WWDGEN
	peripheralHandlesStatic[RCC_WWDG].exists = true;
	peripheralHandlesStatic[RCC_WWDG].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_WWDG].enable = RCC_APB1ENR_WWDGEN_Pos;
#endif

#ifdef RCC_APB1ENR_SPI2EN
	peripheralHandlesStatic[RCC_SPI2].exists = true;
	peripheralHandlesStatic[RCC_SPI2].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_SPI2].enable = RCC_APB1ENR_SPI2EN_Pos;
#endif

#ifdef RCC_APB1ENR_SPI3EN
	peripheralHandlesStatic[RCC_SPI3].exists = true;
	peripheralHandlesStatic[RCC_SPI3].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_SPI3].enable = RCC_APB1ENR_SPI3EN_Pos;
#endif

#ifdef RCC_APB1ENR_USART2EN
	peripheralHandlesStatic[RCC_USART2].exists = true;
	peripheralHandlesStatic[RCC_USART2].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_USART2].enable = RCC_APB1ENR_USART2EN_Pos;
#elif defined RCC_APB1ENR1_USART2EN
	peripheralHandlesStatic[RCC_USART2].exists = true;
	peripheralHandlesStatic[RCC_USART2].enr = &(RCC->APB1ENR1);
	peripheralHandlesStatic[RCC_USART2].enable = RCC_APB1ENR1_USART2EN_Pos;
#endif

#ifdef RCC_APB1ENR_USART3EN
	peripheralHandlesStatic[RCC_USART3].exists = true;
	peripheralHandlesStatic[RCC_USART3].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_USART3].enable = RCC_APB1ENR_USART3EN_Pos;
#elif defined RCC_APB1ENR1_USART3EN
	peripheralHandlesStatic[RCC_USART3].exists = true;
	peripheralHandlesStatic[RCC_USART3].enr = &(RCC->APB1ENR1);
	peripheralHandlesStatic[RCC_USART3].enable = RCC_APB1ENR1_USART3EN_Pos;
#endif

#ifdef RCC_APB1ENR_USART4EN
	peripheralHandlesStatic[RCC_USART4].exists = true;
	peripheralHandlesStatic[RCC_USART4].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_USART4].enable = RCC_APB1ENR_USART4EN_Pos;
#elif defined RCC_APB1ENR1_USART4EN
	peripheralHandlesStatic[RCC_USART4].exists = true;
	peripheralHandlesStatic[RCC_USART4].enr = &(RCC->APB1ENR1);
	peripheralHandlesStatic[RCC_USART4].enable = RCC_APB1ENR1_USART4EN_Pos;
#endif

#ifdef RCC_APB1ENR_USART5EN
	peripheralHandlesStatic[RCC_USART5].exists = true;
	peripheralHandlesStatic[RCC_USART5].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_USART5].enable = RCC_APB1ENR_USART5EN_Pos;
#endif

#ifdef RCC_APB1ENR_USART7EN
	peripheralHandlesStatic[RCC_USART7].exists = true;
	peripheralHandlesStatic[RCC_USART7].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_USART7].enable = RCC_APB1ENR_UART7EN_Pos;
#endif

#ifdef RCC_APB1ENR_USART8EN
	peripheralHandlesStatic[RCC_USART8].exists = true;
	peripheralHandlesStatic[RCC_USART8].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_USART8].enable = RCC_APB1ENR_UART8EN_Pos;
#endif

#ifdef RCC_APB1ENR_I2C1EN
	peripheralHandlesStatic[RCC_I2C1].exists = true;
	peripheralHandlesStatic[RCC_I2C1].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_I2C1].enable = RCC_APB1ENR_I2C1EN_Pos;
#elif defined RCC_APB1ENR1_I2C1EN
	peripheralHandlesStatic[RCC_I2C1].exists = true;
	peripheralHandlesStatic[RCC_I2C1].enr = &(RCC->APB1ENR1);
	peripheralHandlesStatic[RCC_I2C1].enable = RCC_APB1ENR1_I2C1EN_Pos;
#endif

#ifdef RCC_APB1ENR_I2C2EN
	peripheralHandlesStatic[RCC_I2C2].exists = true;
	peripheralHandlesStatic[RCC_I2C2].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_I2C2].enable = RCC_APB1ENR_I2C2EN_Pos;
#elif defined RCC_APB1ENR1_I2C2EN
	peripheralHandlesStatic[RCC_I2C2].exists = true;
	peripheralHandlesStatic[RCC_I2C2].enr = &(RCC->APB1ENR1);
	peripheralHandlesStatic[RCC_I2C2].enable = RCC_APB1ENR1_I2C2EN_Pos;
#endif

#ifdef RCC_APB1ENR_USBEN
	peripheralHandlesStatic[RCC_USB].exists = true;
	peripheralHandlesStatic[RCC_USB].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_USB].enable = RCC_APB1ENR_USBEN_Pos;
#elif defined RCC_APB1ENR1_USBFSEN
	peripheralHandlesStatic[RCC_USB].exists = true;
	peripheralHandlesStatic[RCC_USB].enr = &(RCC->APB1ENR1);
	peripheralHandlesStatic[RCC_USB].enable = RCC_APB1ENR1_USBFSEN_Pos;
#endif

#ifdef RCC_APB1ENR_CANEN
	peripheralHandlesStatic[RCC_CAN].exists = true;
	peripheralHandlesStatic[RCC_CAN].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_CAN].enable = RCC_APB1ENR_CANEN_Pos;
#elif defined RCC_APB1ENR1_CAN1EN
	peripheralHandlesStatic[RCC_CAN].exists = true;
	peripheralHandlesStatic[RCC_CAN].enr = &(RCC->APB1ENR1);
	peripheralHandlesStatic[RCC_CAN].enable = RCC_APB1ENR1_CAN1EN_Pos;
#endif

#ifdef RCC_APB1ENR_CRSEN
	peripheralHandlesStatic[RCC_CRS].exists = true;
	peripheralHandlesStatic[RCC_CRS].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_CRS].enable = RCC_APB1ENR_CRSEN_Pos;
#elif defined RCC_APB1ENR1_CRSEN
	peripheralHandlesStatic[RCC_CRS].exists = true;
	peripheralHandlesStatic[RCC_CRS].enr = &(RCC->APB1ENR1);
	peripheralHandlesStatic[RCC_CRS].enable = RCC_APB1ENR1_CRSEN_Pos;
#endif

#ifdef RCC_APB1ENR_PWREN
	peripheralHandlesStatic[RCC_PWR].exists = true;
	peripheralHandlesStatic[RCC_PWR].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_PWR].enable = RCC_APB1ENR_PWREN_Pos;
#elif defined RCC_APB1ENR1_PWREN
	peripheralHandlesStatic[RCC_PWR].exists = true;
	peripheralHandlesStatic[RCC_PWR].enr = &(RCC->APB1ENR1);
	peripheralHandlesStatic[RCC_PWR].enable = RCC_APB1ENR1_PWREN_Pos;
#endif

#ifdef RCC_APB1ENR_BKPEN
	peripheralHandlesStatic[RCC_BKP].exists = true;
	peripheralHandlesStatic[RCC_BKP].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_BKP].enable = RCC_APB1ENR_BKPEN_Pos;
#endif

/* #ifdef RCC_APB1ENR_DACEN
	peripheralHandlesStatic[RCC_DAC].exists = true;
	peripheralHandlesStatic[RCC_DAC].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_DAC].enable = RCC_APB1ENR_DACEN_Pos;
#elif defined RCC_APB1ENR1_DAC1EN */
#if defined RCC_APB1ENR_DAC1EN
	peripheralHandlesStatic[RCC_DAC1].exists = true;
	peripheralHandlesStatic[RCC_DAC1].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_DAC1].enable = RCC_APB1ENR_DAC1EN_Pos;
#endif

#if defined RCC_APB1ENR_DAC2EN
	peripheralHandlesStatic[RCC_DAC2].exists = true;
	peripheralHandlesStatic[RCC_DAC2].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_DAC2].enable = RCC_APB1ENR_DAC2EN_Pos;
#endif

#ifdef RCC_APB1ENR_CECEN
	peripheralHandlesStatic[RCC_CEC].exists = true;
	peripheralHandlesStatic[RCC_CEC].enr = &(RCC->APB1ENR);
	peripheralHandlesStatic[RCC_CEC].enable = RCC_APB1ENR_CECEN_Pos;
#endif
	
	return peripheralHandlesStatic;
}

//RccPeripheralHandle* perHandlesStatic = peripheralHandles();


// Public methods:

// --- ENABLE ---
// Enable the target peripheral. 
// Returns true if the peripheral was successfully turned on, or if the peripheral was already on.
// Returns false if the peripheral could not be turned on. 
bool Rcc::enable(RccPeripheral peripheral) {
	uint8_t perNum = (uint8_t) peripheral;
	RccPeripheralHandle* perHandlesStatic = peripheralHandles();
	RccPeripheralHandle &ph = perHandlesStatic[perNum];
	
	if (ph.exists == false) {
		// TODO: set reason.
		return false;
	}
	
	// Check the current peripheral status.
	if (ph.count > 0) {
		if (ph.count >= handle_max) {
			// Reached maximum handles. Return false to prevent counter overflow.
			// TODO: set reason.
			return false;
		}
		
		// Increase handler count by one.
		ph.count++;
	}
	else {
		// Activate the peripheral.
		ph.count = 1;
		*(ph.enr) |= (1 << ph.enable);
	}
	
	return true;
}


// --- DISABLE ---
// Disable the target peripheral.
// Returns true if the disable request was received but not processed due to outstanding handles, or
// if the peripheral was successfully disabled.
// Returns false if the request was rejected or disabling the peripheral failed.
bool Rcc::disable(RccPeripheral peripheral) {
	uint8_t perNum = (uint8_t) peripheral;
	RccPeripheralHandle* perHandlesStatic = peripheralHandles();
	RccPeripheralHandle &ph = perHandlesStatic[perNum];
	
	if (ph.exists == false) {
		// TODO: set reason.
		return false;
	}
	
	if (ph.count > 1) {
		// Decrease handler count by one.
		ph.count--;
	}
	else {
		// Deactivate the peripheral.
		ph.count = 0;
		*(ph.enr) &= ~(1 << ph.enable);
	}
	
	return true;
}


// --- ENABLE PORT ---
// Returns true if the port was already enabled, or was successfully enabled.
// Returns false if the port could not be enabled.
bool Rcc::enablePort(RccPort port) {
	uint8_t portNum = (uint8_t) port;
	RccPortHandle* portHandlesStatic = portHandles();
	RccPortHandle &ph = portHandlesStatic[portNum];
	
	if (ph.exists == false) {
		// TODO: set reason.
		return false; 
	}
	
	// Check the current port status.
	if (ph.count > 0) {
		if (ph.count >= handle_max) {
			// Reached maximum handles. Return false to prevent counter overflow.
			// TODO: set reason.
			return false;
		}
		
		// Increase handler count by one.
		ph.count++;
	}
	else {
		// Activate the port.
		ph.count = 1;
		*(ph.enr) |= (1 << ph.enable);
	}
	
	return true;
}


// --- DISABLE PORT ---
// Returns true if the port is already disabled, if the request was accepted, or the port disabled.
// Returns false if the requested was rejected, or the port could not be disabled.
bool Rcc::disablePort(RccPort port) {
	uint8_t portNum = (uint8_t) port;
	RccPortHandle* portHandlesStatic = portHandles();
	RccPortHandle &ph = portHandlesStatic[portNum];
	
	if (ph.exists == false) {
		// TODO: set reason.
		return false; 
	}
	
	// Check the current port status.
	if (ph.count > 1) {
		// Decrease handler count by one.
		ph.count--;
	}
	else {
		// Deactivate the port.
		ph.count = 0;
		*(ph.enr) &= ~(1 << ph.enable);
	}
	
	return true;
}


// --- CONFIGURE SYSCLOCK ---
// Configure the system clock.
bool Rcc::configureSysClock(RccSysClockConfig cfg) {
#ifdef __stm32f7
	// Set AHB & APB dividers.
	uint32_t bitField;
	if (!getAHBprescaler(cfg.AHB_prescale, bitField)) {return false;}
	RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_HPRE) | bitField;
	
	if (!getAPB1prescaler(cfg.APB1_prescale, bitField)) {return false;}
	RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PPRE1) | bitField;
	
	if (!getAPB2prescaler(cfg.APB2_prescale, bitField)) {return false;}
	RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PPRE2) | bitField;
	
	if (cfg.source == (uint32_t) RCC_SYSCLOCK_SRC_HSE) {
		// HSE oscillator is used with external crystal. 
		// * Disable HSE bypass.
		RCC->CR &= ~RCC_CR_HSEON;
		RCC->CR &= ~RCC_CR_HSEBYP;
		RCC->CR |= RCC_CR_HSEON;
		
		// Wait for HSE to stabilise.
		while (!(RCC->CR & (uint32_t) RCC_CR_HSERDY)) { }
	}
	else if (cfg.source == (uint32_t) RCC_SYSCLOCK_SRC_HSI) {
		// HSI oscillator is used.
		// * Enable HSI.
		RCC->CR |= RCC_CR_HSION;
		
		// Wait for HSI to stabilise.
		while (!(RCC->CR & (uint32_t) RCC_CR_HSIRDY)) { }
	}
	else if (cfg.source == (uint32_t) RCC_SYSCLOCK_SRC_PLL) {
		// Ensure HSEON & HSEBYP are set.
		// * Turn HSE off.
		// * Enable HSE bypass.
		// * Turn HSE on.
		RCC->CR &= ~RCC_CR_HSEON;
		if (cfg.HSE_bypass) { RCC->CR |= RCC_CR_HSEBYP;	}
		else 				{ RCC->CR &= ~RCC_CR_HSEBYP; }
		RCC->CR |= RCC_CR_HSEON;
		// Wait for HSE to stabilise.
		while (!(RCC->CR & (uint32_t) RCC_CR_HSERDY)) { }
	}
	else {
		return false;
	}
	
	// Configure PLL.
	// * Set PLL source (HSE/HSI).
	// * Set PLL M, N, Q (PLL48CLK) and P.
	RCC->CR &= ~RCC_CR_PLLON;
	RCC->PLLCFGR |= ((uint32_t) cfg.PLL_source << RCC_PLLCFGR_PLLSRC_Pos);
	
	if (cfg.PLLM > 63 || cfg.PLLM == 0 || cfg.PLLM == 1) { return false; }
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLM;
	RCC->PLLCFGR |= (cfg.PLLM << RCC_PLLCFGR_PLLM_Pos);
	
	if (cfg.PLLN > 432 || cfg.PLLN == 0 || cfg.PLLN == 1) { return false; }
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLN;
	RCC->PLLCFGR |= (cfg.PLLN << RCC_PLLCFGR_PLLN_Pos);
	
	if (cfg.PLLP != 2 && cfg.PLLP != 4 && cfg.PLLP != 6 && cfg.PLLP != 8) { return false; }
	uint32_t new_pllp = (cfg.PLLP / 2) - 1;
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLP;
	RCC->PLLCFGR |= (new_pllp << RCC_PLLCFGR_PLLP_Pos);
	
	if (cfg.PLLQ > 15 || cfg.PLLQ == 0 || cfg.PLLQ == 1) { return false; }
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLQ;
	RCC->PLLCFGR |= (cfg.PLLQ << RCC_PLLCFGR_PLLQ_Pos);
	
	// Enable PLL.
	RCC->CR |= RCC_CR_PLLON;
	
	// Wait for PLL to stabilise.
	while((RCC->CR & RCC_CR_PLLRDY) == 0) { }
	
	// Set CFGR register for the SysClock source (SW).
	RCC->CFGR &= ~RCC_CFGR_SW;
	RCC->CFGR |= (cfg.source << RCC_CFGR_SW_Pos);
	
	// Wait for the PLL source to stabilise.
	while ((RCC->CFGR & (uint32_t) RCC_CFGR_SWS) != (uint32_t) RCC_CFGR_SWS_PLL) { }
#endif
	
	return true;
}


// --- ENABLE LSE ---
// Enable or disable the LSE.
bool Rcc::enableLSE(bool on) {
	//
	
	return true;
}

bool getAHBprescaler(uint32_t divisor, uint32_t &AHBfield) {
	switch(divisor) {
		case 1:
			AHBfield = RCC_CFGR_HPRE_DIV1;
			break;
		case 2:
			AHBfield = RCC_CFGR_HPRE_DIV2;
			break;
		case 4:
			AHBfield = RCC_CFGR_HPRE_DIV4;
			break;
		case 8:
			AHBfield = RCC_CFGR_HPRE_DIV8;
			break;
		case 16:
			AHBfield = RCC_CFGR_HPRE_DIV16;
			break;
		case 64:
			AHBfield = RCC_CFGR_HPRE_DIV64;
			break;
		case 128:
			AHBfield = RCC_CFGR_HPRE_DIV128;
			break;
		case 256:
			AHBfield = RCC_CFGR_HPRE_DIV256;
			break;
		case 512:
			AHBfield = RCC_CFGR_HPRE_DIV512;
			break;
		default:
			AHBfield = RCC_CFGR_HPRE_DIV1;
			return false;
	}
	return true;
}

bool getAPB1prescaler(uint32_t divisor, uint32_t &APB1field) {
#if defined __stm32f0
	uint32_t bitFields[5] = {
		RCC_CFGR_PPRE_DIV1,
		RCC_CFGR_PPRE_DIV2,
		RCC_CFGR_PPRE_DIV4,
		RCC_CFGR_PPRE_DIV8,
		RCC_CFGR_PPRE_DIV16 };
#else
	uint32_t bitFields[5] = {
		RCC_CFGR_PPRE1_DIV1,
		RCC_CFGR_PPRE1_DIV2,
		RCC_CFGR_PPRE1_DIV4,
		RCC_CFGR_PPRE1_DIV8,
		RCC_CFGR_PPRE1_DIV16 };
#endif
	switch(divisor) {
		case 1:
			APB1field = bitFields[0];
			break;
		case 2:
			APB1field = bitFields[1];
			break;
		case 4:
			APB1field = bitFields[2];
			break;
		case 8:
			APB1field = bitFields[3];
			break;
		case 16:
			APB1field = bitFields[4];
			break;
		default:
			APB1field = bitFields[1];
			return false;
	}
	return true;
}

bool getAPB2prescaler(uint32_t divisor, uint32_t &APB2field) {
#if defined __stm32f0
	APB2field = 0;  //APB2 doesn't exist for STM32F0
	return false;
#else
	switch(divisor) {
		case 1:
			APB2field = RCC_CFGR_PPRE2_DIV1;
			break;
		case 2:
			APB2field = RCC_CFGR_PPRE2_DIV2;
			break;
		case 4:
			APB2field = RCC_CFGR_PPRE2_DIV4;
			break;
		case 8:
			APB2field = RCC_CFGR_PPRE2_DIV8;
			break;
		case 16:
			APB2field = RCC_CFGR_PPRE2_DIV16;
			break;
		default:
			APB2field = RCC_CFGR_PPRE2_DIV1;
			return false;
	}
#endif
	return true;
}

