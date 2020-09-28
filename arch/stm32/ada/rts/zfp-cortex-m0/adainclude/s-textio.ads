------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUN-TIME COMPONENTS                         --
--                                                                          --
--                        S Y S T E M . T E X T _ I O                       --
--                                                                          --
--                                 S p e c                                  --
--                                                                          --
--          Copyright (C) 2011-2020, Free Software Foundation, Inc.         --
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

--  This package defines the console I/O interface for the simplified version
--  of Ada.Text_IO used in ZFP runtimes or bare board platforms.

package System.Text_IO is
   pragma No_Elaboration_Code_All;
   pragma Preelaborate;

   --  The interface uses two subprograms for each direction: one for the ready
   --  status and one for the action. This is done on purpose to avoid busy
   --  waiting loops in the body.

   procedure Initialize;
   --  Must be called before all other subprograms to initialize the service.
   --  We avoid the use of elaboration to make this package preelaborated.

   Initialized : Boolean := False;
   --  Set to True (by Initialize) when the service is initialized. Having this
   --  variable outside allows reinitialization of the service.

   --------------
   --  Output  --
   --------------

   function Is_Tx_Ready return Boolean;
   --  Return True if it is possible to call Put. This function can be used for
   --  checking that the output register of an UART is empty before write a
   --  new character on it. For non blocking output system, this function can
   --  always return True. Once this function has returned True, it must always
   --  return True before the next call to Put.

   procedure Put (C : Character);
   --  Write a character on the console. Must be called only when Is_Tx_Ready
   --  has returned True before, otherwise its behavior is undefined.

   function Use_Cr_Lf_For_New_Line return Boolean;
   --  Return True if New_Line should output CR + LF, otherwise it will output
   --  only LF.

   -------------
   --  Input  --
   -------------

   function Is_Rx_Ready return Boolean;
   --  Return True is a character can be read by Get. On systems where is it
   --  difficult or impossible to know wether a character is available, this
   --  function can always return True and Get will be blocking.

   function Get return Character;
   --  Read a character from the console. Must be called only when Is_Rx_Ready
   --  has returned True, otherwise behavior is undefined.
end System.Text_IO;
