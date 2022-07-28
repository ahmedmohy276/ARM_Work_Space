/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  13 March 2022              */
/* Version :  V01                        */
/*****************************************/

#ifndef		I2C_PRIVATE_H
#define		I2C_PRIVATE_H

#define 	I2C1_BASE_ADDRESS			(0X40005400)

typedef struct{
	volatile u32 CR1 , CR2 , OAR1 , OAR2 , DR , SR1 , SR2 , CCR , TRISE ;
}I2C1_Registers;


#define		I2C1_REG					((volatile I2C1_Registers*)I2C1_BASE_ADDRESS)


#endif
