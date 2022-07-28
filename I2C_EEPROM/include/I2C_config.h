/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  13 March 2022              */
/* Version :  V01                        */
/*****************************************/

#ifndef		I2C_CONFIG_H
#define		I2C_CONFIG_H


#define		I2C_CLOCK					(8) //8MHZ
#define		I2C_NODE_ADDRESS			(0X00)

#define		I2C_SCL						(100000)


#define WRITEMODE                       (0X00)
#define READMODE						(0X01)


/* Selections :	ENABLE
				DISABLE   */
#define		I2C_ACK						ENABLE

/* Selections :	ENABLE
				DISABLE   */
#define		I2C_NO_STRETCHING			ENABLE

/* Selections :	ADDRESS_7BIT
				ADDRESS_10BIT   */
#define		I2C_ADDRESSING_MODE			ADDRESS_7BIT	

/* Selections :	ENABLE
				DISABLE   */
#define		I2C_DUAL_ADDRESSING			DISABLE	

/* Selections :	STANDARD_MODE
				FAST_MODE   */
#define		I2C_MASTER_MODE				STANDARD_MODE

/* Selections :	FM_DUTY_2
				FM_DUTY_16_9   */
#define		I2C_FM_DUTY_MODE			FM_DUTY_2





#endif
