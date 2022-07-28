/*****************************************************************************/
/* Author    : Ahmed Mohy													 */
/* Date      : 28 DEC 2021													 */
/* Version   : V01														     */
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LEDANIM_interface.h"
#include "LEDANIM_private.h"
#include "LEDANIM_config.h"

#include "DIO_interface.h"
#include "SYSTICK_interface.h"
#include "LED_interface.h"



void LEDANIM_voidInit(void)
{
	MGPIO_voidSetPinDirection(LED1 , LED_ANNIMATION_PORT_MODE);
	MGPIO_voidSetPinDirection(LED2 , LED_ANNIMATION_PORT_MODE);
	MGPIO_voidSetPinDirection(LED3 , LED_ANNIMATION_PORT_MODE);
	MGPIO_voidSetPinDirection(LED4 , LED_ANNIMATION_PORT_MODE);
	MGPIO_voidSetPinDirection(LED5 , LED_ANNIMATION_PORT_MODE);
	MGPIO_voidSetPinDirection(LED6 , LED_ANNIMATION_PORT_MODE);
	MGPIO_voidSetPinDirection(LED7 , LED_ANNIMATION_PORT_MODE);
	MGPIO_voidSetPinDirection(LED8 , LED_ANNIMATION_PORT_MODE);
}


/* Function to display 8 leds shift right and left (Ping Pong) */
void LEDANIM_voidDisplayPingPong(u32 Copy_u32Delayms , u8 Copy_u8Repetition)
{
	for (u8 i=0 ; i < Copy_u8Repetition ; i++)
	{
		LED_voidTurnToggle(LED1 , Copy_u32Delayms);
		LED_voidTurnToggle(LED2 , Copy_u32Delayms);
		LED_voidTurnToggle(LED3 , Copy_u32Delayms);
		LED_voidTurnToggle(LED4 , Copy_u32Delayms);
		LED_voidTurnToggle(LED5 , Copy_u32Delayms);
		LED_voidTurnToggle(LED6 , Copy_u32Delayms);
		LED_voidTurnToggle(LED7 , Copy_u32Delayms);
		LED_voidTurnToggle(LED8 , Copy_u32Delayms);

		LED_voidTurnToggle(LED7 , Copy_u32Delayms);
		LED_voidTurnToggle(LED6 , Copy_u32Delayms);
		LED_voidTurnToggle(LED5 , Copy_u32Delayms);
		LED_voidTurnToggle(LED4 , Copy_u32Delayms);
		LED_voidTurnToggle(LED3 , Copy_u32Delayms);
		LED_voidTurnToggle(LED2 , Copy_u32Delayms);
	}
	
}


void LEDANIM_voidDisplayInOut(u32 Copy_u32Delayms , u8 Copy_u8Repetition)
{
	for (u8 i=0 ; i < Copy_u8Repetition ; i++)
	{
		LED_voidTurnOn(LED4);
		LED_voidTurnOn(LED5);
		MSTK_voidSetBusyWait(Copy_u32Delayms*1000);
		
		LED_voidTurnOn(LED3);
		LED_voidTurnOn(LED6);
		MSTK_voidSetBusyWait(Copy_u32Delayms*1000);
		
		LED_voidTurnOn(LED2);
		LED_voidTurnOn(LED7);
		MSTK_voidSetBusyWait(Copy_u32Delayms*1000);
		
		LED_voidTurnOn(LED1);
		LED_voidTurnOn(LED8);
		MSTK_voidSetBusyWait(Copy_u32Delayms*1000);
		
		LED_voidTurnOff(LED1);
		LED_voidTurnOff(LED8);
		MSTK_voidSetBusyWait(Copy_u32Delayms*1000);

		LED_voidTurnOff(LED2);
		LED_voidTurnOff(LED7);
		MSTK_voidSetBusyWait(Copy_u32Delayms*1000);
		
		LED_voidTurnOff(LED3);
		LED_voidTurnOff(LED6);
		MSTK_voidSetBusyWait(Copy_u32Delayms*1000);
		
		/*LED_voidTurnOff(LED4);
		LED_voidTurnOff(LED5);
		MSTK_voidSetBusyWait(Copy_u32Delayms*1000);*/
	}
}


/* Function to flashing 8 leds */
void LEDANIM_voidDisplayFlashing(u32 Copy_u32Delayms , u8 Copy_u8Repetition)
{
	for (u8 i=0 ; i < Copy_u8Repetition ; i++)
	{
		MGPIO_voidSetPin(LED1);
		MGPIO_voidSetPin(LED2);
		MGPIO_voidSetPin(LED3);
		MGPIO_voidSetPin(LED4);
		MGPIO_voidSetPin(LED5);
		MGPIO_voidSetPin(LED6);
		MGPIO_voidSetPin(LED7);
		MGPIO_voidSetPin(LED8);
		MSTK_voidSetBusyWait(Copy_u32Delayms*1000);
		MGPIO_voidClearPin(LED1);
		MGPIO_voidClearPin(LED2);
		MGPIO_voidClearPin(LED3);
		MGPIO_voidClearPin(LED4);
		MGPIO_voidClearPin(LED5);
		MGPIO_voidClearPin(LED6);
		MGPIO_voidClearPin(LED7);
		MGPIO_voidClearPin(LED8);
		MSTK_voidSetBusyWait(Copy_u32Delayms*1000);
	}
}


