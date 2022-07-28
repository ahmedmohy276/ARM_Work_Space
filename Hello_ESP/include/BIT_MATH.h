/*****************************************************************************/
/* Author    : Ahmed Mohy													 */
/* Date      : 23 DEC 2021													 */
/* Version   : V01														     */
/*****************************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define CHAR_SIZE     8

#define SET_BIT(VAR,BIT)					(VAR |= (1 << BIT))
#define CLR_BIT(VAR,BIT)					(VAR &=~(1 << BIT))
#define TOG_BIT(VAR,BIT)					(VAR ^= (1 << BIT))
#define GET_BIT(VAR,BIT)					((VAR >> BIT) & (1))
#define SHR(VAR,SHIFT)						(VAR >> SHIFT)
#define SHL(VAR,SHIFT)						(VAR << SHIFT)
#define ROTR(VAR,SHIFT)						((VAR >> SHIFT) | (VAR << (sizeof(VAR)*CHAR_SIZE - SHIFT)))
#define ROTL(VAR,SHIFT)						((VAR << SHIFT) | (VAR >> (sizeof(VAR)*CHAR_SIZE - SHIFT)))

#endif