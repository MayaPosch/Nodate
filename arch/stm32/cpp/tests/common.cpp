
#include "common.h"

#include <cstdio>

// Custom printf things. Implement putchar handler.
extern "C" {
	void _putchar(char character);
}

void _putchar(char character) {
	putchar(character);
}

// ---

// Core
// Defined in core-specific file.
SysTick_Type tSysTick = { .CALIB = 1 };
SysTick_Type* SysTick = &tSysTick;
// End core.


uint32_t SystemCoreClock = 8000000;

ADC_TypeDef tADC1;
ADC_TypeDef* ADC1 = &tADC1;

BKP_TypeDef tBkp;
BKP_TypeDef* BKP = &tBkp;

FLASH_TypeDef tFlash;
FLASH_TypeDef* FLASH = &tFlash;

GPIO_TypeDef tGpioA;
GPIO_TypeDef* GPIOA = &tGpioA;
GPIO_TypeDef tGpioB;
GPIO_TypeDef* GPIOB = &tGpioB;
GPIO_TypeDef tGpioC;
GPIO_TypeDef* GPIOC = &tGpioC;
GPIO_TypeDef tGpioD;
GPIO_TypeDef* GPIOD = &tGpioD;
GPIO_TypeDef tGpioE;
GPIO_TypeDef* GPIOE = &tGpioE;
GPIO_TypeDef tGpioF;
GPIO_TypeDef* GPIOF = &tGpioF;

#if defined STM32F1
AFIO_TypeDef tAfio;
AFIO_TypeDef* AFIO = &tAfio;
#endif

PWR_TypeDef tPWR;
PWR_TypeDef* PWR = &tPWR;

I2C_TypeDef tI2C1;
I2C_TypeDef* I2C1 = &tI2C1;

RCC_TypeDef tRcc;
RCC_TypeDef* RCC = &tRcc;

RTC_TypeDef tRtc;
RTC_TypeDef* RTC = &tRtc;

SYSCFG_TypeDef tSyscfg;
SYSCFG_TypeDef* SYSCFG = &tSyscfg;

EXTI_TypeDef tExti;
EXTI_TypeDef* EXTI = &tExti;


NVIC_Type tNvic;
NVIC_Type* NVIC = &tNvic;

/* SCB_Type tScb;
SCB_Type* SCB = &tScb; */


/**
  \brief   Enable Interrupt
  \details Enables a device specific interrupt in the NVIC interrupt controller.
  \param [in]      IRQn  Device specific interrupt number.
  \note    IRQn must not be negative.
 */
void NVIC_EnableIRQ(IRQn_Type IRQn) {
	/* if ((int32_t) (IRQn) >= 0) {
		NVIC->ISER[0U] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
	} */
}


/**
  \brief   Disable Interrupt
  \details Disables a device specific interrupt in the NVIC interrupt controller.
  \param [in]      IRQn  Device specific interrupt number.
  \note    IRQn must not be negative.
 */
void NVIC_DisableIRQ(IRQn_Type IRQn) {
	/* if ((int32_t)(IRQn) >= 0) {
		NVIC->ICER[0U] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
		__DSB();
		__ISB(); 
	}*/
}


/**
  \brief   Set Interrupt Priority
  \details Sets the priority of a device specific interrupt or a processor exception.
           The interrupt number can be positive to specify a device specific interrupt,
           or negative to specify a processor exception.
  \param [in]      IRQn  Interrupt number.
  \param [in]  priority  Priority to set.
  \note    The priority cannot be set for every processor exception.
 */
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority) {
	/* if ((int32_t)(IRQn) >= 0)   {
		NVIC->IP[_IP_IDX(IRQn)]  = ((uint32_t)(NVIC->IP[_IP_IDX(IRQn)]  & ~(0xFFUL << _BIT_SHIFT(IRQn))) |
       (((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL) << _BIT_SHIFT(IRQn)));
	}
	else {
		SCB->SHP[_SHP_IDX(IRQn)] = ((uint32_t)(SCB->SHP[_SHP_IDX(IRQn)] & ~(0xFFUL << _BIT_SHIFT(IRQn))) |
       (((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL) << _BIT_SHIFT(IRQn)));
	} */
}

uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority) {
	/* uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);   // only values 0..7 are used
	uint32_t PreemptPriorityBits;
	uint32_t SubPriorityBits;

	PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(__NVIC_PRIO_BITS)) ? (uint32_t)(__NVIC_PRIO_BITS) : (uint32_t)(7UL - PriorityGroupTmp);
	SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(__NVIC_PRIO_BITS)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(__NVIC_PRIO_BITS));

	return (
		   ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
		   ((SubPriority     & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL)))
		 ); */
	return 0;
}


USART_TypeDef tUsart1;
USART_TypeDef* USART1 = & tUsart1;
USART_TypeDef tUsart2;
USART_TypeDef* USART2 = & tUsart2;
USART_TypeDef tUsart3;
USART_TypeDef* USART3 = & tUsart3;

SPI_TypeDef tSPI1;
SPI_TypeDef* SPI1 = &tSPI1;
