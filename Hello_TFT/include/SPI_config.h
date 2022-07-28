/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  4 January 2022             */
/* Version :  V01                        */
/*****************************************/



#ifndef		SPI_CONFIG_H
#define  	SPI_CONFIG_H

/********************************** SPI1 Configuration ********************************/ 

/* Write it in a pair port,pin */
#define		SPI1_SLAVE_SELECT_PIN			PORTA,0

/* Options : DATA_BIT_8
			 DATA_BIT_16
			 */
#define		SPI1_DATA_FRAME					DATA_BIT_8


/* Options : MSB_FIRST
			 LSB_FIRST
			 */
#define		SPI1_FRAME_FORMAT				MSB_FIRST

/* Options : PRESCALER_2
			 PRESCALER_4
			 PRESCALER_8
			 PRESCALER_16
			 PRESCALER_32
			 PRESCALER_64
			 PRESCALER_128
			 PRESCALER_256
			 */
#define		SPI1_PRESCALER					PRESCALER_2

/* Options : MASTER_MODE
			 SLAVE_MODE
			 */
#define		SPI1_MODE						MASTER_MODE

/* Options : CLK_IDLE_LOW
			 CLK_IDLE_HIGH
			 */
#define		SPI1_CLOCK_POLARITY				CLK_IDLE_HIGH

/* Options : WRITING_READING
			 READING_WRITING
			 */		
#define		SPI1_CLOCK_PHASE				WRITING_READING	

/*oPTIONS : ENABLE
			DISABLE 
			*/
#define		SPI1_SW_SLAVE_MANAGEMENT				ENABLE

/*oPTIONS : HIGH
			LOW 
			*/
#define		SPI1_INTERNAL_SLAVE_SELECT  			HIGH

#define		SPI1_TX_BUFFER_EMPTY_INTERRUPT			DISABLE
#define		SPI1_RX_BUFFER_NOT_EMPTY_INTERRUPT		DISABLE
#define		SPI1_ERROR_INTERRUPT					DISABLE

/********************************** SPI2 Configuration ********************************/ 

/* Write it in a pair port,pin */
#define		SPI2_SLAVE_SELECT_PIN			PORTA,1

/* Options : DATA_BIT_8
			 DATA_BIT_16
			 */
#define		SPI2_DATA_FRAME					DATA_BIT_8


/* Options : MSB_FIRST
			 LSB_FIRST
			 */
#define		SPI2_FRAME_FORMAT				LSB_FIRST

/* Options : PRESCALER_2
			 PRESCALER_4
			 PRESCALER_8
			 PRESCALER_16
			 PRESCALER_32
			 PRESCALER_64
			 PRESCALER_128
			 PRESCALER_256
			 */
#define		SPI2_PRESCALER					PRESCALER_64

/* Options : MASTER_MODE
			 SLAVE_MODE
			 */
#define		SPI2_MODE						MASTER_MODE

/* Options : CLK_IDLE_LOW
			 CLK_IDLE_HIGH
			 */
#define		SPI2_CLOCK_POLARITY				CLK_IDLE_LOW

/* Options : WRITING_READING
			 READING_WRITING
			 */		
#define		SPI2_CLOCK_PHASE				WRITING_READING	

/*oPTIONS : ENABLE
			DISABLE 
			*/

#define		SPI2_SW_SLAVE_MANAGEMENT				ENABLE

#define		SPI2_TX_BUFFER_EMPTY_INTERRUPT			DISABLE
#define		SPI2_RX_BUFFER_NOT_EMPTY_INTERRUPT		DISABLE
#define		SPI2_ERROR_INTERRUPT					DISABLE


#endif