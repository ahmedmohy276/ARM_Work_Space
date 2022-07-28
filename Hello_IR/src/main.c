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
#include "NVIC_interface.h"
#include "AFIO_interface.h"
#include "EXTI_interface.h"
#include "IR_interface.h"

void voidIR_Action(u8 data)
{
	switch (data)
	{
		case 69:
			MGPIO_voidClearPin(PORTA , PIN1);
			MGPIO_voidClearPin(PORTA , PIN2);
			MGPIO_voidClearPin(PORTA , PIN3);
			break;

		case 12:
			MGPIO_voidSetPin(PORTA , PIN1);
			MGPIO_voidClearPin(PORTA , PIN2);
			MGPIO_voidClearPin(PORTA , PIN3);
			break;

		case 24:
			MGPIO_voidClearPin(PORTA , PIN1);
			MGPIO_voidSetPin(PORTA , PIN2);
			MGPIO_voidClearPin(PORTA , PIN3);
			break;

		case 94:
			MGPIO_voidClearPin(PORTA , PIN1);
			MGPIO_voidClearPin(PORTA , PIN2);
			MGPIO_voidSetPin(PORTA , PIN3);
			break;

		case 8:
			MGPIO_voidSetPin(PORTA , PIN1);
			MGPIO_voidSetPin(PORTA , PIN2);
			MGPIO_voidClearPin(PORTA , PIN3);
			break;

		case 28:
			MGPIO_voidClearPin(PORTA , PIN1);
			MGPIO_voidSetPin(PORTA , PIN2);
			MGPIO_voidSetPin(PORTA , PIN3);
			break;

		case 90:
			MGPIO_voidSetPin(PORTA , PIN1);
			MGPIO_voidSetPin(PORTA , PIN2);
			MGPIO_voidSetPin(PORTA , PIN3);
			break;

		default:
			break;
	}
}

void main(void)
{
	/* Initiate system clock to crystal HSE 8MHZ */
	MRCC_voidInitSysClock();

	/* Enable GPIOA clock */
	MRCC_voidEnableClock(RCC_APB2 , IOPAEN);

	/* Set PINA0 as input floating to connect it with IR receiver output */
	MGPIO_voidSetPinDirection(PORTA , PIN0 , GPIO_FLOATING_INPUT);

	/* Set PINA1 as output 2MHZ PP connected to Red in RGB */
	MGPIO_voidSetPinDirection(PORTA , PIN1 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	/* Set PINA2 as output 2MHZ PP connected to Green in RGB */
	MGPIO_voidSetPinDirection(PORTA , PIN2 , GPIO_OUTPUT_SPEED_2MHZ_PP);
	/* Set PINA3 as output 2MHZ PP connected to blue in  RGB */
	MGPIO_voidSetPinDirection(PORTA , PIN3 , GPIO_OUTPUT_SPEED_2MHZ_PP);

	/* Initiate IR */
	HIR_voidInit();

	/* initiate IR call back function */
	HIR_voidSetCallBack(voidIR_Action);

	/* initiate EXTI0 as falling edge */
	MEXTI_voidInit();

	/* Enable EXTI NVIC */
	MNVIC_voidEnableInterrupt(EXTI0);

	/* Enable EXTI0 */
	MEXTI_voidSetSignalLatch(EXTI_LINE0 , EXTI_FALLING);


	while(1)
	{

	}

}
