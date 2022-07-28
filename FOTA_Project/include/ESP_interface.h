/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  20 January 2022             */
/* Version :  V01                        */
/*****************************************/



#ifndef		ESP_INTERFACE_H
#define  	ESP_INTERFACE_H

void Flashing(void) ;

void HESP_voidInit(void) ;

void HESP_voidSendCommand(u8 *Copy_pu8Command) ;

u8 HESP_u8GetFlag(void) ;

void HESP_u16GetHexFile(void) ;

void HESP_voidWiFiConnect(void) ;

void HESP_voidServerConnect(void) ;

#endif
