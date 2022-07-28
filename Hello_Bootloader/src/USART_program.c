/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  5 January 2022             */
/* Version :  V01                        */
/*****************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "math.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"



void MUSART1_voidInit(void) 
{
	SET_BRR_Value();
	/* clear registers */
	USART1->CR[0] = 0 ;
	USART1->CR[1] = 0 ;
	USART1->CR[2] = 0 ;
	
	USART1->CR[0] |= ( (USART_WORD_LEN << 12) | (USART_PARITY << 10) | (USART_PARITY_TYPE << 9) |
					   (USART_TX_INTERRUPT << 6) | (USART_RX_INTERRUPT << 5) ) ;
					   
	USART1->CR[1] |= ( (USART_STOP_BIT << 12) ) ;
	
	SET_BIT(USART1->CR[0] , 2);			//RX enable
	SET_BIT(USART1->CR[0] , 3);			//TX enable
	SET_BIT(USART1->CR[0] , 13);		//USART enable

	USART1 -> SR = 0;
}


void MUSART1_voidTransmitSynch(u8 Copy_TXData[])
{
	u8 Local_u8Index = 0;
	while(Copy_TXData[Local_u8Index] != '\0'){
		USART1->DR = Copy_TXData[Local_u8Index];
		while(GET_BIT(USART1 -> SR, 6) == 0);
		Local_u8Index++;
	}
}


void MUSART1_voidTransmitAsynch(u8 *Copy_TXData , void (*TXptr)(void))
{
	TX_Callback = TXptr ; 
	TX_Asynch = Copy_TXData ;
	USART1->DR = TX_Asynch[0];
}



u8 MUSART1_voidReceiveSynch(u8 *Copy_u8Data)
{
	u8 Local_u8Result = 1;

		if ( (GET_BIT((USART1 -> SR), 5)) == 1 )
		{
			*Copy_u8Data = USART1 -> DR;
		}
		else
		{
			Local_u8Result = 0;
		}

		return (Local_u8Result);
}


void MUSART1_voidReceiveAsynch( void (*RXptr)(u8))
{
	RX_Callback = RXptr ;
}




void USART1_TX_IRQHandler(void)
{
	
}


void USART1_RX_IRQHandler(void)
{
	RX_Callback(USART1->DR) ;
}


static void SET_BRR_Value(void)
{
	f32 Local_f32Val1 ;
	f32 Local_f32Val2 ;
	u16 Local_u16Mantissa;
	u8  Local_u8Frac;
	
	Local_f32Val1 = (((u32)CLOCK) / (16.0 * (u32)USART_BAUD_RATE)) ;
	Local_u16Mantissa = Local_f32Val1 ;
	Local_f32Val2 = Local_f32Val1 - (u16)Local_f32Val1 ;
	Local_f32Val2 *= 16 ;
	Local_f32Val2 = round(Local_f32Val2);
	Local_u8Frac = Local_f32Val2 ;
	Local_u16Mantissa = ( (Local_u16Mantissa << 4) | (Local_u8Frac & 0xf)) ;
	USART1->BRR = Local_u16Mantissa ;
}
