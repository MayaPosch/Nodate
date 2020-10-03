

#ifndef COMMON_H
#define COMMON_H

#include <cstdint>

#define __IO volatile
#define __IM volatile const
#define __IOM volatile


extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock) */


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

#elif defined STM32F1
// STM32F1
struct GPIO_TypeDef {
  __IO uint32_t CRL;
  __IO uint32_t CRH;
  __IO uint32_t IDR;
  __IO uint32_t ODR;
  __IO uint32_t BSRR;
  __IO uint32_t BRR;
  __IO uint32_t LCKR;
};

struct AFIO_TypeDef {
  __IO uint32_t EVCR;
  __IO uint32_t MAPR;
  __IO uint32_t EXTICR[4];
  uint32_t RESERVED0;
  __IO uint32_t MAPR2;  
};

extern AFIO_TypeDef* AFIO;
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

#elif defined STM32F1
// STM32F1
struct RCC_TypeDef {
  __IO uint32_t CR;
  __IO uint32_t CFGR;
  __IO uint32_t CIR;
  __IO uint32_t APB2RSTR;
  __IO uint32_t APB1RSTR;
  __IO uint32_t AHBENR;
  __IO uint32_t APB2ENR;
  __IO uint32_t APB1ENR;
  __IO uint32_t BDCR;
  __IO uint32_t CSR;
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

#ifdef STM32F0
// STM32F0
struct SYSCFG_TypeDef {
  __IO uint32_t CFGR1;       //!< SYSCFG configuration register 1,                           Address offset: 0x00 
       uint32_t RESERVED;    //!< Reserved,                                                                  0x04 
  __IO uint32_t EXTICR[4];   //!< SYSCFG external interrupt configuration register,     Address offset: 0x14-0x08 
  __IO uint32_t CFGR2;       //!< SYSCFG configuration register 2,                           Address offset: 0x18 
};

#else
// STM32F4
struct SYSCFG_TypeDef {
  __IO uint32_t MEMRMP;       /*!< SYSCFG memory remap register,                      Address offset: 0x00      */
  __IO uint32_t PMC;          /*!< SYSCFG peripheral mode configuration register,     Address offset: 0x04      */
  __IO uint32_t EXTICR[4];    /*!< SYSCFG external interrupt configuration registers, Address offset: 0x08-0x14 */
  uint32_t      RESERVED[2];  /*!< Reserved, 0x18-0x1C                                                          */
  __IO uint32_t CMPCR;        /*!< SYSCFG Compensation cell control register,         Address offset: 0x20      */
};
#endif

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

#if defined STM32F1
enum IRQn_Type {
/******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                             */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M3 Hard Fault Interrupt                     */
  MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M3 Memory Management Interrupt              */
  BusFault_IRQn               = -11,    /*!< 5 Cortex-M3 Bus Fault Interrupt                      */
  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M3 Usage Fault Interrupt                    */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                       */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                 */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                       */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                   */

/******  STM32 specific Interrupt Numbers *********************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                            */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt            */
  TAMPER_IRQn                 = 2,      /*!< Tamper Interrupt                                     */
  RTC_IRQn                    = 3,      /*!< RTC global Interrupt                                 */
  FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                               */
  RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                 */
  EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                 */
  EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                 */
  EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                 */
  EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                 */
  EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                 */
  DMA1_Channel1_IRQn          = 11,     /*!< DMA1 Channel 1 global Interrupt                      */
  DMA1_Channel2_IRQn          = 12,     /*!< DMA1 Channel 2 global Interrupt                      */
  DMA1_Channel3_IRQn          = 13,     /*!< DMA1 Channel 3 global Interrupt                      */
  DMA1_Channel4_IRQn          = 14,     /*!< DMA1 Channel 4 global Interrupt                      */
  DMA1_Channel5_IRQn          = 15,     /*!< DMA1 Channel 5 global Interrupt                      */
  DMA1_Channel6_IRQn          = 16,     /*!< DMA1 Channel 6 global Interrupt                      */
  DMA1_Channel7_IRQn          = 17,     /*!< DMA1 Channel 7 global Interrupt                      */
  ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
  USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts       */
  USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
  CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
  CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                   */
  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
  TIM1_BRK_IRQn               = 24,     /*!< TIM1 Break Interrupt                                 */
  TIM1_UP_IRQn                = 25,     /*!< TIM1 Update Interrupt                                */
  TIM1_TRG_COM_IRQn           = 26,     /*!< TIM1 Trigger and Commutation Interrupt               */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                */
  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                */
  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                 */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                 */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                 */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                 */
  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                */
  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                              */
  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                      */
  RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
  USBWakeUp_IRQn              = 42,     /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */
};
#else
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
#endif

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
uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority);
#if defined STM32F0 || defined STM32F1
#define NVIC_GetPriorityGrouping()  (0U)
#endif
}


// --- USART ---

