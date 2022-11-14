//#define regs 
#ifndef			DIO_PRIVATE_H	//3ashan maya3mlsh #include 2aktr min mara ll DIO_private.h
#define			DIO_PRIVATE_H

// efta7 el datasheet w roo7 3ala Register summary w dawar 3ala el registers beta3t el DIO 

/*			PORTA REGISTERS							*/
#define		PORTA_REG			*((volatile u8 *)0x3B)

#define		DDRA_REG			*((volatile u8 *)0x3A)
#define		PINA_REG			*((volatile u8 *)0x39)

/*			PORTB REGISTERS							*/
#define		PORTB_REG			*((volatile u8 *)0x38)
#define		DDRB_REG			*((volatile u8 *)0x37)
#define		PINB_REG			*((volatile u8 *)0x36)

/*			PORTB REGISTERS							*/
#define		PORTC_REG			*((volatile u8 *)0x35)
#define		DDRC_REG			*((volatile u8 *)0x34)
#define		PINC_REG			*((volatile u8 *)0x33)

/*			PORTD REGISTERS							*/
#define		PORTD_REG			*((volatile u8 *)0x32)
#define		DDRD_REG			*((volatile u8 *)0x31)
#define		PIND_REG			*((volatile u8 *)0x30)


#endif
// '*' 3ashan ana ma7tag el mo7tawa elly fih mish el address beta3ah
//'(u8*)' hena ba3mel casting ll pointer 3ashan 2afahimoh eno hayshawer 3ala char (8bit)
//volatile will be explained in next session