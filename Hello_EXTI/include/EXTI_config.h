/****************************************************************/
/*	Author   : Ahmed Mohy									   	*/
/*	Date     : 26 DEC 2021										*/
/*	Version  : V01												*/
/****************************************************************/


#ifndef 	EXTI_CONFIG_H
#define 	EXTI_CONFIG_H


/* Options : EXTI_RISING
			 EXTI_FALLING
			 EXTI_ON_CHANGE
			 */
#define 	INTERRUPT_MODE		EXTI_RISING


/* Options : EXTI_LINE0
			 .
			 .
			 .
			 EXTI_LINE15
			 */
#define		INTERRUPT_LINE		EXTI_LINE0

#endif