#if defined STM32F0
struct USART_TypeDef {
  __IO uint32_t CR1;    /*!< USART Control register 1,                 Address offset: 0x00 */ 
  __IO uint32_t CR2;    /*!< USART Control register 2,                 Address offset: 0x04 */ 
  __IO uint32_t CR3;    /*!< USART Control register 3,                 Address offset: 0x08 */
  __IO uint32_t BRR;    /*!< USART Baud rate register,                 Address offset: 0x0C */
  __IO uint32_t GTPR;   /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
  __IO uint32_t RTOR;   /*!< USART Receiver Time Out register,         Address offset: 0x14 */  
  __IO uint32_t RQR;    /*!< USART Request register,                   Address offset: 0x18 */
  __IO uint32_t ISR;    /*!< USART Interrupt and status register,      Address offset: 0x1C */
  __IO uint32_t ICR;    /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
  __IO uint16_t RDR;    /*!< USART Receive Data register,              Address offset: 0x24 */
  uint16_t  RESERVED1;  /*!< Reserved, 0x26                                                 */
  __IO uint16_t TDR;    /*!< USART Transmit Data register,             Address offset: 0x28 */
  uint16_t  RESERVED2;  /*!< Reserved, 0x2A                                                 */
};

#elif defined STM32F1 || defined STM32F4
struct USART_TypeDef {
  __IO uint32_t SR;         /*!< USART Status register,                   Address offset: 0x00 */
  __IO uint32_t DR;         /*!< USART Data register,                     Address offset: 0x04 */
  __IO uint32_t BRR;        /*!< USART Baud rate register,                Address offset: 0x08 */
  __IO uint32_t CR1;        /*!< USART Control register 1,                Address offset: 0x0C */
  __IO uint32_t CR2;        /*!< USART Control register 2,                Address offset: 0x10 */
  __IO uint32_t CR3;        /*!< USART Control register 3,                Address offset: 0x14 */
  __IO uint32_t GTPR;       /*!< USART Guard time and prescaler register, Address offset: 0x18 */
};

#elif defined STM32F7
struct USART_TypeDef {
  __IO uint32_t CR1;    /*!< USART Control register 1,                 Address offset: 0x00 */
  __IO uint32_t CR2;    /*!< USART Control register 2,                 Address offset: 0x04 */
  __IO uint32_t CR3;    /*!< USART Control register 3,                 Address offset: 0x08 */
  __IO uint32_t BRR;    /*!< USART Baud rate register,                 Address offset: 0x0C */
  __IO uint32_t GTPR;   /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
  __IO uint32_t RTOR;   /*!< USART Receiver Time Out register,         Address offset: 0x14 */
  __IO uint32_t RQR;    /*!< USART Request register,                   Address offset: 0x18 */
  __IO uint32_t ISR;    /*!< USART Interrupt and status register,      Address offset: 0x1C */
  __IO uint32_t ICR;    /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
  __IO uint32_t RDR;    /*!< USART Receive Data register,              Address offset: 0x24 */
  __IO uint32_t TDR;    /*!< USART Transmit Data register,             Address offset: 0x28 */
};

#endif

extern USART_TypeDef* USART1;
extern USART_TypeDef* USART2;
extern USART_TypeDef* USART3;


// --- DEFINES ---

#if defined STM32F0
// STM32F0
#define RCC_AHBENR_GPIOAEN_Pos                   (17U) 
#define RCC_AHBENR_GPIOAEN 			(0x1UL << RCC_AHBENR_GPIOAEN_Pos)
#define RCC_AHBENR_GPIOBEN_Pos                   (18U)
#define RCC_AHBENR_GPIOBEN 			(0x1UL << RCC_AHBENR_GPIOBEN_Pos)
#define RCC_AHBENR_GPIOCEN_Pos                   (19U)
#define RCC_AHBENR_GPIOCEN 			(0x1UL << RCC_AHBENR_GPIOCEN_Pos)
#define RCC_AHBENR_GPIOFEN_Pos                   (22U)   
#define RCC_AHBENR_GPIOFEN 			(0x1UL << RCC_AHBENR_GPIOFEN_Pos)

#define RCC_APB2ENR_SYSCFGCOMPEN_Pos 	(0U)
#define RCC_APB2ENR_SYSCFGCOMPEN 	(0x1UL << RCC_APB2ENR_SYSCFGCOMPEN_Pos)

#define RCC_APB2ENR_USART1EN_Pos                 (14U)                         
#define RCC_APB2ENR_USART1EN_Msk                 (0x1UL << RCC_APB2ENR_USART1EN_Pos) /*!< 0x00004000 */
#define RCC_APB2ENR_USART1EN                     RCC_APB2ENR_USART1EN_Msk      /*!< USART1 clock enable */

#define RCC_APB1ENR_USART2EN_Pos                 (17U)                         
#define RCC_APB1ENR_USART2EN_Msk                 (0x1UL << RCC_APB1ENR_USART2EN_Pos) /*!< 0x00020000 */
#define RCC_APB1ENR_USART2EN                     RCC_APB1ENR_USART2EN_Msk      /*!< USART2 clock enable */

#define USART_CR1_UE_Pos              (0U)                                     
#define USART_CR1_UE_Msk              (0x1UL << USART_CR1_UE_Pos)               /*!< 0x00000001 */
#define USART_CR1_UE                  USART_CR1_UE_Msk                         /*!< USART Enable */
#define USART_CR1_UESM_Pos            (1U)                                     
#define USART_CR1_UESM_Msk            (0x1UL << USART_CR1_UESM_Pos)             /*!< 0x00000002 */
#define USART_CR1_UESM                USART_CR1_UESM_Msk                       /*!< USART Enable in STOP Mode */
#define USART_CR1_RE_Pos              (2U)                                     
#define USART_CR1_RE_Msk              (0x1UL << USART_CR1_RE_Pos)               /*!< 0x00000004 */
#define USART_CR1_RE                  USART_CR1_RE_Msk                         /*!< Receiver Enable */
#define USART_CR1_TE_Pos              (3U)                                     
#define USART_CR1_TE_Msk              (0x1UL << USART_CR1_TE_Pos)               /*!< 0x00000008 */
#define USART_CR1_TE                  USART_CR1_TE_Msk                         /*!< Transmitter Enable */
#define USART_CR1_IDLEIE_Pos          (4U)                                     
#define USART_CR1_IDLEIE_Msk          (0x1UL << USART_CR1_IDLEIE_Pos)           /*!< 0x00000010 */
#define USART_CR1_IDLEIE              USART_CR1_IDLEIE_Msk                     /*!< IDLE Interrupt Enable */
#define USART_CR1_RXNEIE_Pos          (5U)                                     
#define USART_CR1_RXNEIE_Msk          (0x1UL << USART_CR1_RXNEIE_Pos)           /*!< 0x00000020 */
#define USART_CR1_RXNEIE              USART_CR1_RXNEIE_Msk                     /*!< RXNE Interrupt Enable */

