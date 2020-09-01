

#ifndef COMMON_H
#define COMMON_H

#include <cstdint>

#define __IO volatile
#define __IM volatile const
#define __IOM volatile


#ifdef STM32F0
// STM32F0
struct GPIO_TypeDef {
  __IO uint32_t MODER;        //!< GPIO port mode register,                     Address offset: 0x00      
  __IO uint32_t OTYPER;       //!< GPIO port output type register,              Address offset: 0x04      
  __IO uint32_t OSPEEDR;      //!< GPIO port output speed register,             Address offset: 0x08      
  __IO uint32_t PUPDR;        //!< GPIO port pull-up/pull-down register,        Address offset: 0x0C      
  __IO uint32_t IDR;          //!< GPIO port input data register,               Address offset: 0x10      
  __IO uint32_t ODR;          //!< GPIO port output data register,              Address offset: 0x14      
  __IO uint32_t BSRR;         //!< GPIO port bit set/reset register,      Address offset: 0x1A 
  __IO uint32_t LCKR;         //!< GPIO port configuration lock register,       Address offset: 0x1C      
  __IO uint32_t AFR[2];       //!< GPIO alternate function low register,  Address offset: 0x20-0x24 
  __IO uint32_t BRR;          //!< GPIO bit reset register,                     Address offset: 0x28      
};

#else

// STM32F4
struct GPIO_TypeDef {
  __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
};

#endif

extern GPIO_TypeDef* GPIOA;
extern GPIO_TypeDef* GPIOB;
extern GPIO_TypeDef* GPIOC;
extern GPIO_TypeDef* GPIOD;
extern GPIO_TypeDef* GPIOE;
extern GPIO_TypeDef* GPIOF;


#ifdef STM32F0
// STM32F0
struct RCC_TypeDef {
  __IO uint32_t CR;            //!< RCC clock control register,                                   Address offset: 0x00 
  __IO uint32_t CFGR;       //!< RCC clock configuration register,                            Address offset: 0x04 
  __IO uint32_t CIR;        //!< RCC clock interrupt register,                                Address offset: 0x08 
  __IO uint32_t APB2RSTR;   //!< RCC APB2 peripheral reset register,                          Address offset: 0x0C 
  __IO uint32_t APB1RSTR;   //!< RCC APB1 peripheral reset register,                          Address offset: 0x10 
  __IO uint32_t AHBENR;     //!< RCC AHB peripheral clock register,                           Address offset: 0x14 
  __IO uint32_t APB2ENR;    //!< RCC APB2 peripheral clock enable register,                   Address offset: 0x18 
  __IO uint32_t APB1ENR;    //!< RCC APB1 peripheral clock enable register,                   Address offset: 0x1C 
  __IO uint32_t BDCR;       //!< RCC Backup domain control register,                          Address offset: 0x20 
  __IO uint32_t CSR;        //!< RCC clock control & status register,                         Address offset: 0x24 
  __IO uint32_t AHBRSTR;    //!< RCC AHB peripheral reset register,                           Address offset: 0x28 
  __IO uint32_t CFGR2;      //!< RCC clock configuration register 2,                          Address offset: 0x2C 
  __IO uint32_t CFGR3;      //!< RCC clock configuration register 3,                          Address offset: 0x30 
  __IO uint32_t CR2;        //!< RCC clock control register 2,                                Address offset: 0x34 
};

#else

