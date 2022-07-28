/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  2 January 2022             */
/* Version :  V01                        */
/*****************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SYSTICK_interface.h"

#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"


void HDAC_voidInit(void)
{
	MGPIO_voidSetPinDirection(DAC_PIN0 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(DAC_PIN1 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(DAC_PIN2 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(DAC_PIN3 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(DAC_PIN4 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(DAC_PIN5 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(DAC_PIN6 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(DAC_PIN7 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	/* initialize systick timer to HSE/8 */
	u16ArrayCount = 0 ;
	MSTK_voidInit();
}


void HDAC_voidSetDACInput(const u8 *Copy_u8Arr , u16 Copy_u8Size)
{
	DAC_Input = Copy_u8Arr ;
	DAC_Input_Size = Copy_u8Size ;
}


void HDAC_voidStart(u32 Copy_u32SampleTime)
{
	MSTK_voidSetIntervalPeriodic(Copy_u32SampleTime , DAC_Output) ;
}

static void DAC_Output (void)
{
	u8 Local_u8Index = 0 ;
	u8 Local_u8Data[8] ;
	for (Local_u8Index=0 ; Local_u8Index <7 ; Local_u8Index++)
	{
		Local_u8Data[Local_u8Index] = GET_BIT(DAC_Input[u16ArrayCount] , Local_u8Index) ;
	}
	MGPIO_voidSetPinValue(DAC_PIN0 , Local_u8Data[0]);
	MGPIO_voidSetPinValue(DAC_PIN1 , Local_u8Data[1]);
	MGPIO_voidSetPinValue(DAC_PIN2 , Local_u8Data[2]);
	MGPIO_voidSetPinValue(DAC_PIN3 , Local_u8Data[3]);
	MGPIO_voidSetPinValue(DAC_PIN4 , Local_u8Data[4]);
	MGPIO_voidSetPinValue(DAC_PIN5 , Local_u8Data[5]);
	MGPIO_voidSetPinValue(DAC_PIN6 , Local_u8Data[6]);
	MGPIO_voidSetPinValue(DAC_PIN7 , Local_u8Data[7]);
	
	u16ArrayCount++ ;
	if (u16ArrayCount == DAC_Input_Size)
	{
		u16ArrayCount = 0 ;
	}
}
