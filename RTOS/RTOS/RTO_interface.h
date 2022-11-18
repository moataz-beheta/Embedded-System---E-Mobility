#ifndef 			RTO_INTERfACE_H
#define 			RTO_INTERfACE_H

/* 			Task Data Type 				*/
typedef struct tsk
{
	u16 		u16_periodicity;
	void 	(*PfTask)(void);
	u16 		u16_FirstDelay;
	
}TCB_Tasks;

typedef enum
{
	Scheduler_OK,
	Scheduler_NOK
}ErrorStatus;

/* 			Scheduler APIs				*/

ErrorStatus		RTO_voidCreateTask(u8 Task_ID , u16 periodicity , void  (*pf)(void) , u16 First_Delay);

#endif