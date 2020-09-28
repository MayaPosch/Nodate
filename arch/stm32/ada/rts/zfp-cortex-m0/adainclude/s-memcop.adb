------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUN-TIME COMPONENTS                         --
--                                                                          --
--                     S Y S T E M .  M E M O R Y _ C O P Y                 --
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

package body System.Memory_Copy is

   ------------
   -- memcpy --
   ------------

   function memcpy
     (Dest : Address; Src : Address; N : size_t) return Address
   is
      D : IA     := To_IA (Dest);
      S : IA     := To_IA (Src);
      C : size_t := N;

   begin
      --  Try to copy per word, if alignment constraints are respected

      if ((D or S) and (Word'Alignment - 1)) = 0 then
         while C >= Word_Unit loop
            To_Word_Ptr (D).all := To_Word_Ptr (S).all;
            D := D + Word_Unit;
            S := S + Word_Unit;
            C := C - Word_Unit;
         end loop;
      end if;

      --  Copy the remaining byte per byte

      while C > 0 loop
         To_Byte_Ptr (D).all := To_Byte_Ptr (S).all;
         D := D + Byte_Unit;
         S := S + Byte_Unit;
         C := C - Byte_Unit;
      end loop;

      return Dest;
   end memcpy;

end System.Memory_Copy;
