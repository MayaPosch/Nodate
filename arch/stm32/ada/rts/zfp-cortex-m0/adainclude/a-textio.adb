------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUN-TIME COMPONENTS                         --
--                                                                          --
--                          A D A . T E X T _ I O                           --
--                                                                          --
--                                 B o d y                                  --
--                                                                          --
--             Copyright (C) 2017-2020, Free Software Foundation, Inc.      --
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
-- In particular,  you can freely  distribute your programs  built with the --
-- GNAT Pro compiler, including any required library run-time units,  using --
-- any licensing terms  of your choosing.  See the AdaCore Software License --
-- for full details.                                                        --
--                                                                          --
-- GNAT was originally developed  by the GNAT team at  New York University. --
-- Extensive contributions were provided by Ada Core Technologies Inc.      --
--                                                                          --
------------------------------------------------------------------------------

--  Version for semihosting, a mechanism that enables I/O between target and
--  host computer using the debugger.

with System.Semihosting;

package body Ada.Text_IO is

   ---------
   -- Get --
   ---------

   procedure Get (C : out Character) is
   begin
      System.Semihosting.Get (C);
   end Get;

   --------------
   -- New_Line --
   --------------

   procedure New_Line is
   begin
      System.Semihosting.Put (ASCII.CR & ASCII.LF);
   end New_Line;

   ---------
   -- Put --
   ---------

   procedure Put (Item : Character) is
   begin
      System.Semihosting.Put (Item);
   end Put;

   procedure Put (Item : String) is
   begin
      System.Semihosting.Put (Item);
   end Put;

   --------------
   -- Put_Line --
   --------------

   procedure Put_Line (Item : String) is
   begin
      System.Semihosting.Put (Item & ASCII.CR & ASCII.LF);
   end Put_Line;
end Ada.Text_IO;
