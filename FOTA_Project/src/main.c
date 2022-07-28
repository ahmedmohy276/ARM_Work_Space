/*
 * main.c
 *
 *  Created on: Jan 20, 2022
 *      Author: ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"
#include "FPEC_interface.h"
#include "USART_interface.h"
#include "I2C_interface.h"
#include "ESP_interface.h"

#define PAGE_NUMBER    1
#define BYTE_NUMBER    1

u8 RecData[15000] ;
volatile u8 u8TimeoutFlag = 0 ;
u8 EEPROM_Flag = 0 ;
u8 EEPROM_Address = 80 ;
u16 Byte_Adress = (5 << PAGE_NUMBER) | (BYTE_NUMBER) ;
typedef void (*Function_t)(void) ;
Function_t add_to_call = 0 ;


void JumpToApplication(void)
{
	MSTK_voidSetBusyWait(10000);
	EEPROM_Flag = MI2C1_voidRequestMemoryRead(EEPROM_Address , Byte_Adress) ;
	volatile u32 Data = *(u32*)(0x08002404) ;
	u8TimeoutFlag = 1 ;
	#define SCB_VTOR			*((volatile u32*)0XE000ED08)
	if ( (Data != 0XFFFFFFFF) && (EEPROM_Flag == 1) )
	{
		SCB_VTOR = 0X08000000 ;
		add_to_call = *(Function_t*)(0x08002404) ;
		add_to_call() ;
	}
}

int main(void)
{
	MRCC_voidInitSysClock();						/* HSI clock */
	MRCC_voidEnableClock(RCC_APB1 , I2C1EN) ;		/* I2C1 Enable clock */
	MRCC_voidEnableClock(RCC_APB2 , USART1EN) ;		/* USART1 */
	MRCC_voidEnableClock(RCC_APB2 , IOPAEN) ;		/* GPIOA */
	MRCC_voidEnableClock(RCC_APB2 , IOPBEN) ;		/* GPIOB */
	MRCC_voidEnableClock(RCC_AHB , FLITFEN) ;		/* FPEC */
	/* Set TX=PINA9 as Output alternate function push pull max speed 50 MHz  */
	MGPIO_voidSetPinDirection(PORTA , PIN9 , GPIO_OUTPUT_SPEED_50MHZ_AFPP);
	/* Set RX=PINA10 as input floating */
	MGPIO_voidSetPinDirection(PORTA , PIN10 , GPIO_FLOATING_INPUT);
	MGPIO_voidSetPinDirection(PORTA , PIN0 , GPIO_OUTPUT_SPEED_2MHZ_PP);

	/* Set direction of pins SCL1-->PINB6 and SDA1-->PINB7 as GPIO_OUTPUT_SPEED_50MHZ_AFOD */
	MGPIO_voidSetPinDirection(PORTB ,PIN6 , GPIO_OUTPUT_SPEED_50MHZ_AFOD) ;
	MGPIO_voidSetPinDirection(PORTB ,PIN7 , GPIO_OUTPUT_SPEED_50MHZ_AFOD) ;

	u8 flag ;
	MSTK_voidInit() ;
	MUSART1_voidInit() ;
	MI2C1_voidInit() ;
	MSTK_voidSetBusyWait(1000000) ;
	EEPROM_Flag = MI2C1_voidRequestMemoryRead(EEPROM_Address , Byte_Adress) ;
	HESP_voidInit() ;
	HESP_voidWiFiConnect();
	//MSTK_voidSetIntervalSingle(16000000,Func) ;

	while(u8TimeoutFlag == 0)
	{
		flag = HESP_u8GetFlag();
		if (flag == 1)
		{
			HESP_u16GetHexFile() ;
			Flashing() ;
		}
		else
		{
			// do nothing
		}
		JumpToApplication() ;
	}

	return 0 ;
}
