

package body stm32_h is
	exti0_1_pwr 	: Integer	:= 0;
	exti2_3_pwr 	: Integer	:= 0;
	exti4_15_pwr 	: Integer	:= 0;
	
	
	-- SET IRQ TYPE --
	procedure setIrqType(irqType: out IRQn_Type; pin: Integer) is
		--
	begin
		irqType := EXTI4_15_IRQn;
		if pin = 0 or pin = 1 then
			irqType := EXTI0_1_IRQn;
			exti0_1_pwr := exti0_1_pwr + 1;
		elsif pin = 2 or pin = 3 then
			irqType := EXTI2_3_IRQn;
			exti2_3_pwr := exti2_3_pwr + 1;
		else
			exti4_15_pwr := exti4_15_pwr + 1;
		end if;
	end setIrqType;
	
	
	-- CHECK IRQ DISABLE --
	procedure checkIrqDisable(irqType: in IRQn_Type; nvic_disable: out Boolean) is
		--
	begin
		if irqType = EXTI0_1_IRQn then
			exti0_1_pwr := exti0_1_pwr - 1;
			if exti0_1_pwr /= 0 then
				nvic_disable := false;
			end if;
		elsif irqType = EXTI2_3_IRQn then
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
	end checkIrqDisable;
		
end stm32_h;