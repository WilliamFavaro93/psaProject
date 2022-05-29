/*
 * Relay.c
 *
 *  Created on: 12 apr 2022
 *      Author: William.Favaro
 */

/* INCLUDE */
#include "Relay.h"

/* GLOBAL */
RelayStruct Relay[RELAY_MAX];

void Relay_Init()
{
	for(uint8_t  i=0; i<RELAY_MAX; i++)
	{
		Relay[i].State = RELAY_STATE_OFF;
		Relay[i].SecondsToNextState = 0;
		Relay[i].SecondsInActualState = 0;
	}
}

/*
 * Set the next state as @NextState of the relay @Relay
 */
void Relay_SetNextState(uint8_t i, uint8_t NextState, uint32_t SecondsToNextState, uint32_t SecondsInNextState)
{
	Relay[i].SecondsToNextState = SecondsToNextState;
	Relay[i].SecondsInActualState = SecondsInNextState;
	if(SecondsToNextState == 0)
	{
		Relay_SetState(i, NextState);
	}
	else
	{
		/* Next State */
		Relay[i].State &= ~RELAY_STATE_NEXTSTATE_CLEAR;
		Relay[i].State |= RELAY_STATE_NEXTSTATE;
		Relay[i].State |= (NextState << 1);
	}
}

void Relay_SetState(uint8_t i, uint8_t State)
{
	Relay[i].State = State;
}

/*
 * Check and update state of relays
 */
void Relay_Working()
{
	for(uint8_t i=0; i<RELAY_MAX; i++)
	{
		if(Relay[i].SecondsToNextState)
		{
			Relay[i].SecondsToNextState--;
		}
		else
		{
			if(Relay[i].State & RELAY_STATE_NEXTSTATE)
			{
				if((Relay[i].State) & (RELAY_STATE_NEXTSTATE_ON))
				{
					Relay[i].State = RELAY_STATE_ON;
					//... aggiungere codice per communicare al rele che deve cambiare stato
				}
				else
				{
					Relay[i].State = RELAY_STATE_OFF;
					//... aggiungere codice per communicare al rele che deve cambiare stato
				}
			}
			else if(Relay[i].SecondsInActualState)
				Relay[i].SecondsInActualState--;
		}

	}
}
