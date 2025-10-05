/*
	STM32F4xx defines for local testing.
*/


/**
  * @brief Configuration of the Cortex-M4 Processor and Core Peripherals 
  */
#define __CM4_REV                 0x0001U  /*!< Core revision r0p1                            */
#define __MPU_PRESENT             1U       /*!< STM32F4XX provides an MPU                     */
#define __NVIC_PRIO_BITS          4U       /*!< STM32F4XX uses 4 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0U       /*!< Set to 1 if different SysTick Config is used  */
#define __FPU_PRESENT             1U       /*!< FPU present                                   */


/* SysTick Control / Status Register Definitions */
#define SysTick_CTRL_COUNTFLAG_Pos         16U                                            /*!< SysTick CTRL: COUNTFLAG Position */
#define SysTick_CTRL_COUNTFLAG_Msk         (1UL << SysTick_CTRL_COUNTFLAG_Pos)            /*!< SysTick CTRL: COUNTFLAG Mask */

#define SysTick_CTRL_CLKSOURCE_Pos          2U                                            /*!< SysTick CTRL: CLKSOURCE Position */
#define SysTick_CTRL_CLKSOURCE_Msk         (1UL << SysTick_CTRL_CLKSOURCE_Pos)            /*!< SysTick CTRL: CLKSOURCE Mask */

#define SysTick_CTRL_TICKINT_Pos            1U                                            /*!< SysTick CTRL: TICKINT Position */
#define SysTick_CTRL_TICKINT_Msk           (1UL << SysTick_CTRL_TICKINT_Pos)              /*!< SysTick CTRL: TICKINT Mask */

#define SysTick_CTRL_ENABLE_Pos             0U                                            /*!< SysTick CTRL: ENABLE Position */
#define SysTick_CTRL_ENABLE_Msk            (1UL /*<< SysTick_CTRL_ENABLE_Pos*/)           /*!< SysTick CTRL: ENABLE Mask */

/* SysTick Reload Register Definitions */
#define SysTick_LOAD_RELOAD_Pos             0U                                            /*!< SysTick LOAD: RELOAD Position */
#define SysTick_LOAD_RELOAD_Msk            (0xFFFFFFUL /*<< SysTick_LOAD_RELOAD_Pos*/)    /*!< SysTick LOAD: RELOAD Mask */

/* SysTick Current Register Definitions */
#define SysTick_VAL_CURRENT_Pos             0U                                            /*!< SysTick VAL: CURRENT Position */
#define SysTick_VAL_CURRENT_Msk            (0xFFFFFFUL /*<< SysTick_VAL_CURRENT_Pos*/)    /*!< SysTick VAL: CURRENT Mask */

/* SysTick Calibration Register Definitions */
#define SysTick_CALIB_NOREF_Pos            31U                                            /*!< SysTick CALIB: NOREF Position */
#define SysTick_CALIB_NOREF_Msk            (1UL << SysTick_CALIB_NOREF_Pos)               /*!< SysTick CALIB: NOREF Mask */

#define SysTick_CALIB_SKEW_Pos             30U                                            /*!< SysTick CALIB: SKEW Position */
#define SysTick_CALIB_SKEW_Msk             (1UL << SysTick_CALIB_SKEW_Pos)                /*!< SysTick CALIB: SKEW Mask */

#define SysTick_CALIB_TENMS_Pos             0U                                            /*!< SysTick CALIB: TENMS Position */
#define SysTick_CALIB_TENMS_Msk            (0xFFFFFFUL /*<< SysTick_CALIB_TENMS_Pos*/)    /*!< SysTick CALIB: TENMS Mask */

/*@} end of group CMSIS_SysTick */





/* SCB Application Interrupt and Reset Control Register Definitions */
#define SCB_AIRCR_VECTKEY_Pos              16U                                            /*!< SCB AIRCR: VECTKEY Position */
#define SCB_AIRCR_VECTKEY_Msk              (0xFFFFUL << SCB_AIRCR_VECTKEY_Pos)            /*!< SCB AIRCR: VECTKEY Mask */

#define SCB_AIRCR_VECTKEYSTAT_Pos          16U                                            /*!< SCB AIRCR: VECTKEYSTAT Position */
#define SCB_AIRCR_VECTKEYSTAT_Msk          (0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_Pos)        /*!< SCB AIRCR: VECTKEYSTAT Mask */

#define SCB_AIRCR_ENDIANESS_Pos            15U                                            /*!< SCB AIRCR: ENDIANESS Position */
#define SCB_AIRCR_ENDIANESS_Msk            (1UL << SCB_AIRCR_ENDIANESS_Pos)               /*!< SCB AIRCR: ENDIANESS Mask */

#define SCB_AIRCR_PRIGROUP_Pos              8U                                            /*!< SCB AIRCR: PRIGROUP Position */
#define SCB_AIRCR_PRIGROUP_Msk             (7UL << SCB_AIRCR_PRIGROUP_Pos)                /*!< SCB AIRCR: PRIGROUP Mask */

#define SCB_AIRCR_SYSRESETREQ_Pos           2U                                            /*!< SCB AIRCR: SYSRESETREQ Position */
#define SCB_AIRCR_SYSRESETREQ_Msk          (1UL << SCB_AIRCR_SYSRESETREQ_Pos)             /*!< SCB AIRCR: SYSRESETREQ Mask */

#define SCB_AIRCR_VECTCLRACTIVE_Pos         1U                                            /*!< SCB AIRCR: VECTCLRACTIVE Position */
#define SCB_AIRCR_VECTCLRACTIVE_Msk        (1UL << SCB_AIRCR_VECTCLRACTIVE_Pos)           /*!< SCB AIRCR: VECTCLRACTIVE Mask */

#define SCB_AIRCR_VECTRESET_Pos             0U                                            /*!< SCB AIRCR: VECTRESET Position */
#define SCB_AIRCR_VECTRESET_Msk            (1UL /*<< SCB_AIRCR_VECTRESET_Pos*/)           /*!< SCB AIRCR: VECTRESET Mask */





/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for RCC_CR register  ********************/
#define RCC_CR_HSION_Pos                   (0U)                                
#define RCC_CR_HSION_Msk                   (0x1UL << RCC_CR_HSION_Pos)          /*!< 0x00000001 */
#define RCC_CR_HSION                       RCC_CR_HSION_Msk                    
#define RCC_CR_HSIRDY_Pos                  (1U)                                
#define RCC_CR_HSIRDY_Msk                  (0x1UL << RCC_CR_HSIRDY_Pos)         /*!< 0x00000002 */
#define RCC_CR_HSIRDY                      RCC_CR_HSIRDY_Msk                   

#define RCC_CR_HSITRIM_Pos                 (3U)                                
#define RCC_CR_HSITRIM_Msk                 (0x1FUL << RCC_CR_HSITRIM_Pos)       /*!< 0x000000F8 */
#define RCC_CR_HSITRIM                     RCC_CR_HSITRIM_Msk                  
#define RCC_CR_HSITRIM_0                   (0x01UL << RCC_CR_HSITRIM_Pos)       /*!< 0x00000008 */
#define RCC_CR_HSITRIM_1                   (0x02UL << RCC_CR_HSITRIM_Pos)       /*!< 0x00000010 */
#define RCC_CR_HSITRIM_2                   (0x04UL << RCC_CR_HSITRIM_Pos)       /*!< 0x00000020 */
#define RCC_CR_HSITRIM_3                   (0x08UL << RCC_CR_HSITRIM_Pos)       /*!< 0x00000040 */
#define RCC_CR_HSITRIM_4                   (0x10UL << RCC_CR_HSITRIM_Pos)       /*!< 0x00000080 */

#define RCC_CR_HSICAL_Pos                  (8U)                                
#define RCC_CR_HSICAL_Msk                  (0xFFUL << RCC_CR_HSICAL_Pos)        /*!< 0x0000FF00 */
#define RCC_CR_HSICAL                      RCC_CR_HSICAL_Msk                   
#define RCC_CR_HSICAL_0                    (0x01UL << RCC_CR_HSICAL_Pos)        /*!< 0x00000100 */
#define RCC_CR_HSICAL_1                    (0x02UL << RCC_CR_HSICAL_Pos)        /*!< 0x00000200 */
#define RCC_CR_HSICAL_2                    (0x04UL << RCC_CR_HSICAL_Pos)        /*!< 0x00000400 */
#define RCC_CR_HSICAL_3                    (0x08UL << RCC_CR_HSICAL_Pos)        /*!< 0x00000800 */
#define RCC_CR_HSICAL_4                    (0x10UL << RCC_CR_HSICAL_Pos)        /*!< 0x00001000 */
#define RCC_CR_HSICAL_5                    (0x20UL << RCC_CR_HSICAL_Pos)        /*!< 0x00002000 */
#define RCC_CR_HSICAL_6                    (0x40UL << RCC_CR_HSICAL_Pos)        /*!< 0x00004000 */
#define RCC_CR_HSICAL_7                    (0x80UL << RCC_CR_HSICAL_Pos)        /*!< 0x00008000 */

#define RCC_CR_HSEON_Pos                   (16U)                               
#define RCC_CR_HSEON_Msk                   (0x1UL << RCC_CR_HSEON_Pos)          /*!< 0x00010000 */
#define RCC_CR_HSEON                       RCC_CR_HSEON_Msk                    
#define RCC_CR_HSERDY_Pos                  (17U)                               
#define RCC_CR_HSERDY_Msk                  (0x1UL << RCC_CR_HSERDY_Pos)         /*!< 0x00020000 */
#define RCC_CR_HSERDY                      RCC_CR_HSERDY_Msk                   
#define RCC_CR_HSEBYP_Pos                  (18U)                               
#define RCC_CR_HSEBYP_Msk                  (0x1UL << RCC_CR_HSEBYP_Pos)         /*!< 0x00040000 */
#define RCC_CR_HSEBYP                      RCC_CR_HSEBYP_Msk                   
#define RCC_CR_CSSON_Pos                   (19U)                               
#define RCC_CR_CSSON_Msk                   (0x1UL << RCC_CR_CSSON_Pos)          /*!< 0x00080000 */
#define RCC_CR_CSSON                       RCC_CR_CSSON_Msk                    
#define RCC_CR_PLLON_Pos                   (24U)                               
#define RCC_CR_PLLON_Msk                   (0x1UL << RCC_CR_PLLON_Pos)          /*!< 0x01000000 */
#define RCC_CR_PLLON                       RCC_CR_PLLON_Msk                    
#define RCC_CR_PLLRDY_Pos                  (25U)                               
#define RCC_CR_PLLRDY_Msk                  (0x1UL << RCC_CR_PLLRDY_Pos)         /*!< 0x02000000 */
#define RCC_CR_PLLRDY                      RCC_CR_PLLRDY_Msk                   
/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F4 serie)
 */
#define RCC_PLLI2S_SUPPORT                                                     /*!< Support PLLI2S oscillator */

#define RCC_CR_PLLI2SON_Pos                (26U)                               
#define RCC_CR_PLLI2SON_Msk                (0x1UL << RCC_CR_PLLI2SON_Pos)       /*!< 0x04000000 */
#define RCC_CR_PLLI2SON                    RCC_CR_PLLI2SON_Msk                 
#define RCC_CR_PLLI2SRDY_Pos               (27U)                               
#define RCC_CR_PLLI2SRDY_Msk               (0x1UL << RCC_CR_PLLI2SRDY_Pos)      /*!< 0x08000000 */
#define RCC_CR_PLLI2SRDY                   RCC_CR_PLLI2SRDY_Msk                

