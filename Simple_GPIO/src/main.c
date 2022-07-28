/*
 * main.c
 *
 *  Created on: Dec 25, 2021
 *      Author: ahmed
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"

void main(void)
{
	/* Initiate System clock to HSE Crystal as RCC config */
	MRCC_voidInitSysClock();
	/* Enable RCC for GPIOA */
	MRCC_voidEnableClock(RCC_APB2,IOPAEN);
	/* Enable RCC for GPIOB */
	MRCC_voidEnableClock(RCC_APB2,IOPBEN);
	/* Enable RCC for GPIOC */
	MRCC_voidEnableClock(RCC_APB2,IOPCEN);
	/***********************************************************/

	/* set PINA0 direction to Output 10MHZ Push Pull */
	MGPIO_voidSetPinDirection(PORTA,PIN0,GPIO_OUTPUT_SPEED_10MHZ_PP);

	MGPIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(PORTC,PIN14,GPIO_OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(PORTC,PIN15,GPIO_OUTPUT_SPEED_10MHZ_PP);

	MGPIO_voidSetPortDirection(PORTA,GPIO_OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPortDirection(PORTB,GPIO_OUTPUT_SPEED_10MHZ_PP);

	MGPIO_voidSetPullResistor(PORTB , PIN0 , GPIO_PULL_UP);
	MGPIO_voidSetPullResistor(PORTB , PIN1 , GPIO_PULL_DOWN);

	//MGPIO_voidSetPortValue(PORTA , 0XFFFF);
	//MGPIO_voidSetPortValue(PORTB , 0XFFFF);
	MGPIO_voidSetPin(PORTC,PIN13);
	MGPIO_voidSetPin(PORTC,PIN14);
	MGPIO_voidSetPin(PORTC,PIN15);


	while(1)
	{
		if (MGPIO_u8GetPinValue(PORTB , PIN0 ) == GPIO_LOW)
		{
			/* set PINA1 */
			MGPIO_voidSetPin(PORTA,PIN7);
		}

		if (MGPIO_u8GetPinValue(PORTB , PIN1 ) == GPIO_HIGH)
		{
			/* Clear PINA1 */
			MGPIO_voidClearPin(PORTA,PIN7);
		}
		/* set PINA0 to high value */
		MGPIO_voidSetPin(PORTA,PIN0);

		/* Delay method 1 second */
		MSTK_voidSetBusyWait(200000);

		/* set PINA0 to low value */
		MGPIO_voidClearPin(PORTA,PIN0);

		/* Delay method 1 second */
		MSTK_voidSetBusyWait(200000);
	}




}
