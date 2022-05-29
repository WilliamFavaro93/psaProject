/*
 * AirFluxQueue.h
 *
 *  Created on: 14 apr 2022
 *      Author: William.Favaro
 */

#ifndef AIRFLUXQUEUE_H_
#define AIRFLUXQUEUE_H_

#include "MyQueue.h"


void AirFluxQueue_Init(void);
void AirFluxQueue_InsertElement(int16_t ElementToInsert);
uint16_t AirFluxQueue_GetAverageValue(void);
void AirFluxQueue_UpdateAverageValue(void);

#if MYQUEUE_DEBUG
/*
 * This method is just for testing with debug this code
 */
void AirFluxQueue_InsertElementTesting_1(void);
void AirFluxQueue_InsertElementTesting_2(void);
#endif /* MYQUEUE_DEBUG */

#endif /* AIRFLUXQUEUE_H_ */
