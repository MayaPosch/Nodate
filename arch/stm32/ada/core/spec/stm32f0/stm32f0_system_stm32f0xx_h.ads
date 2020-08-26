pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with stdint_h;

package stm32f0_system_stm32f0xx_h is

   SystemCoreClock : aliased stdint_h.uint32_t  -- ../core/include/stm32f0/system_stm32f0xx.h:58
   with Import => True, 
        Convention => C, 
        External_Name => "SystemCoreClock";

   procedure SystemInit  -- ../core/include/stm32f0/system_stm32f0xx.h:86
   with Import => True, 
        Convention => C, 
        External_Name => "SystemInit";

   procedure SystemCoreClockUpdate  -- ../core/include/stm32f0/system_stm32f0xx.h:87
   with Import => True, 
        Convention => C, 
        External_Name => "SystemCoreClockUpdate";

end stm32f0_system_stm32f0xx_h;
