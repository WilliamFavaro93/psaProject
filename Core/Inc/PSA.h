/*
 * PSA.h
 *
 *  Created on: 14 apr 2022
 *      Author: William.Favaro
 */

#ifndef PSA_H_
#define PSA_H_

#include "MyQueue.h"
//#include "Relay.h"
#include "Valve.h"
#include "Modbus.h"
#include "EEPRAM.h"
#include "Time.h"
#include "AnalogInput.h"
#include "DigitalInput.h"
//#include "Mode.h"
//#include "Alarm.h"

/*** MODE ***/
typedef struct
{
	uint8_t Ready; /* It's Ready changes between 0 and 0xFF when someone press the graphical power button */
	uint8_t Run;
	uint8_t Standby;
	uint8_t Alarm;
} uint8_Mode;


/*** ALARM ***/
typedef struct
{
	uint8_t AL1_CANbusError;
	uint8_t AL2_LowAirPressure;
	uint8_t AL5_LowProcessTankPressure;
	uint8_t AL11_External;
	uint8_t AL16_HighOUT2Pressure;
	uint8_t AL17_HighDewpoint;
	uint8_t AL18_HighDewpoint;
	uint8_t AL19_HighOUT1Pressure;
	uint8_t AL20_PCComunicationFault;
	uint8_t AL31_B1ProbeFault;
	uint8_t AL32_B2ProbeFault;
	uint8_t AL33_B3ProbeFault;
	uint8_t AL34_B4ProbeFault;
	uint8_t AL40_PsaDischanging;
	uint8_t MissingSDCard;
} SetOfAlarms;

/*** RELAY ***/
typedef struct
{
	uint8_t K1;
	uint8_t K6;
	uint8_t K5;
	uint8_t K4;
} SetOfRelays;

typedef struct{
	/* Mode */
	uint8_Mode Mode;			/**/
	/* State */
	int State; 				/* This global variable is used by the tasks: StateTask & */
	uint16_Timer NextState; /* PSA.NextState is used by the tasks: StateTask & */
	/* OUT */
	uint8_t OUT_1;			/* OUT_1, OUT_2 */
	uint8_t OUT_2;			/* OUT_1, OUT_2 -> 0: Not used; 1: Can be used 2: Actually in use */
	uint8_t OUTPriority;
	/* ... */
	uint8_t CloseDrain;

	uint8_t ValveState[8];
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
	/* Relay */
	SetOfRelays Relay;
	/* Alarm */
	SetOfAlarms Alarm;
	/* Time (in ds) */
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

void PSA_Relay_RunningAndOutNotUsed();
void PSA_Relay_RunningAndOutUsed();
void PSA_Relay_GoingStandby();
void PSA_Relay_Standby();

#endif /* PSA_H_ */
