## -*- asm -*- ##############################################################
#                                                                           #
#                 GNAT RUN-TIME LIBRARY (GNARL) COMPONENTS                  #
#                                                                           #
#                               Assembly File                               #
#                                                                           #
#                         Copyright (C) 2017 AdaCore                        #
#                                                                           #
#  GNAT is free software;  you can  redistribute it  and/or modify it under #
#  terms of the  GNU General Public License as published  by the Free Soft- #
#  ware  Foundation;  either version 3,  or (at your option) any later ver- #
#  sion.  GNAT is distributed in the hope that it will be useful, but WITH- #
#  OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY #
#  or FITNESS FOR A PARTICULAR PURPOSE.                                     #
#                                                                           #
#  As a special exception under Section 7 of GPL version 3, you are granted #
#  additional permissions described in the GCC Runtime Library Exception,   #
#  version 3.1, as published by the Free Software Foundation.               #
#                                                                           #
#  You should have received a copy of the GNU General Public License and    #
#  a copy of the GCC Runtime Library Exception along with this program;     #
#  see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see    #
#  <http://www.gnu.org/licenses/>.                                          #
#                                                                           #
#############################################################################

            .syntax unified
            .cpu cortex-m4
            .thumb
          
            /***************************
             * Breakpoint trap handler *
             **************************/
          
            .text
            .thumb_func
	    .globl __gnat_bkpt_trap
            .weak __gnat_bkpt_trap /* Users can implement their own handler */
            .type __gnat_bkpt_trap, %function
__gnat_bkpt_trap:

/* The breakpoint handler will only be executed when there's no debugger
 * attached and the debug monitor is enabled. In that case we decide to ignore
 * the breakpoint and resume execution at the next instruction.
 */

/* Depending on the least significant 4 bits of the EXC_RETURN value in LR we
 * know the stack frame used before the exception (MSP or PSP).
 * ARM Cortex-M Devices Generic User Guide 2.3.7. Exception entry and return
 */
            and r0, lr, #0xF /* Get least significant 4 bits of LR*/
            cmp r0, #0xD     /* Check if interrupted context is in PSP or MSP */
            beq .Luse_psp
.Luse_msp:  mrs r0, MSP      /* Get main stack pointer */
            b .L0
.Luse_psp:  mrs r0, PSP      /* Get process stack pointer */
.L0:        add r0, r0, 24   /* Set r0 to the address of PC on the stack */
            ldr r1, [r0]     /* Load PC */
            add r1, r1, 2    /* Increase PC to the next instruction */
            str r1, [r0]     /* Store PC back to the stack */
            bx lr            /* return from breakpoint fault */
            .size __gnat_bkpt_trap, . - __gnat_bkpt_trap
