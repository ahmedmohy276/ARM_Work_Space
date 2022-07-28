/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  20 January 2022             */
/* Version :  V01                        */
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "FPEC_interface.h"
#include "I2C_interface.h"
#include "SYSTICK_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"


extern u8 EEPROM_Address ;
volatile u8 var = 0 ;
extern u16 Byte_Adress ;
extern volatile u8 CRC_error_Flag ;
extern u64 Time_Out ;
extern u8 RecData[15000] ;
extern void Parser_voidParseRecord(u8* Copy_u8BufData) ;
extern u8 AsciToHex(u8 Copy_u8Asci) ;

void Flashing(void)
{
	FPEC_voidEraseAppArea(9);
	/* Write 0 to EEPROM */
	MI2C1_voidRequestMemoryWrite(EEPROM_Address , Byte_Adress , 0) ;
	//MSTK_voidSetBusyWait(10000);
	//var = MI2C1_voidRequestMemoryRead(EEPROM_Address , Byte_Adress) ;
	/* Clear flag */
	CRC_error_Flag = 0 ;
	//volatile u32 Data = *(u32*)(0x08002404) ;

	u16 Local_u8DataCount = 28 ;
	u16 Local_u8RecordCount = 0 ;
	static u8 RecordArr[100] ;
	volatile u16 recordnum = 0 ;
	while( (RecData[Local_u8DataCount] !='C') ||  (RecData[Local_u8DataCount + 1] !='L') )
	{
		if( (RecData[Local_u8DataCount] == '\r') && (RecData[Local_u8DataCount + 1] == '\n') && (RecData[Local_u8DataCount + 2] == '+') )
		{
			while(RecData[Local_u8DataCount] != ':' )
			{
				Local_u8DataCount++ ;
			}
			Local_u8DataCount++ ;
		}

		else if( (RecData[Local_u8DataCount] == '\r') && (RecData[Local_u8DataCount + 1] == '\n') && (RecData[Local_u8DataCount + 2] != '+') )
		{
			recordnum++ ;
			Local_u8DataCount += 2 ;
			Local_u8RecordCount = 0 ;
			Parser_voidParseRecord(RecordArr) ;
		}

		else if( (RecData[Local_u8DataCount] == '\r') && (RecData[Local_u8DataCount + 1] == '\r') && (RecData[Local_u8DataCount + 2] == '\n') && (RecData[Local_u8DataCount + 3] == '+') )
		{

			recordnum++ ;
			Local_u8DataCount += 2 ;
			Local_u8RecordCount = 0 ;
			Parser_voidParseRecord(RecordArr) ;
			while(RecData[Local_u8DataCount] != ':' )
			{
				Local_u8DataCount++ ;
			}
			Local_u8DataCount += 2 ;
		}

		else
		{
			RecordArr[Local_u8RecordCount] = RecData[Local_u8DataCount] ;
			Local_u8RecordCount ++ ;
			Local_u8DataCount++ ;
		}
	}

	//Data = *(u32*)(0x08002404) ;
	if(CRC_error_Flag == 1)
	{
		FPEC_voidEraseAppArea(9) ;
	}
	/* Write 1 to EEPROM */
	MI2C1_voidRequestMemoryWrite(EEPROM_Address , Byte_Adress , 1) ;
	//MSTK_voidSetBusyWait(10000);
	//var = MI2C1_voidRequestMemoryRead(EEPROM_Address , Byte_Adress) ;

}

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


u8 HESP_u8GetFlag(void)
{
	u8 Local_u8Validation = 0;
	u8 Local_u8Index = 0;
	u8 Dummy = 0;
	volatile u8 Local_u8ReceivedFlag = 0;
	Time_Out = 50000 ;
	HESP_voidServerConnect() ;
	HESP_voidSendCommand((u8*)"AT+CIPSEND=46\r\n") ;
	Time_Out = 200000 ;
	while(Local_u8Validation == 0)
	{
		MUSART1_voidTransmitSynch((u8*)"GET http://otawitharm.freevar.com/status.txt\r\n") ;
		Dummy = 0;
		while(Dummy !=255)
		{
			Dummy = MUSART1_u8ReceiveSynch() ;
			RecData[Local_u8Index] = Dummy ;
			Local_u8Index++ ;
		}

		if ( (RecData[24] == 'O') && (RecData[25] == 'K') )
		{
			Local_u8Validation = 1 ;
		}
	}

	Local_u8ReceivedFlag = RecData[37] ;
	Local_u8ReceivedFlag = AsciToHex(Local_u8ReceivedFlag);

	return Local_u8ReceivedFlag ;
}

void HESP_u16GetHexFile(void)
{
	u8 Local_u8Validation = 0;
	u16 Local_u16Index = 0;
	u8 Dummy = 0;
	Time_Out = 50000 ;
	HESP_voidServerConnect() ;
	HESP_voidSendCommand((u8*)"AT+CIPSEND=52\r\n") ;
	Time_Out = 1000000 ;
	while(Local_u8Validation == 0)
	{
		MUSART1_voidTransmitSynch((u8*)"GET http://otawitharm.freevar.com/uploads/code.hex\r\n") ;
		Dummy = 0;
		while(Dummy !=255)
		{
			Dummy = MUSART1_u8ReceiveSynch() ;
			RecData[Local_u16Index] = Dummy ;
			Local_u16Index++ ;
		}
		
		if ( (RecData[24] == 'O') && (RecData[25] == 'K') )
		{
			Local_u8Validation = 1 ;
		}
	}
}


void HESP_voidWiFiConnect(void) 
{
	Time_Out = 1800000 ;
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

	else if ( (ReceiveResponse[8] == 'C') && (ReceiveResponse[14] == 'T') )
	{
			Local_u8Validation = 1 ;
	}

	else 
	{
		Local_u8Validation = 0 ;
	}
	return Local_u8Validation ;
}