/******************  Bit definition for USART_BRR register  *******************/
#define USART_BRR_DIV_FRACTION_Pos    (0U)                                     
#define USART_BRR_DIV_FRACTION_Msk    (0xFUL << USART_BRR_DIV_FRACTION_Pos)     /*!< 0x0000000F */
#define USART_BRR_DIV_FRACTION        USART_BRR_DIV_FRACTION_Msk               /*!< Fraction of USARTDIV */
#define USART_BRR_DIV_MANTISSA_Pos    (4U)                                     
#define USART_BRR_DIV_MANTISSA_Msk    (0xFFFUL << USART_BRR_DIV_MANTISSA_Pos)   /*!< 0x0000FFF0 */
#define USART_BRR_DIV_MANTISSA        USART_BRR_DIV_MANTISSA_Msk               /*!< Mantissa of USARTDIV */

#define USART_ISR_RXNE_Pos            (5U)                                     
#define USART_ISR_RXNE_Msk            (0x1UL << USART_ISR_RXNE_Pos)             /*!< 0x00000020 */
#define USART_ISR_RXNE                USART_ISR_RXNE_Msk                       /*!< Read Data Register Not Empty */

#elif defined STM32F1
// STM32F1
#define RCC_APB2ENR_AFIOEN_Pos               (0U)                              
#define RCC_APB2ENR_AFIOEN_Msk               (0x1UL << RCC_APB2ENR_AFIOEN_Pos)  /*!< 0x00000001 */
#define RCC_APB2ENR_AFIOEN                   RCC_APB2ENR_AFIOEN_Msk            /*!< Alternate Function I/O clock enable */
#define RCC_APB2ENR_IOPAEN_Pos               (2U)                              
#define RCC_APB2ENR_IOPAEN_Msk               (0x1UL << RCC_APB2ENR_IOPAEN_Pos)  /*!< 0x00000004 */
#define RCC_APB2ENR_IOPAEN                   RCC_APB2ENR_IOPAEN_Msk            /*!< I/O port A clock enable */
#define RCC_APB2ENR_IOPBEN_Pos               (3U)                              
#define RCC_APB2ENR_IOPBEN_Msk               (0x1UL << RCC_APB2ENR_IOPBEN_Pos)  /*!< 0x00000008 */
#define RCC_APB2ENR_IOPBEN                   RCC_APB2ENR_IOPBEN_Msk            /*!< I/O port B clock enable */
#define RCC_APB2ENR_IOPCEN_Pos               (4U)                              
#define RCC_APB2ENR_IOPCEN_Msk               (0x1UL << RCC_APB2ENR_IOPCEN_Pos)  /*!< 0x00000010 */
#define RCC_APB2ENR_IOPCEN                   RCC_APB2ENR_IOPCEN_Msk            /*!< I/O port C clock enable */
#define RCC_APB2ENR_IOPDEN_Pos               (5U)                              
#define RCC_APB2ENR_IOPDEN_Msk               (0x1UL << RCC_APB2ENR_IOPDEN_Pos)  /*!< 0x00000020 */
#define RCC_APB2ENR_IOPDEN                   RCC_APB2ENR_IOPDEN_Msk            /*!< I/O port D clock enable */
#define RCC_APB2ENR_ADC1EN_Pos               (9U)                              
#define RCC_APB2ENR_ADC1EN_Msk               (0x1UL << RCC_APB2ENR_ADC1EN_Pos)  /*!< 0x00000200 */
#define RCC_APB2ENR_ADC1EN                   RCC_APB2ENR_ADC1EN_Msk            /*!< ADC 1 interface clock enable */

#define RCC_APB2ENR_ADC2EN_Pos               (10U)                             
#define RCC_APB2ENR_ADC2EN_Msk               (0x1UL << RCC_APB2ENR_ADC2EN_Pos)  /*!< 0x00000400 */
#define RCC_APB2ENR_ADC2EN                   RCC_APB2ENR_ADC2EN_Msk            /*!< ADC 2 interface clock enable */

#define RCC_APB2ENR_TIM1EN_Pos               (11U)                             
#define RCC_APB2ENR_TIM1EN_Msk               (0x1UL << RCC_APB2ENR_TIM1EN_Pos)  /*!< 0x00000800 */
#define RCC_APB2ENR_TIM1EN                   RCC_APB2ENR_TIM1EN_Msk            /*!< TIM1 Timer clock enable */
#define RCC_APB2ENR_SPI1EN_Pos               (12U)                             
#define RCC_APB2ENR_SPI1EN_Msk               (0x1UL << RCC_APB2ENR_SPI1EN_Pos)  /*!< 0x00001000 */
#define RCC_APB2ENR_SPI1EN                   RCC_APB2ENR_SPI1EN_Msk            /*!< SPI 1 clock enable */
#define RCC_APB2ENR_USART1EN_Pos             (14U)                             
#define RCC_APB2ENR_USART1EN_Msk             (0x1UL << RCC_APB2ENR_USART1EN_Pos) /*!< 0x00004000 */
#define RCC_APB2ENR_USART1EN                 RCC_APB2ENR_USART1EN_Msk          /*!< USART1 clock enable */

