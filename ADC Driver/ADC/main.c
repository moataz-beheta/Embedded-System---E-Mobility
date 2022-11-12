/*
 * ADC.c
 *
 * Created: 1/12/2022 12:59:03 PM
 * Author : Moataz
 */ 

#include "STD_TYPES.h"
#include "Dio_interface.h"
#include "ADC_interface.h"
#include <util/delay.h>
void LED_ON(void);
u16	Local_Digital_Value=0;

int main(void)
{
	GIE_voidEnable	();
	ADC_Init		();
	
	
	u8 Status;
	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT);	//led0
	DIO_voidSetPinDirection(PORTC,PIN7,OUTPUT);	//led1
	DIO_voidSetPinDirection(PORTD,PIN3,OUTPUT);	//led2
	DIO_voidSetPinDirection(PORTC,PIN0,OUTPUT);	//Error_LED
	
	DIO_voidSetPinValue(PORTC,PIN2,LOW);
	DIO_voidSetPinValue(PORTC,PIN7,LOW);
	DIO_voidSetPinValue(PORTD,PIN3,LOW);
	DIO_voidSetPinValue(PORTC,PIN0,LOW);
	
    /* Replace with your application code */
    while (1) 
    {
		
				//ASynchronous Function
				Status=	ADC_StartConvASyn	(ADC7, &Local_Digital_Value,  LED_ON);
				if (Status == OK)
				{
					DIO_voidSetPinValue(PORTC,PIN0,LOW);
				}
				else if (Status == NOK)
				{
					DIO_voidSetPinValue(PORTC,PIN0,HIGH);
				}
				
				
//		//Synchronous Function
//		Status= ADC_StartConvSyn	(ADC7, &Local_Digital_Value);
//		if (Status == OK)
//		{
//			DIO_voidSetPinValue(PORTC,PIN0,LOW);
//		}
//		else if (Status == NOK)
//		{
//			DIO_voidSetPinValue(PORTC,PIN0,HIGH);
//		}
		

		
	}
}
void LED_TEST(void)
{
		DIO_voidSetPinValue(PORTC,PIN2,HIGH);	//led0
		DIO_voidSetPinValue(PORTC,PIN7,HIGH);	//led1
		DIO_voidSetPinValue(PORTD,PIN3,HIGH);	//led2
}
void LED_ON(void)
{
	u16 Local_Analog_Value = (Local_Digital_Value*5000UL)/1024;
	if (Local_Analog_Value <=1000) //1000mV
	{
		DIO_voidSetPinValue(PORTC,PIN2,HIGH);	//led0
		DIO_voidSetPinValue(PORTC,PIN7,LOW);	//led1
		DIO_voidSetPinValue(PORTD,PIN3,LOW);	//led2
	}
	
	else if (Local_Analog_Value <=4000 && Local_Analog_Value >1000 )
	{
		DIO_voidSetPinValue(PORTC,PIN2,LOW);	//led0
		DIO_voidSetPinValue(PORTC,PIN7,HIGH);	//led1
		DIO_voidSetPinValue(PORTD,PIN3,HIGH);	//led2
	}

	else
	{
		DIO_voidSetPinValue(PORTC,PIN2,HIGH);	//led0
		DIO_voidSetPinValue(PORTC,PIN7,LOW);	//led1
		DIO_voidSetPinValue(PORTD,PIN3,HIGH);	//led2
	}
}