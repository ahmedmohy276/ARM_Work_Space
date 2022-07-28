/*
 * main.c
 *
 *  Created on: Feb 17, 2022
 *      Author: ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"
#include "USART_interface.h"
#include "SIM800L_interface.h"




int main(void)
{
	u8 ResponseArr[300] ;
	MRCC_voidInitSysClock();						/* HSE Crystal 8MHZ clock */
	MRCC_voidEnableClock(RCC_APB2 , USART1EN) ;		/* USART1 */
	MRCC_voidEnableClock(RCC_APB2 , IOPAEN) ;		/* GPIOA */
	/* Set TX=PINA9 as Output alternate function push pull max speed 50 MHz  */
	MGPIO_voidSetPinDirection(PORTA , PIN9 , GPIO_OUTPUT_SPEED_50MHZ_AFPP);
	/* Set RX=PINA10 as input floating */
	MGPIO_voidSetPinDirection(PORTA , PIN10 , GPIO_FLOATING_INPUT);

	MSTK_voidInit() ;
	MUSART1_voidInit() ;
	HSIM800L_voidInit() ;

	/* send message to phone number */
	HSIM800L_voidSendMessage((u8*)"Hello Mr Phone") ;
	/* Receive message from the phone */
	HSIM800L_u8ReceiveMessage(ResponseArr) ;


	while(1)
	{

	}

	return 0 ;
}
