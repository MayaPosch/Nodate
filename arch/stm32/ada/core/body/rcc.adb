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
		perArray: PeripheralArray
		with Import, Convention => C, Address => perHandlesStatic.all'Address;
		
		ph		: RccPeripheralHandle renames perArray(RccPeripheral'Pos(peripheral));
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
	-- Disable the target peripheral.
	-- Returns true if the request was received but not processed due to outstanding handles, or
	-- if the peripheral was successfully disabled.
	-- Returns false if the request was rejected or disabling the peripheral failed.
	function disable(peripheral: RccPeripheral) return Boolean is
		perArray: PeripheralArray
		with Import, Convention => C, Address => perHandlesStatic.all'Address;
		
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
	-- Returns true if the port was already enabled, or was successfully enabled.
	-- Returns false if the port could not be enabled.
	function enablePort(port: RccPort) return Boolean is
		portArray: PortArrayType
		with Import, Convention => C, Address => portHandlesStatic.all'Address;
		
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
	-- Returns true if the port is already disabled, if the request was accepted, or port disabled.
	-- Returns false if the request was rejected, or the port could not be disabled.
	function disablePort(port: RccPort) return Boolean is
		portArray: PortArrayType
		with Import, Convention => C, Address => portHandlesStatic.all'Address;
		
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