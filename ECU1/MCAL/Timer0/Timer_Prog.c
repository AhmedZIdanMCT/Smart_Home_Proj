/*

 * Timer_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP lolo
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer_Int.h"
#include "Timer_Priv.h"
#include "Timer_Types.h"
#include "Mcu_HW.h"


void (*M_TIMEROV_CallBack)(void) = NULL ;
void (*M_TIMERCTC_CallBack)(void) = NULL ;

static u32 NumberOfOverFlow;
static u32 NumberOfRemining;
static u32 NumberOfCompareMatch;

static u32 Tcnt_Value = 0;

u16 Arr_Scaler_N[]={8,64,256,1024};


void M_Timer0_Void_Init(Timer0Mode_Type  TimerMode, Timer0ShapeWave_Type TimerWave)
{

	switch(TimerMode)
	{
	case TIMER0_NORMAL_MODE:
		CLR_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);
		break;
	case TIMER0_CTC_MODE:
		SET_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);
		break;
	case TIMER0_PHASECHORRECT_MODE:
		CLR_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		break;
	case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		break;

	}
	switch(TimerWave)
	{
	case Normal:
		CLR_BIT(TCCR0,4);
		CLR_BIT(TCCR0,5);
		break;
	case Clear:
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
		break;
	case Set:
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
		break;

	}/*
//Mode
    TCCR0 &= TIMER0_MODES;
    TCCR0 |= TimerMode;

//Shape Wave
     TCCR0 &= TIMER0_SHAPE;
     TCCR0 |= TimerWave;*/
}
void M_Timer0_Void_start(Timer0Scaler_Type TimerScaler)
{
	//Prescaler
	     TCCR0 &= TIMER0_PRESCALLER;
	     TCCR0 |= TimerScaler;
}
void M_Timer0_Void_stop(void)
{
    TCCR0 &= TIMER0_PRESCALLER;
    TCCR0 |= TIMER0_STOP;
}
void M_VoidEnableInt(Timer0Mode_Type  TimerMode)
{
#if(TimerMode == TIMER0_NORMAL_MODE)
	SET_BIT(TIMSK,0);
#endif
#if(TimerMode == TIMER0__CTC_MODE)
	SET_BIT(TIMSK,1);
#endif
}
void M_VoidDisableInt(Timer0Mode_Type  TimerMode)
{
#if(TimerMode == TIMER0_NORMAL_MODE)
	CLR_BIT(TIMSK,0);
#endif
#if(TimerMode == TIMER0__CTC_MODE)
	CLR_BIT(TIMSK,1);
#endif

}

u8 M_Timer0_U8_OVsetCallBack(void (*pf) (void))
{
	ErrorT0_State Local_Error = 1;
	if(pf != NULL)
	{
	M_TIMEROV_CallBack = pf;
	}
	else
	{
		Local_Error = 0;
	}
	return  Local_Error;
}

u8 M_Timer0_U8_CTCsetCallBack(void (*pf) (void))
{
	ErrorT0_State Local_Error = 1;
	if(pf != NULL)
	{
	M_TIMERCTC_CallBack =  pf;
	}
	else
	{
		Local_Error = 0;
	}
	return  Local_Error;
}


/* ISR */
void __vector_11 (void)
{
	static u32 counter=0;
	counter++;
	if(counter == NumberOfOverFlow)
	{
		TCNT0 = Tcnt_Value;
		counter=0;
		M_TIMEROV_CallBack();
	}
}

void __vector_10 (void)
{
	static u32 counter_CTC=0;
	counter_CTC++;
	if(counter_CTC ==NumberOfCompareMatch)
	{
		counter_CTC=0;
		M_TIMERCTC_CallBack();
	}
}

u32 M_Timer0_U32_GetCounts(void)
{
	u32 copy_num_of_counts;
	copy_num_of_counts = (NumberOfOverFlow * 256) + TCNT0;
	return copy_num_of_counts;
}
void M_Timer0_Void_setFastPWM(u32 duty,Timer0ShapeWave_Type Shape)
{
      // frequency = frequency / (256 * Arr_Scaler_N[Scaler-2]);
/* Non_Inverting */
#if(Shape == Clear)
       OCR0 = ((duty*256)/100-1);
#endif
 /* Inverting */
#if(Shape ==  Set)
       OCR0 =((duty*256)/100+255);
#endif
}
void  M_Timer0_Void_setphaseCorrectPWM(u32 duty,Timer0ShapeWave_Type Shape)
{
   // frequency = frequency / (510 * Arr_Scaler_N[Scaler-2]);
/* Non_Inverting */
#if(Shape == Clear)
    OCR0 = ((duty * 255)/100);
#endif
/* Inverting */
#if(Shape ==  Set)
    OCR0 = ((duty*255)/100+255);
#endif

}

void M_Timer0_Void_setDelayTimeMilliSec(u32 Time_m_Sec,Timer0Mode_Type  Mode_T,Timer0Scaler_Type Scaler)
{
f32 Tick_Time = (f32)Arr_Scaler_N[Scaler-2]/ FCPU;
u32 desired_Ticks =  (Time_m_Sec * 1000) / Tick_Time;

#if(Mode_T == TIMER0_NORMAL_MODE)
   NumberOfOverFlow = desired_Ticks/256;
   NumberOfRemining = desired_Ticks % 256;
   if(NumberOfRemining != 0)
     {
	   Tcnt_Value = 256 - NumberOfRemining;
	TCNT0 = Tcnt_Value ;
	NumberOfOverFlow++;
     }
#endif
#if(Mode_T == TIMER0_CTC_MODE)
   u8 value = 255;
   while(desired_Ticks % value)
   {
	   value--;
   }
   NumberOfCompareMatch = desired_Ticks/value;
   OCR0 =value;
#endif
}


