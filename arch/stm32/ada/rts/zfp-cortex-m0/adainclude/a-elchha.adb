------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUN-TIME COMPONENTS                         --
--                                                                          --
--    A D A . E X C E P T I O N S . L A S T _ C H A N C E _ H A N D L E R   --
--                                                                          --
--                                 B o d y                                  --
--                                                                          --
--          Copyright (C) 2012-2020, Free Software Foundation, Inc.         --
--                                                                          --
-- GNAT is free software;  you can  redistribute it  and/or modify it under --
-- terms of the  GNU General Public License as published  by the Free Soft- --
-- ware  Foundation;  either version 3,  or (at your option) any later ver- --
-- sion.  GNAT is distributed in the hope that it will be useful, but WITH- --
-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
-- or FITNESS FOR A PARTICULAR PURPOSE.                                     --
--                                                                          --
--                                                                          --
--                                                                          --
--                                                                          --
--                                                                          --
-- You should have received a copy of the GNU General Public License and    --
-- a copy of the GCC Runtime Library Exception along with this program;     --
-- see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see    --
-- <http://www.gnu.org/licenses/>.                                          --
--                                                                          --
-- GNAT was originally developed  by the GNAT team at  New York University. --
-- Extensive contributions were provided by Ada Core Technologies Inc.      --
--                                                                          --
------------------------------------------------------------------------------

--  Default last chance handler for no propagation runtimes

with Ada.Unchecked_Conversion;
with System.Machine_Reset;

with GNAT.IO; use GNAT.IO;
--  We rely on GNAT packages for the output. Usually, Ada predefined units
--  cannot depends on GNAT units, as the user could use the GNAT hierarchy.
--  However, this implementation of Last_Chance_Handler is a default one, that
--  could be redefined by the user.

procedure Ada.Exceptions.Last_Chance_Handler
  (Msg : System.Address; Line : Integer)
is
   procedure Put (Str : System.Address);
   --  Put for a nul-terminated string (a C string)

   ---------
   -- Put --
   ---------

   procedure Put (Str : System.Address) is
      type C_String_Ptr is access String (1 .. Positive'Last);
      function To_C_String_Ptr is new Ada.Unchecked_Conversion
        (System.Address, C_String_Ptr);

      Msg_Str : constant C_String_Ptr := To_C_String_Ptr (Str);

   begin
      for J in Msg_Str'Range loop
         exit when Msg_Str (J) = Character'Val (0);
         Put (Msg_Str (J));
      end loop;
   end Put;

begin
   Put_Line ("In last chance handler");

   if Line /= 0 then
      Put ("Predefined exception raised at ");
      Put (Msg);
      Put (':');
      Put (Line);
   else
      Put ("User defined exception, message: ");
      Put (Msg);
   end if;

   New_Line;

   --  Stop the program

   System.Machine_Reset.Stop;
end Ada.Exceptions.Last_Chance_Handler;
