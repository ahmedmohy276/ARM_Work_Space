/*
 * main.c
 *
 *  Created on: Jan 2, 2022
 *      Author: ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "DAC_interface.h"
#include "file.h"


void main(void)
{
	/* Initiate system clock to Crystal HSE = 8MHZ */
	MRCC_voidInitSysClock();
	/* Enable GPIOA clock */
	MRCC_voidEnableClock(RCC_APB2 , IOPAEN);
	/* initiate DAC */
	HDAC_voidInit();
	HDAC_voidSetDACInput(Hamaki_raw , DAC_INPUT_SIZE);
	HDAC_voidStart(125);

	while(1)
	{

	}
}
