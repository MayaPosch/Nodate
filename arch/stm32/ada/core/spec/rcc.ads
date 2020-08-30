--
-- rcc.ads - Specification for the RCC functionality.
--

with stm32_h; use stm32_h;

package RCC is
	function enable(peripheral: RccPeripheral) return Boolean;
	function disable(peripheral: RccPeripheral) return Boolean;
	function enablePort(port: RccPort) return Boolean;
	function disablePort(port: RccPort) return Boolean;
end RCC;