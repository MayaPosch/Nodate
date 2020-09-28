------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUN-TIME COMPONENTS                         --
--                                                                          --
--                         S Y S T E M . M E M O R Y                        --
--                                                                          --
--                                 S p e c                                  --
--                                                                          --
--          Copyright (C) 2001-2020, Free Software Foundation, Inc.         --
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

--  This is a simplified version of this package, for use with a configurable
--  run-time library that does not provide Ada tasking. It does not provide
--  any deallocation routine.

--  This package provides the low level memory allocation/deallocation
--  mechanisms used by GNAT.

package System.Memory is
   pragma Elaborate_Body;

   type size_t is mod 2 ** Standard'Address_Size;
   --  Note: the reason we redefine this here instead of using the
   --  definition in Interfaces.C is that we do not want to drag in
   --  all of Interfaces.C just because System.Memory is used.

   function Alloc (Size : size_t) return System.Address;
   --  This is the low level allocation routine. Given a size in storage
   --  units, it returns the address of a maximally aligned block of
   --  memory.
   --
   --  A first check is performed to discard memory allocations that are
   --  obviously too big, preventing problems of memory wraparound. If Size is
   --  greater than the maximum number of storage elements (taking into account
   --  the maximum alignment) in the machine, then a Storage_Error exception is
   --  raised before trying to perform the memory allocation.
   --
   --  If Size is set to zero on entry, then a minimal (but non-zero)
   --  size block is allocated.
   --
   --  If there is not enough free memory on the heap for the requested
   --  allocation then a Storage_Error exception is raised and the heap remains
   --  unchanged.
   --
   --  Note: this is roughly equivalent to the standard C malloc call
   --  with the additional semantics as described above.

private
   --  The following names are used from the generated compiler code

   pragma Export (C, Alloc,   "__gnat_malloc");

end System.Memory;
