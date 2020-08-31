

with stdint_h;

package stm32_records is
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
	with Convention => C_Pass_By_Copy;
	
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
   with Convention => C_Pass_By_Copy;
   
   type EXTI_TypeDef is record
      IMR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:190
      EMR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:191
      RTSR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:192
      FTSR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:193
      SWIER : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:194
      PR : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:195
   end record
   with Convention => C_Pass_By_Copy;
   
   type SYSCFG_TypeDef_array1096 is array (0 .. 3) of aliased stdint_h.uint32_t;
   type SYSCFG_TypeDef is record
      CFGR1 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:250
      RESERVED : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:251
      EXTICR : aliased SYSCFG_TypeDef_array1096;  -- ../core/include/stm32f0/stm32f030x6.h:252
      CFGR2 : aliased stdint_h.uint32_t;  -- ../core/include/stm32f0/stm32f030x6.h:253
   end record
   with Convention => C_Pass_By_Copy;
end stm32_records;