/********************  Bit definition for RCC_PLLCFGR register  ***************/
#define RCC_PLLCFGR_PLLM_Pos               (0U)                                
#define RCC_PLLCFGR_PLLM_Msk               (0x3FUL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x0000003F */
#define RCC_PLLCFGR_PLLM                   RCC_PLLCFGR_PLLM_Msk                
#define RCC_PLLCFGR_PLLM_0                 (0x01UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000001 */
#define RCC_PLLCFGR_PLLM_1                 (0x02UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000002 */
#define RCC_PLLCFGR_PLLM_2                 (0x04UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000004 */
#define RCC_PLLCFGR_PLLM_3                 (0x08UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000008 */
#define RCC_PLLCFGR_PLLM_4                 (0x10UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000010 */
#define RCC_PLLCFGR_PLLM_5                 (0x20UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000020 */

#define RCC_PLLCFGR_PLLN_Pos               (6U)                                
#define RCC_PLLCFGR_PLLN_Msk               (0x1FFUL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00007FC0 */
#define RCC_PLLCFGR_PLLN                   RCC_PLLCFGR_PLLN_Msk                
#define RCC_PLLCFGR_PLLN_0                 (0x001UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000040 */
#define RCC_PLLCFGR_PLLN_1                 (0x002UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000080 */
#define RCC_PLLCFGR_PLLN_2                 (0x004UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000100 */
#define RCC_PLLCFGR_PLLN_3                 (0x008UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000200 */
#define RCC_PLLCFGR_PLLN_4                 (0x010UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000400 */
#define RCC_PLLCFGR_PLLN_5                 (0x020UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000800 */
#define RCC_PLLCFGR_PLLN_6                 (0x040UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00001000 */
#define RCC_PLLCFGR_PLLN_7                 (0x080UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00002000 */
#define RCC_PLLCFGR_PLLN_8                 (0x100UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00004000 */

#define RCC_PLLCFGR_PLLP_Pos               (16U)                               
#define RCC_PLLCFGR_PLLP_Msk               (0x3UL << RCC_PLLCFGR_PLLP_Pos)      /*!< 0x00030000 */
#define RCC_PLLCFGR_PLLP                   RCC_PLLCFGR_PLLP_Msk                
#define RCC_PLLCFGR_PLLP_0                 (0x1UL << RCC_PLLCFGR_PLLP_Pos)      /*!< 0x00010000 */
#define RCC_PLLCFGR_PLLP_1                 (0x2UL << RCC_PLLCFGR_PLLP_Pos)      /*!< 0x00020000 */

#define RCC_PLLCFGR_PLLSRC_Pos             (22U)                               
#define RCC_PLLCFGR_PLLSRC_Msk             (0x1UL << RCC_PLLCFGR_PLLSRC_Pos)    /*!< 0x00400000 */
#define RCC_PLLCFGR_PLLSRC                 RCC_PLLCFGR_PLLSRC_Msk              
#define RCC_PLLCFGR_PLLSRC_HSE_Pos         (22U)                               
#define RCC_PLLCFGR_PLLSRC_HSE_Msk         (0x1UL << RCC_PLLCFGR_PLLSRC_HSE_Pos) /*!< 0x00400000 */
#define RCC_PLLCFGR_PLLSRC_HSE             RCC_PLLCFGR_PLLSRC_HSE_Msk          
#define RCC_PLLCFGR_PLLSRC_HSI             0x00000000U                         

#define RCC_PLLCFGR_PLLQ_Pos               (24U)                               
#define RCC_PLLCFGR_PLLQ_Msk               (0xFUL << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x0F000000 */
#define RCC_PLLCFGR_PLLQ                   RCC_PLLCFGR_PLLQ_Msk                
#define RCC_PLLCFGR_PLLQ_0                 (0x1UL << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x01000000 */
#define RCC_PLLCFGR_PLLQ_1                 (0x2UL << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x02000000 */
#define RCC_PLLCFGR_PLLQ_2                 (0x4UL << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x04000000 */
#define RCC_PLLCFGR_PLLQ_3                 (0x8UL << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x08000000 */



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


/********************  Bit definition for RCC_AHB2ENR register  ***************/
/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F4 series)
 */
#define RCC_AHB2_SUPPORT                   /*!< AHB2 Bus is supported */

#define RCC_AHB2ENR_OTGFSEN_Pos            (7U)
#define RCC_AHB2ENR_OTGFSEN_Msk            (0x1UL << RCC_AHB2ENR_OTGFSEN_Pos)   /*!< 0x00000080 */
#define RCC_AHB2ENR_OTGFSEN                RCC_AHB2ENR_OTGFSEN_Msk

/********************  Bit definition for RCC_APB1ENR register  ***************/
#define RCC_APB1ENR_TIM2EN_Pos             (0U)
#define RCC_APB1ENR_TIM2EN_Msk             (0x1UL << RCC_APB1ENR_TIM2EN_Pos)    /*!< 0x00000001 */
#define RCC_APB1ENR_TIM2EN                 RCC_APB1ENR_TIM2EN_Msk
#define RCC_APB1ENR_TIM3EN_Pos             (1U)
#define RCC_APB1ENR_TIM3EN_Msk             (0x1UL << RCC_APB1ENR_TIM3EN_Pos)    /*!< 0x00000002 */
#define RCC_APB1ENR_TIM3EN                 RCC_APB1ENR_TIM3EN_Msk
#define RCC_APB1ENR_TIM4EN_Pos             (2U)
#define RCC_APB1ENR_TIM4EN_Msk             (0x1UL << RCC_APB1ENR_TIM4EN_Pos)    /*!< 0x00000004 */
#define RCC_APB1ENR_TIM4EN                 RCC_APB1ENR_TIM4EN_Msk
#define RCC_APB1ENR_TIM5EN_Pos             (3U)
#define RCC_APB1ENR_TIM5EN_Msk             (0x1UL << RCC_APB1ENR_TIM5EN_Pos)    /*!< 0x00000008 */
#define RCC_APB1ENR_TIM5EN                 RCC_APB1ENR_TIM5EN_Msk
#define RCC_APB1ENR_WWDGEN_Pos             (11U)
#define RCC_APB1ENR_WWDGEN_Msk             (0x1UL << RCC_APB1ENR_WWDGEN_Pos)    /*!< 0x00000800 */
#define RCC_APB1ENR_WWDGEN                 RCC_APB1ENR_WWDGEN_Msk
#define RCC_APB1ENR_SPI2EN_Pos             (14U)
#define RCC_APB1ENR_SPI2EN_Msk             (0x1UL << RCC_APB1ENR_SPI2EN_Pos)    /*!< 0x00004000 */
#define RCC_APB1ENR_SPI2EN                 RCC_APB1ENR_SPI2EN_Msk
#define RCC_APB1ENR_SPI3EN_Pos             (15U)
#define RCC_APB1ENR_SPI3EN_Msk             (0x1UL << RCC_APB1ENR_SPI3EN_Pos)    /*!< 0x00008000 */
#define RCC_APB1ENR_SPI3EN                 RCC_APB1ENR_SPI3EN_Msk
#define RCC_APB1ENR_USART2EN_Pos           (17U)
#define RCC_APB1ENR_USART2EN_Msk           (0x1UL << RCC_APB1ENR_USART2EN_Pos)  /*!< 0x00020000 */
#define RCC_APB1ENR_USART2EN               RCC_APB1ENR_USART2EN_Msk
#define RCC_APB1ENR_I2C1EN_Pos             (21U)
#define RCC_APB1ENR_I2C1EN_Msk             (0x1UL << RCC_APB1ENR_I2C1EN_Pos)    /*!< 0x00200000 */
#define RCC_APB1ENR_I2C1EN                 RCC_APB1ENR_I2C1EN_Msk
#define RCC_APB1ENR_I2C2EN_Pos             (22U)
#define RCC_APB1ENR_I2C2EN_Msk             (0x1UL << RCC_APB1ENR_I2C2EN_Pos)    /*!< 0x00400000 */
#define RCC_APB1ENR_I2C2EN                 RCC_APB1ENR_I2C2EN_Msk
#define RCC_APB1ENR_I2C3EN_Pos             (23U)
#define RCC_APB1ENR_I2C3EN_Msk             (0x1UL << RCC_APB1ENR_I2C3EN_Pos)    /*!< 0x00800000 */
#define RCC_APB1ENR_I2C3EN                 RCC_APB1ENR_I2C3EN_Msk
#define RCC_APB1ENR_PWREN_Pos              (28U)
#define RCC_APB1ENR_PWREN_Msk              (0x1UL << RCC_APB1ENR_PWREN_Pos)     /*!< 0x10000000 */
#define RCC_APB1ENR_PWREN                  RCC_APB1ENR_PWREN_Msk

/********************  Bit definition for RCC_APB2ENR register  ***************/
#define RCC_APB2ENR_TIM1EN_Pos             (0U)
#define RCC_APB2ENR_TIM1EN_Msk             (0x1UL << RCC_APB2ENR_TIM1EN_Pos)    /*!< 0x00000001 */
#define RCC_APB2ENR_TIM1EN                 RCC_APB2ENR_TIM1EN_Msk
#define RCC_APB2ENR_USART1EN_Pos           (4U)
#define RCC_APB2ENR_USART1EN_Msk           (0x1UL << RCC_APB2ENR_USART1EN_Pos)  /*!< 0x00000010 */
#define RCC_APB2ENR_USART1EN               RCC_APB2ENR_USART1EN_Msk
#define RCC_APB2ENR_USART6EN_Pos           (5U)
#define RCC_APB2ENR_USART6EN_Msk           (0x1UL << RCC_APB2ENR_USART6EN_Pos)  /*!< 0x00000020 */
#define RCC_APB2ENR_USART6EN               RCC_APB2ENR_USART6EN_Msk
#define RCC_APB2ENR_ADC1EN_Pos             (8U)
#define RCC_APB2ENR_ADC1EN_Msk             (0x1UL << RCC_APB2ENR_ADC1EN_Pos)    /*!< 0x00000100 */
#define RCC_APB2ENR_ADC1EN                 RCC_APB2ENR_ADC1EN_Msk
#define RCC_APB2ENR_SDIOEN_Pos             (11U)
#define RCC_APB2ENR_SDIOEN_Msk             (0x1UL << RCC_APB2ENR_SDIOEN_Pos)    /*!< 0x00000800 */
#define RCC_APB2ENR_SDIOEN                 RCC_APB2ENR_SDIOEN_Msk
#define RCC_APB2ENR_SPI1EN_Pos             (12U)
#define RCC_APB2ENR_SPI1EN_Msk             (0x1UL << RCC_APB2ENR_SPI1EN_Pos)    /*!< 0x00001000 */
#define RCC_APB2ENR_SPI1EN                 RCC_APB2ENR_SPI1EN_Msk
#define RCC_APB2ENR_SPI4EN_Pos             (13U)
#define RCC_APB2ENR_SPI4EN_Msk             (0x1UL << RCC_APB2ENR_SPI4EN_Pos)    /*!< 0x00002000 */
#define RCC_APB2ENR_SPI4EN                 RCC_APB2ENR_SPI4EN_Msk
#define RCC_APB2ENR_SYSCFGEN_Pos           (14U)
#define RCC_APB2ENR_SYSCFGEN_Msk           (0x1UL << RCC_APB2ENR_SYSCFGEN_Pos)  /*!< 0x00004000 */
#define RCC_APB2ENR_SYSCFGEN               RCC_APB2ENR_SYSCFGEN_Msk
#define RCC_APB2ENR_TIM9EN_Pos             (16U)
#define RCC_APB2ENR_TIM9EN_Msk             (0x1UL << RCC_APB2ENR_TIM9EN_Pos)    /*!< 0x00010000 */
#define RCC_APB2ENR_TIM9EN                 RCC_APB2ENR_TIM9EN_Msk
#define RCC_APB2ENR_TIM10EN_Pos            (17U)
#define RCC_APB2ENR_TIM10EN_Msk            (0x1UL << RCC_APB2ENR_TIM10EN_Pos)   /*!< 0x00020000 */
#define RCC_APB2ENR_TIM10EN                RCC_APB2ENR_TIM10EN_Msk
#define RCC_APB2ENR_TIM11EN_Pos            (18U)
#define RCC_APB2ENR_TIM11EN_Msk            (0x1UL << RCC_APB2ENR_TIM11EN_Pos)   /*!< 0x00040000 */
#define RCC_APB2ENR_TIM11EN                RCC_APB2ENR_TIM11EN_Msk
#define RCC_APB2ENR_SPI5EN_Pos             (20U)
#define RCC_APB2ENR_SPI5EN_Msk             (0x1UL << RCC_APB2ENR_SPI5EN_Pos)    /*!< 0x00100000 */
#define RCC_APB2ENR_SPI5EN                 RCC_APB2ENR_SPI5EN_Msk

    

