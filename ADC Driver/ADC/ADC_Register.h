#ifndef		ADC_REGISTER_H
#define		ADC_REGISTER_H


#define		ADMUX		*((volatile u8 *)0x27)
#define		ADCSRA		*((volatile u8 *)0x26)
//#define		ADCH		*((volatile u8 *)0x25)
//#define		ADCL		*((volatile u8 *)0x24)
#define		ADC			*((volatile u16*)0x24) //badal ma 2a2ra ADCH lowa7doh ba3d keda ADCL w 2a7otohom ganb ba3d, keda hay3mel el kalam dah 3ala tool
#define		SFIOR		*((volatile u8 *)0x50)
#define		SREG		*((volatile u8 *)0x5F) //for enabling global interrupt




#endif