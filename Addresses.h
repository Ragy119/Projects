/*
 * Addresses.h
 *
 *  Created on: Sep 3, 2016
 *      Author: Ragy Ahmed
 */

#ifndef ADDRESSES_H_
#define ADDRESSES_H_

typedef struct
{
	u8 bit0:1;
	u8 bit1:1;
	u8 bit2:1;
	u8 bit3:1;
	u8 bit4:1;
	u8 bit5:1;
	u8 bit6:1;
	u8 bit7:1;
}mystuct;

typedef union
{
	mystuct bitaccess;
	u8 byteaccess;
}Reg;

#define DDRA  *((volatile u8*) 0x3A)
#define PORTA *((volatile u8*) 0x3B)
#define PINA  *((volatile u8*) 0x39)

#define DDRB  *((volatile u8*) 0x37)
#define PORTB *((volatile u8*) 0x38)
#define PINB  *((volatile u8*) 0x36)

#define DDRC  *((volatile u8*) 0x34)
#define PORTC *((volatile u8*) 0x35)
#define PINC  *((volatile u8*) 0x33)

#define DDRD  *((volatile u8*) 0x31)
#define PORTD *((volatile u8*) 0x32)
#define PIND  *((volatile u8*) 0x30)

//External interrupt 
#define GICR  *((volatile u8*) 0x5B)
#define MCUCR *((volatile u8*) 0x55)
#define SREG  *((volatile u8*) 0x5F)

//ADC 
#define ADMUX  *((volatile u8*) 0x27)
#define ADCSRA *((volatile u8*) 0x26)
#define ADCH   *((volatile u8*) 0x25)
#define ADCL   *((volatile u8*) 0x24)

//Timer
#define TCCR0 *((volatile u8*) 0x53)
#define TIMSK *((volatile u8*) 0x59)
#define TCNT0 *((volatile u8*) 0x52)
#define TIFR  *((volatile u8*) 0x58)
#define OCR0  *((volatile u8*) 0x5C)

#define TCCR1A *((volatile u8*) 0x4F)
#define TCCR1B *((volatile u8*) 0x4E)
#define TCNT1L *((volatile u8*) 0x4C)
#define TCNT1H *((volatile u8*) 0x4D)
#define ICR1H  *((volatile u8*) 0x47)
#define ICR1L  *((volatile u8*) 0x46)
#define OCR1AL *((volatile u8*) 0x4A)
#define OCR1AH *((volatile u8*) 0x4B)


// USART
#define UDR    *((volatile u8*) 0x2C)
#define UCSRA  *((volatile u8*) 0x2B)
#define UCSRB  *((volatile u8*) 0x2A)
#define UCSRC  *((volatile u8*) 0x40)
#define UBRRL  *((volatile u8*) 0x29)
#define UBRRH  *((volatile u8*) 0x40)


//SPI
#define SPCR   *((volatile u8*) 0x2D)
#define SPSR   *((volatile u8*) 0x2E)
#define SPDR   *((volatile u8*) 0x2F)

#endif /* ADDRESSES_H_ */
