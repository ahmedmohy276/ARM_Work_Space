/****************************************************************/
/*	Author   : Ahmed Mohy									   	*/
/*	Date     : 26 DEC 2021										*/
/*	Version  : V01												*/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"



void MEXTI_voidInit(void)
{
	#if		INTERRUPT_MODE == EXTI_RISING
		SET_BIT(EXTI->RTSR , INTERRUPT_LINE);
		
	#elif	INTERRUPT_MODE == EXTI_FALLING
		SET_BIT(EXTI->FTSR , INTERRUPT_LINE);
		
	#elif	INTERRUPT_MODE == EXTI_ON_CHANGE
		SET_BIT(EXTI->RTSR , INTERRUPT_LINE);
		SET_BIT(EXTI->FTSR , INTERRUPT_LINE);
		
	#else 
		#error("invalid mode")

	#endif
	
	CLR_BIT(EXTI->IMR , INTERRUPT_LINE);		//Disable interrupt line
}


void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI->IMR , Copy_u8EXTILine);		//Enable interrupt line
}


void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine)
{
	CLR_BIT(EXTI->IMR , Copy_u8EXTILine);		//Enable interrupt line
}


void MEXTI_voidSWTrigger(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI->SWIER , Copy_u8EXTILine); 		//Enable Software Interrupt
}



void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8EXTISenseMode)
{
	SET_BIT(EXTI->IMR , Copy_u8EXTILine);		//Enable interrupt line

	switch (Copy_u8EXTISenseMode)      
	{                         
		case EXTI_RISING :          
			SET_BIT(EXTI->RTSR , Copy_u8EXTILine);                  
			break;            

		case EXTI_FALLING :          
			SET_BIT(EXTI->FTSR , Copy_u8EXTILine);                  
			break;            

		case EXTI_ON_CHANGE :          
			SET_BIT(EXTI->RTSR , Copy_u8EXTILine);
			SET_BIT(EXTI->FTSR , Copy_u8EXTILine);                  
			break;            

		default : 		break;
	}
	
}



void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine , void (*ptr) (void) )
{
	EXTI_Callback[Copy_u8EXTILine] = ptr ;
}


void EXTI0_IRQHandler(void)
{
	EXTI_Callback[0]();
	/* clear pending bit by write on to it */
	SET_BIT(EXTI->PR , 0); 
}

void EXTI1_IRQHandler(void)
{
	EXTI_Callback[1]();
	/* clear pending bit by write on to it */
	SET_BIT(EXTI->PR , 1); 
}

void EXTI2_IRQHandler(void)
{
	EXTI_Callback[2]();
	/* clear pending bit by write on to it */
	SET_BIT(EXTI->PR , 2); 
}

void EXTI3_IRQHandler(void)
{
	EXTI_Callback[3]();
	/* clear pending bit by write on to it */
	SET_BIT(EXTI->PR , 3); 
}

void EXTI4_IRQHandler(void)
{
	EXTI_Callback[4]();
	/* clear pending bit by write on to it */
	SET_BIT(EXTI->PR , 4); 
}

void EXTI5_IRQHandler(void)
{
	EXTI_Callback[5]();
	/* clear pending bit by write on to it */
	SET_BIT(EXTI->PR , 5); 
}

void EXTI6_IRQHandler(void)
{
	EXTI_Callback[6]();
	/* clear pending bit by write on to it */
	SET_BIT(EXTI->PR , 6); 
}

void EXTI7_IRQHandler(void)
{
	EXTI_Callback[7]();
	/* clear pending bit by write on to it */
	SET_BIT(EXTI->PR , 7); 
}

void EXTI8_IRQHandler(void)
{
	EXTI_Callback[8]();
	/* clear pending bit by write on to it */
	SET_BIT(EXTI->PR , 8); 
}

void EXTI9_IRQHandler(void)
{
	EXTI_Callback[9]();
	/* clear pending bit by write on to it */
	SET_BIT(EXTI->PR , 9); 
}

void EXTI10_IRQHandler(void)
{
	EXTI_Callback[10]();
	/* clear pending bit by write on to it */
	SET_BIT(EXTI->PR , 10); 
}

void EXTI11_IRQHandler(void)
{
	EXTI_Callback[11]();
	/* clear pending bit by write on to it */
	SET_BIT(EXTI->PR , 11); 
}

void EXTI12_IRQHandler(void)
{
	EXTI_Callback[12]();
	/* clear pending bit by write on to it */
	SET_BIT(EXTI->PR , 12); 
}

void EXTI13_IRQHandler(void)
{
	EXTI_Callback[13]();
	/* clear pending bit by write on to it */
	SET_BIT(EXTI->PR , 13); 
}

void EXTI14_IRQHandler(void)
{
	EXTI_Callback[14]();
	/* clear pending bit by write on to it */
	SET_BIT(EXTI->PR , 14); 
}

void EXTI15_IRQHandler(void)
{
	EXTI_Callback[15]();
	/* clear pending bit by write on to it */
	SET_BIT(EXTI->PR , 15); 
}
