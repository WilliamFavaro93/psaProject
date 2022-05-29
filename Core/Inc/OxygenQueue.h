/*
 * OxygenQueue.h
 *
 *  Created on: 14 apr 2022
 *      Author: William.Favaro
 */

#ifndef OXYGENQUEUE_H_
#define OXYGENQUEUE_H_

#include "MyQueue.h"

//QueueStruct Oxygen;

void OxygenQueue_Init();
void OxygenQueue_InsertElement(int16_t ElementToInsert);
uint16_t OxygenQueue_GetAverageValue();
void OxygenQueue_UpdateAverageValue();

#if MYQUEUE_DEBUG
/*
 * This method is just for testing with debug this code
 */
void OxygenQueue_InsertElementTesting_1();
void OxygenQueue_InsertElementTesting_2();
#endif /* MYQUEUE_DEBUG */

#endif /* OXYGENQUEUE_H_ */
