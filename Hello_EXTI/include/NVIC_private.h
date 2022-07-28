/****************************************************************/
/*	Author   : Ahmed Mohy									   	*/
/*	Date     : 26 DEC 2021										*/
/*	Version  : V01												*/
/****************************************************************/


#ifndef		NVIC_PRIVATE_H
#define		NVIC_PRIVATE_H


#define		NVIC_BASE_ADDRESS				0XE000E100



#define		NVIC_ISER0						(*((volatile u32*)(NVIC_BASE_ADDRESS + 0X000)))
#define		NVIC_ISER1						(*((volatile u32*)(NVIC_BASE_ADDRESS + 0X004)))

#define		NVIC_ICER0						(*((volatile u32*)(NVIC_BASE_ADDRESS + 0X080)))
#define		NVIC_ICER1						(*((volatile u32*)(NVIC_BASE_ADDRESS + 0X084)))

#define		NVIC_ISPR0						(*((volatile u32*)(NVIC_BASE_ADDRESS + 0X100)))
#define		NVIC_ISPR1                      (*((volatile u32*)(NVIC_BASE_ADDRESS + 0X104)))

#define		NVIC_ICPR0                      (*((volatile u32*)(NVIC_BASE_ADDRESS + 0X180)))
#define		NVIC_ICPR1                      (*((volatile u32*)(NVIC_BASE_ADDRESS + 0X184)))

#define		NVIC_IABR0                      (*((volatile u32*)(NVIC_BASE_ADDRESS + 0X200)))
#define		NVIC_IABR1                      (*((volatile u32*)(NVIC_BASE_ADDRESS + 0X204)))

	/* in NVIC_IPR we defined it as pointer refer to an array of u8 to access
	the 8 bit priority of each interrupt like-----> NVIC_IPR[IntNumber] */
#define		NVIC_IPR	                    ((volatile u8*)(NVIC_BASE_ADDRESS + 0X300))




#endif
