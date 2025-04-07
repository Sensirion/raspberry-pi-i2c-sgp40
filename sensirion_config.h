/*
 * Copyright (c) 2019, Sensirion AG
 *
 * For licensing please refer to the LICENSE file of the repository.
 */

#ifndef SENSIRION_CONFIG_H
#define SENSIRION_CONFIG_H

/**
 * If your platform does not provide the library stdlib.h you have to remove the
 * include and define NULL yourself (see below).
 */
#include <stdlib.h>

/**
 * #ifndef NULL
 * #define NULL ((void *)0)
 * #endif
 */

/**
 * If your platform does not provide the library stdint.h you have to
 * define the integral types yourself (see below).
 */
#include <stdint.h>

/**
 * Typedef section for types commonly defined in <stdint.h>
 * If your system does not provide stdint headers, please define them
 * accordingly. Please make sure to define int64_t and uint64_t.
 */
/* typedef unsigned long long int uint64_t;
 * typedef long long int int64_t;
 * typedef long int32_t;
 * typedef unsigned long uint32_t;
 * typedef short int16_t;
 * typedef unsigned short uint16_t;
 * typedef char int8_t;
 * typedef unsigned char uint8_t;
 */

#ifndef __cplusplus

/**
 * If your platform doesn't define the bool type we define it as int. Depending
 * on your system update the definition below.
 */
#if __STDC_VERSION__ >= 199901L
#include <stdbool.h>
#else

#ifndef bool
#define bool int
#define true 1
#define false 0
#endif /* bool */

#endif /* __STDC_VERSION__ */

#endif /* __cplusplus */

#endif /* SENSIRION_CONFIG_H */
