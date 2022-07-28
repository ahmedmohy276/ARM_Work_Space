/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  4 January 2022             */
/* Version :  V01                        */
/*****************************************/



#ifndef		SPI_INTERFACE_H
#define  	SPI_INTERFACE_H



#define 	DATA_BIT_8				0				
#define 	DATA_BIT_16				1

#define 	MSB_FIRST				0				
#define 	LSB_FIRST				1

#define 	PRESCALER_2				0				
#define 	PRESCALER_4				1				
#define 	PRESCALER_8				2				
#define 	PRESCALER_16			3					
#define 	PRESCALER_32			4					
#define 	PRESCALER_64			5					
#define 	PRESCALER_128			6					
#define 	PRESCALER_256			7

#define 	SLAVE_MODE				0
#define 	MASTER_MODE				1				

#define 	CLK_IDLE_LOW			0					
#define 	CLK_IDLE_HIGH			1

#define 	WRITING_READING			1
#define 	READING_WRITING			0

#define 	ENABLE					1			
#define 	DISABLE					0

#define		HIGH					1
#define		LOW 					0
	

/******************************* SPI1 functions ***************************************/

void MSPI1_voidInit(void) ;

void MSPI1_voidSendReceiveSynch( u8 Copy_u8SendData , u8 *Copy_pu8RecData ) ;

void MSPI1_voidSendReceiveAsynch( u8 Copy_u8SendData , void (*Func_Ptr) (u8) ) ;



/******************************* SPI2 functions ***************************************/

void MSPI2_voidInit(void) ;

void MSPI2_voidSendReceiveSynch( u8 Copy_u8SendData , u8 *Copy_pu8RecData ) ;

void MSPI2_voidSendReceiveAsynch( u8 Copy_u8SendData , void (*Func_Ptr) (u8) ) ;






#endif
