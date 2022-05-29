/*
 * State.h
 *
 *  Created on: 12 mag 2022
 *      Author: William.Favaro
 */

/* CYCLE: Adsorption_1 -> Compensation_1 -> Compensation_2 -> Adsorption_2 -> Compensation_1 -> Compensation_2 -> */
/* -> Standby_1 -> Standby_2 -> Standby -> */

#include "Settings.h"
#include "stdint.h"
#include "PSA.h"

#define PSA_STATE__TURN_TO_STANDBY_MODE			-2
#define PSA_STATE__TURN_TO_ADSOCYCLE_MODE		 1
int State_AdsorptionCycleNStandby(int n);
