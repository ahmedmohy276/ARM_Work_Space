/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  13 March 2022              */
/* Version :  V01                        */
/*****************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"

#define UNUSED(X) (void)X      /* To avoid gcc/g++ warnings */

static void I2C_voidSendStartCond(void)
{
	/* send start condition */
	SET_BIT(I2C1_REG->CR1 , 8) ;
	/* wait till SB flag is set */
	while(GET_BIT(I2C1_REG->SR1 , 0) == 0) ;
}

static void I2C_voidSendStopCond(void)
{
	/* send stop condition */
	SET_BIT(I2C1_REG->CR1 , 9) ;
}

static void I2C_voidSendSlaveAddress(u8 Copy_u8SlaveAddress)
{
	u16 Local_u16Temp = 0 ;
	I2C1_REG->DR = Copy_u8SlaveAddress ;
	/* wait till ADDR Flag is set */
	while(GET_BIT(I2C1_REG->SR1 , 1) == 0) ;
	/* Clear ADDR flag */
	Local_u16Temp = I2C1_REG->SR1 ;
	Local_u16Temp = I2C1_REG->SR2 ;
	UNUSED(Local_u16Temp) ;
	/* wait till TXE Flag is set */
	//while(GET_BIT(I2C1_REG->SR1 , 7) == 0) ;
}

static void I2C_voidWriteData(u8 Copy_u8Data)
{
	while(GET_BIT(I2C1_REG->SR1 , 7) == 0) ;
	/* send data */
	I2C1_REG->DR = Copy_u8Data ;
	/* wait till TXE Flag is set */
	while(GET_BIT(I2C1_REG->SR1 , 7) == 0) ;
}

static u8 I2C_u8ReadData(void)
{
	/* wait till data is received */
	while(GET_BIT(I2C1_REG->SR1 , 6) == 0) ;
	/* read receive data */
	u8 Local_u8RecData = I2C1_REG->DR ;
	
	return Local_u8RecData ;
}



void MI2C1_voidInit(void) 
{

	u16 CLK_Control = 0 ;

	I2C1_REG->CR1 = 0 ;
	I2C1_REG->CR1 |= (1<<15);  // reset the I2C
	I2C1_REG->CR1 &= ~(1<<15);  // Normal operation
	I2C1_REG->CR1 |= ( (I2C_ACK << 10) | (I2C_NO_STRETCHING << 7 ) );
	
	I2C1_REG->CR2 = 0 ;
	I2C1_REG->CR2 |= ((u8)I2C_CLOCK) ;
	
	I2C1_REG->OAR1 = 0 ;
	I2C1_REG->OAR1 |= ( (I2C_ADDRESSING_MODE << 15) | (1 << 14) | (I2C_NODE_ADDRESS << 1) ) ;
	SET_BIT(I2C1_REG->OAR1 , 14) ;
	
	I2C1_REG->OAR2 = 0 ;
	I2C1_REG->OAR2 |= (I2C_DUAL_ADDRESSING) ;
	
	I2C1_REG->CCR = 0 ;
	#if			I2C_MASTER_MODE == STANDARD_MODE
		CLK_Control = ( ( (u64)(I2C_CLOCK*1000000) )/( (u64)(2*I2C_SCL) ) ) ;
	
	#elif		I2C_MASTER_MODE == FAST_MODE
		
		#if 		I2C_FM_DUTY_MODE == FM_DUTY_2
			CLK_Control = ( ( (u64)(I2C_CLOCK*1000000) )/( (u64)(3*I2C_SCL) ) ) ;
		
		#elif 		I2C_FM_DUTY_MODE == FM_DUTY_16_9
			CLK_Control = ( ( (u64)(I2C_CLOCK*1000000) )/( (u64)(25*I2C_SCL) ) ) ;
		
		#else
			#error("you entered non valid value")
		
		#endif
	
	#else
		#error("you entered non valid value")
	#endif

	
	I2C1_REG->CCR |= ( (I2C_MASTER_MODE << 15) | (I2C_FM_DUTY_MODE << 14) | (CLK_Control) ) ;
	
	//I2C1_REG->TRISE = 0 ;
	I2C1_REG->TRISE = 9 ;
	
	/* I2C Enable */
	SET_BIT(I2C1_REG->CR1 , 0) ;
	//I2C1_REG->CR1 |= (I2C_ACK << 10) ;
}


