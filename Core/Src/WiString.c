/*
 * WiString.c
 *
 *  Created on: May 20, 2022
 *      Author: willi
 */

#include "WiString.h"


void ClearString(uint8_t String[])
{
	uint8_t index = 0;
	while(String[index] != 0)
	{
		String[index] = 0;
	}
}

uint8_t CompareStrings(uint8_t String_1[], uint8_t String_2[])
{
	uint8_t index = 0;

	while((String_1[index]!=0)||(String_2[index]!=0))
	{
		if(String_1[index] != String_2[index])
			return 0;
		index++;
	}

	if((String_1[index]==0)&&(String_2[index]==0))
	    return 1;

	return 0;
}
