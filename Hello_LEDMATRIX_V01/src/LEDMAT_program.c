/****************************************************************/
/*	Author   : Ahmed Mohy									   	*/
/*	Date     : 30 DEC 2021										*/
/*	Version  : V01												*/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SYSTICK_interface.h"

#include "LEDMAT_INTERFACE.h"
#include "LEDMAT_config.h"
#include "LEDMAT_private.h"


void HLEDMAT_voidInit(void)
{
	/* Set Led matrix Columns direction as output 2MHZ Push Pull */
	MGPIO_voidSetPinDirection ( LEDMAT_COL_PORT , LEDMAT_COL0_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_COL_PORT , LEDMAT_COL1_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_COL_PORT , LEDMAT_COL2_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_COL_PORT , LEDMAT_COL3_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_COL_PORT , LEDMAT_COL4_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_COL_PORT , LEDMAT_COL5_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_COL_PORT , LEDMAT_COL6_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_COL_PORT , LEDMAT_COL7_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	
	/* Set Led matrix Rows direction as output 2MHZ Push Pull */
	MGPIO_voidSetPinDirection ( LEDMAT_ROW_PORT , LEDMAT_ROW0_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_ROW_PORT , LEDMAT_ROW1_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_ROW_PORT , LEDMAT_ROW2_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_ROW_PORT , LEDMAT_ROW3_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_ROW_PORT , LEDMAT_ROW4_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_ROW_PORT , LEDMAT_ROW5_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_ROW_PORT , LEDMAT_ROW6_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection ( LEDMAT_ROW_PORT , LEDMAT_ROW7_PIN , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
}

void HLEDMAT_voidDisplayFrame ( u8 *Copy_u8frame )
{
	while (1)
	{
		/* Put the data to the rows */
		HLEDMAT_voidSetRowsValue(Copy_u8frame[0]) ;
		
		/* Enable Column0 and disable all columns */
		HLEDMAT_voidEnableColumn(LEDMAT_COL0_PIN) ;
		
		/* delay 2.5 milli secomds */
		MSTK_voidSetBusyWait(2500) ;
		
		
		/* Put the data to the rows */
		HLEDMAT_voidSetRowsValue(Copy_u8frame[1]) ;
		
		/* Enable Column1 and disable all columns */
		HLEDMAT_voidEnableColumn(LEDMAT_COL0_PIN) ;
		
		/* delay 2.5 milli secomds */
		MSTK_voidSetBusyWait(2500) ;
		
		
		/* Put the data to the rows */
		HLEDMAT_voidSetRowsValue(Copy_u8frame[2]) ;
		
		/* Enable Column2 and disable all columns */
		HLEDMAT_voidEnableColumn(LEDMAT_COL0_PIN) ;
		
		/* delay 2.5 milli secomds */
		MSTK_voidSetBusyWait(2500) ;
		
		
		/* Put the data to the rows */
		HLEDMAT_voidSetRowsValue(Copy_u8frame[3]) ;
		
		/* Enable Column3 and disable all columns */
		HLEDMAT_voidEnableColumn(LEDMAT_COL0_PIN) ;
		
		/* delay 2.5 milli secomds */
		MSTK_voidSetBusyWait(2500) ;
		
		
		/* Put the data to the rows */
		HLEDMAT_voidSetRowsValue(Copy_u8frame[4]) ;
		
		/* Enable Column4 and disable all columns */
		HLEDMAT_voidEnableColumn(LEDMAT_COL0_PIN) ;
		
		/* delay 2.5 milli secomds */
		MSTK_voidSetBusyWait(2500) ;
		
		
		/* Put the data to the rows */
		HLEDMAT_voidSetRowsValue(Copy_u8frame[5]) ;
		
		/* Enable Column5 and disable all columns */
		HLEDMAT_voidEnableColumn(LEDMAT_COL0_PIN) ;
		
		/* delay 2.5 milli secomds */
		MSTK_voidSetBusyWait(2500) ;
		
		
		/* Put the data to the rows */
		HLEDMAT_voidSetRowsValue(Copy_u8frame[6]) ;
		
		/* Enable Column6 and disable all columns */
		HLEDMAT_voidEnableColumn(LEDMAT_COL0_PIN) ;
		
		/* delay 2.5 milli secomds */
		MSTK_voidSetBusyWait(2500) ;
		
		
		/* Put the data to the rows */
		HLEDMAT_voidSetRowsValue(Copy_u8frame[7]) ;
		
		/* Enable Column7 and disable all columns */
		HLEDMAT_voidEnableColumn(LEDMAT_COL0_PIN) ;
		
		/* delay 2.5 milli secomds */
		MSTK_voidSetBusyWait(2500) ;
	}
	
	
	
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
	MGPIO_voidSetPinValue ( LEDMAT_ROW_PORT , LEDMAT_ROW0_PIN , Local_u8ArrVal[0] ) ;
	MGPIO_voidSetPinValue ( LEDMAT_ROW_PORT , LEDMAT_ROW1_PIN , Local_u8ArrVal[1] ) ;
	MGPIO_voidSetPinValue ( LEDMAT_ROW_PORT , LEDMAT_ROW2_PIN , Local_u8ArrVal[2] ) ;
	MGPIO_voidSetPinValue ( LEDMAT_ROW_PORT , LEDMAT_ROW3_PIN , Local_u8ArrVal[3] ) ;
	MGPIO_voidSetPinValue ( LEDMAT_ROW_PORT , LEDMAT_ROW4_PIN , Local_u8ArrVal[4] ) ;
	MGPIO_voidSetPinValue ( LEDMAT_ROW_PORT , LEDMAT_ROW5_PIN , Local_u8ArrVal[5] ) ;
	MGPIO_voidSetPinValue ( LEDMAT_ROW_PORT , LEDMAT_ROW6_PIN , Local_u8ArrVal[6] ) ;
	MGPIO_voidSetPinValue ( LEDMAT_ROW_PORT , LEDMAT_ROW7_PIN , Local_u8ArrVal[7] ) ;
}


static void HLEDMAT_voidEnableColumn(u8 Copy_u8Col)
{
	/* Disable All columns by writing high value to them */
	MGPIO_voidSetPin ( LEDMAT_COL_PORT , LEDMAT_COL0_PIN ) ;
	MGPIO_voidSetPin ( LEDMAT_COL_PORT , LEDMAT_COL1_PIN ) ;
	MGPIO_voidSetPin ( LEDMAT_COL_PORT , LEDMAT_COL2_PIN ) ;
	MGPIO_voidSetPin ( LEDMAT_COL_PORT , LEDMAT_COL3_PIN ) ;
	MGPIO_voidSetPin ( LEDMAT_COL_PORT , LEDMAT_COL4_PIN ) ;
	MGPIO_voidSetPin ( LEDMAT_COL_PORT , LEDMAT_COL5_PIN ) ;
	MGPIO_voidSetPin ( LEDMAT_COL_PORT , LEDMAT_COL6_PIN ) ;
	MGPIO_voidSetPin ( LEDMAT_COL_PORT , LEDMAT_COL7_PIN ) ;
	
	/* Enable The desired column  by writing Low value to it */
	MGPIO_voidClearPin ( LEDMAT_COL_PORT , Copy_u8Col ) ;
	
	
}
