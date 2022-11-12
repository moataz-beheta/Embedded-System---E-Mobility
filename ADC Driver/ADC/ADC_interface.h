#ifndef		ADC_INTERFACE_H
#define		ADC_INTERFACE_H

typedef enum
{
	OK,
	NOK
} ADC_ERROR_STATUS;

typedef enum
{
	IDLE,
	BUSY
}ADC_STATE;

typedef enum
{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
}ADC_CHANNELS;

void	ADC_Init		(void);
void	GIE_voidEnable(void);
void	GIE_voidDisable(void);
void	__vector_16 (void)	__attribute__((signal,used));

ADC_ERROR_STATUS	ADC_StartConvSyn	(u8 Channel, u16 *result);
ADC_ERROR_STATUS	ADC_StartConvASyn	(u8 Channel, u16 *result, void(*ptrfun)(void));

#endif