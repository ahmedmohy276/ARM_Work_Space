/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  3 January 2022             */
/* Version :  V01                        */
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"
	

void MDMA_voidInitChannel(void) 
{
	/* Clear CCR register */
	DMA->Channel[CHANNEL_NUM].CCR ^= DMA->Channel[CHANNEL_NUM].CCR ;
	/* Set the configuration to CCR register */
	DMA->Channel[CHANNEL_NUM].CCR |= ( (TRANSFER_INT << 1) | (HALF_TRANSFER_INT << 2) | (TRANSFER_ER_INT << 3) | 
									 (DATA_TRANSFER_DIRECTION << 4) | (CIRCULAR_MODE << 5) | (PINC << 6) | 
									 (MINC << 7) | (SOURCE_SIZE << 8) | (DESTINATION_SIZE << 10)| 
									 (CHANNEL_PRIORITY << 12) | (MEMORY_TO_MEMORY_MODE << 14) ) ;
	/* Disable channel */
	CLR_BIT(DMA->Channel[CHANNEL_NUM].CCR , 0) ;
}

void MDMA_voidStartChannel(u32 *Copy_pu32SrcAddress , u32 *Copy_pu32DestAddress , u16 Copy_u16BlockLength , u8 Copy_u8ChannelNum)
{
	/* Disable Channel before writing on registers */
	CLR_BIT(DMA->Channel[Copy_u8ChannelNum].CCR , 0) ;
	/* Load Source and Detination addresses */
	DMA->Channel[Copy_u8ChannelNum].CPAR = Copy_pu32SrcAddress ;
	DMA->Channel[Copy_u8ChannelNum].CMAR = Copy_pu32DestAddress ;
	/* Load Data block length */
	DMA->Channel[Copy_u8ChannelNum].CNDTR = Copy_u16BlockLength ;
	/* Enable Channel */
	SET_BIT(DMA->Channel[CHANNEL_NUM].CCR , 0) ;
}


void MDMA_voidSetChannelConfig( u8 Copy_u8ChannelNum , u8 Copy_u8TCIState , u8 Copy_u8HTCIState , u8 Copy_u8TEIState ,
							   u8 Copy_u8Direction , u8 Copy_u8CircModeState , u8 Copy_u8PINCState , u8 Copy_u8MINCState ,
							   u8 Copy_u8SrcDataSize , u8 Copy_u8DestDataSize , u8 Copy_u8ChPriority , u8 Copy_u8ModeStat )
{
   /* Disable Channel before writing on registers */
	CLR_BIT(DMA->Channel[Copy_u8ChannelNum].CCR , 0) ;
	/* Clear CCR register */
	DMA->Channel[Copy_u8ChannelNum].CCR ^= DMA->Channel[Copy_u8ChannelNum].CCR ;
	/* Set the configuration to CCR register */
	DMA->Channel[Copy_u8ChannelNum].CCR |= ( (Copy_u8TCIState << 1) | (Copy_u8HTCIState << 2) | (Copy_u8TEIState << 3) | 
										   (Copy_u8Direction << 4) | (Copy_u8CircModeState << 5) | (Copy_u8PINCState << 6) | 
										   (Copy_u8MINCState << 7) | (Copy_u8SrcDataSize << 8) | (Copy_u8DestDataSize << 10)| 
										   (Copy_u8ChPriority << 12) | (Copy_u8ModeStat << 14) ) ;
	/* Disable channel */                 
	CLR_BIT(DMA->Channel[Copy_u8ChannelNum].CCR , 0) ;
	
}

void MDMA_voidEnableChannel(u8 Copy_u8ChannelNum)
{
	/* Enable Channel */
	SET_BIT(DMA->Channel[Copy_u8ChannelNum].CCR , 0); 
}

void MDMA_voidDisableChannel(u8 Copy_u8ChannelNum)
{
	/* Disable Channel */
	CLR_BIT(DMA->Channel[Copy_u8ChannelNum].CCR , 0) ;
}


void MDMA_voidSetCallBack(u8 Copy_u8ChannelNum , void (*Copy_Ptr) (void) )
{
	/* Save Callback */
	DMA_Callback[Copy_u8ChannelNum] = Copy_Ptr ;
}

