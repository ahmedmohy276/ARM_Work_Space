/************************************************************************************************/
/*	Author   : Ahmed Mohy														    			*/
/*	Date     : 25 DEC 2021																		*/
/*	Version  : V01																				*/
/************************************************************************************************/


#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H


#define		GPIOA_BASE_ADDRESS			0X40010800
#define		GPIOB_BASE_ADDRESS			0X40010C00
#define		GPIOC_BASE_ADDRESS			0X40011000

typedef	struct {
	volatile u32 CRL,CRH,IDR,ODR,BSRR,BRR,LCKR;
}GPIO_t;


#define		GPIOA						((volatile GPIO_t*)(GPIOA_BASE_ADDRESS))
#define		GPIOB						((volatile GPIO_t*)(GPIOB_BASE_ADDRESS))
#define		GPIOC						((volatile GPIO_t*)(GPIOC_BASE_ADDRESS))


/**********************************************************************************/
/*

					<<<<<<GPIOA register addresses >>>>>>
#define		GPIOA_CRL						(*((volatile u32*)(GPIOA_BASE_ADDRESS + 0X00 )))
#define		GPIOA_CRH						(*((volatile u32*)(GPIOA_BASE_ADDRESS + 0X04 )))
#define		GPIOA_IDR						(*((volatile u32*)(GPIOA_BASE_ADDRESS + 0X08 )))
#define		GPIOA_ODR						(*((volatile u32*)(GPIOA_BASE_ADDRESS + 0X0C )))
#define		GPIOA_BSRR						(*((volatile u32*)(GPIOA_BASE_ADDRESS + 0X10 )))
#define		GPIOA_BRR	       				(*((volatile u32*)(GPIOA_BASE_ADDRESS + 0X14 )))
#define		GPIOA_LCKR						(*((volatile u32*)(GPIOA_BASE_ADDRESS + 0X18 )))


					<<<<<<GPIOB register addresses >>>>>>
#define		GPIOB_CRL						(*((volatile u32*)(GPIOB_BASE_ADDRESS + 0X00 )))
#define		GPIOB_CRH						(*((volatile u32*)(GPIOB_BASE_ADDRESS + 0X04 )))
#define		GPIOB_IDR						(*((volatile u32*)(GPIOB_BASE_ADDRESS + 0X08 )))
#define		GPIOB_ODR						(*((volatile u32*)(GPIOB_BASE_ADDRESS + 0X0C )))
#define		GPIOB_BSRR						(*((volatile u32*)(GPIOB_BASE_ADDRESS + 0X10 )))
#define		GPIOB_BRR	       				(*((volatile u32*)(GPIOB_BASE_ADDRESS + 0X14 )))
#define		GPIOB_LCKR						(*((volatile u32*)(GPIOB_BASE_ADDRESS + 0X18 )))


					<<<<<<GPIOC register addresses >>>>>>
#define		GPIOC_CRL						(*((volatile u32*)(GPIOC_BASE_ADDRESS + 0X00 )))
#define		GPIOC_CRH						(*((volatile u32*)(GPIOC_BASE_ADDRESS + 0X04 )))
#define		GPIOC_IDR						(*((volatile u32*)(GPIOC_BASE_ADDRESS + 0X08 )))
#define		GPIOC_ODR						(*((volatile u32*)(GPIOC_BASE_ADDRESS + 0X0C )))
#define		GPIOC_BSRR						(*((volatile u32*)(GPIOC_BASE_ADDRESS + 0X10 )))
#define		GPIOC_BRR	       				(*((volatile u32*)(GPIOC_BASE_ADDRESS + 0X14 )))
#define		GPIOC_LCKR						(*((volatile u32*)(GPIOC_BASE_ADDRESS + 0X18 )))

*/


#endif