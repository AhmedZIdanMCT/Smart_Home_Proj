/*
 * Timer_Int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP lolo
 */

#ifndef _TIMER_INT_H_
#define _TIMER_INT_H_

#include "STD_TYPES.h"
#include "Timer_Types.h"
#include "Timer_cfg.h"

/******************************************
   GLOBAL FUNCTIONS PROTOTYPES
*******************************************/

/******************************************
  syntax : void M_Timer0_Void_Init(TIMER_Configuration *Timer0_cfg);



  Description : init the timer 0
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  timer mode, shapewave
  parameters (out) :  Non
  Return Value     : void
******************************************/
void M_Timer0_Void_Init(Timer0Mode_Type  TimerMode, Timer0ShapeWave_Type TimerWave);
/******************************************
  syntax : void M_Timer0_Void_start(Timer0Scaler_Type TimerScaler);


  Description : timer 0 start by setting prescaler
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  timer scaler
  parameters (out) :  Non
  Return Value     : void
******************************************/
void M_Timer0_Void_start(Timer0Scaler_Type TimerScaler);
/******************************************
  syntax : void M_Timer0_Void_stop(void);


  Description : timer 0 stop
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  void
  parameters (out) :  Non
  Return Value     : void
******************************************/
void M_Timer0_Void_stop(void);
/******************************************
  syntax : void M_Timer0_Void_EnableInt(Timer0Mode_Type  TimerMode);


  Description : function enable timer0 interrupet by setting interrupet pin
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  TimerMode
  parameters (out) :  Non
  Return Value     : void
******************************************/
void M_Timer0_Void_EnableInt(Timer0Mode_Type  TimerMode);
/******************************************
  syntax : void M_Timer0_Void_DisableInt(Timer0Mode_Type  TimerMode);


  Description : function disnable timer0 interrupet by Clear interrupet pin
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  timer mode
  parameters (out) :  Non
  Return Value     : void
******************************************/
void M_Timer0_Void_DisableInt(Timer0Mode_Type  TimerMode);
/******************************************
  syntax : u8 M_Timer0_U8_CTCsetCallBack(void (*pf) (void));


  Description : callback function for ctc interupt
  Synch/Asynch     : ASynchronouse
  Reentrance       : Reentrant
  parameters (in)  :  void (*pf) (void)
  parameters (out) :  Non
  Return Value     :error state
******************************************/
u8 M_Timer0_U8_CTCsetCallBack(void (*pf) (void));
/******************************************
  syntax : u8 M_Timer0_U8_OVsetCallBack (void (*pf) (void));


  Description : callback function for OV interupt
  Synch/Asynch     : ASynchronouse
  Reentrance       : Reentrant
  parameters (in)  :  void (*pf) (void)
  parameters (out) :  Non
  Return Value     : error state
******************************************/
u8 M_Timer0_U8_OVsetCallBack (void (*pf) (void));
/******************************************
  syntax : void M_Timer0_Void_setDelayTimeMilliSec(u32 Time_m_Sec,Timer0Mode_Type  Mode_T,Timer0Scaler_Type Scaler);

  Description : by using timer 0 this function calculate delay time
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  num of meli sec ,timer scaler, Timermode
  parameters (out) :  Non
  Return Value     : void
******************************************/
void M_Timer0_Void_setDelayTimeMilliSec(u32 Time_m_Sec,Timer0Mode_Type  Mode_T,Timer0Scaler_Type Scaler);
/******************************************
  syntax : void M_Timer0_Void_setFastPWM(u32 duty,Timer0ShapeWave_Type Shape);



  Description : calc duty of timer 0 in fast mode and set the vakue in OCR0
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  duty,shape
  parameters (out) :  Non
  Return Value     : void
******************************************/
void M_Timer0_Void_setphaseCorrectPWM(u32 duty,Timer0ShapeWave_Type Shape);
/******************************************
  syntax : void M_Timer0_Void_setphaseCorrectPWM(u32 duty,Timer0Scaler_Type Scaler, Timer0ShapeWave_Type Shape);



  Description : calc duty of timer 0 in phaseCorrect mode and set the vaLue in OCR0
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  duty,shape
  parameters (out) :  Non
  Return Value     : void
******************************************/
void M_Timer0_Void_setphaseCorrectPWM(u32 duty,Timer0ShapeWave_Type Shape);
/******************************************
  syntax : u32 M_Timer0_U32_GetCounts(void);

  Description : calc the num of counts in Timer0
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  Non
  parameters (out) :  Non
  Return Value     : U32
******************************************/
u32 M_Timer0_U32_GetCounts(void);


#endif /* TIMER0_TIMER_INT_H_ */

