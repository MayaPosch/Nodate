------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUN-TIME COMPONENTS                         --
--                                                                          --
--                     S Y S T E M .  M E M O R Y _ S E T                   --
--                                                                          --
--                                 B o d y                                  --
--                                                                          --
--            Copyright (C) 2006-2020, Free Software Foundation, Inc.       --
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

with System; use System;
with System.Memory_Types; use System.Memory_Types;

package body System.Memory_Set is

   function Shift_Left (V : Word; Amount : Natural) return Word;
   pragma Import (Intrinsic, Shift_Left);

   ------------
   -- memset --
   ------------

   function memset (M : Address; C : Integer; Size : size_t) return Address is
      B  : constant Byte := Byte (C mod 256);
      D  : IA     := To_IA (M);
      N  : size_t := Size;
      CW : Word;

   begin
      --  Try to set per word, if alignment constraints are respected

      if (D and (Word'Alignment - 1)) = 0 then
         CW := Word (B);
         CW := Shift_Left (CW, 8) or CW;
         CW := Shift_Left (CW, 16) or CW;

         --  For 64 bit machine (condition is always true/false)
         pragma Warnings (Off);
         if Word_Unit > 4 then
            CW := Shift_Left (CW, 32) or CW;
         end if;
         pragma Warnings (On);

         while N >= Word_Unit loop
            To_Word_Ptr (D).all := CW;
            N := N - Word_Unit;
            D := D + Word_Unit;
         end loop;
      end if;

      --  Set the remaining byte per byte

      while N > 0 loop
         To_Byte_Ptr (D).all := B;
         N := N - Byte_Unit;
         D := D + Byte_Unit;
      end loop;

      return M;
   end memset;

end System.Memory_Set;
