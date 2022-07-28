/****************************************************************/
/*	Author   : Ahmed Mohy									   	*/
/*	Date     : 26 DEC 2021										*/
/*	Version  : V01												*/
/****************************************************************/


#ifndef 	EXTI_PRIVATE_H
#define 	EXTI_PRIVATE_H

#define 	NULL			((void *)0)

/* Array of pointers to function for 16 ISR */
void (*EXTI_Callback[16]) (void) = {NULL} ;


#define 	EXTI_BASE_ADDRESS				 0X40010400


typedef struct{
	volatile u32 IMR,EMR,RTSR,FTSR,SWIER,PR;
}EXTI_t;


#define		EXTI							((volatile EXTI_t*)(EXTI_BASE_ADDRESS))


#endif
