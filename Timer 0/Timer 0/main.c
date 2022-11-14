/*
 * Timer 0.c
 *
 * Created: 9/29/2021 5:25:10 PM
 * Author : Moataz
 */ 

//#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Dio_interface.h"
#include "Timer0_interface.h"
#include "Dio_private.h"
#define  F_CPU		16000000UL

volatile u8 count =0;

void 	Toggle_Led	(void);

int main(void)
{
		TIMER0_voidSetCallBackCTC(Toggle_Led);
		GIE_voidEnable();
		Timer0_Init		();
		TIMER0_EnableCTCInt();
		TIMER0_SetTCNT0(0);
		TIMER0_SetOCR0(199);
		TIMER0_EnableOverFlowInt();
		TIMER0_DisableOverFlowInt();
		
		
		
		
		DIO_voidSetPinDirection(PORTC,PIN7,OUTPUT);
				
    while (1) 
    {
		
    }
}

void 	Toggle_Led	(void)
{
	if (count == 78)
	{
		static u8 flag = 0 ;
		if(flag == 0)
		{
			DIO_voidSetPinValue(PORTC , PIN7 , HIGH);
			flag = 1;
		}
		else
		{
			DIO_voidSetPinValue(PORTC , PIN7 , LOW);
			flag = 0;
		}
		count = 0;
	}
	count++;
}
