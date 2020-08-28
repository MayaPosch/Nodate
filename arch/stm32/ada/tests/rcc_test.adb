--
-- rcc_test.adb - Tests the RCC package.
--


with RCC;

with Ada.Text_IO, Interfaces;
use Ada.Text_IO, Interfaces;

with stm32f0_stm32f030x6_h;


procedure main is
	package stm32f0 renames stm32f0_stm32f030x6_h;

	RCC_regs: access stm32f0.RCC_TypeDef;
	with Import, Convention => C, Address => stm32f0.RCC.all'Address;
begin
	Put_Line("Running RCC test...");
	
	-- Enable peripherals in RCC package.
	RCC.enable(RCC_SYSCFGCOMP);
	RCC.enablePort(RCC_PORT_A);
	
	-- Print out the AHBENR, APB1ENR and APB2ENR registers.
	Put("AHBENR:  "); Put(Unsigned_32'Image(RCC_regs.all.AHBENR)); New_Line;
	Put("APB1ENR: "); Put(Unsigned_32'Image(RCC_regs.all.AHBENR)); New_Line;
	Put("APB2ENR: "); Put(Unsigned_32'Image(RCC_regs.all.AHBENR)); New_Line;
end main;