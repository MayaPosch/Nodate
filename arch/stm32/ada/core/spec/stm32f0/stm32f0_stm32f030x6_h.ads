pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with stdint_h;

package stm32f0_stm32f030x6_h is

   FLASH_BASE : constant := 16#08000000#;  --  ../core/include/stm32f0/stm32f030x6.h:428
   FLASH_BANK1_END : constant := 16#08007FFF#;  --  ../core/include/stm32f0/stm32f030x6.h:429
   SRAM_BASE : constant := 16#20000000#;  --  ../core/include/stm32f0/stm32f030x6.h:430
   PERIPH_BASE : constant := 16#40000000#;  --  ../core/include/stm32f0/stm32f030x6.h:431
   --  unsupported macro: APBPERIPH_BASE PERIPH_BASE
   --  unsupported macro: AHBPERIPH_BASE (PERIPH_BASE + 0x00020000UL)
   --  unsupported macro: AHB2PERIPH_BASE (PERIPH_BASE + 0x08000000UL)
   --  unsupported macro: TIM3_BASE (APBPERIPH_BASE + 0x00000400UL)
   --  unsupported macro: TIM14_BASE (APBPERIPH_BASE + 0x00002000UL)
   --  unsupported macro: RTC_BASE (APBPERIPH_BASE + 0x00002800UL)
   --  unsupported macro: WWDG_BASE (APBPERIPH_BASE + 0x00002C00UL)
   --  unsupported macro: IWDG_BASE (APBPERIPH_BASE + 0x00003000UL)
   --  unsupported macro: I2C1_BASE (APBPERIPH_BASE + 0x00005400UL)
   --  unsupported macro: PWR_BASE (APBPERIPH_BASE + 0x00007000UL)
   --  unsupported macro: SYSCFG_BASE (APBPERIPH_BASE + 0x00010000UL)
   --  unsupported macro: EXTI_BASE (APBPERIPH_BASE + 0x00010400UL)
   --  unsupported macro: ADC1_BASE (APBPERIPH_BASE + 0x00012400UL)
   --  unsupported macro: ADC_BASE (APBPERIPH_BASE + 0x00012708UL)
   --  unsupported macro: TIM1_BASE (APBPERIPH_BASE + 0x00012C00UL)
   --  unsupported macro: SPI1_BASE (APBPERIPH_BASE + 0x00013000UL)
   --  unsupported macro: USART1_BASE (APBPERIPH_BASE + 0x00013800UL)
   --  unsupported macro: TIM16_BASE (APBPERIPH_BASE + 0x00014400UL)
   --  unsupported macro: TIM17_BASE (APBPERIPH_BASE + 0x00014800UL)
   --  unsupported macro: DBGMCU_BASE (APBPERIPH_BASE + 0x00015800UL)
   --  unsupported macro: DMA1_BASE (AHBPERIPH_BASE + 0x00000000UL)
   --  unsupported macro: DMA1_Channel1_BASE (DMA1_BASE + 0x00000008UL)
   --  unsupported macro: DMA1_Channel2_BASE (DMA1_BASE + 0x0000001CUL)
   --  unsupported macro: DMA1_Channel3_BASE (DMA1_BASE + 0x00000030UL)
   --  unsupported macro: DMA1_Channel4_BASE (DMA1_BASE + 0x00000044UL)
   --  unsupported macro: DMA1_Channel5_BASE (DMA1_BASE + 0x00000058UL)
   --  unsupported macro: RCC_BASE (AHBPERIPH_BASE + 0x00001000UL)
   --  unsupported macro: FLASH_R_BASE (AHBPERIPH_BASE + 0x00002000UL)

   OB_BASE : constant := 16#1FFFF800#;  --  ../core/include/stm32f0/stm32f030x6.h:467
   FLASHSIZE_BASE : constant := 16#1FFFF7CC#;  --  ../core/include/stm32f0/stm32f030x6.h:468
   UID_BASE : constant := 16#1FFFF7AC#;  --  ../core/include/stm32f0/stm32f030x6.h:469
   --  unsupported macro: CRC_BASE (AHBPERIPH_BASE + 0x00003000UL)
   --  unsupported macro: GPIOA_BASE (AHB2PERIPH_BASE + 0x00000000UL)
   --  unsupported macro: GPIOB_BASE (AHB2PERIPH_BASE + 0x00000400UL)
   --  unsupported macro: GPIOC_BASE (AHB2PERIPH_BASE + 0x00000800UL)
   --  unsupported macro: GPIOD_BASE (AHB2PERIPH_BASE + 0x00000C00UL)
   --  unsupported macro: GPIOF_BASE (AHB2PERIPH_BASE + 0x00001400UL)
   --  unsupported macro: TIM3 ((TIM_TypeDef *) TIM3_BASE)
   --  unsupported macro: TIM14 ((TIM_TypeDef *) TIM14_BASE)
   --  unsupported macro: RTC ((RTC_TypeDef *) RTC_BASE)
   --  unsupported macro: WWDG ((WWDG_TypeDef *) WWDG_BASE)
   --  unsupported macro: IWDG ((IWDG_TypeDef *) IWDG_BASE)
   --  unsupported macro: I2C1 ((I2C_TypeDef *) I2C1_BASE)
   --  unsupported macro: PWR ((PWR_TypeDef *) PWR_BASE)
   --  unsupported macro: SYSCFG ((SYSCFG_TypeDef *) SYSCFG_BASE)
   --  unsupported macro: EXTI ((EXTI_TypeDef *) EXTI_BASE)
   --  unsupported macro: ADC1 ((ADC_TypeDef *) ADC1_BASE)
   --  unsupported macro: ADC1_COMMON ((ADC_Common_TypeDef *) ADC_BASE)
   --  unsupported macro: ADC ((ADC_Common_TypeDef *) ADC_BASE)
   --  unsupported macro: TIM1 ((TIM_TypeDef *) TIM1_BASE)
   --  unsupported macro: SPI1 ((SPI_TypeDef *) SPI1_BASE)
   --  unsupported macro: USART1 ((USART_TypeDef *) USART1_BASE)
   --  unsupported macro: TIM16 ((TIM_TypeDef *) TIM16_BASE)
   --  unsupported macro: TIM17 ((TIM_TypeDef *) TIM17_BASE)
   --  unsupported macro: DBGMCU ((DBGMCU_TypeDef *) DBGMCU_BASE)
   --  unsupported macro: DMA1 ((DMA_TypeDef *) DMA1_BASE)
   --  unsupported macro: DMA1_Channel1 ((DMA_Channel_TypeDef *) DMA1_Channel1_BASE)
   --  unsupported macro: DMA1_Channel2 ((DMA_Channel_TypeDef *) DMA1_Channel2_BASE)
   --  unsupported macro: DMA1_Channel3 ((DMA_Channel_TypeDef *) DMA1_Channel3_BASE)
   --  unsupported macro: DMA1_Channel4 ((DMA_Channel_TypeDef *) DMA1_Channel4_BASE)
   --  unsupported macro: DMA1_Channel5 ((DMA_Channel_TypeDef *) DMA1_Channel5_BASE)
   --  unsupported macro: FLASH ((FLASH_TypeDef *) FLASH_R_BASE)
   --  unsupported macro: OB ((OB_TypeDef *) OB_BASE)
   --  unsupported macro: RCC ((RCC_TypeDef *) RCC_BASE)
   --  unsupported macro: CRC ((CRC_TypeDef *) CRC_BASE)
   --  unsupported macro: GPIOA ((GPIO_TypeDef *) GPIOA_BASE)
   --  unsupported macro: GPIOB ((GPIO_TypeDef *) GPIOB_BASE)
   --  unsupported macro: GPIOC ((GPIO_TypeDef *) GPIOC_BASE)
   --  unsupported macro: GPIOD ((GPIO_TypeDef *) GPIOD_BASE)
   --  unsupported macro: GPIOF ((GPIO_TypeDef *) GPIOF_BASE)

   ADC_ISR_ADRDY_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:548
   --  unsupported macro: ADC_ISR_ADRDY_Msk (0x1UL << ADC_ISR_ADRDY_Pos)
   --  unsupported macro: ADC_ISR_ADRDY ADC_ISR_ADRDY_Msk

   ADC_ISR_EOSMP_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:551
   --  unsupported macro: ADC_ISR_EOSMP_Msk (0x1UL << ADC_ISR_EOSMP_Pos)
   --  unsupported macro: ADC_ISR_EOSMP ADC_ISR_EOSMP_Msk

   ADC_ISR_EOC_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:554
   --  unsupported macro: ADC_ISR_EOC_Msk (0x1UL << ADC_ISR_EOC_Pos)
   --  unsupported macro: ADC_ISR_EOC ADC_ISR_EOC_Msk

   ADC_ISR_EOS_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:557
   --  unsupported macro: ADC_ISR_EOS_Msk (0x1UL << ADC_ISR_EOS_Pos)
   --  unsupported macro: ADC_ISR_EOS ADC_ISR_EOS_Msk

   ADC_ISR_OVR_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:560
   --  unsupported macro: ADC_ISR_OVR_Msk (0x1UL << ADC_ISR_OVR_Pos)
   --  unsupported macro: ADC_ISR_OVR ADC_ISR_OVR_Msk

   ADC_ISR_AWD1_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:563
   --  unsupported macro: ADC_ISR_AWD1_Msk (0x1UL << ADC_ISR_AWD1_Pos)
   --  unsupported macro: ADC_ISR_AWD1 ADC_ISR_AWD1_Msk
   --  unsupported macro: ADC_ISR_AWD (ADC_ISR_AWD1)
   --  unsupported macro: ADC_ISR_EOSEQ (ADC_ISR_EOS)

   ADC_IER_ADRDYIE_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:572
   --  unsupported macro: ADC_IER_ADRDYIE_Msk (0x1UL << ADC_IER_ADRDYIE_Pos)
   --  unsupported macro: ADC_IER_ADRDYIE ADC_IER_ADRDYIE_Msk

   ADC_IER_EOSMPIE_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:575
   --  unsupported macro: ADC_IER_EOSMPIE_Msk (0x1UL << ADC_IER_EOSMPIE_Pos)
   --  unsupported macro: ADC_IER_EOSMPIE ADC_IER_EOSMPIE_Msk

   ADC_IER_EOCIE_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:578
   --  unsupported macro: ADC_IER_EOCIE_Msk (0x1UL << ADC_IER_EOCIE_Pos)
   --  unsupported macro: ADC_IER_EOCIE ADC_IER_EOCIE_Msk

   ADC_IER_EOSIE_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:581
   --  unsupported macro: ADC_IER_EOSIE_Msk (0x1UL << ADC_IER_EOSIE_Pos)
   --  unsupported macro: ADC_IER_EOSIE ADC_IER_EOSIE_Msk

   ADC_IER_OVRIE_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:584
   --  unsupported macro: ADC_IER_OVRIE_Msk (0x1UL << ADC_IER_OVRIE_Pos)
   --  unsupported macro: ADC_IER_OVRIE ADC_IER_OVRIE_Msk

   ADC_IER_AWD1IE_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:587
   --  unsupported macro: ADC_IER_AWD1IE_Msk (0x1UL << ADC_IER_AWD1IE_Pos)
   --  unsupported macro: ADC_IER_AWD1IE ADC_IER_AWD1IE_Msk
   --  unsupported macro: ADC_IER_AWDIE (ADC_IER_AWD1IE)
   --  unsupported macro: ADC_IER_EOSEQIE (ADC_IER_EOSIE)

   ADC_CR_ADEN_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:596
   --  unsupported macro: ADC_CR_ADEN_Msk (0x1UL << ADC_CR_ADEN_Pos)
   --  unsupported macro: ADC_CR_ADEN ADC_CR_ADEN_Msk

   ADC_CR_ADDIS_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:599
   --  unsupported macro: ADC_CR_ADDIS_Msk (0x1UL << ADC_CR_ADDIS_Pos)
   --  unsupported macro: ADC_CR_ADDIS ADC_CR_ADDIS_Msk

   ADC_CR_ADSTART_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:602
   --  unsupported macro: ADC_CR_ADSTART_Msk (0x1UL << ADC_CR_ADSTART_Pos)
   --  unsupported macro: ADC_CR_ADSTART ADC_CR_ADSTART_Msk

   ADC_CR_ADSTP_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:605
   --  unsupported macro: ADC_CR_ADSTP_Msk (0x1UL << ADC_CR_ADSTP_Pos)
   --  unsupported macro: ADC_CR_ADSTP ADC_CR_ADSTP_Msk

   ADC_CR_ADCAL_Pos : constant := (31);  --  ../core/include/stm32f0/stm32f030x6.h:608
   --  unsupported macro: ADC_CR_ADCAL_Msk (0x1UL << ADC_CR_ADCAL_Pos)
   --  unsupported macro: ADC_CR_ADCAL ADC_CR_ADCAL_Msk

   ADC_CFGR1_DMAEN_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:613
   --  unsupported macro: ADC_CFGR1_DMAEN_Msk (0x1UL << ADC_CFGR1_DMAEN_Pos)
   --  unsupported macro: ADC_CFGR1_DMAEN ADC_CFGR1_DMAEN_Msk

   ADC_CFGR1_DMACFG_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:616
   --  unsupported macro: ADC_CFGR1_DMACFG_Msk (0x1UL << ADC_CFGR1_DMACFG_Pos)
   --  unsupported macro: ADC_CFGR1_DMACFG ADC_CFGR1_DMACFG_Msk

   ADC_CFGR1_SCANDIR_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:619
   --  unsupported macro: ADC_CFGR1_SCANDIR_Msk (0x1UL << ADC_CFGR1_SCANDIR_Pos)
   --  unsupported macro: ADC_CFGR1_SCANDIR ADC_CFGR1_SCANDIR_Msk

   ADC_CFGR1_RES_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:623
   --  unsupported macro: ADC_CFGR1_RES_Msk (0x3UL << ADC_CFGR1_RES_Pos)
   --  unsupported macro: ADC_CFGR1_RES ADC_CFGR1_RES_Msk
   --  unsupported macro: ADC_CFGR1_RES_0 (0x1UL << ADC_CFGR1_RES_Pos)
   --  unsupported macro: ADC_CFGR1_RES_1 (0x2UL << ADC_CFGR1_RES_Pos)

   ADC_CFGR1_ALIGN_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:629
   --  unsupported macro: ADC_CFGR1_ALIGN_Msk (0x1UL << ADC_CFGR1_ALIGN_Pos)
   --  unsupported macro: ADC_CFGR1_ALIGN ADC_CFGR1_ALIGN_Msk

   ADC_CFGR1_EXTSEL_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:633
   --  unsupported macro: ADC_CFGR1_EXTSEL_Msk (0x7UL << ADC_CFGR1_EXTSEL_Pos)
   --  unsupported macro: ADC_CFGR1_EXTSEL ADC_CFGR1_EXTSEL_Msk
   --  unsupported macro: ADC_CFGR1_EXTSEL_0 (0x1UL << ADC_CFGR1_EXTSEL_Pos)
   --  unsupported macro: ADC_CFGR1_EXTSEL_1 (0x2UL << ADC_CFGR1_EXTSEL_Pos)
   --  unsupported macro: ADC_CFGR1_EXTSEL_2 (0x4UL << ADC_CFGR1_EXTSEL_Pos)

   ADC_CFGR1_EXTEN_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:640
   --  unsupported macro: ADC_CFGR1_EXTEN_Msk (0x3UL << ADC_CFGR1_EXTEN_Pos)
   --  unsupported macro: ADC_CFGR1_EXTEN ADC_CFGR1_EXTEN_Msk
   --  unsupported macro: ADC_CFGR1_EXTEN_0 (0x1UL << ADC_CFGR1_EXTEN_Pos)
   --  unsupported macro: ADC_CFGR1_EXTEN_1 (0x2UL << ADC_CFGR1_EXTEN_Pos)

   ADC_CFGR1_OVRMOD_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:646
   --  unsupported macro: ADC_CFGR1_OVRMOD_Msk (0x1UL << ADC_CFGR1_OVRMOD_Pos)
   --  unsupported macro: ADC_CFGR1_OVRMOD ADC_CFGR1_OVRMOD_Msk

   ADC_CFGR1_CONT_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:649
   --  unsupported macro: ADC_CFGR1_CONT_Msk (0x1UL << ADC_CFGR1_CONT_Pos)
   --  unsupported macro: ADC_CFGR1_CONT ADC_CFGR1_CONT_Msk

   ADC_CFGR1_WAIT_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:652
   --  unsupported macro: ADC_CFGR1_WAIT_Msk (0x1UL << ADC_CFGR1_WAIT_Pos)
   --  unsupported macro: ADC_CFGR1_WAIT ADC_CFGR1_WAIT_Msk

   ADC_CFGR1_AUTOFF_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:655
   --  unsupported macro: ADC_CFGR1_AUTOFF_Msk (0x1UL << ADC_CFGR1_AUTOFF_Pos)
   --  unsupported macro: ADC_CFGR1_AUTOFF ADC_CFGR1_AUTOFF_Msk

   ADC_CFGR1_DISCEN_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:658
   --  unsupported macro: ADC_CFGR1_DISCEN_Msk (0x1UL << ADC_CFGR1_DISCEN_Pos)
   --  unsupported macro: ADC_CFGR1_DISCEN ADC_CFGR1_DISCEN_Msk

   ADC_CFGR1_AWD1SGL_Pos : constant := (22);  --  ../core/include/stm32f0/stm32f030x6.h:662
   --  unsupported macro: ADC_CFGR1_AWD1SGL_Msk (0x1UL << ADC_CFGR1_AWD1SGL_Pos)
   --  unsupported macro: ADC_CFGR1_AWD1SGL ADC_CFGR1_AWD1SGL_Msk

   ADC_CFGR1_AWD1EN_Pos : constant := (23);  --  ../core/include/stm32f0/stm32f030x6.h:665
   --  unsupported macro: ADC_CFGR1_AWD1EN_Msk (0x1UL << ADC_CFGR1_AWD1EN_Pos)
   --  unsupported macro: ADC_CFGR1_AWD1EN ADC_CFGR1_AWD1EN_Msk

   ADC_CFGR1_AWD1CH_Pos : constant := (26);  --  ../core/include/stm32f0/stm32f030x6.h:669
   --  unsupported macro: ADC_CFGR1_AWD1CH_Msk (0x1FUL << ADC_CFGR1_AWD1CH_Pos)
   --  unsupported macro: ADC_CFGR1_AWD1CH ADC_CFGR1_AWD1CH_Msk
   --  unsupported macro: ADC_CFGR1_AWD1CH_0 (0x01UL << ADC_CFGR1_AWD1CH_Pos)
   --  unsupported macro: ADC_CFGR1_AWD1CH_1 (0x02UL << ADC_CFGR1_AWD1CH_Pos)
   --  unsupported macro: ADC_CFGR1_AWD1CH_2 (0x04UL << ADC_CFGR1_AWD1CH_Pos)
   --  unsupported macro: ADC_CFGR1_AWD1CH_3 (0x08UL << ADC_CFGR1_AWD1CH_Pos)
   --  unsupported macro: ADC_CFGR1_AWD1CH_4 (0x10UL << ADC_CFGR1_AWD1CH_Pos)
   --  unsupported macro: ADC_CFGR1_AUTDLY (ADC_CFGR1_WAIT)
   --  unsupported macro: ADC_CFGR1_AWDSGL (ADC_CFGR1_AWD1SGL)
   --  unsupported macro: ADC_CFGR1_AWDEN (ADC_CFGR1_AWD1EN)
   --  unsupported macro: ADC_CFGR1_AWDCH (ADC_CFGR1_AWD1CH)
   --  unsupported macro: ADC_CFGR1_AWDCH_0 (ADC_CFGR1_AWD1CH_0)
   --  unsupported macro: ADC_CFGR1_AWDCH_1 (ADC_CFGR1_AWD1CH_1)
   --  unsupported macro: ADC_CFGR1_AWDCH_2 (ADC_CFGR1_AWD1CH_2)
   --  unsupported macro: ADC_CFGR1_AWDCH_3 (ADC_CFGR1_AWD1CH_3)
   --  unsupported macro: ADC_CFGR1_AWDCH_4 (ADC_CFGR1_AWD1CH_4)

   ADC_CFGR2_CKMODE_Pos : constant := (30);  --  ../core/include/stm32f0/stm32f030x6.h:690
   --  unsupported macro: ADC_CFGR2_CKMODE_Msk (0x3UL << ADC_CFGR2_CKMODE_Pos)
   --  unsupported macro: ADC_CFGR2_CKMODE ADC_CFGR2_CKMODE_Msk
   --  unsupported macro: ADC_CFGR2_CKMODE_1 (0x2UL << ADC_CFGR2_CKMODE_Pos)
   --  unsupported macro: ADC_CFGR2_CKMODE_0 (0x1UL << ADC_CFGR2_CKMODE_Pos)
   --  unsupported macro: ADC_CFGR2_JITOFFDIV4 (ADC_CFGR2_CKMODE_1)
   --  unsupported macro: ADC_CFGR2_JITOFFDIV2 (ADC_CFGR2_CKMODE_0)

   ADC_SMPR_SMP_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:701
   --  unsupported macro: ADC_SMPR_SMP_Msk (0x7UL << ADC_SMPR_SMP_Pos)
   --  unsupported macro: ADC_SMPR_SMP ADC_SMPR_SMP_Msk
   --  unsupported macro: ADC_SMPR_SMP_0 (0x1UL << ADC_SMPR_SMP_Pos)
   --  unsupported macro: ADC_SMPR_SMP_1 (0x2UL << ADC_SMPR_SMP_Pos)
   --  unsupported macro: ADC_SMPR_SMP_2 (0x4UL << ADC_SMPR_SMP_Pos)
   --  unsupported macro: ADC_SMPR1_SMPR (ADC_SMPR_SMP)
   --  unsupported macro: ADC_SMPR1_SMPR_0 (ADC_SMPR_SMP_0)
   --  unsupported macro: ADC_SMPR1_SMPR_1 (ADC_SMPR_SMP_1)
   --  unsupported macro: ADC_SMPR1_SMPR_2 (ADC_SMPR_SMP_2)

   ADC_TR1_LT1_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:715
   --  unsupported macro: ADC_TR1_LT1_Msk (0xFFFUL << ADC_TR1_LT1_Pos)
   --  unsupported macro: ADC_TR1_LT1 ADC_TR1_LT1_Msk
   --  unsupported macro: ADC_TR1_LT1_0 (0x001UL << ADC_TR1_LT1_Pos)
   --  unsupported macro: ADC_TR1_LT1_1 (0x002UL << ADC_TR1_LT1_Pos)
   --  unsupported macro: ADC_TR1_LT1_2 (0x004UL << ADC_TR1_LT1_Pos)
   --  unsupported macro: ADC_TR1_LT1_3 (0x008UL << ADC_TR1_LT1_Pos)
   --  unsupported macro: ADC_TR1_LT1_4 (0x010UL << ADC_TR1_LT1_Pos)
   --  unsupported macro: ADC_TR1_LT1_5 (0x020UL << ADC_TR1_LT1_Pos)
   --  unsupported macro: ADC_TR1_LT1_6 (0x040UL << ADC_TR1_LT1_Pos)
   --  unsupported macro: ADC_TR1_LT1_7 (0x080UL << ADC_TR1_LT1_Pos)
   --  unsupported macro: ADC_TR1_LT1_8 (0x100UL << ADC_TR1_LT1_Pos)
   --  unsupported macro: ADC_TR1_LT1_9 (0x200UL << ADC_TR1_LT1_Pos)
   --  unsupported macro: ADC_TR1_LT1_10 (0x400UL << ADC_TR1_LT1_Pos)
   --  unsupported macro: ADC_TR1_LT1_11 (0x800UL << ADC_TR1_LT1_Pos)

   ADC_TR1_HT1_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:731
   --  unsupported macro: ADC_TR1_HT1_Msk (0xFFFUL << ADC_TR1_HT1_Pos)
   --  unsupported macro: ADC_TR1_HT1 ADC_TR1_HT1_Msk
   --  unsupported macro: ADC_TR1_HT1_0 (0x001UL << ADC_TR1_HT1_Pos)
   --  unsupported macro: ADC_TR1_HT1_1 (0x002UL << ADC_TR1_HT1_Pos)
   --  unsupported macro: ADC_TR1_HT1_2 (0x004UL << ADC_TR1_HT1_Pos)
   --  unsupported macro: ADC_TR1_HT1_3 (0x008UL << ADC_TR1_HT1_Pos)
   --  unsupported macro: ADC_TR1_HT1_4 (0x010UL << ADC_TR1_HT1_Pos)
   --  unsupported macro: ADC_TR1_HT1_5 (0x020UL << ADC_TR1_HT1_Pos)
   --  unsupported macro: ADC_TR1_HT1_6 (0x040UL << ADC_TR1_HT1_Pos)
   --  unsupported macro: ADC_TR1_HT1_7 (0x080UL << ADC_TR1_HT1_Pos)
   --  unsupported macro: ADC_TR1_HT1_8 (0x100UL << ADC_TR1_HT1_Pos)
   --  unsupported macro: ADC_TR1_HT1_9 (0x200UL << ADC_TR1_HT1_Pos)
   --  unsupported macro: ADC_TR1_HT1_10 (0x400UL << ADC_TR1_HT1_Pos)
   --  unsupported macro: ADC_TR1_HT1_11 (0x800UL << ADC_TR1_HT1_Pos)
   --  unsupported macro: ADC_TR_HT (ADC_TR1_HT1)
   --  unsupported macro: ADC_TR_LT (ADC_TR1_LT1)
   --  unsupported macro: ADC_HTR_HT (ADC_TR1_HT1)
   --  unsupported macro: ADC_LTR_LT (ADC_TR1_LT1)

   ADC_CHSELR_CHSEL_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:754
   --  unsupported macro: ADC_CHSELR_CHSEL_Msk (0x7FFFFUL << ADC_CHSELR_CHSEL_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL ADC_CHSELR_CHSEL_Msk

   ADC_CHSELR_CHSEL18_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:757
   --  unsupported macro: ADC_CHSELR_CHSEL18_Msk (0x1UL << ADC_CHSELR_CHSEL18_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL18 ADC_CHSELR_CHSEL18_Msk

   ADC_CHSELR_CHSEL17_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:760
   --  unsupported macro: ADC_CHSELR_CHSEL17_Msk (0x1UL << ADC_CHSELR_CHSEL17_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL17 ADC_CHSELR_CHSEL17_Msk

   ADC_CHSELR_CHSEL16_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:763
   --  unsupported macro: ADC_CHSELR_CHSEL16_Msk (0x1UL << ADC_CHSELR_CHSEL16_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL16 ADC_CHSELR_CHSEL16_Msk

   ADC_CHSELR_CHSEL15_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:766
   --  unsupported macro: ADC_CHSELR_CHSEL15_Msk (0x1UL << ADC_CHSELR_CHSEL15_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL15 ADC_CHSELR_CHSEL15_Msk

   ADC_CHSELR_CHSEL14_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:769
   --  unsupported macro: ADC_CHSELR_CHSEL14_Msk (0x1UL << ADC_CHSELR_CHSEL14_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL14 ADC_CHSELR_CHSEL14_Msk

   ADC_CHSELR_CHSEL13_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:772
   --  unsupported macro: ADC_CHSELR_CHSEL13_Msk (0x1UL << ADC_CHSELR_CHSEL13_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL13 ADC_CHSELR_CHSEL13_Msk

   ADC_CHSELR_CHSEL12_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:775
   --  unsupported macro: ADC_CHSELR_CHSEL12_Msk (0x1UL << ADC_CHSELR_CHSEL12_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL12 ADC_CHSELR_CHSEL12_Msk

   ADC_CHSELR_CHSEL11_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:778
   --  unsupported macro: ADC_CHSELR_CHSEL11_Msk (0x1UL << ADC_CHSELR_CHSEL11_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL11 ADC_CHSELR_CHSEL11_Msk

   ADC_CHSELR_CHSEL10_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:781
   --  unsupported macro: ADC_CHSELR_CHSEL10_Msk (0x1UL << ADC_CHSELR_CHSEL10_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL10 ADC_CHSELR_CHSEL10_Msk

   ADC_CHSELR_CHSEL9_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:784
   --  unsupported macro: ADC_CHSELR_CHSEL9_Msk (0x1UL << ADC_CHSELR_CHSEL9_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL9 ADC_CHSELR_CHSEL9_Msk

   ADC_CHSELR_CHSEL8_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:787
   --  unsupported macro: ADC_CHSELR_CHSEL8_Msk (0x1UL << ADC_CHSELR_CHSEL8_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL8 ADC_CHSELR_CHSEL8_Msk

   ADC_CHSELR_CHSEL7_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:790
   --  unsupported macro: ADC_CHSELR_CHSEL7_Msk (0x1UL << ADC_CHSELR_CHSEL7_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL7 ADC_CHSELR_CHSEL7_Msk

   ADC_CHSELR_CHSEL6_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:793
   --  unsupported macro: ADC_CHSELR_CHSEL6_Msk (0x1UL << ADC_CHSELR_CHSEL6_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL6 ADC_CHSELR_CHSEL6_Msk

   ADC_CHSELR_CHSEL5_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:796
   --  unsupported macro: ADC_CHSELR_CHSEL5_Msk (0x1UL << ADC_CHSELR_CHSEL5_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL5 ADC_CHSELR_CHSEL5_Msk

   ADC_CHSELR_CHSEL4_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:799
   --  unsupported macro: ADC_CHSELR_CHSEL4_Msk (0x1UL << ADC_CHSELR_CHSEL4_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL4 ADC_CHSELR_CHSEL4_Msk

   ADC_CHSELR_CHSEL3_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:802
   --  unsupported macro: ADC_CHSELR_CHSEL3_Msk (0x1UL << ADC_CHSELR_CHSEL3_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL3 ADC_CHSELR_CHSEL3_Msk

   ADC_CHSELR_CHSEL2_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:805
   --  unsupported macro: ADC_CHSELR_CHSEL2_Msk (0x1UL << ADC_CHSELR_CHSEL2_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL2 ADC_CHSELR_CHSEL2_Msk

   ADC_CHSELR_CHSEL1_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:808
   --  unsupported macro: ADC_CHSELR_CHSEL1_Msk (0x1UL << ADC_CHSELR_CHSEL1_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL1 ADC_CHSELR_CHSEL1_Msk

   ADC_CHSELR_CHSEL0_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:811
   --  unsupported macro: ADC_CHSELR_CHSEL0_Msk (0x1UL << ADC_CHSELR_CHSEL0_Pos)
   --  unsupported macro: ADC_CHSELR_CHSEL0 ADC_CHSELR_CHSEL0_Msk

   ADC_DR_DATA_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:816
   --  unsupported macro: ADC_DR_DATA_Msk (0xFFFFUL << ADC_DR_DATA_Pos)
   --  unsupported macro: ADC_DR_DATA ADC_DR_DATA_Msk
   --  unsupported macro: ADC_DR_DATA_0 (0x0001UL << ADC_DR_DATA_Pos)
   --  unsupported macro: ADC_DR_DATA_1 (0x0002UL << ADC_DR_DATA_Pos)
   --  unsupported macro: ADC_DR_DATA_2 (0x0004UL << ADC_DR_DATA_Pos)
   --  unsupported macro: ADC_DR_DATA_3 (0x0008UL << ADC_DR_DATA_Pos)
   --  unsupported macro: ADC_DR_DATA_4 (0x0010UL << ADC_DR_DATA_Pos)
   --  unsupported macro: ADC_DR_DATA_5 (0x0020UL << ADC_DR_DATA_Pos)
   --  unsupported macro: ADC_DR_DATA_6 (0x0040UL << ADC_DR_DATA_Pos)
   --  unsupported macro: ADC_DR_DATA_7 (0x0080UL << ADC_DR_DATA_Pos)
   --  unsupported macro: ADC_DR_DATA_8 (0x0100UL << ADC_DR_DATA_Pos)
   --  unsupported macro: ADC_DR_DATA_9 (0x0200UL << ADC_DR_DATA_Pos)
   --  unsupported macro: ADC_DR_DATA_10 (0x0400UL << ADC_DR_DATA_Pos)
   --  unsupported macro: ADC_DR_DATA_11 (0x0800UL << ADC_DR_DATA_Pos)
   --  unsupported macro: ADC_DR_DATA_12 (0x1000UL << ADC_DR_DATA_Pos)
   --  unsupported macro: ADC_DR_DATA_13 (0x2000UL << ADC_DR_DATA_Pos)
   --  unsupported macro: ADC_DR_DATA_14 (0x4000UL << ADC_DR_DATA_Pos)
   --  unsupported macro: ADC_DR_DATA_15 (0x8000UL << ADC_DR_DATA_Pos)

   ADC_CCR_VREFEN_Pos : constant := (22);  --  ../core/include/stm32f0/stm32f030x6.h:838
   --  unsupported macro: ADC_CCR_VREFEN_Msk (0x1UL << ADC_CCR_VREFEN_Pos)
   --  unsupported macro: ADC_CCR_VREFEN ADC_CCR_VREFEN_Msk

   ADC_CCR_TSEN_Pos : constant := (23);  --  ../core/include/stm32f0/stm32f030x6.h:841
   --  unsupported macro: ADC_CCR_TSEN_Msk (0x1UL << ADC_CCR_TSEN_Pos)
   --  unsupported macro: ADC_CCR_TSEN ADC_CCR_TSEN_Msk

   CRC_DR_DR_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:852
   --  unsupported macro: CRC_DR_DR_Msk (0xFFFFFFFFUL << CRC_DR_DR_Pos)
   --  unsupported macro: CRC_DR_DR CRC_DR_DR_Msk
   --  unsupported macro: CRC_IDR_IDR ((uint8_t)0xFFU)

   CRC_CR_RESET_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:860
   --  unsupported macro: CRC_CR_RESET_Msk (0x1UL << CRC_CR_RESET_Pos)
   --  unsupported macro: CRC_CR_RESET CRC_CR_RESET_Msk

   CRC_CR_REV_IN_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:863
   --  unsupported macro: CRC_CR_REV_IN_Msk (0x3UL << CRC_CR_REV_IN_Pos)
   --  unsupported macro: CRC_CR_REV_IN CRC_CR_REV_IN_Msk
   --  unsupported macro: CRC_CR_REV_IN_0 (0x1UL << CRC_CR_REV_IN_Pos)
   --  unsupported macro: CRC_CR_REV_IN_1 (0x2UL << CRC_CR_REV_IN_Pos)

   CRC_CR_REV_OUT_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:868
   --  unsupported macro: CRC_CR_REV_OUT_Msk (0x1UL << CRC_CR_REV_OUT_Pos)
   --  unsupported macro: CRC_CR_REV_OUT CRC_CR_REV_OUT_Msk

   CRC_INIT_INIT_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:873
   --  unsupported macro: CRC_INIT_INIT_Msk (0xFFFFFFFFUL << CRC_INIT_INIT_Pos)
   --  unsupported macro: CRC_INIT_INIT CRC_INIT_INIT_Msk

   DBGMCU_IDCODE_DEV_ID_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:884
   --  unsupported macro: DBGMCU_IDCODE_DEV_ID_Msk (0xFFFUL << DBGMCU_IDCODE_DEV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_DEV_ID DBGMCU_IDCODE_DEV_ID_Msk

   DBGMCU_IDCODE_REV_ID_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:888
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_Msk (0xFFFFUL << DBGMCU_IDCODE_REV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_REV_ID DBGMCU_IDCODE_REV_ID_Msk
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_0 (0x0001UL << DBGMCU_IDCODE_REV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_1 (0x0002UL << DBGMCU_IDCODE_REV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_2 (0x0004UL << DBGMCU_IDCODE_REV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_3 (0x0008UL << DBGMCU_IDCODE_REV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_4 (0x0010UL << DBGMCU_IDCODE_REV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_5 (0x0020UL << DBGMCU_IDCODE_REV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_6 (0x0040UL << DBGMCU_IDCODE_REV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_7 (0x0080UL << DBGMCU_IDCODE_REV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_8 (0x0100UL << DBGMCU_IDCODE_REV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_9 (0x0200UL << DBGMCU_IDCODE_REV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_10 (0x0400UL << DBGMCU_IDCODE_REV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_11 (0x0800UL << DBGMCU_IDCODE_REV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_12 (0x1000UL << DBGMCU_IDCODE_REV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_13 (0x2000UL << DBGMCU_IDCODE_REV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_14 (0x4000UL << DBGMCU_IDCODE_REV_ID_Pos)
   --  unsupported macro: DBGMCU_IDCODE_REV_ID_15 (0x8000UL << DBGMCU_IDCODE_REV_ID_Pos)

   DBGMCU_CR_DBG_STOP_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:909
   --  unsupported macro: DBGMCU_CR_DBG_STOP_Msk (0x1UL << DBGMCU_CR_DBG_STOP_Pos)
   --  unsupported macro: DBGMCU_CR_DBG_STOP DBGMCU_CR_DBG_STOP_Msk

   DBGMCU_CR_DBG_STANDBY_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:912
   --  unsupported macro: DBGMCU_CR_DBG_STANDBY_Msk (0x1UL << DBGMCU_CR_DBG_STANDBY_Pos)
   --  unsupported macro: DBGMCU_CR_DBG_STANDBY DBGMCU_CR_DBG_STANDBY_Msk

   DBGMCU_APB1_FZ_DBG_TIM3_STOP_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:917
   --  unsupported macro: DBGMCU_APB1_FZ_DBG_TIM3_STOP_Msk (0x1UL << DBGMCU_APB1_FZ_DBG_TIM3_STOP_Pos)
   --  unsupported macro: DBGMCU_APB1_FZ_DBG_TIM3_STOP DBGMCU_APB1_FZ_DBG_TIM3_STOP_Msk

   DBGMCU_APB1_FZ_DBG_TIM14_STOP_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:920
   --  unsupported macro: DBGMCU_APB1_FZ_DBG_TIM14_STOP_Msk (0x1UL << DBGMCU_APB1_FZ_DBG_TIM14_STOP_Pos)
   --  unsupported macro: DBGMCU_APB1_FZ_DBG_TIM14_STOP DBGMCU_APB1_FZ_DBG_TIM14_STOP_Msk

   DBGMCU_APB1_FZ_DBG_RTC_STOP_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:923
   --  unsupported macro: DBGMCU_APB1_FZ_DBG_RTC_STOP_Msk (0x1UL << DBGMCU_APB1_FZ_DBG_RTC_STOP_Pos)
   --  unsupported macro: DBGMCU_APB1_FZ_DBG_RTC_STOP DBGMCU_APB1_FZ_DBG_RTC_STOP_Msk

   DBGMCU_APB1_FZ_DBG_WWDG_STOP_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:926
   --  unsupported macro: DBGMCU_APB1_FZ_DBG_WWDG_STOP_Msk (0x1UL << DBGMCU_APB1_FZ_DBG_WWDG_STOP_Pos)
   --  unsupported macro: DBGMCU_APB1_FZ_DBG_WWDG_STOP DBGMCU_APB1_FZ_DBG_WWDG_STOP_Msk

   DBGMCU_APB1_FZ_DBG_IWDG_STOP_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:929
   --  unsupported macro: DBGMCU_APB1_FZ_DBG_IWDG_STOP_Msk (0x1UL << DBGMCU_APB1_FZ_DBG_IWDG_STOP_Pos)
   --  unsupported macro: DBGMCU_APB1_FZ_DBG_IWDG_STOP DBGMCU_APB1_FZ_DBG_IWDG_STOP_Msk

   DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Pos : constant := (21);  --  ../core/include/stm32f0/stm32f030x6.h:932
   --  unsupported macro: DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Msk (0x1UL << DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Pos)
   --  unsupported macro: DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Msk

   DBGMCU_APB2_FZ_DBG_TIM1_STOP_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:937
   --  unsupported macro: DBGMCU_APB2_FZ_DBG_TIM1_STOP_Msk (0x1UL << DBGMCU_APB2_FZ_DBG_TIM1_STOP_Pos)
   --  unsupported macro: DBGMCU_APB2_FZ_DBG_TIM1_STOP DBGMCU_APB2_FZ_DBG_TIM1_STOP_Msk

   DBGMCU_APB2_FZ_DBG_TIM16_STOP_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:940
   --  unsupported macro: DBGMCU_APB2_FZ_DBG_TIM16_STOP_Msk (0x1UL << DBGMCU_APB2_FZ_DBG_TIM16_STOP_Pos)
   --  unsupported macro: DBGMCU_APB2_FZ_DBG_TIM16_STOP DBGMCU_APB2_FZ_DBG_TIM16_STOP_Msk

   DBGMCU_APB2_FZ_DBG_TIM17_STOP_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:943
   --  unsupported macro: DBGMCU_APB2_FZ_DBG_TIM17_STOP_Msk (0x1UL << DBGMCU_APB2_FZ_DBG_TIM17_STOP_Pos)
   --  unsupported macro: DBGMCU_APB2_FZ_DBG_TIM17_STOP DBGMCU_APB2_FZ_DBG_TIM17_STOP_Msk

   DMA_ISR_GIF1_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:953
   --  unsupported macro: DMA_ISR_GIF1_Msk (0x1UL << DMA_ISR_GIF1_Pos)
   --  unsupported macro: DMA_ISR_GIF1 DMA_ISR_GIF1_Msk

   DMA_ISR_TCIF1_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:956
   --  unsupported macro: DMA_ISR_TCIF1_Msk (0x1UL << DMA_ISR_TCIF1_Pos)
   --  unsupported macro: DMA_ISR_TCIF1 DMA_ISR_TCIF1_Msk

   DMA_ISR_HTIF1_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:959
   --  unsupported macro: DMA_ISR_HTIF1_Msk (0x1UL << DMA_ISR_HTIF1_Pos)
   --  unsupported macro: DMA_ISR_HTIF1 DMA_ISR_HTIF1_Msk

   DMA_ISR_TEIF1_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:962
   --  unsupported macro: DMA_ISR_TEIF1_Msk (0x1UL << DMA_ISR_TEIF1_Pos)
   --  unsupported macro: DMA_ISR_TEIF1 DMA_ISR_TEIF1_Msk

   DMA_ISR_GIF2_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:965
   --  unsupported macro: DMA_ISR_GIF2_Msk (0x1UL << DMA_ISR_GIF2_Pos)
   --  unsupported macro: DMA_ISR_GIF2 DMA_ISR_GIF2_Msk

   DMA_ISR_TCIF2_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:968
   --  unsupported macro: DMA_ISR_TCIF2_Msk (0x1UL << DMA_ISR_TCIF2_Pos)
   --  unsupported macro: DMA_ISR_TCIF2 DMA_ISR_TCIF2_Msk

   DMA_ISR_HTIF2_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:971
   --  unsupported macro: DMA_ISR_HTIF2_Msk (0x1UL << DMA_ISR_HTIF2_Pos)
   --  unsupported macro: DMA_ISR_HTIF2 DMA_ISR_HTIF2_Msk

   DMA_ISR_TEIF2_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:974
   --  unsupported macro: DMA_ISR_TEIF2_Msk (0x1UL << DMA_ISR_TEIF2_Pos)
   --  unsupported macro: DMA_ISR_TEIF2 DMA_ISR_TEIF2_Msk

   DMA_ISR_GIF3_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:977
   --  unsupported macro: DMA_ISR_GIF3_Msk (0x1UL << DMA_ISR_GIF3_Pos)
   --  unsupported macro: DMA_ISR_GIF3 DMA_ISR_GIF3_Msk

   DMA_ISR_TCIF3_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:980
   --  unsupported macro: DMA_ISR_TCIF3_Msk (0x1UL << DMA_ISR_TCIF3_Pos)
   --  unsupported macro: DMA_ISR_TCIF3 DMA_ISR_TCIF3_Msk

   DMA_ISR_HTIF3_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:983
   --  unsupported macro: DMA_ISR_HTIF3_Msk (0x1UL << DMA_ISR_HTIF3_Pos)
   --  unsupported macro: DMA_ISR_HTIF3 DMA_ISR_HTIF3_Msk

   DMA_ISR_TEIF3_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:986
   --  unsupported macro: DMA_ISR_TEIF3_Msk (0x1UL << DMA_ISR_TEIF3_Pos)
   --  unsupported macro: DMA_ISR_TEIF3 DMA_ISR_TEIF3_Msk

   DMA_ISR_GIF4_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:989
   --  unsupported macro: DMA_ISR_GIF4_Msk (0x1UL << DMA_ISR_GIF4_Pos)
   --  unsupported macro: DMA_ISR_GIF4 DMA_ISR_GIF4_Msk

   DMA_ISR_TCIF4_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:992
   --  unsupported macro: DMA_ISR_TCIF4_Msk (0x1UL << DMA_ISR_TCIF4_Pos)
   --  unsupported macro: DMA_ISR_TCIF4 DMA_ISR_TCIF4_Msk

   DMA_ISR_HTIF4_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:995
   --  unsupported macro: DMA_ISR_HTIF4_Msk (0x1UL << DMA_ISR_HTIF4_Pos)
   --  unsupported macro: DMA_ISR_HTIF4 DMA_ISR_HTIF4_Msk

   DMA_ISR_TEIF4_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:998
   --  unsupported macro: DMA_ISR_TEIF4_Msk (0x1UL << DMA_ISR_TEIF4_Pos)
   --  unsupported macro: DMA_ISR_TEIF4 DMA_ISR_TEIF4_Msk

   DMA_ISR_GIF5_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:1001
   --  unsupported macro: DMA_ISR_GIF5_Msk (0x1UL << DMA_ISR_GIF5_Pos)
   --  unsupported macro: DMA_ISR_GIF5 DMA_ISR_GIF5_Msk

   DMA_ISR_TCIF5_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:1004
   --  unsupported macro: DMA_ISR_TCIF5_Msk (0x1UL << DMA_ISR_TCIF5_Pos)
   --  unsupported macro: DMA_ISR_TCIF5 DMA_ISR_TCIF5_Msk

   DMA_ISR_HTIF5_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:1007
   --  unsupported macro: DMA_ISR_HTIF5_Msk (0x1UL << DMA_ISR_HTIF5_Pos)
   --  unsupported macro: DMA_ISR_HTIF5 DMA_ISR_HTIF5_Msk

   DMA_ISR_TEIF5_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:1010
   --  unsupported macro: DMA_ISR_TEIF5_Msk (0x1UL << DMA_ISR_TEIF5_Pos)
   --  unsupported macro: DMA_ISR_TEIF5 DMA_ISR_TEIF5_Msk

   DMA_IFCR_CGIF1_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1015
   --  unsupported macro: DMA_IFCR_CGIF1_Msk (0x1UL << DMA_IFCR_CGIF1_Pos)
   --  unsupported macro: DMA_IFCR_CGIF1 DMA_IFCR_CGIF1_Msk

   DMA_IFCR_CTCIF1_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:1018
   --  unsupported macro: DMA_IFCR_CTCIF1_Msk (0x1UL << DMA_IFCR_CTCIF1_Pos)
   --  unsupported macro: DMA_IFCR_CTCIF1 DMA_IFCR_CTCIF1_Msk

   DMA_IFCR_CHTIF1_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:1021
   --  unsupported macro: DMA_IFCR_CHTIF1_Msk (0x1UL << DMA_IFCR_CHTIF1_Pos)
   --  unsupported macro: DMA_IFCR_CHTIF1 DMA_IFCR_CHTIF1_Msk

   DMA_IFCR_CTEIF1_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:1024
   --  unsupported macro: DMA_IFCR_CTEIF1_Msk (0x1UL << DMA_IFCR_CTEIF1_Pos)
   --  unsupported macro: DMA_IFCR_CTEIF1 DMA_IFCR_CTEIF1_Msk

   DMA_IFCR_CGIF2_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:1027
   --  unsupported macro: DMA_IFCR_CGIF2_Msk (0x1UL << DMA_IFCR_CGIF2_Pos)
   --  unsupported macro: DMA_IFCR_CGIF2 DMA_IFCR_CGIF2_Msk

   DMA_IFCR_CTCIF2_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:1030
   --  unsupported macro: DMA_IFCR_CTCIF2_Msk (0x1UL << DMA_IFCR_CTCIF2_Pos)
   --  unsupported macro: DMA_IFCR_CTCIF2 DMA_IFCR_CTCIF2_Msk

   DMA_IFCR_CHTIF2_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:1033
   --  unsupported macro: DMA_IFCR_CHTIF2_Msk (0x1UL << DMA_IFCR_CHTIF2_Pos)
   --  unsupported macro: DMA_IFCR_CHTIF2 DMA_IFCR_CHTIF2_Msk

   DMA_IFCR_CTEIF2_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:1036
   --  unsupported macro: DMA_IFCR_CTEIF2_Msk (0x1UL << DMA_IFCR_CTEIF2_Pos)
   --  unsupported macro: DMA_IFCR_CTEIF2 DMA_IFCR_CTEIF2_Msk

   DMA_IFCR_CGIF3_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:1039
   --  unsupported macro: DMA_IFCR_CGIF3_Msk (0x1UL << DMA_IFCR_CGIF3_Pos)
   --  unsupported macro: DMA_IFCR_CGIF3 DMA_IFCR_CGIF3_Msk

   DMA_IFCR_CTCIF3_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:1042
   --  unsupported macro: DMA_IFCR_CTCIF3_Msk (0x1UL << DMA_IFCR_CTCIF3_Pos)
   --  unsupported macro: DMA_IFCR_CTCIF3 DMA_IFCR_CTCIF3_Msk

   DMA_IFCR_CHTIF3_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:1045
   --  unsupported macro: DMA_IFCR_CHTIF3_Msk (0x1UL << DMA_IFCR_CHTIF3_Pos)
   --  unsupported macro: DMA_IFCR_CHTIF3 DMA_IFCR_CHTIF3_Msk

   DMA_IFCR_CTEIF3_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:1048
   --  unsupported macro: DMA_IFCR_CTEIF3_Msk (0x1UL << DMA_IFCR_CTEIF3_Pos)
   --  unsupported macro: DMA_IFCR_CTEIF3 DMA_IFCR_CTEIF3_Msk

   DMA_IFCR_CGIF4_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:1051
   --  unsupported macro: DMA_IFCR_CGIF4_Msk (0x1UL << DMA_IFCR_CGIF4_Pos)
   --  unsupported macro: DMA_IFCR_CGIF4 DMA_IFCR_CGIF4_Msk

   DMA_IFCR_CTCIF4_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:1054
   --  unsupported macro: DMA_IFCR_CTCIF4_Msk (0x1UL << DMA_IFCR_CTCIF4_Pos)
   --  unsupported macro: DMA_IFCR_CTCIF4 DMA_IFCR_CTCIF4_Msk

   DMA_IFCR_CHTIF4_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:1057
   --  unsupported macro: DMA_IFCR_CHTIF4_Msk (0x1UL << DMA_IFCR_CHTIF4_Pos)
   --  unsupported macro: DMA_IFCR_CHTIF4 DMA_IFCR_CHTIF4_Msk

   DMA_IFCR_CTEIF4_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:1060
   --  unsupported macro: DMA_IFCR_CTEIF4_Msk (0x1UL << DMA_IFCR_CTEIF4_Pos)
   --  unsupported macro: DMA_IFCR_CTEIF4 DMA_IFCR_CTEIF4_Msk

   DMA_IFCR_CGIF5_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:1063
   --  unsupported macro: DMA_IFCR_CGIF5_Msk (0x1UL << DMA_IFCR_CGIF5_Pos)
   --  unsupported macro: DMA_IFCR_CGIF5 DMA_IFCR_CGIF5_Msk

   DMA_IFCR_CTCIF5_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:1066
   --  unsupported macro: DMA_IFCR_CTCIF5_Msk (0x1UL << DMA_IFCR_CTCIF5_Pos)
   --  unsupported macro: DMA_IFCR_CTCIF5 DMA_IFCR_CTCIF5_Msk

   DMA_IFCR_CHTIF5_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:1069
   --  unsupported macro: DMA_IFCR_CHTIF5_Msk (0x1UL << DMA_IFCR_CHTIF5_Pos)
   --  unsupported macro: DMA_IFCR_CHTIF5 DMA_IFCR_CHTIF5_Msk

   DMA_IFCR_CTEIF5_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:1072
   --  unsupported macro: DMA_IFCR_CTEIF5_Msk (0x1UL << DMA_IFCR_CTEIF5_Pos)
   --  unsupported macro: DMA_IFCR_CTEIF5 DMA_IFCR_CTEIF5_Msk

   DMA_CCR_EN_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1077
   --  unsupported macro: DMA_CCR_EN_Msk (0x1UL << DMA_CCR_EN_Pos)
   --  unsupported macro: DMA_CCR_EN DMA_CCR_EN_Msk

   DMA_CCR_TCIE_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:1080
   --  unsupported macro: DMA_CCR_TCIE_Msk (0x1UL << DMA_CCR_TCIE_Pos)
   --  unsupported macro: DMA_CCR_TCIE DMA_CCR_TCIE_Msk

   DMA_CCR_HTIE_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:1083
   --  unsupported macro: DMA_CCR_HTIE_Msk (0x1UL << DMA_CCR_HTIE_Pos)
   --  unsupported macro: DMA_CCR_HTIE DMA_CCR_HTIE_Msk

   DMA_CCR_TEIE_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:1086
   --  unsupported macro: DMA_CCR_TEIE_Msk (0x1UL << DMA_CCR_TEIE_Pos)
   --  unsupported macro: DMA_CCR_TEIE DMA_CCR_TEIE_Msk

   DMA_CCR_DIR_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:1089
   --  unsupported macro: DMA_CCR_DIR_Msk (0x1UL << DMA_CCR_DIR_Pos)
   --  unsupported macro: DMA_CCR_DIR DMA_CCR_DIR_Msk

   DMA_CCR_CIRC_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:1092
   --  unsupported macro: DMA_CCR_CIRC_Msk (0x1UL << DMA_CCR_CIRC_Pos)
   --  unsupported macro: DMA_CCR_CIRC DMA_CCR_CIRC_Msk

   DMA_CCR_PINC_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:1095
   --  unsupported macro: DMA_CCR_PINC_Msk (0x1UL << DMA_CCR_PINC_Pos)
   --  unsupported macro: DMA_CCR_PINC DMA_CCR_PINC_Msk

   DMA_CCR_MINC_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:1098
   --  unsupported macro: DMA_CCR_MINC_Msk (0x1UL << DMA_CCR_MINC_Pos)
   --  unsupported macro: DMA_CCR_MINC DMA_CCR_MINC_Msk

   DMA_CCR_PSIZE_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:1102
   --  unsupported macro: DMA_CCR_PSIZE_Msk (0x3UL << DMA_CCR_PSIZE_Pos)
   --  unsupported macro: DMA_CCR_PSIZE DMA_CCR_PSIZE_Msk
   --  unsupported macro: DMA_CCR_PSIZE_0 (0x1UL << DMA_CCR_PSIZE_Pos)
   --  unsupported macro: DMA_CCR_PSIZE_1 (0x2UL << DMA_CCR_PSIZE_Pos)

   DMA_CCR_MSIZE_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:1108
   --  unsupported macro: DMA_CCR_MSIZE_Msk (0x3UL << DMA_CCR_MSIZE_Pos)
   --  unsupported macro: DMA_CCR_MSIZE DMA_CCR_MSIZE_Msk
   --  unsupported macro: DMA_CCR_MSIZE_0 (0x1UL << DMA_CCR_MSIZE_Pos)
   --  unsupported macro: DMA_CCR_MSIZE_1 (0x2UL << DMA_CCR_MSIZE_Pos)

   DMA_CCR_PL_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:1114
   --  unsupported macro: DMA_CCR_PL_Msk (0x3UL << DMA_CCR_PL_Pos)
   --  unsupported macro: DMA_CCR_PL DMA_CCR_PL_Msk
   --  unsupported macro: DMA_CCR_PL_0 (0x1UL << DMA_CCR_PL_Pos)
   --  unsupported macro: DMA_CCR_PL_1 (0x2UL << DMA_CCR_PL_Pos)

   DMA_CCR_MEM2MEM_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:1120
   --  unsupported macro: DMA_CCR_MEM2MEM_Msk (0x1UL << DMA_CCR_MEM2MEM_Pos)
   --  unsupported macro: DMA_CCR_MEM2MEM DMA_CCR_MEM2MEM_Msk

   DMA_CNDTR_NDT_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1125
   --  unsupported macro: DMA_CNDTR_NDT_Msk (0xFFFFUL << DMA_CNDTR_NDT_Pos)
   --  unsupported macro: DMA_CNDTR_NDT DMA_CNDTR_NDT_Msk

   DMA_CPAR_PA_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1130
   --  unsupported macro: DMA_CPAR_PA_Msk (0xFFFFFFFFUL << DMA_CPAR_PA_Pos)
   --  unsupported macro: DMA_CPAR_PA DMA_CPAR_PA_Msk

   DMA_CMAR_MA_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1135
   --  unsupported macro: DMA_CMAR_MA_Msk (0xFFFFFFFFUL << DMA_CMAR_MA_Pos)
   --  unsupported macro: DMA_CMAR_MA DMA_CMAR_MA_Msk

   EXTI_IMR_MR0_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1145
   --  unsupported macro: EXTI_IMR_MR0_Msk (0x1UL << EXTI_IMR_MR0_Pos)
   --  unsupported macro: EXTI_IMR_MR0 EXTI_IMR_MR0_Msk

   EXTI_IMR_MR1_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:1148
   --  unsupported macro: EXTI_IMR_MR1_Msk (0x1UL << EXTI_IMR_MR1_Pos)
   --  unsupported macro: EXTI_IMR_MR1 EXTI_IMR_MR1_Msk

   EXTI_IMR_MR2_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:1151
   --  unsupported macro: EXTI_IMR_MR2_Msk (0x1UL << EXTI_IMR_MR2_Pos)
   --  unsupported macro: EXTI_IMR_MR2 EXTI_IMR_MR2_Msk

   EXTI_IMR_MR3_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:1154
   --  unsupported macro: EXTI_IMR_MR3_Msk (0x1UL << EXTI_IMR_MR3_Pos)
   --  unsupported macro: EXTI_IMR_MR3 EXTI_IMR_MR3_Msk

   EXTI_IMR_MR4_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:1157
   --  unsupported macro: EXTI_IMR_MR4_Msk (0x1UL << EXTI_IMR_MR4_Pos)
   --  unsupported macro: EXTI_IMR_MR4 EXTI_IMR_MR4_Msk

   EXTI_IMR_MR5_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:1160
   --  unsupported macro: EXTI_IMR_MR5_Msk (0x1UL << EXTI_IMR_MR5_Pos)
   --  unsupported macro: EXTI_IMR_MR5 EXTI_IMR_MR5_Msk

   EXTI_IMR_MR6_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:1163
   --  unsupported macro: EXTI_IMR_MR6_Msk (0x1UL << EXTI_IMR_MR6_Pos)
   --  unsupported macro: EXTI_IMR_MR6 EXTI_IMR_MR6_Msk

   EXTI_IMR_MR7_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:1166
   --  unsupported macro: EXTI_IMR_MR7_Msk (0x1UL << EXTI_IMR_MR7_Pos)
   --  unsupported macro: EXTI_IMR_MR7 EXTI_IMR_MR7_Msk

   EXTI_IMR_MR8_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:1169
   --  unsupported macro: EXTI_IMR_MR8_Msk (0x1UL << EXTI_IMR_MR8_Pos)
   --  unsupported macro: EXTI_IMR_MR8 EXTI_IMR_MR8_Msk

   EXTI_IMR_MR9_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:1172
   --  unsupported macro: EXTI_IMR_MR9_Msk (0x1UL << EXTI_IMR_MR9_Pos)
   --  unsupported macro: EXTI_IMR_MR9 EXTI_IMR_MR9_Msk

   EXTI_IMR_MR10_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:1175
   --  unsupported macro: EXTI_IMR_MR10_Msk (0x1UL << EXTI_IMR_MR10_Pos)
   --  unsupported macro: EXTI_IMR_MR10 EXTI_IMR_MR10_Msk

   EXTI_IMR_MR11_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:1178
   --  unsupported macro: EXTI_IMR_MR11_Msk (0x1UL << EXTI_IMR_MR11_Pos)
   --  unsupported macro: EXTI_IMR_MR11 EXTI_IMR_MR11_Msk

   EXTI_IMR_MR12_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:1181
   --  unsupported macro: EXTI_IMR_MR12_Msk (0x1UL << EXTI_IMR_MR12_Pos)
   --  unsupported macro: EXTI_IMR_MR12 EXTI_IMR_MR12_Msk

   EXTI_IMR_MR13_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:1184
   --  unsupported macro: EXTI_IMR_MR13_Msk (0x1UL << EXTI_IMR_MR13_Pos)
   --  unsupported macro: EXTI_IMR_MR13 EXTI_IMR_MR13_Msk

   EXTI_IMR_MR14_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:1187
   --  unsupported macro: EXTI_IMR_MR14_Msk (0x1UL << EXTI_IMR_MR14_Pos)
   --  unsupported macro: EXTI_IMR_MR14 EXTI_IMR_MR14_Msk

   EXTI_IMR_MR15_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:1190
   --  unsupported macro: EXTI_IMR_MR15_Msk (0x1UL << EXTI_IMR_MR15_Pos)
   --  unsupported macro: EXTI_IMR_MR15 EXTI_IMR_MR15_Msk

   EXTI_IMR_MR17_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:1193
   --  unsupported macro: EXTI_IMR_MR17_Msk (0x1UL << EXTI_IMR_MR17_Pos)
   --  unsupported macro: EXTI_IMR_MR17 EXTI_IMR_MR17_Msk

   EXTI_IMR_MR19_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:1196
   --  unsupported macro: EXTI_IMR_MR19_Msk (0x1UL << EXTI_IMR_MR19_Pos)
   --  unsupported macro: EXTI_IMR_MR19 EXTI_IMR_MR19_Msk
   --  unsupported macro: EXTI_IMR_IM0 EXTI_IMR_MR0
   --  unsupported macro: EXTI_IMR_IM1 EXTI_IMR_MR1
   --  unsupported macro: EXTI_IMR_IM2 EXTI_IMR_MR2
   --  unsupported macro: EXTI_IMR_IM3 EXTI_IMR_MR3
   --  unsupported macro: EXTI_IMR_IM4 EXTI_IMR_MR4
   --  unsupported macro: EXTI_IMR_IM5 EXTI_IMR_MR5
   --  unsupported macro: EXTI_IMR_IM6 EXTI_IMR_MR6
   --  unsupported macro: EXTI_IMR_IM7 EXTI_IMR_MR7
   --  unsupported macro: EXTI_IMR_IM8 EXTI_IMR_MR8
   --  unsupported macro: EXTI_IMR_IM9 EXTI_IMR_MR9
   --  unsupported macro: EXTI_IMR_IM10 EXTI_IMR_MR10
   --  unsupported macro: EXTI_IMR_IM11 EXTI_IMR_MR11
   --  unsupported macro: EXTI_IMR_IM12 EXTI_IMR_MR12
   --  unsupported macro: EXTI_IMR_IM13 EXTI_IMR_MR13
   --  unsupported macro: EXTI_IMR_IM14 EXTI_IMR_MR14
   --  unsupported macro: EXTI_IMR_IM15 EXTI_IMR_MR15
   --  unsupported macro: EXTI_IMR_IM17 EXTI_IMR_MR17
   --  unsupported macro: EXTI_IMR_IM19 EXTI_IMR_MR19

   EXTI_IMR_IM_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1220
   --  unsupported macro: EXTI_IMR_IM_Msk (0x8EFFFFUL << EXTI_IMR_IM_Pos)
   --  unsupported macro: EXTI_IMR_IM EXTI_IMR_IM_Msk

   EXTI_EMR_MR0_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1226
   --  unsupported macro: EXTI_EMR_MR0_Msk (0x1UL << EXTI_EMR_MR0_Pos)
   --  unsupported macro: EXTI_EMR_MR0 EXTI_EMR_MR0_Msk

   EXTI_EMR_MR1_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:1229
   --  unsupported macro: EXTI_EMR_MR1_Msk (0x1UL << EXTI_EMR_MR1_Pos)
   --  unsupported macro: EXTI_EMR_MR1 EXTI_EMR_MR1_Msk

   EXTI_EMR_MR2_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:1232
   --  unsupported macro: EXTI_EMR_MR2_Msk (0x1UL << EXTI_EMR_MR2_Pos)
   --  unsupported macro: EXTI_EMR_MR2 EXTI_EMR_MR2_Msk

   EXTI_EMR_MR3_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:1235
   --  unsupported macro: EXTI_EMR_MR3_Msk (0x1UL << EXTI_EMR_MR3_Pos)
   --  unsupported macro: EXTI_EMR_MR3 EXTI_EMR_MR3_Msk

   EXTI_EMR_MR4_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:1238
   --  unsupported macro: EXTI_EMR_MR4_Msk (0x1UL << EXTI_EMR_MR4_Pos)
   --  unsupported macro: EXTI_EMR_MR4 EXTI_EMR_MR4_Msk

   EXTI_EMR_MR5_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:1241
   --  unsupported macro: EXTI_EMR_MR5_Msk (0x1UL << EXTI_EMR_MR5_Pos)
   --  unsupported macro: EXTI_EMR_MR5 EXTI_EMR_MR5_Msk

   EXTI_EMR_MR6_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:1244
   --  unsupported macro: EXTI_EMR_MR6_Msk (0x1UL << EXTI_EMR_MR6_Pos)
   --  unsupported macro: EXTI_EMR_MR6 EXTI_EMR_MR6_Msk

   EXTI_EMR_MR7_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:1247
   --  unsupported macro: EXTI_EMR_MR7_Msk (0x1UL << EXTI_EMR_MR7_Pos)
   --  unsupported macro: EXTI_EMR_MR7 EXTI_EMR_MR7_Msk

   EXTI_EMR_MR8_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:1250
   --  unsupported macro: EXTI_EMR_MR8_Msk (0x1UL << EXTI_EMR_MR8_Pos)
   --  unsupported macro: EXTI_EMR_MR8 EXTI_EMR_MR8_Msk

   EXTI_EMR_MR9_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:1253
   --  unsupported macro: EXTI_EMR_MR9_Msk (0x1UL << EXTI_EMR_MR9_Pos)
   --  unsupported macro: EXTI_EMR_MR9 EXTI_EMR_MR9_Msk

   EXTI_EMR_MR10_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:1256
   --  unsupported macro: EXTI_EMR_MR10_Msk (0x1UL << EXTI_EMR_MR10_Pos)
   --  unsupported macro: EXTI_EMR_MR10 EXTI_EMR_MR10_Msk

   EXTI_EMR_MR11_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:1259
   --  unsupported macro: EXTI_EMR_MR11_Msk (0x1UL << EXTI_EMR_MR11_Pos)
   --  unsupported macro: EXTI_EMR_MR11 EXTI_EMR_MR11_Msk

   EXTI_EMR_MR12_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:1262
   --  unsupported macro: EXTI_EMR_MR12_Msk (0x1UL << EXTI_EMR_MR12_Pos)
   --  unsupported macro: EXTI_EMR_MR12 EXTI_EMR_MR12_Msk

   EXTI_EMR_MR13_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:1265
   --  unsupported macro: EXTI_EMR_MR13_Msk (0x1UL << EXTI_EMR_MR13_Pos)
   --  unsupported macro: EXTI_EMR_MR13 EXTI_EMR_MR13_Msk

   EXTI_EMR_MR14_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:1268
   --  unsupported macro: EXTI_EMR_MR14_Msk (0x1UL << EXTI_EMR_MR14_Pos)
   --  unsupported macro: EXTI_EMR_MR14 EXTI_EMR_MR14_Msk

   EXTI_EMR_MR15_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:1271
   --  unsupported macro: EXTI_EMR_MR15_Msk (0x1UL << EXTI_EMR_MR15_Pos)
   --  unsupported macro: EXTI_EMR_MR15 EXTI_EMR_MR15_Msk

   EXTI_EMR_MR17_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:1274
   --  unsupported macro: EXTI_EMR_MR17_Msk (0x1UL << EXTI_EMR_MR17_Pos)
   --  unsupported macro: EXTI_EMR_MR17 EXTI_EMR_MR17_Msk

   EXTI_EMR_MR19_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:1277
   --  unsupported macro: EXTI_EMR_MR19_Msk (0x1UL << EXTI_EMR_MR19_Pos)
   --  unsupported macro: EXTI_EMR_MR19 EXTI_EMR_MR19_Msk
   --  unsupported macro: EXTI_EMR_EM0 EXTI_EMR_MR0
   --  unsupported macro: EXTI_EMR_EM1 EXTI_EMR_MR1
   --  unsupported macro: EXTI_EMR_EM2 EXTI_EMR_MR2
   --  unsupported macro: EXTI_EMR_EM3 EXTI_EMR_MR3
   --  unsupported macro: EXTI_EMR_EM4 EXTI_EMR_MR4
   --  unsupported macro: EXTI_EMR_EM5 EXTI_EMR_MR5
   --  unsupported macro: EXTI_EMR_EM6 EXTI_EMR_MR6
   --  unsupported macro: EXTI_EMR_EM7 EXTI_EMR_MR7
   --  unsupported macro: EXTI_EMR_EM8 EXTI_EMR_MR8
   --  unsupported macro: EXTI_EMR_EM9 EXTI_EMR_MR9
   --  unsupported macro: EXTI_EMR_EM10 EXTI_EMR_MR10
   --  unsupported macro: EXTI_EMR_EM11 EXTI_EMR_MR11
   --  unsupported macro: EXTI_EMR_EM12 EXTI_EMR_MR12
   --  unsupported macro: EXTI_EMR_EM13 EXTI_EMR_MR13
   --  unsupported macro: EXTI_EMR_EM14 EXTI_EMR_MR14
   --  unsupported macro: EXTI_EMR_EM15 EXTI_EMR_MR15
   --  unsupported macro: EXTI_EMR_EM17 EXTI_EMR_MR17
   --  unsupported macro: EXTI_EMR_EM19 EXTI_EMR_MR19

   EXTI_RTSR_TR0_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1302
   --  unsupported macro: EXTI_RTSR_TR0_Msk (0x1UL << EXTI_RTSR_TR0_Pos)
   --  unsupported macro: EXTI_RTSR_TR0 EXTI_RTSR_TR0_Msk

   EXTI_RTSR_TR1_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:1305
   --  unsupported macro: EXTI_RTSR_TR1_Msk (0x1UL << EXTI_RTSR_TR1_Pos)
   --  unsupported macro: EXTI_RTSR_TR1 EXTI_RTSR_TR1_Msk

   EXTI_RTSR_TR2_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:1308
   --  unsupported macro: EXTI_RTSR_TR2_Msk (0x1UL << EXTI_RTSR_TR2_Pos)
   --  unsupported macro: EXTI_RTSR_TR2 EXTI_RTSR_TR2_Msk

   EXTI_RTSR_TR3_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:1311
   --  unsupported macro: EXTI_RTSR_TR3_Msk (0x1UL << EXTI_RTSR_TR3_Pos)
   --  unsupported macro: EXTI_RTSR_TR3 EXTI_RTSR_TR3_Msk

   EXTI_RTSR_TR4_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:1314
   --  unsupported macro: EXTI_RTSR_TR4_Msk (0x1UL << EXTI_RTSR_TR4_Pos)
   --  unsupported macro: EXTI_RTSR_TR4 EXTI_RTSR_TR4_Msk

   EXTI_RTSR_TR5_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:1317
   --  unsupported macro: EXTI_RTSR_TR5_Msk (0x1UL << EXTI_RTSR_TR5_Pos)
   --  unsupported macro: EXTI_RTSR_TR5 EXTI_RTSR_TR5_Msk

   EXTI_RTSR_TR6_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:1320
   --  unsupported macro: EXTI_RTSR_TR6_Msk (0x1UL << EXTI_RTSR_TR6_Pos)
   --  unsupported macro: EXTI_RTSR_TR6 EXTI_RTSR_TR6_Msk

   EXTI_RTSR_TR7_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:1323
   --  unsupported macro: EXTI_RTSR_TR7_Msk (0x1UL << EXTI_RTSR_TR7_Pos)
   --  unsupported macro: EXTI_RTSR_TR7 EXTI_RTSR_TR7_Msk

   EXTI_RTSR_TR8_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:1326
   --  unsupported macro: EXTI_RTSR_TR8_Msk (0x1UL << EXTI_RTSR_TR8_Pos)
   --  unsupported macro: EXTI_RTSR_TR8 EXTI_RTSR_TR8_Msk

   EXTI_RTSR_TR9_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:1329
   --  unsupported macro: EXTI_RTSR_TR9_Msk (0x1UL << EXTI_RTSR_TR9_Pos)
   --  unsupported macro: EXTI_RTSR_TR9 EXTI_RTSR_TR9_Msk

   EXTI_RTSR_TR10_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:1332
   --  unsupported macro: EXTI_RTSR_TR10_Msk (0x1UL << EXTI_RTSR_TR10_Pos)
   --  unsupported macro: EXTI_RTSR_TR10 EXTI_RTSR_TR10_Msk

   EXTI_RTSR_TR11_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:1335
   --  unsupported macro: EXTI_RTSR_TR11_Msk (0x1UL << EXTI_RTSR_TR11_Pos)
   --  unsupported macro: EXTI_RTSR_TR11 EXTI_RTSR_TR11_Msk

   EXTI_RTSR_TR12_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:1338
   --  unsupported macro: EXTI_RTSR_TR12_Msk (0x1UL << EXTI_RTSR_TR12_Pos)
   --  unsupported macro: EXTI_RTSR_TR12 EXTI_RTSR_TR12_Msk

   EXTI_RTSR_TR13_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:1341
   --  unsupported macro: EXTI_RTSR_TR13_Msk (0x1UL << EXTI_RTSR_TR13_Pos)
   --  unsupported macro: EXTI_RTSR_TR13 EXTI_RTSR_TR13_Msk

   EXTI_RTSR_TR14_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:1344
   --  unsupported macro: EXTI_RTSR_TR14_Msk (0x1UL << EXTI_RTSR_TR14_Pos)
   --  unsupported macro: EXTI_RTSR_TR14 EXTI_RTSR_TR14_Msk

   EXTI_RTSR_TR15_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:1347
   --  unsupported macro: EXTI_RTSR_TR15_Msk (0x1UL << EXTI_RTSR_TR15_Pos)
   --  unsupported macro: EXTI_RTSR_TR15 EXTI_RTSR_TR15_Msk

   EXTI_RTSR_TR16_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:1350
   --  unsupported macro: EXTI_RTSR_TR16_Msk (0x1UL << EXTI_RTSR_TR16_Pos)
   --  unsupported macro: EXTI_RTSR_TR16 EXTI_RTSR_TR16_Msk

   EXTI_RTSR_TR17_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:1353
   --  unsupported macro: EXTI_RTSR_TR17_Msk (0x1UL << EXTI_RTSR_TR17_Pos)
   --  unsupported macro: EXTI_RTSR_TR17 EXTI_RTSR_TR17_Msk

   EXTI_RTSR_TR19_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:1356
   --  unsupported macro: EXTI_RTSR_TR19_Msk (0x1UL << EXTI_RTSR_TR19_Pos)
   --  unsupported macro: EXTI_RTSR_TR19 EXTI_RTSR_TR19_Msk
   --  unsupported macro: EXTI_RTSR_RT0 EXTI_RTSR_TR0
   --  unsupported macro: EXTI_RTSR_RT1 EXTI_RTSR_TR1
   --  unsupported macro: EXTI_RTSR_RT2 EXTI_RTSR_TR2
   --  unsupported macro: EXTI_RTSR_RT3 EXTI_RTSR_TR3
   --  unsupported macro: EXTI_RTSR_RT4 EXTI_RTSR_TR4
   --  unsupported macro: EXTI_RTSR_RT5 EXTI_RTSR_TR5
   --  unsupported macro: EXTI_RTSR_RT6 EXTI_RTSR_TR6
   --  unsupported macro: EXTI_RTSR_RT7 EXTI_RTSR_TR7
   --  unsupported macro: EXTI_RTSR_RT8 EXTI_RTSR_TR8
   --  unsupported macro: EXTI_RTSR_RT9 EXTI_RTSR_TR9
   --  unsupported macro: EXTI_RTSR_RT10 EXTI_RTSR_TR10
   --  unsupported macro: EXTI_RTSR_RT11 EXTI_RTSR_TR11
   --  unsupported macro: EXTI_RTSR_RT12 EXTI_RTSR_TR12
   --  unsupported macro: EXTI_RTSR_RT13 EXTI_RTSR_TR13
   --  unsupported macro: EXTI_RTSR_RT14 EXTI_RTSR_TR14
   --  unsupported macro: EXTI_RTSR_RT15 EXTI_RTSR_TR15
   --  unsupported macro: EXTI_RTSR_RT16 EXTI_RTSR_TR16
   --  unsupported macro: EXTI_RTSR_RT17 EXTI_RTSR_TR17
   --  unsupported macro: EXTI_RTSR_RT19 EXTI_RTSR_TR19

   EXTI_FTSR_TR0_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1382
   --  unsupported macro: EXTI_FTSR_TR0_Msk (0x1UL << EXTI_FTSR_TR0_Pos)
   --  unsupported macro: EXTI_FTSR_TR0 EXTI_FTSR_TR0_Msk

   EXTI_FTSR_TR1_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:1385
   --  unsupported macro: EXTI_FTSR_TR1_Msk (0x1UL << EXTI_FTSR_TR1_Pos)
   --  unsupported macro: EXTI_FTSR_TR1 EXTI_FTSR_TR1_Msk

   EXTI_FTSR_TR2_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:1388
   --  unsupported macro: EXTI_FTSR_TR2_Msk (0x1UL << EXTI_FTSR_TR2_Pos)
   --  unsupported macro: EXTI_FTSR_TR2 EXTI_FTSR_TR2_Msk

   EXTI_FTSR_TR3_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:1391
   --  unsupported macro: EXTI_FTSR_TR3_Msk (0x1UL << EXTI_FTSR_TR3_Pos)
   --  unsupported macro: EXTI_FTSR_TR3 EXTI_FTSR_TR3_Msk

   EXTI_FTSR_TR4_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:1394
   --  unsupported macro: EXTI_FTSR_TR4_Msk (0x1UL << EXTI_FTSR_TR4_Pos)
   --  unsupported macro: EXTI_FTSR_TR4 EXTI_FTSR_TR4_Msk

   EXTI_FTSR_TR5_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:1397
   --  unsupported macro: EXTI_FTSR_TR5_Msk (0x1UL << EXTI_FTSR_TR5_Pos)
   --  unsupported macro: EXTI_FTSR_TR5 EXTI_FTSR_TR5_Msk

   EXTI_FTSR_TR6_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:1400
   --  unsupported macro: EXTI_FTSR_TR6_Msk (0x1UL << EXTI_FTSR_TR6_Pos)
   --  unsupported macro: EXTI_FTSR_TR6 EXTI_FTSR_TR6_Msk

   EXTI_FTSR_TR7_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:1403
   --  unsupported macro: EXTI_FTSR_TR7_Msk (0x1UL << EXTI_FTSR_TR7_Pos)
   --  unsupported macro: EXTI_FTSR_TR7 EXTI_FTSR_TR7_Msk

   EXTI_FTSR_TR8_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:1406
   --  unsupported macro: EXTI_FTSR_TR8_Msk (0x1UL << EXTI_FTSR_TR8_Pos)
   --  unsupported macro: EXTI_FTSR_TR8 EXTI_FTSR_TR8_Msk

   EXTI_FTSR_TR9_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:1409
   --  unsupported macro: EXTI_FTSR_TR9_Msk (0x1UL << EXTI_FTSR_TR9_Pos)
   --  unsupported macro: EXTI_FTSR_TR9 EXTI_FTSR_TR9_Msk

   EXTI_FTSR_TR10_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:1412
   --  unsupported macro: EXTI_FTSR_TR10_Msk (0x1UL << EXTI_FTSR_TR10_Pos)
   --  unsupported macro: EXTI_FTSR_TR10 EXTI_FTSR_TR10_Msk

   EXTI_FTSR_TR11_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:1415
   --  unsupported macro: EXTI_FTSR_TR11_Msk (0x1UL << EXTI_FTSR_TR11_Pos)
   --  unsupported macro: EXTI_FTSR_TR11 EXTI_FTSR_TR11_Msk

   EXTI_FTSR_TR12_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:1418
   --  unsupported macro: EXTI_FTSR_TR12_Msk (0x1UL << EXTI_FTSR_TR12_Pos)
   --  unsupported macro: EXTI_FTSR_TR12 EXTI_FTSR_TR12_Msk

   EXTI_FTSR_TR13_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:1421
   --  unsupported macro: EXTI_FTSR_TR13_Msk (0x1UL << EXTI_FTSR_TR13_Pos)
   --  unsupported macro: EXTI_FTSR_TR13 EXTI_FTSR_TR13_Msk

   EXTI_FTSR_TR14_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:1424
   --  unsupported macro: EXTI_FTSR_TR14_Msk (0x1UL << EXTI_FTSR_TR14_Pos)
   --  unsupported macro: EXTI_FTSR_TR14 EXTI_FTSR_TR14_Msk

   EXTI_FTSR_TR15_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:1427
   --  unsupported macro: EXTI_FTSR_TR15_Msk (0x1UL << EXTI_FTSR_TR15_Pos)
   --  unsupported macro: EXTI_FTSR_TR15 EXTI_FTSR_TR15_Msk

   EXTI_FTSR_TR16_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:1430
   --  unsupported macro: EXTI_FTSR_TR16_Msk (0x1UL << EXTI_FTSR_TR16_Pos)
   --  unsupported macro: EXTI_FTSR_TR16 EXTI_FTSR_TR16_Msk

   EXTI_FTSR_TR17_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:1433
   --  unsupported macro: EXTI_FTSR_TR17_Msk (0x1UL << EXTI_FTSR_TR17_Pos)
   --  unsupported macro: EXTI_FTSR_TR17 EXTI_FTSR_TR17_Msk

   EXTI_FTSR_TR19_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:1436
   --  unsupported macro: EXTI_FTSR_TR19_Msk (0x1UL << EXTI_FTSR_TR19_Pos)
   --  unsupported macro: EXTI_FTSR_TR19 EXTI_FTSR_TR19_Msk
   --  unsupported macro: EXTI_FTSR_FT0 EXTI_FTSR_TR0
   --  unsupported macro: EXTI_FTSR_FT1 EXTI_FTSR_TR1
   --  unsupported macro: EXTI_FTSR_FT2 EXTI_FTSR_TR2
   --  unsupported macro: EXTI_FTSR_FT3 EXTI_FTSR_TR3
   --  unsupported macro: EXTI_FTSR_FT4 EXTI_FTSR_TR4
   --  unsupported macro: EXTI_FTSR_FT5 EXTI_FTSR_TR5
   --  unsupported macro: EXTI_FTSR_FT6 EXTI_FTSR_TR6
   --  unsupported macro: EXTI_FTSR_FT7 EXTI_FTSR_TR7
   --  unsupported macro: EXTI_FTSR_FT8 EXTI_FTSR_TR8
   --  unsupported macro: EXTI_FTSR_FT9 EXTI_FTSR_TR9
   --  unsupported macro: EXTI_FTSR_FT10 EXTI_FTSR_TR10
   --  unsupported macro: EXTI_FTSR_FT11 EXTI_FTSR_TR11
   --  unsupported macro: EXTI_FTSR_FT12 EXTI_FTSR_TR12
   --  unsupported macro: EXTI_FTSR_FT13 EXTI_FTSR_TR13
   --  unsupported macro: EXTI_FTSR_FT14 EXTI_FTSR_TR14
   --  unsupported macro: EXTI_FTSR_FT15 EXTI_FTSR_TR15
   --  unsupported macro: EXTI_FTSR_FT16 EXTI_FTSR_TR16
   --  unsupported macro: EXTI_FTSR_FT17 EXTI_FTSR_TR17
   --  unsupported macro: EXTI_FTSR_FT19 EXTI_FTSR_TR19

   EXTI_SWIER_SWIER0_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1462
   --  unsupported macro: EXTI_SWIER_SWIER0_Msk (0x1UL << EXTI_SWIER_SWIER0_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER0 EXTI_SWIER_SWIER0_Msk

   EXTI_SWIER_SWIER1_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:1465
   --  unsupported macro: EXTI_SWIER_SWIER1_Msk (0x1UL << EXTI_SWIER_SWIER1_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER1 EXTI_SWIER_SWIER1_Msk

   EXTI_SWIER_SWIER2_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:1468
   --  unsupported macro: EXTI_SWIER_SWIER2_Msk (0x1UL << EXTI_SWIER_SWIER2_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER2 EXTI_SWIER_SWIER2_Msk

   EXTI_SWIER_SWIER3_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:1471
   --  unsupported macro: EXTI_SWIER_SWIER3_Msk (0x1UL << EXTI_SWIER_SWIER3_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER3 EXTI_SWIER_SWIER3_Msk

   EXTI_SWIER_SWIER4_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:1474
   --  unsupported macro: EXTI_SWIER_SWIER4_Msk (0x1UL << EXTI_SWIER_SWIER4_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER4 EXTI_SWIER_SWIER4_Msk

   EXTI_SWIER_SWIER5_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:1477
   --  unsupported macro: EXTI_SWIER_SWIER5_Msk (0x1UL << EXTI_SWIER_SWIER5_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER5 EXTI_SWIER_SWIER5_Msk

   EXTI_SWIER_SWIER6_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:1480
   --  unsupported macro: EXTI_SWIER_SWIER6_Msk (0x1UL << EXTI_SWIER_SWIER6_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER6 EXTI_SWIER_SWIER6_Msk

   EXTI_SWIER_SWIER7_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:1483
   --  unsupported macro: EXTI_SWIER_SWIER7_Msk (0x1UL << EXTI_SWIER_SWIER7_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER7 EXTI_SWIER_SWIER7_Msk

   EXTI_SWIER_SWIER8_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:1486
   --  unsupported macro: EXTI_SWIER_SWIER8_Msk (0x1UL << EXTI_SWIER_SWIER8_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER8 EXTI_SWIER_SWIER8_Msk

   EXTI_SWIER_SWIER9_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:1489
   --  unsupported macro: EXTI_SWIER_SWIER9_Msk (0x1UL << EXTI_SWIER_SWIER9_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER9 EXTI_SWIER_SWIER9_Msk

   EXTI_SWIER_SWIER10_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:1492
   --  unsupported macro: EXTI_SWIER_SWIER10_Msk (0x1UL << EXTI_SWIER_SWIER10_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER10 EXTI_SWIER_SWIER10_Msk

   EXTI_SWIER_SWIER11_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:1495
   --  unsupported macro: EXTI_SWIER_SWIER11_Msk (0x1UL << EXTI_SWIER_SWIER11_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER11 EXTI_SWIER_SWIER11_Msk

   EXTI_SWIER_SWIER12_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:1498
   --  unsupported macro: EXTI_SWIER_SWIER12_Msk (0x1UL << EXTI_SWIER_SWIER12_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER12 EXTI_SWIER_SWIER12_Msk

   EXTI_SWIER_SWIER13_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:1501
   --  unsupported macro: EXTI_SWIER_SWIER13_Msk (0x1UL << EXTI_SWIER_SWIER13_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER13 EXTI_SWIER_SWIER13_Msk

   EXTI_SWIER_SWIER14_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:1504
   --  unsupported macro: EXTI_SWIER_SWIER14_Msk (0x1UL << EXTI_SWIER_SWIER14_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER14 EXTI_SWIER_SWIER14_Msk

   EXTI_SWIER_SWIER15_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:1507
   --  unsupported macro: EXTI_SWIER_SWIER15_Msk (0x1UL << EXTI_SWIER_SWIER15_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER15 EXTI_SWIER_SWIER15_Msk

   EXTI_SWIER_SWIER16_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:1510
   --  unsupported macro: EXTI_SWIER_SWIER16_Msk (0x1UL << EXTI_SWIER_SWIER16_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER16 EXTI_SWIER_SWIER16_Msk

   EXTI_SWIER_SWIER17_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:1513
   --  unsupported macro: EXTI_SWIER_SWIER17_Msk (0x1UL << EXTI_SWIER_SWIER17_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER17 EXTI_SWIER_SWIER17_Msk

   EXTI_SWIER_SWIER19_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:1516
   --  unsupported macro: EXTI_SWIER_SWIER19_Msk (0x1UL << EXTI_SWIER_SWIER19_Pos)
   --  unsupported macro: EXTI_SWIER_SWIER19 EXTI_SWIER_SWIER19_Msk
   --  unsupported macro: EXTI_SWIER_SWI0 EXTI_SWIER_SWIER0
   --  unsupported macro: EXTI_SWIER_SWI1 EXTI_SWIER_SWIER1
   --  unsupported macro: EXTI_SWIER_SWI2 EXTI_SWIER_SWIER2
   --  unsupported macro: EXTI_SWIER_SWI3 EXTI_SWIER_SWIER3
   --  unsupported macro: EXTI_SWIER_SWI4 EXTI_SWIER_SWIER4
   --  unsupported macro: EXTI_SWIER_SWI5 EXTI_SWIER_SWIER5
   --  unsupported macro: EXTI_SWIER_SWI6 EXTI_SWIER_SWIER6
   --  unsupported macro: EXTI_SWIER_SWI7 EXTI_SWIER_SWIER7
   --  unsupported macro: EXTI_SWIER_SWI8 EXTI_SWIER_SWIER8
   --  unsupported macro: EXTI_SWIER_SWI9 EXTI_SWIER_SWIER9
   --  unsupported macro: EXTI_SWIER_SWI10 EXTI_SWIER_SWIER10
   --  unsupported macro: EXTI_SWIER_SWI11 EXTI_SWIER_SWIER11
   --  unsupported macro: EXTI_SWIER_SWI12 EXTI_SWIER_SWIER12
   --  unsupported macro: EXTI_SWIER_SWI13 EXTI_SWIER_SWIER13
   --  unsupported macro: EXTI_SWIER_SWI14 EXTI_SWIER_SWIER14
   --  unsupported macro: EXTI_SWIER_SWI15 EXTI_SWIER_SWIER15
   --  unsupported macro: EXTI_SWIER_SWI16 EXTI_SWIER_SWIER16
   --  unsupported macro: EXTI_SWIER_SWI17 EXTI_SWIER_SWIER17
   --  unsupported macro: EXTI_SWIER_SWI19 EXTI_SWIER_SWIER19

   EXTI_PR_PR0_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1542
   --  unsupported macro: EXTI_PR_PR0_Msk (0x1UL << EXTI_PR_PR0_Pos)
   --  unsupported macro: EXTI_PR_PR0 EXTI_PR_PR0_Msk

   EXTI_PR_PR1_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:1545
   --  unsupported macro: EXTI_PR_PR1_Msk (0x1UL << EXTI_PR_PR1_Pos)
   --  unsupported macro: EXTI_PR_PR1 EXTI_PR_PR1_Msk

   EXTI_PR_PR2_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:1548
   --  unsupported macro: EXTI_PR_PR2_Msk (0x1UL << EXTI_PR_PR2_Pos)
   --  unsupported macro: EXTI_PR_PR2 EXTI_PR_PR2_Msk

   EXTI_PR_PR3_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:1551
   --  unsupported macro: EXTI_PR_PR3_Msk (0x1UL << EXTI_PR_PR3_Pos)
   --  unsupported macro: EXTI_PR_PR3 EXTI_PR_PR3_Msk

   EXTI_PR_PR4_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:1554
   --  unsupported macro: EXTI_PR_PR4_Msk (0x1UL << EXTI_PR_PR4_Pos)
   --  unsupported macro: EXTI_PR_PR4 EXTI_PR_PR4_Msk

   EXTI_PR_PR5_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:1557
   --  unsupported macro: EXTI_PR_PR5_Msk (0x1UL << EXTI_PR_PR5_Pos)
   --  unsupported macro: EXTI_PR_PR5 EXTI_PR_PR5_Msk

   EXTI_PR_PR6_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:1560
   --  unsupported macro: EXTI_PR_PR6_Msk (0x1UL << EXTI_PR_PR6_Pos)
   --  unsupported macro: EXTI_PR_PR6 EXTI_PR_PR6_Msk

   EXTI_PR_PR7_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:1563
   --  unsupported macro: EXTI_PR_PR7_Msk (0x1UL << EXTI_PR_PR7_Pos)
   --  unsupported macro: EXTI_PR_PR7 EXTI_PR_PR7_Msk

   EXTI_PR_PR8_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:1566
   --  unsupported macro: EXTI_PR_PR8_Msk (0x1UL << EXTI_PR_PR8_Pos)
   --  unsupported macro: EXTI_PR_PR8 EXTI_PR_PR8_Msk

   EXTI_PR_PR9_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:1569
   --  unsupported macro: EXTI_PR_PR9_Msk (0x1UL << EXTI_PR_PR9_Pos)
   --  unsupported macro: EXTI_PR_PR9 EXTI_PR_PR9_Msk

   EXTI_PR_PR10_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:1572
   --  unsupported macro: EXTI_PR_PR10_Msk (0x1UL << EXTI_PR_PR10_Pos)
   --  unsupported macro: EXTI_PR_PR10 EXTI_PR_PR10_Msk

   EXTI_PR_PR11_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:1575
   --  unsupported macro: EXTI_PR_PR11_Msk (0x1UL << EXTI_PR_PR11_Pos)
   --  unsupported macro: EXTI_PR_PR11 EXTI_PR_PR11_Msk

   EXTI_PR_PR12_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:1578
   --  unsupported macro: EXTI_PR_PR12_Msk (0x1UL << EXTI_PR_PR12_Pos)
   --  unsupported macro: EXTI_PR_PR12 EXTI_PR_PR12_Msk

   EXTI_PR_PR13_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:1581
   --  unsupported macro: EXTI_PR_PR13_Msk (0x1UL << EXTI_PR_PR13_Pos)
   --  unsupported macro: EXTI_PR_PR13 EXTI_PR_PR13_Msk

   EXTI_PR_PR14_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:1584
   --  unsupported macro: EXTI_PR_PR14_Msk (0x1UL << EXTI_PR_PR14_Pos)
   --  unsupported macro: EXTI_PR_PR14 EXTI_PR_PR14_Msk

   EXTI_PR_PR15_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:1587
   --  unsupported macro: EXTI_PR_PR15_Msk (0x1UL << EXTI_PR_PR15_Pos)
   --  unsupported macro: EXTI_PR_PR15 EXTI_PR_PR15_Msk

   EXTI_PR_PR16_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:1590
   --  unsupported macro: EXTI_PR_PR16_Msk (0x1UL << EXTI_PR_PR16_Pos)
   --  unsupported macro: EXTI_PR_PR16 EXTI_PR_PR16_Msk

   EXTI_PR_PR17_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:1593
   --  unsupported macro: EXTI_PR_PR17_Msk (0x1UL << EXTI_PR_PR17_Pos)
   --  unsupported macro: EXTI_PR_PR17 EXTI_PR_PR17_Msk

   EXTI_PR_PR19_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:1596
   --  unsupported macro: EXTI_PR_PR19_Msk (0x1UL << EXTI_PR_PR19_Pos)
   --  unsupported macro: EXTI_PR_PR19 EXTI_PR_PR19_Msk
   --  unsupported macro: EXTI_PR_PIF0 EXTI_PR_PR0
   --  unsupported macro: EXTI_PR_PIF1 EXTI_PR_PR1
   --  unsupported macro: EXTI_PR_PIF2 EXTI_PR_PR2
   --  unsupported macro: EXTI_PR_PIF3 EXTI_PR_PR3
   --  unsupported macro: EXTI_PR_PIF4 EXTI_PR_PR4
   --  unsupported macro: EXTI_PR_PIF5 EXTI_PR_PR5
   --  unsupported macro: EXTI_PR_PIF6 EXTI_PR_PR6
   --  unsupported macro: EXTI_PR_PIF7 EXTI_PR_PR7
   --  unsupported macro: EXTI_PR_PIF8 EXTI_PR_PR8
   --  unsupported macro: EXTI_PR_PIF9 EXTI_PR_PR9
   --  unsupported macro: EXTI_PR_PIF10 EXTI_PR_PR10
   --  unsupported macro: EXTI_PR_PIF11 EXTI_PR_PR11
   --  unsupported macro: EXTI_PR_PIF12 EXTI_PR_PR12
   --  unsupported macro: EXTI_PR_PIF13 EXTI_PR_PR13
   --  unsupported macro: EXTI_PR_PIF14 EXTI_PR_PR14
   --  unsupported macro: EXTI_PR_PIF15 EXTI_PR_PR15
   --  unsupported macro: EXTI_PR_PIF16 EXTI_PR_PR16
   --  unsupported macro: EXTI_PR_PIF17 EXTI_PR_PR17
   --  unsupported macro: EXTI_PR_PIF19 EXTI_PR_PR19

   FLASH_ACR_LATENCY_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1628
   --  unsupported macro: FLASH_ACR_LATENCY_Msk (0x1UL << FLASH_ACR_LATENCY_Pos)
   --  unsupported macro: FLASH_ACR_LATENCY FLASH_ACR_LATENCY_Msk

   FLASH_ACR_PRFTBE_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:1632
   --  unsupported macro: FLASH_ACR_PRFTBE_Msk (0x1UL << FLASH_ACR_PRFTBE_Pos)
   --  unsupported macro: FLASH_ACR_PRFTBE FLASH_ACR_PRFTBE_Msk

   FLASH_ACR_PRFTBS_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:1635
   --  unsupported macro: FLASH_ACR_PRFTBS_Msk (0x1UL << FLASH_ACR_PRFTBS_Pos)
   --  unsupported macro: FLASH_ACR_PRFTBS FLASH_ACR_PRFTBS_Msk

   FLASH_KEYR_FKEYR_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1640
   --  unsupported macro: FLASH_KEYR_FKEYR_Msk (0xFFFFFFFFUL << FLASH_KEYR_FKEYR_Pos)
   --  unsupported macro: FLASH_KEYR_FKEYR FLASH_KEYR_FKEYR_Msk

   FLASH_OPTKEYR_OPTKEYR_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1645
   --  unsupported macro: FLASH_OPTKEYR_OPTKEYR_Msk (0xFFFFFFFFUL << FLASH_OPTKEYR_OPTKEYR_Pos)
   --  unsupported macro: FLASH_OPTKEYR_OPTKEYR FLASH_OPTKEYR_OPTKEYR_Msk

   FLASH_KEY1_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1650
   --  unsupported macro: FLASH_KEY1_Msk (0x45670123UL << FLASH_KEY1_Pos)
   --  unsupported macro: FLASH_KEY1 FLASH_KEY1_Msk

   FLASH_KEY2_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1653
   --  unsupported macro: FLASH_KEY2_Msk (0xCDEF89ABUL << FLASH_KEY2_Pos)
   --  unsupported macro: FLASH_KEY2 FLASH_KEY2_Msk

   FLASH_OPTKEY1_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1658
   --  unsupported macro: FLASH_OPTKEY1_Msk (0x45670123UL << FLASH_OPTKEY1_Pos)
   --  unsupported macro: FLASH_OPTKEY1 FLASH_OPTKEY1_Msk

   FLASH_OPTKEY2_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1661
   --  unsupported macro: FLASH_OPTKEY2_Msk (0xCDEF89ABUL << FLASH_OPTKEY2_Pos)
   --  unsupported macro: FLASH_OPTKEY2 FLASH_OPTKEY2_Msk

   FLASH_SR_BSY_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1667
   --  unsupported macro: FLASH_SR_BSY_Msk (0x1UL << FLASH_SR_BSY_Pos)
   --  unsupported macro: FLASH_SR_BSY FLASH_SR_BSY_Msk

   FLASH_SR_PGERR_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:1670
   --  unsupported macro: FLASH_SR_PGERR_Msk (0x1UL << FLASH_SR_PGERR_Pos)
   --  unsupported macro: FLASH_SR_PGERR FLASH_SR_PGERR_Msk

   FLASH_SR_WRPRTERR_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:1673
   --  unsupported macro: FLASH_SR_WRPRTERR_Msk (0x1UL << FLASH_SR_WRPRTERR_Pos)
   --  unsupported macro: FLASH_SR_WRPRTERR FLASH_SR_WRPRTERR_Msk

   FLASH_SR_EOP_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:1676
   --  unsupported macro: FLASH_SR_EOP_Msk (0x1UL << FLASH_SR_EOP_Pos)
   --  unsupported macro: FLASH_SR_EOP FLASH_SR_EOP_Msk
   --  unsupported macro: FLASH_SR_WRPERR FLASH_SR_WRPRTERR

   FLASH_CR_PG_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1682
   --  unsupported macro: FLASH_CR_PG_Msk (0x1UL << FLASH_CR_PG_Pos)
   --  unsupported macro: FLASH_CR_PG FLASH_CR_PG_Msk

   FLASH_CR_PER_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:1685
   --  unsupported macro: FLASH_CR_PER_Msk (0x1UL << FLASH_CR_PER_Pos)
   --  unsupported macro: FLASH_CR_PER FLASH_CR_PER_Msk

   FLASH_CR_MER_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:1688
   --  unsupported macro: FLASH_CR_MER_Msk (0x1UL << FLASH_CR_MER_Pos)
   --  unsupported macro: FLASH_CR_MER FLASH_CR_MER_Msk

   FLASH_CR_OPTPG_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:1691
   --  unsupported macro: FLASH_CR_OPTPG_Msk (0x1UL << FLASH_CR_OPTPG_Pos)
   --  unsupported macro: FLASH_CR_OPTPG FLASH_CR_OPTPG_Msk

   FLASH_CR_OPTER_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:1694
   --  unsupported macro: FLASH_CR_OPTER_Msk (0x1UL << FLASH_CR_OPTER_Pos)
   --  unsupported macro: FLASH_CR_OPTER FLASH_CR_OPTER_Msk

   FLASH_CR_STRT_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:1697
   --  unsupported macro: FLASH_CR_STRT_Msk (0x1UL << FLASH_CR_STRT_Pos)
   --  unsupported macro: FLASH_CR_STRT FLASH_CR_STRT_Msk

   FLASH_CR_LOCK_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:1700
   --  unsupported macro: FLASH_CR_LOCK_Msk (0x1UL << FLASH_CR_LOCK_Pos)
   --  unsupported macro: FLASH_CR_LOCK FLASH_CR_LOCK_Msk

   FLASH_CR_OPTWRE_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:1703
   --  unsupported macro: FLASH_CR_OPTWRE_Msk (0x1UL << FLASH_CR_OPTWRE_Pos)
   --  unsupported macro: FLASH_CR_OPTWRE FLASH_CR_OPTWRE_Msk

   FLASH_CR_ERRIE_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:1706
   --  unsupported macro: FLASH_CR_ERRIE_Msk (0x1UL << FLASH_CR_ERRIE_Pos)
   --  unsupported macro: FLASH_CR_ERRIE FLASH_CR_ERRIE_Msk

   FLASH_CR_EOPIE_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:1709
   --  unsupported macro: FLASH_CR_EOPIE_Msk (0x1UL << FLASH_CR_EOPIE_Pos)
   --  unsupported macro: FLASH_CR_EOPIE FLASH_CR_EOPIE_Msk

   FLASH_CR_OBL_LAUNCH_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:1712
   --  unsupported macro: FLASH_CR_OBL_LAUNCH_Msk (0x1UL << FLASH_CR_OBL_LAUNCH_Pos)
   --  unsupported macro: FLASH_CR_OBL_LAUNCH FLASH_CR_OBL_LAUNCH_Msk

   FLASH_AR_FAR_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1717
   --  unsupported macro: FLASH_AR_FAR_Msk (0xFFFFFFFFUL << FLASH_AR_FAR_Pos)
   --  unsupported macro: FLASH_AR_FAR FLASH_AR_FAR_Msk

   FLASH_OBR_OPTERR_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1722
   --  unsupported macro: FLASH_OBR_OPTERR_Msk (0x1UL << FLASH_OBR_OPTERR_Pos)
   --  unsupported macro: FLASH_OBR_OPTERR FLASH_OBR_OPTERR_Msk

   FLASH_OBR_RDPRT1_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:1725
   --  unsupported macro: FLASH_OBR_RDPRT1_Msk (0x1UL << FLASH_OBR_RDPRT1_Pos)
   --  unsupported macro: FLASH_OBR_RDPRT1 FLASH_OBR_RDPRT1_Msk

   FLASH_OBR_RDPRT2_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:1728
   --  unsupported macro: FLASH_OBR_RDPRT2_Msk (0x1UL << FLASH_OBR_RDPRT2_Pos)
   --  unsupported macro: FLASH_OBR_RDPRT2 FLASH_OBR_RDPRT2_Msk

   FLASH_OBR_USER_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:1732
   --  unsupported macro: FLASH_OBR_USER_Msk (0x77UL << FLASH_OBR_USER_Pos)
   --  unsupported macro: FLASH_OBR_USER FLASH_OBR_USER_Msk

   FLASH_OBR_IWDG_SW_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:1735
   --  unsupported macro: FLASH_OBR_IWDG_SW_Msk (0x1UL << FLASH_OBR_IWDG_SW_Pos)
   --  unsupported macro: FLASH_OBR_IWDG_SW FLASH_OBR_IWDG_SW_Msk

   FLASH_OBR_nRST_STOP_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:1738
   --  unsupported macro: FLASH_OBR_nRST_STOP_Msk (0x1UL << FLASH_OBR_nRST_STOP_Pos)
   --  unsupported macro: FLASH_OBR_nRST_STOP FLASH_OBR_nRST_STOP_Msk

   FLASH_OBR_nRST_STDBY_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:1741
   --  unsupported macro: FLASH_OBR_nRST_STDBY_Msk (0x1UL << FLASH_OBR_nRST_STDBY_Pos)
   --  unsupported macro: FLASH_OBR_nRST_STDBY FLASH_OBR_nRST_STDBY_Msk

   FLASH_OBR_nBOOT1_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:1744
   --  unsupported macro: FLASH_OBR_nBOOT1_Msk (0x1UL << FLASH_OBR_nBOOT1_Pos)
   --  unsupported macro: FLASH_OBR_nBOOT1 FLASH_OBR_nBOOT1_Msk

   FLASH_OBR_VDDA_MONITOR_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:1747
   --  unsupported macro: FLASH_OBR_VDDA_MONITOR_Msk (0x1UL << FLASH_OBR_VDDA_MONITOR_Pos)
   --  unsupported macro: FLASH_OBR_VDDA_MONITOR FLASH_OBR_VDDA_MONITOR_Msk

   FLASH_OBR_RAM_PARITY_CHECK_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:1750
   --  unsupported macro: FLASH_OBR_RAM_PARITY_CHECK_Msk (0x1UL << FLASH_OBR_RAM_PARITY_CHECK_Pos)
   --  unsupported macro: FLASH_OBR_RAM_PARITY_CHECK FLASH_OBR_RAM_PARITY_CHECK_Msk

   FLASH_OBR_DATA0_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:1753
   --  unsupported macro: FLASH_OBR_DATA0_Msk (0xFFUL << FLASH_OBR_DATA0_Pos)
   --  unsupported macro: FLASH_OBR_DATA0 FLASH_OBR_DATA0_Msk

   FLASH_OBR_DATA1_Pos : constant := (24);  --  ../core/include/stm32f0/stm32f030x6.h:1756
   --  unsupported macro: FLASH_OBR_DATA1_Msk (0xFFUL << FLASH_OBR_DATA1_Pos)
   --  unsupported macro: FLASH_OBR_DATA1 FLASH_OBR_DATA1_Msk
   --  unsupported macro: FLASH_OBR_BOOT1 FLASH_OBR_nBOOT1
   --  unsupported macro: FLASH_OBR_VDDA_ANALOG FLASH_OBR_VDDA_MONITOR

   FLASH_WRPR_WRP_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1767
   --  unsupported macro: FLASH_WRPR_WRP_Msk (0xFFFFUL << FLASH_WRPR_WRP_Pos)
   --  unsupported macro: FLASH_WRPR_WRP FLASH_WRPR_WRP_Msk

   OB_RDP_RDP_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1774
   --  unsupported macro: OB_RDP_RDP_Msk (0xFFUL << OB_RDP_RDP_Pos)
   --  unsupported macro: OB_RDP_RDP OB_RDP_RDP_Msk

   OB_RDP_nRDP_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:1777
   --  unsupported macro: OB_RDP_nRDP_Msk (0xFFUL << OB_RDP_nRDP_Pos)
   --  unsupported macro: OB_RDP_nRDP OB_RDP_nRDP_Msk

   OB_USER_USER_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:1782
   --  unsupported macro: OB_USER_USER_Msk (0xFFUL << OB_USER_USER_Pos)
   --  unsupported macro: OB_USER_USER OB_USER_USER_Msk

   OB_USER_nUSER_Pos : constant := (24);  --  ../core/include/stm32f0/stm32f030x6.h:1785
   --  unsupported macro: OB_USER_nUSER_Msk (0xFFUL << OB_USER_nUSER_Pos)
   --  unsupported macro: OB_USER_nUSER OB_USER_nUSER_Msk

   OB_WRP0_WRP0_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1790
   --  unsupported macro: OB_WRP0_WRP0_Msk (0xFFUL << OB_WRP0_WRP0_Pos)
   --  unsupported macro: OB_WRP0_WRP0 OB_WRP0_WRP0_Msk

   OB_WRP0_nWRP0_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:1793
   --  unsupported macro: OB_WRP0_nWRP0_Msk (0xFFUL << OB_WRP0_nWRP0_Pos)
   --  unsupported macro: OB_WRP0_nWRP0 OB_WRP0_nWRP0_Msk

   GPIO_MODER_MODER0_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1803
   --  unsupported macro: GPIO_MODER_MODER0_Msk (0x3UL << GPIO_MODER_MODER0_Pos)
   --  unsupported macro: GPIO_MODER_MODER0 GPIO_MODER_MODER0_Msk
   --  unsupported macro: GPIO_MODER_MODER0_0 (0x1UL << GPIO_MODER_MODER0_Pos)
   --  unsupported macro: GPIO_MODER_MODER0_1 (0x2UL << GPIO_MODER_MODER0_Pos)

   GPIO_MODER_MODER1_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:1808
   --  unsupported macro: GPIO_MODER_MODER1_Msk (0x3UL << GPIO_MODER_MODER1_Pos)
   --  unsupported macro: GPIO_MODER_MODER1 GPIO_MODER_MODER1_Msk
   --  unsupported macro: GPIO_MODER_MODER1_0 (0x1UL << GPIO_MODER_MODER1_Pos)
   --  unsupported macro: GPIO_MODER_MODER1_1 (0x2UL << GPIO_MODER_MODER1_Pos)

   GPIO_MODER_MODER2_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:1813
   --  unsupported macro: GPIO_MODER_MODER2_Msk (0x3UL << GPIO_MODER_MODER2_Pos)
   --  unsupported macro: GPIO_MODER_MODER2 GPIO_MODER_MODER2_Msk
   --  unsupported macro: GPIO_MODER_MODER2_0 (0x1UL << GPIO_MODER_MODER2_Pos)
   --  unsupported macro: GPIO_MODER_MODER2_1 (0x2UL << GPIO_MODER_MODER2_Pos)

   GPIO_MODER_MODER3_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:1818
   --  unsupported macro: GPIO_MODER_MODER3_Msk (0x3UL << GPIO_MODER_MODER3_Pos)
   --  unsupported macro: GPIO_MODER_MODER3 GPIO_MODER_MODER3_Msk
   --  unsupported macro: GPIO_MODER_MODER3_0 (0x1UL << GPIO_MODER_MODER3_Pos)
   --  unsupported macro: GPIO_MODER_MODER3_1 (0x2UL << GPIO_MODER_MODER3_Pos)

   GPIO_MODER_MODER4_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:1823
   --  unsupported macro: GPIO_MODER_MODER4_Msk (0x3UL << GPIO_MODER_MODER4_Pos)
   --  unsupported macro: GPIO_MODER_MODER4 GPIO_MODER_MODER4_Msk
   --  unsupported macro: GPIO_MODER_MODER4_0 (0x1UL << GPIO_MODER_MODER4_Pos)
   --  unsupported macro: GPIO_MODER_MODER4_1 (0x2UL << GPIO_MODER_MODER4_Pos)

   GPIO_MODER_MODER5_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:1828
   --  unsupported macro: GPIO_MODER_MODER5_Msk (0x3UL << GPIO_MODER_MODER5_Pos)
   --  unsupported macro: GPIO_MODER_MODER5 GPIO_MODER_MODER5_Msk
   --  unsupported macro: GPIO_MODER_MODER5_0 (0x1UL << GPIO_MODER_MODER5_Pos)
   --  unsupported macro: GPIO_MODER_MODER5_1 (0x2UL << GPIO_MODER_MODER5_Pos)

   GPIO_MODER_MODER6_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:1833
   --  unsupported macro: GPIO_MODER_MODER6_Msk (0x3UL << GPIO_MODER_MODER6_Pos)
   --  unsupported macro: GPIO_MODER_MODER6 GPIO_MODER_MODER6_Msk
   --  unsupported macro: GPIO_MODER_MODER6_0 (0x1UL << GPIO_MODER_MODER6_Pos)
   --  unsupported macro: GPIO_MODER_MODER6_1 (0x2UL << GPIO_MODER_MODER6_Pos)

   GPIO_MODER_MODER7_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:1838
   --  unsupported macro: GPIO_MODER_MODER7_Msk (0x3UL << GPIO_MODER_MODER7_Pos)
   --  unsupported macro: GPIO_MODER_MODER7 GPIO_MODER_MODER7_Msk
   --  unsupported macro: GPIO_MODER_MODER7_0 (0x1UL << GPIO_MODER_MODER7_Pos)
   --  unsupported macro: GPIO_MODER_MODER7_1 (0x2UL << GPIO_MODER_MODER7_Pos)

   GPIO_MODER_MODER8_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:1843
   --  unsupported macro: GPIO_MODER_MODER8_Msk (0x3UL << GPIO_MODER_MODER8_Pos)
   --  unsupported macro: GPIO_MODER_MODER8 GPIO_MODER_MODER8_Msk
   --  unsupported macro: GPIO_MODER_MODER8_0 (0x1UL << GPIO_MODER_MODER8_Pos)
   --  unsupported macro: GPIO_MODER_MODER8_1 (0x2UL << GPIO_MODER_MODER8_Pos)

   GPIO_MODER_MODER9_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:1848
   --  unsupported macro: GPIO_MODER_MODER9_Msk (0x3UL << GPIO_MODER_MODER9_Pos)
   --  unsupported macro: GPIO_MODER_MODER9 GPIO_MODER_MODER9_Msk
   --  unsupported macro: GPIO_MODER_MODER9_0 (0x1UL << GPIO_MODER_MODER9_Pos)
   --  unsupported macro: GPIO_MODER_MODER9_1 (0x2UL << GPIO_MODER_MODER9_Pos)

   GPIO_MODER_MODER10_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:1853
   --  unsupported macro: GPIO_MODER_MODER10_Msk (0x3UL << GPIO_MODER_MODER10_Pos)
   --  unsupported macro: GPIO_MODER_MODER10 GPIO_MODER_MODER10_Msk
   --  unsupported macro: GPIO_MODER_MODER10_0 (0x1UL << GPIO_MODER_MODER10_Pos)
   --  unsupported macro: GPIO_MODER_MODER10_1 (0x2UL << GPIO_MODER_MODER10_Pos)

   GPIO_MODER_MODER11_Pos : constant := (22);  --  ../core/include/stm32f0/stm32f030x6.h:1858
   --  unsupported macro: GPIO_MODER_MODER11_Msk (0x3UL << GPIO_MODER_MODER11_Pos)
   --  unsupported macro: GPIO_MODER_MODER11 GPIO_MODER_MODER11_Msk
   --  unsupported macro: GPIO_MODER_MODER11_0 (0x1UL << GPIO_MODER_MODER11_Pos)
   --  unsupported macro: GPIO_MODER_MODER11_1 (0x2UL << GPIO_MODER_MODER11_Pos)

   GPIO_MODER_MODER12_Pos : constant := (24);  --  ../core/include/stm32f0/stm32f030x6.h:1863
   --  unsupported macro: GPIO_MODER_MODER12_Msk (0x3UL << GPIO_MODER_MODER12_Pos)
   --  unsupported macro: GPIO_MODER_MODER12 GPIO_MODER_MODER12_Msk
   --  unsupported macro: GPIO_MODER_MODER12_0 (0x1UL << GPIO_MODER_MODER12_Pos)
   --  unsupported macro: GPIO_MODER_MODER12_1 (0x2UL << GPIO_MODER_MODER12_Pos)

   GPIO_MODER_MODER13_Pos : constant := (26);  --  ../core/include/stm32f0/stm32f030x6.h:1868
   --  unsupported macro: GPIO_MODER_MODER13_Msk (0x3UL << GPIO_MODER_MODER13_Pos)
   --  unsupported macro: GPIO_MODER_MODER13 GPIO_MODER_MODER13_Msk
   --  unsupported macro: GPIO_MODER_MODER13_0 (0x1UL << GPIO_MODER_MODER13_Pos)
   --  unsupported macro: GPIO_MODER_MODER13_1 (0x2UL << GPIO_MODER_MODER13_Pos)

   GPIO_MODER_MODER14_Pos : constant := (28);  --  ../core/include/stm32f0/stm32f030x6.h:1873
   --  unsupported macro: GPIO_MODER_MODER14_Msk (0x3UL << GPIO_MODER_MODER14_Pos)
   --  unsupported macro: GPIO_MODER_MODER14 GPIO_MODER_MODER14_Msk
   --  unsupported macro: GPIO_MODER_MODER14_0 (0x1UL << GPIO_MODER_MODER14_Pos)
   --  unsupported macro: GPIO_MODER_MODER14_1 (0x2UL << GPIO_MODER_MODER14_Pos)

   GPIO_MODER_MODER15_Pos : constant := (30);  --  ../core/include/stm32f0/stm32f030x6.h:1878
   --  unsupported macro: GPIO_MODER_MODER15_Msk (0x3UL << GPIO_MODER_MODER15_Pos)
   --  unsupported macro: GPIO_MODER_MODER15 GPIO_MODER_MODER15_Msk
   --  unsupported macro: GPIO_MODER_MODER15_0 (0x1UL << GPIO_MODER_MODER15_Pos)
   --  unsupported macro: GPIO_MODER_MODER15_1 (0x2UL << GPIO_MODER_MODER15_Pos)

   GPIO_OTYPER_OT_0 : constant := (16#00000001#);  --  ../core/include/stm32f0/stm32f030x6.h:1885
   GPIO_OTYPER_OT_1 : constant := (16#00000002#);  --  ../core/include/stm32f0/stm32f030x6.h:1886
   GPIO_OTYPER_OT_2 : constant := (16#00000004#);  --  ../core/include/stm32f0/stm32f030x6.h:1887
   GPIO_OTYPER_OT_3 : constant := (16#00000008#);  --  ../core/include/stm32f0/stm32f030x6.h:1888
   GPIO_OTYPER_OT_4 : constant := (16#00000010#);  --  ../core/include/stm32f0/stm32f030x6.h:1889
   GPIO_OTYPER_OT_5 : constant := (16#00000020#);  --  ../core/include/stm32f0/stm32f030x6.h:1890
   GPIO_OTYPER_OT_6 : constant := (16#00000040#);  --  ../core/include/stm32f0/stm32f030x6.h:1891
   GPIO_OTYPER_OT_7 : constant := (16#00000080#);  --  ../core/include/stm32f0/stm32f030x6.h:1892
   GPIO_OTYPER_OT_8 : constant := (16#00000100#);  --  ../core/include/stm32f0/stm32f030x6.h:1893
   GPIO_OTYPER_OT_9 : constant := (16#00000200#);  --  ../core/include/stm32f0/stm32f030x6.h:1894
   GPIO_OTYPER_OT_10 : constant := (16#00000400#);  --  ../core/include/stm32f0/stm32f030x6.h:1895
   GPIO_OTYPER_OT_11 : constant := (16#00000800#);  --  ../core/include/stm32f0/stm32f030x6.h:1896
   GPIO_OTYPER_OT_12 : constant := (16#00001000#);  --  ../core/include/stm32f0/stm32f030x6.h:1897
   GPIO_OTYPER_OT_13 : constant := (16#00002000#);  --  ../core/include/stm32f0/stm32f030x6.h:1898
   GPIO_OTYPER_OT_14 : constant := (16#00004000#);  --  ../core/include/stm32f0/stm32f030x6.h:1899
   GPIO_OTYPER_OT_15 : constant := (16#00008000#);  --  ../core/include/stm32f0/stm32f030x6.h:1900

   GPIO_OSPEEDR_OSPEEDR0_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:1903
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR0_Msk (0x3UL << GPIO_OSPEEDR_OSPEEDR0_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR0 GPIO_OSPEEDR_OSPEEDR0_Msk
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR0_0 (0x1UL << GPIO_OSPEEDR_OSPEEDR0_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR0_1 (0x2UL << GPIO_OSPEEDR_OSPEEDR0_Pos)

   GPIO_OSPEEDR_OSPEEDR1_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:1908
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR1_Msk (0x3UL << GPIO_OSPEEDR_OSPEEDR1_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR1 GPIO_OSPEEDR_OSPEEDR1_Msk
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR1_0 (0x1UL << GPIO_OSPEEDR_OSPEEDR1_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR1_1 (0x2UL << GPIO_OSPEEDR_OSPEEDR1_Pos)

   GPIO_OSPEEDR_OSPEEDR2_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:1913
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR2_Msk (0x3UL << GPIO_OSPEEDR_OSPEEDR2_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR2 GPIO_OSPEEDR_OSPEEDR2_Msk
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR2_0 (0x1UL << GPIO_OSPEEDR_OSPEEDR2_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR2_1 (0x2UL << GPIO_OSPEEDR_OSPEEDR2_Pos)

   GPIO_OSPEEDR_OSPEEDR3_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:1918
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR3_Msk (0x3UL << GPIO_OSPEEDR_OSPEEDR3_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR3 GPIO_OSPEEDR_OSPEEDR3_Msk
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR3_0 (0x1UL << GPIO_OSPEEDR_OSPEEDR3_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR3_1 (0x2UL << GPIO_OSPEEDR_OSPEEDR3_Pos)

   GPIO_OSPEEDR_OSPEEDR4_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:1923
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR4_Msk (0x3UL << GPIO_OSPEEDR_OSPEEDR4_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR4 GPIO_OSPEEDR_OSPEEDR4_Msk
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR4_0 (0x1UL << GPIO_OSPEEDR_OSPEEDR4_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR4_1 (0x2UL << GPIO_OSPEEDR_OSPEEDR4_Pos)

   GPIO_OSPEEDR_OSPEEDR5_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:1928
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR5_Msk (0x3UL << GPIO_OSPEEDR_OSPEEDR5_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR5 GPIO_OSPEEDR_OSPEEDR5_Msk
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR5_0 (0x1UL << GPIO_OSPEEDR_OSPEEDR5_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR5_1 (0x2UL << GPIO_OSPEEDR_OSPEEDR5_Pos)

   GPIO_OSPEEDR_OSPEEDR6_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:1933
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR6_Msk (0x3UL << GPIO_OSPEEDR_OSPEEDR6_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR6 GPIO_OSPEEDR_OSPEEDR6_Msk
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR6_0 (0x1UL << GPIO_OSPEEDR_OSPEEDR6_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR6_1 (0x2UL << GPIO_OSPEEDR_OSPEEDR6_Pos)

   GPIO_OSPEEDR_OSPEEDR7_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:1938
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR7_Msk (0x3UL << GPIO_OSPEEDR_OSPEEDR7_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR7 GPIO_OSPEEDR_OSPEEDR7_Msk
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR7_0 (0x1UL << GPIO_OSPEEDR_OSPEEDR7_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR7_1 (0x2UL << GPIO_OSPEEDR_OSPEEDR7_Pos)

   GPIO_OSPEEDR_OSPEEDR8_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:1943
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR8_Msk (0x3UL << GPIO_OSPEEDR_OSPEEDR8_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR8 GPIO_OSPEEDR_OSPEEDR8_Msk
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR8_0 (0x1UL << GPIO_OSPEEDR_OSPEEDR8_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR8_1 (0x2UL << GPIO_OSPEEDR_OSPEEDR8_Pos)

   GPIO_OSPEEDR_OSPEEDR9_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:1948
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR9_Msk (0x3UL << GPIO_OSPEEDR_OSPEEDR9_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR9 GPIO_OSPEEDR_OSPEEDR9_Msk
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR9_0 (0x1UL << GPIO_OSPEEDR_OSPEEDR9_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR9_1 (0x2UL << GPIO_OSPEEDR_OSPEEDR9_Pos)

   GPIO_OSPEEDR_OSPEEDR10_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:1953
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR10_Msk (0x3UL << GPIO_OSPEEDR_OSPEEDR10_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR10 GPIO_OSPEEDR_OSPEEDR10_Msk
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR10_0 (0x1UL << GPIO_OSPEEDR_OSPEEDR10_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR10_1 (0x2UL << GPIO_OSPEEDR_OSPEEDR10_Pos)

   GPIO_OSPEEDR_OSPEEDR11_Pos : constant := (22);  --  ../core/include/stm32f0/stm32f030x6.h:1958
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR11_Msk (0x3UL << GPIO_OSPEEDR_OSPEEDR11_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR11 GPIO_OSPEEDR_OSPEEDR11_Msk
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR11_0 (0x1UL << GPIO_OSPEEDR_OSPEEDR11_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR11_1 (0x2UL << GPIO_OSPEEDR_OSPEEDR11_Pos)

   GPIO_OSPEEDR_OSPEEDR12_Pos : constant := (24);  --  ../core/include/stm32f0/stm32f030x6.h:1963
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR12_Msk (0x3UL << GPIO_OSPEEDR_OSPEEDR12_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR12 GPIO_OSPEEDR_OSPEEDR12_Msk
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR12_0 (0x1UL << GPIO_OSPEEDR_OSPEEDR12_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR12_1 (0x2UL << GPIO_OSPEEDR_OSPEEDR12_Pos)

   GPIO_OSPEEDR_OSPEEDR13_Pos : constant := (26);  --  ../core/include/stm32f0/stm32f030x6.h:1968
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR13_Msk (0x3UL << GPIO_OSPEEDR_OSPEEDR13_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR13 GPIO_OSPEEDR_OSPEEDR13_Msk
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR13_0 (0x1UL << GPIO_OSPEEDR_OSPEEDR13_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR13_1 (0x2UL << GPIO_OSPEEDR_OSPEEDR13_Pos)

   GPIO_OSPEEDR_OSPEEDR14_Pos : constant := (28);  --  ../core/include/stm32f0/stm32f030x6.h:1973
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR14_Msk (0x3UL << GPIO_OSPEEDR_OSPEEDR14_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR14 GPIO_OSPEEDR_OSPEEDR14_Msk
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR14_0 (0x1UL << GPIO_OSPEEDR_OSPEEDR14_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR14_1 (0x2UL << GPIO_OSPEEDR_OSPEEDR14_Pos)

   GPIO_OSPEEDR_OSPEEDR15_Pos : constant := (30);  --  ../core/include/stm32f0/stm32f030x6.h:1978
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR15_Msk (0x3UL << GPIO_OSPEEDR_OSPEEDR15_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR15 GPIO_OSPEEDR_OSPEEDR15_Msk
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR15_0 (0x1UL << GPIO_OSPEEDR_OSPEEDR15_Pos)
   --  unsupported macro: GPIO_OSPEEDR_OSPEEDR15_1 (0x2UL << GPIO_OSPEEDR_OSPEEDR15_Pos)
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR0 GPIO_OSPEEDR_OSPEEDR0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR0_0 GPIO_OSPEEDR_OSPEEDR0_0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR0_1 GPIO_OSPEEDR_OSPEEDR0_1
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR1 GPIO_OSPEEDR_OSPEEDR1
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR1_0 GPIO_OSPEEDR_OSPEEDR1_0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR1_1 GPIO_OSPEEDR_OSPEEDR1_1
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR2 GPIO_OSPEEDR_OSPEEDR2
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR2_0 GPIO_OSPEEDR_OSPEEDR2_0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR2_1 GPIO_OSPEEDR_OSPEEDR2_1
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR3 GPIO_OSPEEDR_OSPEEDR3
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR3_0 GPIO_OSPEEDR_OSPEEDR3_0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR3_1 GPIO_OSPEEDR_OSPEEDR3_1
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR4 GPIO_OSPEEDR_OSPEEDR4
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR4_0 GPIO_OSPEEDR_OSPEEDR4_0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR4_1 GPIO_OSPEEDR_OSPEEDR4_1
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR5 GPIO_OSPEEDR_OSPEEDR5
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR5_0 GPIO_OSPEEDR_OSPEEDR5_0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR5_1 GPIO_OSPEEDR_OSPEEDR5_1
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR6 GPIO_OSPEEDR_OSPEEDR6
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR6_0 GPIO_OSPEEDR_OSPEEDR6_0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR6_1 GPIO_OSPEEDR_OSPEEDR6_1
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR7 GPIO_OSPEEDR_OSPEEDR7
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR7_0 GPIO_OSPEEDR_OSPEEDR7_0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR7_1 GPIO_OSPEEDR_OSPEEDR7_1
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR8 GPIO_OSPEEDR_OSPEEDR8
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR8_0 GPIO_OSPEEDR_OSPEEDR8_0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR8_1 GPIO_OSPEEDR_OSPEEDR8_1
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR9 GPIO_OSPEEDR_OSPEEDR9
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR9_0 GPIO_OSPEEDR_OSPEEDR9_0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR9_1 GPIO_OSPEEDR_OSPEEDR9_1
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR10 GPIO_OSPEEDR_OSPEEDR10
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR10_0 GPIO_OSPEEDR_OSPEEDR10_0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR10_1 GPIO_OSPEEDR_OSPEEDR10_1
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR11 GPIO_OSPEEDR_OSPEEDR11
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR11_0 GPIO_OSPEEDR_OSPEEDR11_0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR11_1 GPIO_OSPEEDR_OSPEEDR11_1
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR12 GPIO_OSPEEDR_OSPEEDR12
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR12_0 GPIO_OSPEEDR_OSPEEDR12_0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR12_1 GPIO_OSPEEDR_OSPEEDR12_1
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR13 GPIO_OSPEEDR_OSPEEDR13
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR13_0 GPIO_OSPEEDR_OSPEEDR13_0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR13_1 GPIO_OSPEEDR_OSPEEDR13_1
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR14 GPIO_OSPEEDR_OSPEEDR14
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR14_0 GPIO_OSPEEDR_OSPEEDR14_0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR14_1 GPIO_OSPEEDR_OSPEEDR14_1
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR15 GPIO_OSPEEDR_OSPEEDR15
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR15_0 GPIO_OSPEEDR_OSPEEDR15_0
   --  unsupported macro: GPIO_OSPEEDER_OSPEEDR15_1 GPIO_OSPEEDR_OSPEEDR15_1

   GPIO_PUPDR_PUPDR0_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2035
   --  unsupported macro: GPIO_PUPDR_PUPDR0_Msk (0x3UL << GPIO_PUPDR_PUPDR0_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR0 GPIO_PUPDR_PUPDR0_Msk
   --  unsupported macro: GPIO_PUPDR_PUPDR0_0 (0x1UL << GPIO_PUPDR_PUPDR0_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR0_1 (0x2UL << GPIO_PUPDR_PUPDR0_Pos)

   GPIO_PUPDR_PUPDR1_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:2040
   --  unsupported macro: GPIO_PUPDR_PUPDR1_Msk (0x3UL << GPIO_PUPDR_PUPDR1_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR1 GPIO_PUPDR_PUPDR1_Msk
   --  unsupported macro: GPIO_PUPDR_PUPDR1_0 (0x1UL << GPIO_PUPDR_PUPDR1_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR1_1 (0x2UL << GPIO_PUPDR_PUPDR1_Pos)

   GPIO_PUPDR_PUPDR2_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:2045
   --  unsupported macro: GPIO_PUPDR_PUPDR2_Msk (0x3UL << GPIO_PUPDR_PUPDR2_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR2 GPIO_PUPDR_PUPDR2_Msk
   --  unsupported macro: GPIO_PUPDR_PUPDR2_0 (0x1UL << GPIO_PUPDR_PUPDR2_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR2_1 (0x2UL << GPIO_PUPDR_PUPDR2_Pos)

   GPIO_PUPDR_PUPDR3_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:2050
   --  unsupported macro: GPIO_PUPDR_PUPDR3_Msk (0x3UL << GPIO_PUPDR_PUPDR3_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR3 GPIO_PUPDR_PUPDR3_Msk
   --  unsupported macro: GPIO_PUPDR_PUPDR3_0 (0x1UL << GPIO_PUPDR_PUPDR3_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR3_1 (0x2UL << GPIO_PUPDR_PUPDR3_Pos)

   GPIO_PUPDR_PUPDR4_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2055
   --  unsupported macro: GPIO_PUPDR_PUPDR4_Msk (0x3UL << GPIO_PUPDR_PUPDR4_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR4 GPIO_PUPDR_PUPDR4_Msk
   --  unsupported macro: GPIO_PUPDR_PUPDR4_0 (0x1UL << GPIO_PUPDR_PUPDR4_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR4_1 (0x2UL << GPIO_PUPDR_PUPDR4_Pos)

   GPIO_PUPDR_PUPDR5_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:2060
   --  unsupported macro: GPIO_PUPDR_PUPDR5_Msk (0x3UL << GPIO_PUPDR_PUPDR5_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR5 GPIO_PUPDR_PUPDR5_Msk
   --  unsupported macro: GPIO_PUPDR_PUPDR5_0 (0x1UL << GPIO_PUPDR_PUPDR5_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR5_1 (0x2UL << GPIO_PUPDR_PUPDR5_Pos)

   GPIO_PUPDR_PUPDR6_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:2065
   --  unsupported macro: GPIO_PUPDR_PUPDR6_Msk (0x3UL << GPIO_PUPDR_PUPDR6_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR6 GPIO_PUPDR_PUPDR6_Msk
   --  unsupported macro: GPIO_PUPDR_PUPDR6_0 (0x1UL << GPIO_PUPDR_PUPDR6_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR6_1 (0x2UL << GPIO_PUPDR_PUPDR6_Pos)

   GPIO_PUPDR_PUPDR7_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:2070
   --  unsupported macro: GPIO_PUPDR_PUPDR7_Msk (0x3UL << GPIO_PUPDR_PUPDR7_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR7 GPIO_PUPDR_PUPDR7_Msk
   --  unsupported macro: GPIO_PUPDR_PUPDR7_0 (0x1UL << GPIO_PUPDR_PUPDR7_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR7_1 (0x2UL << GPIO_PUPDR_PUPDR7_Pos)

   GPIO_PUPDR_PUPDR8_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:2075
   --  unsupported macro: GPIO_PUPDR_PUPDR8_Msk (0x3UL << GPIO_PUPDR_PUPDR8_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR8 GPIO_PUPDR_PUPDR8_Msk
   --  unsupported macro: GPIO_PUPDR_PUPDR8_0 (0x1UL << GPIO_PUPDR_PUPDR8_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR8_1 (0x2UL << GPIO_PUPDR_PUPDR8_Pos)

   GPIO_PUPDR_PUPDR9_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:2080
   --  unsupported macro: GPIO_PUPDR_PUPDR9_Msk (0x3UL << GPIO_PUPDR_PUPDR9_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR9 GPIO_PUPDR_PUPDR9_Msk
   --  unsupported macro: GPIO_PUPDR_PUPDR9_0 (0x1UL << GPIO_PUPDR_PUPDR9_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR9_1 (0x2UL << GPIO_PUPDR_PUPDR9_Pos)

   GPIO_PUPDR_PUPDR10_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:2085
   --  unsupported macro: GPIO_PUPDR_PUPDR10_Msk (0x3UL << GPIO_PUPDR_PUPDR10_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR10 GPIO_PUPDR_PUPDR10_Msk
   --  unsupported macro: GPIO_PUPDR_PUPDR10_0 (0x1UL << GPIO_PUPDR_PUPDR10_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR10_1 (0x2UL << GPIO_PUPDR_PUPDR10_Pos)

   GPIO_PUPDR_PUPDR11_Pos : constant := (22);  --  ../core/include/stm32f0/stm32f030x6.h:2090
   --  unsupported macro: GPIO_PUPDR_PUPDR11_Msk (0x3UL << GPIO_PUPDR_PUPDR11_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR11 GPIO_PUPDR_PUPDR11_Msk
   --  unsupported macro: GPIO_PUPDR_PUPDR11_0 (0x1UL << GPIO_PUPDR_PUPDR11_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR11_1 (0x2UL << GPIO_PUPDR_PUPDR11_Pos)

   GPIO_PUPDR_PUPDR12_Pos : constant := (24);  --  ../core/include/stm32f0/stm32f030x6.h:2095
   --  unsupported macro: GPIO_PUPDR_PUPDR12_Msk (0x3UL << GPIO_PUPDR_PUPDR12_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR12 GPIO_PUPDR_PUPDR12_Msk
   --  unsupported macro: GPIO_PUPDR_PUPDR12_0 (0x1UL << GPIO_PUPDR_PUPDR12_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR12_1 (0x2UL << GPIO_PUPDR_PUPDR12_Pos)

   GPIO_PUPDR_PUPDR13_Pos : constant := (26);  --  ../core/include/stm32f0/stm32f030x6.h:2100
   --  unsupported macro: GPIO_PUPDR_PUPDR13_Msk (0x3UL << GPIO_PUPDR_PUPDR13_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR13 GPIO_PUPDR_PUPDR13_Msk
   --  unsupported macro: GPIO_PUPDR_PUPDR13_0 (0x1UL << GPIO_PUPDR_PUPDR13_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR13_1 (0x2UL << GPIO_PUPDR_PUPDR13_Pos)

   GPIO_PUPDR_PUPDR14_Pos : constant := (28);  --  ../core/include/stm32f0/stm32f030x6.h:2105
   --  unsupported macro: GPIO_PUPDR_PUPDR14_Msk (0x3UL << GPIO_PUPDR_PUPDR14_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR14 GPIO_PUPDR_PUPDR14_Msk
   --  unsupported macro: GPIO_PUPDR_PUPDR14_0 (0x1UL << GPIO_PUPDR_PUPDR14_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR14_1 (0x2UL << GPIO_PUPDR_PUPDR14_Pos)

   GPIO_PUPDR_PUPDR15_Pos : constant := (30);  --  ../core/include/stm32f0/stm32f030x6.h:2110
   --  unsupported macro: GPIO_PUPDR_PUPDR15_Msk (0x3UL << GPIO_PUPDR_PUPDR15_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR15 GPIO_PUPDR_PUPDR15_Msk
   --  unsupported macro: GPIO_PUPDR_PUPDR15_0 (0x1UL << GPIO_PUPDR_PUPDR15_Pos)
   --  unsupported macro: GPIO_PUPDR_PUPDR15_1 (0x2UL << GPIO_PUPDR_PUPDR15_Pos)

   GPIO_IDR_0 : constant := (16#00000001#);  --  ../core/include/stm32f0/stm32f030x6.h:2117
   GPIO_IDR_1 : constant := (16#00000002#);  --  ../core/include/stm32f0/stm32f030x6.h:2118
   GPIO_IDR_2 : constant := (16#00000004#);  --  ../core/include/stm32f0/stm32f030x6.h:2119
   GPIO_IDR_3 : constant := (16#00000008#);  --  ../core/include/stm32f0/stm32f030x6.h:2120
   GPIO_IDR_4 : constant := (16#00000010#);  --  ../core/include/stm32f0/stm32f030x6.h:2121
   GPIO_IDR_5 : constant := (16#00000020#);  --  ../core/include/stm32f0/stm32f030x6.h:2122
   GPIO_IDR_6 : constant := (16#00000040#);  --  ../core/include/stm32f0/stm32f030x6.h:2123
   GPIO_IDR_7 : constant := (16#00000080#);  --  ../core/include/stm32f0/stm32f030x6.h:2124
   GPIO_IDR_8 : constant := (16#00000100#);  --  ../core/include/stm32f0/stm32f030x6.h:2125
   GPIO_IDR_9 : constant := (16#00000200#);  --  ../core/include/stm32f0/stm32f030x6.h:2126
   GPIO_IDR_10 : constant := (16#00000400#);  --  ../core/include/stm32f0/stm32f030x6.h:2127
   GPIO_IDR_11 : constant := (16#00000800#);  --  ../core/include/stm32f0/stm32f030x6.h:2128
   GPIO_IDR_12 : constant := (16#00001000#);  --  ../core/include/stm32f0/stm32f030x6.h:2129
   GPIO_IDR_13 : constant := (16#00002000#);  --  ../core/include/stm32f0/stm32f030x6.h:2130
   GPIO_IDR_14 : constant := (16#00004000#);  --  ../core/include/stm32f0/stm32f030x6.h:2131
   GPIO_IDR_15 : constant := (16#00008000#);  --  ../core/include/stm32f0/stm32f030x6.h:2132

   GPIO_ODR_0 : constant := (16#00000001#);  --  ../core/include/stm32f0/stm32f030x6.h:2135
   GPIO_ODR_1 : constant := (16#00000002#);  --  ../core/include/stm32f0/stm32f030x6.h:2136
   GPIO_ODR_2 : constant := (16#00000004#);  --  ../core/include/stm32f0/stm32f030x6.h:2137
   GPIO_ODR_3 : constant := (16#00000008#);  --  ../core/include/stm32f0/stm32f030x6.h:2138
   GPIO_ODR_4 : constant := (16#00000010#);  --  ../core/include/stm32f0/stm32f030x6.h:2139
   GPIO_ODR_5 : constant := (16#00000020#);  --  ../core/include/stm32f0/stm32f030x6.h:2140
   GPIO_ODR_6 : constant := (16#00000040#);  --  ../core/include/stm32f0/stm32f030x6.h:2141
   GPIO_ODR_7 : constant := (16#00000080#);  --  ../core/include/stm32f0/stm32f030x6.h:2142
   GPIO_ODR_8 : constant := (16#00000100#);  --  ../core/include/stm32f0/stm32f030x6.h:2143
   GPIO_ODR_9 : constant := (16#00000200#);  --  ../core/include/stm32f0/stm32f030x6.h:2144
   GPIO_ODR_10 : constant := (16#00000400#);  --  ../core/include/stm32f0/stm32f030x6.h:2145
   GPIO_ODR_11 : constant := (16#00000800#);  --  ../core/include/stm32f0/stm32f030x6.h:2146
   GPIO_ODR_12 : constant := (16#00001000#);  --  ../core/include/stm32f0/stm32f030x6.h:2147
   GPIO_ODR_13 : constant := (16#00002000#);  --  ../core/include/stm32f0/stm32f030x6.h:2148
   GPIO_ODR_14 : constant := (16#00004000#);  --  ../core/include/stm32f0/stm32f030x6.h:2149
   GPIO_ODR_15 : constant := (16#00008000#);  --  ../core/include/stm32f0/stm32f030x6.h:2150

   GPIO_BSRR_BS_0 : constant := (16#00000001#);  --  ../core/include/stm32f0/stm32f030x6.h:2153
   GPIO_BSRR_BS_1 : constant := (16#00000002#);  --  ../core/include/stm32f0/stm32f030x6.h:2154
   GPIO_BSRR_BS_2 : constant := (16#00000004#);  --  ../core/include/stm32f0/stm32f030x6.h:2155
   GPIO_BSRR_BS_3 : constant := (16#00000008#);  --  ../core/include/stm32f0/stm32f030x6.h:2156
   GPIO_BSRR_BS_4 : constant := (16#00000010#);  --  ../core/include/stm32f0/stm32f030x6.h:2157
   GPIO_BSRR_BS_5 : constant := (16#00000020#);  --  ../core/include/stm32f0/stm32f030x6.h:2158
   GPIO_BSRR_BS_6 : constant := (16#00000040#);  --  ../core/include/stm32f0/stm32f030x6.h:2159
   GPIO_BSRR_BS_7 : constant := (16#00000080#);  --  ../core/include/stm32f0/stm32f030x6.h:2160
   GPIO_BSRR_BS_8 : constant := (16#00000100#);  --  ../core/include/stm32f0/stm32f030x6.h:2161
   GPIO_BSRR_BS_9 : constant := (16#00000200#);  --  ../core/include/stm32f0/stm32f030x6.h:2162
   GPIO_BSRR_BS_10 : constant := (16#00000400#);  --  ../core/include/stm32f0/stm32f030x6.h:2163
   GPIO_BSRR_BS_11 : constant := (16#00000800#);  --  ../core/include/stm32f0/stm32f030x6.h:2164
   GPIO_BSRR_BS_12 : constant := (16#00001000#);  --  ../core/include/stm32f0/stm32f030x6.h:2165
   GPIO_BSRR_BS_13 : constant := (16#00002000#);  --  ../core/include/stm32f0/stm32f030x6.h:2166
   GPIO_BSRR_BS_14 : constant := (16#00004000#);  --  ../core/include/stm32f0/stm32f030x6.h:2167
   GPIO_BSRR_BS_15 : constant := (16#00008000#);  --  ../core/include/stm32f0/stm32f030x6.h:2168
   GPIO_BSRR_BR_0 : constant := (16#00010000#);  --  ../core/include/stm32f0/stm32f030x6.h:2169
   GPIO_BSRR_BR_1 : constant := (16#00020000#);  --  ../core/include/stm32f0/stm32f030x6.h:2170
   GPIO_BSRR_BR_2 : constant := (16#00040000#);  --  ../core/include/stm32f0/stm32f030x6.h:2171
   GPIO_BSRR_BR_3 : constant := (16#00080000#);  --  ../core/include/stm32f0/stm32f030x6.h:2172
   GPIO_BSRR_BR_4 : constant := (16#00100000#);  --  ../core/include/stm32f0/stm32f030x6.h:2173
   GPIO_BSRR_BR_5 : constant := (16#00200000#);  --  ../core/include/stm32f0/stm32f030x6.h:2174
   GPIO_BSRR_BR_6 : constant := (16#00400000#);  --  ../core/include/stm32f0/stm32f030x6.h:2175
   GPIO_BSRR_BR_7 : constant := (16#00800000#);  --  ../core/include/stm32f0/stm32f030x6.h:2176
   GPIO_BSRR_BR_8 : constant := (16#01000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2177
   GPIO_BSRR_BR_9 : constant := (16#02000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2178
   GPIO_BSRR_BR_10 : constant := (16#04000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2179
   GPIO_BSRR_BR_11 : constant := (16#08000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2180
   GPIO_BSRR_BR_12 : constant := (16#10000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2181
   GPIO_BSRR_BR_13 : constant := (16#20000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2182
   GPIO_BSRR_BR_14 : constant := (16#40000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2183
   GPIO_BSRR_BR_15 : constant := (16#80000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2184

   GPIO_LCKR_LCK0_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2187
   --  unsupported macro: GPIO_LCKR_LCK0_Msk (0x1UL << GPIO_LCKR_LCK0_Pos)
   --  unsupported macro: GPIO_LCKR_LCK0 GPIO_LCKR_LCK0_Msk

   GPIO_LCKR_LCK1_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:2190
   --  unsupported macro: GPIO_LCKR_LCK1_Msk (0x1UL << GPIO_LCKR_LCK1_Pos)
   --  unsupported macro: GPIO_LCKR_LCK1 GPIO_LCKR_LCK1_Msk

   GPIO_LCKR_LCK2_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:2193
   --  unsupported macro: GPIO_LCKR_LCK2_Msk (0x1UL << GPIO_LCKR_LCK2_Pos)
   --  unsupported macro: GPIO_LCKR_LCK2 GPIO_LCKR_LCK2_Msk

   GPIO_LCKR_LCK3_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:2196
   --  unsupported macro: GPIO_LCKR_LCK3_Msk (0x1UL << GPIO_LCKR_LCK3_Pos)
   --  unsupported macro: GPIO_LCKR_LCK3 GPIO_LCKR_LCK3_Msk

   GPIO_LCKR_LCK4_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:2199
   --  unsupported macro: GPIO_LCKR_LCK4_Msk (0x1UL << GPIO_LCKR_LCK4_Pos)
   --  unsupported macro: GPIO_LCKR_LCK4 GPIO_LCKR_LCK4_Msk

   GPIO_LCKR_LCK5_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:2202
   --  unsupported macro: GPIO_LCKR_LCK5_Msk (0x1UL << GPIO_LCKR_LCK5_Pos)
   --  unsupported macro: GPIO_LCKR_LCK5 GPIO_LCKR_LCK5_Msk

   GPIO_LCKR_LCK6_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:2205
   --  unsupported macro: GPIO_LCKR_LCK6_Msk (0x1UL << GPIO_LCKR_LCK6_Pos)
   --  unsupported macro: GPIO_LCKR_LCK6 GPIO_LCKR_LCK6_Msk

   GPIO_LCKR_LCK7_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:2208
   --  unsupported macro: GPIO_LCKR_LCK7_Msk (0x1UL << GPIO_LCKR_LCK7_Pos)
   --  unsupported macro: GPIO_LCKR_LCK7 GPIO_LCKR_LCK7_Msk

   GPIO_LCKR_LCK8_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2211
   --  unsupported macro: GPIO_LCKR_LCK8_Msk (0x1UL << GPIO_LCKR_LCK8_Pos)
   --  unsupported macro: GPIO_LCKR_LCK8 GPIO_LCKR_LCK8_Msk

   GPIO_LCKR_LCK9_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:2214
   --  unsupported macro: GPIO_LCKR_LCK9_Msk (0x1UL << GPIO_LCKR_LCK9_Pos)
   --  unsupported macro: GPIO_LCKR_LCK9 GPIO_LCKR_LCK9_Msk

   GPIO_LCKR_LCK10_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:2217
   --  unsupported macro: GPIO_LCKR_LCK10_Msk (0x1UL << GPIO_LCKR_LCK10_Pos)
   --  unsupported macro: GPIO_LCKR_LCK10 GPIO_LCKR_LCK10_Msk

   GPIO_LCKR_LCK11_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:2220
   --  unsupported macro: GPIO_LCKR_LCK11_Msk (0x1UL << GPIO_LCKR_LCK11_Pos)
   --  unsupported macro: GPIO_LCKR_LCK11 GPIO_LCKR_LCK11_Msk

   GPIO_LCKR_LCK12_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:2223
   --  unsupported macro: GPIO_LCKR_LCK12_Msk (0x1UL << GPIO_LCKR_LCK12_Pos)
   --  unsupported macro: GPIO_LCKR_LCK12 GPIO_LCKR_LCK12_Msk

   GPIO_LCKR_LCK13_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:2226
   --  unsupported macro: GPIO_LCKR_LCK13_Msk (0x1UL << GPIO_LCKR_LCK13_Pos)
   --  unsupported macro: GPIO_LCKR_LCK13 GPIO_LCKR_LCK13_Msk

   GPIO_LCKR_LCK14_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:2229
   --  unsupported macro: GPIO_LCKR_LCK14_Msk (0x1UL << GPIO_LCKR_LCK14_Pos)
   --  unsupported macro: GPIO_LCKR_LCK14 GPIO_LCKR_LCK14_Msk

   GPIO_LCKR_LCK15_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:2232
   --  unsupported macro: GPIO_LCKR_LCK15_Msk (0x1UL << GPIO_LCKR_LCK15_Pos)
   --  unsupported macro: GPIO_LCKR_LCK15 GPIO_LCKR_LCK15_Msk

   GPIO_LCKR_LCKK_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:2235
   --  unsupported macro: GPIO_LCKR_LCKK_Msk (0x1UL << GPIO_LCKR_LCKK_Pos)
   --  unsupported macro: GPIO_LCKR_LCKK GPIO_LCKR_LCKK_Msk

   GPIO_AFRL_AFSEL0_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2240
   --  unsupported macro: GPIO_AFRL_AFSEL0_Msk (0xFUL << GPIO_AFRL_AFSEL0_Pos)
   --  unsupported macro: GPIO_AFRL_AFSEL0 GPIO_AFRL_AFSEL0_Msk

   GPIO_AFRL_AFSEL1_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:2243
   --  unsupported macro: GPIO_AFRL_AFSEL1_Msk (0xFUL << GPIO_AFRL_AFSEL1_Pos)
   --  unsupported macro: GPIO_AFRL_AFSEL1 GPIO_AFRL_AFSEL1_Msk

   GPIO_AFRL_AFSEL2_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2246
   --  unsupported macro: GPIO_AFRL_AFSEL2_Msk (0xFUL << GPIO_AFRL_AFSEL2_Pos)
   --  unsupported macro: GPIO_AFRL_AFSEL2 GPIO_AFRL_AFSEL2_Msk

   GPIO_AFRL_AFSEL3_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:2249
   --  unsupported macro: GPIO_AFRL_AFSEL3_Msk (0xFUL << GPIO_AFRL_AFSEL3_Pos)
   --  unsupported macro: GPIO_AFRL_AFSEL3 GPIO_AFRL_AFSEL3_Msk

   GPIO_AFRL_AFSEL4_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:2252
   --  unsupported macro: GPIO_AFRL_AFSEL4_Msk (0xFUL << GPIO_AFRL_AFSEL4_Pos)
   --  unsupported macro: GPIO_AFRL_AFSEL4 GPIO_AFRL_AFSEL4_Msk

   GPIO_AFRL_AFSEL5_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:2255
   --  unsupported macro: GPIO_AFRL_AFSEL5_Msk (0xFUL << GPIO_AFRL_AFSEL5_Pos)
   --  unsupported macro: GPIO_AFRL_AFSEL5 GPIO_AFRL_AFSEL5_Msk

   GPIO_AFRL_AFSEL6_Pos : constant := (24);  --  ../core/include/stm32f0/stm32f030x6.h:2258
   --  unsupported macro: GPIO_AFRL_AFSEL6_Msk (0xFUL << GPIO_AFRL_AFSEL6_Pos)
   --  unsupported macro: GPIO_AFRL_AFSEL6 GPIO_AFRL_AFSEL6_Msk

   GPIO_AFRL_AFSEL7_Pos : constant := (28);  --  ../core/include/stm32f0/stm32f030x6.h:2261
   --  unsupported macro: GPIO_AFRL_AFSEL7_Msk (0xFUL << GPIO_AFRL_AFSEL7_Pos)
   --  unsupported macro: GPIO_AFRL_AFSEL7 GPIO_AFRL_AFSEL7_Msk
   --  unsupported macro: GPIO_AFRL_AFRL0_Pos GPIO_AFRL_AFSEL0_Pos
   --  unsupported macro: GPIO_AFRL_AFRL0_Msk GPIO_AFRL_AFSEL0_Msk
   --  unsupported macro: GPIO_AFRL_AFRL0 GPIO_AFRL_AFSEL0
   --  unsupported macro: GPIO_AFRL_AFRL1_Pos GPIO_AFRL_AFSEL1_Pos
   --  unsupported macro: GPIO_AFRL_AFRL1_Msk GPIO_AFRL_AFSEL1_Msk
   --  unsupported macro: GPIO_AFRL_AFRL1 GPIO_AFRL_AFSEL1
   --  unsupported macro: GPIO_AFRL_AFRL2_Pos GPIO_AFRL_AFSEL2_Pos
   --  unsupported macro: GPIO_AFRL_AFRL2_Msk GPIO_AFRL_AFSEL2_Msk
   --  unsupported macro: GPIO_AFRL_AFRL2 GPIO_AFRL_AFSEL2
   --  unsupported macro: GPIO_AFRL_AFRL3_Pos GPIO_AFRL_AFSEL3_Pos
   --  unsupported macro: GPIO_AFRL_AFRL3_Msk GPIO_AFRL_AFSEL3_Msk
   --  unsupported macro: GPIO_AFRL_AFRL3 GPIO_AFRL_AFSEL3
   --  unsupported macro: GPIO_AFRL_AFRL4_Pos GPIO_AFRL_AFSEL4_Pos
   --  unsupported macro: GPIO_AFRL_AFRL4_Msk GPIO_AFRL_AFSEL4_Msk
   --  unsupported macro: GPIO_AFRL_AFRL4 GPIO_AFRL_AFSEL4
   --  unsupported macro: GPIO_AFRL_AFRL5_Pos GPIO_AFRL_AFSEL5_Pos
   --  unsupported macro: GPIO_AFRL_AFRL5_Msk GPIO_AFRL_AFSEL5_Msk
   --  unsupported macro: GPIO_AFRL_AFRL5 GPIO_AFRL_AFSEL5
   --  unsupported macro: GPIO_AFRL_AFRL6_Pos GPIO_AFRL_AFSEL6_Pos
   --  unsupported macro: GPIO_AFRL_AFRL6_Msk GPIO_AFRL_AFSEL6_Msk
   --  unsupported macro: GPIO_AFRL_AFRL6 GPIO_AFRL_AFSEL6
   --  unsupported macro: GPIO_AFRL_AFRL7_Pos GPIO_AFRL_AFSEL7_Pos
   --  unsupported macro: GPIO_AFRL_AFRL7_Msk GPIO_AFRL_AFSEL7_Msk
   --  unsupported macro: GPIO_AFRL_AFRL7 GPIO_AFRL_AFSEL7

   GPIO_AFRH_AFSEL8_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2292
   --  unsupported macro: GPIO_AFRH_AFSEL8_Msk (0xFUL << GPIO_AFRH_AFSEL8_Pos)
   --  unsupported macro: GPIO_AFRH_AFSEL8 GPIO_AFRH_AFSEL8_Msk

   GPIO_AFRH_AFSEL9_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:2295
   --  unsupported macro: GPIO_AFRH_AFSEL9_Msk (0xFUL << GPIO_AFRH_AFSEL9_Pos)
   --  unsupported macro: GPIO_AFRH_AFSEL9 GPIO_AFRH_AFSEL9_Msk

   GPIO_AFRH_AFSEL10_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2298
   --  unsupported macro: GPIO_AFRH_AFSEL10_Msk (0xFUL << GPIO_AFRH_AFSEL10_Pos)
   --  unsupported macro: GPIO_AFRH_AFSEL10 GPIO_AFRH_AFSEL10_Msk

   GPIO_AFRH_AFSEL11_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:2301
   --  unsupported macro: GPIO_AFRH_AFSEL11_Msk (0xFUL << GPIO_AFRH_AFSEL11_Pos)
   --  unsupported macro: GPIO_AFRH_AFSEL11 GPIO_AFRH_AFSEL11_Msk

   GPIO_AFRH_AFSEL12_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:2304
   --  unsupported macro: GPIO_AFRH_AFSEL12_Msk (0xFUL << GPIO_AFRH_AFSEL12_Pos)
   --  unsupported macro: GPIO_AFRH_AFSEL12 GPIO_AFRH_AFSEL12_Msk

   GPIO_AFRH_AFSEL13_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:2307
   --  unsupported macro: GPIO_AFRH_AFSEL13_Msk (0xFUL << GPIO_AFRH_AFSEL13_Pos)
   --  unsupported macro: GPIO_AFRH_AFSEL13 GPIO_AFRH_AFSEL13_Msk

   GPIO_AFRH_AFSEL14_Pos : constant := (24);  --  ../core/include/stm32f0/stm32f030x6.h:2310
   --  unsupported macro: GPIO_AFRH_AFSEL14_Msk (0xFUL << GPIO_AFRH_AFSEL14_Pos)
   --  unsupported macro: GPIO_AFRH_AFSEL14 GPIO_AFRH_AFSEL14_Msk

   GPIO_AFRH_AFSEL15_Pos : constant := (28);  --  ../core/include/stm32f0/stm32f030x6.h:2313
   --  unsupported macro: GPIO_AFRH_AFSEL15_Msk (0xFUL << GPIO_AFRH_AFSEL15_Pos)
   --  unsupported macro: GPIO_AFRH_AFSEL15 GPIO_AFRH_AFSEL15_Msk
   --  unsupported macro: GPIO_AFRH_AFRH0_Pos GPIO_AFRH_AFSEL8_Pos
   --  unsupported macro: GPIO_AFRH_AFRH0_Msk GPIO_AFRH_AFSEL8_Msk
   --  unsupported macro: GPIO_AFRH_AFRH0 GPIO_AFRH_AFSEL8
   --  unsupported macro: GPIO_AFRH_AFRH1_Pos GPIO_AFRH_AFSEL9_Pos
   --  unsupported macro: GPIO_AFRH_AFRH1_Msk GPIO_AFRH_AFSEL9_Msk
   --  unsupported macro: GPIO_AFRH_AFRH1 GPIO_AFRH_AFSEL9
   --  unsupported macro: GPIO_AFRH_AFRH2_Pos GPIO_AFRH_AFSEL10_Pos
   --  unsupported macro: GPIO_AFRH_AFRH2_Msk GPIO_AFRH_AFSEL10_Msk
   --  unsupported macro: GPIO_AFRH_AFRH2 GPIO_AFRH_AFSEL10
   --  unsupported macro: GPIO_AFRH_AFRH3_Pos GPIO_AFRH_AFSEL11_Pos
   --  unsupported macro: GPIO_AFRH_AFRH3_Msk GPIO_AFRH_AFSEL11_Msk
   --  unsupported macro: GPIO_AFRH_AFRH3 GPIO_AFRH_AFSEL11
   --  unsupported macro: GPIO_AFRH_AFRH4_Pos GPIO_AFRH_AFSEL12_Pos
   --  unsupported macro: GPIO_AFRH_AFRH4_Msk GPIO_AFRH_AFSEL12_Msk
   --  unsupported macro: GPIO_AFRH_AFRH4 GPIO_AFRH_AFSEL12
   --  unsupported macro: GPIO_AFRH_AFRH5_Pos GPIO_AFRH_AFSEL13_Pos
   --  unsupported macro: GPIO_AFRH_AFRH5_Msk GPIO_AFRH_AFSEL13_Msk
   --  unsupported macro: GPIO_AFRH_AFRH5 GPIO_AFRH_AFSEL13
   --  unsupported macro: GPIO_AFRH_AFRH6_Pos GPIO_AFRH_AFSEL14_Pos
   --  unsupported macro: GPIO_AFRH_AFRH6_Msk GPIO_AFRH_AFSEL14_Msk
   --  unsupported macro: GPIO_AFRH_AFRH6 GPIO_AFRH_AFSEL14
   --  unsupported macro: GPIO_AFRH_AFRH7_Pos GPIO_AFRH_AFSEL15_Pos
   --  unsupported macro: GPIO_AFRH_AFRH7_Msk GPIO_AFRH_AFSEL15_Msk
   --  unsupported macro: GPIO_AFRH_AFRH7 GPIO_AFRH_AFSEL15

   GPIO_BRR_BR_0 : constant := (16#00000001#);  --  ../core/include/stm32f0/stm32f030x6.h:2344
   GPIO_BRR_BR_1 : constant := (16#00000002#);  --  ../core/include/stm32f0/stm32f030x6.h:2345
   GPIO_BRR_BR_2 : constant := (16#00000004#);  --  ../core/include/stm32f0/stm32f030x6.h:2346
   GPIO_BRR_BR_3 : constant := (16#00000008#);  --  ../core/include/stm32f0/stm32f030x6.h:2347
   GPIO_BRR_BR_4 : constant := (16#00000010#);  --  ../core/include/stm32f0/stm32f030x6.h:2348
   GPIO_BRR_BR_5 : constant := (16#00000020#);  --  ../core/include/stm32f0/stm32f030x6.h:2349
   GPIO_BRR_BR_6 : constant := (16#00000040#);  --  ../core/include/stm32f0/stm32f030x6.h:2350
   GPIO_BRR_BR_7 : constant := (16#00000080#);  --  ../core/include/stm32f0/stm32f030x6.h:2351
   GPIO_BRR_BR_8 : constant := (16#00000100#);  --  ../core/include/stm32f0/stm32f030x6.h:2352
   GPIO_BRR_BR_9 : constant := (16#00000200#);  --  ../core/include/stm32f0/stm32f030x6.h:2353
   GPIO_BRR_BR_10 : constant := (16#00000400#);  --  ../core/include/stm32f0/stm32f030x6.h:2354
   GPIO_BRR_BR_11 : constant := (16#00000800#);  --  ../core/include/stm32f0/stm32f030x6.h:2355
   GPIO_BRR_BR_12 : constant := (16#00001000#);  --  ../core/include/stm32f0/stm32f030x6.h:2356
   GPIO_BRR_BR_13 : constant := (16#00002000#);  --  ../core/include/stm32f0/stm32f030x6.h:2357
   GPIO_BRR_BR_14 : constant := (16#00004000#);  --  ../core/include/stm32f0/stm32f030x6.h:2358
   GPIO_BRR_BR_15 : constant := (16#00008000#);  --  ../core/include/stm32f0/stm32f030x6.h:2359

   I2C_CR1_PE_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2368
   --  unsupported macro: I2C_CR1_PE_Msk (0x1UL << I2C_CR1_PE_Pos)
   --  unsupported macro: I2C_CR1_PE I2C_CR1_PE_Msk

   I2C_CR1_TXIE_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:2371
   --  unsupported macro: I2C_CR1_TXIE_Msk (0x1UL << I2C_CR1_TXIE_Pos)
   --  unsupported macro: I2C_CR1_TXIE I2C_CR1_TXIE_Msk

   I2C_CR1_RXIE_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:2374
   --  unsupported macro: I2C_CR1_RXIE_Msk (0x1UL << I2C_CR1_RXIE_Pos)
   --  unsupported macro: I2C_CR1_RXIE I2C_CR1_RXIE_Msk

   I2C_CR1_ADDRIE_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:2377
   --  unsupported macro: I2C_CR1_ADDRIE_Msk (0x1UL << I2C_CR1_ADDRIE_Pos)
   --  unsupported macro: I2C_CR1_ADDRIE I2C_CR1_ADDRIE_Msk

   I2C_CR1_NACKIE_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:2380
   --  unsupported macro: I2C_CR1_NACKIE_Msk (0x1UL << I2C_CR1_NACKIE_Pos)
   --  unsupported macro: I2C_CR1_NACKIE I2C_CR1_NACKIE_Msk

   I2C_CR1_STOPIE_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:2383
   --  unsupported macro: I2C_CR1_STOPIE_Msk (0x1UL << I2C_CR1_STOPIE_Pos)
   --  unsupported macro: I2C_CR1_STOPIE I2C_CR1_STOPIE_Msk

   I2C_CR1_TCIE_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:2386
   --  unsupported macro: I2C_CR1_TCIE_Msk (0x1UL << I2C_CR1_TCIE_Pos)
   --  unsupported macro: I2C_CR1_TCIE I2C_CR1_TCIE_Msk

   I2C_CR1_ERRIE_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:2389
   --  unsupported macro: I2C_CR1_ERRIE_Msk (0x1UL << I2C_CR1_ERRIE_Pos)
   --  unsupported macro: I2C_CR1_ERRIE I2C_CR1_ERRIE_Msk

   I2C_CR1_DNF_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2392
   --  unsupported macro: I2C_CR1_DNF_Msk (0xFUL << I2C_CR1_DNF_Pos)
   --  unsupported macro: I2C_CR1_DNF I2C_CR1_DNF_Msk

   I2C_CR1_ANFOFF_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:2395
   --  unsupported macro: I2C_CR1_ANFOFF_Msk (0x1UL << I2C_CR1_ANFOFF_Pos)
   --  unsupported macro: I2C_CR1_ANFOFF I2C_CR1_ANFOFF_Msk

   I2C_CR1_SWRST_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:2398
   --  unsupported macro: I2C_CR1_SWRST_Msk (0x1UL << I2C_CR1_SWRST_Pos)
   --  unsupported macro: I2C_CR1_SWRST I2C_CR1_SWRST_Msk

   I2C_CR1_TXDMAEN_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:2401
   --  unsupported macro: I2C_CR1_TXDMAEN_Msk (0x1UL << I2C_CR1_TXDMAEN_Pos)
   --  unsupported macro: I2C_CR1_TXDMAEN I2C_CR1_TXDMAEN_Msk

   I2C_CR1_RXDMAEN_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:2404
   --  unsupported macro: I2C_CR1_RXDMAEN_Msk (0x1UL << I2C_CR1_RXDMAEN_Pos)
   --  unsupported macro: I2C_CR1_RXDMAEN I2C_CR1_RXDMAEN_Msk

   I2C_CR1_SBC_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:2407
   --  unsupported macro: I2C_CR1_SBC_Msk (0x1UL << I2C_CR1_SBC_Pos)
   --  unsupported macro: I2C_CR1_SBC I2C_CR1_SBC_Msk

   I2C_CR1_NOSTRETCH_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:2410
   --  unsupported macro: I2C_CR1_NOSTRETCH_Msk (0x1UL << I2C_CR1_NOSTRETCH_Pos)
   --  unsupported macro: I2C_CR1_NOSTRETCH I2C_CR1_NOSTRETCH_Msk

   I2C_CR1_GCEN_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:2413
   --  unsupported macro: I2C_CR1_GCEN_Msk (0x1UL << I2C_CR1_GCEN_Pos)
   --  unsupported macro: I2C_CR1_GCEN I2C_CR1_GCEN_Msk

   I2C_CR1_SMBHEN_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:2416
   --  unsupported macro: I2C_CR1_SMBHEN_Msk (0x1UL << I2C_CR1_SMBHEN_Pos)
   --  unsupported macro: I2C_CR1_SMBHEN I2C_CR1_SMBHEN_Msk

   I2C_CR1_SMBDEN_Pos : constant := (21);  --  ../core/include/stm32f0/stm32f030x6.h:2419
   --  unsupported macro: I2C_CR1_SMBDEN_Msk (0x1UL << I2C_CR1_SMBDEN_Pos)
   --  unsupported macro: I2C_CR1_SMBDEN I2C_CR1_SMBDEN_Msk

   I2C_CR1_ALERTEN_Pos : constant := (22);  --  ../core/include/stm32f0/stm32f030x6.h:2422
   --  unsupported macro: I2C_CR1_ALERTEN_Msk (0x1UL << I2C_CR1_ALERTEN_Pos)
   --  unsupported macro: I2C_CR1_ALERTEN I2C_CR1_ALERTEN_Msk

   I2C_CR1_PECEN_Pos : constant := (23);  --  ../core/include/stm32f0/stm32f030x6.h:2425
   --  unsupported macro: I2C_CR1_PECEN_Msk (0x1UL << I2C_CR1_PECEN_Pos)
   --  unsupported macro: I2C_CR1_PECEN I2C_CR1_PECEN_Msk

   I2C_CR2_SADD_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2430
   --  unsupported macro: I2C_CR2_SADD_Msk (0x3FFUL << I2C_CR2_SADD_Pos)
   --  unsupported macro: I2C_CR2_SADD I2C_CR2_SADD_Msk

   I2C_CR2_RD_WRN_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:2433
   --  unsupported macro: I2C_CR2_RD_WRN_Msk (0x1UL << I2C_CR2_RD_WRN_Pos)
   --  unsupported macro: I2C_CR2_RD_WRN I2C_CR2_RD_WRN_Msk

   I2C_CR2_ADD10_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:2436
   --  unsupported macro: I2C_CR2_ADD10_Msk (0x1UL << I2C_CR2_ADD10_Pos)
   --  unsupported macro: I2C_CR2_ADD10 I2C_CR2_ADD10_Msk

   I2C_CR2_HEAD10R_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:2439
   --  unsupported macro: I2C_CR2_HEAD10R_Msk (0x1UL << I2C_CR2_HEAD10R_Pos)
   --  unsupported macro: I2C_CR2_HEAD10R I2C_CR2_HEAD10R_Msk

   I2C_CR2_START_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:2442
   --  unsupported macro: I2C_CR2_START_Msk (0x1UL << I2C_CR2_START_Pos)
   --  unsupported macro: I2C_CR2_START I2C_CR2_START_Msk

   I2C_CR2_STOP_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:2445
   --  unsupported macro: I2C_CR2_STOP_Msk (0x1UL << I2C_CR2_STOP_Pos)
   --  unsupported macro: I2C_CR2_STOP I2C_CR2_STOP_Msk

   I2C_CR2_NACK_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:2448
   --  unsupported macro: I2C_CR2_NACK_Msk (0x1UL << I2C_CR2_NACK_Pos)
   --  unsupported macro: I2C_CR2_NACK I2C_CR2_NACK_Msk

   I2C_CR2_NBYTES_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:2451
   --  unsupported macro: I2C_CR2_NBYTES_Msk (0xFFUL << I2C_CR2_NBYTES_Pos)
   --  unsupported macro: I2C_CR2_NBYTES I2C_CR2_NBYTES_Msk

   I2C_CR2_RELOAD_Pos : constant := (24);  --  ../core/include/stm32f0/stm32f030x6.h:2454
   --  unsupported macro: I2C_CR2_RELOAD_Msk (0x1UL << I2C_CR2_RELOAD_Pos)
   --  unsupported macro: I2C_CR2_RELOAD I2C_CR2_RELOAD_Msk

   I2C_CR2_AUTOEND_Pos : constant := (25);  --  ../core/include/stm32f0/stm32f030x6.h:2457
   --  unsupported macro: I2C_CR2_AUTOEND_Msk (0x1UL << I2C_CR2_AUTOEND_Pos)
   --  unsupported macro: I2C_CR2_AUTOEND I2C_CR2_AUTOEND_Msk

   I2C_CR2_PECBYTE_Pos : constant := (26);  --  ../core/include/stm32f0/stm32f030x6.h:2460
   --  unsupported macro: I2C_CR2_PECBYTE_Msk (0x1UL << I2C_CR2_PECBYTE_Pos)
   --  unsupported macro: I2C_CR2_PECBYTE I2C_CR2_PECBYTE_Msk

   I2C_OAR1_OA1_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2465
   --  unsupported macro: I2C_OAR1_OA1_Msk (0x3FFUL << I2C_OAR1_OA1_Pos)
   --  unsupported macro: I2C_OAR1_OA1 I2C_OAR1_OA1_Msk

   I2C_OAR1_OA1MODE_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:2468
   --  unsupported macro: I2C_OAR1_OA1MODE_Msk (0x1UL << I2C_OAR1_OA1MODE_Pos)
   --  unsupported macro: I2C_OAR1_OA1MODE I2C_OAR1_OA1MODE_Msk

   I2C_OAR1_OA1EN_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:2471
   --  unsupported macro: I2C_OAR1_OA1EN_Msk (0x1UL << I2C_OAR1_OA1EN_Pos)
   --  unsupported macro: I2C_OAR1_OA1EN I2C_OAR1_OA1EN_Msk

   I2C_OAR2_OA2_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:2476
   --  unsupported macro: I2C_OAR2_OA2_Msk (0x7FUL << I2C_OAR2_OA2_Pos)
   --  unsupported macro: I2C_OAR2_OA2 I2C_OAR2_OA2_Msk

   I2C_OAR2_OA2MSK_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2479
   --  unsupported macro: I2C_OAR2_OA2MSK_Msk (0x7UL << I2C_OAR2_OA2MSK_Pos)
   --  unsupported macro: I2C_OAR2_OA2MSK I2C_OAR2_OA2MSK_Msk

   I2C_OAR2_OA2NOMASK : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2482
   I2C_OAR2_OA2MASK01_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2483
   --  unsupported macro: I2C_OAR2_OA2MASK01_Msk (0x1UL << I2C_OAR2_OA2MASK01_Pos)
   --  unsupported macro: I2C_OAR2_OA2MASK01 I2C_OAR2_OA2MASK01_Msk

   I2C_OAR2_OA2MASK02_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:2486
   --  unsupported macro: I2C_OAR2_OA2MASK02_Msk (0x1UL << I2C_OAR2_OA2MASK02_Pos)
   --  unsupported macro: I2C_OAR2_OA2MASK02 I2C_OAR2_OA2MASK02_Msk

   I2C_OAR2_OA2MASK03_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2489
   --  unsupported macro: I2C_OAR2_OA2MASK03_Msk (0x3UL << I2C_OAR2_OA2MASK03_Pos)
   --  unsupported macro: I2C_OAR2_OA2MASK03 I2C_OAR2_OA2MASK03_Msk

   I2C_OAR2_OA2MASK04_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:2492
   --  unsupported macro: I2C_OAR2_OA2MASK04_Msk (0x1UL << I2C_OAR2_OA2MASK04_Pos)
   --  unsupported macro: I2C_OAR2_OA2MASK04 I2C_OAR2_OA2MASK04_Msk

   I2C_OAR2_OA2MASK05_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2495
   --  unsupported macro: I2C_OAR2_OA2MASK05_Msk (0x5UL << I2C_OAR2_OA2MASK05_Pos)
   --  unsupported macro: I2C_OAR2_OA2MASK05 I2C_OAR2_OA2MASK05_Msk

   I2C_OAR2_OA2MASK06_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:2498
   --  unsupported macro: I2C_OAR2_OA2MASK06_Msk (0x3UL << I2C_OAR2_OA2MASK06_Pos)
   --  unsupported macro: I2C_OAR2_OA2MASK06 I2C_OAR2_OA2MASK06_Msk

   I2C_OAR2_OA2MASK07_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2501
   --  unsupported macro: I2C_OAR2_OA2MASK07_Msk (0x7UL << I2C_OAR2_OA2MASK07_Pos)
   --  unsupported macro: I2C_OAR2_OA2MASK07 I2C_OAR2_OA2MASK07_Msk

   I2C_OAR2_OA2EN_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:2504
   --  unsupported macro: I2C_OAR2_OA2EN_Msk (0x1UL << I2C_OAR2_OA2EN_Pos)
   --  unsupported macro: I2C_OAR2_OA2EN I2C_OAR2_OA2EN_Msk

   I2C_TIMINGR_SCLL_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2509
   --  unsupported macro: I2C_TIMINGR_SCLL_Msk (0xFFUL << I2C_TIMINGR_SCLL_Pos)
   --  unsupported macro: I2C_TIMINGR_SCLL I2C_TIMINGR_SCLL_Msk

   I2C_TIMINGR_SCLH_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2512
   --  unsupported macro: I2C_TIMINGR_SCLH_Msk (0xFFUL << I2C_TIMINGR_SCLH_Pos)
   --  unsupported macro: I2C_TIMINGR_SCLH I2C_TIMINGR_SCLH_Msk

   I2C_TIMINGR_SDADEL_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:2515
   --  unsupported macro: I2C_TIMINGR_SDADEL_Msk (0xFUL << I2C_TIMINGR_SDADEL_Pos)
   --  unsupported macro: I2C_TIMINGR_SDADEL I2C_TIMINGR_SDADEL_Msk

   I2C_TIMINGR_SCLDEL_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:2518
   --  unsupported macro: I2C_TIMINGR_SCLDEL_Msk (0xFUL << I2C_TIMINGR_SCLDEL_Pos)
   --  unsupported macro: I2C_TIMINGR_SCLDEL I2C_TIMINGR_SCLDEL_Msk

   I2C_TIMINGR_PRESC_Pos : constant := (28);  --  ../core/include/stm32f0/stm32f030x6.h:2521
   --  unsupported macro: I2C_TIMINGR_PRESC_Msk (0xFUL << I2C_TIMINGR_PRESC_Pos)
   --  unsupported macro: I2C_TIMINGR_PRESC I2C_TIMINGR_PRESC_Msk

   I2C_TIMEOUTR_TIMEOUTA_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2526
   --  unsupported macro: I2C_TIMEOUTR_TIMEOUTA_Msk (0xFFFUL << I2C_TIMEOUTR_TIMEOUTA_Pos)
   --  unsupported macro: I2C_TIMEOUTR_TIMEOUTA I2C_TIMEOUTR_TIMEOUTA_Msk

   I2C_TIMEOUTR_TIDLE_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:2529
   --  unsupported macro: I2C_TIMEOUTR_TIDLE_Msk (0x1UL << I2C_TIMEOUTR_TIDLE_Pos)
   --  unsupported macro: I2C_TIMEOUTR_TIDLE I2C_TIMEOUTR_TIDLE_Msk

   I2C_TIMEOUTR_TIMOUTEN_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:2532
   --  unsupported macro: I2C_TIMEOUTR_TIMOUTEN_Msk (0x1UL << I2C_TIMEOUTR_TIMOUTEN_Pos)
   --  unsupported macro: I2C_TIMEOUTR_TIMOUTEN I2C_TIMEOUTR_TIMOUTEN_Msk

   I2C_TIMEOUTR_TIMEOUTB_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:2535
   --  unsupported macro: I2C_TIMEOUTR_TIMEOUTB_Msk (0xFFFUL << I2C_TIMEOUTR_TIMEOUTB_Pos)
   --  unsupported macro: I2C_TIMEOUTR_TIMEOUTB I2C_TIMEOUTR_TIMEOUTB_Msk

   I2C_TIMEOUTR_TEXTEN_Pos : constant := (31);  --  ../core/include/stm32f0/stm32f030x6.h:2538
   --  unsupported macro: I2C_TIMEOUTR_TEXTEN_Msk (0x1UL << I2C_TIMEOUTR_TEXTEN_Pos)
   --  unsupported macro: I2C_TIMEOUTR_TEXTEN I2C_TIMEOUTR_TEXTEN_Msk

   I2C_ISR_TXE_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2543
   --  unsupported macro: I2C_ISR_TXE_Msk (0x1UL << I2C_ISR_TXE_Pos)
   --  unsupported macro: I2C_ISR_TXE I2C_ISR_TXE_Msk

   I2C_ISR_TXIS_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:2546
   --  unsupported macro: I2C_ISR_TXIS_Msk (0x1UL << I2C_ISR_TXIS_Pos)
   --  unsupported macro: I2C_ISR_TXIS I2C_ISR_TXIS_Msk

   I2C_ISR_RXNE_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:2549
   --  unsupported macro: I2C_ISR_RXNE_Msk (0x1UL << I2C_ISR_RXNE_Pos)
   --  unsupported macro: I2C_ISR_RXNE I2C_ISR_RXNE_Msk

   I2C_ISR_ADDR_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:2552
   --  unsupported macro: I2C_ISR_ADDR_Msk (0x1UL << I2C_ISR_ADDR_Pos)
   --  unsupported macro: I2C_ISR_ADDR I2C_ISR_ADDR_Msk

   I2C_ISR_NACKF_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:2555
   --  unsupported macro: I2C_ISR_NACKF_Msk (0x1UL << I2C_ISR_NACKF_Pos)
   --  unsupported macro: I2C_ISR_NACKF I2C_ISR_NACKF_Msk

   I2C_ISR_STOPF_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:2558
   --  unsupported macro: I2C_ISR_STOPF_Msk (0x1UL << I2C_ISR_STOPF_Pos)
   --  unsupported macro: I2C_ISR_STOPF I2C_ISR_STOPF_Msk

   I2C_ISR_TC_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:2561
   --  unsupported macro: I2C_ISR_TC_Msk (0x1UL << I2C_ISR_TC_Pos)
   --  unsupported macro: I2C_ISR_TC I2C_ISR_TC_Msk

   I2C_ISR_TCR_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:2564
   --  unsupported macro: I2C_ISR_TCR_Msk (0x1UL << I2C_ISR_TCR_Pos)
   --  unsupported macro: I2C_ISR_TCR I2C_ISR_TCR_Msk

   I2C_ISR_BERR_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2567
   --  unsupported macro: I2C_ISR_BERR_Msk (0x1UL << I2C_ISR_BERR_Pos)
   --  unsupported macro: I2C_ISR_BERR I2C_ISR_BERR_Msk

   I2C_ISR_ARLO_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:2570
   --  unsupported macro: I2C_ISR_ARLO_Msk (0x1UL << I2C_ISR_ARLO_Pos)
   --  unsupported macro: I2C_ISR_ARLO I2C_ISR_ARLO_Msk

   I2C_ISR_OVR_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:2573
   --  unsupported macro: I2C_ISR_OVR_Msk (0x1UL << I2C_ISR_OVR_Pos)
   --  unsupported macro: I2C_ISR_OVR I2C_ISR_OVR_Msk

   I2C_ISR_PECERR_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:2576
   --  unsupported macro: I2C_ISR_PECERR_Msk (0x1UL << I2C_ISR_PECERR_Pos)
   --  unsupported macro: I2C_ISR_PECERR I2C_ISR_PECERR_Msk

   I2C_ISR_TIMEOUT_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:2579
   --  unsupported macro: I2C_ISR_TIMEOUT_Msk (0x1UL << I2C_ISR_TIMEOUT_Pos)
   --  unsupported macro: I2C_ISR_TIMEOUT I2C_ISR_TIMEOUT_Msk

   I2C_ISR_ALERT_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:2582
   --  unsupported macro: I2C_ISR_ALERT_Msk (0x1UL << I2C_ISR_ALERT_Pos)
   --  unsupported macro: I2C_ISR_ALERT I2C_ISR_ALERT_Msk

   I2C_ISR_BUSY_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:2585
   --  unsupported macro: I2C_ISR_BUSY_Msk (0x1UL << I2C_ISR_BUSY_Pos)
   --  unsupported macro: I2C_ISR_BUSY I2C_ISR_BUSY_Msk

   I2C_ISR_DIR_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:2588
   --  unsupported macro: I2C_ISR_DIR_Msk (0x1UL << I2C_ISR_DIR_Pos)
   --  unsupported macro: I2C_ISR_DIR I2C_ISR_DIR_Msk

   I2C_ISR_ADDCODE_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:2591
   --  unsupported macro: I2C_ISR_ADDCODE_Msk (0x7FUL << I2C_ISR_ADDCODE_Pos)
   --  unsupported macro: I2C_ISR_ADDCODE I2C_ISR_ADDCODE_Msk

   I2C_ICR_ADDRCF_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:2596
   --  unsupported macro: I2C_ICR_ADDRCF_Msk (0x1UL << I2C_ICR_ADDRCF_Pos)
   --  unsupported macro: I2C_ICR_ADDRCF I2C_ICR_ADDRCF_Msk

   I2C_ICR_NACKCF_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:2599
   --  unsupported macro: I2C_ICR_NACKCF_Msk (0x1UL << I2C_ICR_NACKCF_Pos)
   --  unsupported macro: I2C_ICR_NACKCF I2C_ICR_NACKCF_Msk

   I2C_ICR_STOPCF_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:2602
   --  unsupported macro: I2C_ICR_STOPCF_Msk (0x1UL << I2C_ICR_STOPCF_Pos)
   --  unsupported macro: I2C_ICR_STOPCF I2C_ICR_STOPCF_Msk

   I2C_ICR_BERRCF_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2605
   --  unsupported macro: I2C_ICR_BERRCF_Msk (0x1UL << I2C_ICR_BERRCF_Pos)
   --  unsupported macro: I2C_ICR_BERRCF I2C_ICR_BERRCF_Msk

   I2C_ICR_ARLOCF_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:2608
   --  unsupported macro: I2C_ICR_ARLOCF_Msk (0x1UL << I2C_ICR_ARLOCF_Pos)
   --  unsupported macro: I2C_ICR_ARLOCF I2C_ICR_ARLOCF_Msk

   I2C_ICR_OVRCF_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:2611
   --  unsupported macro: I2C_ICR_OVRCF_Msk (0x1UL << I2C_ICR_OVRCF_Pos)
   --  unsupported macro: I2C_ICR_OVRCF I2C_ICR_OVRCF_Msk

   I2C_ICR_PECCF_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:2614
   --  unsupported macro: I2C_ICR_PECCF_Msk (0x1UL << I2C_ICR_PECCF_Pos)
   --  unsupported macro: I2C_ICR_PECCF I2C_ICR_PECCF_Msk

   I2C_ICR_TIMOUTCF_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:2617
   --  unsupported macro: I2C_ICR_TIMOUTCF_Msk (0x1UL << I2C_ICR_TIMOUTCF_Pos)
   --  unsupported macro: I2C_ICR_TIMOUTCF I2C_ICR_TIMOUTCF_Msk

   I2C_ICR_ALERTCF_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:2620
   --  unsupported macro: I2C_ICR_ALERTCF_Msk (0x1UL << I2C_ICR_ALERTCF_Pos)
   --  unsupported macro: I2C_ICR_ALERTCF I2C_ICR_ALERTCF_Msk

   I2C_PECR_PEC_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2625
   --  unsupported macro: I2C_PECR_PEC_Msk (0xFFUL << I2C_PECR_PEC_Pos)
   --  unsupported macro: I2C_PECR_PEC I2C_PECR_PEC_Msk

   I2C_RXDR_RXDATA_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2630
   --  unsupported macro: I2C_RXDR_RXDATA_Msk (0xFFUL << I2C_RXDR_RXDATA_Pos)
   --  unsupported macro: I2C_RXDR_RXDATA I2C_RXDR_RXDATA_Msk

   I2C_TXDR_TXDATA_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2635
   --  unsupported macro: I2C_TXDR_TXDATA_Msk (0xFFUL << I2C_TXDR_TXDATA_Pos)
   --  unsupported macro: I2C_TXDR_TXDATA I2C_TXDR_TXDATA_Msk

   IWDG_KR_KEY_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2645
   --  unsupported macro: IWDG_KR_KEY_Msk (0xFFFFUL << IWDG_KR_KEY_Pos)
   --  unsupported macro: IWDG_KR_KEY IWDG_KR_KEY_Msk

   IWDG_PR_PR_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2650
   --  unsupported macro: IWDG_PR_PR_Msk (0x7UL << IWDG_PR_PR_Pos)
   --  unsupported macro: IWDG_PR_PR IWDG_PR_PR_Msk
   --  unsupported macro: IWDG_PR_PR_0 (0x1UL << IWDG_PR_PR_Pos)
   --  unsupported macro: IWDG_PR_PR_1 (0x2UL << IWDG_PR_PR_Pos)
   --  unsupported macro: IWDG_PR_PR_2 (0x4UL << IWDG_PR_PR_Pos)

   IWDG_RLR_RL_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2658
   --  unsupported macro: IWDG_RLR_RL_Msk (0xFFFUL << IWDG_RLR_RL_Pos)
   --  unsupported macro: IWDG_RLR_RL IWDG_RLR_RL_Msk

   IWDG_SR_PVU_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2663
   --  unsupported macro: IWDG_SR_PVU_Msk (0x1UL << IWDG_SR_PVU_Pos)
   --  unsupported macro: IWDG_SR_PVU IWDG_SR_PVU_Msk

   IWDG_SR_RVU_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:2666
   --  unsupported macro: IWDG_SR_RVU_Msk (0x1UL << IWDG_SR_RVU_Pos)
   --  unsupported macro: IWDG_SR_RVU IWDG_SR_RVU_Msk

   IWDG_SR_WVU_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:2669
   --  unsupported macro: IWDG_SR_WVU_Msk (0x1UL << IWDG_SR_WVU_Pos)
   --  unsupported macro: IWDG_SR_WVU IWDG_SR_WVU_Msk

   IWDG_WINR_WIN_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2674
   --  unsupported macro: IWDG_WINR_WIN_Msk (0xFFFUL << IWDG_WINR_WIN_Pos)
   --  unsupported macro: IWDG_WINR_WIN IWDG_WINR_WIN_Msk

   PWR_CR_LPDS_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2688
   --  unsupported macro: PWR_CR_LPDS_Msk (0x1UL << PWR_CR_LPDS_Pos)
   --  unsupported macro: PWR_CR_LPDS PWR_CR_LPDS_Msk

   PWR_CR_PDDS_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:2691
   --  unsupported macro: PWR_CR_PDDS_Msk (0x1UL << PWR_CR_PDDS_Pos)
   --  unsupported macro: PWR_CR_PDDS PWR_CR_PDDS_Msk

   PWR_CR_CWUF_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:2694
   --  unsupported macro: PWR_CR_CWUF_Msk (0x1UL << PWR_CR_CWUF_Pos)
   --  unsupported macro: PWR_CR_CWUF PWR_CR_CWUF_Msk

   PWR_CR_CSBF_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:2697
   --  unsupported macro: PWR_CR_CSBF_Msk (0x1UL << PWR_CR_CSBF_Pos)
   --  unsupported macro: PWR_CR_CSBF PWR_CR_CSBF_Msk

   PWR_CR_DBP_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2700
   --  unsupported macro: PWR_CR_DBP_Msk (0x1UL << PWR_CR_DBP_Pos)
   --  unsupported macro: PWR_CR_DBP PWR_CR_DBP_Msk

   PWR_CSR_WUF_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2705
   --  unsupported macro: PWR_CSR_WUF_Msk (0x1UL << PWR_CSR_WUF_Pos)
   --  unsupported macro: PWR_CSR_WUF PWR_CSR_WUF_Msk

   PWR_CSR_SBF_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:2708
   --  unsupported macro: PWR_CSR_SBF_Msk (0x1UL << PWR_CSR_SBF_Pos)
   --  unsupported macro: PWR_CSR_SBF PWR_CSR_SBF_Msk

   PWR_CSR_EWUP1_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2712
   --  unsupported macro: PWR_CSR_EWUP1_Msk (0x1UL << PWR_CSR_EWUP1_Pos)
   --  unsupported macro: PWR_CSR_EWUP1 PWR_CSR_EWUP1_Msk

   PWR_CSR_EWUP2_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:2715
   --  unsupported macro: PWR_CSR_EWUP2_Msk (0x1UL << PWR_CSR_EWUP2_Pos)
   --  unsupported macro: PWR_CSR_EWUP2 PWR_CSR_EWUP2_Msk

   RCC_CR_HSION_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2729
   --  unsupported macro: RCC_CR_HSION_Msk (0x1UL << RCC_CR_HSION_Pos)
   --  unsupported macro: RCC_CR_HSION RCC_CR_HSION_Msk

   RCC_CR_HSIRDY_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:2732
   --  unsupported macro: RCC_CR_HSIRDY_Msk (0x1UL << RCC_CR_HSIRDY_Pos)
   --  unsupported macro: RCC_CR_HSIRDY RCC_CR_HSIRDY_Msk

   RCC_CR_HSITRIM_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:2736
   --  unsupported macro: RCC_CR_HSITRIM_Msk (0x1FUL << RCC_CR_HSITRIM_Pos)
   --  unsupported macro: RCC_CR_HSITRIM RCC_CR_HSITRIM_Msk
   --  unsupported macro: RCC_CR_HSITRIM_0 (0x01UL << RCC_CR_HSITRIM_Pos)
   --  unsupported macro: RCC_CR_HSITRIM_1 (0x02UL << RCC_CR_HSITRIM_Pos)
   --  unsupported macro: RCC_CR_HSITRIM_2 (0x04UL << RCC_CR_HSITRIM_Pos)
   --  unsupported macro: RCC_CR_HSITRIM_3 (0x08UL << RCC_CR_HSITRIM_Pos)
   --  unsupported macro: RCC_CR_HSITRIM_4 (0x10UL << RCC_CR_HSITRIM_Pos)

   RCC_CR_HSICAL_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2745
   --  unsupported macro: RCC_CR_HSICAL_Msk (0xFFUL << RCC_CR_HSICAL_Pos)
   --  unsupported macro: RCC_CR_HSICAL RCC_CR_HSICAL_Msk
   --  unsupported macro: RCC_CR_HSICAL_0 (0x01UL << RCC_CR_HSICAL_Pos)
   --  unsupported macro: RCC_CR_HSICAL_1 (0x02UL << RCC_CR_HSICAL_Pos)
   --  unsupported macro: RCC_CR_HSICAL_2 (0x04UL << RCC_CR_HSICAL_Pos)
   --  unsupported macro: RCC_CR_HSICAL_3 (0x08UL << RCC_CR_HSICAL_Pos)
   --  unsupported macro: RCC_CR_HSICAL_4 (0x10UL << RCC_CR_HSICAL_Pos)
   --  unsupported macro: RCC_CR_HSICAL_5 (0x20UL << RCC_CR_HSICAL_Pos)
   --  unsupported macro: RCC_CR_HSICAL_6 (0x40UL << RCC_CR_HSICAL_Pos)
   --  unsupported macro: RCC_CR_HSICAL_7 (0x80UL << RCC_CR_HSICAL_Pos)

   RCC_CR_HSEON_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:2757
   --  unsupported macro: RCC_CR_HSEON_Msk (0x1UL << RCC_CR_HSEON_Pos)
   --  unsupported macro: RCC_CR_HSEON RCC_CR_HSEON_Msk

   RCC_CR_HSERDY_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:2760
   --  unsupported macro: RCC_CR_HSERDY_Msk (0x1UL << RCC_CR_HSERDY_Pos)
   --  unsupported macro: RCC_CR_HSERDY RCC_CR_HSERDY_Msk

   RCC_CR_HSEBYP_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:2763
   --  unsupported macro: RCC_CR_HSEBYP_Msk (0x1UL << RCC_CR_HSEBYP_Pos)
   --  unsupported macro: RCC_CR_HSEBYP RCC_CR_HSEBYP_Msk

   RCC_CR_CSSON_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:2766
   --  unsupported macro: RCC_CR_CSSON_Msk (0x1UL << RCC_CR_CSSON_Pos)
   --  unsupported macro: RCC_CR_CSSON RCC_CR_CSSON_Msk

   RCC_CR_PLLON_Pos : constant := (24);  --  ../core/include/stm32f0/stm32f030x6.h:2769
   --  unsupported macro: RCC_CR_PLLON_Msk (0x1UL << RCC_CR_PLLON_Pos)
   --  unsupported macro: RCC_CR_PLLON RCC_CR_PLLON_Msk

   RCC_CR_PLLRDY_Pos : constant := (25);  --  ../core/include/stm32f0/stm32f030x6.h:2772
   --  unsupported macro: RCC_CR_PLLRDY_Msk (0x1UL << RCC_CR_PLLRDY_Pos)
   --  unsupported macro: RCC_CR_PLLRDY RCC_CR_PLLRDY_Msk

   RCC_CFGR_SW_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2778
   --  unsupported macro: RCC_CFGR_SW_Msk (0x3UL << RCC_CFGR_SW_Pos)
   --  unsupported macro: RCC_CFGR_SW RCC_CFGR_SW_Msk
   --  unsupported macro: RCC_CFGR_SW_0 (0x1UL << RCC_CFGR_SW_Pos)
   --  unsupported macro: RCC_CFGR_SW_1 (0x2UL << RCC_CFGR_SW_Pos)

   RCC_CFGR_SW_HSI : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2784
   RCC_CFGR_SW_HSE : constant := (16#00000001#);  --  ../core/include/stm32f0/stm32f030x6.h:2785
   RCC_CFGR_SW_PLL : constant := (16#00000002#);  --  ../core/include/stm32f0/stm32f030x6.h:2786

   RCC_CFGR_SWS_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:2789
   --  unsupported macro: RCC_CFGR_SWS_Msk (0x3UL << RCC_CFGR_SWS_Pos)
   --  unsupported macro: RCC_CFGR_SWS RCC_CFGR_SWS_Msk
   --  unsupported macro: RCC_CFGR_SWS_0 (0x1UL << RCC_CFGR_SWS_Pos)
   --  unsupported macro: RCC_CFGR_SWS_1 (0x2UL << RCC_CFGR_SWS_Pos)

   RCC_CFGR_SWS_HSI : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2795
   RCC_CFGR_SWS_HSE : constant := (16#00000004#);  --  ../core/include/stm32f0/stm32f030x6.h:2796
   RCC_CFGR_SWS_PLL : constant := (16#00000008#);  --  ../core/include/stm32f0/stm32f030x6.h:2797

   RCC_CFGR_HPRE_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:2800
   --  unsupported macro: RCC_CFGR_HPRE_Msk (0xFUL << RCC_CFGR_HPRE_Pos)
   --  unsupported macro: RCC_CFGR_HPRE RCC_CFGR_HPRE_Msk
   --  unsupported macro: RCC_CFGR_HPRE_0 (0x1UL << RCC_CFGR_HPRE_Pos)
   --  unsupported macro: RCC_CFGR_HPRE_1 (0x2UL << RCC_CFGR_HPRE_Pos)
   --  unsupported macro: RCC_CFGR_HPRE_2 (0x4UL << RCC_CFGR_HPRE_Pos)
   --  unsupported macro: RCC_CFGR_HPRE_3 (0x8UL << RCC_CFGR_HPRE_Pos)

   RCC_CFGR_HPRE_DIV1 : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2808
   RCC_CFGR_HPRE_DIV2 : constant := (16#00000080#);  --  ../core/include/stm32f0/stm32f030x6.h:2809
   RCC_CFGR_HPRE_DIV4 : constant := (16#00000090#);  --  ../core/include/stm32f0/stm32f030x6.h:2810
   RCC_CFGR_HPRE_DIV8 : constant := (16#000000A0#);  --  ../core/include/stm32f0/stm32f030x6.h:2811
   RCC_CFGR_HPRE_DIV16 : constant := (16#000000B0#);  --  ../core/include/stm32f0/stm32f030x6.h:2812
   RCC_CFGR_HPRE_DIV64 : constant := (16#000000C0#);  --  ../core/include/stm32f0/stm32f030x6.h:2813
   RCC_CFGR_HPRE_DIV128 : constant := (16#000000D0#);  --  ../core/include/stm32f0/stm32f030x6.h:2814
   RCC_CFGR_HPRE_DIV256 : constant := (16#000000E0#);  --  ../core/include/stm32f0/stm32f030x6.h:2815
   RCC_CFGR_HPRE_DIV512 : constant := (16#000000F0#);  --  ../core/include/stm32f0/stm32f030x6.h:2816

   RCC_CFGR_PPRE_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2819
   --  unsupported macro: RCC_CFGR_PPRE_Msk (0x7UL << RCC_CFGR_PPRE_Pos)
   --  unsupported macro: RCC_CFGR_PPRE RCC_CFGR_PPRE_Msk
   --  unsupported macro: RCC_CFGR_PPRE_0 (0x1UL << RCC_CFGR_PPRE_Pos)
   --  unsupported macro: RCC_CFGR_PPRE_1 (0x2UL << RCC_CFGR_PPRE_Pos)
   --  unsupported macro: RCC_CFGR_PPRE_2 (0x4UL << RCC_CFGR_PPRE_Pos)

   RCC_CFGR_PPRE_DIV1 : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2826
   RCC_CFGR_PPRE_DIV2_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:2827
   --  unsupported macro: RCC_CFGR_PPRE_DIV2_Msk (0x1UL << RCC_CFGR_PPRE_DIV2_Pos)
   --  unsupported macro: RCC_CFGR_PPRE_DIV2 RCC_CFGR_PPRE_DIV2_Msk

   RCC_CFGR_PPRE_DIV4_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2830
   --  unsupported macro: RCC_CFGR_PPRE_DIV4_Msk (0x5UL << RCC_CFGR_PPRE_DIV4_Pos)
   --  unsupported macro: RCC_CFGR_PPRE_DIV4 RCC_CFGR_PPRE_DIV4_Msk

   RCC_CFGR_PPRE_DIV8_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:2833
   --  unsupported macro: RCC_CFGR_PPRE_DIV8_Msk (0x3UL << RCC_CFGR_PPRE_DIV8_Pos)
   --  unsupported macro: RCC_CFGR_PPRE_DIV8 RCC_CFGR_PPRE_DIV8_Msk

   RCC_CFGR_PPRE_DIV16_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2836
   --  unsupported macro: RCC_CFGR_PPRE_DIV16_Msk (0x7UL << RCC_CFGR_PPRE_DIV16_Pos)
   --  unsupported macro: RCC_CFGR_PPRE_DIV16 RCC_CFGR_PPRE_DIV16_Msk

   RCC_CFGR_ADCPRE_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:2841
   --  unsupported macro: RCC_CFGR_ADCPRE_Msk (0x1UL << RCC_CFGR_ADCPRE_Pos)
   --  unsupported macro: RCC_CFGR_ADCPRE RCC_CFGR_ADCPRE_Msk

   RCC_CFGR_ADCPRE_DIV2 : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2845
   RCC_CFGR_ADCPRE_DIV4 : constant := (16#00004000#);  --  ../core/include/stm32f0/stm32f030x6.h:2846

   RCC_CFGR_PLLSRC_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:2848
   --  unsupported macro: RCC_CFGR_PLLSRC_Msk (0x1UL << RCC_CFGR_PLLSRC_Pos)
   --  unsupported macro: RCC_CFGR_PLLSRC RCC_CFGR_PLLSRC_Msk

   RCC_CFGR_PLLSRC_HSI_DIV2 : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2851
   RCC_CFGR_PLLSRC_HSE_PREDIV : constant := (16#00010000#);  --  ../core/include/stm32f0/stm32f030x6.h:2852

   RCC_CFGR_PLLXTPRE_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:2854
   --  unsupported macro: RCC_CFGR_PLLXTPRE_Msk (0x1UL << RCC_CFGR_PLLXTPRE_Pos)
   --  unsupported macro: RCC_CFGR_PLLXTPRE RCC_CFGR_PLLXTPRE_Msk

   RCC_CFGR_PLLXTPRE_HSE_PREDIV_DIV1 : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2857
   RCC_CFGR_PLLXTPRE_HSE_PREDIV_DIV2 : constant := (16#00020000#);  --  ../core/include/stm32f0/stm32f030x6.h:2858

   RCC_CFGR_PLLMUL_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:2861
   --  unsupported macro: RCC_CFGR_PLLMUL_Msk (0xFUL << RCC_CFGR_PLLMUL_Pos)
   --  unsupported macro: RCC_CFGR_PLLMUL RCC_CFGR_PLLMUL_Msk
   --  unsupported macro: RCC_CFGR_PLLMUL_0 (0x1UL << RCC_CFGR_PLLMUL_Pos)
   --  unsupported macro: RCC_CFGR_PLLMUL_1 (0x2UL << RCC_CFGR_PLLMUL_Pos)
   --  unsupported macro: RCC_CFGR_PLLMUL_2 (0x4UL << RCC_CFGR_PLLMUL_Pos)
   --  unsupported macro: RCC_CFGR_PLLMUL_3 (0x8UL << RCC_CFGR_PLLMUL_Pos)

   RCC_CFGR_PLLMUL2 : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2869
   RCC_CFGR_PLLMUL3 : constant := (16#00040000#);  --  ../core/include/stm32f0/stm32f030x6.h:2870
   RCC_CFGR_PLLMUL4 : constant := (16#00080000#);  --  ../core/include/stm32f0/stm32f030x6.h:2871
   RCC_CFGR_PLLMUL5 : constant := (16#000C0000#);  --  ../core/include/stm32f0/stm32f030x6.h:2872
   RCC_CFGR_PLLMUL6 : constant := (16#00100000#);  --  ../core/include/stm32f0/stm32f030x6.h:2873
   RCC_CFGR_PLLMUL7 : constant := (16#00140000#);  --  ../core/include/stm32f0/stm32f030x6.h:2874
   RCC_CFGR_PLLMUL8 : constant := (16#00180000#);  --  ../core/include/stm32f0/stm32f030x6.h:2875
   RCC_CFGR_PLLMUL9 : constant := (16#001C0000#);  --  ../core/include/stm32f0/stm32f030x6.h:2876
   RCC_CFGR_PLLMUL10 : constant := (16#00200000#);  --  ../core/include/stm32f0/stm32f030x6.h:2877
   RCC_CFGR_PLLMUL11 : constant := (16#00240000#);  --  ../core/include/stm32f0/stm32f030x6.h:2878
   RCC_CFGR_PLLMUL12 : constant := (16#00280000#);  --  ../core/include/stm32f0/stm32f030x6.h:2879
   RCC_CFGR_PLLMUL13 : constant := (16#002C0000#);  --  ../core/include/stm32f0/stm32f030x6.h:2880
   RCC_CFGR_PLLMUL14 : constant := (16#00300000#);  --  ../core/include/stm32f0/stm32f030x6.h:2881
   RCC_CFGR_PLLMUL15 : constant := (16#00340000#);  --  ../core/include/stm32f0/stm32f030x6.h:2882
   RCC_CFGR_PLLMUL16 : constant := (16#00380000#);  --  ../core/include/stm32f0/stm32f030x6.h:2883

   RCC_CFGR_MCO_Pos : constant := (24);  --  ../core/include/stm32f0/stm32f030x6.h:2886
   --  unsupported macro: RCC_CFGR_MCO_Msk (0xFUL << RCC_CFGR_MCO_Pos)
   --  unsupported macro: RCC_CFGR_MCO RCC_CFGR_MCO_Msk
   --  unsupported macro: RCC_CFGR_MCO_0 (0x1UL << RCC_CFGR_MCO_Pos)
   --  unsupported macro: RCC_CFGR_MCO_1 (0x2UL << RCC_CFGR_MCO_Pos)
   --  unsupported macro: RCC_CFGR_MCO_2 (0x4UL << RCC_CFGR_MCO_Pos)

   RCC_CFGR_MCO_NOCLOCK : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2893
   RCC_CFGR_MCO_HSI14 : constant := (16#01000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2894
   RCC_CFGR_MCO_LSI : constant := (16#02000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2895
   RCC_CFGR_MCO_LSE : constant := (16#03000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2896
   RCC_CFGR_MCO_SYSCLK : constant := (16#04000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2897
   RCC_CFGR_MCO_HSI : constant := (16#05000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2898
   RCC_CFGR_MCO_HSE : constant := (16#06000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2899
   RCC_CFGR_MCO_PLL : constant := (16#07000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2900

   RCC_CFGR_MCOPRE_Pos : constant := (28);  --  ../core/include/stm32f0/stm32f030x6.h:2902
   --  unsupported macro: RCC_CFGR_MCOPRE_Msk (0x7UL << RCC_CFGR_MCOPRE_Pos)
   --  unsupported macro: RCC_CFGR_MCOPRE RCC_CFGR_MCOPRE_Msk

   RCC_CFGR_MCOPRE_DIV1 : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2905
   RCC_CFGR_MCOPRE_DIV2 : constant := (16#10000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2906
   RCC_CFGR_MCOPRE_DIV4 : constant := (16#20000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2907
   RCC_CFGR_MCOPRE_DIV8 : constant := (16#30000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2908
   RCC_CFGR_MCOPRE_DIV16 : constant := (16#40000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2909
   RCC_CFGR_MCOPRE_DIV32 : constant := (16#50000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2910
   RCC_CFGR_MCOPRE_DIV64 : constant := (16#60000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2911
   RCC_CFGR_MCOPRE_DIV128 : constant := (16#70000000#);  --  ../core/include/stm32f0/stm32f030x6.h:2912

   RCC_CFGR_PLLNODIV_Pos : constant := (31);  --  ../core/include/stm32f0/stm32f030x6.h:2914
   --  unsupported macro: RCC_CFGR_PLLNODIV_Msk (0x1UL << RCC_CFGR_PLLNODIV_Pos)
   --  unsupported macro: RCC_CFGR_PLLNODIV RCC_CFGR_PLLNODIV_Msk
   --  unsupported macro: RCC_CFGR_MCOSEL RCC_CFGR_MCO
   --  unsupported macro: RCC_CFGR_MCOSEL_0 RCC_CFGR_MCO_0
   --  unsupported macro: RCC_CFGR_MCOSEL_1 RCC_CFGR_MCO_1
   --  unsupported macro: RCC_CFGR_MCOSEL_2 RCC_CFGR_MCO_2
   --  unsupported macro: RCC_CFGR_MCOSEL_NOCLOCK RCC_CFGR_MCO_NOCLOCK
   --  unsupported macro: RCC_CFGR_MCOSEL_HSI14 RCC_CFGR_MCO_HSI14
   --  unsupported macro: RCC_CFGR_MCOSEL_LSI RCC_CFGR_MCO_LSI
   --  unsupported macro: RCC_CFGR_MCOSEL_LSE RCC_CFGR_MCO_LSE
   --  unsupported macro: RCC_CFGR_MCOSEL_SYSCLK RCC_CFGR_MCO_SYSCLK
   --  unsupported macro: RCC_CFGR_MCOSEL_HSI RCC_CFGR_MCO_HSI
   --  unsupported macro: RCC_CFGR_MCOSEL_HSE RCC_CFGR_MCO_HSE
   --  unsupported macro: RCC_CFGR_MCOSEL_PLL_DIV2 RCC_CFGR_MCO_PLL

   RCC_CIR_LSIRDYF_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2933
   --  unsupported macro: RCC_CIR_LSIRDYF_Msk (0x1UL << RCC_CIR_LSIRDYF_Pos)
   --  unsupported macro: RCC_CIR_LSIRDYF RCC_CIR_LSIRDYF_Msk

   RCC_CIR_LSERDYF_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:2936
   --  unsupported macro: RCC_CIR_LSERDYF_Msk (0x1UL << RCC_CIR_LSERDYF_Pos)
   --  unsupported macro: RCC_CIR_LSERDYF RCC_CIR_LSERDYF_Msk

   RCC_CIR_HSIRDYF_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:2939
   --  unsupported macro: RCC_CIR_HSIRDYF_Msk (0x1UL << RCC_CIR_HSIRDYF_Pos)
   --  unsupported macro: RCC_CIR_HSIRDYF RCC_CIR_HSIRDYF_Msk

   RCC_CIR_HSERDYF_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:2942
   --  unsupported macro: RCC_CIR_HSERDYF_Msk (0x1UL << RCC_CIR_HSERDYF_Pos)
   --  unsupported macro: RCC_CIR_HSERDYF RCC_CIR_HSERDYF_Msk

   RCC_CIR_PLLRDYF_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:2945
   --  unsupported macro: RCC_CIR_PLLRDYF_Msk (0x1UL << RCC_CIR_PLLRDYF_Pos)
   --  unsupported macro: RCC_CIR_PLLRDYF RCC_CIR_PLLRDYF_Msk

   RCC_CIR_HSI14RDYF_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:2948
   --  unsupported macro: RCC_CIR_HSI14RDYF_Msk (0x1UL << RCC_CIR_HSI14RDYF_Pos)
   --  unsupported macro: RCC_CIR_HSI14RDYF RCC_CIR_HSI14RDYF_Msk

   RCC_CIR_CSSF_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:2951
   --  unsupported macro: RCC_CIR_CSSF_Msk (0x1UL << RCC_CIR_CSSF_Pos)
   --  unsupported macro: RCC_CIR_CSSF RCC_CIR_CSSF_Msk

   RCC_CIR_LSIRDYIE_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:2954
   --  unsupported macro: RCC_CIR_LSIRDYIE_Msk (0x1UL << RCC_CIR_LSIRDYIE_Pos)
   --  unsupported macro: RCC_CIR_LSIRDYIE RCC_CIR_LSIRDYIE_Msk

   RCC_CIR_LSERDYIE_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:2957
   --  unsupported macro: RCC_CIR_LSERDYIE_Msk (0x1UL << RCC_CIR_LSERDYIE_Pos)
   --  unsupported macro: RCC_CIR_LSERDYIE RCC_CIR_LSERDYIE_Msk

   RCC_CIR_HSIRDYIE_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:2960
   --  unsupported macro: RCC_CIR_HSIRDYIE_Msk (0x1UL << RCC_CIR_HSIRDYIE_Pos)
   --  unsupported macro: RCC_CIR_HSIRDYIE RCC_CIR_HSIRDYIE_Msk

   RCC_CIR_HSERDYIE_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:2963
   --  unsupported macro: RCC_CIR_HSERDYIE_Msk (0x1UL << RCC_CIR_HSERDYIE_Pos)
   --  unsupported macro: RCC_CIR_HSERDYIE RCC_CIR_HSERDYIE_Msk

   RCC_CIR_PLLRDYIE_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:2966
   --  unsupported macro: RCC_CIR_PLLRDYIE_Msk (0x1UL << RCC_CIR_PLLRDYIE_Pos)
   --  unsupported macro: RCC_CIR_PLLRDYIE RCC_CIR_PLLRDYIE_Msk

   RCC_CIR_HSI14RDYIE_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:2969
   --  unsupported macro: RCC_CIR_HSI14RDYIE_Msk (0x1UL << RCC_CIR_HSI14RDYIE_Pos)
   --  unsupported macro: RCC_CIR_HSI14RDYIE RCC_CIR_HSI14RDYIE_Msk

   RCC_CIR_LSIRDYC_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:2972
   --  unsupported macro: RCC_CIR_LSIRDYC_Msk (0x1UL << RCC_CIR_LSIRDYC_Pos)
   --  unsupported macro: RCC_CIR_LSIRDYC RCC_CIR_LSIRDYC_Msk

   RCC_CIR_LSERDYC_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:2975
   --  unsupported macro: RCC_CIR_LSERDYC_Msk (0x1UL << RCC_CIR_LSERDYC_Pos)
   --  unsupported macro: RCC_CIR_LSERDYC RCC_CIR_LSERDYC_Msk

   RCC_CIR_HSIRDYC_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:2978
   --  unsupported macro: RCC_CIR_HSIRDYC_Msk (0x1UL << RCC_CIR_HSIRDYC_Pos)
   --  unsupported macro: RCC_CIR_HSIRDYC RCC_CIR_HSIRDYC_Msk

   RCC_CIR_HSERDYC_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:2981
   --  unsupported macro: RCC_CIR_HSERDYC_Msk (0x1UL << RCC_CIR_HSERDYC_Pos)
   --  unsupported macro: RCC_CIR_HSERDYC RCC_CIR_HSERDYC_Msk

   RCC_CIR_PLLRDYC_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:2984
   --  unsupported macro: RCC_CIR_PLLRDYC_Msk (0x1UL << RCC_CIR_PLLRDYC_Pos)
   --  unsupported macro: RCC_CIR_PLLRDYC RCC_CIR_PLLRDYC_Msk

   RCC_CIR_HSI14RDYC_Pos : constant := (21);  --  ../core/include/stm32f0/stm32f030x6.h:2987
   --  unsupported macro: RCC_CIR_HSI14RDYC_Msk (0x1UL << RCC_CIR_HSI14RDYC_Pos)
   --  unsupported macro: RCC_CIR_HSI14RDYC RCC_CIR_HSI14RDYC_Msk

   RCC_CIR_CSSC_Pos : constant := (23);  --  ../core/include/stm32f0/stm32f030x6.h:2990
   --  unsupported macro: RCC_CIR_CSSC_Msk (0x1UL << RCC_CIR_CSSC_Pos)
   --  unsupported macro: RCC_CIR_CSSC RCC_CIR_CSSC_Msk

   RCC_APB2RSTR_SYSCFGRST_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:2995
   --  unsupported macro: RCC_APB2RSTR_SYSCFGRST_Msk (0x1UL << RCC_APB2RSTR_SYSCFGRST_Pos)
   --  unsupported macro: RCC_APB2RSTR_SYSCFGRST RCC_APB2RSTR_SYSCFGRST_Msk

   RCC_APB2RSTR_ADCRST_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:2998
   --  unsupported macro: RCC_APB2RSTR_ADCRST_Msk (0x1UL << RCC_APB2RSTR_ADCRST_Pos)
   --  unsupported macro: RCC_APB2RSTR_ADCRST RCC_APB2RSTR_ADCRST_Msk

   RCC_APB2RSTR_TIM1RST_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:3001
   --  unsupported macro: RCC_APB2RSTR_TIM1RST_Msk (0x1UL << RCC_APB2RSTR_TIM1RST_Pos)
   --  unsupported macro: RCC_APB2RSTR_TIM1RST RCC_APB2RSTR_TIM1RST_Msk

   RCC_APB2RSTR_SPI1RST_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:3004
   --  unsupported macro: RCC_APB2RSTR_SPI1RST_Msk (0x1UL << RCC_APB2RSTR_SPI1RST_Pos)
   --  unsupported macro: RCC_APB2RSTR_SPI1RST RCC_APB2RSTR_SPI1RST_Msk

   RCC_APB2RSTR_USART1RST_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:3007
   --  unsupported macro: RCC_APB2RSTR_USART1RST_Msk (0x1UL << RCC_APB2RSTR_USART1RST_Pos)
   --  unsupported macro: RCC_APB2RSTR_USART1RST RCC_APB2RSTR_USART1RST_Msk

   RCC_APB2RSTR_TIM16RST_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:3010
   --  unsupported macro: RCC_APB2RSTR_TIM16RST_Msk (0x1UL << RCC_APB2RSTR_TIM16RST_Pos)
   --  unsupported macro: RCC_APB2RSTR_TIM16RST RCC_APB2RSTR_TIM16RST_Msk

   RCC_APB2RSTR_TIM17RST_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:3013
   --  unsupported macro: RCC_APB2RSTR_TIM17RST_Msk (0x1UL << RCC_APB2RSTR_TIM17RST_Pos)
   --  unsupported macro: RCC_APB2RSTR_TIM17RST RCC_APB2RSTR_TIM17RST_Msk

   RCC_APB2RSTR_DBGMCURST_Pos : constant := (22);  --  ../core/include/stm32f0/stm32f030x6.h:3016
   --  unsupported macro: RCC_APB2RSTR_DBGMCURST_Msk (0x1UL << RCC_APB2RSTR_DBGMCURST_Pos)
   --  unsupported macro: RCC_APB2RSTR_DBGMCURST RCC_APB2RSTR_DBGMCURST_Msk
   --  unsupported macro: RCC_APB2RSTR_ADC1RST RCC_APB2RSTR_ADCRST

   RCC_APB1RSTR_TIM3RST_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:3024
   --  unsupported macro: RCC_APB1RSTR_TIM3RST_Msk (0x1UL << RCC_APB1RSTR_TIM3RST_Pos)
   --  unsupported macro: RCC_APB1RSTR_TIM3RST RCC_APB1RSTR_TIM3RST_Msk

   RCC_APB1RSTR_TIM14RST_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3027
   --  unsupported macro: RCC_APB1RSTR_TIM14RST_Msk (0x1UL << RCC_APB1RSTR_TIM14RST_Pos)
   --  unsupported macro: RCC_APB1RSTR_TIM14RST RCC_APB1RSTR_TIM14RST_Msk

   RCC_APB1RSTR_WWDGRST_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:3030
   --  unsupported macro: RCC_APB1RSTR_WWDGRST_Msk (0x1UL << RCC_APB1RSTR_WWDGRST_Pos)
   --  unsupported macro: RCC_APB1RSTR_WWDGRST RCC_APB1RSTR_WWDGRST_Msk

   RCC_APB1RSTR_I2C1RST_Pos : constant := (21);  --  ../core/include/stm32f0/stm32f030x6.h:3033
   --  unsupported macro: RCC_APB1RSTR_I2C1RST_Msk (0x1UL << RCC_APB1RSTR_I2C1RST_Pos)
   --  unsupported macro: RCC_APB1RSTR_I2C1RST RCC_APB1RSTR_I2C1RST_Msk

   RCC_APB1RSTR_PWRRST_Pos : constant := (28);  --  ../core/include/stm32f0/stm32f030x6.h:3036
   --  unsupported macro: RCC_APB1RSTR_PWRRST_Msk (0x1UL << RCC_APB1RSTR_PWRRST_Pos)
   --  unsupported macro: RCC_APB1RSTR_PWRRST RCC_APB1RSTR_PWRRST_Msk

   RCC_AHBENR_DMAEN_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3041
   --  unsupported macro: RCC_AHBENR_DMAEN_Msk (0x1UL << RCC_AHBENR_DMAEN_Pos)
   --  unsupported macro: RCC_AHBENR_DMAEN RCC_AHBENR_DMAEN_Msk

   RCC_AHBENR_SRAMEN_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:3044
   --  unsupported macro: RCC_AHBENR_SRAMEN_Msk (0x1UL << RCC_AHBENR_SRAMEN_Pos)
   --  unsupported macro: RCC_AHBENR_SRAMEN RCC_AHBENR_SRAMEN_Msk

   RCC_AHBENR_FLITFEN_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:3047
   --  unsupported macro: RCC_AHBENR_FLITFEN_Msk (0x1UL << RCC_AHBENR_FLITFEN_Pos)
   --  unsupported macro: RCC_AHBENR_FLITFEN RCC_AHBENR_FLITFEN_Msk

   RCC_AHBENR_CRCEN_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:3050
   --  unsupported macro: RCC_AHBENR_CRCEN_Msk (0x1UL << RCC_AHBENR_CRCEN_Pos)
   --  unsupported macro: RCC_AHBENR_CRCEN RCC_AHBENR_CRCEN_Msk

   RCC_AHBENR_GPIOAEN_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:3053
   --  unsupported macro: RCC_AHBENR_GPIOAEN_Msk (0x1UL << RCC_AHBENR_GPIOAEN_Pos)
   --  unsupported macro: RCC_AHBENR_GPIOAEN RCC_AHBENR_GPIOAEN_Msk

   RCC_AHBENR_GPIOBEN_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:3056
   --  unsupported macro: RCC_AHBENR_GPIOBEN_Msk (0x1UL << RCC_AHBENR_GPIOBEN_Pos)
   --  unsupported macro: RCC_AHBENR_GPIOBEN RCC_AHBENR_GPIOBEN_Msk

   RCC_AHBENR_GPIOCEN_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:3059
   --  unsupported macro: RCC_AHBENR_GPIOCEN_Msk (0x1UL << RCC_AHBENR_GPIOCEN_Pos)
   --  unsupported macro: RCC_AHBENR_GPIOCEN RCC_AHBENR_GPIOCEN_Msk

   RCC_AHBENR_GPIODEN_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:3062
   --  unsupported macro: RCC_AHBENR_GPIODEN_Msk (0x1UL << RCC_AHBENR_GPIODEN_Pos)
   --  unsupported macro: RCC_AHBENR_GPIODEN RCC_AHBENR_GPIODEN_Msk

   RCC_AHBENR_GPIOFEN_Pos : constant := (22);  --  ../core/include/stm32f0/stm32f030x6.h:3065
   --  unsupported macro: RCC_AHBENR_GPIOFEN_Msk (0x1UL << RCC_AHBENR_GPIOFEN_Pos)
   --  unsupported macro: RCC_AHBENR_GPIOFEN RCC_AHBENR_GPIOFEN_Msk
   --  unsupported macro: RCC_AHBENR_DMA1EN RCC_AHBENR_DMAEN
   --  unsupported macro: RCC_AHBENR_TSEN RCC_AHBENR_TSCEN

   RCC_APB2ENR_SYSCFGCOMPEN_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3074
   --  unsupported macro: RCC_APB2ENR_SYSCFGCOMPEN_Msk (0x1UL << RCC_APB2ENR_SYSCFGCOMPEN_Pos)
   --  unsupported macro: RCC_APB2ENR_SYSCFGCOMPEN RCC_APB2ENR_SYSCFGCOMPEN_Msk

   RCC_APB2ENR_ADCEN_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:3077
   --  unsupported macro: RCC_APB2ENR_ADCEN_Msk (0x1UL << RCC_APB2ENR_ADCEN_Pos)
   --  unsupported macro: RCC_APB2ENR_ADCEN RCC_APB2ENR_ADCEN_Msk

   RCC_APB2ENR_TIM1EN_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:3080
   --  unsupported macro: RCC_APB2ENR_TIM1EN_Msk (0x1UL << RCC_APB2ENR_TIM1EN_Pos)
   --  unsupported macro: RCC_APB2ENR_TIM1EN RCC_APB2ENR_TIM1EN_Msk

   RCC_APB2ENR_SPI1EN_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:3083
   --  unsupported macro: RCC_APB2ENR_SPI1EN_Msk (0x1UL << RCC_APB2ENR_SPI1EN_Pos)
   --  unsupported macro: RCC_APB2ENR_SPI1EN RCC_APB2ENR_SPI1EN_Msk

   RCC_APB2ENR_USART1EN_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:3086
   --  unsupported macro: RCC_APB2ENR_USART1EN_Msk (0x1UL << RCC_APB2ENR_USART1EN_Pos)
   --  unsupported macro: RCC_APB2ENR_USART1EN RCC_APB2ENR_USART1EN_Msk

   RCC_APB2ENR_TIM16EN_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:3089
   --  unsupported macro: RCC_APB2ENR_TIM16EN_Msk (0x1UL << RCC_APB2ENR_TIM16EN_Pos)
   --  unsupported macro: RCC_APB2ENR_TIM16EN RCC_APB2ENR_TIM16EN_Msk

   RCC_APB2ENR_TIM17EN_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:3092
   --  unsupported macro: RCC_APB2ENR_TIM17EN_Msk (0x1UL << RCC_APB2ENR_TIM17EN_Pos)
   --  unsupported macro: RCC_APB2ENR_TIM17EN RCC_APB2ENR_TIM17EN_Msk

   RCC_APB2ENR_DBGMCUEN_Pos : constant := (22);  --  ../core/include/stm32f0/stm32f030x6.h:3095
   --  unsupported macro: RCC_APB2ENR_DBGMCUEN_Msk (0x1UL << RCC_APB2ENR_DBGMCUEN_Pos)
   --  unsupported macro: RCC_APB2ENR_DBGMCUEN RCC_APB2ENR_DBGMCUEN_Msk
   --  unsupported macro: RCC_APB2ENR_SYSCFGEN RCC_APB2ENR_SYSCFGCOMPEN
   --  unsupported macro: RCC_APB2ENR_ADC1EN RCC_APB2ENR_ADCEN

   RCC_APB1ENR_TIM3EN_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:3104
   --  unsupported macro: RCC_APB1ENR_TIM3EN_Msk (0x1UL << RCC_APB1ENR_TIM3EN_Pos)
   --  unsupported macro: RCC_APB1ENR_TIM3EN RCC_APB1ENR_TIM3EN_Msk

   RCC_APB1ENR_TIM14EN_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3107
   --  unsupported macro: RCC_APB1ENR_TIM14EN_Msk (0x1UL << RCC_APB1ENR_TIM14EN_Pos)
   --  unsupported macro: RCC_APB1ENR_TIM14EN RCC_APB1ENR_TIM14EN_Msk

   RCC_APB1ENR_WWDGEN_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:3110
   --  unsupported macro: RCC_APB1ENR_WWDGEN_Msk (0x1UL << RCC_APB1ENR_WWDGEN_Pos)
   --  unsupported macro: RCC_APB1ENR_WWDGEN RCC_APB1ENR_WWDGEN_Msk

   RCC_APB1ENR_I2C1EN_Pos : constant := (21);  --  ../core/include/stm32f0/stm32f030x6.h:3113
   --  unsupported macro: RCC_APB1ENR_I2C1EN_Msk (0x1UL << RCC_APB1ENR_I2C1EN_Pos)
   --  unsupported macro: RCC_APB1ENR_I2C1EN RCC_APB1ENR_I2C1EN_Msk

   RCC_APB1ENR_PWREN_Pos : constant := (28);  --  ../core/include/stm32f0/stm32f030x6.h:3116
   --  unsupported macro: RCC_APB1ENR_PWREN_Msk (0x1UL << RCC_APB1ENR_PWREN_Pos)
   --  unsupported macro: RCC_APB1ENR_PWREN RCC_APB1ENR_PWREN_Msk

   RCC_BDCR_LSEON_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3121
   --  unsupported macro: RCC_BDCR_LSEON_Msk (0x1UL << RCC_BDCR_LSEON_Pos)
   --  unsupported macro: RCC_BDCR_LSEON RCC_BDCR_LSEON_Msk

   RCC_BDCR_LSERDY_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:3124
   --  unsupported macro: RCC_BDCR_LSERDY_Msk (0x1UL << RCC_BDCR_LSERDY_Pos)
   --  unsupported macro: RCC_BDCR_LSERDY RCC_BDCR_LSERDY_Msk

   RCC_BDCR_LSEBYP_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:3127
   --  unsupported macro: RCC_BDCR_LSEBYP_Msk (0x1UL << RCC_BDCR_LSEBYP_Pos)
   --  unsupported macro: RCC_BDCR_LSEBYP RCC_BDCR_LSEBYP_Msk

   RCC_BDCR_LSEDRV_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:3131
   --  unsupported macro: RCC_BDCR_LSEDRV_Msk (0x3UL << RCC_BDCR_LSEDRV_Pos)
   --  unsupported macro: RCC_BDCR_LSEDRV RCC_BDCR_LSEDRV_Msk
   --  unsupported macro: RCC_BDCR_LSEDRV_0 (0x1UL << RCC_BDCR_LSEDRV_Pos)
   --  unsupported macro: RCC_BDCR_LSEDRV_1 (0x2UL << RCC_BDCR_LSEDRV_Pos)

   RCC_BDCR_RTCSEL_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3137
   --  unsupported macro: RCC_BDCR_RTCSEL_Msk (0x3UL << RCC_BDCR_RTCSEL_Pos)
   --  unsupported macro: RCC_BDCR_RTCSEL RCC_BDCR_RTCSEL_Msk
   --  unsupported macro: RCC_BDCR_RTCSEL_0 (0x1UL << RCC_BDCR_RTCSEL_Pos)
   --  unsupported macro: RCC_BDCR_RTCSEL_1 (0x2UL << RCC_BDCR_RTCSEL_Pos)

   RCC_BDCR_RTCSEL_NOCLOCK : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:3144
   RCC_BDCR_RTCSEL_LSE : constant := (16#00000100#);  --  ../core/include/stm32f0/stm32f030x6.h:3145
   RCC_BDCR_RTCSEL_LSI : constant := (16#00000200#);  --  ../core/include/stm32f0/stm32f030x6.h:3146
   RCC_BDCR_RTCSEL_HSE : constant := (16#00000300#);  --  ../core/include/stm32f0/stm32f030x6.h:3147

   RCC_BDCR_RTCEN_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:3149
   --  unsupported macro: RCC_BDCR_RTCEN_Msk (0x1UL << RCC_BDCR_RTCEN_Pos)
   --  unsupported macro: RCC_BDCR_RTCEN RCC_BDCR_RTCEN_Msk

   RCC_BDCR_BDRST_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:3152
   --  unsupported macro: RCC_BDCR_BDRST_Msk (0x1UL << RCC_BDCR_BDRST_Pos)
   --  unsupported macro: RCC_BDCR_BDRST RCC_BDCR_BDRST_Msk

   RCC_CSR_LSION_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3157
   --  unsupported macro: RCC_CSR_LSION_Msk (0x1UL << RCC_CSR_LSION_Pos)
   --  unsupported macro: RCC_CSR_LSION RCC_CSR_LSION_Msk

   RCC_CSR_LSIRDY_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:3160
   --  unsupported macro: RCC_CSR_LSIRDY_Msk (0x1UL << RCC_CSR_LSIRDY_Pos)
   --  unsupported macro: RCC_CSR_LSIRDY RCC_CSR_LSIRDY_Msk

   RCC_CSR_V18PWRRSTF_Pos : constant := (23);  --  ../core/include/stm32f0/stm32f030x6.h:3163
   --  unsupported macro: RCC_CSR_V18PWRRSTF_Msk (0x1UL << RCC_CSR_V18PWRRSTF_Pos)
   --  unsupported macro: RCC_CSR_V18PWRRSTF RCC_CSR_V18PWRRSTF_Msk

   RCC_CSR_RMVF_Pos : constant := (24);  --  ../core/include/stm32f0/stm32f030x6.h:3166
   --  unsupported macro: RCC_CSR_RMVF_Msk (0x1UL << RCC_CSR_RMVF_Pos)
   --  unsupported macro: RCC_CSR_RMVF RCC_CSR_RMVF_Msk

   RCC_CSR_OBLRSTF_Pos : constant := (25);  --  ../core/include/stm32f0/stm32f030x6.h:3169
   --  unsupported macro: RCC_CSR_OBLRSTF_Msk (0x1UL << RCC_CSR_OBLRSTF_Pos)
   --  unsupported macro: RCC_CSR_OBLRSTF RCC_CSR_OBLRSTF_Msk

   RCC_CSR_PINRSTF_Pos : constant := (26);  --  ../core/include/stm32f0/stm32f030x6.h:3172
   --  unsupported macro: RCC_CSR_PINRSTF_Msk (0x1UL << RCC_CSR_PINRSTF_Pos)
   --  unsupported macro: RCC_CSR_PINRSTF RCC_CSR_PINRSTF_Msk

   RCC_CSR_PORRSTF_Pos : constant := (27);  --  ../core/include/stm32f0/stm32f030x6.h:3175
   --  unsupported macro: RCC_CSR_PORRSTF_Msk (0x1UL << RCC_CSR_PORRSTF_Pos)
   --  unsupported macro: RCC_CSR_PORRSTF RCC_CSR_PORRSTF_Msk

   RCC_CSR_SFTRSTF_Pos : constant := (28);  --  ../core/include/stm32f0/stm32f030x6.h:3178
   --  unsupported macro: RCC_CSR_SFTRSTF_Msk (0x1UL << RCC_CSR_SFTRSTF_Pos)
   --  unsupported macro: RCC_CSR_SFTRSTF RCC_CSR_SFTRSTF_Msk

   RCC_CSR_IWDGRSTF_Pos : constant := (29);  --  ../core/include/stm32f0/stm32f030x6.h:3181
   --  unsupported macro: RCC_CSR_IWDGRSTF_Msk (0x1UL << RCC_CSR_IWDGRSTF_Pos)
   --  unsupported macro: RCC_CSR_IWDGRSTF RCC_CSR_IWDGRSTF_Msk

   RCC_CSR_WWDGRSTF_Pos : constant := (30);  --  ../core/include/stm32f0/stm32f030x6.h:3184
   --  unsupported macro: RCC_CSR_WWDGRSTF_Msk (0x1UL << RCC_CSR_WWDGRSTF_Pos)
   --  unsupported macro: RCC_CSR_WWDGRSTF RCC_CSR_WWDGRSTF_Msk

   RCC_CSR_LPWRRSTF_Pos : constant := (31);  --  ../core/include/stm32f0/stm32f030x6.h:3187
   --  unsupported macro: RCC_CSR_LPWRRSTF_Msk (0x1UL << RCC_CSR_LPWRRSTF_Pos)
   --  unsupported macro: RCC_CSR_LPWRRSTF RCC_CSR_LPWRRSTF_Msk
   --  unsupported macro: RCC_CSR_OBL RCC_CSR_OBLRSTF

   RCC_AHBRSTR_GPIOARST_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:3195
   --  unsupported macro: RCC_AHBRSTR_GPIOARST_Msk (0x1UL << RCC_AHBRSTR_GPIOARST_Pos)
   --  unsupported macro: RCC_AHBRSTR_GPIOARST RCC_AHBRSTR_GPIOARST_Msk

   RCC_AHBRSTR_GPIOBRST_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:3198
   --  unsupported macro: RCC_AHBRSTR_GPIOBRST_Msk (0x1UL << RCC_AHBRSTR_GPIOBRST_Pos)
   --  unsupported macro: RCC_AHBRSTR_GPIOBRST RCC_AHBRSTR_GPIOBRST_Msk

   RCC_AHBRSTR_GPIOCRST_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:3201
   --  unsupported macro: RCC_AHBRSTR_GPIOCRST_Msk (0x1UL << RCC_AHBRSTR_GPIOCRST_Pos)
   --  unsupported macro: RCC_AHBRSTR_GPIOCRST RCC_AHBRSTR_GPIOCRST_Msk

   RCC_AHBRSTR_GPIODRST_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:3204
   --  unsupported macro: RCC_AHBRSTR_GPIODRST_Msk (0x1UL << RCC_AHBRSTR_GPIODRST_Pos)
   --  unsupported macro: RCC_AHBRSTR_GPIODRST RCC_AHBRSTR_GPIODRST_Msk

   RCC_AHBRSTR_GPIOFRST_Pos : constant := (22);  --  ../core/include/stm32f0/stm32f030x6.h:3207
   --  unsupported macro: RCC_AHBRSTR_GPIOFRST_Msk (0x1UL << RCC_AHBRSTR_GPIOFRST_Pos)
   --  unsupported macro: RCC_AHBRSTR_GPIOFRST RCC_AHBRSTR_GPIOFRST_Msk

   RCC_CFGR2_PREDIV_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3213
   --  unsupported macro: RCC_CFGR2_PREDIV_Msk (0xFUL << RCC_CFGR2_PREDIV_Pos)
   --  unsupported macro: RCC_CFGR2_PREDIV RCC_CFGR2_PREDIV_Msk
   --  unsupported macro: RCC_CFGR2_PREDIV_0 (0x1UL << RCC_CFGR2_PREDIV_Pos)
   --  unsupported macro: RCC_CFGR2_PREDIV_1 (0x2UL << RCC_CFGR2_PREDIV_Pos)
   --  unsupported macro: RCC_CFGR2_PREDIV_2 (0x4UL << RCC_CFGR2_PREDIV_Pos)
   --  unsupported macro: RCC_CFGR2_PREDIV_3 (0x8UL << RCC_CFGR2_PREDIV_Pos)

   RCC_CFGR2_PREDIV_DIV1 : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:3221
   RCC_CFGR2_PREDIV_DIV2 : constant := (16#00000001#);  --  ../core/include/stm32f0/stm32f030x6.h:3222
   RCC_CFGR2_PREDIV_DIV3 : constant := (16#00000002#);  --  ../core/include/stm32f0/stm32f030x6.h:3223
   RCC_CFGR2_PREDIV_DIV4 : constant := (16#00000003#);  --  ../core/include/stm32f0/stm32f030x6.h:3224
   RCC_CFGR2_PREDIV_DIV5 : constant := (16#00000004#);  --  ../core/include/stm32f0/stm32f030x6.h:3225
   RCC_CFGR2_PREDIV_DIV6 : constant := (16#00000005#);  --  ../core/include/stm32f0/stm32f030x6.h:3226
   RCC_CFGR2_PREDIV_DIV7 : constant := (16#00000006#);  --  ../core/include/stm32f0/stm32f030x6.h:3227
   RCC_CFGR2_PREDIV_DIV8 : constant := (16#00000007#);  --  ../core/include/stm32f0/stm32f030x6.h:3228
   RCC_CFGR2_PREDIV_DIV9 : constant := (16#00000008#);  --  ../core/include/stm32f0/stm32f030x6.h:3229
   RCC_CFGR2_PREDIV_DIV10 : constant := (16#00000009#);  --  ../core/include/stm32f0/stm32f030x6.h:3230
   RCC_CFGR2_PREDIV_DIV11 : constant := (16#0000000A#);  --  ../core/include/stm32f0/stm32f030x6.h:3231
   RCC_CFGR2_PREDIV_DIV12 : constant := (16#0000000B#);  --  ../core/include/stm32f0/stm32f030x6.h:3232
   RCC_CFGR2_PREDIV_DIV13 : constant := (16#0000000C#);  --  ../core/include/stm32f0/stm32f030x6.h:3233
   RCC_CFGR2_PREDIV_DIV14 : constant := (16#0000000D#);  --  ../core/include/stm32f0/stm32f030x6.h:3234
   RCC_CFGR2_PREDIV_DIV15 : constant := (16#0000000E#);  --  ../core/include/stm32f0/stm32f030x6.h:3235
   RCC_CFGR2_PREDIV_DIV16 : constant := (16#0000000F#);  --  ../core/include/stm32f0/stm32f030x6.h:3236

   RCC_CFGR3_USART1SW_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3240
   --  unsupported macro: RCC_CFGR3_USART1SW_Msk (0x3UL << RCC_CFGR3_USART1SW_Pos)
   --  unsupported macro: RCC_CFGR3_USART1SW RCC_CFGR3_USART1SW_Msk
   --  unsupported macro: RCC_CFGR3_USART1SW_0 (0x1UL << RCC_CFGR3_USART1SW_Pos)
   --  unsupported macro: RCC_CFGR3_USART1SW_1 (0x2UL << RCC_CFGR3_USART1SW_Pos)

   RCC_CFGR3_USART1SW_PCLK : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:3246
   RCC_CFGR3_USART1SW_SYSCLK : constant := (16#00000001#);  --  ../core/include/stm32f0/stm32f030x6.h:3247
   RCC_CFGR3_USART1SW_LSE : constant := (16#00000002#);  --  ../core/include/stm32f0/stm32f030x6.h:3248
   RCC_CFGR3_USART1SW_HSI : constant := (16#00000003#);  --  ../core/include/stm32f0/stm32f030x6.h:3249

   RCC_CFGR3_I2C1SW_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:3252
   --  unsupported macro: RCC_CFGR3_I2C1SW_Msk (0x1UL << RCC_CFGR3_I2C1SW_Pos)
   --  unsupported macro: RCC_CFGR3_I2C1SW RCC_CFGR3_I2C1SW_Msk

   RCC_CFGR3_I2C1SW_HSI : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:3256
   RCC_CFGR3_I2C1SW_SYSCLK_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:3257
   --  unsupported macro: RCC_CFGR3_I2C1SW_SYSCLK_Msk (0x1UL << RCC_CFGR3_I2C1SW_SYSCLK_Pos)
   --  unsupported macro: RCC_CFGR3_I2C1SW_SYSCLK RCC_CFGR3_I2C1SW_SYSCLK_Msk

   RCC_CR2_HSI14ON_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3262
   --  unsupported macro: RCC_CR2_HSI14ON_Msk (0x1UL << RCC_CR2_HSI14ON_Pos)
   --  unsupported macro: RCC_CR2_HSI14ON RCC_CR2_HSI14ON_Msk

   RCC_CR2_HSI14RDY_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:3265
   --  unsupported macro: RCC_CR2_HSI14RDY_Msk (0x1UL << RCC_CR2_HSI14RDY_Pos)
   --  unsupported macro: RCC_CR2_HSI14RDY RCC_CR2_HSI14RDY_Msk

   RCC_CR2_HSI14DIS_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:3268
   --  unsupported macro: RCC_CR2_HSI14DIS_Msk (0x1UL << RCC_CR2_HSI14DIS_Pos)
   --  unsupported macro: RCC_CR2_HSI14DIS RCC_CR2_HSI14DIS_Msk

   RCC_CR2_HSI14TRIM_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:3271
   --  unsupported macro: RCC_CR2_HSI14TRIM_Msk (0x1FUL << RCC_CR2_HSI14TRIM_Pos)
   --  unsupported macro: RCC_CR2_HSI14TRIM RCC_CR2_HSI14TRIM_Msk

   RCC_CR2_HSI14CAL_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3274
   --  unsupported macro: RCC_CR2_HSI14CAL_Msk (0xFFUL << RCC_CR2_HSI14CAL_Pos)
   --  unsupported macro: RCC_CR2_HSI14CAL RCC_CR2_HSI14CAL_Msk

   RTC_TR_PM_Pos : constant := (22);  --  ../core/include/stm32f0/stm32f030x6.h:3290
   --  unsupported macro: RTC_TR_PM_Msk (0x1UL << RTC_TR_PM_Pos)
   --  unsupported macro: RTC_TR_PM RTC_TR_PM_Msk

   RTC_TR_HT_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:3293
   --  unsupported macro: RTC_TR_HT_Msk (0x3UL << RTC_TR_HT_Pos)
   --  unsupported macro: RTC_TR_HT RTC_TR_HT_Msk
   --  unsupported macro: RTC_TR_HT_0 (0x1UL << RTC_TR_HT_Pos)
   --  unsupported macro: RTC_TR_HT_1 (0x2UL << RTC_TR_HT_Pos)

   RTC_TR_HU_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:3298
   --  unsupported macro: RTC_TR_HU_Msk (0xFUL << RTC_TR_HU_Pos)
   --  unsupported macro: RTC_TR_HU RTC_TR_HU_Msk
   --  unsupported macro: RTC_TR_HU_0 (0x1UL << RTC_TR_HU_Pos)
   --  unsupported macro: RTC_TR_HU_1 (0x2UL << RTC_TR_HU_Pos)
   --  unsupported macro: RTC_TR_HU_2 (0x4UL << RTC_TR_HU_Pos)
   --  unsupported macro: RTC_TR_HU_3 (0x8UL << RTC_TR_HU_Pos)

   RTC_TR_MNT_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:3305
   --  unsupported macro: RTC_TR_MNT_Msk (0x7UL << RTC_TR_MNT_Pos)
   --  unsupported macro: RTC_TR_MNT RTC_TR_MNT_Msk
   --  unsupported macro: RTC_TR_MNT_0 (0x1UL << RTC_TR_MNT_Pos)
   --  unsupported macro: RTC_TR_MNT_1 (0x2UL << RTC_TR_MNT_Pos)
   --  unsupported macro: RTC_TR_MNT_2 (0x4UL << RTC_TR_MNT_Pos)

   RTC_TR_MNU_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3311
   --  unsupported macro: RTC_TR_MNU_Msk (0xFUL << RTC_TR_MNU_Pos)
   --  unsupported macro: RTC_TR_MNU RTC_TR_MNU_Msk
   --  unsupported macro: RTC_TR_MNU_0 (0x1UL << RTC_TR_MNU_Pos)
   --  unsupported macro: RTC_TR_MNU_1 (0x2UL << RTC_TR_MNU_Pos)
   --  unsupported macro: RTC_TR_MNU_2 (0x4UL << RTC_TR_MNU_Pos)
   --  unsupported macro: RTC_TR_MNU_3 (0x8UL << RTC_TR_MNU_Pos)

   RTC_TR_ST_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:3318
   --  unsupported macro: RTC_TR_ST_Msk (0x7UL << RTC_TR_ST_Pos)
   --  unsupported macro: RTC_TR_ST RTC_TR_ST_Msk
   --  unsupported macro: RTC_TR_ST_0 (0x1UL << RTC_TR_ST_Pos)
   --  unsupported macro: RTC_TR_ST_1 (0x2UL << RTC_TR_ST_Pos)
   --  unsupported macro: RTC_TR_ST_2 (0x4UL << RTC_TR_ST_Pos)

   RTC_TR_SU_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3324
   --  unsupported macro: RTC_TR_SU_Msk (0xFUL << RTC_TR_SU_Pos)
   --  unsupported macro: RTC_TR_SU RTC_TR_SU_Msk
   --  unsupported macro: RTC_TR_SU_0 (0x1UL << RTC_TR_SU_Pos)
   --  unsupported macro: RTC_TR_SU_1 (0x2UL << RTC_TR_SU_Pos)
   --  unsupported macro: RTC_TR_SU_2 (0x4UL << RTC_TR_SU_Pos)
   --  unsupported macro: RTC_TR_SU_3 (0x8UL << RTC_TR_SU_Pos)

   RTC_DR_YT_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:3333
   --  unsupported macro: RTC_DR_YT_Msk (0xFUL << RTC_DR_YT_Pos)
   --  unsupported macro: RTC_DR_YT RTC_DR_YT_Msk
   --  unsupported macro: RTC_DR_YT_0 (0x1UL << RTC_DR_YT_Pos)
   --  unsupported macro: RTC_DR_YT_1 (0x2UL << RTC_DR_YT_Pos)
   --  unsupported macro: RTC_DR_YT_2 (0x4UL << RTC_DR_YT_Pos)
   --  unsupported macro: RTC_DR_YT_3 (0x8UL << RTC_DR_YT_Pos)

   RTC_DR_YU_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:3340
   --  unsupported macro: RTC_DR_YU_Msk (0xFUL << RTC_DR_YU_Pos)
   --  unsupported macro: RTC_DR_YU RTC_DR_YU_Msk
   --  unsupported macro: RTC_DR_YU_0 (0x1UL << RTC_DR_YU_Pos)
   --  unsupported macro: RTC_DR_YU_1 (0x2UL << RTC_DR_YU_Pos)
   --  unsupported macro: RTC_DR_YU_2 (0x4UL << RTC_DR_YU_Pos)
   --  unsupported macro: RTC_DR_YU_3 (0x8UL << RTC_DR_YU_Pos)

   RTC_DR_WDU_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:3347
   --  unsupported macro: RTC_DR_WDU_Msk (0x7UL << RTC_DR_WDU_Pos)
   --  unsupported macro: RTC_DR_WDU RTC_DR_WDU_Msk
   --  unsupported macro: RTC_DR_WDU_0 (0x1UL << RTC_DR_WDU_Pos)
   --  unsupported macro: RTC_DR_WDU_1 (0x2UL << RTC_DR_WDU_Pos)
   --  unsupported macro: RTC_DR_WDU_2 (0x4UL << RTC_DR_WDU_Pos)

   RTC_DR_MT_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:3353
   --  unsupported macro: RTC_DR_MT_Msk (0x1UL << RTC_DR_MT_Pos)
   --  unsupported macro: RTC_DR_MT RTC_DR_MT_Msk

   RTC_DR_MU_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3356
   --  unsupported macro: RTC_DR_MU_Msk (0xFUL << RTC_DR_MU_Pos)
   --  unsupported macro: RTC_DR_MU RTC_DR_MU_Msk
   --  unsupported macro: RTC_DR_MU_0 (0x1UL << RTC_DR_MU_Pos)
   --  unsupported macro: RTC_DR_MU_1 (0x2UL << RTC_DR_MU_Pos)
   --  unsupported macro: RTC_DR_MU_2 (0x4UL << RTC_DR_MU_Pos)
   --  unsupported macro: RTC_DR_MU_3 (0x8UL << RTC_DR_MU_Pos)

   RTC_DR_DT_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:3363
   --  unsupported macro: RTC_DR_DT_Msk (0x3UL << RTC_DR_DT_Pos)
   --  unsupported macro: RTC_DR_DT RTC_DR_DT_Msk
   --  unsupported macro: RTC_DR_DT_0 (0x1UL << RTC_DR_DT_Pos)
   --  unsupported macro: RTC_DR_DT_1 (0x2UL << RTC_DR_DT_Pos)

   RTC_DR_DU_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3368
   --  unsupported macro: RTC_DR_DU_Msk (0xFUL << RTC_DR_DU_Pos)
   --  unsupported macro: RTC_DR_DU RTC_DR_DU_Msk
   --  unsupported macro: RTC_DR_DU_0 (0x1UL << RTC_DR_DU_Pos)
   --  unsupported macro: RTC_DR_DU_1 (0x2UL << RTC_DR_DU_Pos)
   --  unsupported macro: RTC_DR_DU_2 (0x4UL << RTC_DR_DU_Pos)
   --  unsupported macro: RTC_DR_DU_3 (0x8UL << RTC_DR_DU_Pos)

   RTC_CR_COE_Pos : constant := (23);  --  ../core/include/stm32f0/stm32f030x6.h:3377
   --  unsupported macro: RTC_CR_COE_Msk (0x1UL << RTC_CR_COE_Pos)
   --  unsupported macro: RTC_CR_COE RTC_CR_COE_Msk

   RTC_CR_OSEL_Pos : constant := (21);  --  ../core/include/stm32f0/stm32f030x6.h:3380
   --  unsupported macro: RTC_CR_OSEL_Msk (0x3UL << RTC_CR_OSEL_Pos)
   --  unsupported macro: RTC_CR_OSEL RTC_CR_OSEL_Msk
   --  unsupported macro: RTC_CR_OSEL_0 (0x1UL << RTC_CR_OSEL_Pos)
   --  unsupported macro: RTC_CR_OSEL_1 (0x2UL << RTC_CR_OSEL_Pos)

   RTC_CR_POL_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:3385
   --  unsupported macro: RTC_CR_POL_Msk (0x1UL << RTC_CR_POL_Pos)
   --  unsupported macro: RTC_CR_POL RTC_CR_POL_Msk

   RTC_CR_COSEL_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:3388
   --  unsupported macro: RTC_CR_COSEL_Msk (0x1UL << RTC_CR_COSEL_Pos)
   --  unsupported macro: RTC_CR_COSEL RTC_CR_COSEL_Msk

   RTC_CR_BKP_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:3391
   --  unsupported macro: RTC_CR_BKP_Msk (0x1UL << RTC_CR_BKP_Pos)
   --  unsupported macro: RTC_CR_BKP RTC_CR_BKP_Msk

   RTC_CR_SUB1H_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:3394
   --  unsupported macro: RTC_CR_SUB1H_Msk (0x1UL << RTC_CR_SUB1H_Pos)
   --  unsupported macro: RTC_CR_SUB1H RTC_CR_SUB1H_Msk

   RTC_CR_ADD1H_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:3397
   --  unsupported macro: RTC_CR_ADD1H_Msk (0x1UL << RTC_CR_ADD1H_Pos)
   --  unsupported macro: RTC_CR_ADD1H RTC_CR_ADD1H_Msk

   RTC_CR_TSIE_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:3400
   --  unsupported macro: RTC_CR_TSIE_Msk (0x1UL << RTC_CR_TSIE_Pos)
   --  unsupported macro: RTC_CR_TSIE RTC_CR_TSIE_Msk

   RTC_CR_ALRAIE_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:3403
   --  unsupported macro: RTC_CR_ALRAIE_Msk (0x1UL << RTC_CR_ALRAIE_Pos)
   --  unsupported macro: RTC_CR_ALRAIE RTC_CR_ALRAIE_Msk

   RTC_CR_TSE_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:3406
   --  unsupported macro: RTC_CR_TSE_Msk (0x1UL << RTC_CR_TSE_Pos)
   --  unsupported macro: RTC_CR_TSE RTC_CR_TSE_Msk

   RTC_CR_ALRAE_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3409
   --  unsupported macro: RTC_CR_ALRAE_Msk (0x1UL << RTC_CR_ALRAE_Pos)
   --  unsupported macro: RTC_CR_ALRAE RTC_CR_ALRAE_Msk

   RTC_CR_FMT_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:3412
   --  unsupported macro: RTC_CR_FMT_Msk (0x1UL << RTC_CR_FMT_Pos)
   --  unsupported macro: RTC_CR_FMT RTC_CR_FMT_Msk

   RTC_CR_BYPSHAD_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:3415
   --  unsupported macro: RTC_CR_BYPSHAD_Msk (0x1UL << RTC_CR_BYPSHAD_Pos)
   --  unsupported macro: RTC_CR_BYPSHAD RTC_CR_BYPSHAD_Msk

   RTC_CR_REFCKON_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:3418
   --  unsupported macro: RTC_CR_REFCKON_Msk (0x1UL << RTC_CR_REFCKON_Pos)
   --  unsupported macro: RTC_CR_REFCKON RTC_CR_REFCKON_Msk

   RTC_CR_TSEDGE_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:3421
   --  unsupported macro: RTC_CR_TSEDGE_Msk (0x1UL << RTC_CR_TSEDGE_Pos)
   --  unsupported macro: RTC_CR_TSEDGE RTC_CR_TSEDGE_Msk
   --  unsupported macro: RTC_CR_BCK_Pos RTC_CR_BKP_Pos
   --  unsupported macro: RTC_CR_BCK_Msk RTC_CR_BKP_Msk
   --  unsupported macro: RTC_CR_BCK RTC_CR_BKP

   RTC_ISR_RECALPF_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:3431
   --  unsupported macro: RTC_ISR_RECALPF_Msk (0x1UL << RTC_ISR_RECALPF_Pos)
   --  unsupported macro: RTC_ISR_RECALPF RTC_ISR_RECALPF_Msk

   RTC_ISR_TAMP2F_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:3434
   --  unsupported macro: RTC_ISR_TAMP2F_Msk (0x1UL << RTC_ISR_TAMP2F_Pos)
   --  unsupported macro: RTC_ISR_TAMP2F RTC_ISR_TAMP2F_Msk

   RTC_ISR_TAMP1F_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:3437
   --  unsupported macro: RTC_ISR_TAMP1F_Msk (0x1UL << RTC_ISR_TAMP1F_Pos)
   --  unsupported macro: RTC_ISR_TAMP1F RTC_ISR_TAMP1F_Msk

   RTC_ISR_TSOVF_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:3440
   --  unsupported macro: RTC_ISR_TSOVF_Msk (0x1UL << RTC_ISR_TSOVF_Pos)
   --  unsupported macro: RTC_ISR_TSOVF RTC_ISR_TSOVF_Msk

   RTC_ISR_TSF_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:3443
   --  unsupported macro: RTC_ISR_TSF_Msk (0x1UL << RTC_ISR_TSF_Pos)
   --  unsupported macro: RTC_ISR_TSF RTC_ISR_TSF_Msk

   RTC_ISR_ALRAF_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3446
   --  unsupported macro: RTC_ISR_ALRAF_Msk (0x1UL << RTC_ISR_ALRAF_Pos)
   --  unsupported macro: RTC_ISR_ALRAF RTC_ISR_ALRAF_Msk

   RTC_ISR_INIT_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:3449
   --  unsupported macro: RTC_ISR_INIT_Msk (0x1UL << RTC_ISR_INIT_Pos)
   --  unsupported macro: RTC_ISR_INIT RTC_ISR_INIT_Msk

   RTC_ISR_INITF_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:3452
   --  unsupported macro: RTC_ISR_INITF_Msk (0x1UL << RTC_ISR_INITF_Pos)
   --  unsupported macro: RTC_ISR_INITF RTC_ISR_INITF_Msk

   RTC_ISR_RSF_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:3455
   --  unsupported macro: RTC_ISR_RSF_Msk (0x1UL << RTC_ISR_RSF_Pos)
   --  unsupported macro: RTC_ISR_RSF RTC_ISR_RSF_Msk

   RTC_ISR_INITS_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:3458
   --  unsupported macro: RTC_ISR_INITS_Msk (0x1UL << RTC_ISR_INITS_Pos)
   --  unsupported macro: RTC_ISR_INITS RTC_ISR_INITS_Msk

   RTC_ISR_SHPF_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:3461
   --  unsupported macro: RTC_ISR_SHPF_Msk (0x1UL << RTC_ISR_SHPF_Pos)
   --  unsupported macro: RTC_ISR_SHPF RTC_ISR_SHPF_Msk

   RTC_ISR_ALRAWF_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3464
   --  unsupported macro: RTC_ISR_ALRAWF_Msk (0x1UL << RTC_ISR_ALRAWF_Pos)
   --  unsupported macro: RTC_ISR_ALRAWF RTC_ISR_ALRAWF_Msk

   RTC_PRER_PREDIV_A_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:3469
   --  unsupported macro: RTC_PRER_PREDIV_A_Msk (0x7FUL << RTC_PRER_PREDIV_A_Pos)
   --  unsupported macro: RTC_PRER_PREDIV_A RTC_PRER_PREDIV_A_Msk

   RTC_PRER_PREDIV_S_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3472
   --  unsupported macro: RTC_PRER_PREDIV_S_Msk (0x7FFFUL << RTC_PRER_PREDIV_S_Pos)
   --  unsupported macro: RTC_PRER_PREDIV_S RTC_PRER_PREDIV_S_Msk

   RTC_ALRMAR_MSK4_Pos : constant := (31);  --  ../core/include/stm32f0/stm32f030x6.h:3477
   --  unsupported macro: RTC_ALRMAR_MSK4_Msk (0x1UL << RTC_ALRMAR_MSK4_Pos)
   --  unsupported macro: RTC_ALRMAR_MSK4 RTC_ALRMAR_MSK4_Msk

   RTC_ALRMAR_WDSEL_Pos : constant := (30);  --  ../core/include/stm32f0/stm32f030x6.h:3480
   --  unsupported macro: RTC_ALRMAR_WDSEL_Msk (0x1UL << RTC_ALRMAR_WDSEL_Pos)
   --  unsupported macro: RTC_ALRMAR_WDSEL RTC_ALRMAR_WDSEL_Msk

   RTC_ALRMAR_DT_Pos : constant := (28);  --  ../core/include/stm32f0/stm32f030x6.h:3483
   --  unsupported macro: RTC_ALRMAR_DT_Msk (0x3UL << RTC_ALRMAR_DT_Pos)
   --  unsupported macro: RTC_ALRMAR_DT RTC_ALRMAR_DT_Msk
   --  unsupported macro: RTC_ALRMAR_DT_0 (0x1UL << RTC_ALRMAR_DT_Pos)
   --  unsupported macro: RTC_ALRMAR_DT_1 (0x2UL << RTC_ALRMAR_DT_Pos)

   RTC_ALRMAR_DU_Pos : constant := (24);  --  ../core/include/stm32f0/stm32f030x6.h:3488
   --  unsupported macro: RTC_ALRMAR_DU_Msk (0xFUL << RTC_ALRMAR_DU_Pos)
   --  unsupported macro: RTC_ALRMAR_DU RTC_ALRMAR_DU_Msk
   --  unsupported macro: RTC_ALRMAR_DU_0 (0x1UL << RTC_ALRMAR_DU_Pos)
   --  unsupported macro: RTC_ALRMAR_DU_1 (0x2UL << RTC_ALRMAR_DU_Pos)
   --  unsupported macro: RTC_ALRMAR_DU_2 (0x4UL << RTC_ALRMAR_DU_Pos)
   --  unsupported macro: RTC_ALRMAR_DU_3 (0x8UL << RTC_ALRMAR_DU_Pos)

   RTC_ALRMAR_MSK3_Pos : constant := (23);  --  ../core/include/stm32f0/stm32f030x6.h:3495
   --  unsupported macro: RTC_ALRMAR_MSK3_Msk (0x1UL << RTC_ALRMAR_MSK3_Pos)
   --  unsupported macro: RTC_ALRMAR_MSK3 RTC_ALRMAR_MSK3_Msk

   RTC_ALRMAR_PM_Pos : constant := (22);  --  ../core/include/stm32f0/stm32f030x6.h:3498
   --  unsupported macro: RTC_ALRMAR_PM_Msk (0x1UL << RTC_ALRMAR_PM_Pos)
   --  unsupported macro: RTC_ALRMAR_PM RTC_ALRMAR_PM_Msk

   RTC_ALRMAR_HT_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:3501
   --  unsupported macro: RTC_ALRMAR_HT_Msk (0x3UL << RTC_ALRMAR_HT_Pos)
   --  unsupported macro: RTC_ALRMAR_HT RTC_ALRMAR_HT_Msk
   --  unsupported macro: RTC_ALRMAR_HT_0 (0x1UL << RTC_ALRMAR_HT_Pos)
   --  unsupported macro: RTC_ALRMAR_HT_1 (0x2UL << RTC_ALRMAR_HT_Pos)

   RTC_ALRMAR_HU_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:3506
   --  unsupported macro: RTC_ALRMAR_HU_Msk (0xFUL << RTC_ALRMAR_HU_Pos)
   --  unsupported macro: RTC_ALRMAR_HU RTC_ALRMAR_HU_Msk
   --  unsupported macro: RTC_ALRMAR_HU_0 (0x1UL << RTC_ALRMAR_HU_Pos)
   --  unsupported macro: RTC_ALRMAR_HU_1 (0x2UL << RTC_ALRMAR_HU_Pos)
   --  unsupported macro: RTC_ALRMAR_HU_2 (0x4UL << RTC_ALRMAR_HU_Pos)
   --  unsupported macro: RTC_ALRMAR_HU_3 (0x8UL << RTC_ALRMAR_HU_Pos)

   RTC_ALRMAR_MSK2_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:3513
   --  unsupported macro: RTC_ALRMAR_MSK2_Msk (0x1UL << RTC_ALRMAR_MSK2_Pos)
   --  unsupported macro: RTC_ALRMAR_MSK2 RTC_ALRMAR_MSK2_Msk

   RTC_ALRMAR_MNT_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:3516
   --  unsupported macro: RTC_ALRMAR_MNT_Msk (0x7UL << RTC_ALRMAR_MNT_Pos)
   --  unsupported macro: RTC_ALRMAR_MNT RTC_ALRMAR_MNT_Msk
   --  unsupported macro: RTC_ALRMAR_MNT_0 (0x1UL << RTC_ALRMAR_MNT_Pos)
   --  unsupported macro: RTC_ALRMAR_MNT_1 (0x2UL << RTC_ALRMAR_MNT_Pos)
   --  unsupported macro: RTC_ALRMAR_MNT_2 (0x4UL << RTC_ALRMAR_MNT_Pos)

   RTC_ALRMAR_MNU_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3522
   --  unsupported macro: RTC_ALRMAR_MNU_Msk (0xFUL << RTC_ALRMAR_MNU_Pos)
   --  unsupported macro: RTC_ALRMAR_MNU RTC_ALRMAR_MNU_Msk
   --  unsupported macro: RTC_ALRMAR_MNU_0 (0x1UL << RTC_ALRMAR_MNU_Pos)
   --  unsupported macro: RTC_ALRMAR_MNU_1 (0x2UL << RTC_ALRMAR_MNU_Pos)
   --  unsupported macro: RTC_ALRMAR_MNU_2 (0x4UL << RTC_ALRMAR_MNU_Pos)
   --  unsupported macro: RTC_ALRMAR_MNU_3 (0x8UL << RTC_ALRMAR_MNU_Pos)

   RTC_ALRMAR_MSK1_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:3529
   --  unsupported macro: RTC_ALRMAR_MSK1_Msk (0x1UL << RTC_ALRMAR_MSK1_Pos)
   --  unsupported macro: RTC_ALRMAR_MSK1 RTC_ALRMAR_MSK1_Msk

   RTC_ALRMAR_ST_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:3532
   --  unsupported macro: RTC_ALRMAR_ST_Msk (0x7UL << RTC_ALRMAR_ST_Pos)
   --  unsupported macro: RTC_ALRMAR_ST RTC_ALRMAR_ST_Msk
   --  unsupported macro: RTC_ALRMAR_ST_0 (0x1UL << RTC_ALRMAR_ST_Pos)
   --  unsupported macro: RTC_ALRMAR_ST_1 (0x2UL << RTC_ALRMAR_ST_Pos)
   --  unsupported macro: RTC_ALRMAR_ST_2 (0x4UL << RTC_ALRMAR_ST_Pos)

   RTC_ALRMAR_SU_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3538
   --  unsupported macro: RTC_ALRMAR_SU_Msk (0xFUL << RTC_ALRMAR_SU_Pos)
   --  unsupported macro: RTC_ALRMAR_SU RTC_ALRMAR_SU_Msk
   --  unsupported macro: RTC_ALRMAR_SU_0 (0x1UL << RTC_ALRMAR_SU_Pos)
   --  unsupported macro: RTC_ALRMAR_SU_1 (0x2UL << RTC_ALRMAR_SU_Pos)
   --  unsupported macro: RTC_ALRMAR_SU_2 (0x4UL << RTC_ALRMAR_SU_Pos)
   --  unsupported macro: RTC_ALRMAR_SU_3 (0x8UL << RTC_ALRMAR_SU_Pos)

   RTC_WPR_KEY_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3547
   --  unsupported macro: RTC_WPR_KEY_Msk (0xFFUL << RTC_WPR_KEY_Pos)
   --  unsupported macro: RTC_WPR_KEY RTC_WPR_KEY_Msk

   RTC_SSR_SS_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3552
   --  unsupported macro: RTC_SSR_SS_Msk (0xFFFFUL << RTC_SSR_SS_Pos)
   --  unsupported macro: RTC_SSR_SS RTC_SSR_SS_Msk

   RTC_SHIFTR_SUBFS_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3557
   --  unsupported macro: RTC_SHIFTR_SUBFS_Msk (0x7FFFUL << RTC_SHIFTR_SUBFS_Pos)
   --  unsupported macro: RTC_SHIFTR_SUBFS RTC_SHIFTR_SUBFS_Msk

   RTC_SHIFTR_ADD1S_Pos : constant := (31);  --  ../core/include/stm32f0/stm32f030x6.h:3560
   --  unsupported macro: RTC_SHIFTR_ADD1S_Msk (0x1UL << RTC_SHIFTR_ADD1S_Pos)
   --  unsupported macro: RTC_SHIFTR_ADD1S RTC_SHIFTR_ADD1S_Msk

   RTC_TSTR_PM_Pos : constant := (22);  --  ../core/include/stm32f0/stm32f030x6.h:3565
   --  unsupported macro: RTC_TSTR_PM_Msk (0x1UL << RTC_TSTR_PM_Pos)
   --  unsupported macro: RTC_TSTR_PM RTC_TSTR_PM_Msk

   RTC_TSTR_HT_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:3568
   --  unsupported macro: RTC_TSTR_HT_Msk (0x3UL << RTC_TSTR_HT_Pos)
   --  unsupported macro: RTC_TSTR_HT RTC_TSTR_HT_Msk
   --  unsupported macro: RTC_TSTR_HT_0 (0x1UL << RTC_TSTR_HT_Pos)
   --  unsupported macro: RTC_TSTR_HT_1 (0x2UL << RTC_TSTR_HT_Pos)

   RTC_TSTR_HU_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:3573
   --  unsupported macro: RTC_TSTR_HU_Msk (0xFUL << RTC_TSTR_HU_Pos)
   --  unsupported macro: RTC_TSTR_HU RTC_TSTR_HU_Msk
   --  unsupported macro: RTC_TSTR_HU_0 (0x1UL << RTC_TSTR_HU_Pos)
   --  unsupported macro: RTC_TSTR_HU_1 (0x2UL << RTC_TSTR_HU_Pos)
   --  unsupported macro: RTC_TSTR_HU_2 (0x4UL << RTC_TSTR_HU_Pos)
   --  unsupported macro: RTC_TSTR_HU_3 (0x8UL << RTC_TSTR_HU_Pos)

   RTC_TSTR_MNT_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:3580
   --  unsupported macro: RTC_TSTR_MNT_Msk (0x7UL << RTC_TSTR_MNT_Pos)
   --  unsupported macro: RTC_TSTR_MNT RTC_TSTR_MNT_Msk
   --  unsupported macro: RTC_TSTR_MNT_0 (0x1UL << RTC_TSTR_MNT_Pos)
   --  unsupported macro: RTC_TSTR_MNT_1 (0x2UL << RTC_TSTR_MNT_Pos)
   --  unsupported macro: RTC_TSTR_MNT_2 (0x4UL << RTC_TSTR_MNT_Pos)

   RTC_TSTR_MNU_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3586
   --  unsupported macro: RTC_TSTR_MNU_Msk (0xFUL << RTC_TSTR_MNU_Pos)
   --  unsupported macro: RTC_TSTR_MNU RTC_TSTR_MNU_Msk
   --  unsupported macro: RTC_TSTR_MNU_0 (0x1UL << RTC_TSTR_MNU_Pos)
   --  unsupported macro: RTC_TSTR_MNU_1 (0x2UL << RTC_TSTR_MNU_Pos)
   --  unsupported macro: RTC_TSTR_MNU_2 (0x4UL << RTC_TSTR_MNU_Pos)
   --  unsupported macro: RTC_TSTR_MNU_3 (0x8UL << RTC_TSTR_MNU_Pos)

   RTC_TSTR_ST_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:3593
   --  unsupported macro: RTC_TSTR_ST_Msk (0x7UL << RTC_TSTR_ST_Pos)
   --  unsupported macro: RTC_TSTR_ST RTC_TSTR_ST_Msk
   --  unsupported macro: RTC_TSTR_ST_0 (0x1UL << RTC_TSTR_ST_Pos)
   --  unsupported macro: RTC_TSTR_ST_1 (0x2UL << RTC_TSTR_ST_Pos)
   --  unsupported macro: RTC_TSTR_ST_2 (0x4UL << RTC_TSTR_ST_Pos)

   RTC_TSTR_SU_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3599
   --  unsupported macro: RTC_TSTR_SU_Msk (0xFUL << RTC_TSTR_SU_Pos)
   --  unsupported macro: RTC_TSTR_SU RTC_TSTR_SU_Msk
   --  unsupported macro: RTC_TSTR_SU_0 (0x1UL << RTC_TSTR_SU_Pos)
   --  unsupported macro: RTC_TSTR_SU_1 (0x2UL << RTC_TSTR_SU_Pos)
   --  unsupported macro: RTC_TSTR_SU_2 (0x4UL << RTC_TSTR_SU_Pos)
   --  unsupported macro: RTC_TSTR_SU_3 (0x8UL << RTC_TSTR_SU_Pos)

   RTC_TSDR_WDU_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:3608
   --  unsupported macro: RTC_TSDR_WDU_Msk (0x7UL << RTC_TSDR_WDU_Pos)
   --  unsupported macro: RTC_TSDR_WDU RTC_TSDR_WDU_Msk
   --  unsupported macro: RTC_TSDR_WDU_0 (0x1UL << RTC_TSDR_WDU_Pos)
   --  unsupported macro: RTC_TSDR_WDU_1 (0x2UL << RTC_TSDR_WDU_Pos)
   --  unsupported macro: RTC_TSDR_WDU_2 (0x4UL << RTC_TSDR_WDU_Pos)

   RTC_TSDR_MT_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:3614
   --  unsupported macro: RTC_TSDR_MT_Msk (0x1UL << RTC_TSDR_MT_Pos)
   --  unsupported macro: RTC_TSDR_MT RTC_TSDR_MT_Msk

   RTC_TSDR_MU_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3617
   --  unsupported macro: RTC_TSDR_MU_Msk (0xFUL << RTC_TSDR_MU_Pos)
   --  unsupported macro: RTC_TSDR_MU RTC_TSDR_MU_Msk
   --  unsupported macro: RTC_TSDR_MU_0 (0x1UL << RTC_TSDR_MU_Pos)
   --  unsupported macro: RTC_TSDR_MU_1 (0x2UL << RTC_TSDR_MU_Pos)
   --  unsupported macro: RTC_TSDR_MU_2 (0x4UL << RTC_TSDR_MU_Pos)
   --  unsupported macro: RTC_TSDR_MU_3 (0x8UL << RTC_TSDR_MU_Pos)

   RTC_TSDR_DT_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:3624
   --  unsupported macro: RTC_TSDR_DT_Msk (0x3UL << RTC_TSDR_DT_Pos)
   --  unsupported macro: RTC_TSDR_DT RTC_TSDR_DT_Msk
   --  unsupported macro: RTC_TSDR_DT_0 (0x1UL << RTC_TSDR_DT_Pos)
   --  unsupported macro: RTC_TSDR_DT_1 (0x2UL << RTC_TSDR_DT_Pos)

   RTC_TSDR_DU_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3629
   --  unsupported macro: RTC_TSDR_DU_Msk (0xFUL << RTC_TSDR_DU_Pos)
   --  unsupported macro: RTC_TSDR_DU RTC_TSDR_DU_Msk
   --  unsupported macro: RTC_TSDR_DU_0 (0x1UL << RTC_TSDR_DU_Pos)
   --  unsupported macro: RTC_TSDR_DU_1 (0x2UL << RTC_TSDR_DU_Pos)
   --  unsupported macro: RTC_TSDR_DU_2 (0x4UL << RTC_TSDR_DU_Pos)
   --  unsupported macro: RTC_TSDR_DU_3 (0x8UL << RTC_TSDR_DU_Pos)

   RTC_TSSSR_SS_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3638
   --  unsupported macro: RTC_TSSSR_SS_Msk (0xFFFFUL << RTC_TSSSR_SS_Pos)
   --  unsupported macro: RTC_TSSSR_SS RTC_TSSSR_SS_Msk

   RTC_CALR_CALP_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:3643
   --  unsupported macro: RTC_CALR_CALP_Msk (0x1UL << RTC_CALR_CALP_Pos)
   --  unsupported macro: RTC_CALR_CALP RTC_CALR_CALP_Msk

   RTC_CALR_CALW8_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:3646
   --  unsupported macro: RTC_CALR_CALW8_Msk (0x1UL << RTC_CALR_CALW8_Pos)
   --  unsupported macro: RTC_CALR_CALW8 RTC_CALR_CALW8_Msk

   RTC_CALR_CALW16_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:3649
   --  unsupported macro: RTC_CALR_CALW16_Msk (0x1UL << RTC_CALR_CALW16_Pos)
   --  unsupported macro: RTC_CALR_CALW16 RTC_CALR_CALW16_Msk

   RTC_CALR_CALM_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3652
   --  unsupported macro: RTC_CALR_CALM_Msk (0x1FFUL << RTC_CALR_CALM_Pos)
   --  unsupported macro: RTC_CALR_CALM RTC_CALR_CALM_Msk
   --  unsupported macro: RTC_CALR_CALM_0 (0x001UL << RTC_CALR_CALM_Pos)
   --  unsupported macro: RTC_CALR_CALM_1 (0x002UL << RTC_CALR_CALM_Pos)
   --  unsupported macro: RTC_CALR_CALM_2 (0x004UL << RTC_CALR_CALM_Pos)
   --  unsupported macro: RTC_CALR_CALM_3 (0x008UL << RTC_CALR_CALM_Pos)
   --  unsupported macro: RTC_CALR_CALM_4 (0x010UL << RTC_CALR_CALM_Pos)
   --  unsupported macro: RTC_CALR_CALM_5 (0x020UL << RTC_CALR_CALM_Pos)
   --  unsupported macro: RTC_CALR_CALM_6 (0x040UL << RTC_CALR_CALM_Pos)
   --  unsupported macro: RTC_CALR_CALM_7 (0x080UL << RTC_CALR_CALM_Pos)
   --  unsupported macro: RTC_CALR_CALM_8 (0x100UL << RTC_CALR_CALM_Pos)

   RTC_TAFCR_PC15MODE_Pos : constant := (23);  --  ../core/include/stm32f0/stm32f030x6.h:3666
   --  unsupported macro: RTC_TAFCR_PC15MODE_Msk (0x1UL << RTC_TAFCR_PC15MODE_Pos)
   --  unsupported macro: RTC_TAFCR_PC15MODE RTC_TAFCR_PC15MODE_Msk

   RTC_TAFCR_PC15VALUE_Pos : constant := (22);  --  ../core/include/stm32f0/stm32f030x6.h:3669
   --  unsupported macro: RTC_TAFCR_PC15VALUE_Msk (0x1UL << RTC_TAFCR_PC15VALUE_Pos)
   --  unsupported macro: RTC_TAFCR_PC15VALUE RTC_TAFCR_PC15VALUE_Msk

   RTC_TAFCR_PC14MODE_Pos : constant := (21);  --  ../core/include/stm32f0/stm32f030x6.h:3672
   --  unsupported macro: RTC_TAFCR_PC14MODE_Msk (0x1UL << RTC_TAFCR_PC14MODE_Pos)
   --  unsupported macro: RTC_TAFCR_PC14MODE RTC_TAFCR_PC14MODE_Msk

   RTC_TAFCR_PC14VALUE_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:3675
   --  unsupported macro: RTC_TAFCR_PC14VALUE_Msk (0x1UL << RTC_TAFCR_PC14VALUE_Pos)
   --  unsupported macro: RTC_TAFCR_PC14VALUE RTC_TAFCR_PC14VALUE_Msk

   RTC_TAFCR_PC13MODE_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:3678
   --  unsupported macro: RTC_TAFCR_PC13MODE_Msk (0x1UL << RTC_TAFCR_PC13MODE_Pos)
   --  unsupported macro: RTC_TAFCR_PC13MODE RTC_TAFCR_PC13MODE_Msk

   RTC_TAFCR_PC13VALUE_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:3681
   --  unsupported macro: RTC_TAFCR_PC13VALUE_Msk (0x1UL << RTC_TAFCR_PC13VALUE_Pos)
   --  unsupported macro: RTC_TAFCR_PC13VALUE RTC_TAFCR_PC13VALUE_Msk

   RTC_TAFCR_TAMPPUDIS_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:3684
   --  unsupported macro: RTC_TAFCR_TAMPPUDIS_Msk (0x1UL << RTC_TAFCR_TAMPPUDIS_Pos)
   --  unsupported macro: RTC_TAFCR_TAMPPUDIS RTC_TAFCR_TAMPPUDIS_Msk

   RTC_TAFCR_TAMPPRCH_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:3687
   --  unsupported macro: RTC_TAFCR_TAMPPRCH_Msk (0x3UL << RTC_TAFCR_TAMPPRCH_Pos)
   --  unsupported macro: RTC_TAFCR_TAMPPRCH RTC_TAFCR_TAMPPRCH_Msk
   --  unsupported macro: RTC_TAFCR_TAMPPRCH_0 (0x1UL << RTC_TAFCR_TAMPPRCH_Pos)
   --  unsupported macro: RTC_TAFCR_TAMPPRCH_1 (0x2UL << RTC_TAFCR_TAMPPRCH_Pos)

   RTC_TAFCR_TAMPFLT_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:3692
   --  unsupported macro: RTC_TAFCR_TAMPFLT_Msk (0x3UL << RTC_TAFCR_TAMPFLT_Pos)
   --  unsupported macro: RTC_TAFCR_TAMPFLT RTC_TAFCR_TAMPFLT_Msk
   --  unsupported macro: RTC_TAFCR_TAMPFLT_0 (0x1UL << RTC_TAFCR_TAMPFLT_Pos)
   --  unsupported macro: RTC_TAFCR_TAMPFLT_1 (0x2UL << RTC_TAFCR_TAMPFLT_Pos)

   RTC_TAFCR_TAMPFREQ_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3697
   --  unsupported macro: RTC_TAFCR_TAMPFREQ_Msk (0x7UL << RTC_TAFCR_TAMPFREQ_Pos)
   --  unsupported macro: RTC_TAFCR_TAMPFREQ RTC_TAFCR_TAMPFREQ_Msk
   --  unsupported macro: RTC_TAFCR_TAMPFREQ_0 (0x1UL << RTC_TAFCR_TAMPFREQ_Pos)
   --  unsupported macro: RTC_TAFCR_TAMPFREQ_1 (0x2UL << RTC_TAFCR_TAMPFREQ_Pos)
   --  unsupported macro: RTC_TAFCR_TAMPFREQ_2 (0x4UL << RTC_TAFCR_TAMPFREQ_Pos)

   RTC_TAFCR_TAMPTS_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:3703
   --  unsupported macro: RTC_TAFCR_TAMPTS_Msk (0x1UL << RTC_TAFCR_TAMPTS_Pos)
   --  unsupported macro: RTC_TAFCR_TAMPTS RTC_TAFCR_TAMPTS_Msk

   RTC_TAFCR_TAMP2TRG_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:3706
   --  unsupported macro: RTC_TAFCR_TAMP2TRG_Msk (0x1UL << RTC_TAFCR_TAMP2TRG_Pos)
   --  unsupported macro: RTC_TAFCR_TAMP2TRG RTC_TAFCR_TAMP2TRG_Msk

   RTC_TAFCR_TAMP2E_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:3709
   --  unsupported macro: RTC_TAFCR_TAMP2E_Msk (0x1UL << RTC_TAFCR_TAMP2E_Pos)
   --  unsupported macro: RTC_TAFCR_TAMP2E RTC_TAFCR_TAMP2E_Msk

   RTC_TAFCR_TAMPIE_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:3712
   --  unsupported macro: RTC_TAFCR_TAMPIE_Msk (0x1UL << RTC_TAFCR_TAMPIE_Pos)
   --  unsupported macro: RTC_TAFCR_TAMPIE RTC_TAFCR_TAMPIE_Msk

   RTC_TAFCR_TAMP1TRG_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:3715
   --  unsupported macro: RTC_TAFCR_TAMP1TRG_Msk (0x1UL << RTC_TAFCR_TAMP1TRG_Pos)
   --  unsupported macro: RTC_TAFCR_TAMP1TRG RTC_TAFCR_TAMP1TRG_Msk

   RTC_TAFCR_TAMP1E_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3718
   --  unsupported macro: RTC_TAFCR_TAMP1E_Msk (0x1UL << RTC_TAFCR_TAMP1E_Pos)
   --  unsupported macro: RTC_TAFCR_TAMP1E RTC_TAFCR_TAMP1E_Msk
   --  unsupported macro: RTC_TAFCR_ALARMOUTTYPE RTC_TAFCR_PC13VALUE

   RTC_ALRMASSR_MASKSS_Pos : constant := (24);  --  ../core/include/stm32f0/stm32f030x6.h:3726
   --  unsupported macro: RTC_ALRMASSR_MASKSS_Msk (0xFUL << RTC_ALRMASSR_MASKSS_Pos)
   --  unsupported macro: RTC_ALRMASSR_MASKSS RTC_ALRMASSR_MASKSS_Msk
   --  unsupported macro: RTC_ALRMASSR_MASKSS_0 (0x1UL << RTC_ALRMASSR_MASKSS_Pos)
   --  unsupported macro: RTC_ALRMASSR_MASKSS_1 (0x2UL << RTC_ALRMASSR_MASKSS_Pos)
   --  unsupported macro: RTC_ALRMASSR_MASKSS_2 (0x4UL << RTC_ALRMASSR_MASKSS_Pos)
   --  unsupported macro: RTC_ALRMASSR_MASKSS_3 (0x8UL << RTC_ALRMASSR_MASKSS_Pos)

   RTC_ALRMASSR_SS_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3733
   --  unsupported macro: RTC_ALRMASSR_SS_Msk (0x7FFFUL << RTC_ALRMASSR_SS_Pos)
   --  unsupported macro: RTC_ALRMASSR_SS RTC_ALRMASSR_SS_Msk

   SPI_CR1_CPHA_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3749
   --  unsupported macro: SPI_CR1_CPHA_Msk (0x1UL << SPI_CR1_CPHA_Pos)
   --  unsupported macro: SPI_CR1_CPHA SPI_CR1_CPHA_Msk

   SPI_CR1_CPOL_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:3752
   --  unsupported macro: SPI_CR1_CPOL_Msk (0x1UL << SPI_CR1_CPOL_Pos)
   --  unsupported macro: SPI_CR1_CPOL SPI_CR1_CPOL_Msk

   SPI_CR1_MSTR_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:3755
   --  unsupported macro: SPI_CR1_MSTR_Msk (0x1UL << SPI_CR1_MSTR_Pos)
   --  unsupported macro: SPI_CR1_MSTR SPI_CR1_MSTR_Msk

   SPI_CR1_BR_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:3758
   --  unsupported macro: SPI_CR1_BR_Msk (0x7UL << SPI_CR1_BR_Pos)
   --  unsupported macro: SPI_CR1_BR SPI_CR1_BR_Msk
   --  unsupported macro: SPI_CR1_BR_0 (0x1UL << SPI_CR1_BR_Pos)
   --  unsupported macro: SPI_CR1_BR_1 (0x2UL << SPI_CR1_BR_Pos)
   --  unsupported macro: SPI_CR1_BR_2 (0x4UL << SPI_CR1_BR_Pos)

   SPI_CR1_SPE_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:3764
   --  unsupported macro: SPI_CR1_SPE_Msk (0x1UL << SPI_CR1_SPE_Pos)
   --  unsupported macro: SPI_CR1_SPE SPI_CR1_SPE_Msk

   SPI_CR1_LSBFIRST_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:3767
   --  unsupported macro: SPI_CR1_LSBFIRST_Msk (0x1UL << SPI_CR1_LSBFIRST_Pos)
   --  unsupported macro: SPI_CR1_LSBFIRST SPI_CR1_LSBFIRST_Msk

   SPI_CR1_SSI_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3770
   --  unsupported macro: SPI_CR1_SSI_Msk (0x1UL << SPI_CR1_SSI_Pos)
   --  unsupported macro: SPI_CR1_SSI SPI_CR1_SSI_Msk

   SPI_CR1_SSM_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:3773
   --  unsupported macro: SPI_CR1_SSM_Msk (0x1UL << SPI_CR1_SSM_Pos)
   --  unsupported macro: SPI_CR1_SSM SPI_CR1_SSM_Msk

   SPI_CR1_RXONLY_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:3776
   --  unsupported macro: SPI_CR1_RXONLY_Msk (0x1UL << SPI_CR1_RXONLY_Pos)
   --  unsupported macro: SPI_CR1_RXONLY SPI_CR1_RXONLY_Msk

   SPI_CR1_CRCL_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:3779
   --  unsupported macro: SPI_CR1_CRCL_Msk (0x1UL << SPI_CR1_CRCL_Pos)
   --  unsupported macro: SPI_CR1_CRCL SPI_CR1_CRCL_Msk

   SPI_CR1_CRCNEXT_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:3782
   --  unsupported macro: SPI_CR1_CRCNEXT_Msk (0x1UL << SPI_CR1_CRCNEXT_Pos)
   --  unsupported macro: SPI_CR1_CRCNEXT SPI_CR1_CRCNEXT_Msk

   SPI_CR1_CRCEN_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:3785
   --  unsupported macro: SPI_CR1_CRCEN_Msk (0x1UL << SPI_CR1_CRCEN_Pos)
   --  unsupported macro: SPI_CR1_CRCEN SPI_CR1_CRCEN_Msk

   SPI_CR1_BIDIOE_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:3788
   --  unsupported macro: SPI_CR1_BIDIOE_Msk (0x1UL << SPI_CR1_BIDIOE_Pos)
   --  unsupported macro: SPI_CR1_BIDIOE SPI_CR1_BIDIOE_Msk

   SPI_CR1_BIDIMODE_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:3791
   --  unsupported macro: SPI_CR1_BIDIMODE_Msk (0x1UL << SPI_CR1_BIDIMODE_Pos)
   --  unsupported macro: SPI_CR1_BIDIMODE SPI_CR1_BIDIMODE_Msk

   SPI_CR2_RXDMAEN_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3796
   --  unsupported macro: SPI_CR2_RXDMAEN_Msk (0x1UL << SPI_CR2_RXDMAEN_Pos)
   --  unsupported macro: SPI_CR2_RXDMAEN SPI_CR2_RXDMAEN_Msk

   SPI_CR2_TXDMAEN_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:3799
   --  unsupported macro: SPI_CR2_TXDMAEN_Msk (0x1UL << SPI_CR2_TXDMAEN_Pos)
   --  unsupported macro: SPI_CR2_TXDMAEN SPI_CR2_TXDMAEN_Msk

   SPI_CR2_SSOE_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:3802
   --  unsupported macro: SPI_CR2_SSOE_Msk (0x1UL << SPI_CR2_SSOE_Pos)
   --  unsupported macro: SPI_CR2_SSOE SPI_CR2_SSOE_Msk

   SPI_CR2_NSSP_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:3805
   --  unsupported macro: SPI_CR2_NSSP_Msk (0x1UL << SPI_CR2_NSSP_Pos)
   --  unsupported macro: SPI_CR2_NSSP SPI_CR2_NSSP_Msk

   SPI_CR2_FRF_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:3808
   --  unsupported macro: SPI_CR2_FRF_Msk (0x1UL << SPI_CR2_FRF_Pos)
   --  unsupported macro: SPI_CR2_FRF SPI_CR2_FRF_Msk

   SPI_CR2_ERRIE_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:3811
   --  unsupported macro: SPI_CR2_ERRIE_Msk (0x1UL << SPI_CR2_ERRIE_Pos)
   --  unsupported macro: SPI_CR2_ERRIE SPI_CR2_ERRIE_Msk

   SPI_CR2_RXNEIE_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:3814
   --  unsupported macro: SPI_CR2_RXNEIE_Msk (0x1UL << SPI_CR2_RXNEIE_Pos)
   --  unsupported macro: SPI_CR2_RXNEIE SPI_CR2_RXNEIE_Msk

   SPI_CR2_TXEIE_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:3817
   --  unsupported macro: SPI_CR2_TXEIE_Msk (0x1UL << SPI_CR2_TXEIE_Pos)
   --  unsupported macro: SPI_CR2_TXEIE SPI_CR2_TXEIE_Msk

   SPI_CR2_DS_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3820
   --  unsupported macro: SPI_CR2_DS_Msk (0xFUL << SPI_CR2_DS_Pos)
   --  unsupported macro: SPI_CR2_DS SPI_CR2_DS_Msk
   --  unsupported macro: SPI_CR2_DS_0 (0x1UL << SPI_CR2_DS_Pos)
   --  unsupported macro: SPI_CR2_DS_1 (0x2UL << SPI_CR2_DS_Pos)
   --  unsupported macro: SPI_CR2_DS_2 (0x4UL << SPI_CR2_DS_Pos)
   --  unsupported macro: SPI_CR2_DS_3 (0x8UL << SPI_CR2_DS_Pos)

   SPI_CR2_FRXTH_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:3827
   --  unsupported macro: SPI_CR2_FRXTH_Msk (0x1UL << SPI_CR2_FRXTH_Pos)
   --  unsupported macro: SPI_CR2_FRXTH SPI_CR2_FRXTH_Msk

   SPI_CR2_LDMARX_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:3830
   --  unsupported macro: SPI_CR2_LDMARX_Msk (0x1UL << SPI_CR2_LDMARX_Pos)
   --  unsupported macro: SPI_CR2_LDMARX SPI_CR2_LDMARX_Msk

   SPI_CR2_LDMATX_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:3833
   --  unsupported macro: SPI_CR2_LDMATX_Msk (0x1UL << SPI_CR2_LDMATX_Pos)
   --  unsupported macro: SPI_CR2_LDMATX SPI_CR2_LDMATX_Msk

   SPI_SR_RXNE_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3838
   --  unsupported macro: SPI_SR_RXNE_Msk (0x1UL << SPI_SR_RXNE_Pos)
   --  unsupported macro: SPI_SR_RXNE SPI_SR_RXNE_Msk

   SPI_SR_TXE_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:3841
   --  unsupported macro: SPI_SR_TXE_Msk (0x1UL << SPI_SR_TXE_Pos)
   --  unsupported macro: SPI_SR_TXE SPI_SR_TXE_Msk

   SPI_SR_CRCERR_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:3844
   --  unsupported macro: SPI_SR_CRCERR_Msk (0x1UL << SPI_SR_CRCERR_Pos)
   --  unsupported macro: SPI_SR_CRCERR SPI_SR_CRCERR_Msk

   SPI_SR_MODF_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:3847
   --  unsupported macro: SPI_SR_MODF_Msk (0x1UL << SPI_SR_MODF_Pos)
   --  unsupported macro: SPI_SR_MODF SPI_SR_MODF_Msk

   SPI_SR_OVR_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:3850
   --  unsupported macro: SPI_SR_OVR_Msk (0x1UL << SPI_SR_OVR_Pos)
   --  unsupported macro: SPI_SR_OVR SPI_SR_OVR_Msk

   SPI_SR_BSY_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:3853
   --  unsupported macro: SPI_SR_BSY_Msk (0x1UL << SPI_SR_BSY_Pos)
   --  unsupported macro: SPI_SR_BSY SPI_SR_BSY_Msk

   SPI_SR_FRE_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3856
   --  unsupported macro: SPI_SR_FRE_Msk (0x1UL << SPI_SR_FRE_Pos)
   --  unsupported macro: SPI_SR_FRE SPI_SR_FRE_Msk

   SPI_SR_FRLVL_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:3859
   --  unsupported macro: SPI_SR_FRLVL_Msk (0x3UL << SPI_SR_FRLVL_Pos)
   --  unsupported macro: SPI_SR_FRLVL SPI_SR_FRLVL_Msk
   --  unsupported macro: SPI_SR_FRLVL_0 (0x1UL << SPI_SR_FRLVL_Pos)
   --  unsupported macro: SPI_SR_FRLVL_1 (0x2UL << SPI_SR_FRLVL_Pos)

   SPI_SR_FTLVL_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:3864
   --  unsupported macro: SPI_SR_FTLVL_Msk (0x3UL << SPI_SR_FTLVL_Pos)
   --  unsupported macro: SPI_SR_FTLVL SPI_SR_FTLVL_Msk
   --  unsupported macro: SPI_SR_FTLVL_0 (0x1UL << SPI_SR_FTLVL_Pos)
   --  unsupported macro: SPI_SR_FTLVL_1 (0x2UL << SPI_SR_FTLVL_Pos)

   SPI_DR_DR_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3871
   --  unsupported macro: SPI_DR_DR_Msk (0xFFFFFFFFUL << SPI_DR_DR_Pos)
   --  unsupported macro: SPI_DR_DR SPI_DR_DR_Msk

   SPI_CRCPR_CRCPOLY_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3876
   --  unsupported macro: SPI_CRCPR_CRCPOLY_Msk (0xFFFFFFFFUL << SPI_CRCPR_CRCPOLY_Pos)
   --  unsupported macro: SPI_CRCPR_CRCPOLY SPI_CRCPR_CRCPOLY_Msk

   SPI_RXCRCR_RXCRC_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3881
   --  unsupported macro: SPI_RXCRCR_RXCRC_Msk (0xFFFFFFFFUL << SPI_RXCRCR_RXCRC_Pos)
   --  unsupported macro: SPI_RXCRCR_RXCRC SPI_RXCRCR_RXCRC_Msk

   SPI_TXCRCR_TXCRC_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3886
   --  unsupported macro: SPI_TXCRCR_TXCRC_Msk (0xFFFFFFFFUL << SPI_TXCRCR_TXCRC_Pos)
   --  unsupported macro: SPI_TXCRCR_TXCRC SPI_TXCRCR_TXCRC_Msk

   SPI_I2SCFGR_I2SMOD_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:3891
   --  unsupported macro: SPI_I2SCFGR_I2SMOD_Msk (0x1UL << SPI_I2SCFGR_I2SMOD_Pos)
   --  unsupported macro: SPI_I2SCFGR_I2SMOD SPI_I2SCFGR_I2SMOD_Msk

   SYSCFG_CFGR1_MEM_MODE_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3901
   --  unsupported macro: SYSCFG_CFGR1_MEM_MODE_Msk (0x3UL << SYSCFG_CFGR1_MEM_MODE_Pos)
   --  unsupported macro: SYSCFG_CFGR1_MEM_MODE SYSCFG_CFGR1_MEM_MODE_Msk
   --  unsupported macro: SYSCFG_CFGR1_MEM_MODE_0 (0x1UL << SYSCFG_CFGR1_MEM_MODE_Pos)
   --  unsupported macro: SYSCFG_CFGR1_MEM_MODE_1 (0x2UL << SYSCFG_CFGR1_MEM_MODE_Pos)

   SYSCFG_CFGR1_DMA_RMP_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3907
   --  unsupported macro: SYSCFG_CFGR1_DMA_RMP_Msk (0x1FUL << SYSCFG_CFGR1_DMA_RMP_Pos)
   --  unsupported macro: SYSCFG_CFGR1_DMA_RMP SYSCFG_CFGR1_DMA_RMP_Msk

   SYSCFG_CFGR1_ADC_DMA_RMP_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3910
   --  unsupported macro: SYSCFG_CFGR1_ADC_DMA_RMP_Msk (0x1UL << SYSCFG_CFGR1_ADC_DMA_RMP_Pos)
   --  unsupported macro: SYSCFG_CFGR1_ADC_DMA_RMP SYSCFG_CFGR1_ADC_DMA_RMP_Msk

   SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:3913
   --  unsupported macro: SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk (0x1UL << SYSCFG_CFGR1_USART1TX_DMA_RMP_Pos)
   --  unsupported macro: SYSCFG_CFGR1_USART1TX_DMA_RMP SYSCFG_CFGR1_USART1TX_DMA_RMP_Msk

   SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:3916
   --  unsupported macro: SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk (0x1UL << SYSCFG_CFGR1_USART1RX_DMA_RMP_Pos)
   --  unsupported macro: SYSCFG_CFGR1_USART1RX_DMA_RMP SYSCFG_CFGR1_USART1RX_DMA_RMP_Msk

   SYSCFG_CFGR1_TIM16_DMA_RMP_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:3919
   --  unsupported macro: SYSCFG_CFGR1_TIM16_DMA_RMP_Msk (0x1UL << SYSCFG_CFGR1_TIM16_DMA_RMP_Pos)
   --  unsupported macro: SYSCFG_CFGR1_TIM16_DMA_RMP SYSCFG_CFGR1_TIM16_DMA_RMP_Msk

   SYSCFG_CFGR1_TIM17_DMA_RMP_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:3922
   --  unsupported macro: SYSCFG_CFGR1_TIM17_DMA_RMP_Msk (0x1UL << SYSCFG_CFGR1_TIM17_DMA_RMP_Pos)
   --  unsupported macro: SYSCFG_CFGR1_TIM17_DMA_RMP SYSCFG_CFGR1_TIM17_DMA_RMP_Msk

   SYSCFG_CFGR1_I2C_FMP_PB6_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:3926
   --  unsupported macro: SYSCFG_CFGR1_I2C_FMP_PB6_Msk (0x1UL << SYSCFG_CFGR1_I2C_FMP_PB6_Pos)
   --  unsupported macro: SYSCFG_CFGR1_I2C_FMP_PB6 SYSCFG_CFGR1_I2C_FMP_PB6_Msk

   SYSCFG_CFGR1_I2C_FMP_PB7_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:3929
   --  unsupported macro: SYSCFG_CFGR1_I2C_FMP_PB7_Msk (0x1UL << SYSCFG_CFGR1_I2C_FMP_PB7_Pos)
   --  unsupported macro: SYSCFG_CFGR1_I2C_FMP_PB7 SYSCFG_CFGR1_I2C_FMP_PB7_Msk

   SYSCFG_CFGR1_I2C_FMP_PB8_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:3932
   --  unsupported macro: SYSCFG_CFGR1_I2C_FMP_PB8_Msk (0x1UL << SYSCFG_CFGR1_I2C_FMP_PB8_Pos)
   --  unsupported macro: SYSCFG_CFGR1_I2C_FMP_PB8 SYSCFG_CFGR1_I2C_FMP_PB8_Msk

   SYSCFG_CFGR1_I2C_FMP_PB9_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:3935
   --  unsupported macro: SYSCFG_CFGR1_I2C_FMP_PB9_Msk (0x1UL << SYSCFG_CFGR1_I2C_FMP_PB9_Pos)
   --  unsupported macro: SYSCFG_CFGR1_I2C_FMP_PB9 SYSCFG_CFGR1_I2C_FMP_PB9_Msk

   SYSCFG_CFGR1_I2C_FMP_I2C1_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:3938
   --  unsupported macro: SYSCFG_CFGR1_I2C_FMP_I2C1_Msk (0x1UL << SYSCFG_CFGR1_I2C_FMP_I2C1_Pos)
   --  unsupported macro: SYSCFG_CFGR1_I2C_FMP_I2C1 SYSCFG_CFGR1_I2C_FMP_I2C1_Msk

   SYSCFG_CFGR1_I2C_FMP_PA9_Pos : constant := (22);  --  ../core/include/stm32f0/stm32f030x6.h:3941
   --  unsupported macro: SYSCFG_CFGR1_I2C_FMP_PA9_Msk (0x1UL << SYSCFG_CFGR1_I2C_FMP_PA9_Pos)
   --  unsupported macro: SYSCFG_CFGR1_I2C_FMP_PA9 SYSCFG_CFGR1_I2C_FMP_PA9_Msk

   SYSCFG_CFGR1_I2C_FMP_PA10_Pos : constant := (23);  --  ../core/include/stm32f0/stm32f030x6.h:3944
   --  unsupported macro: SYSCFG_CFGR1_I2C_FMP_PA10_Msk (0x1UL << SYSCFG_CFGR1_I2C_FMP_PA10_Pos)
   --  unsupported macro: SYSCFG_CFGR1_I2C_FMP_PA10 SYSCFG_CFGR1_I2C_FMP_PA10_Msk

   SYSCFG_EXTICR1_EXTI0_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3949
   --  unsupported macro: SYSCFG_EXTICR1_EXTI0_Msk (0xFUL << SYSCFG_EXTICR1_EXTI0_Pos)
   --  unsupported macro: SYSCFG_EXTICR1_EXTI0 SYSCFG_EXTICR1_EXTI0_Msk

   SYSCFG_EXTICR1_EXTI1_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:3952
   --  unsupported macro: SYSCFG_EXTICR1_EXTI1_Msk (0xFUL << SYSCFG_EXTICR1_EXTI1_Pos)
   --  unsupported macro: SYSCFG_EXTICR1_EXTI1 SYSCFG_EXTICR1_EXTI1_Msk

   SYSCFG_EXTICR1_EXTI2_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:3955
   --  unsupported macro: SYSCFG_EXTICR1_EXTI2_Msk (0xFUL << SYSCFG_EXTICR1_EXTI2_Pos)
   --  unsupported macro: SYSCFG_EXTICR1_EXTI2 SYSCFG_EXTICR1_EXTI2_Msk

   SYSCFG_EXTICR1_EXTI3_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:3958
   --  unsupported macro: SYSCFG_EXTICR1_EXTI3_Msk (0xFUL << SYSCFG_EXTICR1_EXTI3_Pos)
   --  unsupported macro: SYSCFG_EXTICR1_EXTI3 SYSCFG_EXTICR1_EXTI3_Msk

   SYSCFG_EXTICR1_EXTI0_PA : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:3965
   SYSCFG_EXTICR1_EXTI0_PB : constant := (16#00000001#);  --  ../core/include/stm32f0/stm32f030x6.h:3966
   SYSCFG_EXTICR1_EXTI0_PC : constant := (16#00000002#);  --  ../core/include/stm32f0/stm32f030x6.h:3967
   SYSCFG_EXTICR1_EXTI0_PD : constant := (16#00000003#);  --  ../core/include/stm32f0/stm32f030x6.h:3968
   SYSCFG_EXTICR1_EXTI0_PF : constant := (16#00000005#);  --  ../core/include/stm32f0/stm32f030x6.h:3969

   SYSCFG_EXTICR1_EXTI1_PA : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:3974
   SYSCFG_EXTICR1_EXTI1_PB : constant := (16#00000010#);  --  ../core/include/stm32f0/stm32f030x6.h:3975
   SYSCFG_EXTICR1_EXTI1_PC : constant := (16#00000020#);  --  ../core/include/stm32f0/stm32f030x6.h:3976
   SYSCFG_EXTICR1_EXTI1_PD : constant := (16#00000030#);  --  ../core/include/stm32f0/stm32f030x6.h:3977
   SYSCFG_EXTICR1_EXTI1_PF : constant := (16#00000050#);  --  ../core/include/stm32f0/stm32f030x6.h:3978

   SYSCFG_EXTICR1_EXTI2_PA : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:3983
   SYSCFG_EXTICR1_EXTI2_PB : constant := (16#00000100#);  --  ../core/include/stm32f0/stm32f030x6.h:3984
   SYSCFG_EXTICR1_EXTI2_PC : constant := (16#00000200#);  --  ../core/include/stm32f0/stm32f030x6.h:3985
   SYSCFG_EXTICR1_EXTI2_PD : constant := (16#00000300#);  --  ../core/include/stm32f0/stm32f030x6.h:3986
   SYSCFG_EXTICR1_EXTI2_PF : constant := (16#00000500#);  --  ../core/include/stm32f0/stm32f030x6.h:3987

   SYSCFG_EXTICR1_EXTI3_PA : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:3992
   SYSCFG_EXTICR1_EXTI3_PB : constant := (16#00001000#);  --  ../core/include/stm32f0/stm32f030x6.h:3993
   SYSCFG_EXTICR1_EXTI3_PC : constant := (16#00002000#);  --  ../core/include/stm32f0/stm32f030x6.h:3994
   SYSCFG_EXTICR1_EXTI3_PD : constant := (16#00003000#);  --  ../core/include/stm32f0/stm32f030x6.h:3995
   SYSCFG_EXTICR1_EXTI3_PF : constant := (16#00005000#);  --  ../core/include/stm32f0/stm32f030x6.h:3996

   SYSCFG_EXTICR2_EXTI4_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:3999
   --  unsupported macro: SYSCFG_EXTICR2_EXTI4_Msk (0xFUL << SYSCFG_EXTICR2_EXTI4_Pos)
   --  unsupported macro: SYSCFG_EXTICR2_EXTI4 SYSCFG_EXTICR2_EXTI4_Msk

   SYSCFG_EXTICR2_EXTI5_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4002
   --  unsupported macro: SYSCFG_EXTICR2_EXTI5_Msk (0xFUL << SYSCFG_EXTICR2_EXTI5_Pos)
   --  unsupported macro: SYSCFG_EXTICR2_EXTI5 SYSCFG_EXTICR2_EXTI5_Msk

   SYSCFG_EXTICR2_EXTI6_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4005
   --  unsupported macro: SYSCFG_EXTICR2_EXTI6_Msk (0xFUL << SYSCFG_EXTICR2_EXTI6_Pos)
   --  unsupported macro: SYSCFG_EXTICR2_EXTI6 SYSCFG_EXTICR2_EXTI6_Msk

   SYSCFG_EXTICR2_EXTI7_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:4008
   --  unsupported macro: SYSCFG_EXTICR2_EXTI7_Msk (0xFUL << SYSCFG_EXTICR2_EXTI7_Pos)
   --  unsupported macro: SYSCFG_EXTICR2_EXTI7 SYSCFG_EXTICR2_EXTI7_Msk

   SYSCFG_EXTICR2_EXTI4_PA : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:4015
   SYSCFG_EXTICR2_EXTI4_PB : constant := (16#00000001#);  --  ../core/include/stm32f0/stm32f030x6.h:4016
   SYSCFG_EXTICR2_EXTI4_PC : constant := (16#00000002#);  --  ../core/include/stm32f0/stm32f030x6.h:4017
   SYSCFG_EXTICR2_EXTI4_PD : constant := (16#00000003#);  --  ../core/include/stm32f0/stm32f030x6.h:4018
   SYSCFG_EXTICR2_EXTI4_PF : constant := (16#00000005#);  --  ../core/include/stm32f0/stm32f030x6.h:4019

   SYSCFG_EXTICR2_EXTI5_PA : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:4024
   SYSCFG_EXTICR2_EXTI5_PB : constant := (16#00000010#);  --  ../core/include/stm32f0/stm32f030x6.h:4025
   SYSCFG_EXTICR2_EXTI5_PC : constant := (16#00000020#);  --  ../core/include/stm32f0/stm32f030x6.h:4026
   SYSCFG_EXTICR2_EXTI5_PD : constant := (16#00000030#);  --  ../core/include/stm32f0/stm32f030x6.h:4027
   SYSCFG_EXTICR2_EXTI5_PF : constant := (16#00000050#);  --  ../core/include/stm32f0/stm32f030x6.h:4028

   SYSCFG_EXTICR2_EXTI6_PA : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:4033
   SYSCFG_EXTICR2_EXTI6_PB : constant := (16#00000100#);  --  ../core/include/stm32f0/stm32f030x6.h:4034
   SYSCFG_EXTICR2_EXTI6_PC : constant := (16#00000200#);  --  ../core/include/stm32f0/stm32f030x6.h:4035
   SYSCFG_EXTICR2_EXTI6_PD : constant := (16#00000300#);  --  ../core/include/stm32f0/stm32f030x6.h:4036
   SYSCFG_EXTICR2_EXTI6_PF : constant := (16#00000500#);  --  ../core/include/stm32f0/stm32f030x6.h:4037

   SYSCFG_EXTICR2_EXTI7_PA : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:4042
   SYSCFG_EXTICR2_EXTI7_PB : constant := (16#00001000#);  --  ../core/include/stm32f0/stm32f030x6.h:4043
   SYSCFG_EXTICR2_EXTI7_PC : constant := (16#00002000#);  --  ../core/include/stm32f0/stm32f030x6.h:4044
   SYSCFG_EXTICR2_EXTI7_PD : constant := (16#00003000#);  --  ../core/include/stm32f0/stm32f030x6.h:4045
   SYSCFG_EXTICR2_EXTI7_PF : constant := (16#00005000#);  --  ../core/include/stm32f0/stm32f030x6.h:4046

   SYSCFG_EXTICR3_EXTI8_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4049
   --  unsupported macro: SYSCFG_EXTICR3_EXTI8_Msk (0xFUL << SYSCFG_EXTICR3_EXTI8_Pos)
   --  unsupported macro: SYSCFG_EXTICR3_EXTI8 SYSCFG_EXTICR3_EXTI8_Msk

   SYSCFG_EXTICR3_EXTI9_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4052
   --  unsupported macro: SYSCFG_EXTICR3_EXTI9_Msk (0xFUL << SYSCFG_EXTICR3_EXTI9_Pos)
   --  unsupported macro: SYSCFG_EXTICR3_EXTI9 SYSCFG_EXTICR3_EXTI9_Msk

   SYSCFG_EXTICR3_EXTI10_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4055
   --  unsupported macro: SYSCFG_EXTICR3_EXTI10_Msk (0xFUL << SYSCFG_EXTICR3_EXTI10_Pos)
   --  unsupported macro: SYSCFG_EXTICR3_EXTI10 SYSCFG_EXTICR3_EXTI10_Msk

   SYSCFG_EXTICR3_EXTI11_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:4058
   --  unsupported macro: SYSCFG_EXTICR3_EXTI11_Msk (0xFUL << SYSCFG_EXTICR3_EXTI11_Pos)
   --  unsupported macro: SYSCFG_EXTICR3_EXTI11 SYSCFG_EXTICR3_EXTI11_Msk

   SYSCFG_EXTICR3_EXTI8_PA : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:4065
   SYSCFG_EXTICR3_EXTI8_PB : constant := (16#00000001#);  --  ../core/include/stm32f0/stm32f030x6.h:4066
   SYSCFG_EXTICR3_EXTI8_PC : constant := (16#00000002#);  --  ../core/include/stm32f0/stm32f030x6.h:4067
   SYSCFG_EXTICR3_EXTI8_PD : constant := (16#00000003#);  --  ../core/include/stm32f0/stm32f030x6.h:4068
   SYSCFG_EXTICR3_EXTI8_PF : constant := (16#00000005#);  --  ../core/include/stm32f0/stm32f030x6.h:4069

   SYSCFG_EXTICR3_EXTI9_PA : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:4075
   SYSCFG_EXTICR3_EXTI9_PB : constant := (16#00000010#);  --  ../core/include/stm32f0/stm32f030x6.h:4076
   SYSCFG_EXTICR3_EXTI9_PC : constant := (16#00000020#);  --  ../core/include/stm32f0/stm32f030x6.h:4077
   SYSCFG_EXTICR3_EXTI9_PD : constant := (16#00000030#);  --  ../core/include/stm32f0/stm32f030x6.h:4078
   SYSCFG_EXTICR3_EXTI9_PF : constant := (16#00000050#);  --  ../core/include/stm32f0/stm32f030x6.h:4079

   SYSCFG_EXTICR3_EXTI10_PA : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:4084
   SYSCFG_EXTICR3_EXTI10_PB : constant := (16#00000100#);  --  ../core/include/stm32f0/stm32f030x6.h:4085
   SYSCFG_EXTICR3_EXTI10_PC : constant := (16#00000200#);  --  ../core/include/stm32f0/stm32f030x6.h:4086
   SYSCFG_EXTICR3_EXTI10_PD : constant := (16#00000300#);  --  ../core/include/stm32f0/stm32f030x6.h:4087
   SYSCFG_EXTICR3_EXTI10_PF : constant := (16#00000500#);  --  ../core/include/stm32f0/stm32f030x6.h:4088

   SYSCFG_EXTICR3_EXTI11_PA : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:4093
   SYSCFG_EXTICR3_EXTI11_PB : constant := (16#00001000#);  --  ../core/include/stm32f0/stm32f030x6.h:4094
   SYSCFG_EXTICR3_EXTI11_PC : constant := (16#00002000#);  --  ../core/include/stm32f0/stm32f030x6.h:4095
   SYSCFG_EXTICR3_EXTI11_PD : constant := (16#00003000#);  --  ../core/include/stm32f0/stm32f030x6.h:4096
   SYSCFG_EXTICR3_EXTI11_PF : constant := (16#00005000#);  --  ../core/include/stm32f0/stm32f030x6.h:4097

   SYSCFG_EXTICR4_EXTI12_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4100
   --  unsupported macro: SYSCFG_EXTICR4_EXTI12_Msk (0xFUL << SYSCFG_EXTICR4_EXTI12_Pos)
   --  unsupported macro: SYSCFG_EXTICR4_EXTI12 SYSCFG_EXTICR4_EXTI12_Msk

   SYSCFG_EXTICR4_EXTI13_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4103
   --  unsupported macro: SYSCFG_EXTICR4_EXTI13_Msk (0xFUL << SYSCFG_EXTICR4_EXTI13_Pos)
   --  unsupported macro: SYSCFG_EXTICR4_EXTI13 SYSCFG_EXTICR4_EXTI13_Msk

   SYSCFG_EXTICR4_EXTI14_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4106
   --  unsupported macro: SYSCFG_EXTICR4_EXTI14_Msk (0xFUL << SYSCFG_EXTICR4_EXTI14_Pos)
   --  unsupported macro: SYSCFG_EXTICR4_EXTI14 SYSCFG_EXTICR4_EXTI14_Msk

   SYSCFG_EXTICR4_EXTI15_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:4109
   --  unsupported macro: SYSCFG_EXTICR4_EXTI15_Msk (0xFUL << SYSCFG_EXTICR4_EXTI15_Pos)
   --  unsupported macro: SYSCFG_EXTICR4_EXTI15 SYSCFG_EXTICR4_EXTI15_Msk

   SYSCFG_EXTICR4_EXTI12_PA : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:4116
   SYSCFG_EXTICR4_EXTI12_PB : constant := (16#00000001#);  --  ../core/include/stm32f0/stm32f030x6.h:4117
   SYSCFG_EXTICR4_EXTI12_PC : constant := (16#00000002#);  --  ../core/include/stm32f0/stm32f030x6.h:4118
   SYSCFG_EXTICR4_EXTI12_PD : constant := (16#00000003#);  --  ../core/include/stm32f0/stm32f030x6.h:4119
   SYSCFG_EXTICR4_EXTI12_PF : constant := (16#00000005#);  --  ../core/include/stm32f0/stm32f030x6.h:4120

   SYSCFG_EXTICR4_EXTI13_PA : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:4125
   SYSCFG_EXTICR4_EXTI13_PB : constant := (16#00000010#);  --  ../core/include/stm32f0/stm32f030x6.h:4126
   SYSCFG_EXTICR4_EXTI13_PC : constant := (16#00000020#);  --  ../core/include/stm32f0/stm32f030x6.h:4127
   SYSCFG_EXTICR4_EXTI13_PD : constant := (16#00000030#);  --  ../core/include/stm32f0/stm32f030x6.h:4128
   SYSCFG_EXTICR4_EXTI13_PF : constant := (16#00000050#);  --  ../core/include/stm32f0/stm32f030x6.h:4129

   SYSCFG_EXTICR4_EXTI14_PA : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:4134
   SYSCFG_EXTICR4_EXTI14_PB : constant := (16#00000100#);  --  ../core/include/stm32f0/stm32f030x6.h:4135
   SYSCFG_EXTICR4_EXTI14_PC : constant := (16#00000200#);  --  ../core/include/stm32f0/stm32f030x6.h:4136
   SYSCFG_EXTICR4_EXTI14_PD : constant := (16#00000300#);  --  ../core/include/stm32f0/stm32f030x6.h:4137
   SYSCFG_EXTICR4_EXTI14_PF : constant := (16#00000500#);  --  ../core/include/stm32f0/stm32f030x6.h:4138

   SYSCFG_EXTICR4_EXTI15_PA : constant := (16#00000000#);  --  ../core/include/stm32f0/stm32f030x6.h:4143
   SYSCFG_EXTICR4_EXTI15_PB : constant := (16#00001000#);  --  ../core/include/stm32f0/stm32f030x6.h:4144
   SYSCFG_EXTICR4_EXTI15_PC : constant := (16#00002000#);  --  ../core/include/stm32f0/stm32f030x6.h:4145
   SYSCFG_EXTICR4_EXTI15_PD : constant := (16#00003000#);  --  ../core/include/stm32f0/stm32f030x6.h:4146
   SYSCFG_EXTICR4_EXTI15_PF : constant := (16#00005000#);  --  ../core/include/stm32f0/stm32f030x6.h:4147

   SYSCFG_CFGR2_LOCKUP_LOCK_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4150
   --  unsupported macro: SYSCFG_CFGR2_LOCKUP_LOCK_Msk (0x1UL << SYSCFG_CFGR2_LOCKUP_LOCK_Pos)
   --  unsupported macro: SYSCFG_CFGR2_LOCKUP_LOCK SYSCFG_CFGR2_LOCKUP_LOCK_Msk

   SYSCFG_CFGR2_SRAM_PARITY_LOCK_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:4153
   --  unsupported macro: SYSCFG_CFGR2_SRAM_PARITY_LOCK_Msk (0x1UL << SYSCFG_CFGR2_SRAM_PARITY_LOCK_Pos)
   --  unsupported macro: SYSCFG_CFGR2_SRAM_PARITY_LOCK SYSCFG_CFGR2_SRAM_PARITY_LOCK_Msk

   SYSCFG_CFGR2_SRAM_PEF_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4156
   --  unsupported macro: SYSCFG_CFGR2_SRAM_PEF_Msk (0x1UL << SYSCFG_CFGR2_SRAM_PEF_Pos)
   --  unsupported macro: SYSCFG_CFGR2_SRAM_PEF SYSCFG_CFGR2_SRAM_PEF_Msk
   --  unsupported macro: SYSCFG_CFGR2_SRAM_PE SYSCFG_CFGR2_SRAM_PEF

   TIM_CR1_CEN_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4167
   --  unsupported macro: TIM_CR1_CEN_Msk (0x1UL << TIM_CR1_CEN_Pos)
   --  unsupported macro: TIM_CR1_CEN TIM_CR1_CEN_Msk

   TIM_CR1_UDIS_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:4170
   --  unsupported macro: TIM_CR1_UDIS_Msk (0x1UL << TIM_CR1_UDIS_Pos)
   --  unsupported macro: TIM_CR1_UDIS TIM_CR1_UDIS_Msk

   TIM_CR1_URS_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:4173
   --  unsupported macro: TIM_CR1_URS_Msk (0x1UL << TIM_CR1_URS_Pos)
   --  unsupported macro: TIM_CR1_URS TIM_CR1_URS_Msk

   TIM_CR1_OPM_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:4176
   --  unsupported macro: TIM_CR1_OPM_Msk (0x1UL << TIM_CR1_OPM_Pos)
   --  unsupported macro: TIM_CR1_OPM TIM_CR1_OPM_Msk

   TIM_CR1_DIR_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4179
   --  unsupported macro: TIM_CR1_DIR_Msk (0x1UL << TIM_CR1_DIR_Pos)
   --  unsupported macro: TIM_CR1_DIR TIM_CR1_DIR_Msk

   TIM_CR1_CMS_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:4183
   --  unsupported macro: TIM_CR1_CMS_Msk (0x3UL << TIM_CR1_CMS_Pos)
   --  unsupported macro: TIM_CR1_CMS TIM_CR1_CMS_Msk
   --  unsupported macro: TIM_CR1_CMS_0 (0x1UL << TIM_CR1_CMS_Pos)
   --  unsupported macro: TIM_CR1_CMS_1 (0x2UL << TIM_CR1_CMS_Pos)

   TIM_CR1_ARPE_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:4189
   --  unsupported macro: TIM_CR1_ARPE_Msk (0x1UL << TIM_CR1_ARPE_Pos)
   --  unsupported macro: TIM_CR1_ARPE TIM_CR1_ARPE_Msk

   TIM_CR1_CKD_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4193
   --  unsupported macro: TIM_CR1_CKD_Msk (0x3UL << TIM_CR1_CKD_Pos)
   --  unsupported macro: TIM_CR1_CKD TIM_CR1_CKD_Msk
   --  unsupported macro: TIM_CR1_CKD_0 (0x1UL << TIM_CR1_CKD_Pos)
   --  unsupported macro: TIM_CR1_CKD_1 (0x2UL << TIM_CR1_CKD_Pos)

   TIM_CR2_CCPC_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4200
   --  unsupported macro: TIM_CR2_CCPC_Msk (0x1UL << TIM_CR2_CCPC_Pos)
   --  unsupported macro: TIM_CR2_CCPC TIM_CR2_CCPC_Msk

   TIM_CR2_CCUS_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:4203
   --  unsupported macro: TIM_CR2_CCUS_Msk (0x1UL << TIM_CR2_CCUS_Pos)
   --  unsupported macro: TIM_CR2_CCUS TIM_CR2_CCUS_Msk

   TIM_CR2_CCDS_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:4206
   --  unsupported macro: TIM_CR2_CCDS_Msk (0x1UL << TIM_CR2_CCDS_Pos)
   --  unsupported macro: TIM_CR2_CCDS TIM_CR2_CCDS_Msk

   TIM_CR2_MMS_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4210
   --  unsupported macro: TIM_CR2_MMS_Msk (0x7UL << TIM_CR2_MMS_Pos)
   --  unsupported macro: TIM_CR2_MMS TIM_CR2_MMS_Msk
   --  unsupported macro: TIM_CR2_MMS_0 (0x1UL << TIM_CR2_MMS_Pos)
   --  unsupported macro: TIM_CR2_MMS_1 (0x2UL << TIM_CR2_MMS_Pos)
   --  unsupported macro: TIM_CR2_MMS_2 (0x4UL << TIM_CR2_MMS_Pos)

   TIM_CR2_TI1S_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:4217
   --  unsupported macro: TIM_CR2_TI1S_Msk (0x1UL << TIM_CR2_TI1S_Pos)
   --  unsupported macro: TIM_CR2_TI1S TIM_CR2_TI1S_Msk

   TIM_CR2_OIS1_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4220
   --  unsupported macro: TIM_CR2_OIS1_Msk (0x1UL << TIM_CR2_OIS1_Pos)
   --  unsupported macro: TIM_CR2_OIS1 TIM_CR2_OIS1_Msk

   TIM_CR2_OIS1N_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:4223
   --  unsupported macro: TIM_CR2_OIS1N_Msk (0x1UL << TIM_CR2_OIS1N_Pos)
   --  unsupported macro: TIM_CR2_OIS1N TIM_CR2_OIS1N_Msk

   TIM_CR2_OIS2_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:4226
   --  unsupported macro: TIM_CR2_OIS2_Msk (0x1UL << TIM_CR2_OIS2_Pos)
   --  unsupported macro: TIM_CR2_OIS2 TIM_CR2_OIS2_Msk

   TIM_CR2_OIS2N_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:4229
   --  unsupported macro: TIM_CR2_OIS2N_Msk (0x1UL << TIM_CR2_OIS2N_Pos)
   --  unsupported macro: TIM_CR2_OIS2N TIM_CR2_OIS2N_Msk

   TIM_CR2_OIS3_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:4232
   --  unsupported macro: TIM_CR2_OIS3_Msk (0x1UL << TIM_CR2_OIS3_Pos)
   --  unsupported macro: TIM_CR2_OIS3 TIM_CR2_OIS3_Msk

   TIM_CR2_OIS3N_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:4235
   --  unsupported macro: TIM_CR2_OIS3N_Msk (0x1UL << TIM_CR2_OIS3N_Pos)
   --  unsupported macro: TIM_CR2_OIS3N TIM_CR2_OIS3N_Msk

   TIM_CR2_OIS4_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:4238
   --  unsupported macro: TIM_CR2_OIS4_Msk (0x1UL << TIM_CR2_OIS4_Pos)
   --  unsupported macro: TIM_CR2_OIS4 TIM_CR2_OIS4_Msk

   TIM_SMCR_SMS_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4243
   --  unsupported macro: TIM_SMCR_SMS_Msk (0x7UL << TIM_SMCR_SMS_Pos)
   --  unsupported macro: TIM_SMCR_SMS TIM_SMCR_SMS_Msk
   --  unsupported macro: TIM_SMCR_SMS_0 (0x1UL << TIM_SMCR_SMS_Pos)
   --  unsupported macro: TIM_SMCR_SMS_1 (0x2UL << TIM_SMCR_SMS_Pos)
   --  unsupported macro: TIM_SMCR_SMS_2 (0x4UL << TIM_SMCR_SMS_Pos)

   TIM_SMCR_OCCS_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:4250
   --  unsupported macro: TIM_SMCR_OCCS_Msk (0x1UL << TIM_SMCR_OCCS_Pos)
   --  unsupported macro: TIM_SMCR_OCCS TIM_SMCR_OCCS_Msk

   TIM_SMCR_TS_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4254
   --  unsupported macro: TIM_SMCR_TS_Msk (0x7UL << TIM_SMCR_TS_Pos)
   --  unsupported macro: TIM_SMCR_TS TIM_SMCR_TS_Msk
   --  unsupported macro: TIM_SMCR_TS_0 (0x1UL << TIM_SMCR_TS_Pos)
   --  unsupported macro: TIM_SMCR_TS_1 (0x2UL << TIM_SMCR_TS_Pos)
   --  unsupported macro: TIM_SMCR_TS_2 (0x4UL << TIM_SMCR_TS_Pos)

   TIM_SMCR_MSM_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:4261
   --  unsupported macro: TIM_SMCR_MSM_Msk (0x1UL << TIM_SMCR_MSM_Pos)
   --  unsupported macro: TIM_SMCR_MSM TIM_SMCR_MSM_Msk

   TIM_SMCR_ETF_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4265
   --  unsupported macro: TIM_SMCR_ETF_Msk (0xFUL << TIM_SMCR_ETF_Pos)
   --  unsupported macro: TIM_SMCR_ETF TIM_SMCR_ETF_Msk
   --  unsupported macro: TIM_SMCR_ETF_0 (0x1UL << TIM_SMCR_ETF_Pos)
   --  unsupported macro: TIM_SMCR_ETF_1 (0x2UL << TIM_SMCR_ETF_Pos)
   --  unsupported macro: TIM_SMCR_ETF_2 (0x4UL << TIM_SMCR_ETF_Pos)
   --  unsupported macro: TIM_SMCR_ETF_3 (0x8UL << TIM_SMCR_ETF_Pos)

   TIM_SMCR_ETPS_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:4273
   --  unsupported macro: TIM_SMCR_ETPS_Msk (0x3UL << TIM_SMCR_ETPS_Pos)
   --  unsupported macro: TIM_SMCR_ETPS TIM_SMCR_ETPS_Msk
   --  unsupported macro: TIM_SMCR_ETPS_0 (0x1UL << TIM_SMCR_ETPS_Pos)
   --  unsupported macro: TIM_SMCR_ETPS_1 (0x2UL << TIM_SMCR_ETPS_Pos)

   TIM_SMCR_ECE_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:4279
   --  unsupported macro: TIM_SMCR_ECE_Msk (0x1UL << TIM_SMCR_ECE_Pos)
   --  unsupported macro: TIM_SMCR_ECE TIM_SMCR_ECE_Msk

   TIM_SMCR_ETP_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:4282
   --  unsupported macro: TIM_SMCR_ETP_Msk (0x1UL << TIM_SMCR_ETP_Pos)
   --  unsupported macro: TIM_SMCR_ETP TIM_SMCR_ETP_Msk

   TIM_DIER_UIE_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4287
   --  unsupported macro: TIM_DIER_UIE_Msk (0x1UL << TIM_DIER_UIE_Pos)
   --  unsupported macro: TIM_DIER_UIE TIM_DIER_UIE_Msk

   TIM_DIER_CC1IE_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:4290
   --  unsupported macro: TIM_DIER_CC1IE_Msk (0x1UL << TIM_DIER_CC1IE_Pos)
   --  unsupported macro: TIM_DIER_CC1IE TIM_DIER_CC1IE_Msk

   TIM_DIER_CC2IE_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:4293
   --  unsupported macro: TIM_DIER_CC2IE_Msk (0x1UL << TIM_DIER_CC2IE_Pos)
   --  unsupported macro: TIM_DIER_CC2IE TIM_DIER_CC2IE_Msk

   TIM_DIER_CC3IE_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:4296
   --  unsupported macro: TIM_DIER_CC3IE_Msk (0x1UL << TIM_DIER_CC3IE_Pos)
   --  unsupported macro: TIM_DIER_CC3IE TIM_DIER_CC3IE_Msk

   TIM_DIER_CC4IE_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4299
   --  unsupported macro: TIM_DIER_CC4IE_Msk (0x1UL << TIM_DIER_CC4IE_Pos)
   --  unsupported macro: TIM_DIER_CC4IE TIM_DIER_CC4IE_Msk

   TIM_DIER_COMIE_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:4302
   --  unsupported macro: TIM_DIER_COMIE_Msk (0x1UL << TIM_DIER_COMIE_Pos)
   --  unsupported macro: TIM_DIER_COMIE TIM_DIER_COMIE_Msk

   TIM_DIER_TIE_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:4305
   --  unsupported macro: TIM_DIER_TIE_Msk (0x1UL << TIM_DIER_TIE_Pos)
   --  unsupported macro: TIM_DIER_TIE TIM_DIER_TIE_Msk

   TIM_DIER_BIE_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:4308
   --  unsupported macro: TIM_DIER_BIE_Msk (0x1UL << TIM_DIER_BIE_Pos)
   --  unsupported macro: TIM_DIER_BIE TIM_DIER_BIE_Msk

   TIM_DIER_UDE_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4311
   --  unsupported macro: TIM_DIER_UDE_Msk (0x1UL << TIM_DIER_UDE_Pos)
   --  unsupported macro: TIM_DIER_UDE TIM_DIER_UDE_Msk

   TIM_DIER_CC1DE_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:4314
   --  unsupported macro: TIM_DIER_CC1DE_Msk (0x1UL << TIM_DIER_CC1DE_Pos)
   --  unsupported macro: TIM_DIER_CC1DE TIM_DIER_CC1DE_Msk

   TIM_DIER_CC2DE_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:4317
   --  unsupported macro: TIM_DIER_CC2DE_Msk (0x1UL << TIM_DIER_CC2DE_Pos)
   --  unsupported macro: TIM_DIER_CC2DE TIM_DIER_CC2DE_Msk

   TIM_DIER_CC3DE_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:4320
   --  unsupported macro: TIM_DIER_CC3DE_Msk (0x1UL << TIM_DIER_CC3DE_Pos)
   --  unsupported macro: TIM_DIER_CC3DE TIM_DIER_CC3DE_Msk

   TIM_DIER_CC4DE_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:4323
   --  unsupported macro: TIM_DIER_CC4DE_Msk (0x1UL << TIM_DIER_CC4DE_Pos)
   --  unsupported macro: TIM_DIER_CC4DE TIM_DIER_CC4DE_Msk

   TIM_DIER_COMDE_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:4326
   --  unsupported macro: TIM_DIER_COMDE_Msk (0x1UL << TIM_DIER_COMDE_Pos)
   --  unsupported macro: TIM_DIER_COMDE TIM_DIER_COMDE_Msk

   TIM_DIER_TDE_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:4329
   --  unsupported macro: TIM_DIER_TDE_Msk (0x1UL << TIM_DIER_TDE_Pos)
   --  unsupported macro: TIM_DIER_TDE TIM_DIER_TDE_Msk

   TIM_SR_UIF_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4334
   --  unsupported macro: TIM_SR_UIF_Msk (0x1UL << TIM_SR_UIF_Pos)
   --  unsupported macro: TIM_SR_UIF TIM_SR_UIF_Msk

   TIM_SR_CC1IF_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:4337
   --  unsupported macro: TIM_SR_CC1IF_Msk (0x1UL << TIM_SR_CC1IF_Pos)
   --  unsupported macro: TIM_SR_CC1IF TIM_SR_CC1IF_Msk

   TIM_SR_CC2IF_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:4340
   --  unsupported macro: TIM_SR_CC2IF_Msk (0x1UL << TIM_SR_CC2IF_Pos)
   --  unsupported macro: TIM_SR_CC2IF TIM_SR_CC2IF_Msk

   TIM_SR_CC3IF_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:4343
   --  unsupported macro: TIM_SR_CC3IF_Msk (0x1UL << TIM_SR_CC3IF_Pos)
   --  unsupported macro: TIM_SR_CC3IF TIM_SR_CC3IF_Msk

   TIM_SR_CC4IF_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4346
   --  unsupported macro: TIM_SR_CC4IF_Msk (0x1UL << TIM_SR_CC4IF_Pos)
   --  unsupported macro: TIM_SR_CC4IF TIM_SR_CC4IF_Msk

   TIM_SR_COMIF_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:4349
   --  unsupported macro: TIM_SR_COMIF_Msk (0x1UL << TIM_SR_COMIF_Pos)
   --  unsupported macro: TIM_SR_COMIF TIM_SR_COMIF_Msk

   TIM_SR_TIF_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:4352
   --  unsupported macro: TIM_SR_TIF_Msk (0x1UL << TIM_SR_TIF_Pos)
   --  unsupported macro: TIM_SR_TIF TIM_SR_TIF_Msk

   TIM_SR_BIF_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:4355
   --  unsupported macro: TIM_SR_BIF_Msk (0x1UL << TIM_SR_BIF_Pos)
   --  unsupported macro: TIM_SR_BIF TIM_SR_BIF_Msk

   TIM_SR_CC1OF_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:4358
   --  unsupported macro: TIM_SR_CC1OF_Msk (0x1UL << TIM_SR_CC1OF_Pos)
   --  unsupported macro: TIM_SR_CC1OF TIM_SR_CC1OF_Msk

   TIM_SR_CC2OF_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:4361
   --  unsupported macro: TIM_SR_CC2OF_Msk (0x1UL << TIM_SR_CC2OF_Pos)
   --  unsupported macro: TIM_SR_CC2OF TIM_SR_CC2OF_Msk

   TIM_SR_CC3OF_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:4364
   --  unsupported macro: TIM_SR_CC3OF_Msk (0x1UL << TIM_SR_CC3OF_Pos)
   --  unsupported macro: TIM_SR_CC3OF TIM_SR_CC3OF_Msk

   TIM_SR_CC4OF_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:4367
   --  unsupported macro: TIM_SR_CC4OF_Msk (0x1UL << TIM_SR_CC4OF_Pos)
   --  unsupported macro: TIM_SR_CC4OF TIM_SR_CC4OF_Msk

   TIM_EGR_UG_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4372
   --  unsupported macro: TIM_EGR_UG_Msk (0x1UL << TIM_EGR_UG_Pos)
   --  unsupported macro: TIM_EGR_UG TIM_EGR_UG_Msk

   TIM_EGR_CC1G_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:4375
   --  unsupported macro: TIM_EGR_CC1G_Msk (0x1UL << TIM_EGR_CC1G_Pos)
   --  unsupported macro: TIM_EGR_CC1G TIM_EGR_CC1G_Msk

   TIM_EGR_CC2G_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:4378
   --  unsupported macro: TIM_EGR_CC2G_Msk (0x1UL << TIM_EGR_CC2G_Pos)
   --  unsupported macro: TIM_EGR_CC2G TIM_EGR_CC2G_Msk

   TIM_EGR_CC3G_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:4381
   --  unsupported macro: TIM_EGR_CC3G_Msk (0x1UL << TIM_EGR_CC3G_Pos)
   --  unsupported macro: TIM_EGR_CC3G TIM_EGR_CC3G_Msk

   TIM_EGR_CC4G_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4384
   --  unsupported macro: TIM_EGR_CC4G_Msk (0x1UL << TIM_EGR_CC4G_Pos)
   --  unsupported macro: TIM_EGR_CC4G TIM_EGR_CC4G_Msk

   TIM_EGR_COMG_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:4387
   --  unsupported macro: TIM_EGR_COMG_Msk (0x1UL << TIM_EGR_COMG_Pos)
   --  unsupported macro: TIM_EGR_COMG TIM_EGR_COMG_Msk

   TIM_EGR_TG_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:4390
   --  unsupported macro: TIM_EGR_TG_Msk (0x1UL << TIM_EGR_TG_Pos)
   --  unsupported macro: TIM_EGR_TG TIM_EGR_TG_Msk

   TIM_EGR_BG_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:4393
   --  unsupported macro: TIM_EGR_BG_Msk (0x1UL << TIM_EGR_BG_Pos)
   --  unsupported macro: TIM_EGR_BG TIM_EGR_BG_Msk

   TIM_CCMR1_CC1S_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4398
   --  unsupported macro: TIM_CCMR1_CC1S_Msk (0x3UL << TIM_CCMR1_CC1S_Pos)
   --  unsupported macro: TIM_CCMR1_CC1S TIM_CCMR1_CC1S_Msk
   --  unsupported macro: TIM_CCMR1_CC1S_0 (0x1UL << TIM_CCMR1_CC1S_Pos)
   --  unsupported macro: TIM_CCMR1_CC1S_1 (0x2UL << TIM_CCMR1_CC1S_Pos)

   TIM_CCMR1_OC1FE_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:4404
   --  unsupported macro: TIM_CCMR1_OC1FE_Msk (0x1UL << TIM_CCMR1_OC1FE_Pos)
   --  unsupported macro: TIM_CCMR1_OC1FE TIM_CCMR1_OC1FE_Msk

   TIM_CCMR1_OC1PE_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:4407
   --  unsupported macro: TIM_CCMR1_OC1PE_Msk (0x1UL << TIM_CCMR1_OC1PE_Pos)
   --  unsupported macro: TIM_CCMR1_OC1PE TIM_CCMR1_OC1PE_Msk

   TIM_CCMR1_OC1M_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4411
   --  unsupported macro: TIM_CCMR1_OC1M_Msk (0x7UL << TIM_CCMR1_OC1M_Pos)
   --  unsupported macro: TIM_CCMR1_OC1M TIM_CCMR1_OC1M_Msk
   --  unsupported macro: TIM_CCMR1_OC1M_0 (0x1UL << TIM_CCMR1_OC1M_Pos)
   --  unsupported macro: TIM_CCMR1_OC1M_1 (0x2UL << TIM_CCMR1_OC1M_Pos)
   --  unsupported macro: TIM_CCMR1_OC1M_2 (0x4UL << TIM_CCMR1_OC1M_Pos)

   TIM_CCMR1_OC1CE_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:4418
   --  unsupported macro: TIM_CCMR1_OC1CE_Msk (0x1UL << TIM_CCMR1_OC1CE_Pos)
   --  unsupported macro: TIM_CCMR1_OC1CE TIM_CCMR1_OC1CE_Msk

   TIM_CCMR1_CC2S_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4422
   --  unsupported macro: TIM_CCMR1_CC2S_Msk (0x3UL << TIM_CCMR1_CC2S_Pos)
   --  unsupported macro: TIM_CCMR1_CC2S TIM_CCMR1_CC2S_Msk
   --  unsupported macro: TIM_CCMR1_CC2S_0 (0x1UL << TIM_CCMR1_CC2S_Pos)
   --  unsupported macro: TIM_CCMR1_CC2S_1 (0x2UL << TIM_CCMR1_CC2S_Pos)

   TIM_CCMR1_OC2FE_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:4428
   --  unsupported macro: TIM_CCMR1_OC2FE_Msk (0x1UL << TIM_CCMR1_OC2FE_Pos)
   --  unsupported macro: TIM_CCMR1_OC2FE TIM_CCMR1_OC2FE_Msk

   TIM_CCMR1_OC2PE_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:4431
   --  unsupported macro: TIM_CCMR1_OC2PE_Msk (0x1UL << TIM_CCMR1_OC2PE_Pos)
   --  unsupported macro: TIM_CCMR1_OC2PE TIM_CCMR1_OC2PE_Msk

   TIM_CCMR1_OC2M_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:4435
   --  unsupported macro: TIM_CCMR1_OC2M_Msk (0x7UL << TIM_CCMR1_OC2M_Pos)
   --  unsupported macro: TIM_CCMR1_OC2M TIM_CCMR1_OC2M_Msk
   --  unsupported macro: TIM_CCMR1_OC2M_0 (0x1UL << TIM_CCMR1_OC2M_Pos)
   --  unsupported macro: TIM_CCMR1_OC2M_1 (0x2UL << TIM_CCMR1_OC2M_Pos)
   --  unsupported macro: TIM_CCMR1_OC2M_2 (0x4UL << TIM_CCMR1_OC2M_Pos)

   TIM_CCMR1_OC2CE_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:4442
   --  unsupported macro: TIM_CCMR1_OC2CE_Msk (0x1UL << TIM_CCMR1_OC2CE_Pos)
   --  unsupported macro: TIM_CCMR1_OC2CE TIM_CCMR1_OC2CE_Msk

   TIM_CCMR1_IC1PSC_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:4448
   --  unsupported macro: TIM_CCMR1_IC1PSC_Msk (0x3UL << TIM_CCMR1_IC1PSC_Pos)
   --  unsupported macro: TIM_CCMR1_IC1PSC TIM_CCMR1_IC1PSC_Msk
   --  unsupported macro: TIM_CCMR1_IC1PSC_0 (0x1UL << TIM_CCMR1_IC1PSC_Pos)
   --  unsupported macro: TIM_CCMR1_IC1PSC_1 (0x2UL << TIM_CCMR1_IC1PSC_Pos)

   TIM_CCMR1_IC1F_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4454
   --  unsupported macro: TIM_CCMR1_IC1F_Msk (0xFUL << TIM_CCMR1_IC1F_Pos)
   --  unsupported macro: TIM_CCMR1_IC1F TIM_CCMR1_IC1F_Msk
   --  unsupported macro: TIM_CCMR1_IC1F_0 (0x1UL << TIM_CCMR1_IC1F_Pos)
   --  unsupported macro: TIM_CCMR1_IC1F_1 (0x2UL << TIM_CCMR1_IC1F_Pos)
   --  unsupported macro: TIM_CCMR1_IC1F_2 (0x4UL << TIM_CCMR1_IC1F_Pos)
   --  unsupported macro: TIM_CCMR1_IC1F_3 (0x8UL << TIM_CCMR1_IC1F_Pos)

   TIM_CCMR1_IC2PSC_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:4462
   --  unsupported macro: TIM_CCMR1_IC2PSC_Msk (0x3UL << TIM_CCMR1_IC2PSC_Pos)
   --  unsupported macro: TIM_CCMR1_IC2PSC TIM_CCMR1_IC2PSC_Msk
   --  unsupported macro: TIM_CCMR1_IC2PSC_0 (0x1UL << TIM_CCMR1_IC2PSC_Pos)
   --  unsupported macro: TIM_CCMR1_IC2PSC_1 (0x2UL << TIM_CCMR1_IC2PSC_Pos)

   TIM_CCMR1_IC2F_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:4468
   --  unsupported macro: TIM_CCMR1_IC2F_Msk (0xFUL << TIM_CCMR1_IC2F_Pos)
   --  unsupported macro: TIM_CCMR1_IC2F TIM_CCMR1_IC2F_Msk
   --  unsupported macro: TIM_CCMR1_IC2F_0 (0x1UL << TIM_CCMR1_IC2F_Pos)
   --  unsupported macro: TIM_CCMR1_IC2F_1 (0x2UL << TIM_CCMR1_IC2F_Pos)
   --  unsupported macro: TIM_CCMR1_IC2F_2 (0x4UL << TIM_CCMR1_IC2F_Pos)
   --  unsupported macro: TIM_CCMR1_IC2F_3 (0x8UL << TIM_CCMR1_IC2F_Pos)

   TIM_CCMR2_CC3S_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4477
   --  unsupported macro: TIM_CCMR2_CC3S_Msk (0x3UL << TIM_CCMR2_CC3S_Pos)
   --  unsupported macro: TIM_CCMR2_CC3S TIM_CCMR2_CC3S_Msk
   --  unsupported macro: TIM_CCMR2_CC3S_0 (0x1UL << TIM_CCMR2_CC3S_Pos)
   --  unsupported macro: TIM_CCMR2_CC3S_1 (0x2UL << TIM_CCMR2_CC3S_Pos)

   TIM_CCMR2_OC3FE_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:4483
   --  unsupported macro: TIM_CCMR2_OC3FE_Msk (0x1UL << TIM_CCMR2_OC3FE_Pos)
   --  unsupported macro: TIM_CCMR2_OC3FE TIM_CCMR2_OC3FE_Msk

   TIM_CCMR2_OC3PE_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:4486
   --  unsupported macro: TIM_CCMR2_OC3PE_Msk (0x1UL << TIM_CCMR2_OC3PE_Pos)
   --  unsupported macro: TIM_CCMR2_OC3PE TIM_CCMR2_OC3PE_Msk

   TIM_CCMR2_OC3M_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4490
   --  unsupported macro: TIM_CCMR2_OC3M_Msk (0x7UL << TIM_CCMR2_OC3M_Pos)
   --  unsupported macro: TIM_CCMR2_OC3M TIM_CCMR2_OC3M_Msk
   --  unsupported macro: TIM_CCMR2_OC3M_0 (0x1UL << TIM_CCMR2_OC3M_Pos)
   --  unsupported macro: TIM_CCMR2_OC3M_1 (0x2UL << TIM_CCMR2_OC3M_Pos)
   --  unsupported macro: TIM_CCMR2_OC3M_2 (0x4UL << TIM_CCMR2_OC3M_Pos)

   TIM_CCMR2_OC3CE_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:4497
   --  unsupported macro: TIM_CCMR2_OC3CE_Msk (0x1UL << TIM_CCMR2_OC3CE_Pos)
   --  unsupported macro: TIM_CCMR2_OC3CE TIM_CCMR2_OC3CE_Msk

   TIM_CCMR2_CC4S_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4501
   --  unsupported macro: TIM_CCMR2_CC4S_Msk (0x3UL << TIM_CCMR2_CC4S_Pos)
   --  unsupported macro: TIM_CCMR2_CC4S TIM_CCMR2_CC4S_Msk
   --  unsupported macro: TIM_CCMR2_CC4S_0 (0x1UL << TIM_CCMR2_CC4S_Pos)
   --  unsupported macro: TIM_CCMR2_CC4S_1 (0x2UL << TIM_CCMR2_CC4S_Pos)

   TIM_CCMR2_OC4FE_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:4507
   --  unsupported macro: TIM_CCMR2_OC4FE_Msk (0x1UL << TIM_CCMR2_OC4FE_Pos)
   --  unsupported macro: TIM_CCMR2_OC4FE TIM_CCMR2_OC4FE_Msk

   TIM_CCMR2_OC4PE_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:4510
   --  unsupported macro: TIM_CCMR2_OC4PE_Msk (0x1UL << TIM_CCMR2_OC4PE_Pos)
   --  unsupported macro: TIM_CCMR2_OC4PE TIM_CCMR2_OC4PE_Msk

   TIM_CCMR2_OC4M_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:4514
   --  unsupported macro: TIM_CCMR2_OC4M_Msk (0x7UL << TIM_CCMR2_OC4M_Pos)
   --  unsupported macro: TIM_CCMR2_OC4M TIM_CCMR2_OC4M_Msk
   --  unsupported macro: TIM_CCMR2_OC4M_0 (0x1UL << TIM_CCMR2_OC4M_Pos)
   --  unsupported macro: TIM_CCMR2_OC4M_1 (0x2UL << TIM_CCMR2_OC4M_Pos)
   --  unsupported macro: TIM_CCMR2_OC4M_2 (0x4UL << TIM_CCMR2_OC4M_Pos)

   TIM_CCMR2_OC4CE_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:4521
   --  unsupported macro: TIM_CCMR2_OC4CE_Msk (0x1UL << TIM_CCMR2_OC4CE_Pos)
   --  unsupported macro: TIM_CCMR2_OC4CE TIM_CCMR2_OC4CE_Msk

   TIM_CCMR2_IC3PSC_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:4527
   --  unsupported macro: TIM_CCMR2_IC3PSC_Msk (0x3UL << TIM_CCMR2_IC3PSC_Pos)
   --  unsupported macro: TIM_CCMR2_IC3PSC TIM_CCMR2_IC3PSC_Msk
   --  unsupported macro: TIM_CCMR2_IC3PSC_0 (0x1UL << TIM_CCMR2_IC3PSC_Pos)
   --  unsupported macro: TIM_CCMR2_IC3PSC_1 (0x2UL << TIM_CCMR2_IC3PSC_Pos)

   TIM_CCMR2_IC3F_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4533
   --  unsupported macro: TIM_CCMR2_IC3F_Msk (0xFUL << TIM_CCMR2_IC3F_Pos)
   --  unsupported macro: TIM_CCMR2_IC3F TIM_CCMR2_IC3F_Msk
   --  unsupported macro: TIM_CCMR2_IC3F_0 (0x1UL << TIM_CCMR2_IC3F_Pos)
   --  unsupported macro: TIM_CCMR2_IC3F_1 (0x2UL << TIM_CCMR2_IC3F_Pos)
   --  unsupported macro: TIM_CCMR2_IC3F_2 (0x4UL << TIM_CCMR2_IC3F_Pos)
   --  unsupported macro: TIM_CCMR2_IC3F_3 (0x8UL << TIM_CCMR2_IC3F_Pos)

   TIM_CCMR2_IC4PSC_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:4541
   --  unsupported macro: TIM_CCMR2_IC4PSC_Msk (0x3UL << TIM_CCMR2_IC4PSC_Pos)
   --  unsupported macro: TIM_CCMR2_IC4PSC TIM_CCMR2_IC4PSC_Msk
   --  unsupported macro: TIM_CCMR2_IC4PSC_0 (0x1UL << TIM_CCMR2_IC4PSC_Pos)
   --  unsupported macro: TIM_CCMR2_IC4PSC_1 (0x2UL << TIM_CCMR2_IC4PSC_Pos)

   TIM_CCMR2_IC4F_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:4547
   --  unsupported macro: TIM_CCMR2_IC4F_Msk (0xFUL << TIM_CCMR2_IC4F_Pos)
   --  unsupported macro: TIM_CCMR2_IC4F TIM_CCMR2_IC4F_Msk
   --  unsupported macro: TIM_CCMR2_IC4F_0 (0x1UL << TIM_CCMR2_IC4F_Pos)
   --  unsupported macro: TIM_CCMR2_IC4F_1 (0x2UL << TIM_CCMR2_IC4F_Pos)
   --  unsupported macro: TIM_CCMR2_IC4F_2 (0x4UL << TIM_CCMR2_IC4F_Pos)
   --  unsupported macro: TIM_CCMR2_IC4F_3 (0x8UL << TIM_CCMR2_IC4F_Pos)

   TIM_CCER_CC1E_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4556
   --  unsupported macro: TIM_CCER_CC1E_Msk (0x1UL << TIM_CCER_CC1E_Pos)
   --  unsupported macro: TIM_CCER_CC1E TIM_CCER_CC1E_Msk

   TIM_CCER_CC1P_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:4559
   --  unsupported macro: TIM_CCER_CC1P_Msk (0x1UL << TIM_CCER_CC1P_Pos)
   --  unsupported macro: TIM_CCER_CC1P TIM_CCER_CC1P_Msk

   TIM_CCER_CC1NE_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:4562
   --  unsupported macro: TIM_CCER_CC1NE_Msk (0x1UL << TIM_CCER_CC1NE_Pos)
   --  unsupported macro: TIM_CCER_CC1NE TIM_CCER_CC1NE_Msk

   TIM_CCER_CC1NP_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:4565
   --  unsupported macro: TIM_CCER_CC1NP_Msk (0x1UL << TIM_CCER_CC1NP_Pos)
   --  unsupported macro: TIM_CCER_CC1NP TIM_CCER_CC1NP_Msk

   TIM_CCER_CC2E_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4568
   --  unsupported macro: TIM_CCER_CC2E_Msk (0x1UL << TIM_CCER_CC2E_Pos)
   --  unsupported macro: TIM_CCER_CC2E TIM_CCER_CC2E_Msk

   TIM_CCER_CC2P_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:4571
   --  unsupported macro: TIM_CCER_CC2P_Msk (0x1UL << TIM_CCER_CC2P_Pos)
   --  unsupported macro: TIM_CCER_CC2P TIM_CCER_CC2P_Msk

   TIM_CCER_CC2NE_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:4574
   --  unsupported macro: TIM_CCER_CC2NE_Msk (0x1UL << TIM_CCER_CC2NE_Pos)
   --  unsupported macro: TIM_CCER_CC2NE TIM_CCER_CC2NE_Msk

   TIM_CCER_CC2NP_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:4577
   --  unsupported macro: TIM_CCER_CC2NP_Msk (0x1UL << TIM_CCER_CC2NP_Pos)
   --  unsupported macro: TIM_CCER_CC2NP TIM_CCER_CC2NP_Msk

   TIM_CCER_CC3E_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4580
   --  unsupported macro: TIM_CCER_CC3E_Msk (0x1UL << TIM_CCER_CC3E_Pos)
   --  unsupported macro: TIM_CCER_CC3E TIM_CCER_CC3E_Msk

   TIM_CCER_CC3P_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:4583
   --  unsupported macro: TIM_CCER_CC3P_Msk (0x1UL << TIM_CCER_CC3P_Pos)
   --  unsupported macro: TIM_CCER_CC3P TIM_CCER_CC3P_Msk

   TIM_CCER_CC3NE_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:4586
   --  unsupported macro: TIM_CCER_CC3NE_Msk (0x1UL << TIM_CCER_CC3NE_Pos)
   --  unsupported macro: TIM_CCER_CC3NE TIM_CCER_CC3NE_Msk

   TIM_CCER_CC3NP_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:4589
   --  unsupported macro: TIM_CCER_CC3NP_Msk (0x1UL << TIM_CCER_CC3NP_Pos)
   --  unsupported macro: TIM_CCER_CC3NP TIM_CCER_CC3NP_Msk

   TIM_CCER_CC4E_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:4592
   --  unsupported macro: TIM_CCER_CC4E_Msk (0x1UL << TIM_CCER_CC4E_Pos)
   --  unsupported macro: TIM_CCER_CC4E TIM_CCER_CC4E_Msk

   TIM_CCER_CC4P_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:4595
   --  unsupported macro: TIM_CCER_CC4P_Msk (0x1UL << TIM_CCER_CC4P_Pos)
   --  unsupported macro: TIM_CCER_CC4P TIM_CCER_CC4P_Msk

   TIM_CCER_CC4NP_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:4598
   --  unsupported macro: TIM_CCER_CC4NP_Msk (0x1UL << TIM_CCER_CC4NP_Pos)
   --  unsupported macro: TIM_CCER_CC4NP TIM_CCER_CC4NP_Msk

   TIM_CNT_CNT_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4603
   --  unsupported macro: TIM_CNT_CNT_Msk (0xFFFFFFFFUL << TIM_CNT_CNT_Pos)
   --  unsupported macro: TIM_CNT_CNT TIM_CNT_CNT_Msk

   TIM_PSC_PSC_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4608
   --  unsupported macro: TIM_PSC_PSC_Msk (0xFFFFUL << TIM_PSC_PSC_Pos)
   --  unsupported macro: TIM_PSC_PSC TIM_PSC_PSC_Msk

   TIM_ARR_ARR_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4613
   --  unsupported macro: TIM_ARR_ARR_Msk (0xFFFFFFFFUL << TIM_ARR_ARR_Pos)
   --  unsupported macro: TIM_ARR_ARR TIM_ARR_ARR_Msk

   TIM_RCR_REP_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4618
   --  unsupported macro: TIM_RCR_REP_Msk (0xFFUL << TIM_RCR_REP_Pos)
   --  unsupported macro: TIM_RCR_REP TIM_RCR_REP_Msk

   TIM_CCR1_CCR1_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4623
   --  unsupported macro: TIM_CCR1_CCR1_Msk (0xFFFFUL << TIM_CCR1_CCR1_Pos)
   --  unsupported macro: TIM_CCR1_CCR1 TIM_CCR1_CCR1_Msk

   TIM_CCR2_CCR2_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4628
   --  unsupported macro: TIM_CCR2_CCR2_Msk (0xFFFFUL << TIM_CCR2_CCR2_Pos)
   --  unsupported macro: TIM_CCR2_CCR2 TIM_CCR2_CCR2_Msk

   TIM_CCR3_CCR3_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4633
   --  unsupported macro: TIM_CCR3_CCR3_Msk (0xFFFFUL << TIM_CCR3_CCR3_Pos)
   --  unsupported macro: TIM_CCR3_CCR3 TIM_CCR3_CCR3_Msk

   TIM_CCR4_CCR4_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4638
   --  unsupported macro: TIM_CCR4_CCR4_Msk (0xFFFFUL << TIM_CCR4_CCR4_Pos)
   --  unsupported macro: TIM_CCR4_CCR4 TIM_CCR4_CCR4_Msk

   TIM_BDTR_DTG_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4643
   --  unsupported macro: TIM_BDTR_DTG_Msk (0xFFUL << TIM_BDTR_DTG_Pos)
   --  unsupported macro: TIM_BDTR_DTG TIM_BDTR_DTG_Msk
   --  unsupported macro: TIM_BDTR_DTG_0 (0x01UL << TIM_BDTR_DTG_Pos)
   --  unsupported macro: TIM_BDTR_DTG_1 (0x02UL << TIM_BDTR_DTG_Pos)
   --  unsupported macro: TIM_BDTR_DTG_2 (0x04UL << TIM_BDTR_DTG_Pos)
   --  unsupported macro: TIM_BDTR_DTG_3 (0x08UL << TIM_BDTR_DTG_Pos)
   --  unsupported macro: TIM_BDTR_DTG_4 (0x10UL << TIM_BDTR_DTG_Pos)
   --  unsupported macro: TIM_BDTR_DTG_5 (0x20UL << TIM_BDTR_DTG_Pos)
   --  unsupported macro: TIM_BDTR_DTG_6 (0x40UL << TIM_BDTR_DTG_Pos)
   --  unsupported macro: TIM_BDTR_DTG_7 (0x80UL << TIM_BDTR_DTG_Pos)

   TIM_BDTR_LOCK_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4655
   --  unsupported macro: TIM_BDTR_LOCK_Msk (0x3UL << TIM_BDTR_LOCK_Pos)
   --  unsupported macro: TIM_BDTR_LOCK TIM_BDTR_LOCK_Msk
   --  unsupported macro: TIM_BDTR_LOCK_0 (0x1UL << TIM_BDTR_LOCK_Pos)
   --  unsupported macro: TIM_BDTR_LOCK_1 (0x2UL << TIM_BDTR_LOCK_Pos)

   TIM_BDTR_OSSI_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:4661
   --  unsupported macro: TIM_BDTR_OSSI_Msk (0x1UL << TIM_BDTR_OSSI_Pos)
   --  unsupported macro: TIM_BDTR_OSSI TIM_BDTR_OSSI_Msk

   TIM_BDTR_OSSR_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:4664
   --  unsupported macro: TIM_BDTR_OSSR_Msk (0x1UL << TIM_BDTR_OSSR_Pos)
   --  unsupported macro: TIM_BDTR_OSSR TIM_BDTR_OSSR_Msk

   TIM_BDTR_BKE_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:4667
   --  unsupported macro: TIM_BDTR_BKE_Msk (0x1UL << TIM_BDTR_BKE_Pos)
   --  unsupported macro: TIM_BDTR_BKE TIM_BDTR_BKE_Msk

   TIM_BDTR_BKP_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:4670
   --  unsupported macro: TIM_BDTR_BKP_Msk (0x1UL << TIM_BDTR_BKP_Pos)
   --  unsupported macro: TIM_BDTR_BKP TIM_BDTR_BKP_Msk

   TIM_BDTR_AOE_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:4673
   --  unsupported macro: TIM_BDTR_AOE_Msk (0x1UL << TIM_BDTR_AOE_Pos)
   --  unsupported macro: TIM_BDTR_AOE TIM_BDTR_AOE_Msk

   TIM_BDTR_MOE_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:4676
   --  unsupported macro: TIM_BDTR_MOE_Msk (0x1UL << TIM_BDTR_MOE_Pos)
   --  unsupported macro: TIM_BDTR_MOE TIM_BDTR_MOE_Msk

   TIM_DCR_DBA_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4681
   --  unsupported macro: TIM_DCR_DBA_Msk (0x1FUL << TIM_DCR_DBA_Pos)
   --  unsupported macro: TIM_DCR_DBA TIM_DCR_DBA_Msk
   --  unsupported macro: TIM_DCR_DBA_0 (0x01UL << TIM_DCR_DBA_Pos)
   --  unsupported macro: TIM_DCR_DBA_1 (0x02UL << TIM_DCR_DBA_Pos)
   --  unsupported macro: TIM_DCR_DBA_2 (0x04UL << TIM_DCR_DBA_Pos)
   --  unsupported macro: TIM_DCR_DBA_3 (0x08UL << TIM_DCR_DBA_Pos)
   --  unsupported macro: TIM_DCR_DBA_4 (0x10UL << TIM_DCR_DBA_Pos)

   TIM_DCR_DBL_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4690
   --  unsupported macro: TIM_DCR_DBL_Msk (0x1FUL << TIM_DCR_DBL_Pos)
   --  unsupported macro: TIM_DCR_DBL TIM_DCR_DBL_Msk
   --  unsupported macro: TIM_DCR_DBL_0 (0x01UL << TIM_DCR_DBL_Pos)
   --  unsupported macro: TIM_DCR_DBL_1 (0x02UL << TIM_DCR_DBL_Pos)
   --  unsupported macro: TIM_DCR_DBL_2 (0x04UL << TIM_DCR_DBL_Pos)
   --  unsupported macro: TIM_DCR_DBL_3 (0x08UL << TIM_DCR_DBL_Pos)
   --  unsupported macro: TIM_DCR_DBL_4 (0x10UL << TIM_DCR_DBL_Pos)

   TIM_DMAR_DMAB_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4700
   --  unsupported macro: TIM_DMAR_DMAB_Msk (0xFFFFUL << TIM_DMAR_DMAB_Pos)
   --  unsupported macro: TIM_DMAR_DMAB TIM_DMAR_DMAB_Msk

   TIM14_OR_TI1_RMP_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4705
   --  unsupported macro: TIM14_OR_TI1_RMP_Msk (0x3UL << TIM14_OR_TI1_RMP_Pos)
   --  unsupported macro: TIM14_OR_TI1_RMP TIM14_OR_TI1_RMP_Msk
   --  unsupported macro: TIM14_OR_TI1_RMP_0 (0x1UL << TIM14_OR_TI1_RMP_Pos)
   --  unsupported macro: TIM14_OR_TI1_RMP_1 (0x2UL << TIM14_OR_TI1_RMP_Pos)

   USART_CR1_UE_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4717
   --  unsupported macro: USART_CR1_UE_Msk (0x1UL << USART_CR1_UE_Pos)
   --  unsupported macro: USART_CR1_UE USART_CR1_UE_Msk

   USART_CR1_RE_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:4720
   --  unsupported macro: USART_CR1_RE_Msk (0x1UL << USART_CR1_RE_Pos)
   --  unsupported macro: USART_CR1_RE USART_CR1_RE_Msk

   USART_CR1_TE_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:4723
   --  unsupported macro: USART_CR1_TE_Msk (0x1UL << USART_CR1_TE_Pos)
   --  unsupported macro: USART_CR1_TE USART_CR1_TE_Msk

   USART_CR1_IDLEIE_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4726
   --  unsupported macro: USART_CR1_IDLEIE_Msk (0x1UL << USART_CR1_IDLEIE_Pos)
   --  unsupported macro: USART_CR1_IDLEIE USART_CR1_IDLEIE_Msk

   USART_CR1_RXNEIE_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:4729
   --  unsupported macro: USART_CR1_RXNEIE_Msk (0x1UL << USART_CR1_RXNEIE_Pos)
   --  unsupported macro: USART_CR1_RXNEIE USART_CR1_RXNEIE_Msk

   USART_CR1_TCIE_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:4732
   --  unsupported macro: USART_CR1_TCIE_Msk (0x1UL << USART_CR1_TCIE_Pos)
   --  unsupported macro: USART_CR1_TCIE USART_CR1_TCIE_Msk

   USART_CR1_TXEIE_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:4735
   --  unsupported macro: USART_CR1_TXEIE_Msk (0x1UL << USART_CR1_TXEIE_Pos)
   --  unsupported macro: USART_CR1_TXEIE USART_CR1_TXEIE_Msk

   USART_CR1_PEIE_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4738
   --  unsupported macro: USART_CR1_PEIE_Msk (0x1UL << USART_CR1_PEIE_Pos)
   --  unsupported macro: USART_CR1_PEIE USART_CR1_PEIE_Msk

   USART_CR1_PS_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:4741
   --  unsupported macro: USART_CR1_PS_Msk (0x1UL << USART_CR1_PS_Pos)
   --  unsupported macro: USART_CR1_PS USART_CR1_PS_Msk

   USART_CR1_PCE_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:4744
   --  unsupported macro: USART_CR1_PCE_Msk (0x1UL << USART_CR1_PCE_Pos)
   --  unsupported macro: USART_CR1_PCE USART_CR1_PCE_Msk

   USART_CR1_WAKE_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:4747
   --  unsupported macro: USART_CR1_WAKE_Msk (0x1UL << USART_CR1_WAKE_Pos)
   --  unsupported macro: USART_CR1_WAKE USART_CR1_WAKE_Msk

   USART_CR1_M_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:4750
   --  unsupported macro: USART_CR1_M_Msk (0x1UL << USART_CR1_M_Pos)
   --  unsupported macro: USART_CR1_M USART_CR1_M_Msk

   USART_CR1_MME_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:4753
   --  unsupported macro: USART_CR1_MME_Msk (0x1UL << USART_CR1_MME_Pos)
   --  unsupported macro: USART_CR1_MME USART_CR1_MME_Msk

   USART_CR1_CMIE_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:4756
   --  unsupported macro: USART_CR1_CMIE_Msk (0x1UL << USART_CR1_CMIE_Pos)
   --  unsupported macro: USART_CR1_CMIE USART_CR1_CMIE_Msk

   USART_CR1_OVER8_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:4759
   --  unsupported macro: USART_CR1_OVER8_Msk (0x1UL << USART_CR1_OVER8_Pos)
   --  unsupported macro: USART_CR1_OVER8 USART_CR1_OVER8_Msk

   USART_CR1_DEDT_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:4762
   --  unsupported macro: USART_CR1_DEDT_Msk (0x1FUL << USART_CR1_DEDT_Pos)
   --  unsupported macro: USART_CR1_DEDT USART_CR1_DEDT_Msk
   --  unsupported macro: USART_CR1_DEDT_0 (0x01UL << USART_CR1_DEDT_Pos)
   --  unsupported macro: USART_CR1_DEDT_1 (0x02UL << USART_CR1_DEDT_Pos)
   --  unsupported macro: USART_CR1_DEDT_2 (0x04UL << USART_CR1_DEDT_Pos)
   --  unsupported macro: USART_CR1_DEDT_3 (0x08UL << USART_CR1_DEDT_Pos)
   --  unsupported macro: USART_CR1_DEDT_4 (0x10UL << USART_CR1_DEDT_Pos)

   USART_CR1_DEAT_Pos : constant := (21);  --  ../core/include/stm32f0/stm32f030x6.h:4770
   --  unsupported macro: USART_CR1_DEAT_Msk (0x1FUL << USART_CR1_DEAT_Pos)
   --  unsupported macro: USART_CR1_DEAT USART_CR1_DEAT_Msk
   --  unsupported macro: USART_CR1_DEAT_0 (0x01UL << USART_CR1_DEAT_Pos)
   --  unsupported macro: USART_CR1_DEAT_1 (0x02UL << USART_CR1_DEAT_Pos)
   --  unsupported macro: USART_CR1_DEAT_2 (0x04UL << USART_CR1_DEAT_Pos)
   --  unsupported macro: USART_CR1_DEAT_3 (0x08UL << USART_CR1_DEAT_Pos)
   --  unsupported macro: USART_CR1_DEAT_4 (0x10UL << USART_CR1_DEAT_Pos)

   USART_CR1_RTOIE_Pos : constant := (26);  --  ../core/include/stm32f0/stm32f030x6.h:4778
   --  unsupported macro: USART_CR1_RTOIE_Msk (0x1UL << USART_CR1_RTOIE_Pos)
   --  unsupported macro: USART_CR1_RTOIE USART_CR1_RTOIE_Msk

   USART_CR1_EOBIE_Pos : constant := (27);  --  ../core/include/stm32f0/stm32f030x6.h:4781
   --  unsupported macro: USART_CR1_EOBIE_Msk (0x1UL << USART_CR1_EOBIE_Pos)
   --  unsupported macro: USART_CR1_EOBIE USART_CR1_EOBIE_Msk

   USART_CR2_ADDM7_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4786
   --  unsupported macro: USART_CR2_ADDM7_Msk (0x1UL << USART_CR2_ADDM7_Pos)
   --  unsupported macro: USART_CR2_ADDM7 USART_CR2_ADDM7_Msk

   USART_CR2_LBCL_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4789
   --  unsupported macro: USART_CR2_LBCL_Msk (0x1UL << USART_CR2_LBCL_Pos)
   --  unsupported macro: USART_CR2_LBCL USART_CR2_LBCL_Msk

   USART_CR2_CPHA_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:4792
   --  unsupported macro: USART_CR2_CPHA_Msk (0x1UL << USART_CR2_CPHA_Pos)
   --  unsupported macro: USART_CR2_CPHA USART_CR2_CPHA_Msk

   USART_CR2_CPOL_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:4795
   --  unsupported macro: USART_CR2_CPOL_Msk (0x1UL << USART_CR2_CPOL_Pos)
   --  unsupported macro: USART_CR2_CPOL USART_CR2_CPOL_Msk

   USART_CR2_CLKEN_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:4798
   --  unsupported macro: USART_CR2_CLKEN_Msk (0x1UL << USART_CR2_CLKEN_Pos)
   --  unsupported macro: USART_CR2_CLKEN USART_CR2_CLKEN_Msk

   USART_CR2_STOP_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:4801
   --  unsupported macro: USART_CR2_STOP_Msk (0x3UL << USART_CR2_STOP_Pos)
   --  unsupported macro: USART_CR2_STOP USART_CR2_STOP_Msk
   --  unsupported macro: USART_CR2_STOP_0 (0x1UL << USART_CR2_STOP_Pos)
   --  unsupported macro: USART_CR2_STOP_1 (0x2UL << USART_CR2_STOP_Pos)

   USART_CR2_SWAP_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:4806
   --  unsupported macro: USART_CR2_SWAP_Msk (0x1UL << USART_CR2_SWAP_Pos)
   --  unsupported macro: USART_CR2_SWAP USART_CR2_SWAP_Msk

   USART_CR2_RXINV_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:4809
   --  unsupported macro: USART_CR2_RXINV_Msk (0x1UL << USART_CR2_RXINV_Pos)
   --  unsupported macro: USART_CR2_RXINV USART_CR2_RXINV_Msk

   USART_CR2_TXINV_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:4812
   --  unsupported macro: USART_CR2_TXINV_Msk (0x1UL << USART_CR2_TXINV_Pos)
   --  unsupported macro: USART_CR2_TXINV USART_CR2_TXINV_Msk

   USART_CR2_DATAINV_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:4815
   --  unsupported macro: USART_CR2_DATAINV_Msk (0x1UL << USART_CR2_DATAINV_Pos)
   --  unsupported macro: USART_CR2_DATAINV USART_CR2_DATAINV_Msk

   USART_CR2_MSBFIRST_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:4818
   --  unsupported macro: USART_CR2_MSBFIRST_Msk (0x1UL << USART_CR2_MSBFIRST_Pos)
   --  unsupported macro: USART_CR2_MSBFIRST USART_CR2_MSBFIRST_Msk

   USART_CR2_ABREN_Pos : constant := (20);  --  ../core/include/stm32f0/stm32f030x6.h:4821
   --  unsupported macro: USART_CR2_ABREN_Msk (0x1UL << USART_CR2_ABREN_Pos)
   --  unsupported macro: USART_CR2_ABREN USART_CR2_ABREN_Msk

   USART_CR2_ABRMODE_Pos : constant := (21);  --  ../core/include/stm32f0/stm32f030x6.h:4824
   --  unsupported macro: USART_CR2_ABRMODE_Msk (0x3UL << USART_CR2_ABRMODE_Pos)
   --  unsupported macro: USART_CR2_ABRMODE USART_CR2_ABRMODE_Msk
   --  unsupported macro: USART_CR2_ABRMODE_0 (0x1UL << USART_CR2_ABRMODE_Pos)
   --  unsupported macro: USART_CR2_ABRMODE_1 (0x2UL << USART_CR2_ABRMODE_Pos)

   USART_CR2_RTOEN_Pos : constant := (23);  --  ../core/include/stm32f0/stm32f030x6.h:4829
   --  unsupported macro: USART_CR2_RTOEN_Msk (0x1UL << USART_CR2_RTOEN_Pos)
   --  unsupported macro: USART_CR2_RTOEN USART_CR2_RTOEN_Msk

   USART_CR2_ADD_Pos : constant := (24);  --  ../core/include/stm32f0/stm32f030x6.h:4832
   --  unsupported macro: USART_CR2_ADD_Msk (0xFFUL << USART_CR2_ADD_Pos)
   --  unsupported macro: USART_CR2_ADD USART_CR2_ADD_Msk

   USART_CR3_EIE_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4837
   --  unsupported macro: USART_CR3_EIE_Msk (0x1UL << USART_CR3_EIE_Pos)
   --  unsupported macro: USART_CR3_EIE USART_CR3_EIE_Msk

   USART_CR3_HDSEL_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:4840
   --  unsupported macro: USART_CR3_HDSEL_Msk (0x1UL << USART_CR3_HDSEL_Pos)
   --  unsupported macro: USART_CR3_HDSEL USART_CR3_HDSEL_Msk

   USART_CR3_DMAR_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:4843
   --  unsupported macro: USART_CR3_DMAR_Msk (0x1UL << USART_CR3_DMAR_Pos)
   --  unsupported macro: USART_CR3_DMAR USART_CR3_DMAR_Msk

   USART_CR3_DMAT_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:4846
   --  unsupported macro: USART_CR3_DMAT_Msk (0x1UL << USART_CR3_DMAT_Pos)
   --  unsupported macro: USART_CR3_DMAT USART_CR3_DMAT_Msk

   USART_CR3_RTSE_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4849
   --  unsupported macro: USART_CR3_RTSE_Msk (0x1UL << USART_CR3_RTSE_Pos)
   --  unsupported macro: USART_CR3_RTSE USART_CR3_RTSE_Msk

   USART_CR3_CTSE_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:4852
   --  unsupported macro: USART_CR3_CTSE_Msk (0x1UL << USART_CR3_CTSE_Pos)
   --  unsupported macro: USART_CR3_CTSE USART_CR3_CTSE_Msk

   USART_CR3_CTSIE_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:4855
   --  unsupported macro: USART_CR3_CTSIE_Msk (0x1UL << USART_CR3_CTSIE_Pos)
   --  unsupported macro: USART_CR3_CTSIE USART_CR3_CTSIE_Msk

   USART_CR3_ONEBIT_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:4858
   --  unsupported macro: USART_CR3_ONEBIT_Msk (0x1UL << USART_CR3_ONEBIT_Pos)
   --  unsupported macro: USART_CR3_ONEBIT USART_CR3_ONEBIT_Msk

   USART_CR3_OVRDIS_Pos : constant := (12);  --  ../core/include/stm32f0/stm32f030x6.h:4861
   --  unsupported macro: USART_CR3_OVRDIS_Msk (0x1UL << USART_CR3_OVRDIS_Pos)
   --  unsupported macro: USART_CR3_OVRDIS USART_CR3_OVRDIS_Msk

   USART_CR3_DDRE_Pos : constant := (13);  --  ../core/include/stm32f0/stm32f030x6.h:4864
   --  unsupported macro: USART_CR3_DDRE_Msk (0x1UL << USART_CR3_DDRE_Pos)
   --  unsupported macro: USART_CR3_DDRE USART_CR3_DDRE_Msk

   USART_CR3_DEM_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:4867
   --  unsupported macro: USART_CR3_DEM_Msk (0x1UL << USART_CR3_DEM_Pos)
   --  unsupported macro: USART_CR3_DEM USART_CR3_DEM_Msk

   USART_CR3_DEP_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:4870
   --  unsupported macro: USART_CR3_DEP_Msk (0x1UL << USART_CR3_DEP_Pos)
   --  unsupported macro: USART_CR3_DEP USART_CR3_DEP_Msk

   USART_BRR_DIV_FRACTION_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4875
   --  unsupported macro: USART_BRR_DIV_FRACTION_Msk (0xFUL << USART_BRR_DIV_FRACTION_Pos)
   --  unsupported macro: USART_BRR_DIV_FRACTION USART_BRR_DIV_FRACTION_Msk

   USART_BRR_DIV_MANTISSA_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4878
   --  unsupported macro: USART_BRR_DIV_MANTISSA_Msk (0xFFFUL << USART_BRR_DIV_MANTISSA_Pos)
   --  unsupported macro: USART_BRR_DIV_MANTISSA USART_BRR_DIV_MANTISSA_Msk

   USART_GTPR_PSC_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4883
   --  unsupported macro: USART_GTPR_PSC_Msk (0xFFUL << USART_GTPR_PSC_Pos)
   --  unsupported macro: USART_GTPR_PSC USART_GTPR_PSC_Msk

   USART_GTPR_GT_Pos : constant := (8);  --  ../core/include/stm32f0/stm32f030x6.h:4886
   --  unsupported macro: USART_GTPR_GT_Msk (0xFFUL << USART_GTPR_GT_Pos)
   --  unsupported macro: USART_GTPR_GT USART_GTPR_GT_Msk

   USART_RTOR_RTO_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4892
   --  unsupported macro: USART_RTOR_RTO_Msk (0xFFFFFFUL << USART_RTOR_RTO_Pos)
   --  unsupported macro: USART_RTOR_RTO USART_RTOR_RTO_Msk

   USART_RTOR_BLEN_Pos : constant := (24);  --  ../core/include/stm32f0/stm32f030x6.h:4895
   --  unsupported macro: USART_RTOR_BLEN_Msk (0xFFUL << USART_RTOR_BLEN_Pos)
   --  unsupported macro: USART_RTOR_BLEN USART_RTOR_BLEN_Msk

   USART_RQR_ABRRQ_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4900
   --  unsupported macro: USART_RQR_ABRRQ_Msk (0x1UL << USART_RQR_ABRRQ_Pos)
   --  unsupported macro: USART_RQR_ABRRQ USART_RQR_ABRRQ_Msk

   USART_RQR_SBKRQ_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:4903
   --  unsupported macro: USART_RQR_SBKRQ_Msk (0x1UL << USART_RQR_SBKRQ_Pos)
   --  unsupported macro: USART_RQR_SBKRQ USART_RQR_SBKRQ_Msk

   USART_RQR_MMRQ_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:4906
   --  unsupported macro: USART_RQR_MMRQ_Msk (0x1UL << USART_RQR_MMRQ_Pos)
   --  unsupported macro: USART_RQR_MMRQ USART_RQR_MMRQ_Msk

   USART_RQR_RXFRQ_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:4909
   --  unsupported macro: USART_RQR_RXFRQ_Msk (0x1UL << USART_RQR_RXFRQ_Pos)
   --  unsupported macro: USART_RQR_RXFRQ USART_RQR_RXFRQ_Msk

   USART_ISR_PE_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4914
   --  unsupported macro: USART_ISR_PE_Msk (0x1UL << USART_ISR_PE_Pos)
   --  unsupported macro: USART_ISR_PE USART_ISR_PE_Msk

   USART_ISR_FE_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:4917
   --  unsupported macro: USART_ISR_FE_Msk (0x1UL << USART_ISR_FE_Pos)
   --  unsupported macro: USART_ISR_FE USART_ISR_FE_Msk

   USART_ISR_NE_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:4920
   --  unsupported macro: USART_ISR_NE_Msk (0x1UL << USART_ISR_NE_Pos)
   --  unsupported macro: USART_ISR_NE USART_ISR_NE_Msk

   USART_ISR_ORE_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:4923
   --  unsupported macro: USART_ISR_ORE_Msk (0x1UL << USART_ISR_ORE_Pos)
   --  unsupported macro: USART_ISR_ORE USART_ISR_ORE_Msk

   USART_ISR_IDLE_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4926
   --  unsupported macro: USART_ISR_IDLE_Msk (0x1UL << USART_ISR_IDLE_Pos)
   --  unsupported macro: USART_ISR_IDLE USART_ISR_IDLE_Msk

   USART_ISR_RXNE_Pos : constant := (5);  --  ../core/include/stm32f0/stm32f030x6.h:4929
   --  unsupported macro: USART_ISR_RXNE_Msk (0x1UL << USART_ISR_RXNE_Pos)
   --  unsupported macro: USART_ISR_RXNE USART_ISR_RXNE_Msk

   USART_ISR_TC_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:4932
   --  unsupported macro: USART_ISR_TC_Msk (0x1UL << USART_ISR_TC_Pos)
   --  unsupported macro: USART_ISR_TC USART_ISR_TC_Msk

   USART_ISR_TXE_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:4935
   --  unsupported macro: USART_ISR_TXE_Msk (0x1UL << USART_ISR_TXE_Pos)
   --  unsupported macro: USART_ISR_TXE USART_ISR_TXE_Msk

   USART_ISR_CTSIF_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:4938
   --  unsupported macro: USART_ISR_CTSIF_Msk (0x1UL << USART_ISR_CTSIF_Pos)
   --  unsupported macro: USART_ISR_CTSIF USART_ISR_CTSIF_Msk

   USART_ISR_CTS_Pos : constant := (10);  --  ../core/include/stm32f0/stm32f030x6.h:4941
   --  unsupported macro: USART_ISR_CTS_Msk (0x1UL << USART_ISR_CTS_Pos)
   --  unsupported macro: USART_ISR_CTS USART_ISR_CTS_Msk

   USART_ISR_RTOF_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:4944
   --  unsupported macro: USART_ISR_RTOF_Msk (0x1UL << USART_ISR_RTOF_Pos)
   --  unsupported macro: USART_ISR_RTOF USART_ISR_RTOF_Msk

   USART_ISR_ABRE_Pos : constant := (14);  --  ../core/include/stm32f0/stm32f030x6.h:4947
   --  unsupported macro: USART_ISR_ABRE_Msk (0x1UL << USART_ISR_ABRE_Pos)
   --  unsupported macro: USART_ISR_ABRE USART_ISR_ABRE_Msk

   USART_ISR_ABRF_Pos : constant := (15);  --  ../core/include/stm32f0/stm32f030x6.h:4950
   --  unsupported macro: USART_ISR_ABRF_Msk (0x1UL << USART_ISR_ABRF_Pos)
   --  unsupported macro: USART_ISR_ABRF USART_ISR_ABRF_Msk

   USART_ISR_BUSY_Pos : constant := (16);  --  ../core/include/stm32f0/stm32f030x6.h:4953
   --  unsupported macro: USART_ISR_BUSY_Msk (0x1UL << USART_ISR_BUSY_Pos)
   --  unsupported macro: USART_ISR_BUSY USART_ISR_BUSY_Msk

   USART_ISR_CMF_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:4956
   --  unsupported macro: USART_ISR_CMF_Msk (0x1UL << USART_ISR_CMF_Pos)
   --  unsupported macro: USART_ISR_CMF USART_ISR_CMF_Msk

   USART_ISR_SBKF_Pos : constant := (18);  --  ../core/include/stm32f0/stm32f030x6.h:4959
   --  unsupported macro: USART_ISR_SBKF_Msk (0x1UL << USART_ISR_SBKF_Pos)
   --  unsupported macro: USART_ISR_SBKF USART_ISR_SBKF_Msk

   USART_ISR_RWU_Pos : constant := (19);  --  ../core/include/stm32f0/stm32f030x6.h:4962
   --  unsupported macro: USART_ISR_RWU_Msk (0x1UL << USART_ISR_RWU_Pos)
   --  unsupported macro: USART_ISR_RWU USART_ISR_RWU_Msk

   USART_ISR_TEACK_Pos : constant := (21);  --  ../core/include/stm32f0/stm32f030x6.h:4965
   --  unsupported macro: USART_ISR_TEACK_Msk (0x1UL << USART_ISR_TEACK_Pos)
   --  unsupported macro: USART_ISR_TEACK USART_ISR_TEACK_Msk

   USART_ISR_REACK_Pos : constant := (22);  --  ../core/include/stm32f0/stm32f030x6.h:4968
   --  unsupported macro: USART_ISR_REACK_Msk (0x1UL << USART_ISR_REACK_Pos)
   --  unsupported macro: USART_ISR_REACK USART_ISR_REACK_Msk

   USART_ICR_PECF_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:4973
   --  unsupported macro: USART_ICR_PECF_Msk (0x1UL << USART_ICR_PECF_Pos)
   --  unsupported macro: USART_ICR_PECF USART_ICR_PECF_Msk

   USART_ICR_FECF_Pos : constant := (1);  --  ../core/include/stm32f0/stm32f030x6.h:4976
   --  unsupported macro: USART_ICR_FECF_Msk (0x1UL << USART_ICR_FECF_Pos)
   --  unsupported macro: USART_ICR_FECF USART_ICR_FECF_Msk

   USART_ICR_NCF_Pos : constant := (2);  --  ../core/include/stm32f0/stm32f030x6.h:4979
   --  unsupported macro: USART_ICR_NCF_Msk (0x1UL << USART_ICR_NCF_Pos)
   --  unsupported macro: USART_ICR_NCF USART_ICR_NCF_Msk

   USART_ICR_ORECF_Pos : constant := (3);  --  ../core/include/stm32f0/stm32f030x6.h:4982
   --  unsupported macro: USART_ICR_ORECF_Msk (0x1UL << USART_ICR_ORECF_Pos)
   --  unsupported macro: USART_ICR_ORECF USART_ICR_ORECF_Msk

   USART_ICR_IDLECF_Pos : constant := (4);  --  ../core/include/stm32f0/stm32f030x6.h:4985
   --  unsupported macro: USART_ICR_IDLECF_Msk (0x1UL << USART_ICR_IDLECF_Pos)
   --  unsupported macro: USART_ICR_IDLECF USART_ICR_IDLECF_Msk

   USART_ICR_TCCF_Pos : constant := (6);  --  ../core/include/stm32f0/stm32f030x6.h:4988
   --  unsupported macro: USART_ICR_TCCF_Msk (0x1UL << USART_ICR_TCCF_Pos)
   --  unsupported macro: USART_ICR_TCCF USART_ICR_TCCF_Msk

   USART_ICR_CTSCF_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:4991
   --  unsupported macro: USART_ICR_CTSCF_Msk (0x1UL << USART_ICR_CTSCF_Pos)
   --  unsupported macro: USART_ICR_CTSCF USART_ICR_CTSCF_Msk

   USART_ICR_RTOCF_Pos : constant := (11);  --  ../core/include/stm32f0/stm32f030x6.h:4994
   --  unsupported macro: USART_ICR_RTOCF_Msk (0x1UL << USART_ICR_RTOCF_Pos)
   --  unsupported macro: USART_ICR_RTOCF USART_ICR_RTOCF_Msk

   USART_ICR_CMCF_Pos : constant := (17);  --  ../core/include/stm32f0/stm32f030x6.h:4997
   --  unsupported macro: USART_ICR_CMCF_Msk (0x1UL << USART_ICR_CMCF_Pos)
   --  unsupported macro: USART_ICR_CMCF USART_ICR_CMCF_Msk
   --  unsupported macro: USART_RDR_RDR ((uint16_t)0x01FFU)
   --  unsupported macro: USART_TDR_TDR ((uint16_t)0x01FFU)

   WWDG_CR_T_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:5014
   --  unsupported macro: WWDG_CR_T_Msk (0x7FUL << WWDG_CR_T_Pos)
   --  unsupported macro: WWDG_CR_T WWDG_CR_T_Msk
   --  unsupported macro: WWDG_CR_T_0 (0x01UL << WWDG_CR_T_Pos)
   --  unsupported macro: WWDG_CR_T_1 (0x02UL << WWDG_CR_T_Pos)
   --  unsupported macro: WWDG_CR_T_2 (0x04UL << WWDG_CR_T_Pos)
   --  unsupported macro: WWDG_CR_T_3 (0x08UL << WWDG_CR_T_Pos)
   --  unsupported macro: WWDG_CR_T_4 (0x10UL << WWDG_CR_T_Pos)
   --  unsupported macro: WWDG_CR_T_5 (0x20UL << WWDG_CR_T_Pos)
   --  unsupported macro: WWDG_CR_T_6 (0x40UL << WWDG_CR_T_Pos)
   --  unsupported macro: WWDG_CR_T0 WWDG_CR_T_0
   --  unsupported macro: WWDG_CR_T1 WWDG_CR_T_1
   --  unsupported macro: WWDG_CR_T2 WWDG_CR_T_2
   --  unsupported macro: WWDG_CR_T3 WWDG_CR_T_3
   --  unsupported macro: WWDG_CR_T4 WWDG_CR_T_4
   --  unsupported macro: WWDG_CR_T5 WWDG_CR_T_5
   --  unsupported macro: WWDG_CR_T6 WWDG_CR_T_6

   WWDG_CR_WDGA_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:5034
   --  unsupported macro: WWDG_CR_WDGA_Msk (0x1UL << WWDG_CR_WDGA_Pos)
   --  unsupported macro: WWDG_CR_WDGA WWDG_CR_WDGA_Msk

   WWDG_CFR_W_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:5039
   --  unsupported macro: WWDG_CFR_W_Msk (0x7FUL << WWDG_CFR_W_Pos)
   --  unsupported macro: WWDG_CFR_W WWDG_CFR_W_Msk
   --  unsupported macro: WWDG_CFR_W_0 (0x01UL << WWDG_CFR_W_Pos)
   --  unsupported macro: WWDG_CFR_W_1 (0x02UL << WWDG_CFR_W_Pos)
   --  unsupported macro: WWDG_CFR_W_2 (0x04UL << WWDG_CFR_W_Pos)
   --  unsupported macro: WWDG_CFR_W_3 (0x08UL << WWDG_CFR_W_Pos)
   --  unsupported macro: WWDG_CFR_W_4 (0x10UL << WWDG_CFR_W_Pos)
   --  unsupported macro: WWDG_CFR_W_5 (0x20UL << WWDG_CFR_W_Pos)
   --  unsupported macro: WWDG_CFR_W_6 (0x40UL << WWDG_CFR_W_Pos)
   --  unsupported macro: WWDG_CFR_W0 WWDG_CFR_W_0
   --  unsupported macro: WWDG_CFR_W1 WWDG_CFR_W_1
   --  unsupported macro: WWDG_CFR_W2 WWDG_CFR_W_2
   --  unsupported macro: WWDG_CFR_W3 WWDG_CFR_W_3
   --  unsupported macro: WWDG_CFR_W4 WWDG_CFR_W_4
   --  unsupported macro: WWDG_CFR_W5 WWDG_CFR_W_5
   --  unsupported macro: WWDG_CFR_W6 WWDG_CFR_W_6

   WWDG_CFR_WDGTB_Pos : constant := (7);  --  ../core/include/stm32f0/stm32f030x6.h:5059
   --  unsupported macro: WWDG_CFR_WDGTB_Msk (0x3UL << WWDG_CFR_WDGTB_Pos)
   --  unsupported macro: WWDG_CFR_WDGTB WWDG_CFR_WDGTB_Msk
   --  unsupported macro: WWDG_CFR_WDGTB_0 (0x1UL << WWDG_CFR_WDGTB_Pos)
   --  unsupported macro: WWDG_CFR_WDGTB_1 (0x2UL << WWDG_CFR_WDGTB_Pos)
   --  unsupported macro: WWDG_CFR_WDGTB0 WWDG_CFR_WDGTB_0
   --  unsupported macro: WWDG_CFR_WDGTB1 WWDG_CFR_WDGTB_1

   WWDG_CFR_EWI_Pos : constant := (9);  --  ../core/include/stm32f0/stm32f030x6.h:5069
   --  unsupported macro: WWDG_CFR_EWI_Msk (0x1UL << WWDG_CFR_EWI_Pos)
   --  unsupported macro: WWDG_CFR_EWI WWDG_CFR_EWI_Msk

   WWDG_SR_EWIF_Pos : constant := (0);  --  ../core/include/stm32f0/stm32f030x6.h:5074
   --  unsupported macro: WWDG_SR_EWIF_Msk (0x1UL << WWDG_SR_EWIF_Pos)
   --  unsupported macro: WWDG_SR_EWIF WWDG_SR_EWIF_Msk
   --  arg-macro: function IS_ADC_ALL_INSTANCE (INSTANCE)
   --    return (INSTANCE) = ADC1;
   --  arg-macro: function IS_ADC_COMMON_INSTANCE (INSTANCE)
   --    return (INSTANCE) = ADC;
   --  arg-macro: function IS_CRC_ALL_INSTANCE (INSTANCE)
   --    return (INSTANCE) = CRC;
   --  arg-macro: function IS_DMA_ALL_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = DMA1_Channel1)  or else  ((INSTANCE) = DMA1_Channel2)  or else  ((INSTANCE) = DMA1_Channel3)  or else  ((INSTANCE) = DMA1_Channel4)  or else  ((INSTANCE) = DMA1_Channel5);
   --  arg-macro: function IS_GPIO_ALL_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = GPIOA)  or else  ((INSTANCE) = GPIOB)  or else  ((INSTANCE) = GPIOC)  or else  ((INSTANCE) = GPIOD)  or else  ((INSTANCE) = GPIOF);
   --  arg-macro: function IS_GPIO_AF_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = GPIOA)  or else  ((INSTANCE) = GPIOB)  or else  ((INSTANCE) = GPIOF);
   --  arg-macro: function IS_GPIO_LOCK_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = GPIOA)  or else  ((INSTANCE) = GPIOB);
   --  arg-macro: function IS_I2C_ALL_INSTANCE (INSTANCE)
   --    return (INSTANCE) = I2C1;
   --  arg-macro: function IS_IWDG_ALL_INSTANCE (INSTANCE)
   --    return (INSTANCE) = IWDG;
   --  arg-macro: function IS_RTC_ALL_INSTANCE (INSTANCE)
   --    return (INSTANCE) = RTC;
   --  arg-macro: function IS_SMBUS_ALL_INSTANCE (INSTANCE)
   --    return (INSTANCE) = I2C1;
   --  arg-macro: function IS_SPI_ALL_INSTANCE (INSTANCE)
   --    return (INSTANCE) = SPI1;
   --  arg-macro: function IS_TIM_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3)  or else  ((INSTANCE) = TIM14)  or else  ((INSTANCE) = TIM16)  or else  ((INSTANCE) = TIM17);
   --  arg-macro: function IS_TIM_CC1_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3)  or else  ((INSTANCE) = TIM14)  or else  ((INSTANCE) = TIM16)  or else  ((INSTANCE) = TIM17);
   --  arg-macro: function IS_TIM_CC2_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3);
   --  arg-macro: function IS_TIM_CC3_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3);
   --  arg-macro: function IS_TIM_CC4_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3);
   --  arg-macro: function IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3);
   --  arg-macro: function IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3);
   --  arg-macro: function IS_TIM_CLOCKSOURCE_TIX_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3);
   --  arg-macro: function IS_TIM_CLOCKSOURCE_ITRX_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3);
   --  arg-macro: function IS_TIM_OCXREF_CLEAR_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3);
   --  arg-macro: function IS_TIM_ENCODER_INTERFACE_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3);
   --  arg-macro: function IS_TIM_HALL_INTERFACE_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1);
   --  arg-macro: function IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1);
   --  arg-macro: function IS_TIM_XOR_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3);
   --  arg-macro: function IS_TIM_MASTER_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3);
   --  arg-macro: function IS_TIM_SLAVE_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3);
   --  arg-macro: function IS_TIM_32B_COUNTER_INSTANCE (INSTANCE)
   --    return 0;
   --  arg-macro: function IS_TIM_DMABURST_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3)  or else  ((INSTANCE) = TIM16)  or else  ((INSTANCE) = TIM17);
   --  arg-macro: function IS_TIM_BREAK_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM16)  or else  ((INSTANCE) = TIM17);
   --  arg-macro: function IS_TIM_CCX_INSTANCE (INSTANCE, CHANNEL)
   --    return (((INSTANCE) = TIM1)  and then  (((CHANNEL) = TIM_CHANNEL_1)  or else  ((CHANNEL) = TIM_CHANNEL_2)  or else  ((CHANNEL) = TIM_CHANNEL_3)  or else  ((CHANNEL) = TIM_CHANNEL_4)))  or else  (((INSTANCE) = TIM3)  and then  (((CHANNEL) = TIM_CHANNEL_1)  or else  ((CHANNEL) = TIM_CHANNEL_2)  or else  ((CHANNEL) = TIM_CHANNEL_3)  or else  ((CHANNEL) = TIM_CHANNEL_4)))  or else  (((INSTANCE) = TIM14)  and then  (((CHANNEL) = TIM_CHANNEL_1)))  or else  (((INSTANCE) = TIM16)  and then  (((CHANNEL) = TIM_CHANNEL_1)))  or else  (((INSTANCE) = TIM17)  and then  (((CHANNEL) = TIM_CHANNEL_1)));
   --  arg-macro: function IS_TIM_CCXN_INSTANCE (INSTANCE, CHANNEL)
   --    return (((INSTANCE) = TIM1)  and then  (((CHANNEL) = TIM_CHANNEL_1)  or else  ((CHANNEL) = TIM_CHANNEL_2)  or else  ((CHANNEL) = TIM_CHANNEL_3)))  or else  (((INSTANCE) = TIM16)  and then  ((CHANNEL) = TIM_CHANNEL_1))  or else  (((INSTANCE) = TIM17)  and then  ((CHANNEL) = TIM_CHANNEL_1));
   --  arg-macro: function IS_TIM_COUNTER_MODE_SELECT_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3);
   --  arg-macro: function IS_TIM_REPETITION_COUNTER_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM16)  or else  ((INSTANCE) = TIM17);
   --  arg-macro: function IS_TIM_CLOCK_DIVISION_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3)  or else  ((INSTANCE) = TIM14)  or else  ((INSTANCE) = TIM16)  or else  ((INSTANCE) = TIM17);
   --  arg-macro: function IS_TIM_DMA_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3)  or else  ((INSTANCE) = TIM16)  or else  ((INSTANCE) = TIM17);
   --  arg-macro: function IS_TIM_DMA_CC_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM3)  or else  ((INSTANCE) = TIM16)  or else  ((INSTANCE) = TIM17);
   --  arg-macro: function IS_TIM_COMMUTATION_EVENT_INSTANCE (INSTANCE)
   --    return ((INSTANCE) = TIM1)  or else  ((INSTANCE) = TIM16)  or else  ((INSTANCE) = TIM17);
   --  arg-macro: function IS_TIM_REMAP_INSTANCE (INSTANCE)
   --    return (INSTANCE) = TIM14;
   --  arg-macro: function IS_TIM_ADVANCED_INSTANCE (INSTANCE)
   --    return (INSTANCE) = TIM1;
   --  arg-macro: function IS_USART_INSTANCE (INSTANCE)
   --    return (INSTANCE) = USART1;
   --  arg-macro: function IS_USART_AUTOBAUDRATE_DETECTION_INSTANCE (INSTANCE)
   --    return (INSTANCE) = USART1;
   --  arg-macro: function IS_UART_INSTANCE (INSTANCE)
   --    return (INSTANCE) = USART1;
   --  arg-macro: function IS_UART_HALFDUPLEX_INSTANCE (INSTANCE)
   --    return (INSTANCE) = USART1;
   --  arg-macro: function IS_UART_HWFLOW_INSTANCE (INSTANCE)
   --    return (INSTANCE) = USART1;
   --  arg-macro: function IS_UART_DRIVER_ENABLE_INSTANCE (INSTANCE)
   --    return (INSTANCE) = USART1;
   --  arg-macro: function IS_WWDG_ALL_INSTANCE (INSTANCE)
   --    return (INSTANCE) = WWDG;
   --  unsupported macro: ADC1_COMP_IRQn ADC1_IRQn
   --  unsupported macro: DMA1_Ch1_IRQn DMA1_Channel1_IRQn
   --  unsupported macro: DMA1_Ch2_3_DMA2_Ch1_2_IRQn DMA1_Channel2_3_IRQn
   --  unsupported macro: DMA1_Channel4_5_6_7_IRQn DMA1_Channel4_5_IRQn
   --  unsupported macro: DMA1_Ch4_7_DMA2_Ch3_5_IRQn DMA1_Channel4_5_IRQn
   --  unsupported macro: RCC_CRS_IRQn RCC_IRQn
   --  unsupported macro: ADC1_COMP_IRQHandler ADC1_IRQHandler
   --  unsupported macro: DMA1_Ch1_IRQHandler DMA1_Channel1_IRQHandler
   --  unsupported macro: DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler DMA1_Channel2_3_IRQHandler
   --  unsupported macro: DMA1_Channel4_5_6_7_IRQHandler DMA1_Channel4_5_IRQHandler
   --  unsupported macro: DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler DMA1_Channel4_5_IRQHandler
   --  unsupported macro: RCC_CRS_IRQHandler RCC_IRQHandler

   subtype IRQn_Type is int;
   NonMaskableInt_IRQn : constant int := -14;
   HardFault_IRQn : constant int := -13;
   SVC_IRQn : constant int := -5;
   PendSV_IRQn : constant int := -2;
   SysTick_IRQn : constant int := -1;
   WWDG_IRQn : constant int := 0;
   RTC_IRQn : constant int := 2;
   FLASH_IRQn : constant int := 3;
   RCC_IRQn : constant int := 4;
   EXTI0_1_IRQn : constant int := 5;
   EXTI2_3_IRQn : constant int := 6;
   EXTI4_15_IRQn : constant int := 7;
   DMA1_Channel1_IRQn : constant int := 9;
   DMA1_Channel2_3_IRQn : constant int := 10;
   DMA1_Channel4_5_IRQn : constant int := 11;
   ADC1_IRQn : constant int := 12;
   TIM1_BRK_UP_TRG_COM_IRQn : constant int := 13;
   TIM1_CC_IRQn : constant int := 14;
   TIM3_IRQn : constant int := 16;
   TIM14_IRQn : constant int := 19;
   TIM16_IRQn : constant int := 21;
   TIM17_IRQn : constant int := 22;
   I2C1_IRQn : constant int := 23;
   SPI1_IRQn : constant int := 25;
   USART1_IRQn : constant int := 27;  -- ../core/include/stm32f0/stm32f030x6.h:98

   --  skipped anonymous struct anon_anon_14

   type ADC_TypeDef_array1070 is array (0 .. 4) of aliased stdint_h.uint32_t;
   type ADC_TypeDef is record
      ISR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:118
      IER : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:119
      CR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:120
      CFGR1 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:121
      CFGR2 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:122
      SMPR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:123
      RESERVED1 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:124
      RESERVED2 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:125
      TR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:126
      RESERVED3 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:127
      CHSELR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:128
      RESERVED4 : aliased ADC_TypeDef_array1070;  -- ../core/include/stm32f0/stm32f030x6.h:129
      DR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:130
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:131

   --  skipped anonymous struct anon_anon_15

   type ADC_Common_TypeDef is record
      CCR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:135
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:136

   --  skipped anonymous struct anon_anon_16

   type CRC_TypeDef is record
      DR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:144
      IDR : aliased stdint_h.uint8_t;  -- ../core/include/stm32f0/stm32f030x6.h:145
      RESERVED0 : aliased stdint_h.uint8_t;  -- ../core/include/stm32f0/stm32f030x6.h:146
      RESERVED1 : aliased stdint_h.uint16_t;  -- ../core/include/stm32f0/stm32f030x6.h:147
      CR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:148
      RESERVED2 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:149
      INIT : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:150
      RESERVED3 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:151
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:152

   --  skipped anonymous struct anon_anon_17

   type DBGMCU_TypeDef is record
      IDCODE : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:160
      CR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:161
      APB1FZ : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:162
      APB2FZ : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:163
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:164

   --  skipped anonymous struct anon_anon_18

   type DMA_Channel_TypeDef is record
      CCR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:172
      CNDTR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:173
      CPAR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:174
      CMAR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:175
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:176

   --  skipped anonymous struct anon_anon_19

   type DMA_TypeDef is record
      ISR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:180
      IFCR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:181
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:182

   --  skipped anonymous struct anon_anon_20

   type EXTI_TypeDef is record
      IMR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:190
      EMR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:191
      RTSR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:192
      FTSR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:193
      SWIER : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:194
      PR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:195
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:196

   --  skipped anonymous struct anon_anon_21

   type FLASH_TypeDef is record
      ACR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:203
      KEYR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:204
      OPTKEYR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:205
      SR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:206
      CR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:207
      AR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:208
      RESERVED : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:209
      OBR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:210
      WRPR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:211
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:212

   --  skipped anonymous struct anon_anon_22

   type OB_TypeDef is record
      RDP : aliased stdint_h.uint16_t;  -- ../core/include/stm32f0/stm32f030x6.h:219
      USER : aliased stdint_h.uint16_t;  -- ../core/include/stm32f0/stm32f030x6.h:220
      DATA0 : aliased stdint_h.uint16_t;  -- ../core/include/stm32f0/stm32f030x6.h:221
      DATA1 : aliased stdint_h.uint16_t;  -- ../core/include/stm32f0/stm32f030x6.h:222
      WRP0 : aliased stdint_h.uint16_t;  -- ../core/include/stm32f0/stm32f030x6.h:223
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:224

   --  skipped anonymous struct anon_anon_23

   type GPIO_TypeDef_array1045 is array (0 .. 1) of aliased stdint_h.uint32_t;
   type GPIO_TypeDef is record
      MODER : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:232
      OTYPER : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:233
      OSPEEDR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:234
      PUPDR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:235
      IDR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:236
      ODR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:237
      BSRR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:238
      LCKR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:239
      AFR : aliased GPIO_TypeDef_array1045;  -- ../core/include/stm32f0/stm32f030x6.h:240
      BRR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:241
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:242

   --  skipped anonymous struct anon_anon_24

   type SYSCFG_TypeDef_array1096 is array (0 .. 3) of aliased stdint_h.uint32_t;
   type SYSCFG_TypeDef is record
      CFGR1 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:250
      RESERVED : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:251
      EXTICR : aliased SYSCFG_TypeDef_array1096;  -- ../core/include/stm32f0/stm32f030x6.h:252
      CFGR2 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:253
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:254

   --  skipped anonymous struct anon_anon_25

   type I2C_TypeDef is record
      CR1 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:262
      CR2 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:263
      OAR1 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:264
      OAR2 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:265
      TIMINGR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:266
      TIMEOUTR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:267
      ISR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:268
      ICR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:269
      PECR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:270
      RXDR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:271
      TXDR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:272
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:273

   --  skipped anonymous struct anon_anon_26

   type IWDG_TypeDef is record
      KR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:281
      PR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:282
      RLR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:283
      SR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:284
      WINR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:285
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:286

   --  skipped anonymous struct anon_anon_27

   type PWR_TypeDef is record
      CR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:294
      CSR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:295
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:296

   --  skipped anonymous struct anon_anon_28

   type RCC_TypeDef is record
      CR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:304
      CFGR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:305
      CIR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:306
      APB2RSTR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:307
      APB1RSTR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:308
      AHBENR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:309
      APB2ENR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:310
      APB1ENR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:311
      BDCR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:312
      CSR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:313
      AHBRSTR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:314
      CFGR2 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:315
      CFGR3 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:316
      CR2 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:317
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:318

   --  skipped anonymous struct anon_anon_29

   type RTC_TypeDef is record
      TR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:325
      DR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:326
      CR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:327
      ISR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:328
      PRER : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:329
      RESERVED1 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:330
      RESERVED2 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:331
      ALRMAR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:332
      RESERVED3 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:333
      WPR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:334
      SSR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:335
      SHIFTR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:336
      TSTR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:337
      TSDR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:338
      TSSSR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:339
      CALR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:340
      TAFCR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:341
      ALRMASSR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:342
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:343

   --  skipped anonymous struct anon_anon_30

   type SPI_TypeDef is record
      CR1 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:351
      CR2 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:352
      SR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:353
      DR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:354
      CRCPR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:355
      RXCRCR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:356
      TXCRCR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:357
      I2SCFGR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:358
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:359

   --  skipped anonymous struct anon_anon_31

   type TIM_TypeDef is record
      CR1 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:366
      CR2 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:367
      SMCR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:368
      DIER : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:369
      SR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:370
      EGR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:371
      CCMR1 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:372
      CCMR2 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:373
      CCER : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:374
      CNT : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:375
      PSC : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:376
      ARR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:377
      RCR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:378
      CCR1 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:379
      CCR2 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:380
      CCR3 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:381
      CCR4 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:382
      BDTR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:383
      DCR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:384
      DMAR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:385
      c_OR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:386
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:387

   --  skipped anonymous struct anon_anon_32

   type USART_TypeDef is record
      CR1 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:395
      CR2 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:396
      CR3 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:397
      BRR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:398
      GTPR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:399
      RTOR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:400
      RQR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:401
      ISR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:402
      ICR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:403
      RDR : aliased stdint_h.uint16_t;  -- ../core/include/stm32f0/stm32f030x6.h:404
      RESERVED1 : aliased stdint_h.uint16_t;  -- ../core/include/stm32f0/stm32f030x6.h:405
      TDR : aliased stdint_h.uint16_t;  -- ../core/include/stm32f0/stm32f030x6.h:406
      RESERVED2 : aliased stdint_h.uint16_t;  -- ../core/include/stm32f0/stm32f030x6.h:407
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:408

   --  skipped anonymous struct anon_anon_33

   type WWDG_TypeDef is record
      CR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:415
      CFR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:416
      SR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:417
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/stm32f030x6.h:418

end stm32f0_stm32f030x6_h;
