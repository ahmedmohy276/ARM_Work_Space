/*
 * main.c
 *
 *  Created on: Jan 1, 2022
 *      Author: ahmed
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"
#include "OS_interface.h"


void LED0(void);
void LED1(void);
void LED2(void);

void main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2 , IOPAEN);

	MGPIO_voidSetPinDirection(PORTA , PIN0 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA , PIN1 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA , PIN2 , GPIO_OUTPUT_SPEED_2MHZ_PP);

	SOS_voidCreateTask(0 , 1000 , LED0 , 0);

	SOS_voidCreateTask(1 , 2000 , LED1 , 1);

	SOS_voidCreateTask(2 , 3000 , LED2 , 2);

	SOS_voidStart() ;

	while(1)
	{


	}

}

void LED0(void)
{
	static u8 Local_u8Togg = 0 ;
	TOG_BIT(Local_u8Togg , 0);
	MGPIO_voidSetPinValue(PORTA , PIN0 , Local_u8Togg);
}
void LED1(void)
{
	static u8 Local_u8Togg = 0 ;
	TOG_BIT(Local_u8Togg , 0);
	MGPIO_voidSetPinValue(PORTA , PIN1 , Local_u8Togg);
}
void LED2(void)
{
	static u8 Local_u8Togg = 0 ;
	TOG_BIT(Local_u8Togg , 0);
	MGPIO_voidSetPinValue(PORTA , PIN2 , Local_u8Togg);
}