// STM32F4
struct RCC_TypeDef {
  __IO uint32_t CR;            //!< RCC clock control register,                                  Address offset: 0x00 
  __IO uint32_t PLLCFGR;       //!< RCC PLL configuration register,                              Address offset: 0x04 
  __IO uint32_t CFGR;          //!< RCC clock configuration register,                            Address offset: 0x08 
  __IO uint32_t CIR;           //!< RCC clock interrupt register,                                Address offset: 0x0C 
  __IO uint32_t AHB1RSTR;      //!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 
  __IO uint32_t AHB2RSTR;      //!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 
  __IO uint32_t AHB3RSTR;      //!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 
  uint32_t      RESERVED0;     //!< Reserved, 0x1C                                                                    
  __IO uint32_t APB1RSTR;      //!< RCC APB1 peripheral reset register,                          Address offset: 0x20 
  __IO uint32_t APB2RSTR;      //!< RCC APB2 peripheral reset register,                          Address offset: 0x24 
  uint32_t      RESERVED1[2];  //!< Reserved, 0x28-0x2C                                                               
  __IO uint32_t AHB1ENR;       //!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 
  __IO uint32_t AHB2ENR;       //!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 
  __IO uint32_t AHB3ENR;       //!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 
  uint32_t      RESERVED2;     //!< Reserved, 0x3C                                                                    
  __IO uint32_t APB1ENR;       //!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 
  __IO uint32_t APB2ENR;       //!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 
  uint32_t      RESERVED3[2];  //!< Reserved, 0x48-0x4C                                                               
  __IO uint32_t AHB1LPENR;     //!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 
  __IO uint32_t AHB2LPENR;     //!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 
  __IO uint32_t AHB3LPENR;     //!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 
  uint32_t      RESERVED4;     //!< Reserved, 0x5C                                                                    
  __IO uint32_t APB1LPENR;     //!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 
  __IO uint32_t APB2LPENR;     //!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 
  uint32_t      RESERVED5[2];  //!< Reserved, 0x68-0x6C                                                               
  __IO uint32_t BDCR;          //!< RCC Backup domain control register,                          Address offset: 0x70 
  __IO uint32_t CSR;           //!< RCC clock control & status register,                         Address offset: 0x74 
  uint32_t      RESERVED6[2];  //!< Reserved, 0x78-0x7C                                                               
  __IO uint32_t SSCGR;         //!< RCC spread spectrum clock generation register,               Address offset: 0x80 
  __IO uint32_t PLLI2SCFGR;    //!< RCC PLLI2S configuration register,                           Address offset: 0x84 
};

#endif

extern RCC_TypeDef* RCC;


// STM32F0
/* struct SYSCFG_TypeDef {
  __IO uint32_t CFGR1;       //!< SYSCFG configuration register 1,                           Address offset: 0x00 
       uint32_t RESERVED;    //!< Reserved,                                                                  0x04 
  __IO uint32_t EXTICR[4];   //!< SYSCFG external interrupt configuration register,     Address offset: 0x14-0x08 
  __IO uint32_t CFGR2;       //!< SYSCFG configuration register 2,                           Address offset: 0x18 
}; */

// STM32F4
struct SYSCFG_TypeDef {
  __IO uint32_t MEMRMP;       /*!< SYSCFG memory remap register,                      Address offset: 0x00      */
  __IO uint32_t PMC;          /*!< SYSCFG peripheral mode configuration register,     Address offset: 0x04      */
  __IO uint32_t EXTICR[4];    /*!< SYSCFG external interrupt configuration registers, Address offset: 0x08-0x14 */
  uint32_t      RESERVED[2];  /*!< Reserved, 0x18-0x1C                                                          */
  __IO uint32_t CMPCR;        /*!< SYSCFG Compensation cell control register,         Address offset: 0x20      */
};

extern SYSCFG_TypeDef* SYSCFG;


struct EXTI_TypeDef {
  __IO uint32_t IMR;          /*!<EXTI Interrupt mask register,                 Address offset: 0x00 */
  __IO uint32_t EMR;          /*!<EXTI Event mask register,                     Address offset: 0x04 */
  __IO uint32_t RTSR;         /*!<EXTI Rising trigger selection register ,      Address offset: 0x08 */
  __IO uint32_t FTSR;         /*!<EXTI Falling trigger selection register,      Address offset: 0x0C */
  __IO uint32_t SWIER;        /*!<EXTI Software interrupt event register,       Address offset: 0x10 */
  __IO uint32_t PR;           /*!<EXTI Pending register,                        Address offset: 0x14 */
};

extern EXTI_TypeDef* EXTI;


 /*!< Interrupt Number Definition */
