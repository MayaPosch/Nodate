--
-- gpio.adb - Body for the GPIO functionality.
--


with RCC;
with stm32_h; use stm32_h;
with stdint_h; use stdint_h;
with Interfaces; use Interfaces;
with Interfaces.C; use Interfaces.C;


package body GPIO is
	use Class_GPIO_instance;
	type PortRange is range 0 .. 50;
	type PortArrayType is array(PortRange) of aliased GPIO_instance;

	-- SET INPUT --
	function set_input(port: GPIO_ports; pin: Integer; pupd: GPIO_pupd) return Boolean is
		portArray: PortArrayType
		with Import, Convention => C, Address => instancesStatic.all'Address;
		
		instance	: GPIO_instance renames portArray(GPIO_ports'Pos(port));
		pin2		: Integer := pin * 2;
	begin
		-- Validate pin.
		if pin > 15 then
			return false;
		end if;
		
		-- Check if port is active. If not, try to activate it.
		if instance.active = false then
			if RCC.enablePort(RccPort'Val(GPIO_ports'Pos(port))) = true then
				instance.active := true;
			else
				return false;
			end if;
		end if;
			
		-- Set parameters.
		instance.regs.all.MODER := uint32_t(Unsigned_32(instance.regs.all.MODER) and (not Shift_Left(3, pin2)));
		instance.regs.all.PUPDR := uint32_t(Unsigned_32(instance.regs.all.PUPDR) and (not Shift_Left(3, pin2)));
		if pupd = GPIO_PULL_UP then
			instance.regs.all.PUPDR := uint32_t(Unsigned_32(instance.regs.all.PUPDR) or Shift_Left(1, pin2));
		else
			instance.regs.all.PUPDR := uint32_t(Unsigned_32(instance.regs.all.PUPDR) or Shift_Left(2, pin2));
		end if;
		
		return true;
	end set_input;
	
	
	-- SET OUTPUT --
	function set_output(port	: 	GPIO_ports; 
						pin		: 	Integer; 
						pupd	: 	GPIO_pupd := GPIO_FLOATING; 
						out_type: 	GPIO_out_type := GPIO_PUSH_PULL;
						speed	: 	GPIO_out_speed := GPIO_LOW) return Boolean is
		portArray: PortArrayType
		with Import, Convention => C, Address => instancesStatic.all'Address;
		
		instance	: GPIO_instance renames portArray(GPIO_ports'Pos(port));
		pin2		: Integer := pin * 2;
	begin
		-- Validate pin.
		if pin > 15 then
			return false;
		end if;
		
		-- Check if port is active. If not, try to activate it.
		if instance.active = false then
			if RCC.enablePort(RccPort'Val(GPIO_ports'Pos(port))) = true then
				instance.active := true;
			else
				return false;
			end if;
		end if;
		
		-- Set parameters.
		instance.regs.all.MODER := uint32_t(Unsigned_32(instance.regs.all.MODER) and (not Shift_Left(3, pin2)));
		instance.regs.all.MODER := uint32_t(Unsigned_32(instance.regs.all.MODER) or (Shift_Left(1, pin2)));
		
		instance.regs.all.PUPDR := uint32_t(Unsigned_32(instance.regs.all.PUPDR) and (not Shift_Left(3, pin2)));
		if pupd = GPIO_PULL_UP then
			instance.regs.all.PUPDR := uint32_t(Unsigned_32(instance.regs.all.PUPDR) or Shift_Left(1, pin2));
		elsif pupd = GPIO_PULL_DOWN then
			instance.regs.all.PUPDR := uint32_t(Unsigned_32(instance.regs.all.PUPDR) or Shift_Left(2, pin2));
		end if;
		
		if out_type = GPIO_PUSH_PULL then
			instance.regs.all.OTYPER := uint32_t(Unsigned_32(instance.regs.all.OTYPER) and (not Shift_Left(1, pin)));
		elsif out_type = GPIO_OPEN_DRAIN then
			instance.regs.all.OTYPER := uint32_t(Unsigned_32(instance.regs.all.OTYPER) or Shift_Left(1, pin));
		end if;
		
		if speed = GPIO_LOW then
			instance.regs.all.OSPEEDR := uint32_t(Unsigned_32(instance.regs.all.OSPEEDR) and (not Shift_Left(3, pin2)));
		elsif speed = GPIO_MID then
			instance.regs.all.OSPEEDR := uint32_t(Unsigned_32(instance.regs.all.OSPEEDR) and (not Shift_Left(3, pin2)));
			instance.regs.all.OSPEEDR := uint32_t(Unsigned_32(instance.regs.all.OSPEEDR) or Shift_Left(1, pin2));
		elsif speed = GPIO_HIGH then
			instance.regs.all.OSPEEDR := uint32_t(Unsigned_32(instance.regs.all.OSPEEDR) and (not Shift_Left(3, pin2)));
			instance.regs.all.OSPEEDR := uint32_t(Unsigned_32(instance.regs.all.OSPEEDR) or Shift_Left(1, pin2));
		end if;
		
		return true;			
	end set_output;
						
	
	-- WRITE --
	function write(port: GPIO_ports; pin: Integer; level: GPIO_level) return Boolean is
		portArray: PortArrayType
		with Import, Convention => C, Address => instancesStatic.all'Address;
		
		instance	: GPIO_instance renames portArray(GPIO_ports'Pos(port));
	begin
		-- Validate pin.
		if pin > 15 then
			return false;
		end if;
		
		-- Check if port is active. If not, try to activate it.
		if instance.active = false then
			if RCC.enablePort(RccPort'Val(GPIO_ports'Pos(port))) = true then
				instance.active := true;
			else
				return false;
			end if;
		end if;
		
		-- Write to pin.
		if level = GPIO_LEVEL_LOW then
			instance.regs.all.ODR := uint32_t(Unsigned_32(instance.regs.all.ODR) and (not Shift_Left(1, pin)));
		elsif level = GPIO_LEVEL_HIGH then
			instance.regs.all.ODR := uint32_t(Unsigned_32(instance.regs.all.ODR) or Shift_Left(1, pin));
		end if;
		
		return true;
	end write;
	
	
	-- WRITE --
	function write(port: GPIO_ports; pin: Integer; level: Integer) return Boolean is
	begin
		return true;
	end write;
	
	
	-- READ --
	function read(port: GPIO_ports; pin: Integer) return Integer is
		portArray: PortArrayType
		with Import, Convention => C, Address => instancesStatic.all'Address;
		
		instance	: GPIO_instance renames portArray(GPIO_ports'Pos(port));
		idr			: Unsigned_32;
		output		: Unsigned_32;
		mask_base	: Unsigned_32	:= 1;
	begin
		-- Validate pin.
		if pin > 15 then
			return 0;
		end if;
		
		-- Check if port is active. If not, try to activate it.
		if instance.active = false then
			if RCC.enablePort(RccPort'Val(GPIO_ports'Pos(port))) = true then
				instance.active := true;
			else
				return 0;
			end if;
		end if;
		
		-- Read from pin.
		idr := Unsigned_32(instance.regs.all.IDR);
		output := Shift_Right(idr, pin) and mask_base;
		
		return Integer(output);
	end read;
	
	
	-- READ ANALOG --
	function readAnalog(port: GPIO_ports; pin: Integer) return Integer is
	begin
		return 0;
	end readAnalog;
	
end GPIO;
