/*
 * NitrogenQueue.h
 *
 *  Created on: 14 apr 2022
 *      Author: William.Favaro
 */

#ifndef NITROGENQUEUE_H_
#define NITROGENQUEUE_H_

#include "MyQueue.h"

void NitrogenQueue_Init(void);
void NitrogenQueue_InsertElement(int16_t ElementToInsert);
uint16_t NitrogenQueue_GetAverageValue(void);
void NitrogenQueue_UpdateAverageValue(void);

#if MYQUEUE_DEBUG
/*
 * This method is just for testing with debug this code
 */
void NitrogenQueue_InsertElementTesting_1(void);
void NitrogenQueue_InsertElementTesting_2(void);
#endif /* MYQUEUE_DEBUG */

#endif /* NITROGENQUEUE_H_ */
