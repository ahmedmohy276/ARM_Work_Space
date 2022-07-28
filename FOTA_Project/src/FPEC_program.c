/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  7 January 2022             */
/* Version :  V01                        */
/*****************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"FPEC_interface.h"
#include"FPEC_private.h"
#include"FPEC_config.h"


void FPEC_voidEraseAppArea(u8 Copy_u8StartPage) 
{
	u8 Local_u8Index = Copy_u8StartPage ;
	for(Local_u8Index=Copy_u8StartPage ; Local_u8Index<64 ; Local_u8Index++)
	{
		FPEC_voidFlashErasePage(Local_u8Index) ;
	}
}


void FPEC_voidFlashErasePage(u8 Copy_u8PageNum) 
{
	/* wait busy flag */
	while(GET_BIT(FPEC->SR , 0) == 1);
	
	/*Check if flash is locked or no */
	if( GET_BIT(FPEC->CR , 7) == 1) 
	{
		/*Unlock sequence */
		FPEC->KEYR = 0X45670123 ;
		FPEC->KEYR = 0XCDEF89AB ;
	}
	
	/* Page erase operation */
	SET_BIT(FPEC->CR , 1);
	
	/* Set page addres to be erased */
	FPEC->AR = (u32)(Copy_u8PageNum * 1024) + 0X08000000;
	
	/*Start Erase */
	SET_BIT(FPEC->CR , 6);
	
	/* wait busy flag */
	while(GET_BIT(FPEC->SR , 0) == 1);
	
	/* End Off Operation */
	SET_BIT(FPEC->SR , 5);
	CLR_BIT(FPEC->CR , 1);
}


void FPEC_voidFlashWrite(u32 Copy_u32Address , u16* Copy_pu16Data , u8 Copy_u8Length) 
{
	u8 i = 0;
	volatile u16 Temp = 0;
	//volatile u16 Var = 0 ;
	/* wait busy flag */
	while(GET_BIT(FPEC->SR , 0) == 1);
	
	/*Check if flash is locked or no */
	if( GET_BIT(FPEC->CR , 7) == 1) 
	{
		/*Unlock sequence */
		FPEC->KEYR = 0X45670123 ;
		FPEC->KEYR = 0XCDEF89AB ;
	}
	
	for (i=0 ; i<Copy_u8Length ; i++)
	{
		/* flash write operation */
		SET_BIT(FPEC->CR , 0);
		
		/* Half word operation */
		
		Temp = Copy_pu16Data[i] ;
		*((volatile u16*)Copy_u32Address)= Copy_pu16Data[i] ;
		//Var = *(u16*)(Copy_u32Address) ;
		Copy_u32Address += 2 ;
		
		/* wait busy flag */
		while(GET_BIT(FPEC->SR , 0) == 1);
		
		/* End Off Operation */
		SET_BIT(FPEC->SR , 5);
		CLR_BIT(FPEC->CR , 0);
	}
	
}


