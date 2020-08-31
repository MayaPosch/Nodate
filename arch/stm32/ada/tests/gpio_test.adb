--
-- rcc_test.adb - Tests the RCC package.
--


with GPIO;

with Ada.Text_IO, Interfaces;
use Ada.Text_IO, Interfaces;

with stm32_records;
with stm32_h; use stm32_h;


procedure gpio_test is
	RCC_regs: access stm32_records.RCC_TypeDef
	with Import, Convention => C, External_name => "RCC";
	
	GPIOA_regs: access stm32_records.GPIO_TypeDef
	with Import, Convention => C, External_name => "GPIOA";
	
	GPIOB_regs: access stm32_records.GPIO_TypeDef
	with Import, Convention => C, External_name => "GPIOB";
	
	GPIOD_regs: access stm32_records.GPIO_TypeDef
	with Import, Convention => C, External_name => "GPIOD";
	
	ret: Boolean;
begin
	Put_Line("Running GPIO test...");
	
	-- Set pins in GPIO class.
	ret := GPIO.set_output(GPIO_PORT_A, 3, GPIO_PULL_UP);
	Put_Line("Set output: " & Boolean'Image(ret));
	ret := GPIO.write(GPIO_PORT_A, 3, GPIO_LEVEL_HIGH);
	Put_Line("Write output: " & Boolean'Image(ret));
	
	ret := GPIO.set_output(GPIO_PORT_B, 1, GPIO_PULL_UP);
	Put_Line("Set output: " & Boolean'Image(ret));
	ret := GPIO.write(GPIO_PORT_B, 1, GPIO_LEVEL_HIGH);
	Put_Line("Write output: " & Boolean'Image(ret));
	
	ret := GPIO.set_input(GPIO_PORT_A, 1, GPIO_PULL_UP);
	Put_Line("Set input: " & Boolean'Image(ret));
	ret := GPIO.set_input(GPIO_PORT_B, 3, GPIO_PULL_UP);
	Put_Line("Set input: " & Boolean'Image(ret));
	ret := GPIO.set_input(GPIO_PORT_D, 1, GPIO_PULL_UP);
	Put_Line("Set input: " & Boolean'Image(ret));
	
	-- Print out the RCC AHB register.
	Put_Line("RCC");
	Put("AHBENR:  "); Put(Unsigned_32'Image(Unsigned_32(RCC_regs.all.AHBENR))); New_Line;
	New_Line;
	
	-- Print out the GPIOA MODER, PUPDR, OTYPER, OSPEEDR, IDR and ODR registers.
	Put_Line("GPIOA");
	Put("MODER:   "); Put(Unsigned_32'Image(Unsigned_32(GPIOA_regs.all.MODER))); New_Line;
	Put("PUPDR:   "); Put(Unsigned_32'Image(Unsigned_32(GPIOA_regs.all.PUPDR))); New_Line;
	Put("OTYPER:  "); Put(Unsigned_32'Image(Unsigned_32(GPIOA_regs.all.OTYPER))); New_Line;
	Put("OSPEEDR: "); Put(Unsigned_32'Image(Unsigned_32(GPIOA_regs.all.OSPEEDR))); New_Line;
	Put("IDR:     "); Put(Unsigned_32'Image(Unsigned_32(GPIOA_regs.all.IDR))); New_Line;
	Put("ODR:     "); Put(Unsigned_32'Image(Unsigned_32(GPIOA_regs.all.ODR))); New_Line;
	New_Line;
	
	-- Print out the GPIOB MODER, PUPDR, OTYPER, OSPEEDR, IDR and ODR registers.
	Put_Line("GPIOB");
	Put("MODER:   "); Put(Unsigned_32'Image(Unsigned_32(GPIOB_regs.all.MODER))); New_Line;
	Put("PUPDR:   "); Put(Unsigned_32'Image(Unsigned_32(GPIOB_regs.all.PUPDR))); New_Line;
	Put("OTYPER:  "); Put(Unsigned_32'Image(Unsigned_32(GPIOB_regs.all.OTYPER))); New_Line;
	Put("OSPEEDR: "); Put(Unsigned_32'Image(Unsigned_32(GPIOB_regs.all.OSPEEDR))); New_Line;
	Put("IDR:     "); Put(Unsigned_32'Image(Unsigned_32(GPIOB_regs.all.IDR))); New_Line;
	Put("ODR:     "); Put(Unsigned_32'Image(Unsigned_32(GPIOB_regs.all.ODR))); New_Line;
	New_Line;
	
	
	-- Print out the GPIOD MODER, PUPDR, OTYPER, OSPEEDR, IDR and ODR registers.
	Put_Line("GPIOD");
	Put("MODER:   "); Put(Unsigned_32'Image(Unsigned_32(GPIOD_regs.all.MODER))); New_Line;
	Put("PUPDR:   "); Put(Unsigned_32'Image(Unsigned_32(GPIOD_regs.all.PUPDR))); New_Line;
	Put("OTYPER:  "); Put(Unsigned_32'Image(Unsigned_32(GPIOD_regs.all.OTYPER))); New_Line;
	Put("OSPEEDR: "); Put(Unsigned_32'Image(Unsigned_32(GPIOD_regs.all.OSPEEDR))); New_Line;
	Put("IDR:     "); Put(Unsigned_32'Image(Unsigned_32(GPIOD_regs.all.IDR))); New_Line;
	Put("ODR:     "); Put(Unsigned_32'Image(Unsigned_32(GPIOD_regs.all.ODR))); New_Line;
	New_Line;
	
end gpio_test;
