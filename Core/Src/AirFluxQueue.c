/*
 * AirFluxQueue.c
 *
 *  Created on: 13 apr 2022
 *      Author: William.Favaro
 */

#include "AirFluxQueue.h"

QueueStruct AirFlux;

void AirFluxQueue_Init()
{
	MyQueue_Init(&AirFlux);
}

void AirFluxQueue_InsertElement(int16_t ElementToInsert)
{
	MyQueue_InsertElement(&AirFlux, ElementToInsert);
}

uint16_t AirFluxQueue_GetAverageValue()
{
	return MyQueue_GetAverageValue(&AirFlux);
}

void AirFluxQueue_UpdateAverageValue()
{
	MyQueue_GetAverageValue(&AirFlux);
}

#if MYQUEUE_DEBUG
/*
 * This method is just for testing with debug this code
 */
void AirFluxQueue_InsertElementTesting_1()
{
	for(MYQUEUE_SIZE_TYPE i=0; i<125; i++){
		AirFluxQueue_InsertElement(i+2);
	}
}

/*
 * This method is just for testing with debug this code
 */
void AirFluxQueue_InsertElementTesting_2()
{
	for(MYQUEUE_SIZE_TYPE i=0; i<125; i++){
		AirFluxQueue_InsertElement(3000);
	}
}
#endif /* MYQUEUE_DEBUG */
