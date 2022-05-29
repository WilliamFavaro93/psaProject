/*
 * Relay.h
 *
 *  Created on: 12 apr 2022
 *      Author: William.Favaro
 */

#ifndef RELAY_H_
#define RELAY_H_

#include <stdint.h>

/* DEFINE to be used also outside */
/* Relay[...] */
#define RELAY_PSA_WORKING		0 /**/
#define RELAY_O2SENSOR			1 /**/
#define RELAY_N2DISCHARGE 		3 /* ON -> Scarico di azoto impuro */
#define RELAY_CALIBRATION	 	4 /* Valvola di taratura */
#define RELAY_NO_ALARM 			5 /* ON -> Nessun allarme generico */
#define RELAY_MAX 				6 /**/
/* Relay[N].State = ... */
#define RELAY_STATE_OFF 			(0U<<0)
#define RELAY_STATE_ON 				(1U<<0)

/* DEFINE to be used only inside */
#define RELAY_STATE_NEXT_OFF 		(0U<<1)
#define RELAY_STATE_NEXT_ON 		(1U<<1)
#define RELAY_STATE_NEXTSTATE		(1U<<2)
#define RELAY_STATE_NEXTSTATE_OFF 	RELAY_STATE_NEXTSTATE+RELAY_STATE_NEXT_OFF
#define RELAY_STATE_NEXTSTATE_ON 	RELAY_STATE_NEXTSTATE+RELAY_STATE_NEXT_ON
#define RELAY_STATE_NEXTSTATE_CLEAR ((1U<<2) + (1U<<1))
#define RELAY_STATE_CLEARSTATE		0

typedef struct{
	uint8_t State;
	uint32_t SecondsToNextState;
	uint32_t SecondsInActualState;
	uint8_t Port;
	uint8_t Pin;
}RelayStruct;

void Relay_Init();
void Relay_SetNextState(uint8_t nRelay, uint8_t NextState, uint32_t SecondsToNextState, uint32_t SecondsInNextState);
void Relay_SetState(uint8_t i, uint8_t State);
void Relay_Working();

#endif /* RELAY_H_ */
