/****************************************************************/
/*	Author   : Ahmed Mohy									   	*/
/*	Date     : 25 DEC 2021										*/
/*	Version  : V01												*/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"



void MGPIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)
{
	switch (Copy_u8Port)
	{
		case PORTA :
			if (Copy_u8Pin <= 7)
			{
				GPIOA->CRL &= ~((0XF) << (Copy_u8Pin*4));			// Clear 4 bits mode of the pin
				GPIOA->CRL |= ((Copy_u8Mode) << (Copy_u8Pin*4));	// Set pin mode
			}
			
			else if (Copy_u8Pin <= 15)
			{
				Copy_u8Pin -= 8;
				GPIOA->CRH &= ~((0XF) << (Copy_u8Pin*4));			// Clear 4 bits mode of the pin
				GPIOA->CRH |= ((Copy_u8Mode) << (Copy_u8Pin*4));	// Set pin mode
			}
			break;
			
		case PORTB :
			if (Copy_u8Pin <= 7)
			{
				GPIOB->CRL &= ~((0XF) << (Copy_u8Pin*4));			// Clear 4 bits mode of the pin
				GPIOB->CRL |= ((Copy_u8Mode) << (Copy_u8Pin*4));	// Set pin mode
			}
			
			else if (Copy_u8Pin <= 15)
			{
				Copy_u8Pin -= 8;
				GPIOB->CRH &= ~((0XF) << (Copy_u8Pin*4));			// Clear 4 bits mode of the pin
				GPIOB->CRH |= ((Copy_u8Mode) << (Copy_u8Pin*4));	// Set pin mode
			}
			break;
		
		case PORTC :
			if (Copy_u8Pin <= 7)
			{
				GPIOC->CRL &= ~((0XF) << (Copy_u8Pin*4));			// Clear 4 bits mode of the pin
				GPIOC->CRL |= ((Copy_u8Mode) << (Copy_u8Pin*4));	// Set pin mode
			}
			
			else if (Copy_u8Pin <= 15)
			{
				Copy_u8Pin -= 8;
				GPIOC->CRH &= ~((0XF) << (Copy_u8Pin*4));			// Clear 4 bits mode of the pin
				GPIOC->CRH |= ((Copy_u8Mode) << (Copy_u8Pin*4));	// Set pin mode
			}
			break;
			
		default : 		break;
	}
}


void MGPIO_voidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	switch (Copy_u8Port)
		{
			case PORTA :
				if (Copy_u8Value == GPIO_LOW)
				{
					GPIOA->BRR = (1 << Copy_u8Pin);
				}

				else if (Copy_u8Value == GPIO_HIGH)
				{
					GPIOA->BSRR = (1 << Copy_u8Pin);
				}
				break;

			case PORTB :
				if (Copy_u8Value == GPIO_LOW)
				{
					GPIOB->BRR = (1 << Copy_u8Pin);
				}

				else if (Copy_u8Value == GPIO_HIGH)
				{
					GPIOB->BSRR = (1 << Copy_u8Pin);
				}
				break;

			case PORTC :
				if (Copy_u8Value == GPIO_LOW)
				{
					GPIOC->BRR = (1 << Copy_u8Pin);
				}

				else if (Copy_u8Value == GPIO_HIGH)
				{
					GPIOC->BSRR = (1 << Copy_u8Pin);
				}
				break;

			default : 		break;
		}
}


void MGPIO_voidSetPin(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	switch (Copy_u8Port)
	{
		case PORTA :
			/* Using ODR  register is slower because it is under sequence of read modify write */
			/* this operation takes 3 instructions */
			//SET_BIT(GPIOA->ODR,Copy_u8Pin);
			/* writing 1 to 16 lower bits of BSRR register it set the pin, writing 0 do nothing  */
			/* this operation takes only one instruction so it is more speed than the above */
			GPIOA->BSRR = (1 << Copy_u8Pin);
			break;
			
		case PORTB :
			//SET_BIT(GPIOB->ODR,Copy_u8Pin);
			GPIOB->BSRR = (1 << Copy_u8Pin);
			break;
			
		case PORTC :
			//SET_BIT(GPIOC->ODR,Copy_u8Pin);
			GPIOC->BSRR = (1 << Copy_u8Pin);
			break;
			
		default : 		break;
	}
}


