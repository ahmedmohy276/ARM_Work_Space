/*****************************************************************************/
/* Author    : Ahmed Mohy													 */
/* Date      : 24 DEC 2021													 */
/* Version   : V01														     */
/*****************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define 	RCC_AHB			0
#define 	RCC_APB1		1
#define 	RCC_APB2		2


#define 	SDIOEN			10
#define 	FSMCEN			8
#define 	CRCEN			6
#define 	FLITFEN			4
#define 	SRAMEN			2
#define 	DMA2			1
#define 	DMA1			0
#define 	TIM11EN			21
#define 	TIM10EN			20
#define 	TIM19EN			19
#define 	ADC3EN			15
#define 	USART1EN		14
#define 	TIM8EN			13
#define 	SPI1EN			12
#define 	TIM1EN			11
#define 	ADC2EN			10
#define 	ADC1EN			9
#define 	IOPGEN			8
#define 	IOPFEN			7
#define 	IOPEEN			6
#define 	IOPDEN			5
#define 	IOPCEN			4
#define 	IOPBEN			3
#define 	IOPAEN			2
#define 	AFIOEN			0


void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);
void MRCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);



#endif
