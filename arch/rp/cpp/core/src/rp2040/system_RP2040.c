/**************************************************************************/ /**
 * @file     system_ARMCM0plus.c
 * @brief    CMSIS Device System Source File for
 *           ARMCM0plus Device
 * @version  V1.0.0
 * @date     09. July 2018
 ******************************************************************************/
/*
 * Copyright (c) 2009-2018 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "RP20XX.h"
#include "system_RP2040.h"
#include "cmsis_compiler.h"

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/

#define XOSC_VALUE   (12000000UL) /* Oscillator frequency */
#define SYSTEM_CLOCK (XOSC_VALUE)

/*----------------------------------------------------------------------------
  System Core Clock Variable
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock = SYSTEM_CLOCK; /* System Core Clock Frequency */

#define CLK_REF_SRC_ROSC 0x00
#define CLK_REF_SRC_AUX  0x01
#define CLK_REF_SRC_XOSC 0x02

/*----------------------------------------------------------------------------
  System Core Clock update function
 *----------------------------------------------------------------------------*/

void SystemCoreClockUpdate(void)
{
    uint32_t clock_source = CLOCKS->CLK_REF_CTRL;
    uint32_t ref_div;
    uint32_t fb_div;
    uint32_t postdiv1;
    uint32_t postdiv2;

    switch (clock_source) {
        case CLK_REF_SRC_ROSC:
            // We can't directly calculate ROSC frequency, we have to use other stable source
            // In this case we use known frequency of XOSC
            CLOCKS->FC0_REF_KHZ  = XOSC_VALUE / 1000;
            CLOCKS->FC0_MIN_KHZ  = 0;
            CLOCKS->FC0_MAX_KHZ  = 0;
            CLOCKS->FC0_INTERVAL = 4;    // 1us * 2 * value
            // Since this gets more complicated we don't support this source now
            break;
        case CLK_REF_SRC_XOSC:
            ref_div = PLL_SYS->CS & PLL_SYS_CS_REFDIV_Msk;
            if (PLL_SYS->CS & PLL_SYS_CS_BYPASS_Msk) {
                SystemCoreClock = XOSC_VALUE / ref_div;
            } else {
                // Calculation from datasheet
                // (FREF / REFDIV) × FBDIV / (POSTDIV1 × POSTDIV2)
                fb_div          = PLL_SYS->FBDIV_INT;
                postdiv1        = (PLL_SYS->PRIM & PLL_SYS_PRIM_POSTDIV1_Msk) >> PLL_SYS_PRIM_POSTDIV1_Pos;
                postdiv2        = (PLL_SYS->PRIM & PLL_SYS_PRIM_POSTDIV2_Msk) >> PLL_SYS_PRIM_POSTDIV2_Pos;
                SystemCoreClock = (XOSC_VALUE / ref_div) * fb_div / (postdiv1 * postdiv2);
            }
            break;
        case CLK_REF_SRC_AUX:
            break;
    }

    return;
}

/*----------------------------------------------------------------------------
  System initialization function
 *----------------------------------------------------------------------------*/
extern const VECTOR_TABLE_Type __VECTOR_TABLE[48];

void SystemInit(void)
{
#if defined(__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
    SCB->VTOR = (uint32_t) & (__VECTOR_TABLE);
#endif

    // We only want to set XOSC to run on our board
    //if (CLOCKS->CLK_REF_CTRL != CLK_REF_SRC_XOSC) {
        // Setup XOSC range
        XOSC->CTRL = 0xaa0; // 1_15Mhz
        // Setup startup delay
        uint32_t startup_delay = (((12 * 1000000) / 1000) + 128) / 256;
        XOSC->STARTUP = startup_delay;
        // Enable XOSC
        XOSC->CTRL = (XOSC->CTRL & ~XOSC_CTRL_ENABLE_Msk) | (0xFAB << XOSC_CTRL_ENABLE_Pos);
        while (!(XOSC->STATUS & XOSC_STATUS_ENABLED_Msk));
        
        // // First bypass PLL
        // RESETS->RESET |= RESETS_RESET_pll_sys_Msk;
        // RESETS->RESET &= ~RESETS_RESET_pll_sys_Msk;
        // while (!(RESETS->RESET_DONE & RESETS_RESET_DONE_pll_sys_Msk));
        // PLL_SYS->PWR = 0x0;
        // PLL_SYS->CS |= PLL_SYS_CS_BYPASS_Msk;
        // while (!(PLL_SYS->CS & PLL_SYS_CS_BYPASS_Msk));
        // Change from using PLL to CLK_REF
        CLOCKS->CLK_REF_CTRL = 0x2 << CLOCKS_CLK_REF_CTRL_SRC_Pos;

        MODIFY_REG(CLOCKS->CLK_SYS_CTRL, CLOCKS_CLK_SYS_CTRL_SRC_Msk, 0);
        MODIFY_REG(CLOCKS->CLK_SYS_CTRL, CLOCKS_CLK_SYS_CTRL_AUXSRC_Msk, 0x03 << CLOCKS_CLK_SYS_CTRL_AUXSRC_Pos);
        MODIFY_REG(CLOCKS->CLK_SYS_CTRL, CLOCKS_CLK_SYS_CTRL_SRC_Msk, 0x01 << CLOCKS_CLK_SYS_CTRL_SRC_Pos);
    //}

    SystemCoreClockUpdate();
}