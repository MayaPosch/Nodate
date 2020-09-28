------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUN-TIME COMPONENTS                         --
--                                                                          --
--                              G N A T . I O                               --
--                                                                          --
--                                 S p e c                                  --
--                                                                          --
--                     Copyright (C) 1995-2020, AdaCore                     --
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

--  A simple preelaborable subset of Text_IO capabilities

--  A simple text I/O package that can be used for simple I/O functions in
--  user programs as required. This package is also preelaborated, unlike
--  Text_IO, and can thus be with'ed by preelaborated library units.

--  Note that Data_Error is not raised by these subprograms for bad data.
--  If such checks are needed then the regular Text_IO package must be used.

--  This is the zfp version of GNAT.IO package

package GNAT.IO is
   pragma Preelaborate;

   procedure Put (X : Integer);
   --  Output integer to specified file, or to current output file, same
   --  output as if Ada.Text_IO.Integer_IO had been instantiated for Integer.

   procedure Put (C : Character);
   --  Output character to specified file, or to current output file

   procedure Put (S : String);
   --  Output string to specified file, or to current output file

   procedure Put_Line (S : String);
   --  Output string followed by new line to specified file, or to
   --  current output file.

   procedure New_Line (Spacing : Positive := 1);
   --  Output new line character to specified file, or to current output file

end GNAT.IO;
