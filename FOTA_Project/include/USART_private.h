/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  5 January 2022             */
/* Version :  V01                        */
/*****************************************/

#ifndef		USART_PRIVATE_H
#define		USART_PRIVATE_H


#define 	NULL						((void *)0)

#define		USART1_BASE_ADDRESS			0X40013800


typedef struct
{
	volatile u32 SR,DR,BRR ;
	volatile u32 CR[3] ;
	volatile u32 GTPR ;
}USART1_Registers;


#define		USART1						((volatile USART1_Registers*)USART1_BASE_ADDRESS)


u8 *TX_Asynch = NULL ;
void (*TX_Callback) (void) ;
void (*RX_Callback) (u8) ;
static void SET_BRR_Value(void);

#endif
