/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  20 January 2022             */
/* Version :  V01                        */
/*****************************************/



#ifndef		ESP_INTERFACE_H
#define  	ESP_INTERFACE_H

void HESP_voidInit(void) ;

void HESP_voidSendCommand(u8 *Copy_pu8Command) ;

u16 HESP_u8SendReceiveData(u8 *Local_pu8RecData) ;

void HESP_voidWiFiConnect(void) ;

void HESP_voidServerConnect(void) ;

#endif