/*
 * ADC.h
 *
 *  Created on: Oct 7, 2016
 *      Author: toudy
 */

#ifndef ADC_H_
#define ADC_H_
#define ADMUX *((volatile u8*)0x27)
#define ADCSRA *((volatile u8*)0x26)
#define ADCH *((volatile u8*)0x25)
#define ADCL *((volatile u8*)0x24)
#define SFIOR *((volatile u8*)0x50)
#include "types.h"

#endif /* ADC_H_ */

void ADC_vidInit(void);
u8 ADC_u8ConvAndGetResult(void);
