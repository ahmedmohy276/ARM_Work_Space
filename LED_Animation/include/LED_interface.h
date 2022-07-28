/*****************************************************************************/
/* Author    : Ahmed Mohy													 */
/* Date      : 25 DEC 2021													 */
/* Version   : V01														     */
/*****************************************************************************/


#ifndef		LED_INTERFACE_H
#define 	LED_INTERFACE_H

void LED_voidInit(u8 Copy_u8Port , u8 Copy_u8Pin);
void LED_voidTurnOn(u8 Copy_u8Port , u8 Copy_u8Pin);
void LED_voidTurnOff(u8 Copy_u8Port , u8 Copy_u8Pin);
void LED_voidTurnToggle(u8 Copy_u8Port , u8 Copy_u8Pin , u32 Copy_u32Delayms);


#endif