/********************  Bit definition for RCC_PLLCFGR register  ***************/
#define RCC_PLLCFGR_PLLM_Pos               (0U)                                
#define RCC_PLLCFGR_PLLM_Msk               (0x3FUL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x0000003F */
#define RCC_PLLCFGR_PLLM                   RCC_PLLCFGR_PLLM_Msk                
#define RCC_PLLCFGR_PLLM_0                 (0x01UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000001 */
#define RCC_PLLCFGR_PLLM_1                 (0x02UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000002 */
#define RCC_PLLCFGR_PLLM_2                 (0x04UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000004 */
#define RCC_PLLCFGR_PLLM_3                 (0x08UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000008 */
#define RCC_PLLCFGR_PLLM_4                 (0x10UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000010 */
#define RCC_PLLCFGR_PLLM_5                 (0x20UL << RCC_PLLCFGR_PLLM_Pos)     /*!< 0x00000020 */

#define RCC_PLLCFGR_PLLN_Pos               (6U)                                
#define RCC_PLLCFGR_PLLN_Msk               (0x1FFUL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00007FC0 */
#define RCC_PLLCFGR_PLLN                   RCC_PLLCFGR_PLLN_Msk                
#define RCC_PLLCFGR_PLLN_0                 (0x001UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000040 */
#define RCC_PLLCFGR_PLLN_1                 (0x002UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000080 */
#define RCC_PLLCFGR_PLLN_2                 (0x004UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000100 */
#define RCC_PLLCFGR_PLLN_3                 (0x008UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000200 */
#define RCC_PLLCFGR_PLLN_4                 (0x010UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000400 */
#define RCC_PLLCFGR_PLLN_5                 (0x020UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00000800 */
#define RCC_PLLCFGR_PLLN_6                 (0x040UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00001000 */
#define RCC_PLLCFGR_PLLN_7                 (0x080UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00002000 */
#define RCC_PLLCFGR_PLLN_8                 (0x100UL << RCC_PLLCFGR_PLLN_Pos)    /*!< 0x00004000 */

#define RCC_PLLCFGR_PLLP_Pos               (16U)                               
#define RCC_PLLCFGR_PLLP_Msk               (0x3UL << RCC_PLLCFGR_PLLP_Pos)      /*!< 0x00030000 */
#define RCC_PLLCFGR_PLLP                   RCC_PLLCFGR_PLLP_Msk                
#define RCC_PLLCFGR_PLLP_0                 (0x1UL << RCC_PLLCFGR_PLLP_Pos)      /*!< 0x00010000 */
#define RCC_PLLCFGR_PLLP_1                 (0x2UL << RCC_PLLCFGR_PLLP_Pos)      /*!< 0x00020000 */

#define RCC_PLLCFGR_PLLSRC_Pos             (22U)                               
#define RCC_PLLCFGR_PLLSRC_Msk             (0x1UL << RCC_PLLCFGR_PLLSRC_Pos)    /*!< 0x00400000 */
#define RCC_PLLCFGR_PLLSRC                 RCC_PLLCFGR_PLLSRC_Msk              
#define RCC_PLLCFGR_PLLSRC_HSE_Pos         (22U)                               
#define RCC_PLLCFGR_PLLSRC_HSE_Msk         (0x1UL << RCC_PLLCFGR_PLLSRC_HSE_Pos) /*!< 0x00400000 */
#define RCC_PLLCFGR_PLLSRC_HSE             RCC_PLLCFGR_PLLSRC_HSE_Msk          
#define RCC_PLLCFGR_PLLSRC_HSI             0x00000000U                         

#define RCC_PLLCFGR_PLLQ_Pos               (24U)                               
#define RCC_PLLCFGR_PLLQ_Msk               (0xFUL << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x0F000000 */
#define RCC_PLLCFGR_PLLQ                   RCC_PLLCFGR_PLLQ_Msk                
#define RCC_PLLCFGR_PLLQ_0                 (0x1UL << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x01000000 */
#define RCC_PLLCFGR_PLLQ_1                 (0x2UL << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x02000000 */
#define RCC_PLLCFGR_PLLQ_2                 (0x4UL << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x04000000 */
#define RCC_PLLCFGR_PLLQ_3                 (0x8UL << RCC_PLLCFGR_PLLQ_Pos)      /*!< 0x08000000 */


/********************  Bit definition for RCC_CFGR register  ******************/
/*!< SW configuration */
#define RCC_CFGR_SW_Pos                    (0U)                                
#define RCC_CFGR_SW_Msk                    (0x3UL << RCC_CFGR_SW_Pos)           /*!< 0x00000003 */
#define RCC_CFGR_SW                        RCC_CFGR_SW_Msk                     /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_0                      (0x1UL << RCC_CFGR_SW_Pos)           /*!< 0x00000001 */
#define RCC_CFGR_SW_1                      (0x2UL << RCC_CFGR_SW_Pos)           /*!< 0x00000002 */

#define RCC_CFGR_SW_HSI                    0x00000000U                         /*!< HSI selected as system clock */
#define RCC_CFGR_SW_HSE                    0x00000001U                         /*!< HSE selected as system clock */
#define RCC_CFGR_SW_PLL                    0x00000002U                         /*!< PLL selected as system clock */

/*!< SWS configuration */
#define RCC_CFGR_SWS_Pos                   (2U)                                
#define RCC_CFGR_SWS_Msk                   (0x3UL << RCC_CFGR_SWS_Pos)          /*!< 0x0000000C */
#define RCC_CFGR_SWS                       RCC_CFGR_SWS_Msk                    /*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_0                     (0x1UL << RCC_CFGR_SWS_Pos)          /*!< 0x00000004 */
#define RCC_CFGR_SWS_1                     (0x2UL << RCC_CFGR_SWS_Pos)          /*!< 0x00000008 */

#define RCC_CFGR_SWS_HSI                   0x00000000U                         /*!< HSI oscillator used as system clock        */
#define RCC_CFGR_SWS_HSE                   0x00000004U                         /*!< HSE oscillator used as system clock        */
#define RCC_CFGR_SWS_PLL                   0x00000008U                         /*!< PLL used as system clock                   */

/*!< HPRE configuration */
#define RCC_CFGR_HPRE_Pos                  (4U)                                
#define RCC_CFGR_HPRE_Msk                  (0xFUL << RCC_CFGR_HPRE_Pos)         /*!< 0x000000F0 */
#define RCC_CFGR_HPRE                      RCC_CFGR_HPRE_Msk                   /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_HPRE_0                    (0x1UL << RCC_CFGR_HPRE_Pos)         /*!< 0x00000010 */
#define RCC_CFGR_HPRE_1                    (0x2UL << RCC_CFGR_HPRE_Pos)         /*!< 0x00000020 */
#define RCC_CFGR_HPRE_2                    (0x4UL << RCC_CFGR_HPRE_Pos)         /*!< 0x00000040 */
#define RCC_CFGR_HPRE_3                    (0x8UL << RCC_CFGR_HPRE_Pos)         /*!< 0x00000080 */

#define RCC_CFGR_HPRE_DIV1                 0x00000000U                         /*!< SYSCLK not divided    */
#define RCC_CFGR_HPRE_DIV2                 0x00000080U                         /*!< SYSCLK divided by 2   */
#define RCC_CFGR_HPRE_DIV4                 0x00000090U                         /*!< SYSCLK divided by 4   */
#define RCC_CFGR_HPRE_DIV8                 0x000000A0U                         /*!< SYSCLK divided by 8   */
#define RCC_CFGR_HPRE_DIV16                0x000000B0U                         /*!< SYSCLK divided by 16  */
#define RCC_CFGR_HPRE_DIV64                0x000000C0U                         /*!< SYSCLK divided by 64  */
#define RCC_CFGR_HPRE_DIV128               0x000000D0U                         /*!< SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256               0x000000E0U                         /*!< SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512               0x000000F0U                         /*!< SYSCLK divided by 512 */

/*!< PPRE1 configuration */
#define RCC_CFGR_PPRE1_Pos                 (10U)                               
#define RCC_CFGR_PPRE1_Msk                 (0x7UL << RCC_CFGR_PPRE1_Pos)        /*!< 0x00001C00 */
#define RCC_CFGR_PPRE1                     RCC_CFGR_PPRE1_Msk                  /*!< PRE1[2:0] bits (APB1 prescaler) */
#define RCC_CFGR_PPRE1_0                   (0x1UL << RCC_CFGR_PPRE1_Pos)        /*!< 0x00000400 */
#define RCC_CFGR_PPRE1_1                   (0x2UL << RCC_CFGR_PPRE1_Pos)        /*!< 0x00000800 */
#define RCC_CFGR_PPRE1_2                   (0x4UL << RCC_CFGR_PPRE1_Pos)        /*!< 0x00001000 */

#define RCC_CFGR_PPRE1_DIV1                0x00000000U                         /*!< HCLK not divided   */
#define RCC_CFGR_PPRE1_DIV2                0x00001000U                         /*!< HCLK divided by 2  */
#define RCC_CFGR_PPRE1_DIV4                0x00001400U                         /*!< HCLK divided by 4  */
#define RCC_CFGR_PPRE1_DIV8                0x00001800U                         /*!< HCLK divided by 8  */
#define RCC_CFGR_PPRE1_DIV16               0x00001C00U                         /*!< HCLK divided by 16 */

/*!< PPRE2 configuration */
#define RCC_CFGR_PPRE2_Pos                 (13U)                               
#define RCC_CFGR_PPRE2_Msk                 (0x7UL << RCC_CFGR_PPRE2_Pos)        /*!< 0x0000E000 */
#define RCC_CFGR_PPRE2                     RCC_CFGR_PPRE2_Msk                  /*!< PRE2[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE2_0                   (0x1UL << RCC_CFGR_PPRE2_Pos)        /*!< 0x00002000 */
#define RCC_CFGR_PPRE2_1                   (0x2UL << RCC_CFGR_PPRE2_Pos)        /*!< 0x00004000 */
#define RCC_CFGR_PPRE2_2                   (0x4UL << RCC_CFGR_PPRE2_Pos)        /*!< 0x00008000 */

#define RCC_CFGR_PPRE2_DIV1                0x00000000U                         /*!< HCLK not divided   */
#define RCC_CFGR_PPRE2_DIV2                0x00008000U                         /*!< HCLK divided by 2  */
#define RCC_CFGR_PPRE2_DIV4                0x0000A000U                         /*!< HCLK divided by 4  */
#define RCC_CFGR_PPRE2_DIV8                0x0000C000U                         /*!< HCLK divided by 8  */
#define RCC_CFGR_PPRE2_DIV16               0x0000E000U                         /*!< HCLK divided by 16 */

