/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  3 January 2022             */
/* Version :  V01                        */
/*****************************************/


#ifndef		DMA_INTERFACE_H
#define 	DMA_INTERFACE_H


#define		PERIPHERAL_TO_MEMORY		0
#define		MEMORY_TO_MEMORY			1

#define		BITS_8						0
#define		BITS_16						1
#define		BITS_32						2

#define		CH1							0
#define		CH2							1
#define		CH3							2
#define		CH4							3
#define		CH5							4
#define		CH6 						5
#define		CH7							6

#define		LOW_PRIORITY				0
#define		MEDIUM_PRIORITY				1
#define		HIGH_PRIORITY				2
#define		VERY_HIGH_PRIORITY			3

#define		ENABLE 						1
#define		DISABLE						0



void MDMA_voidInitChannel(void) ;

void MDMA_voidStartChannel(u32 *Copy_pu32SrcAddress , u32 *Copy_pu32DestAddress , u16 Copy_u16BlockLength , u8 Copy_u8ChannelNum);

void MDMA_voidSetChannelConfig( u8 Copy_u8ChannelNum , u8 Copy_u8TCIState , u8 Copy_u8HTCIState , u8 Copy_u8TEIState ,
							   u8 Copy_u8Direction , u8 Copy_u8CircModeState , u8 Copy_u8PINCState , u8 Copy_u8MINCState ,
							   u8 Copy_u8SrcDataSize , u8 Copy_u8DestDataSize , u8 Copy_u8ChPriority , u8 Copy_u8ModeState );

void MDMA_voidEnableChannel(u8 Copy_u8ChannelNum);

void MDMA_voidDisableChannel(u8 Copy_u8ChannelNum);

void MDMA_voidSetCallBack(u8 Copy_u8ChannelNum , void (*Copy_Ptr) (void) );

void MDMA_voidSetTCIState(u8 Copy_u8TCIState , u8 Copy_u8ChannelNum);

void MDMA_voidSetHTCIState(u8 Copy_u8HTCIState , u8 Copy_u8ChannelNum);

void MDMA_voidSetTEIState(u8 Copy_u8TEIState , u8 Copy_u8ChannelNum);

void MDMA_voidSetDataTransferDirection(u8 Copy_u8Direction , u8 Copy_u8ChannelNum);

void MDMA_voidSetCircularModeState(u8 Copy_u8CircModeState , u8 Copy_u8ChannelNum);

void MDMA_voidSetPeripheralIncState(u8 Copy_u8PINCState , u8 Copy_u8ChannelNum);

void MDMA_voidSetMemoryIncState(u8 Copy_u8MINCState , u8 Copy_u8ChannelNum);

void MDMA_voidSetSrcDataSize(u8 Copy_u8SrcDataSize , u8 Copy_u8ChannelNum);

void MDMA_voidSetDestDataSize(u8 Copy_u8DestDataSize , u8 Copy_u8ChannelNum);

void MDMA_voidSetChannelPriority(u8 Copy_u8ChPriority , u8 Copy_u8ChannelNum);

void MDMA_voidSetMemToMemModeState(u8 Copy_u8ModeState , u8 Copy_u8ChannelNum);







#endif
