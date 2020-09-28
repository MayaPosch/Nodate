------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUN-TIME COMPONENTS                         --
--                                                                          --
--                   S Y S T E M .  M E M O R Y _ T Y P E S                 --
--                                                                          --
--                                 S p e c                                  --
--                                                                          --
--              Copyright (C) 2017-2020, Free Software Foundation, Inc.     --
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

with Ada.Unchecked_Conversion;

package System.Memory_Types is
   pragma No_Elaboration_Code_All;
   pragma Preelaborate;

   type size_t is mod 2 ** Standard'Address_Size;
   --  The type corresponding to size_t in C. We cannot reuse the one defined
   --  in Interfaces.C as we want this package not to have any elaboration
   --  code.

   type IA is mod System.Memory_Size;
   --  The type used to provide the actual desired operations

   function To_IA is new Ada.Unchecked_Conversion (Address, IA);
   --  The operations are implemented by unchecked conversion to type IA,
   --  followed by doing the intrinsic operation on the IA values, followed
   --  by converting the result back to type Address.

   type Byte is mod 2 ** 8;
   for Byte'Size use 8;
   --  Byte is the storage unit

   type Byte_Ptr is access Byte;
   --  Access to a byte

   function To_Byte_Ptr is new Ada.Unchecked_Conversion (IA, Byte_Ptr);
   --  Conversion between an integer address and access to byte

   Byte_Unit : constant := 1;
   --  Number of storage unit in a byte

   type Word is mod 2 ** System.Word_Size;
   for Word'Size use System.Word_Size;
   --  Word is efficiently loaded and stored by the processor, but has
   --  alignment constraints.

   type Word_Ptr is access Word;
   --  Access to a word.

   function To_Word_Ptr is new Ada.Unchecked_Conversion (IA, Word_Ptr);
   --  Conversion from an integer address to word access

   Word_Unit : constant := Word'Size / Storage_Unit;
   --  Number of storage unit per word
end System.Memory_Types;
