pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with Interfaces.C.Extensions;
with stdint_h;

package stm32f0_core_cm0_h is

   APSR_N_Pos : constant := 31;  --  ../core/include/stm32f0/core_cm0.h:213
   --  unsupported macro: APSR_N_Msk (1UL << APSR_N_Pos)

   APSR_Z_Pos : constant := 30;  --  ../core/include/stm32f0/core_cm0.h:216
   --  unsupported macro: APSR_Z_Msk (1UL << APSR_Z_Pos)

   APSR_C_Pos : constant := 29;  --  ../core/include/stm32f0/core_cm0.h:219
   --  unsupported macro: APSR_C_Msk (1UL << APSR_C_Pos)

   APSR_V_Pos : constant := 28;  --  ../core/include/stm32f0/core_cm0.h:222
   --  unsupported macro: APSR_V_Msk (1UL << APSR_V_Pos)

   IPSR_ISR_Pos : constant := 0;  --  ../core/include/stm32f0/core_cm0.h:240
   IPSR_ISR_Msk : constant := (16#1FF# );  --  ../core/include/stm32f0/core_cm0.h:241

   xPSR_N_Pos : constant := 31;  --  ../core/include/stm32f0/core_cm0.h:264
   --  unsupported macro: xPSR_N_Msk (1UL << xPSR_N_Pos)

   xPSR_Z_Pos : constant := 30;  --  ../core/include/stm32f0/core_cm0.h:267
   --  unsupported macro: xPSR_Z_Msk (1UL << xPSR_Z_Pos)

   xPSR_C_Pos : constant := 29;  --  ../core/include/stm32f0/core_cm0.h:270
   --  unsupported macro: xPSR_C_Msk (1UL << xPSR_C_Pos)

   xPSR_V_Pos : constant := 28;  --  ../core/include/stm32f0/core_cm0.h:273
   --  unsupported macro: xPSR_V_Msk (1UL << xPSR_V_Pos)

   xPSR_T_Pos : constant := 24;  --  ../core/include/stm32f0/core_cm0.h:276
   --  unsupported macro: xPSR_T_Msk (1UL << xPSR_T_Pos)

   xPSR_ISR_Pos : constant := 0;  --  ../core/include/stm32f0/core_cm0.h:279
   xPSR_ISR_Msk : constant := (16#1FF# );  --  ../core/include/stm32f0/core_cm0.h:280

   CONTROL_SPSEL_Pos : constant := 1;  --  ../core/include/stm32f0/core_cm0.h:298
   --  unsupported macro: CONTROL_SPSEL_Msk (1UL << CONTROL_SPSEL_Pos)

   SCB_CPUID_IMPLEMENTER_Pos : constant := 24;  --  ../core/include/stm32f0/core_cm0.h:355
   --  unsupported macro: SCB_CPUID_IMPLEMENTER_Msk (0xFFUL << SCB_CPUID_IMPLEMENTER_Pos)

   SCB_CPUID_VARIANT_Pos : constant := 20;  --  ../core/include/stm32f0/core_cm0.h:358
   --  unsupported macro: SCB_CPUID_VARIANT_Msk (0xFUL << SCB_CPUID_VARIANT_Pos)

   SCB_CPUID_ARCHITECTURE_Pos : constant := 16;  --  ../core/include/stm32f0/core_cm0.h:361
   --  unsupported macro: SCB_CPUID_ARCHITECTURE_Msk (0xFUL << SCB_CPUID_ARCHITECTURE_Pos)

   SCB_CPUID_PARTNO_Pos : constant := 4;  --  ../core/include/stm32f0/core_cm0.h:364
   --  unsupported macro: SCB_CPUID_PARTNO_Msk (0xFFFUL << SCB_CPUID_PARTNO_Pos)

   SCB_CPUID_REVISION_Pos : constant := 0;  --  ../core/include/stm32f0/core_cm0.h:367
   SCB_CPUID_REVISION_Msk : constant := (16#F# );  --  ../core/include/stm32f0/core_cm0.h:368

   SCB_ICSR_NMIPENDSET_Pos : constant := 31;  --  ../core/include/stm32f0/core_cm0.h:371
   --  unsupported macro: SCB_ICSR_NMIPENDSET_Msk (1UL << SCB_ICSR_NMIPENDSET_Pos)

   SCB_ICSR_PENDSVSET_Pos : constant := 28;  --  ../core/include/stm32f0/core_cm0.h:374
   --  unsupported macro: SCB_ICSR_PENDSVSET_Msk (1UL << SCB_ICSR_PENDSVSET_Pos)

   SCB_ICSR_PENDSVCLR_Pos : constant := 27;  --  ../core/include/stm32f0/core_cm0.h:377
   --  unsupported macro: SCB_ICSR_PENDSVCLR_Msk (1UL << SCB_ICSR_PENDSVCLR_Pos)

   SCB_ICSR_PENDSTSET_Pos : constant := 26;  --  ../core/include/stm32f0/core_cm0.h:380
   --  unsupported macro: SCB_ICSR_PENDSTSET_Msk (1UL << SCB_ICSR_PENDSTSET_Pos)

   SCB_ICSR_PENDSTCLR_Pos : constant := 25;  --  ../core/include/stm32f0/core_cm0.h:383
   --  unsupported macro: SCB_ICSR_PENDSTCLR_Msk (1UL << SCB_ICSR_PENDSTCLR_Pos)

   SCB_ICSR_ISRPREEMPT_Pos : constant := 23;  --  ../core/include/stm32f0/core_cm0.h:386
   --  unsupported macro: SCB_ICSR_ISRPREEMPT_Msk (1UL << SCB_ICSR_ISRPREEMPT_Pos)

   SCB_ICSR_ISRPENDING_Pos : constant := 22;  --  ../core/include/stm32f0/core_cm0.h:389
   --  unsupported macro: SCB_ICSR_ISRPENDING_Msk (1UL << SCB_ICSR_ISRPENDING_Pos)

   SCB_ICSR_VECTPENDING_Pos : constant := 12;  --  ../core/include/stm32f0/core_cm0.h:392
   --  unsupported macro: SCB_ICSR_VECTPENDING_Msk (0x1FFUL << SCB_ICSR_VECTPENDING_Pos)

   SCB_ICSR_VECTACTIVE_Pos : constant := 0;  --  ../core/include/stm32f0/core_cm0.h:395
   SCB_ICSR_VECTACTIVE_Msk : constant := (16#1FF# );  --  ../core/include/stm32f0/core_cm0.h:396

   SCB_AIRCR_VECTKEY_Pos : constant := 16;  --  ../core/include/stm32f0/core_cm0.h:399
   --  unsupported macro: SCB_AIRCR_VECTKEY_Msk (0xFFFFUL << SCB_AIRCR_VECTKEY_Pos)

   SCB_AIRCR_VECTKEYSTAT_Pos : constant := 16;  --  ../core/include/stm32f0/core_cm0.h:402
   --  unsupported macro: SCB_AIRCR_VECTKEYSTAT_Msk (0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_Pos)

   SCB_AIRCR_ENDIANESS_Pos : constant := 15;  --  ../core/include/stm32f0/core_cm0.h:405
   --  unsupported macro: SCB_AIRCR_ENDIANESS_Msk (1UL << SCB_AIRCR_ENDIANESS_Pos)

   SCB_AIRCR_SYSRESETREQ_Pos : constant := 2;  --  ../core/include/stm32f0/core_cm0.h:408
   --  unsupported macro: SCB_AIRCR_SYSRESETREQ_Msk (1UL << SCB_AIRCR_SYSRESETREQ_Pos)

   SCB_AIRCR_VECTCLRACTIVE_Pos : constant := 1;  --  ../core/include/stm32f0/core_cm0.h:411
   --  unsupported macro: SCB_AIRCR_VECTCLRACTIVE_Msk (1UL << SCB_AIRCR_VECTCLRACTIVE_Pos)

   SCB_SCR_SEVONPEND_Pos : constant := 4;  --  ../core/include/stm32f0/core_cm0.h:415
   --  unsupported macro: SCB_SCR_SEVONPEND_Msk (1UL << SCB_SCR_SEVONPEND_Pos)

   SCB_SCR_SLEEPDEEP_Pos : constant := 2;  --  ../core/include/stm32f0/core_cm0.h:418
   --  unsupported macro: SCB_SCR_SLEEPDEEP_Msk (1UL << SCB_SCR_SLEEPDEEP_Pos)

   SCB_SCR_SLEEPONEXIT_Pos : constant := 1;  --  ../core/include/stm32f0/core_cm0.h:421
   --  unsupported macro: SCB_SCR_SLEEPONEXIT_Msk (1UL << SCB_SCR_SLEEPONEXIT_Pos)

   SCB_CCR_STKALIGN_Pos : constant := 9;  --  ../core/include/stm32f0/core_cm0.h:425
   --  unsupported macro: SCB_CCR_STKALIGN_Msk (1UL << SCB_CCR_STKALIGN_Pos)

   SCB_CCR_UNALIGN_TRP_Pos : constant := 3;  --  ../core/include/stm32f0/core_cm0.h:428
   --  unsupported macro: SCB_CCR_UNALIGN_TRP_Msk (1UL << SCB_CCR_UNALIGN_TRP_Pos)

   SCB_SHCSR_SVCALLPENDED_Pos : constant := 15;  --  ../core/include/stm32f0/core_cm0.h:432
   --  unsupported macro: SCB_SHCSR_SVCALLPENDED_Msk (1UL << SCB_SHCSR_SVCALLPENDED_Pos)

   SysTick_CTRL_COUNTFLAG_Pos : constant := 16;  --  ../core/include/stm32f0/core_cm0.h:457
   --  unsupported macro: SysTick_CTRL_COUNTFLAG_Msk (1UL << SysTick_CTRL_COUNTFLAG_Pos)

   SysTick_CTRL_CLKSOURCE_Pos : constant := 2;  --  ../core/include/stm32f0/core_cm0.h:460
   --  unsupported macro: SysTick_CTRL_CLKSOURCE_Msk (1UL << SysTick_CTRL_CLKSOURCE_Pos)

   SysTick_CTRL_TICKINT_Pos : constant := 1;  --  ../core/include/stm32f0/core_cm0.h:463
   --  unsupported macro: SysTick_CTRL_TICKINT_Msk (1UL << SysTick_CTRL_TICKINT_Pos)

   SysTick_CTRL_ENABLE_Pos : constant := 0;  --  ../core/include/stm32f0/core_cm0.h:466
   SysTick_CTRL_ENABLE_Msk : constant := (1 );  --  ../core/include/stm32f0/core_cm0.h:467

   SysTick_LOAD_RELOAD_Pos : constant := 0;  --  ../core/include/stm32f0/core_cm0.h:470
   SysTick_LOAD_RELOAD_Msk : constant := (16#FFFFFF# );  --  ../core/include/stm32f0/core_cm0.h:471

   SysTick_VAL_CURRENT_Pos : constant := 0;  --  ../core/include/stm32f0/core_cm0.h:474
   SysTick_VAL_CURRENT_Msk : constant := (16#FFFFFF# );  --  ../core/include/stm32f0/core_cm0.h:475

   SysTick_CALIB_NOREF_Pos : constant := 31;  --  ../core/include/stm32f0/core_cm0.h:478
   --  unsupported macro: SysTick_CALIB_NOREF_Msk (1UL << SysTick_CALIB_NOREF_Pos)

   SysTick_CALIB_SKEW_Pos : constant := 30;  --  ../core/include/stm32f0/core_cm0.h:481
   --  unsupported macro: SysTick_CALIB_SKEW_Msk (1UL << SysTick_CALIB_SKEW_Pos)

   SysTick_CALIB_TENMS_Pos : constant := 0;  --  ../core/include/stm32f0/core_cm0.h:484
   SysTick_CALIB_TENMS_Msk : constant := (16#FFFFFF# );  --  ../core/include/stm32f0/core_cm0.h:485

   SCS_BASE : constant := (16#E000E000#);  --  ../core/include/stm32f0/core_cm0.h:534
   --  unsupported macro: SysTick_BASE (SCS_BASE + 0x0010UL)
   --  unsupported macro: NVIC_BASE (SCS_BASE + 0x0100UL)
   --  unsupported macro: SCB_BASE (SCS_BASE + 0x0D00UL)
   --  unsupported macro: SCB ((SCB_Type *) SCB_BASE )
   --  unsupported macro: SysTick ((SysTick_Type *) SysTick_BASE )
   --  unsupported macro: NVIC ((NVIC_Type *) NVIC_BASE )
   --  unsupported macro: NVIC_SetPriorityGrouping __NVIC_SetPriorityGrouping
   --  unsupported macro: NVIC_GetPriorityGrouping __NVIC_GetPriorityGrouping
   --  unsupported macro: NVIC_EnableIRQ __NVIC_EnableIRQ
   --  unsupported macro: NVIC_GetEnableIRQ __NVIC_GetEnableIRQ
   --  unsupported macro: NVIC_DisableIRQ __NVIC_DisableIRQ
   --  unsupported macro: NVIC_GetPendingIRQ __NVIC_GetPendingIRQ
   --  unsupported macro: NVIC_SetPendingIRQ __NVIC_SetPendingIRQ
   --  unsupported macro: NVIC_ClearPendingIRQ __NVIC_ClearPendingIRQ
   --  unsupported macro: NVIC_SetPriority __NVIC_SetPriority
   --  unsupported macro: NVIC_GetPriority __NVIC_GetPriority
   --  unsupported macro: NVIC_SystemReset __NVIC_SystemReset
   --  unsupported macro: NVIC_SetVector __NVIC_SetVector
   --  unsupported macro: NVIC_GetVector __NVIC_GetVector

   NVIC_USER_IRQ_OFFSET : constant := 16;  --  ../core/include/stm32f0/core_cm0.h:599

   EXC_RETURN_HANDLER : constant := (16#FFFFFFF1#);  --  ../core/include/stm32f0/core_cm0.h:603
   EXC_RETURN_THREAD_MSP : constant := (16#FFFFFFF9#);  --  ../core/include/stm32f0/core_cm0.h:604
   EXC_RETURN_THREAD_PSP : constant := (16#FFFFFFFD#);  --  ../core/include/stm32f0/core_cm0.h:605

   --  skipped anonymous struct anon_anon_3

   type anon_anon_4 is record
      u_reserved0 : Extensions.Unsigned_28;  -- ../core/include/stm32f0/core_cm0.h:203
      V : Extensions.Unsigned_1;  -- ../core/include/stm32f0/core_cm0.h:204
      C : Extensions.Unsigned_1;  -- ../core/include/stm32f0/core_cm0.h:205
      Z : Extensions.Unsigned_1;  -- ../core/include/stm32f0/core_cm0.h:206
      N : Extensions.Unsigned_1;  -- ../core/include/stm32f0/core_cm0.h:207
   end record
   with Convention => C_Pass_By_Copy;
   type APSR_Type (discr : unsigned := 0) is record
      case discr is
         when 0 =>
            b : aliased anon_anon_4;  -- ../core/include/stm32f0/core_cm0.h:208
         when others =>
            w : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/core_cm0.h:209
      end case;
   end record
   with Convention => C_Pass_By_Copy,
        Unchecked_Union => True;  -- ../core/include/stm32f0/core_cm0.h:210

   --  skipped anonymous struct anon_anon_5

   type anon_anon_6 is record
      ISR : Extensions.Unsigned_9;  -- ../core/include/stm32f0/core_cm0.h:233
      u_reserved0 : Extensions.Unsigned_23;  -- ../core/include/stm32f0/core_cm0.h:234
   end record
   with Convention => C_Pass_By_Copy;
   type IPSR_Type (discr : unsigned := 0) is record
      case discr is
         when 0 =>
            b : aliased anon_anon_6;  -- ../core/include/stm32f0/core_cm0.h:235
         when others =>
            w : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/core_cm0.h:236
      end case;
   end record
   with Convention => C_Pass_By_Copy,
        Unchecked_Union => True;  -- ../core/include/stm32f0/core_cm0.h:237

   --  skipped anonymous struct anon_anon_7

   type anon_anon_8 is record
      ISR : Extensions.Unsigned_9;  -- ../core/include/stm32f0/core_cm0.h:251
      u_reserved0 : Extensions.Unsigned_15;  -- ../core/include/stm32f0/core_cm0.h:252
      T : Extensions.Unsigned_1;  -- ../core/include/stm32f0/core_cm0.h:253
      u_reserved1 : Extensions.Unsigned_3;  -- ../core/include/stm32f0/core_cm0.h:254
      V : Extensions.Unsigned_1;  -- ../core/include/stm32f0/core_cm0.h:255
      C : Extensions.Unsigned_1;  -- ../core/include/stm32f0/core_cm0.h:256
      Z : Extensions.Unsigned_1;  -- ../core/include/stm32f0/core_cm0.h:257
      N : Extensions.Unsigned_1;  -- ../core/include/stm32f0/core_cm0.h:258
   end record
   with Convention => C_Pass_By_Copy;
   type xPSR_Type (discr : unsigned := 0) is record
      case discr is
         when 0 =>
            b : aliased anon_anon_8;  -- ../core/include/stm32f0/core_cm0.h:259
         when others =>
            w : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/core_cm0.h:260
      end case;
   end record
   with Convention => C_Pass_By_Copy,
        Unchecked_Union => True;  -- ../core/include/stm32f0/core_cm0.h:261

   --  skipped anonymous struct anon_anon_9

   type anon_anon_10 is record
      u_reserved0 : Extensions.Unsigned_1;  -- ../core/include/stm32f0/core_cm0.h:290
      SPSEL : Extensions.Unsigned_1;  -- ../core/include/stm32f0/core_cm0.h:291
      u_reserved1 : Extensions.Unsigned_30;  -- ../core/include/stm32f0/core_cm0.h:292
   end record
   with Convention => C_Pass_By_Copy;
   type CONTROL_Type (discr : unsigned := 0) is record
      case discr is
         when 0 =>
            b : aliased anon_anon_10;  -- ../core/include/stm32f0/core_cm0.h:293
         when others =>
            w : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/core_cm0.h:294
      end case;
   end record
   with Convention => C_Pass_By_Copy,
        Unchecked_Union => True;  -- ../core/include/stm32f0/core_cm0.h:295

   --  skipped anonymous struct anon_anon_11

   type NVIC_Type_array1029 is array (0 .. 0) of aliased stdint_h.uint32_t;
   type NVIC_Type_array1033 is array (0 .. 30) of aliased stdint_h.uint32_t;
   type NVIC_Type_array1036 is array (0 .. 63) of aliased stdint_h.uint32_t;
   type NVIC_Type_array1038 is array (0 .. 7) of aliased stdint_h.uint32_t;
   type NVIC_Type is record
      ISER : aliased NVIC_Type_array1029;  -- ../core/include/stm32f0/core_cm0.h:316
      RESERVED0 : aliased NVIC_Type_array1033;  -- ../core/include/stm32f0/core_cm0.h:317
      ICER : aliased NVIC_Type_array1029;  -- ../core/include/stm32f0/core_cm0.h:318
      RSERVED1 : aliased NVIC_Type_array1033;  -- ../core/include/stm32f0/core_cm0.h:319
      ISPR : aliased NVIC_Type_array1029;  -- ../core/include/stm32f0/core_cm0.h:320
      RESERVED2 : aliased NVIC_Type_array1033;  -- ../core/include/stm32f0/core_cm0.h:321
      ICPR : aliased NVIC_Type_array1029;  -- ../core/include/stm32f0/core_cm0.h:322
      RESERVED3 : aliased NVIC_Type_array1033;  -- ../core/include/stm32f0/core_cm0.h:323
      RESERVED4 : aliased NVIC_Type_array1036;  -- ../core/include/stm32f0/core_cm0.h:324
      IP : aliased NVIC_Type_array1038;  -- ../core/include/stm32f0/core_cm0.h:325
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/core_cm0.h:326

   --  skipped anonymous struct anon_anon_12

   type SCB_Type_array1045 is array (0 .. 1) of aliased stdint_h.uint32_t;
   type SCB_Type is record
      CPUID : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/core_cm0.h:343
      ICSR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/core_cm0.h:344
      RESERVED0 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/core_cm0.h:345
      AIRCR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/core_cm0.h:346
      SCR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/core_cm0.h:347
      CCR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/core_cm0.h:348
      RESERVED1 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/core_cm0.h:349
      SHP : aliased SCB_Type_array1045;  -- ../core/include/stm32f0/core_cm0.h:350
      SHCSR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/core_cm0.h:351
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/core_cm0.h:352

   --  skipped anonymous struct anon_anon_13

   type SysTick_Type is record
      CTRL : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/core_cm0.h:450
      LOAD : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/core_cm0.h:451
      VAL : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/core_cm0.h:452
      CALIB : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/core_cm0.h:453
   end record
   with Convention => C_Pass_By_Copy;  -- ../core/include/stm32f0/core_cm0.h:454

   --  skipped func __NVIC_EnableIRQ

   --  skipped func __NVIC_GetEnableIRQ

   --  skipped func __NVIC_DisableIRQ

   --  skipped func __NVIC_GetPendingIRQ

   --  skipped func __NVIC_SetPendingIRQ

   --  skipped func __NVIC_ClearPendingIRQ

   --  skipped func __NVIC_SetPriority

   --  skipped func __NVIC_GetPriority

   function NVIC_EncodePriority
     (PriorityGroup : stdint_h.uint32_t;
      PreemptPriority : stdint_h.uint32_t;
      SubPriority : stdint_h.uint32_t) return stdint_h.uint32_t  -- ../core/include/stm32f0/core_cm0.h:779
   with Import => True, 
        Convention => C, 
        External_Name => "NVIC_EncodePriority";

   procedure NVIC_DecodePriority
     (Priority : stdint_h.uint32_t;
      PriorityGroup : stdint_h.uint32_t;
      pPreemptPriority : access stdint_h.uint32_t;
      pSubPriority : access stdint_h.uint32_t)  -- ../core/include/stm32f0/core_cm0.h:806
   with Import => True, 
        Convention => C, 
        External_Name => "NVIC_DecodePriority";

   --  skipped func __NVIC_SetVector

   --  skipped func __NVIC_GetVector

   --  skipped func __NVIC_SystemReset

   function SCB_GetFPUType return stdint_h.uint32_t  -- ../core/include/stm32f0/core_cm0.h:889
   with Import => True, 
        Convention => C, 
        External_Name => "SCB_GetFPUType";

   function SysTick_Config (ticks : stdint_h.uint32_t) return stdint_h.uint32_t  -- ../core/include/stm32f0/core_cm0.h:920
   with Import => True, 
        Convention => C, 
        External_Name => "SysTick_Config";

end stm32f0_core_cm0_h;