void MGPIO_voidClearPin(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	switch (Copy_u8Port)
	{
		case PORTA :
			/* Using ODR  register is slower because it is under sequence of read modify write */
			/* this operation takes 3 instructions */
			//CLR_BIT(GPIOA->ODR,Copy_u8Pin);
			/* writing 1 to 16 lower bits of BRR register it reset the pin, writing 0 do nothing  */
			/* this operation takes only one instruction so it is more speed than the above */
			GPIOA->BRR = (1 << Copy_u8Pin);
			
			break;
			
		case PORTB :
			//CLR_BIT(GPIOB->ODR,Copy_u8Pin);
			GPIOB->BRR = (1 << Copy_u8Pin);
			break;
			
		case PORTC :
			//CLR_BIT(GPIOC->ODR,Copy_u8Pin);
			GPIOC->BRR = (1 << Copy_u8Pin);
			break;
			
		default : 		break;
	}
}


u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 Loc_u8Resilt = 0;
	
	switch (Copy_u8Port)
	{
		case PORTA :
			Loc_u8Resilt = GET_BIT(GPIOA->IDR,Copy_u8Pin);
			break;
			
		case PORTB :
			Loc_u8Resilt = GET_BIT(GPIOB->IDR,Copy_u8Pin);
			break;
			
		case PORTC :
			Loc_u8Resilt = GET_BIT(GPIOC->IDR,Copy_u8Pin);
			break;
			
		default : 		break;
	}
	
	return Loc_u8Resilt;
}


void MGPIO_voidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Mode)
{
    u32 Loc_u32ModeLow = 0;
    u32 Loc_u32ModeHigh = 0;
	for (u8 i=0;i<=7;i++)
		{
			Loc_u32ModeLow |= (u64)(Copy_u8Mode << (i*4));
			Loc_u32ModeHigh |= (u64)(Copy_u8Mode << (i*4));
		}
	switch (Copy_u8Port)
	{
		case PORTA :
			GPIOA->CRL = Loc_u32ModeLow;
			GPIOA->CRH = Loc_u32ModeHigh;
			break;
			
		case PORTB :
			GPIOB->CRL = Loc_u32ModeLow;
			GPIOB->CRH = Loc_u32ModeHigh;
			break;
			
		case PORTC :
			GPIOC->CRL = Loc_u32ModeLow;
			GPIOC->CRH = Loc_u32ModeHigh;
			break;
			
		default : 		break;
	}
}


void MGPIO_voidSetPortValue(u8 Copy_u8Port,u16 Copy_u16Val)
{
	switch (Copy_u8Port)
	{
		case PORTA :
			GPIOA->ODR = Copy_u16Val;
			break;
			
		case PORTB :
			GPIOB->ODR = Copy_u16Val;
			break;
			
		case PORTC :
			GPIOC->ODR = Copy_u16Val;
			break;
			
		default : 		break;
	}
}


u16 MGPIO_u16GetPortValue(u8 Copy_u8Port)
{
	u16 Loc_u16Result = 0;
	switch (Copy_u8Port)
	{
		case PORTA :
			Loc_u16Result = GPIOA->IDR;
			break;
			
		case PORTB :
			Loc_u16Result = GPIOB->IDR;
			break;
			
		case PORTC :
			Loc_u16Result = GPIOC->IDR;
			break;
			
		default : 		break;
	}
	
	return Loc_u16Result;
}


