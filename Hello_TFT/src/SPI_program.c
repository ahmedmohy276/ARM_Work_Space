/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  4 January 2022             */
/* Version :  V01                        */
/*****************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"




/******************************* SPI1 functions ***************************************/

void MSPI1_voidInit(void) 
{
	/* clear register */
	SPI1->CR1 = 0 ;
	
	/* Set SPI1 cofiguration */
	SPI1->CR1 |= ( (SPI1_CLOCK_PHASE << 0) | (SPI1_CLOCK_POLARITY << 1) | (SPI1_MODE << 2) | (SPI1_PRESCALER << 3) | 
				 (SPI1_FRAME_FORMAT << 7) | (SPI1_INTERNAL_SLAVE_SELECT << 8) | (SPI1_SW_SLAVE_MANAGEMENT << 9) | 
				 (SPI1_DATA_FRAME << 11) ) ;
				  
	/* clear register */
	SPI1->CR2 = 0 ;
	
	SPI1->CR2 |= ( (SPI1_TX_BUFFER_EMPTY_INTERRUPT << 7) | (SPI1_RX_BUFFER_NOT_EMPTY_INTERRUPT << 6) | (SPI1_ERROR_INTERRUPT << 5) ) ;
	
	/* Enable SPI1 */
	SET_BIT(SPI1->CR1 , 6) ;

}


void MSPI1_voidSendReceiveSynch( u8 Copy_u8SendData , u8 *Copy_pu8RecData ) 
{
	/* Enable Slave Select */
	MGPIO_voidSetPinValue(SPI1_SLAVE_SELECT_PIN , GPIO_LOW) ;
	
	/* Write data to SPI Data register */
	SPI1->DR = Copy_u8SendData ;
	
	/* Wait till data to be transmitted */
	while(GET_BIT(SPI1->SR , 7) == 1) ;
	
	/* Return received data */
	*Copy_pu8RecData = SPI1->DR ;
	
	/* Disable Slave Select */
	MGPIO_voidSetPinValue(SPI1_SLAVE_SELECT_PIN , GPIO_HIGH) ;
	
}


void MSPI1_voidSendReceiveAsynch( u8 Copy_u8SendData , void (*Func_Ptr) (u8) ) 
{
	/* Enable Slave Select */
	MGPIO_voidSetPinValue(SPI1_SLAVE_SELECT_PIN , GPIO_LOW) ;
	
	/* Save Callback */
	SPI1_Callback = Func_Ptr ;
	
	/* Write data to SPI Data register */
	SPI1->DR = Copy_u8SendData ;
}


/* SPI1 ISR function */
void SPI1_IRQHandler(void)
{
	/* Return received data to callback function */
	SPI1_Callback(SPI1->DR) ;
}

/******************************* SPI2 functions ***************************************/

void MSPI2_voidInit(void) 
{
	/* clear register */
	SPI2->CR1 = 0 ;
	
	/* Set SPI1 cofiguration */
	SPI2->CR1 |= ( (SPI2_CLOCK_PHASE << 0) | (SPI2_CLOCK_POLARITY << 1) | (SPI2_MODE << 2) | (SPI2_PRESCALER << 3) | 
				 (SPI2_FRAME_FORMAT << 7) | (SPI2_SW_SLAVE_MANAGEMENT << 9) | (SPI2_DATA_FRAME << 11) ) ;
				  
	/* clear register */
	SPI2->CR2 = 0 ;
	
	SPI2->CR1 |= ( (SPI2_TX_BUFFER_EMPTY_INTERRUPT << 7) | (SPI2_RX_BUFFER_NOT_EMPTY_INTERRUPT << 6) | (SPI2_ERROR_INTERRUPT << 5) ) ;
	
	/* Enable SPI1 */
	SET_BIT(SPI2->CR1 , 6) ;
}


void MSPI2_voidSendReceiveSynch( u8 Copy_u8SendData , u8 *Copy_pu8RecData ) 
{
	/* Enable Slave Select */
	MGPIO_voidSetPinValue(SPI2_SLAVE_SELECT_PIN , GPIO_LOW) ;
	
	/* Write data to SPI Data register */
	SPI2->DR = Copy_u8SendData ;
	
	/* Wait till data to be transmitted */
	while(GET_BIT(SPI2->SR , 7) == 1) ;
	
	/* Return received data */
	*Copy_pu8RecData = SPI2->DR ;
	
	/* Disable Slave Select */
	MGPIO_voidSetPinValue(SPI2_SLAVE_SELECT_PIN , GPIO_HIGH) ;
	
}


void MSPI2_voidSendReceiveAsynch( u8 Copy_u8SendData , void (*Func_Ptr) (u8) ) 
{
	/* Enable Slave Select */
	MGPIO_voidSetPinValue(SPI2_SLAVE_SELECT_PIN , GPIO_LOW) ;
	
	/* Save Callback */
	SPI2_Callback = Func_Ptr ;
	
	/* Write data to SPI Data register */
	SPI2->DR = Copy_u8SendData ;
}


/* SPI2 ISR function */
void SPI2_IRQHandler(void)
{
	/* Return received data to callback function */
	SPI2_Callback(SPI2->DR) ;
}