/*!< RTCPRE configuration */
#define RCC_CFGR_RTCPRE_Pos                (16U)                               
#define RCC_CFGR_RTCPRE_Msk                (0x1FUL << RCC_CFGR_RTCPRE_Pos)      /*!< 0x001F0000 */
#define RCC_CFGR_RTCPRE                    RCC_CFGR_RTCPRE_Msk                 
#define RCC_CFGR_RTCPRE_0                  (0x01UL << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00010000 */
#define RCC_CFGR_RTCPRE_1                  (0x02UL << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00020000 */
#define RCC_CFGR_RTCPRE_2                  (0x04UL << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00040000 */
#define RCC_CFGR_RTCPRE_3                  (0x08UL << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00080000 */
#define RCC_CFGR_RTCPRE_4                  (0x10UL << RCC_CFGR_RTCPRE_Pos)      /*!< 0x00100000 */

/*!< MCO1 configuration */
#define RCC_CFGR_MCO1_Pos                  (21U)                               
#define RCC_CFGR_MCO1_Msk                  (0x3UL << RCC_CFGR_MCO1_Pos)         /*!< 0x00600000 */
#define RCC_CFGR_MCO1                      RCC_CFGR_MCO1_Msk                   
#define RCC_CFGR_MCO1_0                    (0x1UL << RCC_CFGR_MCO1_Pos)         /*!< 0x00200000 */
#define RCC_CFGR_MCO1_1                    (0x2UL << RCC_CFGR_MCO1_Pos)         /*!< 0x00400000 */

#define RCC_CFGR_I2SSRC_Pos                (23U)                               
#define RCC_CFGR_I2SSRC_Msk                (0x1UL << RCC_CFGR_I2SSRC_Pos)       /*!< 0x00800000 */
#define RCC_CFGR_I2SSRC                    RCC_CFGR_I2SSRC_Msk                 

#define RCC_CFGR_MCO1PRE_Pos               (24U)                               
#define RCC_CFGR_MCO1PRE_Msk               (0x7UL << RCC_CFGR_MCO1PRE_Pos)      /*!< 0x07000000 */
#define RCC_CFGR_MCO1PRE                   RCC_CFGR_MCO1PRE_Msk                
#define RCC_CFGR_MCO1PRE_0                 (0x1UL << RCC_CFGR_MCO1PRE_Pos)      /*!< 0x01000000 */
#define RCC_CFGR_MCO1PRE_1                 (0x2UL << RCC_CFGR_MCO1PRE_Pos)      /*!< 0x02000000 */
#define RCC_CFGR_MCO1PRE_2                 (0x4UL << RCC_CFGR_MCO1PRE_Pos)      /*!< 0x04000000 */

#define RCC_CFGR_MCO2PRE_Pos               (27U)                               
#define RCC_CFGR_MCO2PRE_Msk               (0x7UL << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x38000000 */
#define RCC_CFGR_MCO2PRE                   RCC_CFGR_MCO2PRE_Msk                
#define RCC_CFGR_MCO2PRE_0                 (0x1UL << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x08000000 */
#define RCC_CFGR_MCO2PRE_1                 (0x2UL << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x10000000 */
#define RCC_CFGR_MCO2PRE_2                 (0x4UL << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x20000000 */

#define RCC_CFGR_MCO2_Pos                  (30U)                               
#define RCC_CFGR_MCO2_Msk                  (0x3UL << RCC_CFGR_MCO2_Pos)         /*!< 0xC0000000 */
#define RCC_CFGR_MCO2                      RCC_CFGR_MCO2_Msk                   
#define RCC_CFGR_MCO2_0                    (0x1UL << RCC_CFGR_MCO2_Pos)         /*!< 0x40000000 */
#define RCC_CFGR_MCO2_1                    (0x2UL << RCC_CFGR_MCO2_Pos)         /*!< 0x80000000 */

        

/********************  Bit definition for RCC_BDCR register  ******************/
#define RCC_BDCR_LSEON_Pos                 (0U)                                
#define RCC_BDCR_LSEON_Msk                 (0x1UL << RCC_BDCR_LSEON_Pos)        /*!< 0x00000001 */
#define RCC_BDCR_LSEON                     RCC_BDCR_LSEON_Msk                  
#define RCC_BDCR_LSERDY_Pos                (1U)                                
#define RCC_BDCR_LSERDY_Msk                (0x1UL << RCC_BDCR_LSERDY_Pos)       /*!< 0x00000002 */
#define RCC_BDCR_LSERDY                    RCC_BDCR_LSERDY_Msk                 
#define RCC_BDCR_LSEBYP_Pos                (2U)                                
#define RCC_BDCR_LSEBYP_Msk                (0x1UL << RCC_BDCR_LSEBYP_Pos)       /*!< 0x00000004 */
#define RCC_BDCR_LSEBYP                    RCC_BDCR_LSEBYP_Msk                 
#define RCC_BDCR_LSEMOD_Pos                (3U)                                
#define RCC_BDCR_LSEMOD_Msk                (0x1UL << RCC_BDCR_LSEMOD_Pos)       /*!< 0x00000008 */
#define RCC_BDCR_LSEMOD                    RCC_BDCR_LSEMOD_Msk                 

#define RCC_BDCR_RTCSEL_Pos                (8U)                                
#define RCC_BDCR_RTCSEL_Msk                (0x3UL << RCC_BDCR_RTCSEL_Pos)       /*!< 0x00000300 */
#define RCC_BDCR_RTCSEL                    RCC_BDCR_RTCSEL_Msk                 
#define RCC_BDCR_RTCSEL_0                  (0x1UL << RCC_BDCR_RTCSEL_Pos)       /*!< 0x00000100 */
#define RCC_BDCR_RTCSEL_1                  (0x2UL << RCC_BDCR_RTCSEL_Pos)       /*!< 0x00000200 */

#define RCC_BDCR_RTCEN_Pos                 (15U)                               
#define RCC_BDCR_RTCEN_Msk                 (0x1UL << RCC_BDCR_RTCEN_Pos)        /*!< 0x00008000 */
#define RCC_BDCR_RTCEN                     RCC_BDCR_RTCEN_Msk                  
#define RCC_BDCR_BDRST_Pos                 (16U)                               
#define RCC_BDCR_BDRST_Msk                 (0x1UL << RCC_BDCR_BDRST_Pos)        /*!< 0x00010000 */
#define RCC_BDCR_BDRST                     RCC_BDCR_BDRST_Msk                  


/********************  Bit definition for RCC_CSR register  *******************/
#define RCC_CSR_LSION_Pos                  (0U)                                
#define RCC_CSR_LSION_Msk                  (0x1UL << RCC_CSR_LSION_Pos)         /*!< 0x00000001 */
#define RCC_CSR_LSION                      RCC_CSR_LSION_Msk                   
#define RCC_CSR_LSIRDY_Pos                 (1U)                                
#define RCC_CSR_LSIRDY_Msk                 (0x1UL << RCC_CSR_LSIRDY_Pos)        /*!< 0x00000002 */
#define RCC_CSR_LSIRDY                     RCC_CSR_LSIRDY_Msk                  
#define RCC_CSR_RMVF_Pos                   (24U)                               
#define RCC_CSR_RMVF_Msk                   (0x1UL << RCC_CSR_RMVF_Pos)          /*!< 0x01000000 */
#define RCC_CSR_RMVF                       RCC_CSR_RMVF_Msk                    
#define RCC_CSR_BORRSTF_Pos                (25U)                               
#define RCC_CSR_BORRSTF_Msk                (0x1UL << RCC_CSR_BORRSTF_Pos)       /*!< 0x02000000 */
#define RCC_CSR_BORRSTF                    RCC_CSR_BORRSTF_Msk                 
#define RCC_CSR_PINRSTF_Pos                (26U)
#define RCC_CSR_PINRSTF_Msk                (0x1UL << RCC_CSR_PINRSTF_Pos)       /*!< 0x04000000 */
#define RCC_CSR_PINRSTF                    RCC_CSR_PINRSTF_Msk
#define RCC_CSR_PORRSTF_Pos                (27U)                               
#define RCC_CSR_PORRSTF_Msk                (0x1UL << RCC_CSR_PORRSTF_Pos)       /*!< 0x08000000 */
#define RCC_CSR_PORRSTF                    RCC_CSR_PORRSTF_Msk                 
#define RCC_CSR_SFTRSTF_Pos                (28U)                               
#define RCC_CSR_SFTRSTF_Msk                (0x1UL << RCC_CSR_SFTRSTF_Pos)       /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF                    RCC_CSR_SFTRSTF_Msk                 
#define RCC_CSR_IWDGRSTF_Pos               (29U)
#define RCC_CSR_IWDGRSTF_Msk               (0x1UL << RCC_CSR_IWDGRSTF_Pos)      /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF                   RCC_CSR_IWDGRSTF_Msk
#define RCC_CSR_WWDGRSTF_Pos               (30U)                               
#define RCC_CSR_WWDGRSTF_Msk               (0x1UL << RCC_CSR_WWDGRSTF_Pos)      /*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF                   RCC_CSR_WWDGRSTF_Msk                
#define RCC_CSR_LPWRRSTF_Pos               (31U)                               
#define RCC_CSR_LPWRRSTF_Msk               (0x1UL << RCC_CSR_LPWRRSTF_Pos)      /*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF                   RCC_CSR_LPWRRSTF_Msk
/* Legacy defines */
#define RCC_CSR_PADRSTF                    RCC_CSR_PINRSTF
#define RCC_CSR_WDGRSTF                    RCC_CSR_IWDGRSTF






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




/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bits definition for FLASH_ACR register  *****************/
#define FLASH_ACR_LATENCY_Pos          (0U)                                    
#define FLASH_ACR_LATENCY_Msk          (0xFUL << FLASH_ACR_LATENCY_Pos)         /*!< 0x0000000F */
#define FLASH_ACR_LATENCY              FLASH_ACR_LATENCY_Msk                   
#define FLASH_ACR_LATENCY_0WS          0x00000000U                             
#define FLASH_ACR_LATENCY_1WS          0x00000001U                             
#define FLASH_ACR_LATENCY_2WS          0x00000002U                             
#define FLASH_ACR_LATENCY_3WS          0x00000003U                             
#define FLASH_ACR_LATENCY_4WS          0x00000004U                             
#define FLASH_ACR_LATENCY_5WS          0x00000005U                             
#define FLASH_ACR_LATENCY_6WS          0x00000006U                             
#define FLASH_ACR_LATENCY_7WS          0x00000007U                             

#define FLASH_ACR_PRFTEN_Pos           (8U)                                    
#define FLASH_ACR_PRFTEN_Msk           (0x1UL << FLASH_ACR_PRFTEN_Pos)          /*!< 0x00000100 */
#define FLASH_ACR_PRFTEN               FLASH_ACR_PRFTEN_Msk                    
#define FLASH_ACR_ICEN_Pos             (9U)                                    
#define FLASH_ACR_ICEN_Msk             (0x1UL << FLASH_ACR_ICEN_Pos)            /*!< 0x00000200 */
#define FLASH_ACR_ICEN                 FLASH_ACR_ICEN_Msk                      
#define FLASH_ACR_DCEN_Pos             (10U)                                   
#define FLASH_ACR_DCEN_Msk             (0x1UL << FLASH_ACR_DCEN_Pos)            /*!< 0x00000400 */
#define FLASH_ACR_DCEN                 FLASH_ACR_DCEN_Msk                      
#define FLASH_ACR_ICRST_Pos            (11U)                                   
#define FLASH_ACR_ICRST_Msk            (0x1UL << FLASH_ACR_ICRST_Pos)           /*!< 0x00000800 */
#define FLASH_ACR_ICRST                FLASH_ACR_ICRST_Msk                     
#define FLASH_ACR_DCRST_Pos            (12U)                                   
#define FLASH_ACR_DCRST_Msk            (0x1UL << FLASH_ACR_DCRST_Pos)           /*!< 0x00001000 */
#define FLASH_ACR_DCRST                FLASH_ACR_DCRST_Msk                     
#define FLASH_ACR_BYTE0_ADDRESS_Pos    (10U)                                   
#define FLASH_ACR_BYTE0_ADDRESS_Msk    (0x10008FUL << FLASH_ACR_BYTE0_ADDRESS_Pos) /*!< 0x40023C00 */
#define FLASH_ACR_BYTE0_ADDRESS        FLASH_ACR_BYTE0_ADDRESS_Msk             
#define FLASH_ACR_BYTE2_ADDRESS_Pos    (0U)                                    
#define FLASH_ACR_BYTE2_ADDRESS_Msk    (0x40023C03UL << FLASH_ACR_BYTE2_ADDRESS_Pos) /*!< 0x40023C03 */
#define FLASH_ACR_BYTE2_ADDRESS        FLASH_ACR_BYTE2_ADDRESS_Msk             