void MDMA_voidSetTCIState(u8 Copy_u8TCIState , u8 Copy_u8ChannelNum)
{
	/* Disable Channel before writing on registers */
	CLR_BIT(DMA->Channel[Copy_u8ChannelNum].CCR , 0) ;
	
	#if		Copy_u8TCIState == ENABLE
		SET_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 1 ) ;
	
	#elif	Copy_u8TCIState == DISABLE
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 1 ) ;
		
	#else
		#error("Wrong value")
	#endif
}


void MDMA_voidSetHTCIState(u8 Copy_u8HTCIState , u8 Copy_u8ChannelNum)
{
	/* Disable Channel before writing on registers */
	CLR_BIT(DMA->Channel[Copy_u8ChannelNum].CCR , 0) ;
	
	#if		Copy_u8HTCIState == ENABLE
		SET_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 2 ) ;
	
	#elif	Copy_u8HTCIState == DISABLE
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 2 ) ;
		
	#else
		#error("Wrong value")
	#endif
}


void MDMA_voidSetTEIState(u8 Copy_u8TEIState , u8 Copy_u8ChannelNum)
{
	/* Disable Channel before writing on registers */
	CLR_BIT(DMA->Channel[Copy_u8ChannelNum].CCR , 0) ;
	
	#if		Copy_u8TEIState == ENABLE
		SET_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 3 ) ;
	
	#elif	Copy_u8TEIState == DISABLE
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 3 ) ;
		
	#else
		#error("Wrong value")
	#endif
}


void MDMA_voidSetDataTransferDirection(u8 Copy_u8Direction , u8 Copy_u8ChannelNum)
{
	/* Disable Channel before writing on registers */
	CLR_BIT(DMA->Channel[Copy_u8ChannelNum].CCR , 0) ;
	
	#if		Copy_u8Direction == MEMORY_TO_MEMORY
		SET_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 4 ) ;
	
	#elif	Copy_u8Direction == PERIPHERAL_TO_MEMORY
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 4 ) ;
		
	#else
		#error("Wrong value")
	#endif
}


void MDMA_voidSetCircularModeState(u8 Copy_u8CircModeState , u8 Copy_u8ChannelNum)
{
	/* Disable Channel before writing on registers */
	CLR_BIT(DMA->Channel[Copy_u8ChannelNum].CCR , 0) ;
	
	#if		Copy_u8CircModeState == ENABLE
		SET_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 5 ) ;
	
	#elif	Copy_u8CircModeState == DISABLE
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 5 ) ;
		
	#else
		#error("Wrong value")
	#endif
}


void MDMA_voidSetPeripheralIncState(u8 Copy_u8PINCState , u8 Copy_u8ChannelNum)
{
	/* Disable Channel before writing on registers */
	CLR_BIT(DMA->Channel[Copy_u8ChannelNum].CCR , 0) ;
	
	#if		Copy_u8PINCState == ENABLE
		SET_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 6 ) ;
	
	#elif	Copy_u8PINCState == DISABLE
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 6 ) ;
		
	#else
		#error("Wrong value")
	#endif 
}


void MDMA_voidSetMemoryIncState(u8 Copy_u8MINCState , u8 Copy_u8ChannelNum)
{
	/* Disable Channel before writing on registers */
	CLR_BIT(DMA->Channel[Copy_u8ChannelNum].CCR , 0) ;
	
	#if		Copy_u8MINCState == ENABLE
		SET_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 7 ) ;
	
	#elif	Copy_u8MINCState == DISABLE
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 7 ) ;
		
	#else
		#error("Wrong value")
	#endif
}


void MDMA_voidSetSrcDataSize(u8 Copy_u8SrcDataSize , u8 Copy_u8ChannelNum)
{
	/* Disable Channel before writing on registers */
	CLR_BIT(DMA->Channel[Copy_u8ChannelNum].CCR , 0) ;
	
	#if		Copy_u8HTCIState == BITS_8
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 8 ) ;
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 9 ) ;
	
	#elif	Copy_u8HTCIState == BITS_16
		SET_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 8 ) ;
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 9 ) ;
		
	#elif	Copy_u8HTCIState == BITS_32
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 8 ) ;
		SET_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 9 ) ;
		
	#else
		#error("Wrong value")
	#endif
}


