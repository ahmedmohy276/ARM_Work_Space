/****************************************************************/
/* Authour	: Ahmed Mohy										*/ 
/* Date     : 1 January 2022									*/
/* Version  : V01												*/
/****************************************************************/


#ifndef		IR_PRIVATE_H
#define		IR_PRIVATE_H

void (*IR_Callback) (u8) ;
volatile u8 u8Counter = 0 ;
volatile u8 u8StartFlag = 0;
volatile u8 u8RecData ;
u32 u32RecFrame[50] = {0} ;

static void voidReceiveFrame(void);

static void voidTakeAction(void);
 


#define		IR_EXTI0			0
#define		IR_EXTI1			1
#define		IR_EXTI2			2
#define		IR_EXTI3			3
#define		IR_EXTI4			4
#define		IR_EXTI5			5
#define		IR_EXTI6			6
#define		IR_EXTI7			7
#define		IR_EXTI8			8
#define		IR_EXTI9			9
#define		IR_EXTI10			10
#define		IR_EXTI11			11
#define		IR_EXTI12			12
#define		IR_EXTI13			13
#define		IR_EXTI14			14
#define		IR_EXTI15			15



#endif
