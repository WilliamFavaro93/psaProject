/*
 * Mode.h
 *
 *  Created on: 27 mag 2022
 *      Author: willi
 */

#ifndef INC_MODE_H_
#define INC_MODE_H_

typedef struct
{
	uint8_t Ready; /* It's Ready changes between 0 and 0xFF when someone press the graphical power button */
	uint8_t Run;
	uint8_t Standby;
	uint8_t Alarm;
} uint8_Mode;

#endif /* INC_MODE_H_ */
