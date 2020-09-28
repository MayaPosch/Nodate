------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUN-TIME COMPONENTS                         --
--                                                                          --
--                              G N A T . I O                               --
--                                                                          --
--                                 B o d y                                  --
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

package body GNAT.IO is

   procedure Put (C : Character) is separate;

   --------------
   -- New_Line --
   --------------

   procedure New_Line (Spacing : Positive := 1) is
   begin
      for J in 1 .. Spacing loop
         Put (ASCII.LF);
      end loop;
   end New_Line;

   ---------
   -- Put --
   ---------

   procedure Put (X : Integer) is
      Int   : Integer;
      S     : String (1 .. Integer'Width);
      First : Natural := S'Last + 1;
      Val   : Integer;

   begin
      --  Work on negative values to avoid overflows
      Int := (if X < 0 then X else -X);

      loop
         --  Cf RM 4.5.5 Multiplying Operators.  The rem operator will return
         --  negative values for negative values of Int.
         Val := Int rem 10;
         Int := (Int - Val) / 10;
         First := First - 1;
         S (First) := Character'Val (Character'Pos ('0') - Val);
         exit when Int = 0;
      end loop;

      if X < 0 then
         First := First - 1;
         S (First) := '-';
      end if;

      Put (S (First .. S'Last));
   end Put;

   ---------
   -- Put --
   ---------

   procedure Put (S : String) is
   begin
      for J in S'Range loop
         Put (S (J));
      end loop;
   end Put;

   --------------
   -- Put_Line --
   --------------

   procedure Put_Line (S : String) is
   begin
      Put (S);
      New_Line;
   end Put_Line;

end GNAT.IO;
