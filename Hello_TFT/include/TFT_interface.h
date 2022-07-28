/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  5 January 2022             */
/* Version :  V01                        */
/*****************************************/



#ifndef		TFT_INTERFACE_H
#define  	TFT_INTERFACE_H

void HTFT_voidInit(void);
void HTFT_voidDisplayImage(const u16 *Copy_Image) ;

void HTFT_voidFillColour(u16 Copy_u16Colour);

void HTFT_voidDrawRect(u8 x1 , u8 x2 , u8 y1 , u8 y2 ,u16 Copy_u16Colour);


#endif
