/*
 * main_All_RTOS.c
 *
 *  Created on: Dec 30, 2016
 *      Author: Ragy Ahmed
 */


#include"types.h"
#include"DIO.h"
#include"ADC.h"
#include"TIMER.h"
#include"USART.h"

#include"FreeRTOS.h"
#include"task.h"
#include"semphr.h"


xSemaphoreHandle sem_PIR;
xSemaphoreHandle sem_Bluetooth;


void Bluetooth_module(void *pv)
{
	u8 bluetooth_data = '0';

	while(1)
	{
		//if ((UCSRA & 0b10000000) != 0)
		if(USART_u8CheckReceive() != 0)
		{
			//PORTD ^= 0x1C;    //check
			bluetooth_data = USART_u8ReadChar();

			if(bluetooth_data == '1')
			{
				xSemaphoreGive(sem_Bluetooth);
//				PORTD ^= 0b00010000;   //check
			}
			else if(bluetooth_data == '0')
			{
				xSemaphoreTake(sem_Bluetooth,1000);
//				PORTD ^= 0b00100000;   //check
			}
			else
			{
//				PORTD ^= 0b01000000;   //check
			}
		}
		else
		{
			if(bluetooth_data == '1')
			{
				xSemaphoreGive(sem_Bluetooth);
			}
			else if(bluetooth_data == '0')
			{
				xSemaphoreTake(sem_Bluetooth,1000);
			}
		}

		vTaskDelay(100);
	}
}


void PIR_sensor(void *pv)
{

	while(1)
	{
//		PORTD ^= 0b00001000;    //check

		//if((PINA & 0x02) == 0x02)
		if(DIO_u8ReadPin(1) == 1)
		{
			xSemaphoreGive(sem_PIR);
		}
		else
		{
			xSemaphoreTake(sem_PIR,1000);
		}

		vTaskDelay(50);
	}
}


void lamp (void *pv)
{
	u8 ret1,ret2,ADCValue;

	while(1)
	{
//		PORTD ^= 0b00000100;   //check

		ret1 = xSemaphoreTake(sem_PIR,1000);
		ret2 = xSemaphoreTake(sem_Bluetooth,1000);

		if ((ret1 == 1) && (ret2 == 1))
		{
			ADCValue =  ADC_u8ConvAndGetResult();
			TIMER_SetComparison(ADCValue);
			//OCR0 = ADCValue;
//			PORTC = 0xFF;      //represent output
			xSemaphoreGive(sem_PIR);
			xSemaphoreGive(sem_Bluetooth);
		}
		else
		{
			//OCR0 = 255;
			TIMER_SetComparison(255);
//			PORTC = 0x00;
		}

		vTaskDelay(50);
	}
}


int main(void)
{
	DIO_VidInitPortDir();
	DIO_VidInitPortValue();

	//============ Initialization ====================
	ADC_vidInit();
	TIMER_TimerInit();
	USART_vodinit();

	//============ Semaphores ========================
	vSemaphoreCreateBinary(sem_PIR);
	xSemaphoreTake(sem_PIR,1000);
	vSemaphoreCreateBinary(sem_Bluetooth);
	xSemaphoreTake(sem_Bluetooth,1000);

	//============ Tasks =============================
	xTaskCreate(Bluetooth_module,NULL,60,NULL,2,NULL);
	xTaskCreate(PIR_sensor,NULL,60,NULL,2,NULL);
	xTaskCreate(lamp,NULL,60,NULL,1,NULL);

	vTaskStartScheduler();


//	u8 ADCValue;
//	while(1)
//	{
//		if((PINA & 0x02) == 0x02)
//		{
//			ADCValue =  ADC_u8ConvAndGetResult();
//			OCR0 = ADCValue;
//		}
//		else
//			OCR0 = 255;
//	}


	return 0;
}

