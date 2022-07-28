/*****************************************************************************/
/* Author    : Ahmed Mohy													 */
/* Date      : 28 DEC 2021													 */
/* Version   : V01														     */
/*****************************************************************************/

#ifndef		SYSTICK_PRIVATE_H
#define 	SYSTICK_PRIVATE_H

#define 	NULL			((void *)0)

#define		SYSTICK_BASE_ADDRESS				0XE000E010

typedef struct{
	volatile u32 CTRL , LOAD , VAL , CALIB ;
}SYSTICK_t;


#define		SYSTICK								((volatile SYSTICK_t*)0XE000E010)

/* Define Callback Global Variable */
void(*MSTK_CallBack)(void) = NULL ;

/* Define Variable for interval mode */
u8 MSTK_u8ModeOfInterval;

#define		AHB_CLOCK							0
#define		AHB_CLOCK_DIV_8						1

#define     MSTK_SINGLE_INTERVAL    			0
#define     MSTK_PERIOD_INTERVAL    			1


#endif
