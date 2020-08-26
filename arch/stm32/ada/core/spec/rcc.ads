--
-- rcc.ads - Specification for the RCC functionality.
--

with stm32;
use stm32;

package RCC is
	function enable(peripheral: RccPeripheral) return Boolean;
	function disable(peripheral: RccPeripheral) return Boolean;
	function enablePort(port: RccPort) return Boolean;
	function disablePort(port: RccPort) return Boolean;
end RCC;