/*****************  Bit definition for RCC_APB1ENR register  ******************/
#define RCC_APB1ENR_TIM2EN_Pos               (0U)                              
#define RCC_APB1ENR_TIM2EN_Msk               (0x1UL << RCC_APB1ENR_TIM2EN_Pos)  /*!< 0x00000001 */
#define RCC_APB1ENR_TIM2EN                   RCC_APB1ENR_TIM2EN_Msk            /*!< Timer 2 clock enabled*/
#define RCC_APB1ENR_TIM3EN_Pos               (1U)                              
#define RCC_APB1ENR_TIM3EN_Msk               (0x1UL << RCC_APB1ENR_TIM3EN_Pos)  /*!< 0x00000002 */
#define RCC_APB1ENR_TIM3EN                   RCC_APB1ENR_TIM3EN_Msk            /*!< Timer 3 clock enable */
#define RCC_APB1ENR_WWDGEN_Pos               (11U)                             
#define RCC_APB1ENR_WWDGEN_Msk               (0x1UL << RCC_APB1ENR_WWDGEN_Pos)  /*!< 0x00000800 */
#define RCC_APB1ENR_WWDGEN                   RCC_APB1ENR_WWDGEN_Msk            /*!< Window Watchdog clock enable */
#define RCC_APB1ENR_USART2EN_Pos             (17U)                             
#define RCC_APB1ENR_USART2EN_Msk             (0x1UL << RCC_APB1ENR_USART2EN_Pos) /*!< 0x00020000 */
#define RCC_APB1ENR_USART2EN                 RCC_APB1ENR_USART2EN_Msk          /*!< USART 2 clock enable */
#define RCC_APB1ENR_I2C1EN_Pos               (21U)                             
#define RCC_APB1ENR_I2C1EN_Msk               (0x1UL << RCC_APB1ENR_I2C1EN_Pos)  /*!< 0x00200000 */
#define RCC_APB1ENR_I2C1EN                   RCC_APB1ENR_I2C1EN_Msk            /*!< I2C 1 clock enable */

#define RCC_APB1ENR_CAN1EN_Pos               (25U)                             
#define RCC_APB1ENR_CAN1EN_Msk               (0x1UL << RCC_APB1ENR_CAN1EN_Pos)  /*!< 0x02000000 */
#define RCC_APB1ENR_CAN1EN                   RCC_APB1ENR_CAN1EN_Msk            /*!< CAN1 clock enable */

#define RCC_APB1ENR_BKPEN_Pos                (27U)                             
#define RCC_APB1ENR_BKPEN_Msk                (0x1UL << RCC_APB1ENR_BKPEN_Pos)   /*!< 0x08000000 */
#define RCC_APB1ENR_BKPEN                    RCC_APB1ENR_BKPEN_Msk             /*!< Backup interface clock enable */
#define RCC_APB1ENR_PWREN_Pos                (28U)                             
#define RCC_APB1ENR_PWREN_Msk                (0x1UL << RCC_APB1ENR_PWREN_Pos)   /*!< 0x10000000 */
#define RCC_APB1ENR_PWREN                    RCC_APB1ENR_PWREN_Msk             /*!< Power interface clock enable */

#define RCC_APB1ENR_TIM4EN_Pos               (2U)                              
#define RCC_APB1ENR_TIM4EN_Msk               (0x1UL << RCC_APB1ENR_TIM4EN_Pos)  /*!< 0x00000004 */
#define RCC_APB1ENR_TIM4EN                   RCC_APB1ENR_TIM4EN_Msk            /*!< Timer 4 clock enable */
#define RCC_APB1ENR_SPI2EN_Pos               (14U)                             
#define RCC_APB1ENR_SPI2EN_Msk               (0x1UL << RCC_APB1ENR_SPI2EN_Pos)  /*!< 0x00004000 */
#define RCC_APB1ENR_SPI2EN                   RCC_APB1ENR_SPI2EN_Msk            /*!< SPI 2 clock enable */
#define RCC_APB1ENR_USART3EN_Pos             (18U)                             
#define RCC_APB1ENR_USART3EN_Msk             (0x1UL << RCC_APB1ENR_USART3EN_Pos) /*!< 0x00040000 */
#define RCC_APB1ENR_USART3EN                 RCC_APB1ENR_USART3EN_Msk          /*!< USART 3 clock enable */
#define RCC_APB1ENR_I2C2EN_Pos               (22U)                             
#define RCC_APB1ENR_I2C2EN_Msk               (0x1UL << RCC_APB1ENR_I2C2EN_Pos)  /*!< 0x00400000 */
#define RCC_APB1ENR_I2C2EN                   RCC_APB1ENR_I2C2EN_Msk            /*!< I2C 2 clock enable */

#define RCC_APB1ENR_USBEN_Pos                (23U)                             
#define RCC_APB1ENR_USBEN_Msk                (0x1UL << RCC_APB1ENR_USBEN_Pos)   /*!< 0x00800000 */
#define RCC_APB1ENR_USBEN                    RCC_APB1ENR_USBEN_Msk             /*!< USB Device clock enable */

