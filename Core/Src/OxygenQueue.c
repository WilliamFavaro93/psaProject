/*
 * OxygenQueue.c
 *
 *  Created on: 13 apr 2022
 *      Author: William.Favaro
 */

#include "OxygenQueue.h"

QueueStruct Oxygen;

void OxygenQueue_Init()
{
	MyQueue_Init(&Oxygen);
}

void OxygenQueue_InsertElement(int16_t ElementToInsert)
{
	MyQueue_InsertElement(&Oxygen, ElementToInsert);
}

uint16_t OxygenQueue_GetAverageValue()
{
	return MyQueue_GetAverageValue(&Oxygen);
}

void OxygenQueue_UpdateAverageValue()
{
	MyQueue_GetAverageValue(&Oxygen);
}

#if MYQUEUE_DEBUG
/*
 * This method is just for testing with debug this code
 */
void OxygenQueue_InsertElementTesting_1()
{
	for(MYQUEUE_SIZE_TYPE i=0; i<125; i++){
		OxygenQueue_InsertElement(i+2);
	}
}

/*
 * This method is just for testing with debug this code
 */
void OxygenQueue_InsertElementTesting_2()
{
	for(MYQUEUE_SIZE_TYPE i=0; i<125; i++){
		OxygenQueue_InsertElement(3000);
	}
}
#endif /* MYQUEUE_DEBUG */
