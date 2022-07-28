/*
 * main.c
 *
 *  Created on: Dec 31, 2021
 *      Author: ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"
#include "LEDMAT_interface.h"


void main (void)
{
	/* Initiate system clock */
	MRCC_voidInitSysClock();

	/* Enable GPIOA & GPIOB Clock */
	MRCC_voidEnableClock(RCC_APB2 , IOPAEN);
	MRCC_voidEnableClock(RCC_APB2 , IOPBEN);

	/* Rows value to show A alphabet */
	u8 Alphabit_Arr[8] = { 0 , 124 , 18 , 18 , 18 , 124 , 0 , 0 } ;

	/* Initiate led matrix */
	HLEDMAT_voidInit();

	/* Display character */
	HLEDMAT_voidDisplayFrame(Alphabit_Arr);

	while (1)
	{

	}
}