/******************  Bit definition for AFIO_MAPR register  *******************/
#define AFIO_MAPR_SPI1_REMAP_Pos             (0U)                              
#define AFIO_MAPR_SPI1_REMAP_Msk             (0x1UL << AFIO_MAPR_SPI1_REMAP_Pos) /*!< 0x00000001 */
#define AFIO_MAPR_SPI1_REMAP                 AFIO_MAPR_SPI1_REMAP_Msk          /*!< SPI1 remapping */
#define AFIO_MAPR_I2C1_REMAP_Pos             (1U)                              
#define AFIO_MAPR_I2C1_REMAP_Msk             (0x1UL << AFIO_MAPR_I2C1_REMAP_Pos) /*!< 0x00000002 */
#define AFIO_MAPR_I2C1_REMAP                 AFIO_MAPR_I2C1_REMAP_Msk          /*!< I2C1 remapping */
#define AFIO_MAPR_USART1_REMAP_Pos           (2U)                              
#define AFIO_MAPR_USART1_REMAP_Msk           (0x1UL << AFIO_MAPR_USART1_REMAP_Pos) /*!< 0x00000004 */
#define AFIO_MAPR_USART1_REMAP               AFIO_MAPR_USART1_REMAP_Msk        /*!< USART1 remapping */
#define AFIO_MAPR_USART2_REMAP_Pos           (3U)                              
#define AFIO_MAPR_USART2_REMAP_Msk           (0x1UL << AFIO_MAPR_USART2_REMAP_Pos) /*!< 0x00000008 */
#define AFIO_MAPR_USART2_REMAP               AFIO_MAPR_USART2_REMAP_Msk        /*!< USART2 remapping */


#define AFIO_MAPR_TIM1_REMAP_Pos             (6U)                              
#define AFIO_MAPR_TIM1_REMAP_Msk             (0x3UL << AFIO_MAPR_TIM1_REMAP_Pos) /*!< 0x000000C0 */
#define AFIO_MAPR_TIM1_REMAP                 AFIO_MAPR_TIM1_REMAP_Msk          /*!< TIM1_REMAP[1:0] bits (TIM1 remapping) */
#define AFIO_MAPR_TIM1_REMAP_0               (0x1UL << AFIO_MAPR_TIM1_REMAP_Pos) /*!< 0x00000040 */
#define AFIO_MAPR_TIM1_REMAP_1               (0x2UL << AFIO_MAPR_TIM1_REMAP_Pos) /*!< 0x00000080 */

/*!< TIM1_REMAP configuration */
#define AFIO_MAPR_TIM1_REMAP_NOREMAP         0x00000000U                          /*!< No remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15) */
#define AFIO_MAPR_TIM1_REMAP_PARTIALREMAP_Pos (6U)                             
#define AFIO_MAPR_TIM1_REMAP_PARTIALREMAP_Msk (0x1UL << AFIO_MAPR_TIM1_REMAP_PARTIALREMAP_Pos) /*!< 0x00000040 */
#define AFIO_MAPR_TIM1_REMAP_PARTIALREMAP    AFIO_MAPR_TIM1_REMAP_PARTIALREMAP_Msk /*!< Partial remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PA6, CH1N/PA7, CH2N/PB0, CH3N/PB1) */
#define AFIO_MAPR_TIM1_REMAP_FULLREMAP_Pos   (6U)                              
#define AFIO_MAPR_TIM1_REMAP_FULLREMAP_Msk   (0x3UL << AFIO_MAPR_TIM1_REMAP_FULLREMAP_Pos) /*!< 0x000000C0 */
#define AFIO_MAPR_TIM1_REMAP_FULLREMAP       AFIO_MAPR_TIM1_REMAP_FULLREMAP_Msk /*!< Full remap (ETR/PE7, CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15, CH1N/PE8, CH2N/PE10, CH3N/PE12) */

#define AFIO_MAPR_TIM2_REMAP_Pos             (8U)                              
#define AFIO_MAPR_TIM2_REMAP_Msk             (0x3UL << AFIO_MAPR_TIM2_REMAP_Pos) /*!< 0x00000300 */
#define AFIO_MAPR_TIM2_REMAP                 AFIO_MAPR_TIM2_REMAP_Msk          /*!< TIM2_REMAP[1:0] bits (TIM2 remapping) */
#define AFIO_MAPR_TIM2_REMAP_0               (0x1UL << AFIO_MAPR_TIM2_REMAP_Pos) /*!< 0x00000100 */
#define AFIO_MAPR_TIM2_REMAP_1               (0x2UL << AFIO_MAPR_TIM2_REMAP_Pos) /*!< 0x00000200 */

/*!< TIM2_REMAP configuration */
#define AFIO_MAPR_TIM2_REMAP_NOREMAP         0x00000000U                          /*!< No remap (CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3) */
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1_Pos (8U)                            
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1_Msk (0x1UL << AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1_Pos) /*!< 0x00000100 */
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1   AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1_Msk /*!< Partial remap (CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3) */
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2_Pos (9U)                            
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2_Msk (0x1UL << AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2_Pos) /*!< 0x00000200 */
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2   AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2_Msk /*!< Partial remap (CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11) */
#define AFIO_MAPR_TIM2_REMAP_FULLREMAP_Pos   (8U)                              
#define AFIO_MAPR_TIM2_REMAP_FULLREMAP_Msk   (0x3UL << AFIO_MAPR_TIM2_REMAP_FULLREMAP_Pos) /*!< 0x00000300 */
#define AFIO_MAPR_TIM2_REMAP_FULLREMAP       AFIO_MAPR_TIM2_REMAP_FULLREMAP_Msk /*!< Full remap (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11) */

