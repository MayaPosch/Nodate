/*
	common.h - Common header includes for core files.
*/


#ifndef COMMON_H
#define COMMON_H


#ifdef __stm32f0
#include "stm32f0/stm32f0xx.h"
#elif defined __stm32f1
#include "stm32f1/stm32f1xx.h"
#endif

#ifdef __stm32f3
#include "stm32f3/stm32f3xx.h"
#endif

#ifdef __stm32f4
#include "stm32f4/stm32f4xx.h"
#endif

#ifdef __stm32f7
#include "stm32f7/stm32f7xx.h"
#endif

#ifdef __stm32l4
#include "stm32l4/stm32l4xx.h"
#endif

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

#endif
