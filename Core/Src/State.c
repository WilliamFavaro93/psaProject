/*
 * State.c
 *
 *  Created on: 12 mag 2022
 *      Author: William.Favaro
 */

#include "State.h"


/* CYCLE: Adsorption_1 -> Compensation_1 -> Compensation_2 -> Adsorption_2 -> Compensation_1 -> Compensation_2 -> */

//uint8_t charState[2]; /* Send the state by UART communication during DEBUG */
extern PSAStruct PSA;


void State_OutValve()
{
	PSA.ValveState[1] = 0;
	if(PSA.OUT_1 == 2)
	{
		PSA.ValveState[0]++;
	}
	else if(PSA.OUT_2 == 2)
	{
		PSA.ValveState[1]++;
	}
}

void State_Cycle_Adsorption_1()
{

	PSA.ValveState[0] = 0xC6;
	State_OutValve();
	PSA.NextState.Timer = 27; /* 275 ds */

}

void State_Cycle_Compensation_1()
{
	PSA.ValveState[0] = 0xA0;
	State_OutValve();
	PSA.NextState.Timer = 1; /* 5 ds */

}

void State_Cycle_Compensation_2()
{
	PSA.ValveState[0] = 0x24;
	State_OutValve();
	PSA.NextState.Timer = 1; /* 5 ds */
}
void State_Cycle_Adsorption_2()
{
	PSA.ValveState[0] = 0xB8;
	State_OutValve();
	PSA.NextState.Timer = 27; /* 275 ds */
}

/* -> Standby1 -> Standby2 -> Standby3 -> */
void State_Standby_1()
{
	PSA.ValveState[0] = 0x08;
	PSA.NextState.Timer = 5; /* 50 ds */

}
void State_Standby_2()
{
	PSA.ValveState[0] = 0x48;
	PSA.NextState.Timer = 5; /* 50 ds */
}
void State_Standby_3()
{
	PSA.ValveState[0] = 0x00;
	PSA.NextState.Timer = 0; /* ds */
}

int State_AdsorptionCycleNStandby(int n)
{
	switch(n)
	{
	/* STANDBY */
	case -2:
		State_Standby_1();
		return -1;
	case -1:
		State_Standby_2();
		return 0;
	case 0:
		State_Standby_3();
		return 0;

	/* ADSORPTION_CYCLE */
	case 1:
		State_Cycle_Adsorption_1();
		return 2;
	case 2:
		State_Cycle_Compensation_1();
		return 3;
	case 3:
		State_Cycle_Compensation_2();
		return 4;
	case 4:
		State_Cycle_Adsorption_2();
		return 5;
	case 5:
		State_Cycle_Compensation_1();
		return 6;
	case 6:
		State_Cycle_Compensation_2();
		return 1;
	}
	return 0;
}
