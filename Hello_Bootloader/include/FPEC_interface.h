/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  7 January 2022             */
/* Version :  V01                        */
/*****************************************/



#ifndef		FPEC_INTERFACE_H
#define  	FPEC_INTERFACE_H

void FPEC_voidEraseAppArea(u8 Copy_u8StartPage) ;

void FPEC_voidFlashErasePage(u8 Copy_u8PageNum) ;

void FPEC_voidFlashWrite(u32 Copy_u32Address , u16* Copy_pu16Data , u8 Copy_u8Length) ;



#endif