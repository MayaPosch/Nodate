pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with stdint_h;
with Interfaces.C.Extensions;

package stm32 is

   type RccPeripheral is 
     (RCC_TSC,
      RCC_CRC,
      RCC_FLITF,
      RCC_SRAM,
      RCC_DMA2,
      RCC_DMA,
      RCC_SYSCFGCOMP,
      RCC_USART6,
      RCC_USART7,
      RCC_USART8,
      RCC_ADC,
      RCC_TIM1,
      RCC_SPI1,
      RCC_USART1,
      RCC_TIM15,
      RCC_TIM16,
      RCC_TIM17,
      RCC_DBGMCU,
      RCC_TIM2,
      RCC_TIM3,
      RCC_TIM6,
      RCC_TIM7,
      RCC_TIM14,
      RCC_WWDG,
      RCC_SPI2,
      RCC_USART2,
      RCC_USART3,
      RCC_USART4,
      RCC_USART5,
      RCC_I2C1,
      RCC_I2C2,
      RCC_USB,
      RCC_CAN,
      RCC_CRS,
      RCC_PWR,
      RCC_DAC,
      RCC_CEC)
   with Convention => C;  -- stm32f042x6.h:5

  -- AHB peripherals
  -- APB2 peripherals
  -- APB1 peripherals
   package Class_RccPeripheralHandle is
      type RccPeripheralHandle is limited record
         count : aliased stdint_h.uint8_t;  -- stm32f042x6.h:47
         exists : aliased Extensions.bool;  -- stm32f042x6.h:48
         enr : access stdint_h.uint32_t;  -- stm32f042x6.h:49
         enable : aliased stdint_h.uint32_t;  -- stm32f042x6.h:50
      end record
      with Import => True,
           Convention => CPP;
   end;
   use Class_RccPeripheralHandle;
   type RccPort is 
     (RCC_PORT_A,
      RCC_PORT_B,
      RCC_PORT_C,
      RCC_PORT_D,
      RCC_PORT_E,
      RCC_PORT_F,
      RCC_PORT_G,
      RCC_PORT_H,
      RCC_PORT_I,
      RCC_PORT_J,
      RCC_PORT_K)
   with Convention => C;  -- stm32f042x6.h:54

   package Class_RccPortHandle is
      type RccPortHandle is limited record
         count : aliased stdint_h.uint8_t;  -- stm32f042x6.h:70
         exists : aliased Extensions.bool;  -- stm32f042x6.h:71
         enr : access stdint_h.uint32_t;  -- stm32f042x6.h:72
         enable : aliased stdint_h.uint32_t;  -- stm32f042x6.h:73
      end record
      with Import => True,
           Convention => CPP;
   end;
   use Class_RccPortHandle;
   function portHandles return access RccPortHandle  -- stm32f042x6.h:77
   with Import => True, 
        Convention => CPP, 
        External_Name => "_Z11portHandlesv";

   function peripheralHandles return access RccPeripheralHandle  -- stm32f042x6.h:78
   with Import => True, 
        Convention => CPP, 
        External_Name => "_Z17peripheralHandlesv";

   portHandlesStatic : access RccPortHandle  -- stm32f042x6.h:80
   with Import => True, 
        Convention => C, 
        External_Name => "portHandlesStatic";

   perHandlesStatic : access RccPeripheralHandle  -- stm32f042x6.h:81
   with Import => True, 
        Convention => C, 
        External_Name => "perHandlesStatic";

end stm32f042x6_h;
