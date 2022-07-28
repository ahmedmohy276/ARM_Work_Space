/*

 * main.c
 *
 *  Created on: Jan 3, 2022
 *      Author: ahmed
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STP_interface.h"
#include "SYSTICK_interface.h"


void main(void)
{
	u8 Local_u8Index = 0;
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2 , IOPAEN);
	HSTP_voidInit();


	while(1)
	{
		for (Local_u8Index=0 ; Local_u8Index < 8 ; Local_u8Index++)
		{
			HSTP_voidSendSynchronous(1 << Local_u8Index);
			MSTK_voidSetBusyWait(300000);
		}
	}
}
