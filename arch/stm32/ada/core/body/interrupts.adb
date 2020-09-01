--
-- interrupts.adb - Body for the Interrupts functionality.
--

with RCC;
with GPIO;
with stdint_h; use stdint_h;
with stm32_h; use stm32_h;
with stm32f0_stm32f030x6_h; use stm32f0_stm32f030x6_h;

with Ada.Containers.Vectors;
with Interfaces; use Interfaces;
with Interfaces.C; use Interfaces.C;


package body Interrupts is
	type SourceRange is range 0 .. 50;
	type SourceArrayType is array(SourceRange) of aliased InterruptSource;
	--type SourceArrayType is array(0 .. 50) of aliased InterruptSource;
	
	-- type CallbackRange is range 0 .. 16;
	-- type CallbackArrayType is array(CallbackRange) of InterruptCallback;
	type callbackArrayType is array(SourceRange) of InterruptCallback;
	callbackArray : CallbackArrayType;
	--callbackArray : array (0 .. 16) of InterruptCallback;
	
	procedure NVIC_EnableIRQ(IRQn: IRQn_Type)
	with Import, Convention => C, External_Name => "NVIC_EnableIRQ";
	procedure NVIC_DisableIRQ(IRQn: IRQn_Type)
	with Import, Convention => C, External_Name => "NVIC_DisableIRQ";
	procedure NVIC_SetPriority(IRQn: IRQn_Type; priority: uint32_t)
	with Import, Convention => C, External_Name => "NVIC_SetPriority";
	
	-- STM32F0
	-- exti0_1_pwr : Integer;
	-- exti2_3_pwr : Integer;
	-- exti4_15_pwr : Integer;
	-- STM32F4/F7
	-- exti5_9_pwr : Integer;
	-- exti10_15_pwr : Integer;
	
	-- STM32F0 
	-- EXTI0_1_IRQHandler --
	procedure EXTI0_1_IRQHandler is
		srcArray: SourceArrayType
		with Import, Convention => C, Address => InterruptSources.all'Address;
	begin
		-- Determine whether pin 0 or 1 was triggered.
		if (Unsigned_32(srcArray(1).exti.all.PR) and Shift_Left(1, 1)) = 1 then
			-- Clear the EXTI status flag.
			srcArray(1).exti.all.PR := uint32_t(Unsigned_32(srcArray(1).exti.all.PR) or Shift_Left(1, 1));
			callbackArray(1).all; -- Call the callback function.
		else
			srcArray(0).exti.all.PR := uint32_t(Unsigned_32(srcArray(0).exti.all.PR) or 1);
			callbackArray(0).all;
		end if;
	end EXTI0_1_IRQHandler;
	
	-- EXTI2_3_IRQHandler --
	procedure EXTI2_3_IRQHandler is
		srcArray: SourceArrayType
		with Import, Convention => C, Address => InterruptSources.all'Address;
	begin
		if (Unsigned_32(srcArray(2).exti.all.PR) and Shift_Left(1, 2)) = 1 then
			srcArray(2).exti.all.PR := uint32_t(Unsigned_32(srcArray(2).exti.all.PR) or Shift_Left(1, 2));
			callbackArray(2).all; -- Call the callback function.
		else
			srcArray(3).exti.all.PR := uint32_t(Unsigned_32(srcArray(3).exti.all.PR) or Shift_Left(1, 3));
			callbackArray(3).all;
		end if;
	end EXTI2_3_IRQHandler;
	
	-- EXTI4_15_IRQHandler --
	procedure EXTI4_15_IRQHandler is
		srcArray: SourceArrayType
		with Import, Convention => C, Address => InterruptSources.all'Address;
		idx	: Integer := 4;
	begin
		for i in SourceRange range 4 .. 15 loop
			if (Unsigned_32(srcArray(i).exti.all.PR) and Shift_Left(1, idx)) = 1 then
				srcArray(i).exti.all.PR := uint32_t(Unsigned_32(srcArray(i).exti.all.PR) or Shift_Left(1, idx));
				callbackArray(i).all;
			end if;
			idx := idx + 1;
		end loop;
	end EXTI4_15_IRQHandler;
	
	-- STM32F4/F7
	-- EXTI0_IRQHandler --
	procedure EXTI0_IRQHandler is
		srcArray: SourceArrayType
		with Import, Convention => C, Address => InterruptSources.all'Address;
	begin
		srcArray(0).exti.all.PR := uint32_t(Unsigned_32(srcArray(0).exti.all.PR) or 1);
		callbackArray(0).all;
	end EXTI0_IRQHandler;
	
	-- EXTI1_IRQHandler --
	procedure EXTI1_IRQHandler is
		srcArray: SourceArrayType
		with Import, Convention => C, Address => InterruptSources.all'Address;
	begin
		srcArray(1).exti.all.PR := uint32_t(Unsigned_32(srcArray(1).exti.all.PR) or Shift_Left(1, 1));
		callbackArray(1).all;
	end EXTI1_IRQHandler;
	
	-- EXTI2_IRQHandler --
	procedure EXTI2_IRQHandler is
		srcArray: SourceArrayType
		with Import, Convention => C, Address => InterruptSources.all'Address;
	begin
		srcArray(2).exti.all.PR := uint32_t(Unsigned_32(srcArray(2).exti.all.PR) or Shift_Left(1, 2));
		callbackArray(2).all;
	end EXTI2_IRQHandler;
	
	-- EXTI3_IRQHandler --
	procedure EXTI3_IRQHandler is
		srcArray: SourceArrayType
		with Import, Convention => C, Address => InterruptSources.all'Address;
	begin
		srcArray(3).exti.all.PR := uint32_t(Unsigned_32(srcArray(3).exti.all.PR) or Shift_Left(1, 3));
		callbackArray(3).all;
	end EXTI3_IRQHandler;
	
	-- EXTI4_IRQHandler --
	procedure EXTI4_IRQHandler is
		srcArray: SourceArrayType
		with Import, Convention => C, Address => InterruptSources.all'Address;
	begin
		srcArray(4).exti.all.PR := uint32_t(Unsigned_32(srcArray(4).exti.all.PR) or Shift_Left(1, 4));
		callbackArray(4).all;
	end EXTI4_IRQHandler;
	
	-- EXTI9_5_IRQHandler --
	procedure EXTI9_5_IRQHandler is
		srcArray: SourceArrayType
		with Import, Convention => C, Address => InterruptSources.all'Address;
		idx	: Integer := 5;
	begin
		for i in SourceRange range 5 .. 9 loop
			if (Unsigned_32(srcArray(i).exti.all.PR) and Shift_Left(1, idx)) = 1 then
				srcArray(i).exti.all.PR := uint32_t(Unsigned_32(srcArray(i).exti.all.PR) or Shift_Left(1, idx));
				callbackArray(i).all;
			end if;
			idx := idx + 1;
		end loop;
	end EXTI9_5_IRQHandler;
	
	-- EXTI15_10_IRQHandler --
	procedure EXTI15_10_IRQHandler is
		srcArray: SourceArrayType
		with Import, Convention => C, Address => InterruptSources.all'Address;
		idx	: Integer := 10;
	begin
		for i in SourceRange range 10 .. 15 loop
			if (Unsigned_32(srcArray(i).exti.all.PR) and Shift_Left(1, idx)) = 1 then
				srcArray(i).exti.all.PR := uint32_t(Unsigned_32(srcArray(i).exti.all.PR) or Shift_Left(1, idx));
				callbackArray(i).all;
			end if;
			idx := idx + 1;
		end loop;
	end EXTI15_10_IRQHandler;
	
	
	-- ENABLE --
	function enable return Boolean is
		ret: Boolean;
	begin
		ret := RCC.enable(RCC_SYSCFGCOMP);
		return ret;
	end enable;
	
	
	-- DISABLE --
	function disable return Boolean is
		ret: Boolean;
	begin
		ret := RCC.disable(RCC_SYSCFGCOMP);
		return ret;
	end disable;
	
	
	-- SET INTERRUPT --
	function setInterrupt(	pin: Integer; 
							port: GPIO_ports; 
							trigger: InterruptTrigger;
							callback: in not null InterruptCallback;
							priority: Integer;
							handle: out Integer) return Boolean is
		srcArray: SourceArrayType
		with Import, Convention => C, Address => InterruptSources.all'Address;
		
		src		: InterruptSource renames srcArray(SourceRange(pin));
	begin
		handle := pin;
		if src.active = true then
			-- Already active EXTICRx entry. Possibly due to a pin on another port in use.
			-- TODO: set reason.
			return false;
		end if;
		
		-- Assign the new entry information and set the requested port in the SYSCFG EXTICR.
		src.port := port;
		src.pin := Unsigned_8(pin);
		src.trigger := trigger;
		--src.callback := callback;
		callbackArray(SourceRange(pin)) := callback;
		src.priority := Unsigned_8(priority);
		src.syscfg.all.EXTICR(Integer(src.reg)) := uint32_t(Unsigned_32(src.syscfg.all.EXTICR(Integer(src.reg))) or Shift_Left(Unsigned_32(GPIO_ports'Pos(port)), Integer(Integer(src.offset))));
		
		-- In the EXTI peripheral.
		-- - set interrupt mask (IM) for the pin.
		-- - set RTSR, FTSR or both for the pin.
		-- The pin corresponds to the EXTI line.
		src.exti.all.IMR := uint32_t(Unsigned_32(src.exti.all.IMR) or Shift_Left(1, pin));
		
		if trigger = INTERRUPT_TRIGGER_RISING then
			src.exti.all.RTSR := uint32_t(Unsigned_32(src.exti.all.RTSR) or Shift_Left(1, pin));
			src.exti.all.FTSR := uint32_t(Unsigned_32(src.exti.all.FTSR) and (not Shift_Left(1, pin)));
		elsif trigger = INTERRUPT_TRIGGER_FALLING then
			src.exti.all.RTSR := uint32_t(Unsigned_32(src.exti.all.RTSR) and (not Shift_Left(1, pin)));
			src.exti.all.FTSR := uint32_t(Unsigned_32(src.exti.all.FTSR) or Shift_Left(1, pin));
		elsif trigger = INTERRUPT_TRIGGER_BOTH then
			src.exti.all.RTSR := uint32_t(Unsigned_32(src.exti.all.RTSR) or Shift_Left(1, pin));
			src.exti.all.FTSR := uint32_t(Unsigned_32(src.exti.all.FTSR) or Shift_Left(1, pin));
		end if;
		
		-- Enable the NVIC interrupt on the registered EXTI line.
		-- Priority level 0 is the highest, with M0 supporting up to 192.
		-- Cortex M3, M4 and M7 support 255 levels.
		setIrqType(src.irqType, pin);
		
		-- if stm32_type = 0 then
			-- src.irqType := EXTI4_15_IRQn;
			-- if pin = 0 or pin = 1 then
				-- src.irqType := EXTI0_1_IRQn;
				-- exti0_1_pwr := exti0_1_pwr + 1;
			-- elsif pin = 2 or pin = 3 then
				-- src.irqType := EXTI2_3_IRQn;
				-- exti2_3_pwr := exti2_3_pwr + 1;
			-- else
				-- exti4_15_pwr := exti4_15_pwr + 1;
			-- end if;
		-- elsif stm32_type = 4 or stm32_type = 7 then
			-- src.irqType := EXTI15_10_IRQn;
			-- if pin = 0 then
				-- src.irqType := EXTI0_IRQn;
			-- elsif pin = 1 then
				-- src.irqType := EXTI1_IRQn;
			-- elsif pin = 2 then
				-- src.irqType := EXTI2_IRQn;
			-- elsif pin = 3 then
				-- src.irqType := EXTI3_IRQn;
			-- elsif pin = 4 then
				-- src.irqType := EXTI4_IRQn;
			-- elsif pin > 4 and pin < 10 then
				-- src.irqType := EXTI9_5_IRQn;
				-- exti5_9_pwr := exti5_9_pwr + 1;
			-- elsif pin > 9 and pin < 16 then
				-- src.irqType := EXTI15_10_IRQn;
				-- exti5_9_pwr := exti10_15_pwr + 1;
			-- end if;
		-- end if;
		
		NVIC_SetPriority(src.irqType, Unsigned(priority));
		NVIC_EnableIRQ(src.irqType);
		
		return true;
	end setInterrupt;
	
	
	-- TRIGGER INTERRUPT --
	procedure triggerInterrupt is
	begin
		null;
	end triggerInterrupt;
	
	
	-- REMOVE INTERRUPT --
	function removeInterrupt(handle: Integer) return Boolean is
		srcArray: SourceArrayType
		with Import, Convention => C, Address => InterruptSources.all'Address;
		
		src		: InterruptSource renames srcArray(SourceRange(handle));
		nvic_disable	: Boolean := false; -- Set to disable the interrupt.
	begin
		if src.active = false then
			-- Set reason.
			return false;
		end if;
		
		-- Set record to non-active.
		src.active := false;
		
		-- Disable the interrupt.
		checkIrqDisable(src.irqType, nvic_disable);
		
		--if stm32_type = 0 then
			-- if src.irqType = EXTI0_1_IRQn then
				-- exti0_1_pwr := exti0_1_pwr - 1;
				-- if exti0_1_pwr /= 0 then
					-- nvic_disable := false;
				-- end if;
			-- elsif src.irqType = EXTI2_3_IRQn then
				-- exti2_3_pwr := exti2_3_pwr - 1;
				-- if exti2_3_pwr /= 0 then
					-- nvic_disable := false;
				-- end if;
			-- else
				-- exti4_15_pwr := exti4_15_pwr -1;
				-- if exti4_15_pwr /= 0 then
					-- nvic_disable := false;
				-- end if;
			-- end if;
		--elsif stm32_type = 4 or stm32_type = 7 then
			-- if src.irqType = EXTI9_5_IRQn then
				-- exti5_9_pwr := exti5_9_pwr - 1;
				-- if exti5_9_pwr /= 0 then
					-- nvic_disable := false;
				-- end if;
			-- elsif src.irqType = EXTI15_10_IRQn then
				-- exti10_15_pwr := exti10_15_pwr - 1;
				-- if exti10_15_pwr /= 0 then
					-- nvic_disable := false;
				-- end if;
			-- end if;
		--end if;
		
		if nvic_disable = true then
			NVIC_DisableIRQ(src.irqType);
		end if;
		
		-- Next reset the EXTI registers.
		src.exti.all.IMR := uint32_t(Unsigned_32(src.exti.all.IMR) and (not Shift_Left(1, Integer(src.pin))));
		src.exti.all.RTSR := uint32_t(Unsigned_32(src.exti.all.RTSR) and (not Shift_Left(1, Integer(src.pin))));
		src.exti.all.FTSR := uint32_t(Unsigned_32(src.exti.all.FTSR) and (not Shift_Left(1, Integer(src.pin))));
		
		-- Finally reset the SYSCFG register.
		src.syscfg.all.EXTICR(Integer(src.reg)) := uint32_t(Unsigned_32(src.syscfg.all.EXTICR(Integer(src.reg))) and (not Shift_Left(16#F#, Integer(src.offset))));
		
		return true;
	end removeInterrupt;
	
end Interrupts;