void MDMA_voidSetDestDataSize(u8 Copy_u8DestDataSize , u8 Copy_u8ChannelNum)
{
	/* Disable Channel before writing on registers */
	CLR_BIT(DMA->Channel[Copy_u8ChannelNum].CCR , 0) ;
	
	#if		Copy_u8HTCIState == BITS_8
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 10 ) ;
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 11 ) ;
	
	#elif	Copy_u8HTCIState == BITS_16
		SET_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 10 ) ;
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 11 ) ;
		
	#elif	Copy_u8HTCIState == BITS_32
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 10 ) ;
		SET_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 11 ) ;
		
	#else
		#error("Wrong value")
	#endif
}


void MDMA_voidSetChannelPriority(u8 Copy_u8ChPriority , u8 Copy_u8ChannelNum)
{
	/* Disable Channel before writing on registers */
	CLR_BIT(DMA->Channel[Copy_u8ChannelNum].CCR , 0) ;
	
	#if		Copy_u8HTCIState == LOW_PRIORITY
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 12 ) ;
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 13 ) ;								
		
	#elif	Copy_u8HTCIState == MEDIUM_PRIORITY                                             		
		SET_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 12 ) ;                               
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 13 ) ;
		
	#elif	Copy_u8HTCIState == HIGH_PRIORITY
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 12 ) ;
		SET_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 13 ) ;
		
	#elif	Copy_u8HTCIState == VERY_HIGH_PRIORITY
		SET_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 12 ) ;
		SET_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 13 ) ;
		
	#else
		#error("Wrong value")
	#endif
}


void MDMA_voidSetMemToMemModeState(u8 Copy_u8ModeState , u8 Copy_u8ChannelNum)
{
	/* Disable Channel before writing on registers */
	CLR_BIT(DMA->Channel[Copy_u8ChannelNum].CCR , 0) ;
	
	#if		Copy_u8ModeState == ENABLE
		SET_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 14 ) ;
	
	#elif	Copy_u8ModeState == DISABLE
		CLR_BIT( DMA->Channel[Copy_u8ChannelNum].CCR , 14 ) ;
		
	#else
		#error("Wrong value")
	#endif 
}


void DMA1_Channel1_IRQHandler(void)
{
	/* Clear Interrupt flags (CTEIF1,CHTIF1,CTCIF1,CGIF1) */
	DMA->IFCR = ((0XF) << 0);
	/* Execute the callback funtion */
	DMA_Callback[CH1]() ;
}


void DMA1_Channel2_IRQHandler(void)
{
	/* Clear Interrupt flags (CTEIF2,CHTIF2,CTCIF2,CGIF2) */
	DMA->IFCR = ((0XF) << 4);
	/* Execute the callback funtion */
	DMA_Callback[CH2]() ;
}

void DMA1_Channel3_IRQHandler(void)
{
	/* Clear Interrupt flags (CTEIF3,CHTIF3,CTCIF3,CGIF3) */
	DMA->IFCR = ((0XF) << 8);
	/* Execute the callback funtion */
	DMA_Callback[CH3]() ;
}


void DMA1_Channel4_IRQHandler(void)
{
	/* Clear Interrupt flags (CTEIF4,CHTIF4,CTCIF4,CGIF4) */
	DMA->IFCR = ((0XF) << 12);
	/* Execute the callback funtion */
	DMA_Callback[CH4]() ;
}


void DMA1_Channel5_IRQHandler(void)
{
	/* Clear Interrupt flags (CTEIF5,CHTIF5,CTCIF5,CGIF5) */
	DMA->IFCR = ((0XF) << 16);
	/* Execute the callback funtion */
	DMA_Callback[CH5]() ;
}


void DMA1_Channel6_IRQHandler(void)
{
	/* Clear Interrupt flags (CTEIF6,CHTIF6,CTCIF6,CGIF6) */
	DMA->IFCR = ((0XF) << 20);
	/* Execute the callback funtion */
	DMA_Callback[CH6]() ;
}


void DMA1_Channel7_IRQHandler(void)
{
	/* Clear Interrupt flags (CTEIF7,CHTIF7,CTCIF7,CGIF7) */
	DMA->IFCR = ((0XF) << 24);
	/* Execute the callback funtion */
	DMA_Callback[CH7]() ;
}