/******************************************************************************/
/*                                                                            */
/*                             Power Control                                  */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for PWR_CR register  ********************/
#define PWR_CR_LPDS_Pos        (0U)                                            
#define PWR_CR_LPDS_Msk        (0x1UL << PWR_CR_LPDS_Pos)                       /*!< 0x00000001 */
#define PWR_CR_LPDS            PWR_CR_LPDS_Msk                                 /*!< Low-Power Deepsleep                 */
#define PWR_CR_PDDS_Pos        (1U)                                            
#define PWR_CR_PDDS_Msk        (0x1UL << PWR_CR_PDDS_Pos)                       /*!< 0x00000002 */
#define PWR_CR_PDDS            PWR_CR_PDDS_Msk                                 /*!< Power Down Deepsleep                */
#define PWR_CR_CWUF_Pos        (2U)                                            
#define PWR_CR_CWUF_Msk        (0x1UL << PWR_CR_CWUF_Pos)                       /*!< 0x00000004 */
#define PWR_CR_CWUF            PWR_CR_CWUF_Msk                                 /*!< Clear Wakeup Flag                   */
#define PWR_CR_CSBF_Pos        (3U)                                            
#define PWR_CR_CSBF_Msk        (0x1UL << PWR_CR_CSBF_Pos)                       /*!< 0x00000008 */
#define PWR_CR_CSBF            PWR_CR_CSBF_Msk                                 /*!< Clear Standby Flag                  */
#define PWR_CR_PVDE_Pos        (4U)                                            
#define PWR_CR_PVDE_Msk        (0x1UL << PWR_CR_PVDE_Pos)                       /*!< 0x00000010 */
#define PWR_CR_PVDE            PWR_CR_PVDE_Msk                                 /*!< Power Voltage Detector Enable       */

#define PWR_CR_PLS_Pos         (5U)                                            
#define PWR_CR_PLS_Msk         (0x7UL << PWR_CR_PLS_Pos)                        /*!< 0x000000E0 */
#define PWR_CR_PLS             PWR_CR_PLS_Msk                                  /*!< PLS[2:0] bits (PVD Level Selection) */
#define PWR_CR_PLS_0           (0x1UL << PWR_CR_PLS_Pos)                        /*!< 0x00000020 */
#define PWR_CR_PLS_1           (0x2UL << PWR_CR_PLS_Pos)                        /*!< 0x00000040 */
#define PWR_CR_PLS_2           (0x4UL << PWR_CR_PLS_Pos)                        /*!< 0x00000080 */

/*!< PVD level configuration */
#define PWR_CR_PLS_LEV0        0x00000000U                                     /*!< PVD level 0 */
#define PWR_CR_PLS_LEV1        0x00000020U                                     /*!< PVD level 1 */
#define PWR_CR_PLS_LEV2        0x00000040U                                     /*!< PVD level 2 */
#define PWR_CR_PLS_LEV3        0x00000060U                                     /*!< PVD level 3 */
#define PWR_CR_PLS_LEV4        0x00000080U                                     /*!< PVD level 4 */
#define PWR_CR_PLS_LEV5        0x000000A0U                                     /*!< PVD level 5 */
#define PWR_CR_PLS_LEV6        0x000000C0U                                     /*!< PVD level 6 */
#define PWR_CR_PLS_LEV7        0x000000E0U                                     /*!< PVD level 7 */
#define PWR_CR_DBP_Pos         (8U)                                            
#define PWR_CR_DBP_Msk         (0x1UL << PWR_CR_DBP_Pos)                        /*!< 0x00000100 */
#define PWR_CR_DBP             PWR_CR_DBP_Msk                                  /*!< Disable Backup Domain write protection                     */
#define PWR_CR_FPDS_Pos        (9U)                                            
#define PWR_CR_FPDS_Msk        (0x1UL << PWR_CR_FPDS_Pos)                       /*!< 0x00000200 */
#define PWR_CR_FPDS            PWR_CR_FPDS_Msk                                 /*!< Flash power down in Stop mode                              */
#define PWR_CR_LPLVDS_Pos      (10U)                                           
#define PWR_CR_LPLVDS_Msk      (0x1UL << PWR_CR_LPLVDS_Pos)                     /*!< 0x00000400 */
#define PWR_CR_LPLVDS          PWR_CR_LPLVDS_Msk                               /*!< Low Power Regulator Low Voltage in Deep Sleep mode         */
#define PWR_CR_MRLVDS_Pos      (11U)                                           
#define PWR_CR_MRLVDS_Msk      (0x1UL << PWR_CR_MRLVDS_Pos)                     /*!< 0x00000800 */
#define PWR_CR_MRLVDS          PWR_CR_MRLVDS_Msk                               /*!< Main Regulator Low Voltage in Deep Sleep mode              */
#define PWR_CR_ADCDC1_Pos      (13U)                                           
#define PWR_CR_ADCDC1_Msk      (0x1UL << PWR_CR_ADCDC1_Pos)                     /*!< 0x00002000 */
#define PWR_CR_ADCDC1          PWR_CR_ADCDC1_Msk                               /*!< Refer to AN4073 on how to use this bit                     */ 
#define PWR_CR_VOS_Pos         (14U)                                           
#define PWR_CR_VOS_Msk         (0x3UL << PWR_CR_VOS_Pos)                        /*!< 0x0000C000 */
#define PWR_CR_VOS             PWR_CR_VOS_Msk                                  /*!< VOS[1:0] bits (Regulator voltage scaling output selection) */
#define PWR_CR_VOS_0           0x00004000U                                     /*!< Bit 0 */
#define PWR_CR_VOS_1           0x00008000U                                     /*!< Bit 1 */
#define PWR_CR_FMSSR_Pos       (20U)                                           
#define PWR_CR_FMSSR_Msk       (0x1UL << PWR_CR_FMSSR_Pos)                      /*!< 0x00100000 */
#define PWR_CR_FMSSR           PWR_CR_FMSSR_Msk                                /*!< Flash Memory Sleep System Run        */
#define PWR_CR_FISSR_Pos       (21U)                                           
#define PWR_CR_FISSR_Msk       (0x1UL << PWR_CR_FISSR_Pos)                      /*!< 0x00200000 */
#define PWR_CR_FISSR           PWR_CR_FISSR_Msk                                /*!< Flash Interface Stop while System Run */

/* Legacy define */
#define  PWR_CR_PMODE                        PWR_CR_VOS



/******************************************************************************/
/*                                                                            */
/*                           Real-Time Clock (RTC)                            */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for RTC_TR register  *******************/
#define RTC_TR_PM_Pos                 (22U)
#define RTC_TR_PM_Msk                 (0x1UL << RTC_TR_PM_Pos)                  /*!< 0x00400000 */
#define RTC_TR_PM                     RTC_TR_PM_Msk
#define RTC_TR_HT_Pos                 (20U)
#define RTC_TR_HT_Msk                 (0x3UL << RTC_TR_HT_Pos)                  /*!< 0x00300000 */
#define RTC_TR_HT                     RTC_TR_HT_Msk
#define RTC_TR_HT_0                   (0x1UL << RTC_TR_HT_Pos)                  /*!< 0x00100000 */
#define RTC_TR_HT_1                   (0x2UL << RTC_TR_HT_Pos)                  /*!< 0x00200000 */
#define RTC_TR_HU_Pos                 (16U)
#define RTC_TR_HU_Msk                 (0xFUL << RTC_TR_HU_Pos)                  /*!< 0x000F0000 */
#define RTC_TR_HU                     RTC_TR_HU_Msk
#define RTC_TR_HU_0                   (0x1UL << RTC_TR_HU_Pos)                  /*!< 0x00010000 */
#define RTC_TR_HU_1                   (0x2UL << RTC_TR_HU_Pos)                  /*!< 0x00020000 */
#define RTC_TR_HU_2                   (0x4UL << RTC_TR_HU_Pos)                  /*!< 0x00040000 */
#define RTC_TR_HU_3                   (0x8UL << RTC_TR_HU_Pos)                  /*!< 0x00080000 */
#define RTC_TR_MNT_Pos                (12U)
#define RTC_TR_MNT_Msk                (0x7UL << RTC_TR_MNT_Pos)                 /*!< 0x00007000 */
#define RTC_TR_MNT                    RTC_TR_MNT_Msk
#define RTC_TR_MNT_0                  (0x1UL << RTC_TR_MNT_Pos)                 /*!< 0x00001000 */
#define RTC_TR_MNT_1                  (0x2UL << RTC_TR_MNT_Pos)                 /*!< 0x00002000 */
#define RTC_TR_MNT_2                  (0x4UL << RTC_TR_MNT_Pos)                 /*!< 0x00004000 */
#define RTC_TR_MNU_Pos                (8U)
#define RTC_TR_MNU_Msk                (0xFUL << RTC_TR_MNU_Pos)                 /*!< 0x00000F00 */
#define RTC_TR_MNU                    RTC_TR_MNU_Msk
#define RTC_TR_MNU_0                  (0x1UL << RTC_TR_MNU_Pos)                 /*!< 0x00000100 */
#define RTC_TR_MNU_1                  (0x2UL << RTC_TR_MNU_Pos)                 /*!< 0x00000200 */
#define RTC_TR_MNU_2                  (0x4UL << RTC_TR_MNU_Pos)                 /*!< 0x00000400 */
#define RTC_TR_MNU_3                  (0x8UL << RTC_TR_MNU_Pos)                 /*!< 0x00000800 */
#define RTC_TR_ST_Pos                 (4U)
#define RTC_TR_ST_Msk                 (0x7UL << RTC_TR_ST_Pos)                  /*!< 0x00000070 */
#define RTC_TR_ST                     RTC_TR_ST_Msk
#define RTC_TR_ST_0                   (0x1UL << RTC_TR_ST_Pos)                  /*!< 0x00000010 */
#define RTC_TR_ST_1                   (0x2UL << RTC_TR_ST_Pos)                  /*!< 0x00000020 */
#define RTC_TR_ST_2                   (0x4UL << RTC_TR_ST_Pos)                  /*!< 0x00000040 */
#define RTC_TR_SU_Pos                 (0U)
#define RTC_TR_SU_Msk                 (0xFUL << RTC_TR_SU_Pos)                  /*!< 0x0000000F */
#define RTC_TR_SU                     RTC_TR_SU_Msk
#define RTC_TR_SU_0                   (0x1UL << RTC_TR_SU_Pos)                  /*!< 0x00000001 */
#define RTC_TR_SU_1                   (0x2UL << RTC_TR_SU_Pos)                  /*!< 0x00000002 */
#define RTC_TR_SU_2                   (0x4UL << RTC_TR_SU_Pos)                  /*!< 0x00000004 */
#define RTC_TR_SU_3                   (0x8UL << RTC_TR_SU_Pos)                  /*!< 0x00000008 */

