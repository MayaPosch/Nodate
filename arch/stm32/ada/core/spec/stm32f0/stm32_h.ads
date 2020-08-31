pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with stdint_h;
with Interfaces.C.Extensions;
with stm32f0_stm32f030x6_h; use stm32f0_stm32f030x6_h;

package stm32_h is

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
   with Convention => C;  -- stm32.h:9

   package Class_RccPeripheralHandle is
      type RccPeripheralHandle is record
         count : aliased stdint_h.uint8_t;  -- stm32.h:51
         exists : aliased Boolean;  -- stm32.h:52
         enr : access stdint_h.uint32_t;  -- stm32.h:53
         enable : aliased stdint_h.uint32_t;  -- stm32.h:54
      end record
	  with Convention => C;
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
   with Convention => C;  -- stm32.h:58

   package Class_RccPortHandle is
      type RccPortHandle is record
         count : aliased stdint_h.uint8_t;  -- stm32.h:74
         exists : aliased Boolean;  -- stm32.h:75
         enr : access stdint_h.uint32_t;  -- stm32.h:76
         enable : aliased stdint_h.uint32_t;  -- stm32.h:77
      end record
	  with Convention => C;
   end;
   use Class_RccPortHandle;

   portHandlesStatic : access RccPortHandle  -- stm32.h:84
   with Import => True, 
        Convention => C, 
        External_Name => "portHandlesStatic";

   perHandlesStatic : access RccPeripheralHandle  -- stm32.h:85
   with Import => True, 
        Convention => C, 
        External_Name => "perHandlesStatic";


-- GPIO

   type GPIO_mode is 
     (GPIO_INPUT,
      GPIO_OUTPUT,
      GPIO_ALTERNATE,
      GPIO_ANALOG)
   with Convention => C;  -- stm32.h:90

   type GPIO_pupd is 
     (GPIO_FLOATING,
      GPIO_PULL_UP,
      GPIO_PULL_DOWN)
   with Convention => C;  -- stm32.h:98

   type GPIO_out_speed is 
     (GPIO_LOW,
      GPIO_MID,
      GPIO_HIGH)
   with Convention => C;  -- stm32.h:105

   type GPIO_out_type is 
     (GPIO_PUSH_PULL,
      GPIO_OPEN_DRAIN)
   with Convention => C;  -- stm32.h:112

   type GPIO_level is 
     (GPIO_LEVEL_UNKNOWN,
      GPIO_LEVEL_LOW,
      GPIO_LEVEL_HIGH)
   with Convention => C;  -- stm32.h:118

   type GPIO_ports is 
     (GPIO_PORT_A,
      GPIO_PORT_B,
      GPIO_PORT_C,
      GPIO_PORT_D,
      GPIO_PORT_E,
      GPIO_PORT_F,
      GPIO_PORT_G,
      GPIO_PORT_H,
      GPIO_PORT_I,
      GPIO_PORT_J,
      GPIO_PORT_K,
      GPIO_PORT_L)
   with Convention => C;  -- stm32.h:125

   package Class_GPIO_instance is
      type GPIO_instance is record
         active : aliased Boolean;  -- stm32.h:142
         regs : access GPIO_TypeDef;  -- stm32.h:143
      end record
	  with Convention => C;
   end;
   use Class_GPIO_instance;

   instancesStatic : access GPIO_instance  -- stm32.h:149
   with Import => True, 
        Convention => C, 
        External_Name => "instancesStatic";

end stm32_h;
