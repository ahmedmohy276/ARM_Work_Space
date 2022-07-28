/*
 * main.c
 *
 *  Created on: Jan 14, 2022
 *      Author: ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "USART_interface.h"

int main(void)
{
	/* Enable system clock to 8MHZ Crystal HSE */
	MRCC_voidInitSysClock();

	/* Enable GPIOA & USART1 clock */
	MRCC_voidEnableClock(RCC_APB2 , IOPAEN) ;
	MRCC_voidEnableClock(RCC_APB2 , USART1EN) ;

	/* Set TX=PINA9 as Output alternate function push pull max speed 50 MHz  */
	MGPIO_voidSetPinDirection(PORTA , PIN9 , GPIO_OUTPUT_SPEED_50MHZ_AFPP);

	/* Set RX=PINA10 as input floating */
	MGPIO_voidSetPinDirection(PORTA , PIN10 , GPIO_FLOATING_INPUT);
	MGPIO_voidSetPinDirection(PORTA , PIN0 , GPIO_OUTPUT_SPEED_2MHZ_PP);

	MUSART1_voidInit();

	u8 ReceiveChar ;
	while(1)
	{
		MUSART1_voidTransmitSynch((u8*)"97") ;
		ReceiveChar = MUSART1_u8ReceiveSynch() ;
		if (ReceiveChar == '5')
		{
			MGPIO_voidSetPin(PORTA , PIN0) ;
		}

		else if (ReceiveChar == 'R')
		{
			MGPIO_voidClearPin(PORTA , PIN0) ;
		}
	}
	return 0 ;
}