/********************  Bits definition for RTC_DR register  *******************/
#define RTC_DR_YT_Pos                 (20U)
#define RTC_DR_YT_Msk                 (0xFUL << RTC_DR_YT_Pos)                  /*!< 0x00F00000 */
#define RTC_DR_YT                     RTC_DR_YT_Msk
#define RTC_DR_YT_0                   (0x1UL << RTC_DR_YT_Pos)                  /*!< 0x00100000 */
#define RTC_DR_YT_1                   (0x2UL << RTC_DR_YT_Pos)                  /*!< 0x00200000 */
#define RTC_DR_YT_2                   (0x4UL << RTC_DR_YT_Pos)                  /*!< 0x00400000 */
#define RTC_DR_YT_3                   (0x8UL << RTC_DR_YT_Pos)                  /*!< 0x00800000 */
#define RTC_DR_YU_Pos                 (16U)
#define RTC_DR_YU_Msk                 (0xFUL << RTC_DR_YU_Pos)                  /*!< 0x000F0000 */
#define RTC_DR_YU                     RTC_DR_YU_Msk
#define RTC_DR_YU_0                   (0x1UL << RTC_DR_YU_Pos)                  /*!< 0x00010000 */
#define RTC_DR_YU_1                   (0x2UL << RTC_DR_YU_Pos)                  /*!< 0x00020000 */
#define RTC_DR_YU_2                   (0x4UL << RTC_DR_YU_Pos)                  /*!< 0x00040000 */
#define RTC_DR_YU_3                   (0x8UL << RTC_DR_YU_Pos)                  /*!< 0x00080000 */
#define RTC_DR_WDU_Pos                (13U)
#define RTC_DR_WDU_Msk                (0x7UL << RTC_DR_WDU_Pos)                 /*!< 0x0000E000 */
#define RTC_DR_WDU                    RTC_DR_WDU_Msk
#define RTC_DR_WDU_0                  (0x1UL << RTC_DR_WDU_Pos)                 /*!< 0x00002000 */
#define RTC_DR_WDU_1                  (0x2UL << RTC_DR_WDU_Pos)                 /*!< 0x00004000 */
#define RTC_DR_WDU_2                  (0x4UL << RTC_DR_WDU_Pos)                 /*!< 0x00008000 */
#define RTC_DR_MT_Pos                 (12U)
#define RTC_DR_MT_Msk                 (0x1UL << RTC_DR_MT_Pos)                  /*!< 0x00001000 */
#define RTC_DR_MT                     RTC_DR_MT_Msk
#define RTC_DR_MU_Pos                 (8U)
#define RTC_DR_MU_Msk                 (0xFUL << RTC_DR_MU_Pos)                  /*!< 0x00000F00 */
#define RTC_DR_MU                     RTC_DR_MU_Msk
#define RTC_DR_MU_0                   (0x1UL << RTC_DR_MU_Pos)                  /*!< 0x00000100 */
#define RTC_DR_MU_1                   (0x2UL << RTC_DR_MU_Pos)                  /*!< 0x00000200 */
#define RTC_DR_MU_2                   (0x4UL << RTC_DR_MU_Pos)                  /*!< 0x00000400 */
#define RTC_DR_MU_3                   (0x8UL << RTC_DR_MU_Pos)                  /*!< 0x00000800 */
#define RTC_DR_DT_Pos                 (4U)
#define RTC_DR_DT_Msk                 (0x3UL << RTC_DR_DT_Pos)                  /*!< 0x00000030 */
#define RTC_DR_DT                     RTC_DR_DT_Msk
#define RTC_DR_DT_0                   (0x1UL << RTC_DR_DT_Pos)                  /*!< 0x00000010 */
#define RTC_DR_DT_1                   (0x2UL << RTC_DR_DT_Pos)                  /*!< 0x00000020 */
#define RTC_DR_DU_Pos                 (0U)
#define RTC_DR_DU_Msk                 (0xFUL << RTC_DR_DU_Pos)                  /*!< 0x0000000F */
#define RTC_DR_DU                     RTC_DR_DU_Msk
#define RTC_DR_DU_0                   (0x1UL << RTC_DR_DU_Pos)                  /*!< 0x00000001 */
#define RTC_DR_DU_1                   (0x2UL << RTC_DR_DU_Pos)                  /*!< 0x00000002 */
#define RTC_DR_DU_2                   (0x4UL << RTC_DR_DU_Pos)                  /*!< 0x00000004 */
#define RTC_DR_DU_3                   (0x8UL << RTC_DR_DU_Pos)                  /*!< 0x00000008 */

/********************  Bits definition for RTC_CR register  *******************/
#define RTC_CR_COE_Pos                (23U)
#define RTC_CR_COE_Msk                (0x1UL << RTC_CR_COE_Pos)                 /*!< 0x00800000 */
#define RTC_CR_COE                    RTC_CR_COE_Msk
#define RTC_CR_OSEL_Pos               (21U)
#define RTC_CR_OSEL_Msk               (0x3UL << RTC_CR_OSEL_Pos)                /*!< 0x00600000 */
#define RTC_CR_OSEL                   RTC_CR_OSEL_Msk
#define RTC_CR_OSEL_0                 (0x1UL << RTC_CR_OSEL_Pos)                /*!< 0x00200000 */
#define RTC_CR_OSEL_1                 (0x2UL << RTC_CR_OSEL_Pos)                /*!< 0x00400000 */
#define RTC_CR_POL_Pos                (20U)
#define RTC_CR_POL_Msk                (0x1UL << RTC_CR_POL_Pos)                 /*!< 0x00100000 */
#define RTC_CR_POL                    RTC_CR_POL_Msk
#define RTC_CR_COSEL_Pos              (19U)
#define RTC_CR_COSEL_Msk              (0x1UL << RTC_CR_COSEL_Pos)               /*!< 0x00080000 */
#define RTC_CR_COSEL                  RTC_CR_COSEL_Msk
#define RTC_CR_BKP_Pos                 (18U)
#define RTC_CR_BKP_Msk                 (0x1UL << RTC_CR_BKP_Pos)                /*!< 0x00040000 */
#define RTC_CR_BKP                     RTC_CR_BKP_Msk
#define RTC_CR_SUB1H_Pos              (17U)
#define RTC_CR_SUB1H_Msk              (0x1UL << RTC_CR_SUB1H_Pos)               /*!< 0x00020000 */
#define RTC_CR_SUB1H                  RTC_CR_SUB1H_Msk
#define RTC_CR_ADD1H_Pos              (16U)
#define RTC_CR_ADD1H_Msk              (0x1UL << RTC_CR_ADD1H_Pos)               /*!< 0x00010000 */
#define RTC_CR_ADD1H                  RTC_CR_ADD1H_Msk
#define RTC_CR_TSIE_Pos               (15U)
#define RTC_CR_TSIE_Msk               (0x1UL << RTC_CR_TSIE_Pos)                /*!< 0x00008000 */
#define RTC_CR_TSIE                   RTC_CR_TSIE_Msk
#define RTC_CR_WUTIE_Pos              (14U)
#define RTC_CR_WUTIE_Msk              (0x1UL << RTC_CR_WUTIE_Pos)               /*!< 0x00004000 */
#define RTC_CR_WUTIE                  RTC_CR_WUTIE_Msk
#define RTC_CR_ALRBIE_Pos             (13U)
#define RTC_CR_ALRBIE_Msk             (0x1UL << RTC_CR_ALRBIE_Pos)              /*!< 0x00002000 */
#define RTC_CR_ALRBIE                 RTC_CR_ALRBIE_Msk
#define RTC_CR_ALRAIE_Pos             (12U)
#define RTC_CR_ALRAIE_Msk             (0x1UL << RTC_CR_ALRAIE_Pos)              /*!< 0x00001000 */
#define RTC_CR_ALRAIE                 RTC_CR_ALRAIE_Msk
#define RTC_CR_TSE_Pos                (11U)
#define RTC_CR_TSE_Msk                (0x1UL << RTC_CR_TSE_Pos)                 /*!< 0x00000800 */
#define RTC_CR_TSE                    RTC_CR_TSE_Msk
#define RTC_CR_WUTE_Pos               (10U)
#define RTC_CR_WUTE_Msk               (0x1UL << RTC_CR_WUTE_Pos)                /*!< 0x00000400 */
#define RTC_CR_WUTE                   RTC_CR_WUTE_Msk
#define RTC_CR_ALRBE_Pos              (9U)
#define RTC_CR_ALRBE_Msk              (0x1UL << RTC_CR_ALRBE_Pos)               /*!< 0x00000200 */
#define RTC_CR_ALRBE                  RTC_CR_ALRBE_Msk
#define RTC_CR_ALRAE_Pos              (8U)
#define RTC_CR_ALRAE_Msk              (0x1UL << RTC_CR_ALRAE_Pos)               /*!< 0x00000100 */
#define RTC_CR_ALRAE                  RTC_CR_ALRAE_Msk
#define RTC_CR_DCE_Pos                (7U)
#define RTC_CR_DCE_Msk                (0x1UL << RTC_CR_DCE_Pos)                 /*!< 0x00000080 */
#define RTC_CR_DCE                    RTC_CR_DCE_Msk
#define RTC_CR_FMT_Pos                (6U)
#define RTC_CR_FMT_Msk                (0x1UL << RTC_CR_FMT_Pos)                 /*!< 0x00000040 */
#define RTC_CR_FMT                    RTC_CR_FMT_Msk
#define RTC_CR_BYPSHAD_Pos            (5U)
#define RTC_CR_BYPSHAD_Msk            (0x1UL << RTC_CR_BYPSHAD_Pos)             /*!< 0x00000020 */
#define RTC_CR_BYPSHAD                RTC_CR_BYPSHAD_Msk
#define RTC_CR_REFCKON_Pos            (4U)
#define RTC_CR_REFCKON_Msk            (0x1UL << RTC_CR_REFCKON_Pos)             /*!< 0x00000010 */
#define RTC_CR_REFCKON                RTC_CR_REFCKON_Msk
#define RTC_CR_TSEDGE_Pos             (3U)
#define RTC_CR_TSEDGE_Msk             (0x1UL << RTC_CR_TSEDGE_Pos)              /*!< 0x00000008 */
#define RTC_CR_TSEDGE                 RTC_CR_TSEDGE_Msk
#define RTC_CR_WUCKSEL_Pos            (0U)
#define RTC_CR_WUCKSEL_Msk            (0x7UL << RTC_CR_WUCKSEL_Pos)             /*!< 0x00000007 */
#define RTC_CR_WUCKSEL                RTC_CR_WUCKSEL_Msk
#define RTC_CR_WUCKSEL_0              (0x1UL << RTC_CR_WUCKSEL_Pos)             /*!< 0x00000001 */
#define RTC_CR_WUCKSEL_1              (0x2UL << RTC_CR_WUCKSEL_Pos)             /*!< 0x00000002 */
#define RTC_CR_WUCKSEL_2              (0x4UL << RTC_CR_WUCKSEL_Pos)             /*!< 0x00000004 */

/* Legacy defines */
#define RTC_CR_BCK                     RTC_CR_BKP

