/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  5 January 2022             */
/* Version :  V01                        */
/*****************************************/

#ifndef		USART_CONFIG_H
#define		USART_CONFIG_H


#define		USART_BAUD_RATE						(9600)

#define 	CLOCK								(8000000)

/* Options : USART_8_BIT_WORD
			 USART_9_BIT_WORD
			 */
#define		USART_WORD_LEN						USART_8_BIT_WORD

/* Options : ENABLE
			 DISABLE
			 */
#define		USART_PARITY						DISABLE

/* Options : EVEN_PARITY
			 ODD_PARITY
			 */
#define		USART_PARITY_TYPE					EVEN_PARITY

#define		USART_TX_INTERRUPT					DISABLE
#define		USART_RX_INTERRUPT					DISABLE
/* Options : USART_1_STOP
			 USART_2_STOP
			 */
#define		USART_STOP_BIT						USART_1_STOP


#endif
