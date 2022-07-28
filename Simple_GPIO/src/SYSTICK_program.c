/*****************************************************************************/
/* Author    : Ahmed Mohy													 */
/* Date      : 28 DEC 2021													 */
/* Version   : V01														     */
/*****************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"
#include "SYSTICK_private.h"




/* function to -----> Initiate STK cloclK , Disable SysTick , Disable SysTick interrupt */
void MSTK_voidInit(void)
{
	#if		SYSTICK_CLOCK_SOURCE == AHB_CLOCK 
		SYSTICK->CTRL = 0X00000004;				/*Set STK cloclK to AHP , Disable SysTick , Disable SysTick interrupt */
	
	#elif	SYSTICK_CLOCK_SOURCE == AHB_CLOCK_DIV_8 
		SYSTICK->CTRL = 0;						/*Set STK cloclK to AHP/8 , Disable SysTick , Disable SysTick interrupt */
	
	#else
		#error("invalid choice")
	
	#endif
}

/* Synchronous function to delay for number of ticks */ 
void MSTK_voidSetBusyWait( u32 Copy_u32Ticks )
{
	SYSTICK->LOAD = Copy_u32Ticks ;					// put Ticks to load register 
	SET_BIT(SYSTICK->CTRL , 0) ;					// Enable SysTick Timer
	while (GET_BIT(SYSTICK->CTRL , 16) == 0) ;		// Wait till flag is raised
	u8 Local_u8Temporary = GET_BIT(SYSTICK->CTRL , 16) ;  //clear SysTick interrupt flag 
	CLR_BIT(SYSTICK->CTRL , 0) ;					// stop SysTick Timer
	SYSTICK->VAL = 0;
	SYSTICK->LOAD = 0;
}


/* Asynchronous function to execute a function only once time after number of ticks */ 
void MSTK_voidSetIntervalSingle( u32 Copy_u32Ticks , void (*Copy_Ptr) (void) )
{
	CLR_BIT(SYSTICK->CTRL , 0) ;					// Disable SysTick Timer
	SYSTICK->VAL = 0;
	SYSTICK->LOAD = 0;
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL ;	//set mode to single
	MSTK_CallBack = Copy_Ptr ;							//Save callback
	SYSTICK->LOAD = Copy_u32Ticks ;					// put Ticks to load register 
	SET_BIT(SYSTICK->CTRL , 1) ;					// Enable SysTick interrupt when under flow (counts down till reach 0)
	SET_BIT(SYSTICK->CTRL , 0) ;					// Enable SysTick Timer
}


/* Asynchronous function to execute a function periodecally after number of ticks */ 
void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks , void (*Copy_Ptr) (void) )
{
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL ;		//set mode to periodic
	MSTK_CallBack = Copy_Ptr ;							//Save callback
	SYSTICK->LOAD = Copy_u32Ticks ;					// put Ticks to load register 
	SET_BIT(SYSTICK->CTRL , 1) ;					// Enable SysTick interrupt when under flow (counts down till reach 0)
	SET_BIT(SYSTICK->CTRL , 0) ;					// Enable SysTick Timer
}


/* function to stop the SysTick */
void MSTK_voidStopInterval(void)
{
	SYSTICK->CTRL = 0;
	SYSTICK->VAL = 0;
	SYSTICK->LOAD = 0;
}


/* funtion to return number of counted Ticks == Value regiter - Load register */
u32 MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	
	Local_u32ElapsedTime = SYSTICK->LOAD - SYSTICK->VAL ;
	
	return Local_u32ElapsedTime;
}


/* funtion to return number of  Ticks remaining till interrupt happens = Value regiter */
u32 MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainTime;
	
	Local_u32RemainTime = SYSTICK->VAL  ;
	
	return Local_u32RemainTime;
}



/* ISR function of SysTick */
void SysTick_Handler(void)
{
	u8 Local_u8Temporary;
	
	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(SYSTICK->CTRL, 1);
		
		/* Stop Timer */
		CLR_BIT(SYSTICK->CTRL, 0);
		SYSTICK -> LOAD = 0;
		SYSTICK -> VAL  = 0;
	}
	
	/* Callback notification */
	MSTK_CallBack();
	
	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(SYSTICK->CTRL,16);
}



