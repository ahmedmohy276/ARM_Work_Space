/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  17 February 2022           */
/* Version :  V01                        */
/*****************************************/


#ifndef		SIM800L_INTERFACE_H
#define		SIM800L_INTERFACE_H

void HSIM800L_voidInit(void) ;

void HSIM800L_voidSendMessage(u8 *Message)  ;

void HSIM800L_u8ReceiveMessage(u8 *Response)  ;

#endif
