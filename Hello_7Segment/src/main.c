/*
 * main.c
 *
 *  Created on: Jan 12, 2022
 *      Author: ahmed
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"
#include "SEVSEG_interface.h"


void Display(void)
{
	static u8 Local_u8Num = 0;
	SEVSEG_voidDisplay(Local_u8Num);
	Local_u8Num++ ;
	if(Local_u8Num == 10)
	{
		Local_u8Num = 0 ;
	}
}

void main(void)
{
	/* Initiate system clock to Crystal HSE = 8MHZ */
	MRCC_voidInitSysClock();

	/* Enable GPIOA clock */
	MRCC_voidEnableClock(RCC_APB2 , IOPAEN);

	MGPIO_voidSetPinDirection(PORTA , PIN7 , GPIO_OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPin(PORTA , PIN7);

	/* initiate 7 Segment */
	SEVSEG_voidInit();

	/* Display numbers from 0 to 9 */
	MSTK_voidSetIntervalPeriodic(500000 , Display) ;
	while(1)
	{

	}
}
