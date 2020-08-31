--
-- interrupts.adb - Body for the Interrupts functionality.
--

with RCC;
with GPIO;
with stdint_h; use stdint_h;
with stm32_h; use stm32_h;

with Ada.Containers.Vectors;
with Interfaces; use Interfaces;
with Interfaces.C; use Interfaces.C;


package body Interrupts is
	type SourceRange is range 0 .. 50;
	type SourceArrayType is array(SourceRange) of aliased InterruptSource;
	
	procedure NVIC_EnableIRQ(IRQn: IRQn_Type)
	with Import, Convention => C;
	procedure NVIC_DisableIRQ(IRQn: IRQn_Type)
	with Import, Convention => C;
	procedure NVIC_SetPriority(IRQn: IRQn_Type; priority: uint32_t)
	with Import, Convention => C;
	
	-- STM32F0
	ext0_1_pwr : Integer;
	ext2_3_pwr : Integer;
	ext4_15_pwr : Integer;
	-- STM32F4/F7
	ext5_9_pwr : Integer;
	ext10_15_pwr : Integer;
	
	-- STM32F0 
	procedure EXTI0_1_IRQHandler is
	begin
		-- Determine whether pin 0 or 1 was triggered.
		if 
	end EXTI0_1_IRQHandler
	with Export, Convention => C, External_Name => "EXTI0_1_IRQHandler";
	
	procedure EXTI2_3_IRQHandler is
	begin
		--
	end EXTI2_3_IRQHandler
	with Export, Convention => C, External_Name => "EXTI2_3_IRQHandler";
	
	procedure EXTI4_15_IRQHandler is
	begin
		--
	end EXTI4_15_IRQHandler
	with Export, Convention => C, External_Name => "EXTI4_15_IRQHandler";
	
	-- STM32F4/F7
	procedure EXTI0_IRQHandler is
	begin
		--
	end EXTI0_IRQHandler
	with Export, Convention => C, External_Name => "EXTI0_IRQHandler";
	
	
	-- ENABLE --
	function enable return Boolean is
		ret: Boolean;
	begin
		ret := RCC.enable(RCC_SYSCFGCOMP);
		return ret;
	end disable;
	
	
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
							trigger: InterruptSource;
							callback: in not null InterruptCallback;
							priority: Integer;
							handle: out Integer) return Boolean is
		srcArray: SourceArrayType
		with Import, Convention => C, Address => InterruptSources.all'Address;
		
		src		: InterruptSource renames srcArray(InterruptSource'Pos(pin));
	begin
		handle := pin;
		if src.active = true then
			-- Already active EXTICRx entry. Possibly due to a pin on another port in use.
			-- TODO: set reason.
			return false;
		end if;
		
		-- Assign the new entry information and set the requested port in the SYSCFG EXTICR.
		src.port := port;
		src.pin := pin;
		src.trigger := trigger;
		src.callback := callback;
		src.priority := priority;
		src.syscfg.all.EXTICR(src.reg) := uint32_t(Unsigned_32(src.syscfg.all.EXTICR(src.reg)) or Shift_Left(port, src.offset));
		
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
		if stm32_type = 0 then
			src.irqType = EXTI4_15_IRQn;
			if pin = 0 or pin = 1 then
				src.irqType := EXTI0_1_IRQn;
				exti0_1_pwr := exti0_1_pwr + 1;
			elsif pin = 2 or pin = 3 then
				src.irqType := EXTI2_3_IRQn;
				exti2_3_pwr := exti2_3_pwr + 1;
			else
				exti4_15_pwr := exti4_15_pwr + 1;
			end if;
		elsif stm32_type = 4 or stm32_type = 7 then
			src.irqType := EXTI15_10_IRQn;
			if pin = 0 then
				src.irqType := EXTI0_IRQn;
			elsif pin = 1 then
				src.irqType := EXTI1_IRQn;
			elsif pin = 2 then
				src.irqType := EXTI2_IRQn;
			elsif pin = 3 then
				src.irqType := EXTI3_IRQn;
			elsif pin = 4 then
				src.irqType := EXTI4_IRQn;
			elsif pin > 4 and pin < 10 then
				src.irqType := EXTI9_5_IRQn;
				exti5_9_pwr := exti5_9_pwr + 1;
			elsif pin > 9 and pin < 16 then
				src.irqType := EXTI15_10_IRQn;
				exti5_9_pwr := exti10_15_pwr + 1;
			end if;
		end if;
		
		NVIC_SetPriority(src.irqType, priority); -- TODO
		NVIC_EnableIRQ(src.irqType);
	end setInterrupt;
	
	
	-- TRIGGER INTERRUPT --
	procedure triggerInterrupt is
	begin
	end triggerInterrupt;
	
	
	-- REMOVE INTERRUPT --
	function removeInterrupt(handle: Integer) return Boolean is
		srcArray: SourceArrayType
		with Import, Convention => C, Address => InterruptSources.all'Address;
		
		src		: InterruptSource renames srcArray(InterruptSource'Pos(pin));
		nvic_disable	: Boolean := false; -- Set to disable the interrupt.
	begin
		if src.active = false then
			-- Set reason.
			return false;
		end if;
		
		-- Set record to non-active.
		src.active := false;
		
		-- Disable the interrupt.
		if stm32_type = 0 then
			if src.irqType = EXTI0_1_IRQn then
				exti0_1_pwr := exti0_1_pwr - 1;
				if exti0_1_pwr /= 0 then
					nvic_disable := false;
				end if;
			elsif src.irqType = EXTI2_3_IRQn then
				exti2_3_pwr := exti2_3_pwr - 1;
				if exti2_3_pwr /= 0 then
					nvic_disable := false;
				end if;
			else
				exti4_15_pwr := exti4_15_pwr -1;
				if exti4_15_pwr /= 0 then
					nvic_disable := false;
				end if;
			end if;
		elsif stm32_type = 4 or stm32_type = 7 then
			if src.irqType = EXTI9_5_IRQn then
				exti5_9_pwr := exti5_9_pwr - 1;
				if exti5_9_pwr /= 0 then
					nvic_disable := false;
				end if;
			elsif src.irqType = EXTI15_10_IRQn then
				exti10_15_pwr := exti10_15_pwr - 1;
				if exti10_15_pwr /= 0 then
					nvic_disable := false;
				end if;
			end if;
		end if;
		
		if nvic_disable = true then
			NVIC_DisableIRQ(src.irqType);
		end if;
		
		-- Next reset the EXTI registers.
		src.exti.all.IMR := uint32_t(Unsigned_32(src.exti.all.IMR) and (not Shift_Left(1, src.pin)));
		src.exti.all.RTSR := uint32_t(Unsigned_32(src.exti.all.RTSR) and (not Shift_Left(1, src.pin)));
		src.exti.all.FTSR := uint32_t(Unsigned_32(src.exti.all.FTSR) and (not Shift_Left(1, src.pin)));
		
		-- Finally reset the SYSCFG register.
		src.syscfg.all.EXTICR(src.reg) := uint32_t(Unsigned_32(src.syscfg.all.EXTICR(src.reg)) and (not Shift_Left(16#F#, src.offset)));
		
		return true;
	end removeInterrupt;
	
end Interrupts;