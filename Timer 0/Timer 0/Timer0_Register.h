#ifndef		Timer0_REGISTER_H
#define		Timer0_REGISTER_H


#define		TCCR0		*((volatile u8 *)0x53)
#define		TCNT0		*((volatile u8 *)0x52)
#define		OCR0		*((volatile u8 *)0x5C)
#define		TIMSK		*((volatile u8 *)0x59)
#define		TIFR		*((volatile u16*)0x58) 
#define		SREG		*((volatile u8 *)0x5F) //for enabling global interrupt

#endif