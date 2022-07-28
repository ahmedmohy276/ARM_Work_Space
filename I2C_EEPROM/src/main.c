/*
 * main.c
 *
 *  Created on: Mar 25, 2022
 *      Author: ahmed
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"
#include "I2C_interface.h"

#define PAGE_NUMBER    1
#define BYTE_NUMBER    1

volatile u8 var = 1 ;
volatile u8 var2 = 0 ;
u16 Byte_Adress = (5 << PAGE_NUMBER) | (BYTE_NUMBER) ;

u8 Slave_Address = 80 ;

void func(void)
{
	var = (var ^ 1) ;
	MSTK_voidSetBusyWait(5000) ;
	MI2C1_voidRequestMemoryWrite(Slave_Address , Byte_Adress , var) ;
	//var2 = MI2C1_voidRequestMemoryRead(Slave_Address , Byte_Adress) ;
}

int main(void)
{
	MRCC_voidInitSysClock() ;	/* initialize HSI as system clock */
	MRCC_voidEnableClock(RCC_APB1 , I2C1EN) ;		/* I2C1 Enable clock */
	MRCC_voidEnableClock(RCC_APB2 , IOPAEN) ;		/* GPIOA Enable clock */
	MRCC_voidEnableClock(RCC_APB2 , IOPBEN) ;		/* GPIOB Enable clock */

	/* Set direction of pins SCL1-->PINB6 and SDA1-->PINB7 as GPIO_OUTPUT_SPEED_50MHZ_AFOD */
	MGPIO_voidSetPinDirection(PORTB ,PIN6 , GPIO_OUTPUT_SPEED_50MHZ_AFOD) ;
	MGPIO_voidSetPinDirection(PORTB ,PIN7 , GPIO_OUTPUT_SPEED_50MHZ_AFOD) ;

	MGPIO_voidSetPinDirection(PORTA ,PIN0 , GPIO_OUTPUT_SPEED_50MHZ_PP) ;

	MI2C1_voidInit() ;			/* initialize I2C1 */
	MSTK_voidInit() ;			/* initialize Systick timer */

	//MSTK_voidSetIntervalPeriodic(500000 , func) ;

	u8 x = 0 ;
	while(1)
	{
		MI2C1_voidRequestMemoryWrite(Slave_Address , Byte_Adress , var) ;
		MSTK_voidSetBusyWait(5000) ;
		x = MI2C1_voidRequestMemoryRead(Slave_Address , Byte_Adress) ;
		if(x == 0)
		{
			MGPIO_voidClearPin(PORTA , PIN0) ;
		}

		else if(x == 1)
		{
			MGPIO_voidSetPin(PORTA , PIN0) ;
		}
		MSTK_voidSetBusyWait(500000) ;
		var ^= 1 ;
	}
	return 0 ;
}
