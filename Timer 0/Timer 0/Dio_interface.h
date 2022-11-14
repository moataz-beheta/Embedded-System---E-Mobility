//fn prototypes + #define
//habi3 eih ll user, dah elly batala3o ll user

#ifndef			DIO_INTERFACE_H
#define			DIO_INTERFACE_H

void	DIO_voidSetPinDirection(u8 Port ,u8 Pin , u8 Direction ); // this pin will be used as i/p or o/p
void	DIO_voidSetPinValue(u8 Port ,u8 Pin , u8 Value );        // this o/p pin will high or low
u8		DIO_u8GetPinValue(u8 Port , u8 Pin);                     // this i/p pin is high or low
void	DIO_voidSetPortDirection(u8 Port ,u8 Direction ); // this port will be used as i/p or o/p
void	DIO_voidSetPortValue(u8 Port , u8 Value );        // this o/p port will high or low

#define				PORTA			0
#define				PORTB			1
#define				PORTC			2
#define				PORTD			3

#define				PIN0			0
#define				PIN1			1
#define				PIN2			2
#define				PIN3			3
#define				PIN4			4
#define				PIN5			5
#define				PIN6			6
#define				PIN7			7


#define				INPUT			0
#define				OUTPUT			1

#define				HIGH			1
#define				LOW				0

//Example
//DIO_voidSetPinDirection(PORTA , PIN0 , OUTPUT);
// ==>> DDRA =0B00000001;
// hena 2a7san 3ashan keda mish readable, w kaman mish hay2assar 3ala el pins elly ma3aha fi el port
// A0 is OUTPUT
//DIO_voidSetPinValue(PORTA , PIN0 , HIGH);
// A0 is set high

#endif