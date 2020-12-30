#include"types.h"
#include"Addresses.h"
#define F_CPU 16000000
#include"avr/delay.h"

void DIO_VidInitPortDir(void)
{
	DDRA = 0x00;    // IN
	DDRB = 0xFF;    // OUT
	DDRC = 0xFF;
	DDRD = 0xFE;    //USART    0b 1111 1110
}

void DIO_VidInitPortValue(void)
{
	PORTA=0x00;
	PORTB=0x00;
	PORTC=0x00;
	PORTD=0x00;
}

void DIO_VidWritPin(u8 copy_u8PinNum,u8 copy_u8PinVal)
{
	u8 local_u8RealPortNum;
	u8 local_u8RealPinNum;
	u8 local_u8Flag;

	local_u8RealPortNum=copy_u8PinNum/8;
	local_u8RealPinNum=copy_u8PinNum%8;

	if(copy_u8PinVal==0)
	{
		local_u8Flag  = local_u8Flag & (~(1<<local_u8RealPinNum));
	}
	else if(copy_u8PinVal==1)
	{
		local_u8Flag  = local_u8Flag | (1<<local_u8RealPinNum);
	}

	if (copy_u8PinNum>=0 && copy_u8PinNum<=7)
	{
		PORTA=local_u8Flag;
	}
	else if (copy_u8PinNum>=8 && copy_u8PinNum<=15)
	{
		PORTB=local_u8Flag;
	}
	else if (copy_u8PinNum>=16 && copy_u8PinNum<=23)
	{
		PORTC=local_u8Flag;
	}
	else if (copy_u8PinNum>=24 && copy_u8PinNum<=31)
	{
		PORTD=local_u8Flag;
	}

}

u8 DIO_u8ReadPin(u8 copy_u8PinNum)
{
	u8 local_u8RealPinNum;
	u8 local_u8Flag;
	u8 local_u8ReadedValue;

	local_u8RealPinNum=copy_u8PinNum%8;

	if (copy_u8PinNum>=0 && copy_u8PinNum<=7)
	{
		local_u8Flag=PINA;
	}
	else if (copy_u8PinNum>=8 && copy_u8PinNum<=15)
	{
		local_u8Flag=PINB;
	}
	else if (copy_u8PinNum>=16 && copy_u8PinNum<=23)
	{
		local_u8Flag=PINC;
	}
	else if (copy_u8PinNum>=24 && copy_u8PinNum<=31)
	{
		local_u8Flag=PIND;
	}

	local_u8ReadedValue = (local_u8Flag>>local_u8RealPinNum) & 0x01;
	return local_u8ReadedValue;
}

void DIO_VidWritPort(u8 copy_u8PortNum,u8 copy_u8PortVal)
{
	if(copy_u8PortNum==1)
	{
		if (copy_u8PortVal==1)
		{
			PORTA=0xFF;
		}
		else
		{
			PORTA=0x00;
		}

	}
	else if(copy_u8PortNum==2)
	{
		if (copy_u8PortVal==1)
		{
			PORTB=0xFF;
		}
		else
		{
			PORTB=0x00;
		}
	}
	else if(copy_u8PortNum==3)
	{
		if (copy_u8PortVal==1)
		{
			PORTC=0xFF;
		}
		else
		{
			PORTC=0x00;
		}
	}
	else if(copy_u8PortNum==4)
	{
		if (copy_u8PortVal==1)
		{
			PORTD=0xFF;
		}
		else
		{
			PORTD=0x00;
		}
	}
}

u8 DIO_u8ReadPort(u8 copy_u8PortNum)
{
	u8 local_u8ReadedValue;
	if(copy_u8PortNum==1)
	{
		local_u8ReadedValue=PINA;
	}
	else if(copy_u8PortNum==2)
	{
		local_u8ReadedValue=PINB;
	}
	else if(copy_u8PortNum==3)
	{
		local_u8ReadedValue=PINC;
	}
	else if(copy_u8PortNum==4)
	{
		local_u8ReadedValue=PIND;
	}
	return local_u8ReadedValue;
}

