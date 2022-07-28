/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  1 January 2022             */
/* Version :  V01                        */
/*****************************************/


#ifndef		OS_INTERFACE_H
#define		OS_INTERFACE_H

#define		TASK_SUSPEND			0
#define		TASK_READY				1

void SOS_voidCreateTask( u8 Copy_u8TaskPeriority , u16 Copy_u16Periodicity , void (*CopyPtr) (void) , u16 Copy_u16FirstDelay );

void SOS_voidStart(void);

void SOS_voidSuspendTask(u8 Copy_u8TaskPeriority);

void SOS_voidResumeTask(u8 Copy_u8TaskPeriority);

void SOS_voidKillTask(u8 Copy_u8TaskPeriority);


#endif
