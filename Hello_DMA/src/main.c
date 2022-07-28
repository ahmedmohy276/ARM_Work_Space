/*
 * main.c
 *
 *  Created on: Jan 3, 2022
 *      Author: ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DMA_interface.h"
#include "NVIC_interface.h"

void main(void)
{
	u16 Local_u16Index = 0;
	u32 arr1[1000] = {0} ;
	u32 arr2[1000] ;
	u32 arr3[1000] = {0} ;
	u32 arr4[1000] ;
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_ABH , DMA1);
	MDMA_voidInitChannel();
	MNVIC_voidEnableInterrupt(DMA1_Channel1);
	MDMA_voidStartChannel(arr3 , arr4 , 1000 , CH1);
	for (Local_u16Index=0 ; Local_u16Index<1000 ; Local_u16Index++)
	{
		arr2[Local_u16Index] = arr1[Local_u16Index] ;
	}


	while(1)
	{

	}

}
