/*
 * Timer_Priv.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP lolo
 */

#ifndef _TIMER_PRIV_H_
#define _TIMER_PRIV_H_

#define TIMER0_MODES       0xB7
#define TIMER0_SHAPE       0xCF
#define TIMER0_PRESCALLER  0xF8


#define	 FCPU 16

void __vector_10 (void)__attribute__((signal , used));
void __vector_11 (void)__attribute__((signal , used));


//--------------------Timer0---------------
#define TCCR0    (*((volatile u8*)0x53))
#define TCNT0    (*((volatile u8*)0x52))
#define OCR0     (*((volatile u8*)0x5C))
#define TIMSK    (*((volatile u8*)0x59))
#define TIFR     (*((volatile u8*)0x58))
#define SFIOR    (*((volatile u8*)0x50))

#endif /* TIMER0_TIMER_PRIV_H_ */
