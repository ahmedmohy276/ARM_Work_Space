/****************************************************************/
/*	Author   : Ahmed Mohy									   	*/
/*	Date     : 31 DEC 2021										*/
/*	Version  : V02												*/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SYSTICK_interface.h"

#include "LEDMAT_INTERFACE.h"
#include "LEDMAT_config.h"
#include "LEDMAT_private.h"


u8 Display_Num = 0 ;		/* define the speed of display shifting */
u16 Counter = 0 ;


void HLEDMAT_voidInit(void)
{
	/* Set Led matrix Columns direction as output 2MHZ Push Pull */
	MGPIO_voidSetPinDirection ( LEDMAT_COL0_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_COL1_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_COL2_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_COL3_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_COL4_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_COL5_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_COL6_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_COL7_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	
	/* Set Led matrix Rows direction as output 2MHZ Push Pull */
	MGPIO_voidSetPinDirection ( LEDMAT_ROW0_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_ROW1_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_ROW2_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_ROW3_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_ROW4_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_ROW5_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_ROW6_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_ROW7_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;

	MSTK_voidInit();
}

void HLEDMAT_voidDisplayFrame ( u8 *Copy_u8frame )
{
	/* Reset index value */
	HLEDMAT_u8CurrentIndex = 0 ;
	
	/* Save desired frame */
	HLEDMAT_u8Frame  = Copy_u8frame ;
	
	/* Display first column */
	HLEDMAT_voidActivateColumn(HLEDMAT_u8CurrentIndex) ; 
	HLEDMAT_voidSetRowsValue(HLEDMAT_u8Frame[HLEDMAT_u8CurrentIndex]) ;
	
	/*  Start SysTick timer */
	MSTK_voidSetIntervalPeriodic(2500 , HLEDMAT_voidDisplayNextColumn) ;
	
}


static void HLEDMAT_voidDisplayNextColumn(void)
{

	HLEDMAT_u8CurrentIndex++ ;
	if (HLEDMAT_u8CurrentIndex == 8)
	{
		//Counter++ ;
		Display_Num++ ;
		HLEDMAT_u8CurrentIndex = 0 ;
		if (Display_Num == 7)
		{
			Counter++ ;
			Display_Num = 0;
		}
	}
	if (Counter == 32)
	{
		Counter = 0 ;
	}
	/* Put the data to the rows */
	HLEDMAT_voidSetRowsValue(HLEDMAT_u8Frame[HLEDMAT_u8CurrentIndex + Counter]) ;
	
	/* Enable the desired Column and disable all columns */
	HLEDMAT_voidActivateColumn(HLEDMAT_u8CurrentIndex) ;
	
}


static void HLEDMAT_voidSetRowsValue(u8 Copy_u8Value)
{
	u8 Local_u8Index = 0 ;
	u8 Local_u8ArrVal[8] = {0} ;
	for (Local_u8Index=0 ; Local_u8Index <=7 ; Local_u8Index++)
	{
		Local_u8ArrVal[Local_u8Index] = GET_BIT(Copy_u8Value , Local_u8Index) ;
	}
	
	/* Set Led matrix Rows Value */
	MGPIO_voidSetPinValue ( LEDMAT_ROW0_PIN , Local_u8ArrVal[0] ) ;
	MGPIO_voidSetPinValue ( LEDMAT_ROW1_PIN , Local_u8ArrVal[1] ) ;
	MGPIO_voidSetPinValue ( LEDMAT_ROW2_PIN , Local_u8ArrVal[2] ) ;
	MGPIO_voidSetPinValue ( LEDMAT_ROW3_PIN , Local_u8ArrVal[3] ) ;
	MGPIO_voidSetPinValue ( LEDMAT_ROW4_PIN , Local_u8ArrVal[4] ) ;
	MGPIO_voidSetPinValue ( LEDMAT_ROW5_PIN , Local_u8ArrVal[5] ) ;
	MGPIO_voidSetPinValue ( LEDMAT_ROW6_PIN , Local_u8ArrVal[6] ) ;
	MGPIO_voidSetPinValue ( LEDMAT_ROW7_PIN , Local_u8ArrVal[7] ) ;
}


static void HLEDMAT_voidActivateColumn(u8 Copy_u8Col)
{
	/* Disable All columns by writing high value to them */
	MGPIO_voidSetPin ( LEDMAT_COL0_PIN ) ;
	MGPIO_voidSetPin ( LEDMAT_COL1_PIN ) ;
	MGPIO_voidSetPin ( LEDMAT_COL2_PIN ) ;
	MGPIO_voidSetPin ( LEDMAT_COL3_PIN ) ;
	MGPIO_voidSetPin ( LEDMAT_COL4_PIN ) ;
	MGPIO_voidSetPin ( LEDMAT_COL5_PIN ) ;
	MGPIO_voidSetPin ( LEDMAT_COL6_PIN ) ;
	MGPIO_voidSetPin ( LEDMAT_COL7_PIN ) ;
	
	/* Enable The desired column  by writing Low value to it */
	switch (Copy_u8Col)
	{
		case 0: MGPIO_voidClearPin(LEDMAT_COL0_PIN); break;
		case 1: MGPIO_voidClearPin(LEDMAT_COL1_PIN); break;
		case 2: MGPIO_voidClearPin(LEDMAT_COL2_PIN); break;
		case 3: MGPIO_voidClearPin(LEDMAT_COL3_PIN); break;
		case 4: MGPIO_voidClearPin(LEDMAT_COL4_PIN); break;
		case 5: MGPIO_voidClearPin(LEDMAT_COL5_PIN); break;
		case 6: MGPIO_voidClearPin(LEDMAT_COL6_PIN); break;
		case 7: MGPIO_voidClearPin(LEDMAT_COL7_PIN); break;
		default:   break;
	}
	
}
