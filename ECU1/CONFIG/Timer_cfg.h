/*
 * Timer_cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP lolo
 */

#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

#include "Timer_Types.h"

typedef struct
{
	Timer0Mode_Type mode;
	Timer0Scaler_Type Prescaler;
	Timer0ShapeWave_Type Shape;
}TIMER_Configuration;


#endif /* TIMER_CFG_H_ */
