------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUN-TIME COMPONENTS                         --
--                                                                          --
--                           G N A T . I O . P U T                          --
--                                                                          --
--                                 B o d y                                  --
--                                                                          --
--                     Copyright (C) 2011-2020, AdaCore                     --
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

--  Implementation of Put (C : Character) based on System.Text_IO.

with System.Text_IO; use System.Text_IO;

separate (GNAT.IO)
procedure Put (C : Character) is
begin
   if not Initialized then
      Initialize;
   end if;

   --  GNAT.IO calls Put (ASCII.LF) for New_Line. Compensate.
   if C = ASCII.LF and then Use_Cr_Lf_For_New_Line then
      while not Is_Tx_Ready loop
         null;
      end loop;

      System.Text_IO.Put (ASCII.CR);
   end if;

   while not Is_Tx_Ready loop
      null;
   end loop;

   System.Text_IO.Put (C);
end Put;
