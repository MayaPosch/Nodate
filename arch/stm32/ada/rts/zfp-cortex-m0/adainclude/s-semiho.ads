------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUN-TIME COMPONENTS                         --
--                                                                          --
--                    S Y S T E M . S E M I H O S T I N G                   --
--                                                                          --
--                                 S p e c                                  --
--                                                                          --
--            Copyright (C) 2017-2020, Free Software Foundation, Inc.       --
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

--  Semihosting is a mechanism that enables I/O between target and host
--  computer using the debugger. Although based on ARM definition of
--  semihosting, the features described here can be implemented on virtually
--  any platform.

package System.Semihosting is
   pragma No_Elaboration_Code_All;
   pragma Preelaborate;

   procedure Put (Item : Character);
   --  Put a character on the console

   procedure Put (Item : String);
   --  Put a string on the console

   procedure Get (Item : out Character);
   --  Get one character from the console

end System.Semihosting;
