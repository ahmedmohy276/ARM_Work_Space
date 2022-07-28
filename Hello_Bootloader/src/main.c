/*
 * main.c
 *
 *  Created on: Jan 7, 2022
 *      Author: ahmed
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"
#include "USART_interface.h"
#include "FPEC_interface.h"

void Parser_voidParseRecord(u8* Copy_u8BufData);

volatile u8 RecData[100] ;
volatile u8 DataCounter = 0 ;
volatile u8 u8TimeoutFlag = 0 ;
volatile u8 u8WriteReq = 1 ;


typedef void (*Function_t)(void) ;
Function_t add_to_call = 0 ;


void Func(void)
{
	u8TimeoutFlag = 1 ;
	#define SCB_VTOR			*((volatile u32*)0XE000ED08)

	SCB_VTOR = 0X08000000 ;
	add_to_call = *(Function_t*)(0x08002404) ;
	add_to_call() ;
}

void main(void)
{
	u8 RecState ;
	MRCC_voidInitSysClock();						/* HSI clock */
	MRCC_voidEnableClock(RCC_APB2 , USART1EN) ;		/* USART1 */
	MRCC_voidEnableClock(RCC_APB2 , IOPAEN) ;		/* GPIOA */
	MRCC_voidEnableClock(RCC_AHB , FLITFEN) ;		/* FPEC */

	MGPIO_voidSetPinDirection(PORTA , PIN9 , GPIO_OUTPUT_SPEED_50MHZ_AFPP);          	//TX AFPP
	MGPIO_voidSetPinDirection(PORTA , PIN10 , GPIO_FLOATING_INPUT);          	 		// RX Input floating

	MSTK_voidInit();

	MUSART1_voidInit();

	MSTK_voidSetIntervalSingle(15000000 , Func) ;

	while(u8TimeoutFlag == 0)
	{
		RecState = MUSART1_voidReceiveSynch(&(RecData[DataCounter])) ;
		if(RecState == 1)
		{
			MSTK_voidStopInterval();

			if(RecData[DataCounter] == '\0')
			{
				if(u8WriteReq == 1)
				{
					FPEC_voidEraseAppArea(10);
					u8WriteReq = 0;
				}

				Parser_voidParseRecord(RecData);
				MUSART1_voidTransmitSynch((u8*)"ok") ;
				DataCounter = 0 ;
			}
			else
			{
				DataCounter++ ;
			}
			MSTK_voidSetIntervalSingle(15000000 , Func) ;
		}
		else
		{
			/* Nothing received */
		}

	}

}
