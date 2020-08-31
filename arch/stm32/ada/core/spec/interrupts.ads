--
-- interrupts.ads - Specification for the Interrupts functionality.
--

with stm32_h; use stm32_h;
with Interfaces; use Interfaces;
with Interfaces.C; use Interfaces.C;
with GPIO;

package Interrupts is
	type InterruptCallback is access procedure;
	
	type InterruptTrigger is
		(INTERRUPT_TRIGGER_NONE,
		INTERRUPT_TRIGGER_RISING,
		INTERRUPT_TRIGGER_FALLING,
		INTERRUPT_TRIGGER_BOTH)
	with Convention => C;

	type InterruptSource is record
		active	: aliased Boolean;
		port	: aliased GPIO_ports;
		pin		: aliased Unsigned_8;
		trigger	: aliased InterruptTrigger;
		irqType	: aliased IRQn_Type;
		priority: aliased Unsigned_8;
		exti	: access EXTI_TypeDef;
		syscfg	: access SYSCFG_TypeDef;
		reg		: aliased Unsigned_8;
		offset	: aliased Unsigned_32;
		callback: access InterruptCallback;
	end record
	with Convention => C;

	function enable return Boolean;
	function disable return Boolean;
	function setInterrupt(	pin: Integer; 
							port: GPIO_ports; 
							trigger: InterruptSource;
							callback: in not null InterruptCallback;
							priority: Integer;
							handle: out Integer) return Boolean;
	procedure triggerInterrupt;
	function removeInterrupt(handle: Integer) return Boolean;
end Interrupts;