#ifndef		Timer0_INTERFACE_H
#define		Timer0_INTERFACE_H

void	Timer0_Init		(void);
void	TIMER0_EnableOverFlowInt(void);
void	TIMER0_EnableCTCInt(void);

void	TIMER0_DisableOverFlowInt(void);
void	TIMER0_DisableCTCInt(void);

void	TIMER0_SetTCNT0(u8 Val);
void	TIMER0_SetOCR0(u16 Val);

void	TIMER0_voidSetCallBackOF(void (*PF)(void));
void	TIMER0_voidSetCallBackCTC(void (*PF)(void));

void	__vector_10 (void)	__attribute__((signal,used));
void	__vector_11 (void)	__attribute__((signal,used));

void	GIE_voidEnable(void);
void	GIE_voidDisable(void);

#endif