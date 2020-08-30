--
-- rcc.adb - Body for the RCC functionality.
--

with Interfaces; use Interfaces;
with Interfaces.C; use Interfaces.C;
with Interfaces.C.Extensions;
with stdint_h; use stdint_h;
with stm32_h; use stm32_h;


package body RCC is
	use Class_RccPeripheralHandle;
	use Class_RccPortHandle;
	type PeripheralRange is range 0 .. 50;
	type PeripheralArray is array(PeripheralRange) of aliased RccPeripheralHandle;
	type PortRange is range 0 .. 50;
	type PortArrayType is array(PortRange) of aliased RccPortHandle;
		
		
	-- ENABLE --
	-- Enable the target peripheral. 
	-- Returns true if the peripheral was successfully enabled, or if the peripheral was already on.
	-- Returns false if the peripheral could not be enabled. 
	function enable(peripheral: RccPeripheral) return Boolean is
		-- peripheralCount: Integer
		-- with Import, Convention => C;
		
		perArray: PeripheralArray
		--perArray: array(1 .. peripheralCount) of aliased RccPeripheralHandle;
		--for perArray'Address use perHandlesStatic'Address;
		with Import, Convention => C, Address => perHandlesStatic.all'Address;
		
		--perNum	: Integer := Integer(peripheral);
		ph		: RccPeripheralHandle renames perArray(RccPeripheral'Pos(peripheral));
		--N : constant Natural := 1;
	begin
		if ph.exists = false then
			-- TODO: set reason.
			return false;
		end if;
		
		-- Check the current peripheral status.
		if ph.count > 0 then
			if ph.count >= 255 then
				-- Reached maximum handles. Return false to prevent counter overflow.
				-- TODO: set reason.
				return false;
			end if;
		else
			ph.count := 1;
			ph.enr.all := uint32_t(Unsigned_32(ph.enr.all) or Shift_Left(1, Integer(ph.enable)));
		end if;
		
		return true;
	end enable;
	
	
	-- DISABLE --
	function disable(peripheral: RccPeripheral) return Boolean is
		--perArray: array(Integer range <>) of aliased RccPeripheralHandle
		perArray: PeripheralArray
		with Import, Convention => C, Address => perHandlesStatic.all'Address;
		
		--perNum	: Integer := Integer(peripheral);
		ph		: RccPeripheralHandle renames perArray(RccPeripheral'Pos(peripheral));
	begin
		if ph.exists = false then
			-- TODO: set reason.
			return false;
		end if;
		
		if ph.count > 1 then
			-- Decrease handle count by one.
			ph.count := ph.count - 1;
		else
			-- Deactivate the peripheral.
			ph.count := 0;
			ph.enr.all := uint32_t(Unsigned_32(ph.enr.all) and (not Shift_Left(1, Integer(ph.enable))));
		end if;
		
		return true;
	end disable;
	
	
	-- ENABLE PORT --
	function enablePort(port: RccPort) return Boolean is
		--portArray: array(Integer range <>) of aliased RccPortHandle
		portArray: PortArrayType
		with Import, Convention => C, Address => portHandlesStatic.all'Address;
		
		--portNum	: Integer := Integer(port);
		ph		: RccPortHandle renames portArray(RccPort'Pos(port));
	begin
		if ph.exists = false then
			-- TODO: set reason.
			return false;
		end if;
		
		-- Check current port status.
		if ph.count > 0 then
			if ph.count >= 255 then
				-- Reached maximum handles. Return false to prevent counter overflow.
				-- TODO: set reason.
				return false;
			end if;
			
			-- Increase handler count by one.
			ph.count := ph.count + 1;
		else
			-- Activate the port.
			ph.count := 1;
			ph.enr.all := uint32_t(Unsigned_32(ph.enr.all) or Shift_Left(1, Integer(ph.enable)));
		end if;
		
		return true;
	end enablePort;
	
	
	-- DISABLE PORT --
	function disablePort(port: RccPort) return Boolean is
		--portArray: array(Integer range <>) of aliased RccPortHandle
		portArray: PortArrayType
		with Import, Convention => C, Address => portHandlesStatic.all'Address;
		
		--portNum	: Integer := Integer(peripheral);
		ph		: RccPortHandle renames portArray(RccPort'Pos(port));
	begin
		if ph.exists = false then
			-- TODO: set reason.
			return false;
		end if;
		
		if ph.count > 1 then
			-- Decrease handle count by one.
			ph.count := ph.count - 1;
		else
			-- Deactivate the port.
			ph.count := 0;
			ph.enr.all := uint32_t(Unsigned_32(ph.enr.all) and (not Shift_Left(1, Integer(ph.enable))));
		end if;
		
		return true;
	end disablePort;
	
end RCC;