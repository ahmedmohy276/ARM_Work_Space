/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  1 January 2022             */
/* Version :  V01                        */
/*****************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"

#include "OS_interface.h"
#include "OS_config.h"
#include "OS_private.h"




void SOS_voidCreateTask( u8 Copy_u8TaskPeriority , u16 Copy_u16Periodicity , void (*CopyPtr) (void) , u16 Copy_u16FirstDelay )
{
	/* Set task parameters in its structure element */
	OS_Task[Copy_u8TaskPeriority].TaskHandler = CopyPtr ;
	OS_Task[Copy_u8TaskPeriority].Periodicity = Copy_u16Periodicity ;
	OS_Task[Copy_u8TaskPeriority].FirstDelay  = Copy_u16FirstDelay ;
	OS_Task[Copy_u8TaskPeriority].State       = TASK_READY ;
}


void SOS_voidStart(void)
{
	/* Initialize SysTick to HSE/8 = 1MHZ -----> Tick time = 1 usec */
	MSTK_voidInit();
	/* Initialize systick to execute Scheduler function  periodically every 1msec = 1000 usec */ 
	MSTK_voidSetIntervalPeriodic(1000 , Scheduler);
}


static void Scheduler (void)
{
	u16 Local_u16Index = 0 ;
	/* Loop to the tasks */
	for (Local_u16Index=0 ; Local_u16Index < NUM_OF_TASKS ; Local_u16Index++)
	{
		/* Check if task is Suspended or Killed */
		if ( (OS_Task[Local_u16Index].TaskHandler != NULL) && (OS_Task[Local_u16Index].State == TASK_READY) )
		{
			/* check till FirstDelay = 0 */
			if (OS_Task[Local_u16Index].FirstDelay == 0)
			{
				/* Set FirstDelay to Periodicity - 1 */
				OS_Task[Local_u16Index].FirstDelay = OS_Task[Local_u16Index].Periodicity - 1 ;
				/* Respond to the specific task */
				OS_Task[Local_u16Index].TaskHandler();
			}
			else
			{
				/* decrement FirstDelay */
				OS_Task[Local_u16Index].FirstDelay-- ;
			}
		}
		else
		{
			/* Do nothing */
		}
	}
}


void SOS_voidSuspendTask(u8 Copy_u8TaskPeriority)
{
	OS_Task[Copy_u8TaskPeriority].State = TASK_SUSPEND ;
}


void SOS_voidResumeTask(u8 Copy_u8TaskPeriority)
{
	OS_Task[Copy_u8TaskPeriority].State = TASK_READY ;
}


void SOS_voidKillTask(u8 Copy_u8TaskPeriority)
{
	OS_Task[Copy_u8TaskPeriority].TaskHandler = NULL ;
}
