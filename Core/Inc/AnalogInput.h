/*
 * AnalogInput.h
 *
 *  Created on: 27 apr 2022
 *      Author: William.Favaro
 */

#ifndef ANALOGINPUT_H_
#define ANALOGINPUT_H_

#include <stdint.h>

typedef struct{
	uint8_t Value;
	uint8_t UpperThreshold;
	uint8_t LowerThreshold;
}uint8_AnalogInput;

typedef struct{
	uint16_t Value;
	uint16_t UpperThreshold;
	uint16_t LowerThreshold;
}uint16_AnalogInput;

typedef struct{
	uint32_t Value;
	uint32_t UpperThreshold;
	uint32_t LowerThreshold;
}uint32_AnalogInput;

#endif /* ANALOGINPUT_H_ */
