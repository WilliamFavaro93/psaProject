/*
 * DigitalInput.h
 *
 *  Created on: 26 apr 2022
 *      Author: William.Favaro
 */

#ifndef DIGITALINPUT_H_
#define DIGITALINPUT_H_

#include "EEPRAM.h"
#include "Modbus.h"
#include <stdint.h>

typedef struct
{
	uint8_t Value;
} uint8_DigitalInput;

typedef struct
{
	uint16_t Value;
} uint16_DigitalInput;

typedef struct
{
	uint32_t Value;
} uint32_DigitalInput;

typedef struct
{
	uint64_t Value;
} uint64_DigitalInput;

#endif /* DIGITALINPUT_H_ */
