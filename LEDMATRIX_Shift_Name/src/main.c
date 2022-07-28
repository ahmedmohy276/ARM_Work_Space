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
	u8 Alphabit_Arr[32] = {  0 , 0 ,124, 18, 18, 18, 124, 0, 0, 126, 8, 8, 8, 126, 0, 0, 126,
							4, 8, 4, 126, 0, 0, 126, 74, 74, 0, 0, 126, 66, 36, 24  } ;
	/* Initiate system clock */
	MRCC_voidInitSysClock();

	/* Enable GPIOA & GPIOB Clock */
	MRCC_voidEnableClock(RCC_APB2 , IOPAEN);
	MRCC_voidEnableClock(RCC_APB2 , IOPBEN);

	/* Rows value to show A alphabet */

	/* Initiate led matrix */
	HLEDMAT_voidInit();

	/* Display character */
	HLEDMAT_voidDisplayFrame(Alphabit_Arr);

	while (1)
	{

	}
}
