/*
 * main.c
 *
 *  Created on: Jan 5, 2022
 *      Author: ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"
#include "SPI_interface.h"
#include "TFT_interface.h"
#include "image.h"


void main(void)
{
	/* Initiate clock system */
	MRCC_voidInitSysClock();
	/* Enable GPIOA and SPI1 */
	MRCC_voidEnableClock(RCC_APB2 , IOPAEN) ;
	MRCC_voidEnableClock(RCC_APB2 , SPI1EN) ;

	/* Pins initializations */
	MGPIO_voidSetPinDirection(PORTA , PIN1 , GPIO_OUTPUT_SPEED_2MHZ_PP);		// A0 PIN
	MGPIO_voidSetPinDirection(PORTA , PIN2 , GPIO_OUTPUT_SPEED_2MHZ_PP);		// Reset pin
	MGPIO_voidSetPinDirection(PORTA , PIN5 , GPIO_OUTPUT_SPEED_10MHZ_AFPP);		// CLK
	MGPIO_voidSetPinDirection(PORTA , PIN7 , GPIO_OUTPUT_SPEED_10MHZ_AFPP);		// MOSI

	/* Initiate SYSTICK */
	MSTK_voidInit();

	/* Initiate SPI */
	MSPI1_voidInit();

	/* Initiate TFT */
	HTFT_voidInit() ;

	while(1)
	{
		/* Display image */
		HTFT_voidDisplayImage(image);
		MSTK_voidSetBusyWait(1000000);
		HTFT_voidFillColour(0XFFFF);
		MSTK_voidSetBusyWait(3000000);
		HTFT_voidDrawRect(0 , 20 , 0 , 40 , 0);
		MSTK_voidSetBusyWait(1000000);
	}
}
