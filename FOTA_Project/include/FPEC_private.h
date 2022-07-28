/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  7 January 2022             */
/* Version :  V01                        */
/*****************************************/



#ifndef		FPEC_PRIVATE_H
#define  	FPEC_PRIVATE_H


#define		FPEC_BASE_ADDRESS			0X40022000

typedef struct 
{
	volatile u32 ACR,KEYR,OPTKEYR,SR,CR,AR,Reserved,OBR,WRPR ;
}FPEC_Registers;


#define		FPEC						((volatile FPEC_Registers*)FPEC_BASE_ADDRESS)


#endif