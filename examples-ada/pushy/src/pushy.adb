-- Basic Pushy example for Nodate's STM32 framework.


with GPIO;
with stm32_h; use stm32_h;


procedure pushy is
	led_pin		: Integer 		:= 3; --  Nucleo-f042k6: Port B, pin 4 (D12).
	led_port	: GPIO_ports	:= GPIO_PORT_B;
	--led_pin		: Integer		:= 13; --  STM32F4-Discovery: Port D, pin 13 (orange)
	--led_port	: GPIO_ports	:= GPIO_PORT_D;
	--led_pin		: Integer		:= 7; -- Nucleo-F746ZG: Port B, pin 7 (blue)
	--led_port	: GPIO_ports	:= GPIO_PORT_B;
	
	button_pin	: Integer 		:= 1; -- Nucleo-f042k6 (PB1)
	button_port	: GPIO_ports	:= GPIO_PORT_B;
	--button_pin	: Integer		:= 0; -- STM32F4-Discovery (PA0)
	--button_port	: GPIO_ports	:= GPIO_PORT_A;
	--button_pin	: Integer		:= 13; -- Nucleo-F746ZG (PC13)
	--button_port	: GPIO_ports	:= GPIO_PORT_C;
	
	button_down	: Integer;
	ret			: Boolean;
begin
	-- Set pin mode on the built-in LED.
	ret := gpio.set_output(led_port, led_pin, GPIO_PULL_UP);
	ret := gpio.write(led_port, led_pin, GPIO_LEVEL_LOW);
	
	-- Set input mode on PB1 pin.
	ret := gpio.set_input(button_port, button_pin, GPIO_FLOATING);
	
	-- If the button pulls down to ground (high to low), 'button_down' is low when pushed.
	-- If the button is pulled up to Vdd (low to high), 'button_down' is high when pushed.
	loop
		button_down := gpio.read(button_port, button_pin);
		if button_down = 0 then
			ret := gpio.write(led_port, led_pin, GPIO_LEVEL_HIGH);
		else
			ret := gpio.write(led_port, led_pin, GPIO_LEVEL_LOW);
		end if;
	end loop;

end pushy;
