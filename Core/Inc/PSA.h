/*
 * PSA.h
 *
 *  Created on: 14 apr 2022
 *      Author: William.Favaro
 */

#ifndef PSA_H_
#define PSA_H_

#include "MyQueue.h"
#include "Relay.h"
#include "Valve.h"
#include "Modbus.h"
#include "EEPRAM.h"
#include "Time.h"
#include "AnalogInput.h"
#include "DigitalInput.h"
#include "Mode.h"


/**/
#define PSA_STEP_CYCLE_MAX 8
#define PSA_STBY_CYCLE_MAX 6

#define PSA_MODE_START 			0x01
#define PSA_MODE_RUNNING 		0x02
#define PSA_MODE_STOP 			0x04

#define PSA_VALVE_CYCLE_MAX_STEP	 	8 /* Numero Totale di Cicli per Valvola */
#define PSA_VALVE_CYCLE_MAX_STANDBY 	6
#define PSA_VALVE_MAX 					4 /* Numero Totale di Blocco Valvole */

#define PSA_ADSORPTION_STARTINGVALUE 	0 /* Decimi?Secondi */
#define PSA_ADSORPTION_TIME 			0 /* Decimi?Secondi */
#define PSA_COMPENSATION_TIME			0 /* Decimi?Secondi */

typedef struct{
	uint8_Mode Mode;			/**/
	int State; 				/* This global variable is used by the tasks: StateTask & */
	uint16_Timer NextState; /* PSA.NextState is used by the tasks: StateTask & */
	uint8_t OUT_1;			/* OUT_1, OUT_2 */
	uint8_t OUT_2;			/* OUT_1, OUT_2 -> 0: Not used; 1: Can be used 2: Actually in use */
	uint8_t OUTPriority;
	uint8_t CloseDrain;

	uint8_t ValveState[PSA_VALVE_MAX];
	uint32_t MaskOutputPreview; // <- PSA.Valve.Module
	/* Analog Input */
	uint16_AnalogInput B1_IncomingAirPressure;			/* B1: 0 - 16 bar */
	uint16_AnalogInput B2_OutputPressure_1;				/* B2: 0 - 16 bar */
	uint16_AnalogInput B3_ProcessTankPressure;			/* B3: 0 - 16 bar */
	uint16_AnalogInput B4_OutputPressure_2;				/* B4: 0 - 16 bar */

	uint16_AnalogInput DW_IncomingAirDewpoint;
	uint16_AnalogInput FM_NitrogenFlowmeter;
	uint16_AnalogInput KE1_OxygenSensor_1;			/* KE: UpperTh = LowerTh*/
	uint16_AnalogInput KE2_OxygenSensor_2;			/* KE: */
	/* Digital Input */
	uint8_DigitalInput IN5_RemoteStartOUT_2;
	uint8_DigitalInput IN6_RemoteStartOUT_1;
	uint8_DigitalInput IN8_FaultAL11_EXT;
	/* Time */
	uint16_Time Adsorption; 		/* 0 - 3600 decimi */
//	uint16_Time InitialAdsorption; 	/* 0 - 3600 decimi */
	uint8_Time Compensation; 		/* 0 -  100 decimi */
	uint16_Time Standby_1;			/* 0 -  900 decimi */
	uint16_Time Standby_2;			/* 0 -  900 decimi */
	uint16_Time StartUp;			/* 0 - 1000 decimi */
	/* Queue */
//	QueueStruct Oxygen;
//	QueueStruct Nitrogen;
//	QueueStruct AirFlux;
//	RelayStruct Relay[];
}PSAStruct;

#endif /* PSA_H_ */
