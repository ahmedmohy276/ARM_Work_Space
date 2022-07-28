/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  17 February 2022           */
/* Version :  V01                        */
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "SYSTICK_interface.h"

#include "SIM800L_interface.h"
#include "SIM800L_private.h"
#include "SIM800L_config.h"



void HSIM800L_voidInit(void) 
{
	/*Set baud rate at 9,600 bps*/
	MUSART1_voidTransmitSynch((u8*)"AT+IPR=9600") ;
	/* Delay 200ms */
	MSTK_voidSetBusyWait( 200000 );
	
	/*Synchronize baud rate*/
	/*Once the handshake test is successful, it will back to OK*/
	MUSART1_voidTransmitSynch((u8*)"AT") ;
	/* Delay 200ms */
	MSTK_voidSetBusyWait( 200000 );
	
	/*Read SIM information to confirm whether the SIM is plugged*/
	MUSART1_voidTransmitSynch((u8*)"AT+CCID") ;
	/* Delay 200ms */
	MSTK_voidSetBusyWait( 200000 );
	
	/*Check whether it has registered in the network*/
	MUSART1_voidTransmitSynch((u8*)"AT+CREG?") ;
	/* Delay 200ms */
	MSTK_voidSetBusyWait( 200000 );
	
	/*Inquire GSM signal quality*/
	MUSART1_voidTransmitSynch((u8*)"AT+CSQ") ;
	/* Delay 200ms */
	MSTK_voidSetBusyWait( 200000 );
	
	/*Inquire charging status and remaining battery capacity*/
	MUSART1_voidTransmitSynch((u8*)"AT+CBC") ;
	/* Delay 200ms */
	MSTK_voidSetBusyWait( 200000 );
}


void HSIM800L_voidSendMessage(u8 *Message)
{
	/*Synchronize baud rate*/
	/*Once the handshake test is successful, it will back to OK*/
	MUSART1_voidTransmitSynch((u8*)"AT") ;
	/* Delay 200ms */
	MSTK_voidSetBusyWait( 200000 );
	
	/*Configuring TEXT mode*/
	MUSART1_voidTransmitSynch((u8*)"AT+CMGF=1") ;
	/* Delay 200ms */
	MSTK_voidSetBusyWait( 200000 );
	
	/*change ZZ with country code and xxxxxxxxxxx with phone number to sms*/
	MUSART1_voidTransmitSynch((u8*)"AT+CMGS=\"+ZZxxxxxxxxxx\"") ;
	/* Delay 200ms */
	MSTK_voidSetBusyWait( 200000 );
	
	/*Enter the custom message*/
	MUSART1_voidTransmitSynch(Message) ;
	/* Delay 200ms */
	MSTK_voidSetBusyWait( 200000 );
	
	/*End of message character 0x1A : Equivalent to Ctrl+z*/
	MUSART1_voidTransmitSynch((u8*)0X1A) ;
	/* Delay 200ms */
	MSTK_voidSetBusyWait( 200000 );

}


void HSIM800L_u8ReceiveMessage(u8 *Response) 
{
	u8 Dummy = 0;
	u16 counter = 0 ;
	/*Synchronize baud rate*/
	/*Once the handshake test is successful, it will back to OK*/
	MUSART1_voidTransmitSynch((u8*)"AT") ;
	/* Delay 200ms */
	MSTK_voidSetBusyWait( 200000 );
	
	/*Configuring TEXT mode*/
	MUSART1_voidTransmitSynch((u8*)"AT+CMGF=1") ;
	/* Delay 200ms */
	MSTK_voidSetBusyWait( 200000 );
	
	/*Decides how newly arrived SMS messages should be handled*/
	MUSART1_voidTransmitSynch((u8*)"AT+CNMI=1,2,0,0,0") ;
	
	while(Dummy != 255)
	{
		/* Receive response */
		Dummy = MUSART1_u8ReceiveSynch() ;
		Response[counter] = Dummy ;
		counter++ ;
	}
	
}