#define AFIO_MAPR_TIM3_REMAP_Pos             (10U)                             
#define AFIO_MAPR_TIM3_REMAP_Msk             (0x3UL << AFIO_MAPR_TIM3_REMAP_Pos) /*!< 0x00000C00 */
#define AFIO_MAPR_TIM3_REMAP                 AFIO_MAPR_TIM3_REMAP_Msk          /*!< TIM3_REMAP[1:0] bits (TIM3 remapping) */
#define AFIO_MAPR_TIM3_REMAP_0               (0x1UL << AFIO_MAPR_TIM3_REMAP_Pos) /*!< 0x00000400 */
#define AFIO_MAPR_TIM3_REMAP_1               (0x2UL << AFIO_MAPR_TIM3_REMAP_Pos) /*!< 0x00000800 */

/*!< TIM3_REMAP configuration */
#define AFIO_MAPR_TIM3_REMAP_NOREMAP         0x00000000U                          /*!< No remap (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1) */
#define AFIO_MAPR_TIM3_REMAP_PARTIALREMAP_Pos (11U)                            
#define AFIO_MAPR_TIM3_REMAP_PARTIALREMAP_Msk (0x1UL << AFIO_MAPR_TIM3_REMAP_PARTIALREMAP_Pos) /*!< 0x00000800 */
#define AFIO_MAPR_TIM3_REMAP_PARTIALREMAP    AFIO_MAPR_TIM3_REMAP_PARTIALREMAP_Msk /*!< Partial remap (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1) */
#define AFIO_MAPR_TIM3_REMAP_FULLREMAP_Pos   (10U)                             
#define AFIO_MAPR_TIM3_REMAP_FULLREMAP_Msk   (0x3UL << AFIO_MAPR_TIM3_REMAP_FULLREMAP_Pos) /*!< 0x00000C00 */
#define AFIO_MAPR_TIM3_REMAP_FULLREMAP       AFIO_MAPR_TIM3_REMAP_FULLREMAP_Msk /*!< Full remap (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9) */


#define AFIO_MAPR_CAN_REMAP_Pos              (13U)                             
#define AFIO_MAPR_CAN_REMAP_Msk              (0x3UL << AFIO_MAPR_CAN_REMAP_Pos) /*!< 0x00006000 */
#define AFIO_MAPR_CAN_REMAP                  AFIO_MAPR_CAN_REMAP_Msk           /*!< CAN_REMAP[1:0] bits (CAN Alternate function remapping) */
#define AFIO_MAPR_CAN_REMAP_0                (0x1UL << AFIO_MAPR_CAN_REMAP_Pos) /*!< 0x00002000 */
#define AFIO_MAPR_CAN_REMAP_1                (0x2UL << AFIO_MAPR_CAN_REMAP_Pos) /*!< 0x00004000 */

/*!< CAN_REMAP configuration */
#define AFIO_MAPR_CAN_REMAP_REMAP1           0x00000000U                          /*!< CANRX mapped to PA11, CANTX mapped to PA12 */
#define AFIO_MAPR_CAN_REMAP_REMAP2_Pos       (14U)                             
#define AFIO_MAPR_CAN_REMAP_REMAP2_Msk       (0x1UL << AFIO_MAPR_CAN_REMAP_REMAP2_Pos) /*!< 0x00004000 */
#define AFIO_MAPR_CAN_REMAP_REMAP2           AFIO_MAPR_CAN_REMAP_REMAP2_Msk    /*!< CANRX mapped to PB8, CANTX mapped to PB9 */
#define AFIO_MAPR_CAN_REMAP_REMAP3_Pos       (13U)                             
#define AFIO_MAPR_CAN_REMAP_REMAP3_Msk       (0x3UL << AFIO_MAPR_CAN_REMAP_REMAP3_Pos) /*!< 0x00006000 */
#define AFIO_MAPR_CAN_REMAP_REMAP3           AFIO_MAPR_CAN_REMAP_REMAP3_Msk    /*!< CANRX mapped to PD0, CANTX mapped to PD1 */

/******************  Bit definition for USART_BRR register  *******************/
#define USART_BRR_DIV_Fraction_Pos          (0U)                               
#define USART_BRR_DIV_Fraction_Msk          (0xFUL << USART_BRR_DIV_Fraction_Pos) /*!< 0x0000000F */
#define USART_BRR_DIV_Fraction              USART_BRR_DIV_Fraction_Msk         /*!< Fraction of USARTDIV */
#define USART_BRR_DIV_Mantissa_Pos          (4U)                               
#define USART_BRR_DIV_Mantissa_Msk          (0xFFFUL << USART_BRR_DIV_Mantissa_Pos) /*!< 0x0000FFF0 */
#define USART_BRR_DIV_Mantissa              USART_BRR_DIV_Mantissa_Msk         /*!< Mantissa of USARTDIV */

