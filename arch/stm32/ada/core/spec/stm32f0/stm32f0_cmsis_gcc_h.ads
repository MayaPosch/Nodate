pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with stdint_h;

package stm32f0_cmsis_gcc_h is

   pragma Compile_Time_Warning (True, "probably incorrect record layout");
   type T_UINT32 is record
      v : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/cmsis_gcc.h:74
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/cmsis_gcc.h:74

   pragma Compile_Time_Warning (True, "probably incorrect record layout");
   type T_UINT16_WRITE is record
      v : aliased stdint_h.uint16_t;  -- ../core/include/stm32f0/cmsis_gcc.h:82
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/cmsis_gcc.h:82

   pragma Compile_Time_Warning (True, "probably incorrect record layout");
   type T_UINT16_READ is record
      v : aliased stdint_h.uint16_t;  -- ../core/include/stm32f0/cmsis_gcc.h:90
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/cmsis_gcc.h:90

   pragma Compile_Time_Warning (True, "probably incorrect record layout");
   type T_UINT32_WRITE is record
      v : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/cmsis_gcc.h:98
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/cmsis_gcc.h:98

   pragma Compile_Time_Warning (True, "probably incorrect record layout");
   type T_UINT32_READ is record
      v : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/cmsis_gcc.h:106
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/cmsis_gcc.h:106

   --  skipped func __enable_irq

   --  skipped func __disable_irq

   --  skipped func __get_CONTROL

   --  skipped func __set_CONTROL

   --  skipped func __get_IPSR

   --  skipped func __get_APSR

   --  skipped func __get_xPSR

   --  skipped func __get_PSP

   --  skipped func __set_PSP

   --  skipped func __get_MSP

   --  skipped func __set_MSP

   --  skipped func __get_PRIMASK

   --  skipped func __set_PRIMASK

   --  skipped func __get_FPSCR

   --  skipped func __set_FPSCR

   --  skipped func __ISB

   --  skipped func __DSB

   --  skipped func __DMB

   --  skipped func __REV

   --  skipped func __REV16

   --  skipped func __REVSH

   --  skipped func __ROR

   --  skipped func __RBIT

   --  skipped func __SSAT

   --  skipped func __USAT

end stm32f0_cmsis_gcc_h;