static void MGPIO_voidLockSequence(u8 Copy_u8Port)
{
	switch (Copy_u8Port)
	{
		case PORTA :
			/* lock sequence */
			SET_BIT(GPIOA->LCKR,16); 
			CLR_BIT(GPIOA->LCKR,16); 
			SET_BIT(GPIOA->LCKR,16); 
			if (GET_BIT(GPIOA->LCKR,16) != 0)
			{
				//return error ---------> it must be 0
			}
			if (GET_BIT(GPIOA->LCKR,16) != 1)
			{
				//return error ---------> it must be 1
			} 
			break;
			
		case PORTB :
			/* lock sequence */
			SET_BIT(GPIOB->LCKR,16); 
			CLR_BIT(GPIOB->LCKR,16); 
			SET_BIT(GPIOB->LCKR,16); 
			if (GET_BIT(GPIOB->LCKR,16) != 0)
			{
				//return error ---------> it must be 0
			}
			if (GET_BIT(GPIOB->LCKR,16) != 1)
			{
				//return error ---------> it must be 1
			} 
			break;
			
		case PORTC :
			/* lock sequence */
			SET_BIT(GPIOC->LCKR,16); 
			CLR_BIT(GPIOC->LCKR,16); 
			SET_BIT(GPIOC->LCKR,16); 
			if (GET_BIT(GPIOC->LCKR,16) != 0)
			{
				//return error ---------> it must be 0
			}
			if (GET_BIT(GPIOC->LCKR,16) != 1)
			{
				//return error ---------> it must be 1
			} 
			break;
			
		default : 		break;
	}
}


void MGPIO_voidLockPin(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	switch (Copy_u8Port)
	{
		case PORTA :
			SET_BIT(GPIOA->LCKR,Copy_u8Pin);   		// Lock pin configuration
			/* lock sequence */
			MGPIO_voidLockSequence(Copy_u8Port);
			break;
			
		case PORTB :
			SET_BIT(GPIOB->LCKR,Copy_u8Pin);		// Lock pin configuration
			/* lock sequence */
			MGPIO_voidLockSequence(Copy_u8Port);
			break;
			
		case PORTC :
			SET_BIT(GPIOC->LCKR,Copy_u8Pin);		// Lock pin configuration
			/* lock sequence */
			MGPIO_voidLockSequence(Copy_u8Port);
			break;
			
		default : 		break;
	}
}



void MGPIO_voidUnlockPin(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	switch (Copy_u8Port)
	{
		case PORTA :
			CLR_BIT(GPIOA->LCKR,Copy_u8Pin);   		// Lock pin configuration
			/* lock sequence */
			MGPIO_voidLockSequence(Copy_u8Port);
			break;
			
		case PORTB :
			CLR_BIT(GPIOB->LCKR,Copy_u8Pin);		// Lock pin configuration
			/* lock sequence */
			MGPIO_voidLockSequence(Copy_u8Port);
			break;
			
		case PORTC :
			CLR_BIT(GPIOC->LCKR,Copy_u8Pin);		// Lock pin configuration
			MGPIO_voidLockSequence(Copy_u8Port);
			break;
			
		default : 		break;
	}
}


void MGPIO_voidSetPullResistor(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PullType)
{
	/* set pin configuration as input pull */
	MGPIO_voidSetPinDirection(Copy_u8Port , Copy_u8Pin , GPIO_INPUT_PULL_UP_DOWN);
	switch (Copy_u8Port)
	{
		case PORTA :
			if (Copy_u8PullType == GPIO_PULL_UP)
			{
				GPIOA->BSRR = (1 << Copy_u8Pin);
			}
			
			else if (Copy_u8PullType == GPIO_PULL_DOWN)
			{
				GPIOA->BRR = (1 << Copy_u8Pin);
			}
			break;
			
		case PORTB :
			if (Copy_u8PullType == GPIO_PULL_UP)
			{
				GPIOB->BSRR = (1 << Copy_u8Pin);
			}
			
			else if (Copy_u8PullType == GPIO_PULL_DOWN)
			{
				GPIOB->BRR = (1 << Copy_u8Pin);
			}
			break;
			
		case PORTC :
			if (Copy_u8PullType == GPIO_PULL_UP)
			{
				GPIOC->BSRR = (1 << Copy_u8Pin);
			}
			
			else if (Copy_u8PullType == GPIO_PULL_DOWN)
			{
				GPIOC->BRR = (1 << Copy_u8Pin);
			}
			break;
			
		default : 		break;
	}
}
