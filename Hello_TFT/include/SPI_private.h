/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  4 January 2022             */
/* Version :  V01                        */
/*****************************************/



#ifndef		SPI_PRIVATE_H
#define  	SPI_PRIVATE_H

#define		NULL							((void*)0)

#define		SPI1_BASE_ADDRESS				0X40013000
#define		SPI2_BASE_ADDRESS				0X40003800




typedef	struct
{
	volatile u32 CR1,CR2,SR,DR,CRCPR,RXCRCR,TXCRCR,I2SCFGR,I2SPR ;
}SPI1_Registers;


typedef	struct
{
	volatile u32 CR1,CR2,SR,DR,CRCPR,RXCRCR,TXCRCR,I2SCFGR,I2SPR ;
}SPI2_Registers;


#define		SPI1				((volatile SPI1_Registers*)SPI1_BASE_ADDRESS)
#define		SPI2				((volatile SPI2_Registers*)SPI2_BASE_ADDRESS)

/* SPI1 and SPI2 callback pionters */
void (*SPI1_Callback) (u8) = NULL ;
void (*SPI2_Callback) (u8) = NULL ;



#endif