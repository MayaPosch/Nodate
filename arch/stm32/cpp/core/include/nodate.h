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


#include <board_definition.h>

#include <clock.h>
#include <common.h>
#include <ethernet.h>
#include <gpio.h>
#include <i2c.h>
#include <interrupts.h>
#include <io.h>
#include <rcc.h>
#include <rtc.h>
#include <timer.h>
#include <usart.h>

// Include configuration file for enabling optional modules.
// This file is expected to be present in each project.
#include <nodate_config.h>

#endif
