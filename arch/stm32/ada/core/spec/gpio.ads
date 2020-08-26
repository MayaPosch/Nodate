--
-- gpio.ads - Specification for the GPIO functionality.
--

with stm32;
use stm32;

package GPIO is
	function set_input(port: GPIO_ports; pin: Integer; pupd: GPIO_pupd) return Boolean;
	function set_output(port	: 	GPIO_ports; 
						pin		: 	Integer; 
						pupd	: 	GPIO_pupd := GPIO_FLOATING; 
						out_type: 	GPIO_out_type := GPIO_PUSH_PULL;
						speed	: 	GPIO_out_speed := GPIO_LOW) return Boolean;
	function write(port: GPIO_ports; pin: Integer; level: GPIO_level) return Boolean;
	function write(port: GPIO_ports; pin: Integer; level: Integer) return Boolean;
	function read(port: GPIO_ports; pin: Integer) return Integer;
	function readAnalog() return Integer;
	
private
	--
end GPIO;