/********************  Bits definition for RTC_ISR register  ******************/
#define RTC_ISR_RECALPF_Pos           (16U)
#define RTC_ISR_RECALPF_Msk           (0x1UL << RTC_ISR_RECALPF_Pos)            /*!< 0x00010000 */
#define RTC_ISR_RECALPF               RTC_ISR_RECALPF_Msk
#define RTC_ISR_TAMP1F_Pos            (13U)
#define RTC_ISR_TAMP1F_Msk            (0x1UL << RTC_ISR_TAMP1F_Pos)             /*!< 0x00002000 */
#define RTC_ISR_TAMP1F                RTC_ISR_TAMP1F_Msk
#define RTC_ISR_TAMP2F_Pos            (14U)
#define RTC_ISR_TAMP2F_Msk            (0x1UL << RTC_ISR_TAMP2F_Pos)             /*!< 0x00004000 */
#define RTC_ISR_TAMP2F                RTC_ISR_TAMP2F_Msk
#define RTC_ISR_TSOVF_Pos             (12U)
#define RTC_ISR_TSOVF_Msk             (0x1UL << RTC_ISR_TSOVF_Pos)              /*!< 0x00001000 */
#define RTC_ISR_TSOVF                 RTC_ISR_TSOVF_Msk
#define RTC_ISR_TSF_Pos               (11U)
#define RTC_ISR_TSF_Msk               (0x1UL << RTC_ISR_TSF_Pos)                /*!< 0x00000800 */
#define RTC_ISR_TSF                   RTC_ISR_TSF_Msk
#define RTC_ISR_WUTF_Pos              (10U)
#define RTC_ISR_WUTF_Msk              (0x1UL << RTC_ISR_WUTF_Pos)               /*!< 0x00000400 */
#define RTC_ISR_WUTF                  RTC_ISR_WUTF_Msk
#define RTC_ISR_ALRBF_Pos             (9U)
#define RTC_ISR_ALRBF_Msk             (0x1UL << RTC_ISR_ALRBF_Pos)              /*!< 0x00000200 */
#define RTC_ISR_ALRBF                 RTC_ISR_ALRBF_Msk
#define RTC_ISR_ALRAF_Pos             (8U)
#define RTC_ISR_ALRAF_Msk             (0x1UL << RTC_ISR_ALRAF_Pos)              /*!< 0x00000100 */
#define RTC_ISR_ALRAF                 RTC_ISR_ALRAF_Msk
#define RTC_ISR_INIT_Pos              (7U)
#define RTC_ISR_INIT_Msk              (0x1UL << RTC_ISR_INIT_Pos)               /*!< 0x00000080 */
#define RTC_ISR_INIT                  RTC_ISR_INIT_Msk
#define RTC_ISR_INITF_Pos             (6U)
#define RTC_ISR_INITF_Msk             (0x1UL << RTC_ISR_INITF_Pos)              /*!< 0x00000040 */
#define RTC_ISR_INITF                 RTC_ISR_INITF_Msk
#define RTC_ISR_RSF_Pos               (5U)
#define RTC_ISR_RSF_Msk               (0x1UL << RTC_ISR_RSF_Pos)                /*!< 0x00000020 */
#define RTC_ISR_RSF                   RTC_ISR_RSF_Msk
#define RTC_ISR_INITS_Pos             (4U)
#define RTC_ISR_INITS_Msk             (0x1UL << RTC_ISR_INITS_Pos)              /*!< 0x00000010 */
#define RTC_ISR_INITS                 RTC_ISR_INITS_Msk
#define RTC_ISR_SHPF_Pos              (3U)
#define RTC_ISR_SHPF_Msk              (0x1UL << RTC_ISR_SHPF_Pos)               /*!< 0x00000008 */
#define RTC_ISR_SHPF                  RTC_ISR_SHPF_Msk
#define RTC_ISR_WUTWF_Pos             (2U)
#define RTC_ISR_WUTWF_Msk             (0x1UL << RTC_ISR_WUTWF_Pos)              /*!< 0x00000004 */
#define RTC_ISR_WUTWF                 RTC_ISR_WUTWF_Msk
#define RTC_ISR_ALRBWF_Pos            (1U)
#define RTC_ISR_ALRBWF_Msk            (0x1UL << RTC_ISR_ALRBWF_Pos)             /*!< 0x00000002 */
#define RTC_ISR_ALRBWF                RTC_ISR_ALRBWF_Msk
#define RTC_ISR_ALRAWF_Pos            (0U)
#define RTC_ISR_ALRAWF_Msk            (0x1UL << RTC_ISR_ALRAWF_Pos)             /*!< 0x00000001 */
#define RTC_ISR_ALRAWF                RTC_ISR_ALRAWF_Msk

/********************  Bits definition for RTC_PRER register  *****************/
#define RTC_PRER_PREDIV_A_Pos         (16U)
#define RTC_PRER_PREDIV_A_Msk         (0x7FUL << RTC_PRER_PREDIV_A_Pos)         /*!< 0x007F0000 */
#define RTC_PRER_PREDIV_A             RTC_PRER_PREDIV_A_Msk
#define RTC_PRER_PREDIV_S_Pos         (0U)
#define RTC_PRER_PREDIV_S_Msk         (0x7FFFUL << RTC_PRER_PREDIV_S_Pos)       /*!< 0x00007FFF */
#define RTC_PRER_PREDIV_S             RTC_PRER_PREDIV_S_Msk

/********************  Bits definition for RTC_WUTR register  *****************/
#define RTC_WUTR_WUT_Pos              (0U)
#define RTC_WUTR_WUT_Msk              (0xFFFFUL << RTC_WUTR_WUT_Pos)            /*!< 0x0000FFFF */
#define RTC_WUTR_WUT                  RTC_WUTR_WUT_Msk

/********************  Bits definition for RTC_CALIBR register  ***************/
#define RTC_CALIBR_DCS_Pos            (7U)
#define RTC_CALIBR_DCS_Msk            (0x1UL << RTC_CALIBR_DCS_Pos)             /*!< 0x00000080 */
#define RTC_CALIBR_DCS                RTC_CALIBR_DCS_Msk
#define RTC_CALIBR_DC_Pos             (0U)
#define RTC_CALIBR_DC_Msk             (0x1FUL << RTC_CALIBR_DC_Pos)             /*!< 0x0000001F */
#define RTC_CALIBR_DC                 RTC_CALIBR_DC_Msk

/********************  Bits definition for RTC_ALRMAR register  ***************/
#define RTC_ALRMAR_MSK4_Pos           (31U)
#define RTC_ALRMAR_MSK4_Msk           (0x1UL << RTC_ALRMAR_MSK4_Pos)            /*!< 0x80000000 */
#define RTC_ALRMAR_MSK4               RTC_ALRMAR_MSK4_Msk
#define RTC_ALRMAR_WDSEL_Pos          (30U)
#define RTC_ALRMAR_WDSEL_Msk          (0x1UL << RTC_ALRMAR_WDSEL_Pos)           /*!< 0x40000000 */
#define RTC_ALRMAR_WDSEL              RTC_ALRMAR_WDSEL_Msk
#define RTC_ALRMAR_DT_Pos             (28U)
#define RTC_ALRMAR_DT_Msk             (0x3UL << RTC_ALRMAR_DT_Pos)              /*!< 0x30000000 */
#define RTC_ALRMAR_DT                 RTC_ALRMAR_DT_Msk
#define RTC_ALRMAR_DT_0               (0x1UL << RTC_ALRMAR_DT_Pos)              /*!< 0x10000000 */
#define RTC_ALRMAR_DT_1               (0x2UL << RTC_ALRMAR_DT_Pos)              /*!< 0x20000000 */
#define RTC_ALRMAR_DU_Pos             (24U)
#define RTC_ALRMAR_DU_Msk             (0xFUL << RTC_ALRMAR_DU_Pos)              /*!< 0x0F000000 */
#define RTC_ALRMAR_DU                 RTC_ALRMAR_DU_Msk
#define RTC_ALRMAR_DU_0               (0x1UL << RTC_ALRMAR_DU_Pos)              /*!< 0x01000000 */
#define RTC_ALRMAR_DU_1               (0x2UL << RTC_ALRMAR_DU_Pos)              /*!< 0x02000000 */
#define RTC_ALRMAR_DU_2               (0x4UL << RTC_ALRMAR_DU_Pos)              /*!< 0x04000000 */
#define RTC_ALRMAR_DU_3               (0x8UL << RTC_ALRMAR_DU_Pos)              /*!< 0x08000000 */
#define RTC_ALRMAR_MSK3_Pos           (23U)
#define RTC_ALRMAR_MSK3_Msk           (0x1UL << RTC_ALRMAR_MSK3_Pos)            /*!< 0x00800000 */
#define RTC_ALRMAR_MSK3               RTC_ALRMAR_MSK3_Msk
#define RTC_ALRMAR_PM_Pos             (22U)
#define RTC_ALRMAR_PM_Msk             (0x1UL << RTC_ALRMAR_PM_Pos)              /*!< 0x00400000 */
#define RTC_ALRMAR_PM                 RTC_ALRMAR_PM_Msk
#define RTC_ALRMAR_HT_Pos             (20U)
#define RTC_ALRMAR_HT_Msk             (0x3UL << RTC_ALRMAR_HT_Pos)              /*!< 0x00300000 */
#define RTC_ALRMAR_HT                 RTC_ALRMAR_HT_Msk
#define RTC_ALRMAR_HT_0               (0x1UL << RTC_ALRMAR_HT_Pos)              /*!< 0x00100000 */
#define RTC_ALRMAR_HT_1               (0x2UL << RTC_ALRMAR_HT_Pos)              /*!< 0x00200000 */
#define RTC_ALRMAR_HU_Pos             (16U)
#define RTC_ALRMAR_HU_Msk             (0xFUL << RTC_ALRMAR_HU_Pos)              /*!< 0x000F0000 */
#define RTC_ALRMAR_HU                 RTC_ALRMAR_HU_Msk
#define RTC_ALRMAR_HU_0               (0x1UL << RTC_ALRMAR_HU_Pos)              /*!< 0x00010000 */
#define RTC_ALRMAR_HU_1               (0x2UL << RTC_ALRMAR_HU_Pos)              /*!< 0x00020000 */
#define RTC_ALRMAR_HU_2               (0x4UL << RTC_ALRMAR_HU_Pos)              /*!< 0x00040000 */
#define RTC_ALRMAR_HU_3               (0x8UL << RTC_ALRMAR_HU_Pos)              /*!< 0x00080000 */
#define RTC_ALRMAR_MSK2_Pos           (15U)
#define RTC_ALRMAR_MSK2_Msk           (0x1UL << RTC_ALRMAR_MSK2_Pos)            /*!< 0x00008000 */
#define RTC_ALRMAR_MSK2               RTC_ALRMAR_MSK2_Msk
#define RTC_ALRMAR_MNT_Pos            (12U)
#define RTC_ALRMAR_MNT_Msk            (0x7UL << RTC_ALRMAR_MNT_Pos)             /*!< 0x00007000 */
#define RTC_ALRMAR_MNT                RTC_ALRMAR_MNT_Msk
#define RTC_ALRMAR_MNT_0              (0x1UL << RTC_ALRMAR_MNT_Pos)             /*!< 0x00001000 */
#define RTC_ALRMAR_MNT_1              (0x2UL << RTC_ALRMAR_MNT_Pos)             /*!< 0x00002000 */
#define RTC_ALRMAR_MNT_2              (0x4UL << RTC_ALRMAR_MNT_Pos)             /*!< 0x00004000 */
#define RTC_ALRMAR_MNU_Pos            (8U)
#define RTC_ALRMAR_MNU_Msk            (0xFUL << RTC_ALRMAR_MNU_Pos)             /*!< 0x00000F00 */
#define RTC_ALRMAR_MNU                RTC_ALRMAR_MNU_Msk
#define RTC_ALRMAR_MNU_0              (0x1UL << RTC_ALRMAR_MNU_Pos)             /*!< 0x00000100 */
#define RTC_ALRMAR_MNU_1              (0x2UL << RTC_ALRMAR_MNU_Pos)             /*!< 0x00000200 */
#define RTC_ALRMAR_MNU_2              (0x4UL << RTC_ALRMAR_MNU_Pos)             /*!< 0x00000400 */
#define RTC_ALRMAR_MNU_3              (0x8UL << RTC_ALRMAR_MNU_Pos)             /*!< 0x00000800 */
#define RTC_ALRMAR_MSK1_Pos           (7U)
#define RTC_ALRMAR_MSK1_Msk           (0x1UL << RTC_ALRMAR_MSK1_Pos)            /*!< 0x00000080 */
#define RTC_ALRMAR_MSK1               RTC_ALRMAR_MSK1_Msk
#define RTC_ALRMAR_ST_Pos             (4U)
#define RTC_ALRMAR_ST_Msk             (0x7UL << RTC_ALRMAR_ST_Pos)              /*!< 0x00000070 */
#define RTC_ALRMAR_ST                 RTC_ALRMAR_ST_Msk
#define RTC_ALRMAR_ST_0               (0x1UL << RTC_ALRMAR_ST_Pos)              /*!< 0x00000010 */
#define RTC_ALRMAR_ST_1               (0x2UL << RTC_ALRMAR_ST_Pos)              /*!< 0x00000020 */
#define RTC_ALRMAR_ST_2               (0x4UL << RTC_ALRMAR_ST_Pos)              /*!< 0x00000040 */
#define RTC_ALRMAR_SU_Pos             (0U)
#define RTC_ALRMAR_SU_Msk             (0xFUL << RTC_ALRMAR_SU_Pos)              /*!< 0x0000000F */
#define RTC_ALRMAR_SU                 RTC_ALRMAR_SU_Msk
#define RTC_ALRMAR_SU_0               (0x1UL << RTC_ALRMAR_SU_Pos)              /*!< 0x00000001 */
#define RTC_ALRMAR_SU_1               (0x2UL << RTC_ALRMAR_SU_Pos)              /*!< 0x00000002 */
#define RTC_ALRMAR_SU_2               (0x4UL << RTC_ALRMAR_SU_Pos)              /*!< 0x00000004 */
#define RTC_ALRMAR_SU_3               (0x8UL << RTC_ALRMAR_SU_Pos)              /*!< 0x00000008 */

