/*
	common.h - Common header includes for core files.
*/


#ifndef COMMON_H
#define COMMON_H


#ifdef __stm32f0

#if MCU_GENUS == stm32f030x6
//#include "stm32f0/stm32f030x6.h"
#define STM32F030x6
#elif MCU_GENUS == stm32f030x8
//#include "stm32f0/stm32f030x8.h"
#define STM32F030x8
#elif MCU_GENUS == stm32f030xc
//#include "stm32f0/stm32f030xc.h"
#define STM32F030xC
#elif MCU_GENUS == stm32f031x6
//#include "stm32f0/stm32f031x6.h"
#define STM32F031x6
#elif MCU_GENUS == stm32f038xx
//#include "stm32f0/stm32f038xx.h"
#define STM32F038xx
#elif MCU_GENUS == stm32f042x6
//#include "stm32f0/stm32f042x6.h"
#define STM32F042x6
#elif MCU_GENUS == stm32f048xx
//#include "stm32f0/stm32f048xx.h"
#define STM32F048xx
#elif MCU_GENUS == stm32f051x8
//#include "stm32f0/stm32f051x8.h"
#define STM32F051x8
#elif MCU_GENUS == stm32f058xx
//#include "stm32f0/stm32f058xx.h"
#define STM32F058xx
#elif MCU_GENUS == stm32f070x6
//#include "stm32f0/stm32f070x6.h"
#define STM32F070x6
#elif MCU_GENUS == stm32f070xb
//#include "stm32f0/stm32f070xb.h"
#define STM32F070xB
#elif MCU_GENUS == stm32f071xb
//#include "stm32f0/stm32f071xb.h"
#define STM32F071xB
#elif MCU_GENUS == stm32f072xb
//#include "stm32f0/stm32f072xb.h"
#define STM32F072xB
#elif MCU_GENUS == stm32f078xx
//#include "stm32f0/stm32f078xx.h"
#define STM32F078xx
#elif MCU_GENUS == stm32f091xc
//#include "stm32f0/stm32f091xc.h"
#define STM32F091xC
#elif MCU_GENUS == stm32f098xx
//#include "stm32f0/stm32f098xx.h"
#define STM32F098xx
#endif

#include "stm32f0/stm32f0xx.h"

#endif

#ifdef __stm32f4
#include "stm32f4/stm32f4xx.h"
#endif

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

#endif
