/*****************************************************************************/
/* Author    : Ahmed Mohy													 */
/* Date      : 25 DEC 2021													 */
/* Version   : V01														     */
/*****************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


#include "DIO_interface.h"
#include "SYSTICK_interface.h"


void LED_voidInit(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	MGPIO_voidSetPinDirection(Copy_u8Port , Copy_u8Pin , GPIO_OUTPUT_SPEED_10MHZ_PP);
}


void LED_voidTurnOn(u8 Copy_u8Port , u8 Copy_u8Pin)
{	
	
	MGPIO_voidSetPin(Copy_u8Port , Copy_u8Pin);
}


void LED_voidTurnOff(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	MGPIO_voidClearPin(Copy_u8Port , Copy_u8Pin);
}


void LED_voidTurnToggle(u8 Copy_u8Port , u8 Copy_u8Pin , u32 Copy_u32Delayms)
{	
	MGPIO_voidSetPin(Copy_u8Port , Copy_u8Pin);
	/* Delay method 1 second */
	MSTK_voidSetBusyWait(Copy_u32Delayms*1000);

	MGPIO_voidClearPin(Copy_u8Port , Copy_u8Pin);
	/* Delay method 1 second */
	MSTK_voidSetBusyWait(Copy_u32Delayms*1000);
}
