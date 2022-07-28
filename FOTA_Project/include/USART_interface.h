/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  5 January 2022             */
/* Version :  V01                        */
/*****************************************/

#ifndef		USART_INTERFACE_H
#define		USART_INTERFACE_H



#define		USART_8_BIT_WORD			0
#define		USART_9_BIT_WORD			1

#define		ENABLE						1
#define		DISABLE						0

#define		USART_1_STOP				0
#define		USART_2_STOP				2


#define		EVEN_PARITY					0		
#define		ODD_PARITY					1	



void MUSART1_voidInit(void) ;
void MUSART1_voidTransmitSynch(u8 Copy_TXData[]);
void MUSART1_voidTransmitAsynch(u8 *Copy_TXData , void (*TXptr)(void));

u8 MUSART1_u8ReceiveSynch(void);
void MUSART1_voidReceiveAsynch( void (*RXptr)(u8));






#endif
