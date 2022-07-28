/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  3 January 2022             */
/* Version :  V01                        */
/*****************************************/


#ifndef		DMA_PRIVATE_H
#define 	DMA_PRIVATE_H

#define		NULL							((void*)0)

#define		DMA_BASE_ADDRESS				(0X40020000)

typedef struct 
{
	volatile u32 CCR , CNDTR , CPAR , CMAR , Reserved ;
}DMA_CH;

typedef struct 
{
	volatile u32 ISR , IFCR ;
	DMA_CH	Channel[7] ;
}DMA_t;


#define		DMA							((volatile DMA_t*)DMA_BASE_ADDRESS)

/* Array of pinters to function for DMA Channels callback */
void (*DMA_Callback[7]) (void) = {NULL} ;


#endif