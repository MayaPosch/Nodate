/*
	common.h - Common header includes for core files.
*/


#ifndef COMMON_H
#define COMMON_H


#ifdef __rp2040
#include <core_cm0plus.h>
#include "rp2040/RP2040.h"
#endif

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

#include <nodate_config.h>

#endif
