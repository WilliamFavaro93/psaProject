/*
 * PSA.c
 *
 *  Created on: May 18, 2022
 *      Author: William.Favaro
 */

#include "PSA.h"

PSAStruct PSA;

void PSA_Relay_RunningAndOutNotUsed()
{
	PSA.Relay.K1 = 0xFF;
	PSA.Relay.K6 = 0xFF;
	PSA.Relay.K5 = 0xFF;
	PSA.Relay.K4 = 0xFF;
}

void PSA_Relay_RunningAndOutUsed()
{
	PSA.Relay.K1 = 0xFF;
	PSA.Relay.K6 = 0xFF;
	PSA.Relay.K5 = 0xFF;
	PSA.Relay.K4 = 0x00;
}

void PSA_Relay_GoingStandby()
{
	PSA.Relay.K1 = 0xFF;
	PSA.Relay.K6 = 0xFF;
	PSA.Relay.K5 = 0x00;
	PSA.Relay.K4 = 0x00;
}

void PSA_Relay_Standby()
{
	PSA.Relay.K1 = 0xFF;
	PSA.Relay.K6 = 0x00;
	PSA.Relay.K5 = 0x00;
	PSA.Relay.K4 = 0x00;
}
