------------------------------------------------------------------------------
--                                                                          --
--                         GNAT COMPILER COMPONENTS                         --
--                                                                          --
--                    S Y S T E M . P A R A M E T E R S                     --
--                                                                          --
--                                 S p e c                                  --
--                                                                          --
--          Copyright (C) 1992-2020, Free Software Foundation, Inc.         --
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

--  This is a small memory zfp version the package

--  This package defines some system dependent parameters for GNAT. These
--  are values that are referenced by the runtime library and are therefore
--  relevant to the target machine.

--  The parameters whose value is defined in the spec are not generally
--  expected to be changed. If they are changed, it will be necessary to
--  recompile the run-time library.

--  The parameters which are defined by functions can be changed by modifying
--  the body of System.Parameters in file s-parame.adb. A change to this body
--  requires only rebinding and relinking of the application.

--  Note: do not introduce any pragma Inline statements into this unit, since
--  otherwise the relinking and rebinding capability would be deactivated.

package System.Parameters is
   pragma Pure;

   ------------------------------
   -- Stack Allocation Control --
   ------------------------------

   type Size_Type is range
     -(2 ** (Integer'(Standard'Address_Size) - 1)) ..
     +(2 ** (Integer'(Standard'Address_Size) - 1)) - 1;
   --  Type used to provide task stack sizes to the runtime. Sized to permit
   --  stack sizes of up to half the total addressable memory space. This may
   --  seem excessively large (even for 32-bit systems), however there are many
   --  instances of users requiring large stack sizes (for example string
   --  processing).

   Unspecified_Size : constant Size_Type := Size_Type'First;
   --  Value used to indicate that no size type is set

   Runtime_Default_Sec_Stack_Size : constant Size_Type := 512;
   --  The run-time chosen default size for secondary stacks that may be
   --  overridden by the user with the use of binder -D switch.

end System.Parameters;
