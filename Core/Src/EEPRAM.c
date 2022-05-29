/*
 * EEPRAM.c
 *
 *  Created on: May 3, 2022
 *      Author: William.Favaro
 */

#include "EEPRAM.h"

/* EEPRAM is the RAM where you copy EEPROM values */
uint16_t EEPRAM[EEPRAM_PAGE_MAX][EEPRAM_INT_PER_PAGE];
