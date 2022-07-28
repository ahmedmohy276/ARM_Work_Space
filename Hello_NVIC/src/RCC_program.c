/*****************************************************************************/
/* Author    : Ahmed Mohy													 */
/* Date      : 24 DEC 2021													 */
/* Version   : V01														     */
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void MRCC_voidInitSysClock(void)
{
	#if		RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR = 0X00010000;								/* Enable HSE with no bypass */
		RCC_CFGR = 0X00000001;								/* Select system clock switch */
		
	#elif 	RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR = 0X00050000;								/* Enable HSE with bypass */
		RCC_CFGR = 0X00000001;								/* Select system clock switch */
		
	#elif 	RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR = 0X00000081;								/* Enable HSi + Trimming = 0 */
		RCC_CFGR = 0X00000000;								/* Select system clock switch */
		
	#elif 	RCC_CLOCK_TYPE == RCC_PLL
		#if		RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			RCC_CFGR &= ~(0XF << 18);						/* Clear PLLMUL bits */
			RCC_CFGR |= ((RCC_PLL_MUL_VAL - 2) << 18);		/* Set value of PLLMUL val */
			CLR_BIT(RCC_CFGR,16);							/* set PLL input clock to HSI/2 */
			CLR_BIT(RCC_CFGR,0);							/* Select system clock switch */
			CLR_BIT(RCC_CFGR,1);
			
			RCC_CR = 0X01000081;						   /* enable PLL and HSI clock + Trimming = 0 */
			
		#elif 	RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
			RCC_CFGR &= ~(0XF << 18);						/* Clear PLLMUL bits */
			RCC_CFGR |= ((RCC_PLL_MUL_VAL - 2) << 18);		/* Set value of PLLMUL val */
			SET_BIT(RCC_CFGR,16);							/* set PLL input clock to HSE */
			SET_BIT(RCC_CFGR,17);							/* HSE prescaler = 2 */
			SET_BIT(RCC_CFGR,0);							/* Select system clock switch */
			CLR_BIT(RCC_CFGR,1);
			
			#if		RCC_PLL_IN_HSE_TYPE	== RCC_PLL_IN_HSE_CRYSTAL
				RCC_CR = 0X01010000;						/* enable PLL and HSE clock with no bypass */
				
			#elif	RCC_PLL_IN_HSE_TYPE	== RCC_PLL_IN_HSE_RC
				RCC_CR = 0X01050000;						/* enable PLL and HSE clock with bypass */
			
			#else
				#error("you entered non valid value")
			#endif
			
		#elif 	RCC_PLL_INPUT == RCC_PLL_IN_HSE
			RCC_CFGR &= ~(0XF << 18);						/* Clear PLLMUL bits */
			RCC_CFGR |= ((RCC_PLL_MUL_VAL - 2) << 18);		/* Set value of PLLMUL val */
			SET_BIT(RCC_CFGR,16);							/* set PLL input clock to HSE */
			CLR_BIT(RCC_CFGR,17);							/* HSE prescaler = 1 */
			SET_BIT(RCC_CFGR,0);							/* Select system clock switch */
			CLR_BIT(RCC_CFGR,1);
			
			#if		RCC_PLL_IN_HSE_TYPE	== RCC_PLL_IN_HSE_CRYSTAL
				RCC_CR = 0X01010000;						/* enable PLL and HSE clock with no bypass */
				
			#elif	RCC_PLL_IN_HSE_TYPE	== RCC_PLL_IN_HSE_RC
				RCC_CR = 0X01050000;						/* enable PLL and HSE clock with bypass */
				
			#else
				#error("you entered non valid value")
			#endif
			
		#else
			#error("you entered non valid value")
		#endif
	#else
		#error("you entered non valid clock type")
	#endif
}


void MRCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_ABH   :
				SET_BIT(RCC_AHBENR,Copy_u8PerId);
				break;
				
			case RCC_APB1  :
				SET_BIT(RCC_APB1ENR,Copy_u8PerId);
				break;
				
			case RCC_APB2  :
				SET_BIT(RCC_APB2ENR,Copy_u8PerId);
				break;
				
			default        : 
				/* Return error */ 
				break;
		}
	}
	
	else
	{
		/* Return error */
	}
}




void MRCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_ABH   :
				CLR_BIT(RCC_AHBENR,Copy_u8PerId);
				break;
				
			case RCC_APB1  :
				CLR_BIT(RCC_APB1ENR,Copy_u8PerId);
				break;
				
			case RCC_APB2  :
				CLR_BIT(RCC_APB2ENR,Copy_u8PerId);
				break;
				
			default        : 
				/* Return error */ 
				break;
		}
	}
	
	else
	{
		/* Return error */
	}
}
