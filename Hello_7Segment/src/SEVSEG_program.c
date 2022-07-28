/********************************************************************/
/* Author   : Ahmed Mohy						    				*/
/* Date	    : 25 DEC 2021											*/
/* Version  : V01													*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SEVSEG_interface.h"
#include "SEVSEG_private.h"
#include "SEVSEG_config.h"



void SEVSEG_voidInit(void)
{
	MGPIO_voidSetPinDirection(SEVSEG_PINA , GPIO_OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(SEVSEG_PINB , GPIO_OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(SEVSEG_PINC , GPIO_OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(SEVSEG_PIND , GPIO_OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(SEVSEG_PINE , GPIO_OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(SEVSEG_PINF , GPIO_OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(SEVSEG_PING , GPIO_OUTPUT_SPEED_10MHZ_PP);
}



void SEVSEG_voidDisplay(u8 Copy_u8Num)
{
	u8 Local_u8Bit[7] = {0} ;
	u8 Local_u8Index = 0;
	switch (SEVSEG_TYPE)
	{
		case COMMON_CATHODE_SEVSEG :
			for (Local_u8Index=0 ; Local_u8Index<7 ; Local_u8Index++)
			{
				Local_u8Bit[Local_u8Index] = GET_BIT(array_val[Copy_u8Num] , Local_u8Index);
			}
			
			MGPIO_voidSetPinValue(SEVSEG_PINA , Local_u8Bit[0]) ;
			MGPIO_voidSetPinValue(SEVSEG_PINB , Local_u8Bit[1]) ;
			MGPIO_voidSetPinValue(SEVSEG_PINC , Local_u8Bit[2]) ;
			MGPIO_voidSetPinValue(SEVSEG_PIND , Local_u8Bit[3]) ;
			MGPIO_voidSetPinValue(SEVSEG_PINE , Local_u8Bit[4]) ;
			MGPIO_voidSetPinValue(SEVSEG_PINF , Local_u8Bit[5]) ;
			MGPIO_voidSetPinValue(SEVSEG_PING , Local_u8Bit[6]) ;
			break;
			
		case COMMON_ANODE_SEVSEG :
			for (Local_u8Index=0 ; Local_u8Index<7 ; Local_u8Index++)
			{
				Local_u8Bit[Local_u8Index] = ~(GET_BIT(array_val[Copy_u8Num] , Local_u8Index));
			}
			
			MGPIO_voidSetPinValue(SEVSEG_PINA , Local_u8Bit[0]) ;
			MGPIO_voidSetPinValue(SEVSEG_PINB , Local_u8Bit[1]) ;
			MGPIO_voidSetPinValue(SEVSEG_PINC , Local_u8Bit[2]) ;
			MGPIO_voidSetPinValue(SEVSEG_PIND , Local_u8Bit[3]) ;
			MGPIO_voidSetPinValue(SEVSEG_PINE , Local_u8Bit[4]) ;
			MGPIO_voidSetPinValue(SEVSEG_PINF , Local_u8Bit[5]) ;
			MGPIO_voidSetPinValue(SEVSEG_PING , Local_u8Bit[6]) ;
			break;
		
		default : 			break;
	}
}
