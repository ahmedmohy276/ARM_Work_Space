/*
 * main.c
 *
 *  Created on: Dec 24, 2021
 *      Author: ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"


void main(void)
{
	/* initialize system clock */
	MRCC_voidInitSysClock();

	/* enable GPIOA peripheral clock */
	MRCC_voidEnableClock(RCC_APB2,IOPAEN);

	/* set configuration of pin A0 to output 2MHZ push pull */
	MGPIO_voidSetPinDirection(PORTA , PIN0 , GPIO_OUTPUT_SPEED_10MHZ_PP) ;


	while(1)
	{
		/* blink A0 */
		MGPIO_voidSetPin(PORTA , PIN0) ;
		MSTK_voidSetBusyWait(1000000) ;
		MGPIO_voidClearPin(PORTA , PIN0) ;
		MSTK_voidSetBusyWait(1000000) ;
	}
}










