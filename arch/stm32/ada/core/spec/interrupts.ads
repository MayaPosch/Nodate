--
-- interrupts.ads - Specification for the Interrupts functionality.
--

with stm32_h; use stm32_h;

with Interfaces; use Interfaces;
with Interfaces.C; use Interfaces.C;
with GPIO;

package Interrupts is
	function enable return Boolean;
	function disable return Boolean;
	function setInterrupt(	pin: Integer; 
							port: GPIO_ports; 
							trigger: InterruptTrigger;
							callback: in not null InterruptCallback;
							priority: Integer;
							handle: out Integer) return Boolean;
	procedure triggerInterrupt;
	function removeInterrupt(handle: Integer) return Boolean;
	
	-- ISRs --
	-- STM32F0
	procedure EXTI0_1_IRQHandler
	with Export, Convention => C, External_Name => "EXTI0_1_IRQHandler";
	procedure EXTI2_3_IRQHandler
	with Export, Convention => C, External_Name => "EXTI2_3_IRQHandler";
	procedure EXTI4_15_IRQHandler
	with Export, Convention => C, External_Name => "EXTI4_15_IRQHandler";
	-- STM32F4/F7
	procedure EXTI0_IRQHandler
	with Export, Convention => C, External_Name => "EXTI0_IRQHandler";
	procedure EXTI1_IRQHandler
	with Export, Convention => C, External_Name => "EXTI1_IRQHandler";
	procedure EXTI2_IRQHandler
	with Export, Convention => C, External_Name => "EXTI2_IRQHandler";
	procedure EXTI3_IRQHandler
	with Export, Convention => C, External_Name => "EXTI3_IRQHandler";
	procedure EXTI4_IRQHandler
	with Export, Convention => C, External_Name => "EXTI4_IRQHandler";
	procedure EXTI9_5_IRQHandler
	with Export, Convention => C, External_Name => "EXTI9_5_IRQHandler";
	procedure EXTI15_10_IRQHandler
	with Export, Convention => C, External_Name => "EXTI15_10_IRQHandler";
end Interrupts;