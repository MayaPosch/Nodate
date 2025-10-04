

#ifndef COMMON_H
#define COMMON_H

#include <cstdint>

#define __IO volatile
#define __IM volatile const
#define __IOM volatile

#ifndef   __STATIC_INLINE
	#define __STATIC_INLINE static inline
#endif


extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock) */


struct ADC_TypeDef {
  __IO uint32_t SR;
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t SMPR1;
  __IO uint32_t SMPR2;
  __IO uint32_t JOFR1;
  __IO uint32_t JOFR2;
  __IO uint32_t JOFR3;
  __IO uint32_t JOFR4;
  __IO uint32_t HTR;
  __IO uint32_t LTR;
  __IO uint32_t SQR1;
  __IO uint32_t SQR2;
  __IO uint32_t SQR3;
  __IO uint32_t JSQR;
  __IO uint32_t JDR1;
  __IO uint32_t JDR2;
  __IO uint32_t JDR3;
  __IO uint32_t JDR4;
  __IO uint32_t DR;
};


extern ADC_TypeDef* ADC1;


struct BKP_TypeDef {
  uint32_t  RESERVED0;
  __IO uint32_t DR1;
  __IO uint32_t DR2;
  __IO uint32_t DR3;
  __IO uint32_t DR4;
  __IO uint32_t DR5;
  __IO uint32_t DR6;
  __IO uint32_t DR7;
  __IO uint32_t DR8;
  __IO uint32_t DR9;
  __IO uint32_t DR10;
  __IO uint32_t RTCCR;
  __IO uint32_t CR;
  __IO uint32_t CSR;
};

extern BKP_TypeDef* BKP;


/** 
  * @brief FLASH Registers
  */

struct FLASH_TypeDef {
  __IO uint32_t ACR;
  __IO uint32_t KEYR;
  __IO uint32_t OPTKEYR;
  __IO uint32_t SR;
  __IO uint32_t CR;
  __IO uint32_t AR;
  __IO uint32_t RESERVED;
  __IO uint32_t OBR;
  __IO uint32_t WRPR;
};

extern FLASH_TypeDef* FLASH;


#if defined STM32F0
// STM32F0
struct SysTick_Type {
  __IOM uint32_t CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  __IOM uint32_t LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
  __IOM uint32_t VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
  __IM  uint32_t CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
};

extern SysTick_Type* SysTick;


struct ADC_Common_TypeDef {
  __IO uint32_t CCR;          /*!< ADC common configuration register,             Address offset: ADC1 base address + 0x308 */
};


 struct I2C_TypeDef {
  __IO uint32_t CR1;          /*!< I2C Control register 1,                      Address offset: 0x00 */
  __IO uint32_t CR2;          /*!< I2C Control register 2,                      Address offset: 0x04 */
  __IO uint32_t OAR1;     /*!< I2C Own address 1 register,        Address offset: 0x08 */
  __IO uint32_t OAR2;     /*!< I2C Own address 2 register,        Address offset: 0x0C */
  __IO uint32_t TIMINGR;  /*!< I2C Timing register,               Address offset: 0x10 */
  __IO uint32_t TIMEOUTR; /*!< I2C Timeout register,              Address offset: 0x14 */
  __IO uint32_t ISR;      /*!< I2C Interrupt and status register, Address offset: 0x18 */
  __IO uint32_t ICR;      /*!< I2C Interrupt clear register,      Address offset: 0x1C */
  __IO uint32_t PECR;     /*!< I2C PEC register,                  Address offset: 0x20 */
  __IO uint32_t RXDR;     /*!< I2C Receive data register,         Address offset: 0x24 */
  __IO uint32_t TXDR;     /*!< I2C Transmit data register,        Address offset: 0x28 */
};


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


