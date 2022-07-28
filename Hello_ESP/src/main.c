/*
 * main.c
 *
 *  Created on: Jan 20, 2022
 *      Author: ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "USART_interface.h"
#include "ESP_interface.h"



int main(void)
{
	MRCC_voidInitSysClock();						/* HSI clock */
	MRCC_voidEnableClock(RCC_APB2 , USART1EN) ;		/* USART1 */
	MRCC_voidEnableClock(RCC_APB2 , IOPAEN) ;		/* GPIOA */
	MRCC_voidEnableClock(RCC_ABH , FLITFEN) ;		/* FPEC */

	/* Set TX=PINA9 as Output alternate function push pull max speed 50 MHz  */
	MGPIO_voidSetPinDirection(PORTA , PIN9 , GPIO_OUTPUT_SPEED_50MHZ_AFPP);

	/* Set RX=PINA10 as input floating */
	MGPIO_voidSetPinDirection(PORTA , PIN10 , GPIO_FLOATING_INPUT);
	MGPIO_voidSetPinDirection(PORTA , PIN0 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	u8 RecData[15000] ;
	u16 len = 0 ;
	MUSART1_voidInit() ;
	HESP_voidInit() ;
	HESP_voidWiFiConnect();

	while(1)
	{
		len = HESP_u8SendReceiveData(RecData) ;
		if (RecData[0] == '1')
		{
			MGPIO_voidSetPin(PORTA , PIN0) ;
		}
		if (RecData[0] == '0')
		{
			MGPIO_voidClearPin(PORTA , PIN0) ;
		}
	}
	return 0 ;
}
