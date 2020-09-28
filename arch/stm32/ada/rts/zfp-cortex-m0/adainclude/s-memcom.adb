------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUN-TIME COMPONENTS                         --
--                                                                          --
--                  S Y S T E M .  M E M O R Y _ C O M P A R E              --
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

with System.Memory_Types; use System.Memory_Types;

package body System.Memory_Compare is

   ------------
   -- memcmp --
   ------------

   function memcmp (S1 : Address; S2 : Address; N : size_t) return Integer is
      S1_A  : IA := To_IA (S1);
      S2_A  : IA := To_IA (S2);
      C     : size_t := N;
      V1, V2 : Byte;

   begin
      --  Try to compare word by word if alignment constraints are respected.
      --  Compare as long as words are equal.

      if ((S1_A or S2_A) and (Word'Alignment - 1)) = 0 then
         while C >= Word_Unit loop
            exit when To_Word_Ptr (S1_A).all /= To_Word_Ptr (S2_A).all;
            S1_A := S1_A + Word_Unit;
            S2_A := S2_A + Word_Unit;
            C := C - Word_Unit;
         end loop;
      end if;

      --  Finish byte per byte

      while C > 0 loop
         V1 := To_Byte_Ptr (S1_A).all;
         V2 := To_Byte_Ptr (S2_A).all;
         if V1 < V2 then
            return -1;
         elsif V1 > V2 then
            return 1;
         end if;

         S1_A := S1_A + Byte_Unit;
         S2_A := S2_A + Byte_Unit;
         C := C - Byte_Unit;
      end loop;

      return 0;
   end memcmp;

end System.Memory_Compare;
