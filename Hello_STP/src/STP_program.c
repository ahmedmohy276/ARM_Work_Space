/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  3 January 2022             */
/* Version :  V01                        */
/*****************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SYSTICK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"



void HSTP_voidInit(void) 
{
	/* set shift register pins configuration */
	MGPIO_voidSetPinDirection( STP_DATA_SERIAL , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection( STP_SHIFT_CLOCK , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_voidSetPinDirection( STP_STORAG_CLOCK , GPIO_OUTPUT_SPEED_2MHZ_PP ) ;
	/* Initiate systick timer */
	MSTK_voidInit();
}


void HSTP_voidSendSynchronous(u8 Copy_u8SendData)
{
	s8 Local_s8Index = 0 ;
	u8 Local_u8Bit = 0;
	for (Local_s8Index=STP_OUTPUT_BITS_NUM - 1 ; Local_s8Index >= 0 ; Local_s8Index--)
	{
		Local_u8Bit = GET_BIT(Copy_u8SendData , Local_s8Index) ;
		MGPIO_voidSetPinValue(STP_DATA_SERIAL , Local_u8Bit);
		/* send shift clock pulse */
		MGPIO_voidSetPinValue(STP_SHIFT_CLOCK , GPIO_HIGH);
		MSTK_voidSetBusyWait(1) ;
		MGPIO_voidSetPinValue(STP_SHIFT_CLOCK , GPIO_LOW);
		MSTK_voidSetBusyWait(1) ;
	}
	
	/* send Storage clock pulse */
	MGPIO_voidSetPinValue(STP_STORAG_CLOCK , GPIO_HIGH);
	MSTK_voidSetBusyWait(1) ;
	MGPIO_voidSetPinValue(STP_STORAG_CLOCK , GPIO_LOW);
	MSTK_voidSetBusyWait(1) ;
}