/********************  Bits definition for RTC_ALRMBR register  ***************/
#define RTC_ALRMBR_MSK4_Pos           (31U)
#define RTC_ALRMBR_MSK4_Msk           (0x1UL << RTC_ALRMBR_MSK4_Pos)            /*!< 0x80000000 */
#define RTC_ALRMBR_MSK4               RTC_ALRMBR_MSK4_Msk
#define RTC_ALRMBR_WDSEL_Pos          (30U)
#define RTC_ALRMBR_WDSEL_Msk          (0x1UL << RTC_ALRMBR_WDSEL_Pos)           /*!< 0x40000000 */
#define RTC_ALRMBR_WDSEL              RTC_ALRMBR_WDSEL_Msk
#define RTC_ALRMBR_DT_Pos             (28U)
#define RTC_ALRMBR_DT_Msk             (0x3UL << RTC_ALRMBR_DT_Pos)              /*!< 0x30000000 */
#define RTC_ALRMBR_DT                 RTC_ALRMBR_DT_Msk
#define RTC_ALRMBR_DT_0               (0x1UL << RTC_ALRMBR_DT_Pos)              /*!< 0x10000000 */
#define RTC_ALRMBR_DT_1               (0x2UL << RTC_ALRMBR_DT_Pos)              /*!< 0x20000000 */
#define RTC_ALRMBR_DU_Pos             (24U)
#define RTC_ALRMBR_DU_Msk             (0xFUL << RTC_ALRMBR_DU_Pos)              /*!< 0x0F000000 */
#define RTC_ALRMBR_DU                 RTC_ALRMBR_DU_Msk
#define RTC_ALRMBR_DU_0               (0x1UL << RTC_ALRMBR_DU_Pos)              /*!< 0x01000000 */
#define RTC_ALRMBR_DU_1               (0x2UL << RTC_ALRMBR_DU_Pos)              /*!< 0x02000000 */
#define RTC_ALRMBR_DU_2               (0x4UL << RTC_ALRMBR_DU_Pos)              /*!< 0x04000000 */
#define RTC_ALRMBR_DU_3               (0x8UL << RTC_ALRMBR_DU_Pos)              /*!< 0x08000000 */
#define RTC_ALRMBR_MSK3_Pos           (23U)
#define RTC_ALRMBR_MSK3_Msk           (0x1UL << RTC_ALRMBR_MSK3_Pos)            /*!< 0x00800000 */
#define RTC_ALRMBR_MSK3               RTC_ALRMBR_MSK3_Msk
#define RTC_ALRMBR_PM_Pos             (22U)
#define RTC_ALRMBR_PM_Msk             (0x1UL << RTC_ALRMBR_PM_Pos)              /*!< 0x00400000 */
#define RTC_ALRMBR_PM                 RTC_ALRMBR_PM_Msk
#define RTC_ALRMBR_HT_Pos             (20U)
#define RTC_ALRMBR_HT_Msk             (0x3UL << RTC_ALRMBR_HT_Pos)              /*!< 0x00300000 */
#define RTC_ALRMBR_HT                 RTC_ALRMBR_HT_Msk
#define RTC_ALRMBR_HT_0               (0x1UL << RTC_ALRMBR_HT_Pos)              /*!< 0x00100000 */
#define RTC_ALRMBR_HT_1               (0x2UL << RTC_ALRMBR_HT_Pos)              /*!< 0x00200000 */
#define RTC_ALRMBR_HU_Pos             (16U)
#define RTC_ALRMBR_HU_Msk             (0xFUL << RTC_ALRMBR_HU_Pos)              /*!< 0x000F0000 */
#define RTC_ALRMBR_HU                 RTC_ALRMBR_HU_Msk
#define RTC_ALRMBR_HU_0               (0x1UL << RTC_ALRMBR_HU_Pos)              /*!< 0x00010000 */
#define RTC_ALRMBR_HU_1               (0x2UL << RTC_ALRMBR_HU_Pos)              /*!< 0x00020000 */
#define RTC_ALRMBR_HU_2               (0x4UL << RTC_ALRMBR_HU_Pos)              /*!< 0x00040000 */
#define RTC_ALRMBR_HU_3               (0x8UL << RTC_ALRMBR_HU_Pos)              /*!< 0x00080000 */
#define RTC_ALRMBR_MSK2_Pos           (15U)
#define RTC_ALRMBR_MSK2_Msk           (0x1UL << RTC_ALRMBR_MSK2_Pos)            /*!< 0x00008000 */
#define RTC_ALRMBR_MSK2               RTC_ALRMBR_MSK2_Msk
#define RTC_ALRMBR_MNT_Pos            (12U)
#define RTC_ALRMBR_MNT_Msk            (0x7UL << RTC_ALRMBR_MNT_Pos)             /*!< 0x00007000 */
#define RTC_ALRMBR_MNT                RTC_ALRMBR_MNT_Msk
#define RTC_ALRMBR_MNT_0              (0x1UL << RTC_ALRMBR_MNT_Pos)             /*!< 0x00001000 */
#define RTC_ALRMBR_MNT_1              (0x2UL << RTC_ALRMBR_MNT_Pos)             /*!< 0x00002000 */
#define RTC_ALRMBR_MNT_2              (0x4UL << RTC_ALRMBR_MNT_Pos)             /*!< 0x00004000 */
#define RTC_ALRMBR_MNU_Pos            (8U)
#define RTC_ALRMBR_MNU_Msk            (0xFUL << RTC_ALRMBR_MNU_Pos)             /*!< 0x00000F00 */
#define RTC_ALRMBR_MNU                RTC_ALRMBR_MNU_Msk
#define RTC_ALRMBR_MNU_0              (0x1UL << RTC_ALRMBR_MNU_Pos)             /*!< 0x00000100 */
#define RTC_ALRMBR_MNU_1              (0x2UL << RTC_ALRMBR_MNU_Pos)             /*!< 0x00000200 */
#define RTC_ALRMBR_MNU_2              (0x4UL << RTC_ALRMBR_MNU_Pos)             /*!< 0x00000400 */
#define RTC_ALRMBR_MNU_3              (0x8UL << RTC_ALRMBR_MNU_Pos)             /*!< 0x00000800 */
#define RTC_ALRMBR_MSK1_Pos           (7U)
#define RTC_ALRMBR_MSK1_Msk           (0x1UL << RTC_ALRMBR_MSK1_Pos)            /*!< 0x00000080 */
#define RTC_ALRMBR_MSK1               RTC_ALRMBR_MSK1_Msk
#define RTC_ALRMBR_ST_Pos             (4U)
#define RTC_ALRMBR_ST_Msk             (0x7UL << RTC_ALRMBR_ST_Pos)              /*!< 0x00000070 */
#define RTC_ALRMBR_ST                 RTC_ALRMBR_ST_Msk
#define RTC_ALRMBR_ST_0               (0x1UL << RTC_ALRMBR_ST_Pos)              /*!< 0x00000010 */
#define RTC_ALRMBR_ST_1               (0x2UL << RTC_ALRMBR_ST_Pos)              /*!< 0x00000020 */
#define RTC_ALRMBR_ST_2               (0x4UL << RTC_ALRMBR_ST_Pos)              /*!< 0x00000040 */
#define RTC_ALRMBR_SU_Pos             (0U)
#define RTC_ALRMBR_SU_Msk             (0xFUL << RTC_ALRMBR_SU_Pos)              /*!< 0x0000000F */
#define RTC_ALRMBR_SU                 RTC_ALRMBR_SU_Msk
#define RTC_ALRMBR_SU_0               (0x1UL << RTC_ALRMBR_SU_Pos)              /*!< 0x00000001 */
#define RTC_ALRMBR_SU_1               (0x2UL << RTC_ALRMBR_SU_Pos)              /*!< 0x00000002 */
#define RTC_ALRMBR_SU_2               (0x4UL << RTC_ALRMBR_SU_Pos)              /*!< 0x00000004 */
#define RTC_ALRMBR_SU_3               (0x8UL << RTC_ALRMBR_SU_Pos)              /*!< 0x00000008 */

/********************  Bits definition for RTC_WPR register  ******************/
#define RTC_WPR_KEY_Pos               (0U)
#define RTC_WPR_KEY_Msk               (0xFFUL << RTC_WPR_KEY_Pos)               /*!< 0x000000FF */
#define RTC_WPR_KEY                   RTC_WPR_KEY_Msk

/********************  Bits definition for RTC_SSR register  ******************/
#define RTC_SSR_SS_Pos                (0U)
#define RTC_SSR_SS_Msk                (0xFFFFUL << RTC_SSR_SS_Pos)              /*!< 0x0000FFFF */
#define RTC_SSR_SS                    RTC_SSR_SS_Msk

/********************  Bits definition for RTC_SHIFTR register  ***************/
#define RTC_SHIFTR_SUBFS_Pos          (0U)
#define RTC_SHIFTR_SUBFS_Msk          (0x7FFFUL << RTC_SHIFTR_SUBFS_Pos)        /*!< 0x00007FFF */
#define RTC_SHIFTR_SUBFS              RTC_SHIFTR_SUBFS_Msk
#define RTC_SHIFTR_ADD1S_Pos          (31U)
#define RTC_SHIFTR_ADD1S_Msk          (0x1UL << RTC_SHIFTR_ADD1S_Pos)           /*!< 0x80000000 */
#define RTC_SHIFTR_ADD1S              RTC_SHIFTR_ADD1S_Msk



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



#define NVIC_GetPriorityGrouping    __NVIC_GetPriorityGrouping

/**
  \brief   Get Priority Grouping
  \details Reads the priority grouping field from the NVIC Interrupt Controller.
  \return                Priority grouping field (SCB->AIRCR [10:8] PRIGROUP field).
 */
__STATIC_INLINE uint32_t __NVIC_GetPriorityGrouping(void)
{
  return ((uint32_t)((SCB->AIRCR & SCB_AIRCR_PRIGROUP_Msk) >> SCB_AIRCR_PRIGROUP_Pos));
}
