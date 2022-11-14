#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"Dio_interface.h"
#include	"Dio_private.h"

Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )
{
	u8 Local_u8Value = 0xFF;		//Initial value, it will be edited
	
	u8 PORT = (ChannelId & PORT_MASK)>>4; 0XF1 0X1111 0001
	u8 PIN 	= ChannelId & PIN_MASK;
	
	/*		Range Check				*/
	if( (PORT < NUM_OF_PORTS) && (PIN < NUM_OF_PINS) )
	{
		
		switch(PORT)
		{
			case PORTA :	Local_u8Value	=	GET_BIT(HWREG(PINA_REG),PIN);	break;
			case PORTB :	Local_u8Value	=	GET_BIT(HWREG(PINB_REG),PIN);	break;
			case PORTC :	Local_u8Value	=	GET_BIT(HWREG(PINC_REG),PIN);	break;
			case PORTD :	Local_u8Value	=	GET_BIT(HWREG(PIND_REG),PIN);	break;
			default    :														break;
		}		
	}	
	else
	{
		Error = DIO_E_PARAM_INVALID_CHANNEL_ID;
	}
	
	return Local_u8Value ;
}


void Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level )
{

	/*		Range Check				*/
	if( PortId < NUM_OF_PORTS )
	{
		if ( (Level == STD_HIGH) || (Level == STD_LOW) )
		{
			switch(PortId)
			{
				case PORTA :	HWREG(PORTA_REG) = Level;	break;
				case PORTB :	HWREG(PORTB_REG) = Level;	break;
				case PORTC :	HWREG(PORTC_REG) = Level;	break;
				case PORTD :	HWREG(PORTD_REG) = Level;	break;
				default    :								break;
			}
		}
		else {}
		
	}
	else
	{
		Error = DIO_E_PARAM_INVALID_PORT_ID;
	}
}

Dio_PortLevelType Dio_ReadPort ( Dio_PortType PortId )
{
	u8 Local_u8Value = 0xFF;		//Initial value, it will be edited
	
	u8 PORT = (ChannelId & PORT_MASK)>>4;
	
	/*		Range Check				*/
	if(PORT < NUM_OF_PORTS)
	{		
		switch(PORT)
		{
			case PORTA :	Local_u8Value	=	HWREG(PINA_REG);	break;
			case PORTB :	Local_u8Value	=	HWREG(PINB_REG);	break;
			case PORTC :	Local_u8Value	=	HWREG(PINC_REG);	break;
			case PORTD :	Local_u8Value	=	HWREG(PIND_REG);	break;
			default    :											break;
		}		
	}	
	else
	{
		Error = DIO_E_PARAM_INVALID_CHANNEL_ID;
	}
	
	return Local_u8Value ;
}






void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
	u8 PORT = (ChannelId & PORT_MASK)>>4;
	u8 PIN 	= ChannelId & PIN_MASK;
	
	/*		Range Check				*/
	if( (PORT < NUM_OF_PORTS) && (PIN < NUM_OF_PINS) )
	{
		
		if(Level == STD_HIGH)
		{
			switch(PORT)
			{
				case PORTA :	SET_BIT(HWREG(PORTA_REG),PIN);	break;
				case PORTB :	SET_BIT(HWREG(PORTB_REG),PIN);	break;
				case PORTC :	SET_BIT(HWREG(PORTC_REG),PIN);	break;
				case PORTD :	SET_BIT(HWREG(PORTD_REG),PIN);	break;
				default    :									break;
			}
		}
		else if (Level == STD_LOW)
		{
			switch(Port)
			{
				case PORTA :	CLR_BIT(HWREG(PORTA_REG),PIN);	break;
				case PORTB :	CLR_BIT(HWREG(PORTB_REG),PIN);	break;
				case PORTC :	CLR_BIT(HWREG(PORTC_REG),PIN);	break;
				case PORTD :	CLR_BIT(HWREG(PORTD_REG),PIN);	break;
				default    :									break;
			}			
		}
		else{}
				
	}
	else
	{
		Error = DIO_E_PARAM_INVALID_CHANNEL_ID;
	}
}

void Dio_MaskedWritePort ( Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask )
{

	/*		Range Check				*/
	if( PortId < NUM_OF_PORTS )
	{
		if ( GET_BIT(HWREG(DDRA_REG) == 1 ) //if the channel is configured as an output channel
			if(Level == STD_HIGH)
			{
				switch(PORT)
				{
					case PORTA :	HWREG(PORTA_REG)|= Mask;	break;
					case PORTB :	HWREG(PORTB_REG)|= Mask;	break;
					case PORTC :	HWREG(PORTC_REG)|= Mask;	break;
					case PORTD :	HWREG(PORTD_REG)|= Mask;	break;
					default    :								break;
				}
			}
			else if (Level == STD_LOW)
			{
				switch(Port)
				{
					case PORTA :	HWREG(PORTA_REG)&= Mask ;	break;
					case PORTB :	HWREG(PORTB_REG)&= Mask ;	break;
					case PORTC :	HWREG(PORTC_REG)&= Mask ;	break;
					case PORTD :	HWREG(PORTD_REG)&= Mask ;	break;
					default    :								break;
				}			
			}
			else {}
	}
	else
	{
		Error = DIO_E_PARAM_INVALID_PORT_ID;
	}
}


Dio_LevelType Dio_FlipChannel ( Dio_ChannelType ChannelId )
{
	u8 PORT = (ChannelId & PORT_MASK)>>4;
	u8 PIN 	= ChannelId & PIN_MASK;
	
	/*		Range Check				*/
	if( (PORT < NUM_OF_PORTS) && (PIN < NUM_OF_PINS) )
	{
		if ( GET_BIT(HWREG(DDRA_REG) == 1 ) //if the channel is configured as an output channel
		{
		switch(PORT)
			{
				case PORTA :	HWREG(PORTA_REG)=~HWREG(PORTA_REG)	break;
				case PORTB :	HWREG(PORTB_REG)=~HWREG(PORTB_REG)	break;
				case PORTC :	HWREG(PORTC_REG)=~HWREG(PORTC_REG)	break;
				case PORTD :	HWREG(PORTD_REG)=~HWREG(PORTD_REG)	break;
				default    :										break;
			}
		}
		else {}
	}
	else
	{
		Error = DIO_E_PARAM_INVALID_CHANNEL_ID;
	}
}

Dio_PortLevelType Dio_ReadChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr )
{
	u8 offset = ChannelGroupIdPtr->offset;
	u8 mask = ChannelGroupIdPtr->mask ;
	u8 Local_u8Value = 0xFF;
	/*		Range Check				*/
	if( ChannelGroupIdPtr->Port < NUM_OF_PORTS )
	{
		if ( GET_BIT(HWREG(DDRA_REG) == 1 ) //if the channel is configured as an output channel
		{
			switch(PORT)
			{
				case PORTA :	Local_u8Value = (HWREG(PINA_REG) & mask<<offset) >>offset ;	break;
				case PORTB :	Local_u8Value = (HWREG(PINB_REG) & mask<<offset) >>offset ;	break;
				case PORTC :	Local_u8Value = (HWREG(PINC_REG) & mask<<offset) >>offset ;	break;
				case PORTD :	Local_u8Value = (HWREG(PIND_REG) & mask<<offset) >>offset ;	break;
				default    :																break;
			}
		}

	}
	else
	{
		Error = DIO_E_PARAM_INVALID_GROUP;
	}
	return Local_u8Value;
}

