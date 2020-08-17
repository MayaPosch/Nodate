#include "common.h"

GPIO_TypeDef tGpioA;
GPIO_TypeDef* GPIOA = &tGpioA;
GPIO_TypeDef tGpioB;
GPIO_TypeDef* GPIOB = &tGpioB;
GPIO_TypeDef tGpioC;
GPIO_TypeDef* GPIOC = &tGpioC;
GPIO_TypeDef tGpioF;
GPIO_TypeDef* GPIOF = &tGpioF;

RCC_TypeDef tRcc;
RCC_TypeDef* RCC = &tRcc;

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
