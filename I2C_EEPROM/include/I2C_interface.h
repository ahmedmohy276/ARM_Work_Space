/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  13 March 2022              */
/* Version :  V01                        */
/*****************************************/

#ifndef		I2C_INTERFACE_H
#define		I2C_INTERFACE_H

#define		ENABLE					1
#define		DISABLE					0

#define		ADDRESS_7BIT 			0
#define		ADDRESS_10BIT			1

#define		STANDARD_MODE			0
#define		FAST_MODE				1

#define		FM_DUTY_2				0
#define		FM_DUTY_16_9			1

void MI2C1_voidInit(void) ;

void MI2C1_voidRequestMemoryWrite(u8 Copy_u8SlaveAddress, u16 Copy_u16ByteAddress , u8 Copy_u8Data) ;

u8 MI2C1_voidRequestMemoryRead(u8 Copy_u8SlaveAddress , u16 Copy_u16ByteAddress) ;

#endif
