/*****************************************************************************/
/* Author    : Ahmed Mohy													 */
/* Date      : 28 DEC 2021													 */
/* Version   : V01														     */
/*****************************************************************************/

#ifndef		SYSTICK_INTERFACE_H
#define 	SYSTICK_INTERFACE_H


/* function to -----> Initiate STK clocl , Disable SysTick , Disable SysTick interrupt */
void MSTK_voidInit(void);

/* Synchronous function to delay for number of ticks */ 
void MSTK_voidSetBusyWait( u32 Copy_u32Ticks );

/* Asynchronous function to execute a function only once time after number of ticks */ 
void MSTK_voidSetIntervalSingle( u32 Copy_u32Ticks , void (*Copy_Ptr) (void) ) ;

/* Asynchronous function to execute a function periodecally after number of ticks */ 
void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks , void (*Copy_Ptr) (void) ) ;

/* function to stop the SysTick */
void MSTK_voidStopInterval(void);

/* funtion to return number of counted Ticks == Value regiter - Load register */
u32 MSTK_u32GetElapsedTime(void);

/* funtion to return number of  Ticks remaining till interrupt happens = Value regiter */
u32 MSTK_u32GetRemainingTime(void);


#endif
