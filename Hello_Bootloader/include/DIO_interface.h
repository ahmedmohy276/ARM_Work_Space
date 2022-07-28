/****************************************************************/
/*	Author   : Ahmed Mohy									   	*/
/*	Date     : 25 DEC 2021										*/
/*	Version  : V01												*/
/****************************************************************/


#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


#define 	GPIO_LOW						0
#define 	GPIO_HIGH						1

#define 	GPIO_PULL_DOWN					0
#define 	GPIO_PULL_UP					1


#define		PORTA							0
#define		PORTB							1
#define		PORTC							2



#define		PIN0							0	
#define		PIN1							1
#define		PIN2							2 
#define		PIN3							3
#define		PIN4							4
#define		PIN5							5
#define		PIN6							6
#define		PIN7							7
#define		PIN8							8
#define		PIN9							9
#define		PIN10							10
#define		PIN11							11
#define		PIN12							12
#define		PIN13							13
#define		PIN14							14
#define		PIN15							15



/*************************   DIO Modes 	 ***********************/

#define GPIO_OUTPUT_SPEED_10MHZ_PP			0X1			// 10MHZ Push-Pull
#define GPIO_OUTPUT_SPEED_10MHZ_OD			0X5			// 10MHZ Open-Drain with max speed
#define GPIO_OUTPUT_SPEED_10MHZ_AFPP		0X9			// 10MHZ Alternate function output Push-pull
#define GPIO_OUTPUT_SPEED_10MHZ_AFOD		0XD			// 10MHZ Alternate function output Open-drain

#define GPIO_OUTPUT_SPEED_2MHZ_PP			0X2			// 2MHZ Push-Pull
#define GPIO_OUTPUT_SPEED_2MHZ_OD			0X6			// 2MHZ Open-Drain with max speed
#define GPIO_OUTPUT_SPEED_2MHZ_AFPP			0XA			// 2MHZ Alternate function output Push-pull
#define GPIO_OUTPUT_SPEED_2MHZ_AFOD			0XE			// 2MHZ Alternate function output Open-drain

#define GPIO_OUTPUT_SPEED_50MHZ_PP			0X3			// 50MHZ Push-Pull
#define GPIO_OUTPUT_SPEED_50MHZ_OD			0X7			// 50MHZ Open-Drain with max speed
#define GPIO_OUTPUT_SPEED_50MHZ_AFPP		0XB			// 50MHZ Alternate function output Push-pull
#define GPIO_OUTPUT_SPEED_50MHZ_AFOD		0XF			// 50MHZ Alternate function output Open-drain

#define GPIO_ANALOG_INPUT					0X0
#define GPIO_FLOATING_INPUT					0X4
#define GPIO_INPUT_PULL_UP_DOWN				0X8


/* function to set pin GPIO mode and configuration */
void MGPIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode);

/* function to set pin GPIO value to high or low */
void MGPIO_voidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);

/* function to set pin GPIO value to high */
void MGPIO_voidSetPin(u8 Copy_u8Port , u8 Copy_u8Pin);

/* function to set pin GPIO value to Low */
void MGPIO_voidClearPin(u8 Copy_u8Port , u8 Copy_u8Pin);

/* function to read and return pin GPIO value */
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin);


/* function to set port GPIO mode and configuration */
void MGPIO_voidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Mode);

/* function to set port GPIO value */
void MGPIO_voidSetPortValue(u8 Copy_u8Port,u16 Copy_u16Val);

/* function to read and return port GPIO value */
u16 MGPIO_u16GetPortValue(u8 Copy_u8Port);


/* function to lock pin configuration */
void MGPIO_voidLockPin(u8 Copy_u8Port , u8 Copy_u8Pin);

/* function to unlock pin configuration */
void MGPIO_voidUnlockPin(u8 Copy_u8Port , u8 Copy_u8Pin);

/* function to set pull up or down resistor to pin */
void MGPIO_voidSetPullResistor(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PullType);






#endif
