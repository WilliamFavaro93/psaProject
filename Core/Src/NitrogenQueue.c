/*
 * NitrogenQueue.c
 *
 *  Created on: 14 apr 2022
 *      Author: William.Favaro
 */

#include "NitrogenQueue.h"

QueueStruct Nitrogen;

void NitrogenQueue_Init()
{
	MyQueue_Init(&Nitrogen);
}

void NitrogenQueue_InsertElement(int16_t ElementToInsert)
{
	MyQueue_InsertElement(&Nitrogen, ElementToInsert);
}

uint16_t NitrogenQueue_GetAverageValue()
{
	return MyQueue_GetAverageValue(&Nitrogen);
}

void NitrogenQueue_UpdateAverageValue()
{
	MyQueue_GetAverageValue(&Nitrogen);
}

#if MYQUEUE_DEBUG
/*
 * This method is just for testing with debug this code
 */
void NitrogenQueue_InsertElementTesting_1()
{
	for(MYQUEUE_SIZE_TYPE i=0; i<125; i++){
		NitrogenQueue_InsertElement(i+2);
	}
}

/*
 * This method is just for testing with debug this code
 */
void NitrogenQueue_InsertElementTesting_2()
{
	for(MYQUEUE_SIZE_TYPE i=0; i<125; i++){
		NitrogenQueue_InsertElement(3000);
	}
}
#endif /* MYQUEUE_DEBUG */

