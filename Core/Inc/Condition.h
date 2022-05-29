/*
 * Condition.h
 *
 *  Created on: 26 apr 2022
 *      Author: William.Favaro
 */

#ifndef CONDITION_H_
#define CONDITION_H_

#include "EEPRAM.h"
#include "Modbus.h"
#include <stdint.h>

#define CONDITION_OUT1_START		0x01
#define CONDITION_OUT1_STOP			0x02
#define CONDITION_OUT1_DIRTY		0x04
#define CONDITION_OUT2_START		0x10
#define CONDITION_OUT2_STOP			0x20

uint8_t Condition;

#endif /* CONDITION_H_ */
