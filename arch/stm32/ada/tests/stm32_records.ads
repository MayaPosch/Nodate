

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
end stm32_records;
