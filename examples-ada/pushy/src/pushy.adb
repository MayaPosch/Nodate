-- Basic Pushy example for Nodate's STM32 framework.

with GPIO;


procedure main is
	led_builtin	: gpio_pin := 3;
	button_pin	: gpio_pin := 1;
	button_down	: Integer;
	
begin
	-- Set pin mode on the built-in LED.
	gpio.set_output();
	gpio.write();
	
	-- Set input mode on PB1 pin.
	gpio.set_input();
	
	loop;
		button_down := gpio.read();
		if button_down = 0 then
			gpio.write();
		else
			gpio.write();
		end if;
	end loop;

end main;
