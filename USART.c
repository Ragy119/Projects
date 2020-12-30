#include"types.h"
#include"Addresses.h"
#define F_CPU 16000000
#include"avr/delay.h"

void USART_vodinit(void)
{
	UCSRB=0b00011000;
	UCSRC=0b10000110; // 8-bits  // 1-bit stop // no parity // Async

	UBRRL=103;
	UBRRH=0;
}

u8 USART_u8ReadChar(void)
{
//	if((UCSRA & 0b10000000) != 0)
//	{
//		return UDR;
//	}
//	else
//	{
//
//	}
	while((UCSRA & 0b10000000) == 0);
	return UDR;
}

u8 USART_u8CheckReceive(void)
{
	if((UCSRA & 0b10000000) != 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
}

void USART_u8WriteData(u8 Data)
{
	while((UCSRA & 0b00100000) == 0);
	UDR=Data;
}
