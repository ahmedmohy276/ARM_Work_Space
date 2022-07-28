/****************************************************************/
/*	Author   : Ahmed Mohy									   	*/
/*	Date     : 31 DEC 2021										*/
/*	Version  : V02												*/
/****************************************************************/


#ifndef 	LEDMAT_PRIVATE_H
#define 	LEDMAT_PRIVATE_H

#define		LEDMAT_PORTA		0
#define		LEDMAT_PORTB		1
#define		LEDMAT_PORTC		2


u8 HLEDMAT_u8CurrentIndex ;
u8 *HLEDMAT_u8Frame ;

static void HLEDMAT_voidDisplayNextColumn(void);

static void HLEDMAT_voidSetRowsValue(u8 Copy_u8Value);

static void HLEDMAT_voidActivateColumn(u8 Copy_u8Col);

#endif
