#ifndef			DIO_PRIVATE_H	
#define			DIO_PRIVATE_H

#define		NUM_OF_PORTS	4
#define		NUM_OF_PINS		8
	
#define		HWREG(REG)			*((volatile u8 *)REG)

#define		SFIOR_REG			0x50
#define		PUD_PIN				2

/*			PORTA REGISTERS							*/
#define		PORTA_REG			0x3B
#define		DDRA_REG			0x3A
#define		PINA_REG			0x39

/*			PORTB REGISTERS							*/
#define		PORTB_REG			0x38
#define		DDRB_REG			0x37
#define		PINB_REG			0x36

/*			PORTB REGISTERS							*/
#define		PORTC_REG			0x35
#define		DDRC_REG			0x34
#define		PINC_REG			0x33

/*			PORTD REGISTERS							*/
#define		PORTD_REG			0x32
#define		DDRD_REG			0x31
#define		PIND_REG			0x30


#endif