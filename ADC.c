/*
 * ADC.c
 *
 *  Created on: Oct 7, 2016
 *      Author: toudy
 */

#include "ADC.h"

void ADC_vidInit(void)
{
	ADMUX = 0b01100000; // AVCC is vref, Left Adjustment is ON, single ended from ADC0
	ADCSRA = 0b10000000; //enabling ADC but not by trigger or interrupt, Frequency in divided by 2 to make it fast
	ADCH = 0b00000000;
}

u8 ADC_u8ConvAndGetResult(void)
{
	u8 ADCvalue;
	ADCSRA |= 0b01000000; // start conversion

	while((ADCSRA & 0b00010000) == 0); //while the flag is zero, do nothing

	ADCSRA |= 0b00010000; // clear the flag
	ADCvalue = ADCH;
	return ADCvalue;

}