void MI2C1_voidRequestMemoryWrite(u8 Copy_u8SlaveAddress, u16 Copy_u16ByteAddress , u8 Copy_u8Data) 
{
	I2C1_REG->CR1 |= (I2C_ACK << 10) ;
	/* Generate Start */
	I2C_voidSendStartCond();
	
	/* Send slave address + write */
	I2C_voidSendSlaveAddress((Copy_u8SlaveAddress<<1) | (WRITEMODE));

	/* Check ACK */
	if (GET_BIT(I2C1_REG->SR1 , 10) == 1)
	{
		/* Generate Stop */
		I2C_voidSendStopCond();
		/* Clear ACK Failed(AF) flag */
		CLR_BIT(I2C1_REG->SR1 , 10) ;
		//return error ;
	}
	
	/* Send MSB Word address */
	I2C_voidWriteData((u8)(Copy_u16ByteAddress >> 8));

	/* Check ACK -- ACK Failed(AF) flag */
	if (GET_BIT(I2C1_REG->SR1 , 10) == 1)
	{
		/* Generate Stop */
		I2C_voidSendStopCond();
		/* Clear ACK Failed(AF) flag */
		CLR_BIT(I2C1_REG->SR1 , 10) ;
		//return error ;
	}
	
	/* Send LSB Word address */
	I2C_voidWriteData((u8)Copy_u16ByteAddress);

	/* Check ACK */
	if (GET_BIT(I2C1_REG->SR1 , 10) == 1)
	{
		/* Generate Stop */
		I2C_voidSendStopCond();
		/* Clear ACK Failed(AF) flag */
		CLR_BIT(I2C1_REG->SR1 , 10) ;
		//return error ;
	}
	
	/* Send Data to be stored in the byte address */
	I2C_voidWriteData((u8)Copy_u8Data);

	/* Check ACK */
	if (GET_BIT(I2C1_REG->SR1 , 10) == 1)
	{
		/* Generate Stop */
		I2C_voidSendStopCond();
		/* Clear ACK Failed(AF) flag */
		CLR_BIT(I2C1_REG->SR1 , 10) ;
		//return error ;
	}
	
	/* Generate Stop */
	I2C_voidSendStopCond();
}



u8 MI2C1_voidRequestMemoryRead(u8 Copy_u8SlaveAddress , u16 Copy_u16ByteAddress) 
{
	I2C1_REG->CR1 |= (I2C_ACK << 10) ;
	u8 RXData = 0 ;
	/* Generate Start */
	I2C_voidSendStartCond();
	
	/* Send slave address + write */
	I2C_voidSendSlaveAddress((Copy_u8SlaveAddress<<1) | (WRITEMODE));

	/* Check ACK */
	if (GET_BIT(I2C1_REG->SR1 , 10) == 1)
	{
		/* Generate Stop */
		I2C_voidSendStopCond();
		/* Clear ACK Failed(AF) flag */
		CLR_BIT(I2C1_REG->SR1 , 10) ;
		//return error ;
	}
	
	/* Send MSB Word address */
	I2C_voidWriteData((u8)(Copy_u16ByteAddress >> 8));

	/* Check ACK */
	if (GET_BIT(I2C1_REG->SR1 , 10) == 1)
	{
		/* Generate Stop */
		I2C_voidSendStopCond();
		/* Clear ACK Failed(AF) flag */
		CLR_BIT(I2C1_REG->SR1 , 10) ;
		//return error ;
	}
	
	/* Send LSB Word address */
	I2C_voidWriteData((u8)Copy_u16ByteAddress);

	/* Check ACK */
	if (GET_BIT(I2C1_REG->SR1 , 10) == 1)
	{
		/* Generate Stop */
		I2C_voidSendStopCond();
		/* Clear ACK Failed(AF) flag */
		CLR_BIT(I2C1_REG->SR1 , 10) ;
		//return error ;
	}
	
	/* Generate repeated Start */
	I2C_voidSendStartCond();
	
	/* Send slave address + read */
	I2C_voidSendSlaveAddress((Copy_u8SlaveAddress<<1) | (READMODE));

	/* Check ACK */
	if (GET_BIT(I2C1_REG->SR1 , 10) == 1)
	{
		/* Generate Stop */
		I2C_voidSendStopCond();
		/* Clear ACK Failed(AF) flag */
		CLR_BIT(I2C1_REG->SR1 , 10) ;
		//return error ;
	}
	
	//read received data 
	RXData=I2C_u8ReadData();
	
	/* Generate Stop */
	I2C_voidSendStopCond();
	
	return RXData;
}