/******************  Bit definition for USART_CR1 register  *******************/
#define USART_CR1_SBK_Pos                   (0U)                               
#define USART_CR1_SBK_Msk                   (0x1UL << USART_CR1_SBK_Pos)        /*!< 0x00000001 */
#define USART_CR1_SBK                       USART_CR1_SBK_Msk                  /*!< Send Break */
#define USART_CR1_RWU_Pos                   (1U)                               
#define USART_CR1_RWU_Msk                   (0x1UL << USART_CR1_RWU_Pos)        /*!< 0x00000002 */
#define USART_CR1_RWU                       USART_CR1_RWU_Msk                  /*!< Receiver wakeup */
#define USART_CR1_RE_Pos                    (2U)                               
#define USART_CR1_RE_Msk                    (0x1UL << USART_CR1_RE_Pos)         /*!< 0x00000004 */
#define USART_CR1_RE                        USART_CR1_RE_Msk                   /*!< Receiver Enable */
#define USART_CR1_TE_Pos                    (3U)                               
#define USART_CR1_TE_Msk                    (0x1UL << USART_CR1_TE_Pos)         /*!< 0x00000008 */
#define USART_CR1_TE                        USART_CR1_TE_Msk                   /*!< Transmitter Enable */
#define USART_CR1_IDLEIE_Pos                (4U)                               
#define USART_CR1_IDLEIE_Msk                (0x1UL << USART_CR1_IDLEIE_Pos)     /*!< 0x00000010 */
#define USART_CR1_IDLEIE                    USART_CR1_IDLEIE_Msk               /*!< IDLE Interrupt Enable */
#define USART_CR1_RXNEIE_Pos                (5U)                               
#define USART_CR1_RXNEIE_Msk                (0x1UL << USART_CR1_RXNEIE_Pos)     /*!< 0x00000020 */
#define USART_CR1_RXNEIE                    USART_CR1_RXNEIE_Msk               /*!< RXNE Interrupt Enable */
#define USART_CR1_TCIE_Pos                  (6U)                               
#define USART_CR1_TCIE_Msk                  (0x1UL << USART_CR1_TCIE_Pos)       /*!< 0x00000040 */
#define USART_CR1_TCIE                      USART_CR1_TCIE_Msk                 /*!< Transmission Complete Interrupt Enable */
#define USART_CR1_TXEIE_Pos                 (7U)                               
#define USART_CR1_TXEIE_Msk                 (0x1UL << USART_CR1_TXEIE_Pos)      /*!< 0x00000080 */
#define USART_CR1_TXEIE                     USART_CR1_TXEIE_Msk                /*!< PE Interrupt Enable */
#define USART_CR1_PEIE_Pos                  (8U)                               
#define USART_CR1_PEIE_Msk                  (0x1UL << USART_CR1_PEIE_Pos)       /*!< 0x00000100 */
#define USART_CR1_PEIE                      USART_CR1_PEIE_Msk                 /*!< PE Interrupt Enable */
#define USART_CR1_PS_Pos                    (9U)                               
#define USART_CR1_PS_Msk                    (0x1UL << USART_CR1_PS_Pos)         /*!< 0x00000200 */
#define USART_CR1_PS                        USART_CR1_PS_Msk                   /*!< Parity Selection */
#define USART_CR1_PCE_Pos                   (10U)                              
#define USART_CR1_PCE_Msk                   (0x1UL << USART_CR1_PCE_Pos)        /*!< 0x00000400 */
#define USART_CR1_PCE                       USART_CR1_PCE_Msk                  /*!< Parity Control Enable */
#define USART_CR1_WAKE_Pos                  (11U)                              
#define USART_CR1_WAKE_Msk                  (0x1UL << USART_CR1_WAKE_Pos)       /*!< 0x00000800 */
#define USART_CR1_WAKE                      USART_CR1_WAKE_Msk                 /*!< Wakeup method */
#define USART_CR1_M_Pos                     (12U)                              
#define USART_CR1_M_Msk                     (0x1UL << USART_CR1_M_Pos)          /*!< 0x00001000 */
#define USART_CR1_M                         USART_CR1_M_Msk                    /*!< Word length */
#define USART_CR1_UE_Pos                    (13U)                              
#define USART_CR1_UE_Msk                    (0x1UL << USART_CR1_UE_Pos)         /*!< 0x00002000 */
#define USART_CR1_UE                        USART_CR1_UE_Msk                   /*!< USART Enable */

