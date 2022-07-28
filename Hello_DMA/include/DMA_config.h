/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  3 January 2022             */
/* Version :  V01                        */
/*****************************************/


#ifndef		DMA_CONFIG_H
#define 	DMA_CONFIG_H

/* Options : CH1 --> CH7 */
#define		CHANNEL_NUM					CH1

/* Options : LOW_PRIORITY
			 MEDIUM_PRIORITY
			 HIGH_PRIORITY
			 VERY_HIGH_PRIORITY
			 */
#define		CHANNEL_PRIORITY			VERY_HIGH_PRIORITY

/* Options : 8_BITS
			 16_BITS
			 32_BITS
			 */
#define		SOURCE_SIZE 				BITS_32
#define		DESTINATION_SIZE 			BITS_32

/* Options : PERIPHERAL_TO_MEMORY
			 MEMORY_TO_MEMORY
			 */
#define		DATA_TRANSFER_DIRECTION		PERIPHERAL_TO_MEMORY

/* Options : ENABLE
			 DISABLE
			 */
#define		TRANSFER_INT				ENABLE
#define		HALF_TRANSFER_INT			DISABLE
#define		TRANSFER_ER_INT				DISABLE

#define		MINC						ENABLE
#define		PINC						ENABLE

#define		CIRCULAR_MODE				DISABLE

#define		MEMORY_TO_MEMORY_MODE		ENABLE
	

#endif
