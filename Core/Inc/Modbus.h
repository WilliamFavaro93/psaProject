/*
 * Modbus.h
 *
 *  Created on: 21 apr 2022
 *      Author: William.Favaro
 */

#ifndef MODBUS_H_
#define MODBUS_H_

#include <stdint.h>

#define MODBUS_ARRAY_MAX 255
#define MODBUS_PSA_STATE 255

/* READ ANALOG MEASURES: 0 */
#define MODBUS_OXYGEN				0 /* Read Oxygen */
#define MODBUS_AIRFLOW				1 /* Incoming Air Input [nm3/h] */
#define MODBUS_DEWPOINT				2 /*  */
#define MODBUS_PRESSURE_B1			3 /*  */
#define MODBUS_PRESSURE_B2			4 /*  */
#define MODBUS_PRESSURE_B3			5 /*  */
#define MODBUS_PRESSURE_B4			6 /*  */
#define MODBUS_TEMPERATURE_AIR		7 /* Incoming Air Temperature */
#define MODBUS_TEMPERATURE_NITROGEN	8 /* Delivery Nitrogen Temperatura */
#define MODBUS_DELTAPRESSURE		9 /* Pressure Difference between INlet and OUTlet */
/* READ DIGITAL MEASURES + ALARMS: 50 */
#define MODBUS_ALARMS				50
/* WORKING STATE: 75 */
#define MODBUS_COMMAND				99

#define MODBUS_ALARMS_IN(x) (1U<<(x-1)) /* x is from 1 to 16 */
/*	MODBUS_ALARMS_IN(x)
 * 1: pressure (line 1)
 * 2: pressure (line 2)
 * 3: pressure process tank
 * 4: no compress air
 * 5: no communication CANBUS <--> Valve Modules
 * 6: no communicaiton MODBUS <--> ISOSOFT
 * 7:
 * 8:
 * 9:
 * 10: generic like filters, temperature, fridge...
 * 11:
 * 12: external compressor
 * 13. external dryer
 * 14:
 * 15:
 * 16:
 */

#endif /* MODBUS_H_ */
