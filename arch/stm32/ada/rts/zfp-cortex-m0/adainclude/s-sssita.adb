------------------------------------------------------------------------------
--                                                                          --
--                         GNAT COMPILER COMPONENTS                         --
--                                                                          --
--    S Y S T E M . S E C O N D A R Y _ S T A C K . S I N G L E _ T A S K   --
--                                                                          --
--                                 B o d y                                  --
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

pragma Restrictions (No_Elaboration_Code);
--  We want to guarantee the absence of elaboration code because the
--  binder does not handle references to this package.

package body System.Secondary_Stack.Single_Task is

   ----------------
   -- Local Data --
   ----------------

   Secondary_Stack : SS_Stack_Ptr := null;
   --  Pointer to the assigned secondary stack

   -------------------
   -- Get_Sec_Stack --
   -------------------

   function Get_Sec_Stack return SS_Stack_Ptr is
   begin
      --  If the pointer to the secondary stack is null then a stack has not
      --  been allocated. A call to SS_Init will assign the binder generated
      --  stack and will initialize it.

      if Secondary_Stack = null then
         SS_Init (Secondary_Stack);
      end if;

      return Secondary_Stack;
   end Get_Sec_Stack;

end System.Secondary_Stack.Single_Task;
