
with Ada.Text_IO; use Ada.Text_IO;


package body interrupts_callbacks is
	procedure callback is
		--
	begin
		Put_Line("Received interrupt...");
	end callback;
end interrupts_callbacks;