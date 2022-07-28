/*
 * main.c
 *
 *  Created on: Dec 28, 2021
 *      Author: ahmed
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"



/* the ISR */
void FunctionPassedToEXTI0(void);


void FunctionPassedToEXTI1(void);



void main(void)
{
	/* enable GPIOA Clock */
	MRCC_voidEnableClock(RCC_APB2,IOPAEN);

	/* set PINA0 , PINA1 and PINA2 configuration to Output 2MHZ PP */
	MGPIO_voidSetPinDirection(PORTA,PIN0,GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,PIN1,GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(PORTA,PIN2,GPIO_OUTPUT_SPEED_2MHZ_PP);

	/* set EXTI1 as higher group priority than EXTI0 so it can interrupt it */
	MNVIC_voidSetPriority(EXTI0,1,0,NVIC_GROUP2_SUB2); // EXTI0 Group 1 Sub 0
	MNVIC_voidSetPriority(EXTI1,0,3,NVIC_GROUP2_SUB2); // EXTI1 Group 0	Sub 3


	/* Pass function FunctionPassedToEXTI0 as pointer to EXTI0 */
	MEXTI_voidSetCallBack( EXTI_LINE0 , FunctionPassedToEXTI0 );

	/* Pass function FunctionPassedToEXTI1 as pointer to EXTI1 */
	MEXTI_voidSetCallBack( EXTI_LINE1 , FunctionPassedToEXTI1 );

	/* enable interrupt  EXTI0 from NVIC */
	MNVIC_voidEnableInterrupt(EXTI0);

	/* enable interrupt  EXTI1 from NVIC */
	MNVIC_voidEnableInterrupt(EXTI1);

	/* Set Pending Flag interrupt for EXTI0 */
	MNVIC_voidSetPendingFlag(EXTI0);




	while(1)
	{

	}
}

/* the ISR */
void FunctionPassedToEXTI0(void)
{
	MGPIO_voidSetPin(PORTA,PIN0);
	/* Set Pending Flag interrupt for EXTI1 */
	MNVIC_voidSetPendingFlag(EXTI1);
	MGPIO_voidSetPin(PORTA,PIN1);
}

void FunctionPassedToEXTI1(void)
{
	MGPIO_voidSetPin(PORTA,PIN2);
}

