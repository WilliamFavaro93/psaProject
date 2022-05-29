/*
 * c
 *
 *  Created on: 21 apr 2022
 *      Author: William.Favaro
 */

#ifndef EEPRAM_H_
#define EEPRAM_H_

#include <stdint.h>

#define	EEPRAM_PAGE_MAX 5
#define EEPRAM_INT_PER_PAGE 32

/* EEPROM PAGE 0 */

/* EEPROM PAGE 1 */
#define EE_1_SET_OXYGEN_1	 		 0
#define EE_1_SET_OXYGEN_2			 1
#define EE_1_TIME_HYSTERESIS 		 2
#define EE_1_SET_OXYGEN_1_ISOSOFT	 3
#define EE_1_SET_OXYGEN_2_ISOSOFT 	 4
#define EE_1_ADSORPTION_TIME 		 5
#define EE_1_TIME_TO_START_PSA 		 6
#define EE_1_COMPENSATION_TIME 		 7
#define EE_1_ALARM11_DELAY	 		 8
#define EE_1_TIME_STANDBY_1 		 9
#define EE_1_TIME_STANDBY_2 		10
#define EE_1_EN_MODULE				11
#define EE_1_ADSORPTION_TIME_TOSTART 	12
#define EE_1_PRESSURE_B3_OPEN		15
#define EE_1_PRESSURE_B3_CLOSE		16
#define EE_1_PRESSURE_B2_START		17
#define EE_1_PRESSURE_B2_STANDBY	18
#define EE_1_PRESSURE_B4_START		19
#define EE_1_PRESSURE_B4_STANDBY	20
#define EE_1_PRESSURE_B1_START		21
#define EE_1_PRESSURE_B1_STOP		22
#define EE_1_TIMER_B2_ERROR			23
#define EE_1_TIMER_B4_ERROR			24
#define EE_1_VALVE_NUMBER			25
#define EE_1_TIMER_WARMUP			26
#define EE_1_DEWPOINT_SET			27
#define EE_1_DEWPOINT_ALARM			28
#define EE_1_DEWPOINT_DELAY			29
#define EE_1_MODULE_NUMBER			30
#define EE_1_MACHINE				31
/* EEPROM PAGE 2 */
/* EEPROM PAGE 3 */
#define EE_3_COMMAND				23
/* EEPROM PAGE 4 */

//void EEPRAM_Init()

#endif /* EEPRAM_H_ */
