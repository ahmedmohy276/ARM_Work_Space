/*****************************************************************************/
/* Author    : Ahmed Mohy													 */
/* Date      : 28 DEC 2021													 */
/* Version   : V01														     */
/*****************************************************************************/


#ifndef		LEDANIM_INTERFACE_H
#define 	LEDANIM_INTERFACE_H

void LEDANIM_voidInit(void);

/* Function to display 8 leds shift right and left (Ping Pong) */
void LEDANIM_voidDisplayPingPong(u32 Copy_u32Delayms , u8 Copy_u8Repetition);


void LEDANIM_voidDisplayInOut(u32 Copy_u32Delayms , u8 Copy_u8Repetition);

/* Function to flashing 8 leds */
void LEDANIM_voidDisplayFlashing(u32 Copy_u32Delayms , u8 Copy_u8Repetition);

#endif
