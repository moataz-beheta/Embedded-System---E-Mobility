#ifndef		ADC_CONFIGURATION_H
#define		ADC_CONFIGURATION_H
/* OPTIONS :
///						Prescaler						///
For Prescaler = 2,						Write Clock_Div_2
For Prescaler = 4,						Write Clock_Div_4
For Prescaler = 8,						Write Clock_Div_8
For Prescaler = 16,						Write Clock_Div_16
For Prescaler = 32,						Write Clock_Div_32
For Prescaler = 64,						Write Clock_Div_64
For Prescaler = 128,					Write Clock_Div_128

///						Vref							///
For Internal(2.54v) Votlage Ref			Write 	Internal
For AVCC Votlage Ref					Write 	AVCC
For AREF Votlage Ref					Write 	AREF

				*/
#define		Prescaler			Clock_Div_128				
#define		V_Ref		 		AVCC					

#endif