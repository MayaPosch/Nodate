------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUN-TIME COMPONENTS                         --
--                                                                          --
--                    S Y S T E M . S E M I H O S T I N G                   --
--                                                                          --
--                                 S p e c                                  --
--                                                                          --
--            Copyright (C) 2017-2020, Free Software Foundation, Inc.       --
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

with Interfaces;               use Interfaces;
with System.Machine_Code;      use System.Machine_Code;
with Ada.Unchecked_Conversion;

package body System.Semihosting is

   type SH_Word is new Interfaces.Unsigned_32;

   function To_SH_Word is new Ada.Unchecked_Conversion
     (Source => System.Address, Target => SH_Word);

   function Generic_SH_Call (R0, R1 : SH_Word) return SH_Word;
   --  Handles the low-level part of semihosting, setting the registers and
   --  executing a breakpoint instruction.

   subtype Syscall is SH_Word;

   SYS_WRITEC : constant Syscall := 16#03#;
   SYS_WRITE0 : constant Syscall := 16#04#;
   SYS_READC  : constant Syscall := 16#07#;

   --  Output buffer

   --  Because most of the time required for semihosting is not consumed for
   --  the data itself but rather in the handling of breakpoint and
   --  communication between the target and debugger, sending one byte costs
   --  almost as much time as sending a buffer of multiple bytes.
   --
   --  For this reason, we use an output buffer for the semihosting Put
   --  functions. The buffer is flushed when full or when a line feed or NUL
   --  character is transmitted.

   Buffer_Size : constant := 128;
   type Buffer_Range is range 1 .. Buffer_Size;
   Buffer : array (Buffer_Range) of Unsigned_8;
   Buffer_Index : Buffer_Range := Buffer_Range'First;

   procedure Flush;
   --  Send the content of the buffer with semihosting WRITE0 call

   ---------------------
   -- Generic_SH_Call --
   ---------------------

   function Generic_SH_Call (R0, R1 : SH_Word) return SH_Word is
      Ret : SH_Word;
   begin
      Asm ("mov r0, %1" & ASCII.LF & ASCII.HT &
           "mov r1, %2" & ASCII.LF & ASCII.HT &
           "bkpt #0xAB" & ASCII.LF & ASCII.HT &
           "mov %0, r0",
           Outputs  => (SH_Word'Asm_Output ("=r", Ret)),
           Inputs   => (SH_Word'Asm_Input ("r", R0),
                        SH_Word'Asm_Input ("r", R1)),
           Volatile => True,
           Clobber => ("r1, r0"));
      return Ret;
   end Generic_SH_Call;

   -----------
   -- Flush --
   -----------

   procedure Flush is
      Unref : SH_Word;
      pragma Unreferenced (Unref);
   begin
      if Buffer_Index /= Buffer'First then
         --  Set null-termination
         Buffer (Buffer_Index) := 0;

         --  Send the buffer with a semihosting call
         Unref := Generic_SH_Call (SYS_WRITE0, To_SH_Word (Buffer'Address));

         --  Reset buffer index
         Buffer_Index := Buffer'First;
      end if;
   end Flush;

   ---------
   -- Put --
   ---------

   procedure Put (Item : Character) is
      Unref : SH_Word;
      pragma Unreferenced (Unref);

      C : Character with Volatile;
      --  Use a volatile variable to avoid compiler's optimization

   begin
      if Item = ASCII.NUL then
         --  The WRITE0 semihosting call that we use to send the output buffer
         --  expects a null terminated C string. Therefore it is not possible
         --  to have an ASCII.NUL character in the middle of the buffer as this
         --  would truncate the buffer.
         --
         --  For this reason the ASCII.NUL character is sent separately with a
         --  WRITEC semihosting call.

         --  Flush the current buffer
         Flush;

         --  Send the ASCII.NUL with a WRITEC semihosting call
         C := Item;
         Unref := Generic_SH_Call (SYS_WRITEC, To_SH_Word (C'Address));

      else

         Buffer (Buffer_Index) := Character'Pos (Item);
         Buffer_Index := Buffer_Index + 1;

         --  Flush the buffer when it is full or if the character is a line
         --  feed.
         if Buffer_Index = Buffer'Last or else Item = ASCII.LF then
            Flush;
         end if;
      end if;
   end Put;

   ---------
   -- Put --
   ---------

   procedure Put (Item : String) is
   begin
      for Index in Item'Range loop
         Put (Item (Index));
      end loop;
   end Put;

   ---------
   -- Get --
   ---------

   procedure Get (Item : out Character) is
      Ret : SH_Word;
   begin
      Ret := Generic_SH_Call (SYS_READC, 0);
      Item := Character'Val (Ret);
   end Get;

end System.Semihosting;
