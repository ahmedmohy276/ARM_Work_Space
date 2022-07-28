/****************************************************************/
/*	Author   : Ahmed Mohy									   	*/
/*	Date     : 26 DEC 2021										*/
/*	Version  : V01												*/
/****************************************************************/


#ifndef		NVIC_INTERFACE_H
#define		NVIC_INTERFACE_H


typedef enum {
	WWDG , PVD , TAMPER , RTC , FLASH , RCC , EXTI0 , EXTI1 , EXTI2 , EXTI3 , EXTI4 , DMA1_Channel1 , DMA1_Channel2 ,
	DMA1_Channel3 , DMA1_Channel4 , DMA1_Channel5 , DMA1_Channel6 , DMA1_Channel7 , ADC1_2 , USB_HB_CAN_TX , USB_LB_CAN_RX0 ,
	CAN_RX1 , CAN_SCE , EXTI19_5 , TIM1_BRK , TIM1_UP , TIM1_TRG_COM , TIM1_CC , TIM2 , TIM3 , TIM4 , I2C1_EV , I2C1_ER , 
	I2C2_EV , I2C2_ER , USART1 , USART2 , USART3 , EXTI15_10 , RTCAlarm , USBWakeup , TIM8_BRK , TIM8_UP , TIM8_TRG_COM , 
	TIM8_CC , ADC3 , FSMC , SDIO , TIM5 , SPI3 , UART4 , UART5 , TIM6 , TIM7 , DMA2_Channel1 , DMA2_Channel2 , DMA2_Channel3 ,
	DMA2_Channel4_5 ,
	
}INT_number;



#define 	NVIC_GROUP4_SUB0			0X05FA0300	// 4 bits for Group priority and 0 bits for sub priority

#define 	NVIC_GROUP3_SUB1			0X05FA0400	// 3 bits for Group priority and 1 bits for sub priority

#define 	NVIC_GROUP2_SUB2			0X05FA0500	// 2 bits for Group priority and 2 bits for sub priority

#define 	NVIC_GROUP1_SUB3			0X05FA0600	// 1 bits for Group priority and 3 bits for sub priority

#define 	NVIC_GROUP0_SUB4			0X05FA0700	// 0 bits for Group priority and 4 bits for sub priority



void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNum);

void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNum);

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNum);

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNum);

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNum);

void MNVIC_voidSetPriority(s8 Copy_s8IntNum , u8 Copy_u8GroupPriority  , u8 Copy_u8SubPriority , u32 Copy_u32PriGroup);


#endif
