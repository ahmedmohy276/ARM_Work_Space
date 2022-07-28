/********************************************************************/
/* Author   : Ahmed Mohy						    				*/
/* Date	    : 25 DEC 2021											*/
/* Version  : V01													*/
/********************************************************************/



#ifndef SEVSEG_PRIVATE_H
#define SEVSEG_PRIVATE_H


/* array that carry equvalent pin values for numbers from 0 to 9 in 7-segment */
u8 array_val[10] = { 0b00111111 , 0b00000110 , 0b01011011 , 0b01001111 , 0b01100110 ,
					 0b01101101 , 0b01111101 , 0b00000111 , 0b01111111 , 0b01101111 };


		/* 7-segment type */
#define COMMON_ANODE_SEVSEG				0
#define COMMON_CATHODE_SEVSEG			1





#endif				
