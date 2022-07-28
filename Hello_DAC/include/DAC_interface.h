/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  2 January 2022             */
/* Version :  V01                        */
/*****************************************/


#ifndef		DAC_INTERFACE_H
#define     DAC_INTERFACE_H


void HDAC_voidInit(void) ;

void HDAC_voidSetDACInput(const u8 *Copy_u8Arr , u16 Copy_u8Size) ;

void HDAC_voidStart(u32 Copy_u32SampleTime);

#endif
