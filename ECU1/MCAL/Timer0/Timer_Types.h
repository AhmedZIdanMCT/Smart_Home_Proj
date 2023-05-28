/*
 * Timer_Types.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP lolo
 */

#ifndef _TIMER_TYPES_H_
#define _TIMER_TYPES_H_


typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECHORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE,
}Timer0Mode_Type;

//PRESCALER
typedef enum
{
	TIMER0_STOP=0,
	TIMER0_SCALER_0,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNAL_FALLING,
	EXTERNAL_RISING
}Timer0Scaler_Type;

typedef enum
{
	Normal,
	Reserved,
	Clear,
	Set
}Timer0ShapeWave_Type;

typedef enum
{
	 NULL_POINTER,
	 NO_ERROR,
	 Out_of_Range
}ErrorT0_State;
#endif /* TIMER0_TIMER_TYPES_H_ */
