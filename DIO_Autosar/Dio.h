#ifndef			DIO_H
#define			DIO_H

#define NM_DEV_ERROR_DETECT STD_ON

#define				PORTA			0
#define				PORTB			1
#define				PORTC			2
#define				PORTD			3

#define DIO_E_PARAM_INVALID_CHANNEL_ID 	0x0A	//Invalid channel requested
#define DIO_E_PARAM_INVALID_PORT_ID 	0x14	//Invalid port requested
#define DIO_E_PARAM_INVALID_GROUP		0x1F	//Invalid channel group requested
#define DIO_E_PARAM_POINTER				0x20	//API service called with a NULL pointer

#define STD_HIGH	1
#define STD_LOW		0

typedef	enum
{
	Channel_0 = 0x00,		//0x00		//PortA Pin0
	Channel_1,				//0x01      //PortA Pin1
	Channel_2,				//0x02      //PortA Pin2
	Channel_3,				//0x03      //PortA Pin3
	Channel_4,				//0x04      //PortA Pin4
	Channel_5,				//0x05      //PortA Pin5
	Channel_6,				//0x06      //PortA Pin6
	Channel_7,				//0x07      //PortA Pin7
	
	Channel_8 = 0x10,		//0x10      //PortB Pin0
	Channel_10,				//0x11      //PortB Pin1
	Channel_11,				//0x12      //PortB Pin2
	Channel_12,				//0x13      //PortB Pin3
	Channel_13,				//0x14      //PortB Pin4
	Channel_14,				//0x15      //PortB Pin5
	Channel_15,				//0x16      //PortB Pin6
	Channel_16,				//0x17      //PortB Pin7
	
	Channel_17 = 0x20,		//0x20      //PortC Pin0
	Channel_18              //0x21      //PortC Pin1
	Channel_19,				//0x22      //PortC Pin2
	Channel_20,				//0x23      //PortC Pin3
	Channel_21,				//0x24      //PortC Pin4
	Channel_22,				//0x25      //PortC Pin5
	Channel_23,				//0x26      //PortC Pin6
	Channel_24,				//0x27      //PortC Pin7
	
	Channel_25 = 0x30,		//0x30      //PortD Pin0
	Channel_26,				//0x31      //PortD Pin1
	Channel_27,				//0x32      //PortD Pin2
	Channel_28,				//0x33      //PortD Pin3
	Channel_29,				//0x34      //PortD Pin4
	Channel_30,				//0x35      //PortD Pin5
	Channel_31,				//0x36      //PortD Pin6
	Channel_32,				//0x37      //PortD Pin7

	
} Channels;
#define PORT_MASK	 (-1<<4)
#define PIN_MASK	~(-1<<4)
	

typedef uint8 Dio_ChannelType			//Numeric ID of a DIO channel
typedef uint8 Dio_PortType				//Numeric ID of a DIO port
typedef	uint8 Dio_LevelType				//These are the possible levels a DIO channel can have (input or output)
typedef	uint8 Dio_PortLevelType			//If the μC owns ports of different port widths (e.g. 4, 8,16...Bit) Dio_PortLevelType inherits the size of the largest port.

typedef struct 
{
	uint8 mask;			//This element mask which defines the positions of the channel group
	uint8 offset;		//This element shall be the position of the Channel Group on the port, counted from the LSB.
	Dio_PortType port;	//This shall be the port on which the Channel group is defined.
	
}Dio_ChannelGroupType; //Type for the definition of a channel group, which consists of several adjoining channels within a port.


Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId );

void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level );

Dio_PortLevelType Dio_ReadPort ( Dio_PortType PortId );

void Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level );

Dio_PortLevelType Dio_ReadChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr );

void Dio_WriteChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level );

void Dio_GetVersionInfo ( Std_VersionInfoType* VersionInfo );

Dio_LevelType Dio_FlipChannel ( Dio_ChannelType ChannelId );

void Dio_MaskedWritePort ( Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask );

#endif