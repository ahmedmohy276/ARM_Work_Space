/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  1 January 2022             */
/* Version :  V01                        */
/*****************************************/



#ifndef		OS_PRIVATE_H
#define		OS_PRIVATE_H


#define 	NULL			((void *)0)


typedef	struct 
{
	void (*TaskHandler) (void) ;
	u16	Periodicity ;
	u16 FirstDelay ;
	u8 State ;
}Task;

/* Array of TASK  "Array of structure " */
static Task OS_Task[NUM_OF_TASKS]  ;

static void Scheduler (void);


#endif
