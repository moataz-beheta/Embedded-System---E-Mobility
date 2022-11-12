#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_configuration.h"
#include "ADC_Private.h"
#include "ADC_Register.h"
#include "ADC_interface.h"

u16 *ADC_Result;
void(*ADC_END_OF_JOB)(void);
u8 Status = IDLE;

void	ADC_Init	(void)
{
	/*	Enable ADC		*/
	SET_BIT(ADCSRA,7);
	
	/*	Voltage Reference		*/
	
	#if 	V_Ref == AREF
	CLR_BIT(ADMUX,6);	//REFS0 Pin
	CLR_BIT(ADMUX,7);	//REFS1 Pin
	
	#elif 	V_Ref == AVCC
	SET_BIT(ADMUX,6);	//REFS0 Pin
	CLR_BIT(ADMUX,7);	//REFS1 Pin
	
	#elif 	V_Ref == Internal
	SET_BIT(ADMUX,6);	//REFS0 Pin
	SET_BIT(ADMUX,7);	//REFS1 Pin
	
	#else
	#error	"Wrong Choice of ADC Voltage Reference!"
	#endif
	
	/*	Prescaler				*/
	#if 	Prescaler == Clock_Div_2
	CLR_BIT(ADCSRA,0);	//ADPS0 Pin
	CLR_BIT(ADCSRA,1);	//ADPS1 Pin
	CLR_BIT(ADCSRA,2);	//ADPS2 Pin
	
	#elif 	Prescaler == Clock_Div_4
	CLR_BIT(ADCSRA,0);	//ADPS0 Pin
	SET_BIT(ADCSRA,1);	//ADPS1 Pin
	CLR_BIT(ADCSRA,2);	//ADPS2 Pin
	
	#elif 	Prescaler == Clock_Div_8
	SET_BIT(ADCSRA,0);	//ADPS0 Pin
	SET_BIT(ADCSRA,1);	//ADPS1 Pin
	CLR_BIT(ADCSRA,2);	//ADPS2 Pin
	
	#elif 	Prescaler == Clock_Div_16
	CLR_BIT(ADCSRA,0);	//ADPS0 Pin
	CLR_BIT(ADCSRA,1);	//ADPS1 Pin
	SET_BIT(ADCSRA,2);	//ADPS2 Pin
	
	#elif 	Prescaler == Clock_Div_32
	SET_BIT(ADCSRA,0);	//ADPS0 Pin
	CLR_BIT(ADCSRA,1);	//ADPS1 Pin
	SET_BIT(ADCSRA,2);	//ADPS2 Pin

	#elif 	Prescaler == Clock_Div_64
	CLR_BIT(ADCSRA,0);	//ADPS0 Pin
	SET_BIT(ADCSRA,1);	//ADPS1 Pin
	SET_BIT(ADCSRA,2);	//ADPS2 Pin

	#elif 	Prescaler == Clock_Div_128
	SET_BIT(ADCSRA,0);	//ADPS0 Pin
	SET_BIT(ADCSRA,1);	//ADPS1 Pin
	SET_BIT(ADCSRA,2);	//ADPS2 Pin
	
	#else
	#error	"Wrong Choice of ADC Prescaler!"
	#endif
}

ADC_ERROR_STATUS	ADC_StartConvSyn	(u8 Channel, u16 *result)
{
	u8 ErrorStatus = OK;
	if ((result == NULL) | (Channel>7))
	{
		ErrorStatus = NOK;
	}
	else
	{
		ADMUX |= Channel;
		u8 TimerOutCounter = 0;
		
		/*	Start Single Conversion		*/
		SET_BIT(ADCSRA,6);
		
		/* wait till conversion is done		*/
		while	( ((GET_BIT(ADCSRA,4)) == 0) && (TimerOutCounter<1000) )
		{
			TimerOutCounter++;
		}
		if (TimerOutCounter == 1000)
		{
			ErrorStatus= NOK;			
		}
		
		SET_BIT(ADCSRA,4);	//Clear Flag
		
		/*	Read The Conversion Value	*/
		*result = ADC;

		return ErrorStatus;	
	}
}

ADC_ERROR_STATUS	ADC_StartConvASyn	(u8 Channel, u16 *result, void(*ptrfun)(void))
{
	u8 ErrorStatus = OK;
	if ((ptrfun == NULL) || (result == NULL) || (Channel>7))
	{
		ErrorStatus = NOK;	
	}
	
	if (Status==IDLE)
	{
		Status = BUSY;
		ADC_Result = result;
		ADC_END_OF_JOB = ptrfun;
		
		ADMUX |= Channel;
		
		/*	Interrupt Enable 			*/
		SET_BIT(ADCSRA,3);
		
		/*	Start Single Conversion		*/
		SET_BIT(ADCSRA,6);
	}	
	return ErrorStatus;
}

void	__vector_16 (void) //ADC Conversion Complete
{ 
	*ADC_Result = ADC;
	ADC_END_OF_JOB(); //ADCCallBack_PF
	Status = IDLE;
}

void GIE_voidEnable(void)
{
	SET_BIT(SREG,7);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,7);
}