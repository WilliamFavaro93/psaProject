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

/* DEFINE: digital input bit */
#define DINPUT(x) (1U<<(x-1)) /* x is from 1 to 8 */
#define DINPUT_1 0x01
#define DINPUT_2 0x02
#define DINPUT_3 0x04
#define DINPUT_4 0x08
#define DINPUT_5 0x10 /* Remote Start OUT 2 */
#define DINPUT_6 0x20 /* Remote Start OUT 1 */
#define DINPUT_7 0x40
#define DINPUT_8 0x80 /* EXT Fault AL11 */

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
