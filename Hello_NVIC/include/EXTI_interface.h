/****************************************************************/
/*	Author   : Ahmed Mohy									   	*/
/*	Date     : 26 DEC 2021										*/
/*	Version  : V01												*/
/****************************************************************/


#ifndef 	EXTI_INTERFACE_H
#define 	EXTI_INTERFACE_H


#define		EXTI_RISING					0
#define		EXTI_FALLING				1
#define		EXTI_ON_CHANGE				2


#define		EXTI_LINE0					0
#define		EXTI_LINE1					1
#define		EXTI_LINE2					2
#define		EXTI_LINE3					3
#define		EXTI_LINE4					4
#define		EXTI_LINE5					5
#define		EXTI_LINE6					6
#define		EXTI_LINE7					7
#define		EXTI_LINE8					8
#define		EXTI_LINE9					9
#define		EXTI_LINE10					10
#define		EXTI_LINE11					11
#define		EXTI_LINE12					12
#define		EXTI_LINE13					13
#define		EXTI_LINE14					14
#define		EXTI_LINE15					15


/* initialize EXTI Mode and line as configuration */
void MEXTI_voidInit(void);

/* EXTI Mode and line in the run time */ 
void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8EXTISenseMode);

/* enable EXTI Line */
void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine);

/* disable EXTI Line */
void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine);

/* enable Software interrupt */
void MEXTI_voidSWTrigger(u8 Copy_u8EXTILine);

/* Call back function to take pinter to the function that will execute in the ISR */
void MEXTI_voidSetCallBack( u8 Copy_u8EXTILine , void (*ptr) (void) );




#endif