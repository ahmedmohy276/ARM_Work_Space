/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  2 January 2022             */
/* Version :  V01                        */
/*****************************************/

#ifndef		DAC_PRIVATE_H
#define     DAC_PRIVATE_H

#define		NULL				((void *)0)


#define		DAC_PORTA			0
#define		DAC_PORTB			1
#define		DAC_PORTC			2


static volatile const u8 *DAC_Input = NULL ;
static volatile u16 DAC_Input_Size = 0 ;
static volatile u16 u16ArrayCount = 0 ;

static void DAC_Output (void) ;


#endif