enum IRQn_Type {
/******  Cortex-M0 Processor Exceptions Numbers **************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                        */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                                */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                              */

/******  STM32F0 specific Interrupt Numbers ******************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                               */
  PVD_VDDIO2_IRQn             = 1,      /*!< PVD & VDDIO2 Interrupt through EXTI Lines 16 and 31             */
  RTC_IRQn                    = 2,      /*!< RTC Interrupt through EXTI Lines 17, 19 and 20                  */
  FLASH_IRQn                  = 3,      /*!< FLASH global Interrupt                                          */
  RCC_CRS_IRQn                = 4,      /*!< RCC & CRS global Interrupt                                      */
  EXTI0_1_IRQn                = 5,      /*!< EXTI Line 0 and 1 Interrupt                                     */
  EXTI2_3_IRQn                = 6,      /*!< EXTI Line 2 and 3 Interrupt                                     */
  EXTI4_15_IRQn               = 7,      /*!< EXTI Line 4 to 15 Interrupt                                     */
  TSC_IRQn                    = 8,      /*!< Touch Sensing Controller Interrupts                             */
  DMA1_Channel1_IRQn          = 9,      /*!< DMA1 Channel 1 Interrupt                                        */
  DMA1_Channel2_3_IRQn        = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupt                          */
  DMA1_Channel4_5_IRQn        = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupt                          */
  ADC1_IRQn                   = 12,     /*!< ADC1 Interrupt                                                  */
  TIM1_BRK_UP_TRG_COM_IRQn    = 13,     /*!< TIM1 Break, Update, Trigger and Commutation Interrupt           */
  TIM1_CC_IRQn                = 14,     /*!< TIM1 Capture Compare Interrupt                                  */
  TIM2_IRQn                   = 15,     /*!< TIM2 global Interrupt                                           */
  TIM3_IRQn                   = 16,     /*!< TIM3 global Interrupt                                           */
  TIM14_IRQn                  = 19,     /*!< TIM14 global Interrupt                                          */
  TIM16_IRQn                  = 21,     /*!< TIM16 global Interrupt                                          */
  TIM17_IRQn                  = 22,     /*!< TIM17 global Interrupt                                          */
  I2C1_IRQn                   = 23,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)      */
  SPI1_IRQn                   = 25,     /*!< SPI1 global Interrupt                                           */
  SPI2_IRQn                   = 26,     /*!< SPI2 global Interrupt                                           */
  USART1_IRQn                 = 27,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup) */
  USART2_IRQn                 = 28,     /*!< USART2 global Interrupt                                         */
  CEC_CAN_IRQn                = 30,     /*!< CEC and CAN global Interrupts & EXTI Line27 Interrupt           */
  USB_IRQn                    = 31      /*!< USB global Interrupt  & EXTI Line18 Interrupt                   */
};


/**
  \brief  Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
struct NVIC_Type {
  __IOM uint32_t ISER[1U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[31U];
  __IOM uint32_t ICER[1U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RSERVED1[31U];
  __IOM uint32_t ISPR[1U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[31U];
  __IOM uint32_t ICPR[1U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[31U];
        uint32_t RESERVED4[64U];
  __IOM uint32_t IP[8U];                 /*!< Offset: 0x300 (R/W)  Interrupt Priority Register */
};

extern NVIC_Type* NVIC;


//struct SCB_Type {
//  __IM  uint32_t CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
//  __IOM uint32_t ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
        //uint32_t RESERVED0;
  //__IOM uint32_t AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
  //__IOM uint32_t SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
  //__IOM uint32_t CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
        //uint32_t RESERVED1;
  //__IOM uint32_t SHP[2U];                /*!< Offset: 0x01C (R/W)  System Handlers Priority Registers. [0] is RESERVED */
  //__IOM uint32_t SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
//};

//extern SCB_Type* SCB;

extern "C" {
void NVIC_EnableIRQ(IRQn_Type IRQn);
void NVIC_DisableIRQ(IRQn_Type IRQn);
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority);
}


