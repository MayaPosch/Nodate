------------------------------------------------------------------------------
--                                                                          --
--                         GNAT COMPILER COMPONENTS                         --
--                                                                          --
--    S Y S T E M . S E C O N D A R Y _ S T A C K . S I N G L E _ T A S K   --
--                                                                          --
--                                 S p e c                                  --
--                                                                          --
--          Copyright (C) 2005-2020, Free Software Foundation, Inc.         --
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

--  This package provides a simple, default implementation of a function that
--  returns a pointer to a secondary stack for use in single-threaded
--  applications. It is not suitable for multi-threaded applications.
--
--  The function defined in this package is used when the following two
--  conditions are met:
--    1) No user-defined implementation has been provided. That is, the
--       symbol __gnat_get_sec_stack is not exported by the user's code.
--    2) No tasking is used. When tasking is used, __gnat_get_secondary_stack
--       is resolved by libgnarl.a (that contains a thread-safe implementation
--       of the secondary stack), so that the single-threaded version is not
--       included in the final executable.

pragma Restrictions (No_Elaboration_Code);
--  We want to guarantee the absence of elaboration code because the binder
--  does not handle references to this package.

package System.Secondary_Stack.Single_Task is

   function Get_Sec_Stack return SS_Stack_Ptr;
   pragma Export (C, Get_Sec_Stack, "__gnat_get_secondary_stack");
   --  Return the pointer of the secondary stack to be used for single-threaded
   --  applications, as expected by System.Secondary_Stack.

end System.Secondary_Stack.Single_Task;
