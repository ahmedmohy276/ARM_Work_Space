/*
 * main.c
 *
 *  Created on: Sep 21, 2020
 *      Author: Ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"
#include "RCC_interface.h"

#include "TFT_interface.h"
#include "image.h"

void main(void)
{
	/* RCC Initialization */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);   /* GPIOA */
	RCC_voidEnableClock(RCC_APB2,12);  /* SPI1  */

	/* Pin Initializations */
	MGPIO_VidSetPinDirection(GPIOA,1,0b0010);  /* A0   */
	MGPIO_VidSetPinDirection(GPIOA,2,0b0010);  /* RST  */
	MGPIO_VidSetPinDirection(GPIOA,5,0b1001);  /* CLK  */
	MGPIO_VidSetPinDirection(GPIOA,7,0b1001);  /* MOSI */

	/* Init STK */
	MSTK_voidInit();

	/* SPI Init */
	MSPI1_voidInit();

	/* TFT Init */
	HTFT_voidInitialize();

	/* Display Image */
	HTFT_voidDisplayImage(image);

	while(1);

}