/*******************  Bit definition for USART_SR register  *******************/
#define USART_SR_PE_Pos                     (0U)                               
#define USART_SR_PE_Msk                     (0x1UL << USART_SR_PE_Pos)          /*!< 0x00000001 */
#define USART_SR_PE                         USART_SR_PE_Msk                    /*!< Parity Error */
#define USART_SR_FE_Pos                     (1U)                               
#define USART_SR_FE_Msk                     (0x1UL << USART_SR_FE_Pos)          /*!< 0x00000002 */
#define USART_SR_FE                         USART_SR_FE_Msk                    /*!< Framing Error */
#define USART_SR_NE_Pos                     (2U)                               
#define USART_SR_NE_Msk                     (0x1UL << USART_SR_NE_Pos)          /*!< 0x00000004 */
#define USART_SR_NE                         USART_SR_NE_Msk                    /*!< Noise Error Flag */
#define USART_SR_ORE_Pos                    (3U)                               
#define USART_SR_ORE_Msk                    (0x1UL << USART_SR_ORE_Pos)         /*!< 0x00000008 */
#define USART_SR_ORE                        USART_SR_ORE_Msk                   /*!< OverRun Error */
#define USART_SR_IDLE_Pos                   (4U)                               
#define USART_SR_IDLE_Msk                   (0x1UL << USART_SR_IDLE_Pos)        /*!< 0x00000010 */
#define USART_SR_IDLE                       USART_SR_IDLE_Msk                  /*!< IDLE line detected */
#define USART_SR_RXNE_Pos                   (5U)                               
#define USART_SR_RXNE_Msk                   (0x1UL << USART_SR_RXNE_Pos)        /*!< 0x00000020 */
#define USART_SR_RXNE                       USART_SR_RXNE_Msk                  /*!< Read Data Register Not Empty */
#define USART_SR_TC_Pos                     (6U)                               
#define USART_SR_TC_Msk                     (0x1UL << USART_SR_TC_Pos)          /*!< 0x00000040 */
#define USART_SR_TC                         USART_SR_TC_Msk                    /*!< Transmission Complete */
#define USART_SR_TXE_Pos                    (7U)                               
#define USART_SR_TXE_Msk                    (0x1UL << USART_SR_TXE_Pos)         /*!< 0x00000080 */
#define USART_SR_TXE                        USART_SR_TXE_Msk                   /*!< Transmit Data Register Empty */
#define USART_SR_LBD_Pos                    (8U)                               
#define USART_SR_LBD_Msk                    (0x1UL << USART_SR_LBD_Pos)         /*!< 0x00000100 */
#define USART_SR_LBD                        USART_SR_LBD_Msk                   /*!< LIN Break Detection Flag */
#define USART_SR_CTS_Pos                    (9U)                               
#define USART_SR_CTS_Msk                    (0x1UL << USART_SR_CTS_Pos)         /*!< 0x00000200 */
#define USART_SR_CTS                        USART_SR_CTS_Msk                   /*!< CTS Flag */

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

#define RCC_APB2ENR_SYSCFGEN_Pos           (14U)                               
#define RCC_APB2ENR_SYSCFGEN_Msk           (0x1UL << RCC_APB2ENR_SYSCFGEN_Pos)  //!< 0x00004000
#define RCC_APB2ENR_SYSCFGEN               RCC_APB2ENR_SYSCFGEN_Msk

#define RCC_APB2ENR_USART1EN_Pos           (4U)                                
#define RCC_APB2ENR_USART1EN_Msk           (0x1UL << RCC_APB2ENR_USART1EN_Pos)  /*!< 0x00000010 */
#define RCC_APB2ENR_USART1EN               RCC_APB2ENR_USART1EN_Msk     

#define RCC_APB1ENR_USART2EN_Pos           (17U)                               
#define RCC_APB1ENR_USART2EN_Msk           (0x1UL << RCC_APB1ENR_USART2EN_Pos)  /*!< 0x00020000 */
#define RCC_APB1ENR_USART2EN               RCC_APB1ENR_USART2EN_Msk                

#define USART_CR1_UE_Pos              (13U)                                    
#define USART_CR1_UE_Msk              (0x1UL << USART_CR1_UE_Pos)               /*!< 0x00002000 */
#define USART_CR1_UE                  USART_CR1_UE_Msk                         /*!<USART Enable                           */
#define USART_CR1_RE_Pos              (2U)                                     
#define USART_CR1_RE_Msk              (0x1UL << USART_CR1_RE_Pos)               /*!< 0x00000004 */
#define USART_CR1_RE                  USART_CR1_RE_Msk                         /*!<Receiver Enable                        */
#define USART_CR1_TE_Pos              (3U)                                     
#define USART_CR1_TE_Msk              (0x1UL << USART_CR1_TE_Pos)               /*!< 0x00000008 */
#define USART_CR1_TE                  USART_CR1_TE_Msk                         /*!<Transmitter Enable                     */
#define USART_CR1_IDLEIE_Pos          (4U)                                     
#define USART_CR1_IDLEIE_Msk          (0x1UL << USART_CR1_IDLEIE_Pos)           /*!< 0x00000010 */
#define USART_CR1_IDLEIE              USART_CR1_IDLEIE_Msk                     /*!<IDLE Interrupt Enable                  */
#define USART_CR1_RXNEIE_Pos          (5U)                                     
#define USART_CR1_RXNEIE_Msk          (0x1UL << USART_CR1_RXNEIE_Pos)           /*!< 0x00000020 */
#define USART_CR1_RXNEIE              USART_CR1_RXNEIE_Msk                     /*!<RXNE Interrupt Enable                  */

/******************  Bit definition for USART_BRR register  *******************/
#define USART_BRR_DIV_Fraction_Pos    (0U)                                     
#define USART_BRR_DIV_Fraction_Msk    (0xFUL << USART_BRR_DIV_Fraction_Pos)     /*!< 0x0000000F */
#define USART_BRR_DIV_Fraction        USART_BRR_DIV_Fraction_Msk               /*!<Fraction of USARTDIV */
#define USART_BRR_DIV_Mantissa_Pos    (4U)                                     
#define USART_BRR_DIV_Mantissa_Msk    (0xFFFUL << USART_BRR_DIV_Mantissa_Pos)   /*!< 0x0000FFF0 */
#define USART_BRR_DIV_Mantissa        USART_BRR_DIV_Mantissa_Msk               /*!<Mantissa of USARTDIV */

#define USART_SR_RXNE_Pos             (5U)                                     
#define USART_SR_RXNE_Msk             (0x1UL << USART_SR_RXNE_Pos)              /*!< 0x00000020 */
#define USART_SR_RXNE                 USART_SR_RXNE_Msk                        /*!<Read Data Register Not Empty */

#endif


#endif
