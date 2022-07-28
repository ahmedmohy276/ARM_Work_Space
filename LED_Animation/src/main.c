/*
 * main.c
 *
 *  Created on: Dec 29, 2021
 *      Author: ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"
#include "LED_interface.h"
#include "LEDANIM_interface.h"



void main(void)
{
	MRCC_voidInitSysClock();				    //Initiate system clock at HSE 8MHZ
	MRCC_voidEnableClock(RCC_APB2,IOPAEN);      //enable GPIOA clock
	LEDANIM_voidInit();							//initialize PORTA for leds


	while(1)
	{
		LEDANIM_voidDisplayPingPong(200,2);
		LEDANIM_voidDisplayInOut(300,5);
		LEDANIM_voidDisplayFlashing(700,5);
	}
}