struct RTC_TypeDef {
  __IO uint32_t TR;         /*!< RTC time register,                                         Address offset: 0x00 */
  __IO uint32_t DR;         /*!< RTC date register,                                         Address offset: 0x04 */
  __IO uint32_t CR;         /*!< RTC control register,                                      Address offset: 0x08 */                                                                                            
  __IO uint32_t ISR;        /*!< RTC initialization and status register,                    Address offset: 0x0C */
  __IO uint32_t PRER;       /*!< RTC prescaler register,                                    Address offset: 0x10 */
       uint32_t RESERVED1;  /*!< Reserved,                                                  Address offset: 0x14 */
       uint32_t RESERVED2;  /*!< Reserved,                                                  Address offset: 0x18 */
  __IO uint32_t ALRMAR;     /*!< RTC alarm A register,                                      Address offset: 0x1C */
       uint32_t RESERVED3;  /*!< Reserved,                                                  Address offset: 0x20 */
  __IO uint32_t WPR;        /*!< RTC write protection register,                             Address offset: 0x24 */
  __IO uint32_t SSR;        /*!< RTC sub second register,                                   Address offset: 0x28 */
  __IO uint32_t SHIFTR;     /*!< RTC shift control register,                                Address offset: 0x2C */
  __IO uint32_t TSTR;       /*!< RTC time stamp time register,                              Address offset: 0x30 */
  __IO uint32_t TSDR;       /*!< RTC time stamp date register,                              Address offset: 0x34 */
  __IO uint32_t TSSSR;      /*!< RTC time-stamp sub second register,                        Address offset: 0x38 */
  __IO uint32_t CALR;       /*!< RTC calibration register,                                  Address offset: 0x3C */
  __IO uint32_t TAFCR;      /*!< RTC tamper and alternate function configuration register,  Address offset: 0x40 */
  __IO uint32_t ALRMASSR;   /*!< RTC alarm A sub second register,                           Address offset: 0x44 */
       uint32_t RESERVED4;  /*!< Reserved,                                                  Address offset: 0x48 */
       uint32_t RESERVED5;  /*!< Reserved,                                                  Address offset: 0x4C */
  __IO uint32_t BKP0R;      /*!< RTC backup register 0,                                     Address offset: 0x50 */
  __IO uint32_t BKP1R;      /*!< RTC backup register 1,                                     Address offset: 0x54 */
  __IO uint32_t BKP2R;      /*!< RTC backup register 2,                                     Address offset: 0x58 */
  __IO uint32_t BKP3R;      /*!< RTC backup register 3,                                     Address offset: 0x5C */
  __IO uint32_t BKP4R;      /*!< RTC backup register 4,                                     Address offset: 0x60 */
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


struct I2C_TypeDef {
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t OAR1;
  __IO uint32_t OAR2;
  __IO uint32_t DR;
  __IO uint32_t SR1;
  __IO uint32_t SR2;
  __IO uint32_t CCR;
  __IO uint32_t TRISE;
};


#elif defined STM32F4

// STM32F4

struct SysTick_Type {
  __IOM uint32_t CTRL;		/*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  __IOM uint32_t LOAD;     	/*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
  __IOM uint32_t VAL;       /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
  __IM  uint32_t CALIB;     /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
};

extern SysTick_Type* SysTick;


/**
  \brief  Structure type to access the System Control Block (SCB).
 */
struct SCB_Type {
  __IM  uint32_t CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
  __IOM uint32_t ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
  __IOM uint32_t VTOR;                   /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
  __IOM uint32_t AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
  __IOM uint32_t SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
  __IOM uint32_t CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
  __IOM uint8_t  SHP[12U];               /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  __IOM uint32_t SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
  __IOM uint32_t CFSR;                   /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register */
  __IOM uint32_t HFSR;                   /*!< Offset: 0x02C (R/W)  HardFault Status Register */
  __IOM uint32_t DFSR;                   /*!< Offset: 0x030 (R/W)  Debug Fault Status Register */
  __IOM uint32_t MMFAR;                  /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register */
  __IOM uint32_t BFAR;                   /*!< Offset: 0x038 (R/W)  BusFault Address Register */
  __IOM uint32_t AFSR;                   /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register */
  __IM  uint32_t PFR[2U];                /*!< Offset: 0x040 (R/ )  Processor Feature Register */
  __IM  uint32_t DFR;                    /*!< Offset: 0x048 (R/ )  Debug Feature Register */
  __IM  uint32_t ADR;                    /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register */
  __IM  uint32_t MMFR[4U];               /*!< Offset: 0x050 (R/ )  Memory Model Feature Register */
  __IM  uint32_t ISAR[5U];               /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register */
        uint32_t RESERVED0[5U];
  __IOM uint32_t CPACR;                  /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register */
};

extern SCB_Type* SCB;


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


struct I2C_TypeDef {
  __IO uint32_t CR1;        /*!< I2C Control register 1,     Address offset: 0x00 */
  __IO uint32_t CR2;        /*!< I2C Control register 2,     Address offset: 0x04 */
  __IO uint32_t OAR1;       /*!< I2C Own address register 1, Address offset: 0x08 */
  __IO uint32_t OAR2;       /*!< I2C Own address register 2, Address offset: 0x0C */
  __IO uint32_t DR;         /*!< I2C Data register,          Address offset: 0x10 */
  __IO uint32_t SR1;        /*!< I2C Status register 1,      Address offset: 0x14 */
  __IO uint32_t SR2;        /*!< I2C Status register 2,      Address offset: 0x18 */
  __IO uint32_t CCR;        /*!< I2C Clock control register, Address offset: 0x1C */
  __IO uint32_t TRISE;      /*!< I2C TRISE register,         Address offset: 0x20 */
  __IO uint32_t FLTR;       /*!< I2C FLTR register,          Address offset: 0x24 */
};


struct RTC_TypeDef {
  __IO uint32_t TR;      /*!< RTC time register,                                        Address offset: 0x00 */
  __IO uint32_t DR;      /*!< RTC date register,                                        Address offset: 0x04 */
  __IO uint32_t CR;      /*!< RTC control register,                                     Address offset: 0x08 */
  __IO uint32_t ISR;     /*!< RTC initialization and status register,                   Address offset: 0x0C */
  __IO uint32_t PRER;    /*!< RTC prescaler register,                                   Address offset: 0x10 */
  __IO uint32_t WUTR;    /*!< RTC wakeup timer register,                                Address offset: 0x14 */
  __IO uint32_t CALIBR;  /*!< RTC calibration register,                                 Address offset: 0x18 */
  __IO uint32_t ALRMAR;  /*!< RTC alarm A register,                                     Address offset: 0x1C */
  __IO uint32_t ALRMBR;  /*!< RTC alarm B register,                                     Address offset: 0x20 */
  __IO uint32_t WPR;     /*!< RTC write protection register,                            Address offset: 0x24 */
  __IO uint32_t SSR;     /*!< RTC sub second register,                                  Address offset: 0x28 */
  __IO uint32_t SHIFTR;  /*!< RTC shift control register,                               Address offset: 0x2C */
  __IO uint32_t TSTR;    /*!< RTC time stamp time register,                             Address offset: 0x30 */
  __IO uint32_t TSDR;    /*!< RTC time stamp date register,                             Address offset: 0x34 */
  __IO uint32_t TSSSR;   /*!< RTC time-stamp sub second register,                       Address offset: 0x38 */
  __IO uint32_t CALR;    /*!< RTC calibration register,                                 Address offset: 0x3C */
  __IO uint32_t TAFCR;   /*!< RTC tamper and alternate function configuration register, Address offset: 0x40 */
  __IO uint32_t ALRMASSR;/*!< RTC alarm A sub second register,                          Address offset: 0x44 */
  __IO uint32_t ALRMBSSR;/*!< RTC alarm B sub second register,                          Address offset: 0x48 */
  uint32_t RESERVED7;    /*!< Reserved, 0x4C                                                                 */
  __IO uint32_t BKP0R;   /*!< RTC backup register 1,                                    Address offset: 0x50 */
  __IO uint32_t BKP1R;   /*!< RTC backup register 1,                                    Address offset: 0x54 */
  __IO uint32_t BKP2R;   /*!< RTC backup register 2,                                    Address offset: 0x58 */
  __IO uint32_t BKP3R;   /*!< RTC backup register 3,                                    Address offset: 0x5C */
  __IO uint32_t BKP4R;   /*!< RTC backup register 4,                                    Address offset: 0x60 */
  __IO uint32_t BKP5R;   /*!< RTC backup register 5,                                    Address offset: 0x64 */
  __IO uint32_t BKP6R;   /*!< RTC backup register 6,                                    Address offset: 0x68 */
  __IO uint32_t BKP7R;   /*!< RTC backup register 7,                                    Address offset: 0x6C */
  __IO uint32_t BKP8R;   /*!< RTC backup register 8,                                    Address offset: 0x70 */
  __IO uint32_t BKP9R;   /*!< RTC backup register 9,                                    Address offset: 0x74 */
  __IO uint32_t BKP10R;  /*!< RTC backup register 10,                                   Address offset: 0x78 */
  __IO uint32_t BKP11R;  /*!< RTC backup register 11,                                   Address offset: 0x7C */
  __IO uint32_t BKP12R;  /*!< RTC backup register 12,                                   Address offset: 0x80 */
  __IO uint32_t BKP13R;  /*!< RTC backup register 13,                                   Address offset: 0x84 */
  __IO uint32_t BKP14R;  /*!< RTC backup register 14,                                   Address offset: 0x88 */
  __IO uint32_t BKP15R;  /*!< RTC backup register 15,                                   Address offset: 0x8C */
  __IO uint32_t BKP16R;  /*!< RTC backup register 16,                                   Address offset: 0x90 */
  __IO uint32_t BKP17R;  /*!< RTC backup register 17,                                   Address offset: 0x94 */
  __IO uint32_t BKP18R;  /*!< RTC backup register 18,                                   Address offset: 0x98 */
  __IO uint32_t BKP19R;  /*!< RTC backup register 19,                                   Address offset: 0x9C */
};


struct DMA_Stream_TypeDef {
  __IO uint32_t CR;     /*!< DMA stream x configuration register      */
  __IO uint32_t NDTR;   /*!< DMA stream x number of data register     */
  __IO uint32_t PAR;    /*!< DMA stream x peripheral address register */
  __IO uint32_t M0AR;   /*!< DMA stream x memory 0 address register   */
  __IO uint32_t M1AR;   /*!< DMA stream x memory 1 address register   */
  __IO uint32_t FCR;    /*!< DMA stream x FIFO control register       */
};

/* struct DMA_TypeDef {
  __IO uint32_t LISR;   //!< DMA low interrupt status register,      Address offset: 0x00 
  __IO uint32_t HISR;   //!< DMA high interrupt status register,     Address offset: 0x04 
  __IO uint32_t LIFCR;  //!< DMA low interrupt flag clear register,  Address offset: 0x08 
  __IO uint32_t HIFCR;  //!< DMA high interrupt flag clear register, Address offset: 0x0C 
}; */


/* struct ADC_TypeDef {
  __IO uint32_t SR;     //!< ADC status register,                         Address offset: 0x00 
  __IO uint32_t CR1;    //!< ADC control register 1,                      Address offset: 0x04 
  __IO uint32_t CR2;    //!< ADC control register 2,                      Address offset: 0x08 
  __IO uint32_t SMPR1;  //!< ADC sample time register 1,                  Address offset: 0x0C 
  __IO uint32_t SMPR2;  //!< ADC sample time register 2,                  Address offset: 0x10 
  __IO uint32_t JOFR1;  //!< ADC injected channel data offset register 1, Address offset: 0x14 
  __IO uint32_t JOFR2;  //!< ADC injected channel data offset register 2, Address offset: 0x18 
  __IO uint32_t JOFR3;  //!< ADC injected channel data offset register 3, Address offset: 0x1C 
  __IO uint32_t JOFR4;  //!< ADC injected channel data offset register 4, Address offset: 0x20 
  __IO uint32_t HTR;    //!< ADC watchdog higher threshold register,      Address offset: 0x24 
  __IO uint32_t LTR;    //!< ADC watchdog lower threshold register,       Address offset: 0x28 
  __IO uint32_t SQR1;   //!< ADC regular sequence register 1,             Address offset: 0x2C 
  __IO uint32_t SQR2;   //!< ADC regular sequence register 2,             Address offset: 0x30 
  __IO uint32_t SQR3;   //!< ADC regular sequence register 3,             Address offset: 0x34 
  __IO uint32_t JSQR;   //!< ADC injected sequence register,              Address offset: 0x38
  __IO uint32_t JDR1;   //!< ADC injected data register 1,                Address offset: 0x3C
  __IO uint32_t JDR2;   //!< ADC injected data register 2,                Address offset: 0x40 
  __IO uint32_t JDR3;   //!< ADC injected data register 3,                Address offset: 0x44 
  __IO uint32_t JDR4;   //!< ADC injected data register 4,                Address offset: 0x48 
  __IO uint32_t DR;     //!< ADC regular data register,                   Address offset: 0x4C 
}; */

struct ADC_Common_TypeDef {
  __IO uint32_t CSR;    /*!< ADC Common status register,                  Address offset: ADC1 base address + 0x300 */
  __IO uint32_t CCR;    /*!< ADC common control register,                 Address offset: ADC1 base address + 0x304 */
  __IO uint32_t CDR;    /*!< ADC common regular data register for dual
                             AND triple modes,                            Address offset: ADC1 base address + 0x308 */
};


#endif

extern GPIO_TypeDef* GPIOA;
extern GPIO_TypeDef* GPIOB;
extern GPIO_TypeDef* GPIOC;
extern GPIO_TypeDef* GPIOD;
extern GPIO_TypeDef* GPIOE;
extern GPIO_TypeDef* GPIOF;


struct PWR_TypeDef {
  __IO uint32_t CR;
  __IO uint32_t CSR;
};


extern PWR_TypeDef* PWR;
extern I2C_TypeDef* I2C1;


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


struct RTC_TypeDef {
  __IO uint32_t CRH;
  __IO uint32_t CRL;
  __IO uint32_t PRLH;
  __IO uint32_t PRLL;
  __IO uint32_t DIVH;
  __IO uint32_t DIVL;
  __IO uint32_t CNTH;
  __IO uint32_t CNTL;
  __IO uint32_t ALRH;
  __IO uint32_t ALRL;
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
extern RTC_TypeDef* RTC;


struct SPI_TypeDef {
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t SR;
  __IO uint32_t DR;
  __IO uint32_t CRCPR;
  __IO uint32_t RXCRCR;
  __IO uint32_t TXCRCR;
  __IO uint32_t I2SCFGR;
};

extern SPI_TypeDef* SPI1;


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

struct DMA_Channel_TypeDef {
  __IO uint32_t CCR;
  __IO uint32_t CNDTR;
  __IO uint32_t CPAR;
  __IO uint32_t CMAR;
};

struct DMA_TypeDef {
  __IO uint32_t ISR;
  __IO uint32_t IFCR;
};


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
	#include "stm32f0/stm32f0_def.h"
#elif defined STM32F1
	#include "stm32f1/stm32f1_def.h"
#elif defined STM32F4
	#include "stm32f4/stm32f4_def.h"
#else
	//
#endif


#endif
