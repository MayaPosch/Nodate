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