// STM32F0
#ifdef STM32F0
#define RCC_AHBENR_GPIOAEN_Pos                   (17U) 
#define RCC_AHBENR_GPIOAEN 			(0x1UL << RCC_AHBENR_GPIOAEN_Pos)
#define RCC_AHBENR_GPIOBEN_Pos                   (18U)
#define RCC_AHBENR_GPIOBEN 			(0x1UL << RCC_AHBENR_GPIOBEN_Pos)
#define RCC_AHBENR_GPIOCEN_Pos                   (19U)
#define RCC_AHBENR_GPIOCEN 			(0x1UL << RCC_AHBENR_GPIOCEN_Pos)
#define RCC_AHBENR_GPIOFEN_Pos                   (22U)   
#define RCC_AHBENR_GPIOFEN 			(0x1UL << RCC_AHBENR_GPIOFEN_Pos)

#else

// STM32F4
#define RCC_AHB1ENR_GPIOAEN_Pos            (0U)                                
#define RCC_AHB1ENR_GPIOAEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOAEN_Pos)   //!< 0x00000001 
#define RCC_AHB1ENR_GPIOAEN                RCC_AHB1ENR_GPIOAEN_Msk             
#define RCC_AHB1ENR_GPIOBEN_Pos            (1U)                                
#define RCC_AHB1ENR_GPIOBEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOBEN_Pos)   //!< 0x00000002 
#define RCC_AHB1ENR_GPIOBEN                RCC_AHB1ENR_GPIOBEN_Msk             
#define RCC_AHB1ENR_GPIOCEN_Pos            (2U)                                
#define RCC_AHB1ENR_GPIOCEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOCEN_Pos)   //!< 0x00000004 
#define RCC_AHB1ENR_GPIOCEN                RCC_AHB1ENR_GPIOCEN_Msk             
#define RCC_AHB1ENR_GPIODEN_Pos            (3U)                                
#define RCC_AHB1ENR_GPIODEN_Msk            (0x1UL << RCC_AHB1ENR_GPIODEN_Pos)   //!< 0x00000008 
#define RCC_AHB1ENR_GPIODEN                RCC_AHB1ENR_GPIODEN_Msk             
#define RCC_AHB1ENR_GPIOEEN_Pos            (4U)                                
#define RCC_AHB1ENR_GPIOEEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOEEN_Pos)   //!< 0x00000010 
#define RCC_AHB1ENR_GPIOEEN                RCC_AHB1ENR_GPIOEEN_Msk             
#define RCC_AHB1ENR_GPIOFEN_Pos            (5U)                                
#define RCC_AHB1ENR_GPIOFEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOFEN_Pos)   //!< 0x00000020 
#define RCC_AHB1ENR_GPIOFEN                RCC_AHB1ENR_GPIOFEN_Msk             
#define RCC_AHB1ENR_GPIOGEN_Pos            (6U)                                
#define RCC_AHB1ENR_GPIOGEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOGEN_Pos)   //!< 0x00000040 
#define RCC_AHB1ENR_GPIOGEN                RCC_AHB1ENR_GPIOGEN_Msk             
#define RCC_AHB1ENR_GPIOHEN_Pos            (7U)                                
#define RCC_AHB1ENR_GPIOHEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOHEN_Pos)   //!< 0x00000080 
#define RCC_AHB1ENR_GPIOHEN                RCC_AHB1ENR_GPIOHEN_Msk             
#define RCC_AHB1ENR_GPIOIEN_Pos            (8U)                                
#define RCC_AHB1ENR_GPIOIEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOIEN_Pos)   //!< 0x00000100 
#define RCC_AHB1ENR_GPIOIEN                RCC_AHB1ENR_GPIOIEN_Msk 

#endif

// STM32F0
#ifdef STM32F0
#define RCC_APB2ENR_SYSCFGCOMPEN_Pos 	(0U)
#define RCC_APB2ENR_SYSCFGCOMPEN 	(0x1UL << RCC_APB2ENR_SYSCFGCOMPEN_Pos)

#else

// STM32F4
#define RCC_APB2ENR_SYSCFGEN_Pos           (14U)                               
#define RCC_APB2ENR_SYSCFGEN_Msk           (0x1UL << RCC_APB2ENR_SYSCFGEN_Pos)  //!< 0x00004000
#define RCC_APB2ENR_SYSCFGEN               RCC_APB2ENR_SYSCFGEN_Msk

#endif

#endif
