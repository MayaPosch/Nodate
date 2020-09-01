--
-- interrupts_test.adb - Tests the Interrupts package.
--


with Interrupts; use Interrupts;

with Ada.Text_IO, Interfaces;
use Ada.Text_IO, Interfaces;

with stm32_records;
with stm32_h; use stm32_h;

with interrupts_callbacks; use interrupts_callbacks;


procedure interrupts_test is
	RCC_regs: access stm32_records.RCC_TypeDef
	with Import, Convention => C, External_name => "RCC";
	
	SYSCFG_regs: access stm32_records.SYSCFG_TypeDef
	with Import, Convention => C, External_name => "SYSCFG";
	
	EXTI_regs: access stm32_records.EXTI_TypeDef
	with Import, Convention => C, External_name => "EXTI";
	
	ret		: Boolean;
	handleA	: Integer;
	handleB	: Integer;
begin
	Put_Line("Running Interrupts test...");

	-- Start Interrupts.
	ret := Interrupts.enable;
	Put_Line("Set output: " & Boolean'Image(ret));
	
	-- Set interrupts.
	ret := Interrupts.setInterrupt(0, GPIO_PORT_B, INTERRUPT_TRIGGER_FALLING, callback'Access, 0, handleA);
	Put_Line("Set output: " & Boolean'Image(ret));
	ret := Interrupts.setInterrupt(1, GPIO_PORT_B, INTERRUPT_TRIGGER_FALLING, callback'Access, 0, handleB);
	Put_Line("Set output: " & Boolean'Image(ret));
	
	-- Print out the RCC AHB, APB1 and APB2 registers.
	Put_Line("RCC");
	Put("AHBENR:  "); Put(Unsigned_32'Image(Unsigned_32(RCC_regs.all.AHBENR))); New_Line;
	Put("APB1ENR:  "); Put(Unsigned_32'Image(Unsigned_32(RCC_regs.all.APB1ENR))); New_Line;
	Put("APB2ENR:  "); Put(Unsigned_32'Image(Unsigned_32(RCC_regs.all.APB2ENR))); New_Line;
	New_Line;
	
	-- Print out the RCC AHB register.
	Put_Line("SYSCFG");
	Put("EXTICR1:  "); Put(Unsigned_32'Image(Unsigned_32(SYSCFG_regs.all.EXTICR(0)))); New_Line;
	Put("EXTICR2:  "); Put(Unsigned_32'Image(Unsigned_32(SYSCFG_regs.all.EXTICR(1)))); New_Line;
	Put("EXTICR3:  "); Put(Unsigned_32'Image(Unsigned_32(SYSCFG_regs.all.EXTICR(2)))); New_Line;
	Put("EXTICR4:  "); Put(Unsigned_32'Image(Unsigned_32(SYSCFG_regs.all.EXTICR(3)))); New_Line;
	New_Line;
	
	-- Print out the EXTI IMR, RTSR, FTSR & PR registers.
	Put_Line("EXTI");
	Put("IMR:  "); Put(Unsigned_32'Image(Unsigned_32(EXTI_regs.all.IMR))); New_Line;
	Put("RTSR:  "); Put(Unsigned_32'Image(Unsigned_32(EXTI_regs.all.RTSR))); New_Line;
	Put("FTSR:  "); Put(Unsigned_32'Image(Unsigned_32(EXTI_regs.all.FTSR))); New_Line;
	Put("PR:  "); Put(Unsigned_32'Image(Unsigned_32(EXTI_regs.all.PR))); New_Line;
	New_Line;

end interrupts_test;