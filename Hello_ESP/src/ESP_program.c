/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  20 January 2022             */
/* Version :  V01                        */
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"


extern u64 Time_Out ;

void HESP_voidSendCommand(u8 *Copy_pu8Command) 
{
	u8 Local_u8Response = 0;
	while(Local_u8Response == 0)
	{
		MUSART1_voidTransmitSynch(Copy_pu8Command) ;
		Local_u8Response = ValidateResponse() ;
	}
}


void HESP_voidInit(void) 
{
	/* Disable Echo */
	Time_Out = 10000 ;
	HESP_voidSendCommand((u8*)"ATE0\r\n") ;
	
	/* Set ESP To Station Mode */
	Time_Out = 10000 ;
	HESP_voidSendCommand((u8*)"AT+CWMODE=1\r\n") ;
	/*HESP_voidSendCommand((u8*)"AT+CWJAP_CUR=\"Honor_8x\",\"01065121188Mohy#\"\r\n") ;
	HESP_voidSendCommand((u8*)"AT+CIPSTART=\"TCP\",\"162.253.155.226\",80\r\n") ;
	HESP_voidSendCommand((u8*)"AT+CIPSEND=40\r\n") ;
	MUSART1_voidTransmitSynch((u8*)"GET http://mohy.freevar.com/status.txt\r\n") ;*/
}


u16 HESP_u8SendReceiveData(u8 *Local_pu8RecData) 
{
	u8 Local_u8Length = 0;
	u8 ReceiveResponse [1000] = {0} ;
	u8 Local_u8Validation = 0;
	u8 Local_u8Index = 0;
	u8 Dummy = 0;
	Time_Out = 50000 ;
	HESP_voidServerConnect() ;
	HESP_voidSendCommand((u8*)"AT+CIPSEND=40\r\n") ;
	Time_Out = 200000 ;
	while(Local_u8Validation == 0)
	{
		MUSART1_voidTransmitSynch((u8*)"GET http://mohy.freevar.com/status.txt\r\n") ;
		Dummy = 0;
		while(Dummy !=255)
		{
			Dummy = MUSART1_u8ReceiveSynch() ;
			ReceiveResponse[Local_u8Index] = Dummy ;
			Local_u8Index++ ;
		}
		
		if ( (ReceiveResponse[24] == 'O') && (ReceiveResponse[25] == 'K') )
		{
			Local_u8Validation = 1 ;
		}
	}
	
	Local_u8Length = ReceiveResponse[35] - 48 ;
	for (Local_u8Index=0 ; Local_u8Index < Local_u8Length ; Local_u8Index++)
	{
		Local_pu8RecData[Local_u8Index] = ReceiveResponse[Local_u8Index + 37] ;
	}
	
	return Local_u8Length ;
}


void HESP_voidWiFiConnect(void) 
{
	Time_Out = 1700000 ;
	HESP_voidSendCommand((u8*)"AT+CWJAP_CUR=\"Honor_8x\",\"01065121188Mohy#\"\r\n") ;
}


void HESP_voidServerConnect(void) 
{
	Time_Out = 10000 ;
	HESP_voidSendCommand((u8*)"AT+CIPSTART=\"TCP\",\"162.253.155.226\",80\r\n") ;
}


static u8 ValidateResponse(void)
{
	volatile u8 ReceiveResponse [100] = {0} ;
	u8 Local_u8Validation = 0;
	u8 Local_u8Index = 0;
	u8 Dummy = 0;
	while(Dummy !=255)
	{
		Dummy = MUSART1_u8ReceiveSynch() ;
		ReceiveResponse[Local_u8Index] = Dummy ;
		Local_u8Index++ ;
	}
	
	if ( (ReceiveResponse[2] == 'O') && (ReceiveResponse[3] == 'K') )
	{
		Local_u8Validation = 1 ;
	}

	else if ( (ReceiveResponse[9] == 'O') && (ReceiveResponse[10] == 'K') )
	{
		Local_u8Validation = 1 ;
	}
	
	else if ( (ReceiveResponse[48] == 'O') && (ReceiveResponse[49] == 'K') )
	{
		Local_u8Validation = 1 ;
	}
	else if ( (ReceiveResponse[11] == 'O') && (ReceiveResponse[12] == 'K') )
	{
		Local_u8Validation = 1 ;
	}
	
	else if ( (ReceiveResponse[31] == 'O') && (ReceiveResponse[32] == 'K') )
	{
		Local_u8Validation = 1 ;
	}

	else if ( (ReceiveResponse[8] == 'C') && (ReceiveResponse[16] == 'D') )
	{
			Local_u8Validation = 1 ;
	}

	else 
	{
		Local_u8Validation = 0 ;
	}
	return Local_u8Validation ;
}

