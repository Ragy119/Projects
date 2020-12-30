/*
 * TIMER.h
 *
 *  Created on: Oct 14, 2016
 *      Author: toudy
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "types.h"

#define  TCCR0 *((volatile u8*) 0x53)
#define  TCNT0 *((volatile u8*) 0x52)
#define  OCR0 *((volatile u8*) 0x5C)
#define  TIMSK *((volatile u8*) 0x59)
#define  TIFR *((volatile u8*) 0x58)
#define FOC0 7
#define WGM00 3
#define WGM01 6
#define COM00 4
#define COM01 5
#define CS00 0
#define	CS01 1
#define	CS02 2
#define OCF0 1
#define TOV0 0


extern void TIMER_SetComparison(u8 value);
extern void TIMER_TimerInit(void);



#endif /* TIMER_H_ */
