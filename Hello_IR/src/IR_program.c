/****************************************************************/
/* Authour	: Ahmed Mohy										*/ 
/* Date     : 1 January 2022									*/
/* Version  : V01												*/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "EXTI_interface.h"

#include "IR_interface.h"
#include "IR_config.h"
#include "IR_private.h"



void HIR_voidInit(void)
{
	/* initiate systick to HSE/8 = 1MHZ */
	MSTK_voidInit() ;
	MEXTI_voidSetCallBack( IR_EXTI , voidReceiveFrame ) ;
}


/* function to take pointer to the action function that will be executed after receive the data */
void HIR_voidSetCallBack( void (*ptr) (u8) )
{
	/* Save Callback */
	IR_Callback = ptr ;
}



/* function will be passed to EXTI callback */
static void voidReceiveFrame(void)
{
	if ( u8StartFlag == 0 )
	{
		MSTK_voidSetIntervalSingle( 500000 , voidTakeAction ) ;
		u8StartFlag = 1 ;
		u8Counter = 0 ;
	}
	
	else
	{
		u32RecFrame[u8Counter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle( 500000 , voidTakeAction ) ;
		u8Counter++ ;
	}
}


static void voidTakeAction(void)
{
	if ( ( u32RecFrame[0] > 10000 ) && ( u32RecFrame[0] < 14000 ) )
	{
		u8 Local_u8Index = 0 ;
		for (Local_u8Index=0 ; Local_u8Index <= 7 ; Local_u8Index++)
		{
			if ( ( u32RecFrame[17 + Local_u8Index] > 2000 ) && ( u32RecFrame[17 + Local_u8Index] < 2500 ) )
			{
				SET_BIT(u8RecData , Local_u8Index) ;
			}
			
			else if ( ( u32RecFrame[17 + Local_u8Index] > 1000 ) && ( u32RecFrame[17 + Local_u8Index] < 1300 ) )
			{
				CLR_BIT(u8RecData , Local_u8Index) ;
			}
			
		}
	}
	
	else
	{
		/* receiving error */
	}
	
	IR_Callback(u8RecData) ;
	
	u8Counter = 0 ;
	u8StartFlag = 0 ;
	u32RecFrame[0] = 0 ;
}
