/*
 * main.c
 *
 *  Created on: Dec 30, 2021
 *      Author: ahmed
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "AFIO_interface.h"
#include "EXTI_interface.h"

void FunctionPassedToEXTI0(void);
void FunctionPassedToEXTI1(void);

void main (void)
{
	/* Initiate System clock to Crystal HSE clock 8MHZ */
	MRCC_voidInitSysClock();
	/* Initiate EXTI */
	MEXTI_voidInit();

	/* enable GPIOA Clock */
	MRCC_voidEnableClock(RCC_APB2 , IOPAEN);

	/* Set PINA0 as input pull up resistor to connect it with a switch */
	MGPIO_voidSetPullResistor(PORTA , PIN0 , GPIO_PULL_UP);

	/* Set PINA1 as input pull up resistor to connect it with a switch */
	MGPIO_voidSetPullResistor(PORTA , PIN1 , GPIO_PULL_UP);

	/* Set PINA5 as Output NMHZ Push pull */
	MGPIO_voidSetPinDirection(PORTA , PIN5 , GPIO_OUTPUT_SPEED_2MHZ_PP);

	/* Set PINA6 as Output NMHZ Push pull */
	MGPIO_voidSetPinDirection(PORTA , PIN6 , GPIO_OUTPUT_SPEED_2MHZ_PP);

	/* Set PINA7 as Output NMHZ Push pull */
	MGPIO_voidSetPinDirection(PORTA , PIN7 , GPIO_OUTPUT_SPEED_2MHZ_PP);

	/* set EXTI1 as higher group priority than EXTI0 so it can interrupt it */
	MNVIC_voidSetPriority(EXTI0,1,0,NVIC_GROUP2_SUB2); // EXTI0 Group 1 Sub 0
	MNVIC_voidSetPriority(EXTI1,0,3,NVIC_GROUP2_SUB2); // EXTI1 Group 0	Sub 3

	/* Set EXTIO Mode */
	MEXTI_voidSetSignalLatch(EXTI_LINE0 , EXTI_FALLING);

	/* Set EXTI1 Mode */
	MEXTI_voidSetSignalLatch(EXTI_LINE1 , EXTI_FALLING);

	/* Pass function to EXTI0 */
	MEXTI_voidSetCallBack(EXTI_LINE0 , FunctionPassedToEXTI0);

	/* Pass function to EXTI1 */
	MEXTI_voidSetCallBack(EXTI_LINE1 , FunctionPassedToEXTI1);

	/* enable NVIC EXTI0 */
	MNVIC_voidEnableInterrupt(EXTI0);

	/* enable NVIC EXTI1 */
	MNVIC_voidEnableInterrupt(EXTI1);


	while (1)
	{

	}
}

void FunctionPassedToEXTI0(void)
{
	MGPIO_voidSetPin(PORTA,PIN5);
	/* Set Pending Flag interrupt for EXTI1 */
	//MNVIC_voidSetPendingFlag(EXTI1);
	MGPIO_voidSetPin(PORTA,PIN6);
}

void FunctionPassedToEXTI1(void)
{
	MGPIO_voidSetPin(PORTA,PIN7);
}
