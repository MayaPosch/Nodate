--
-- rcc_test.adb - Tests the RCC package.
--


with RCC;

with Ada.Text_IO, Interfaces;
use Ada.Text_IO, Interfaces;

--with stm32f0_stm32f030x6_h;

with stm32_records;
with stm32;


procedure rcc_test is
	--package stm32f0 renames stm32f0_stm32f030x6_h;

	RCC_regs: access stm32_records.RCC_TypeDef
	with Import, Convention => C, External_name => "RCC";
	
	ret: Boolean;
begin
	Put_Line("Running RCC test...");
	
	-- Enable peripherals in RCC package.
	ret := RCC.enable(stm32.RCC_SYSCFGCOMP);
	Put_Line("Enable: " & Boolean'Image(ret));
	ret := RCC.enablePort(stm32.RCC_PORT_A);
	Put_Line("Enable Port: " & Boolean'Image(ret));
	
	-- Print out the AHBENR, APB1ENR and APB2ENR registers.
	Put("AHBENR:  "); Put(Unsigned_32'Image(Unsigned_32(RCC_regs.all.AHBENR))); New_Line;
	Put("APB1ENR: "); Put(Unsigned_32'Image(Unsigned_32(RCC_regs.all.AHBENR))); New_Line;
	Put("APB2ENR: "); Put(Unsigned_32'Image(Unsigned_32(RCC_regs.all.AHBENR))); New_Line;
end rcc_test;
