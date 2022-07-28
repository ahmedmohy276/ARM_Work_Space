/****************************************************************/
/*	Author   : Ahmed Mohy									   	*/
/*	Date     : 28 DEC 2021										*/
/*	Version  : V01												*/
/****************************************************************/


#ifndef		AFIO_PRIVATE_H
#define		AFIO_PRIVATE_H


#define		AFIO_BASE_ADDRESS			0X40010000

typedef	struct{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
}AFIO_t;


#define		AFIO						((volatile AFIO_t*)(AFIO_BASE_ADDRESS))


#endif
