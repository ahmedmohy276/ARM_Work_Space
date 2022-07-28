/****************************************************************/
/*	Author   : Ahmed Mohy									   	*/
/*	Date     : 26 DEC 2021										*/
/*	Version  : V01												*/
/****************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"




void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNum)
{
	if (Copy_u8IntNum <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8IntNum);
	}
	
	else if (Copy_u8IntNum <= 59)
	{
		Copy_u8IntNum -=32;
		NVIC_ISER1 = (1 << Copy_u8IntNum);
	}
	
	else 
	{
		/* return an error */
	}
}


void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNum)
{
	if (Copy_u8IntNum <= 31)
	{
		NVIC_ICER0 = (1 << Copy_u8IntNum);
	}
	
	else if (Copy_u8IntNum <= 59)
	{
		Copy_u8IntNum -=32;
		NVIC_ICER1 = (1 << Copy_u8IntNum);
	}
	
	else 
	{
		/* return an error */
	}
}


void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNum)
{
	if (Copy_u8IntNum <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNum);
	}
	
	else if (Copy_u8IntNum <= 59)
	{
		Copy_u8IntNum -=32;
		NVIC_ISPR1 = (1 << Copy_u8IntNum);
	}
	
	else 
	{
		/* return an error */
	}
}


void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNum)
{
	if (Copy_u8IntNum <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNum);
	}
	
	else if (Copy_u8IntNum <= 59)
	{
		Copy_u8IntNum -=32;
		NVIC_ICPR1 = (1 << Copy_u8IntNum);
	}
	
	else 
	{
		/* return an error */
	}
}


u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNum)
{
	u8 Local_u8Result = 0;
	if (Copy_u8IntNum <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0 , Copy_u8IntNum);
	}
	
	else if (Copy_u8IntNum <= 59)
	{
		Copy_u8IntNum -=32;
		Local_u8Result = GET_BIT(NVIC_IABR1 , Copy_u8IntNum);
	}
	
	else 
	{
		/* return an error */
	}
	
	return Local_u8Result;
}


void MNVIC_voidSetPriority(s8 Copy_s8IntNum , u8 Copy_u8GroupPriority  , u8 Copy_u8SubPriority, u32 Copy_u32PriGroup)
{
	/* SCB_AIRCR register is used to determines the split of group priority from sub priority */
	#define		SCB_AIRCR						(*((volatile u32*)(0XE000ED00 + 0X0C)))
	u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << (Copy_u32PriGroup - 0X05FA0300)/256) ; // 256 = 0x100
	/* Core peripheral */
	
	/* External Peripheral */
	
	if (Copy_s8IntNum >= 0)
	{
		NVIC_IPR[Copy_s8IntNum] = Local_u8Priority << 4 ;
	}
	
	SCB_AIRCR = Copy_u32PriGroup ;
}   
    
    
    
