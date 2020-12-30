/*
 * TIMER.c
 *
 *  Created on: Oct 14, 2016
 *      Author: toudy
 */

#include "TIMER.h"


extern void TIMER_TimerInit(void)
{
	TCCR0 &= ~(1<<FOC0);
	TCCR0 |= (1<<WGM00) | (1<<WGM01) | (1<<COM00) | (1<<COM01) | (1<<CS01);
	TCCR0 &= ~((1<<CS00) | (1<< CS02));
	TCNT0 = 0;
}

extern void TIMER_SetComparison(u8 value)
{
	OCR0 = value;
}
