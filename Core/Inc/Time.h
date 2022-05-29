/*
 * Time.h
 *
 *  Created on: 27 apr 2022
 *      Author: William.Favaro
 */

#ifndef TIME_H_
#define TIME_H_

#include "Settings.h"
#include <stdint.h>

/* GOOD PRACTICE: Time & Timer have the same time unit (tenths of a second) */

typedef struct{
	uint8_t Time;
}uint8_Time;

typedef struct{
	uint16_t Time;
}uint16_Time;

typedef struct{
	uint32_t Time;
}uint32_Time;

typedef struct{
	uint64_t Time;
}uint64_Time;

typedef struct{
	uint8_t Timer;
}uint8_Timer;

typedef struct{
	uint16_t Timer;
}uint16_Timer;

typedef struct{
	uint32_t Timer;
}uint32_Timer;

typedef struct{
	uint64_t Timer;
}uint64_Timer;

#endif /* TIME_H_ */
