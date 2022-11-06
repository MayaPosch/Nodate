/*
	nodate.h - Common header file for the Nodate STM32 framework.
	
	Features:
			- Provides includes for all core functionality.
			- Automates board-specific includes.
			
	Notes:
			- 
			
	2021/03/01, Maya Posch
*/


#ifndef NODATE_H
#define NODATE_H


#if defined ( __GNUC__ ) && !defined (__CC_ARM) /* GNU Compiler */
  #ifndef __weak
    #define __weak   __attribute__((weak))
  #endif /* __weak */
  #ifndef __packed
    #define __packed __attribute__((__packed__))
  #endif /* __packed */
#endif /* __GNUC__ */


#include <core.h>
#include <rcc.h>
#include <clock.h>
#include <common.h>
#include <ethernet.h>
#include <gpio.h>
#include <i2c.h>
#include <interrupts.h>
#include <io.h>
#include <rtc.h>
#include <timer.h>
#include <dma.h>
#include <usart.h>
#include <adc.h>
#include <spi.h>
#include <dac.h>

#include <board_definition.h>

#endif
