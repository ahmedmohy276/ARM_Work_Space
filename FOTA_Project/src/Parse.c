/*****************************************/
/* Author  :  Ahmed Mohy                 */
/* Date    :  7 January 2022             */
/* Version :  V01                        */
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FPEC_interface.h"

u16 Data[100] = {0};
u32 Address= 0x08000000;
volatile u8 CRC_error_Flag = 0 ;

u8 AsciToHex(u8 Copy_u8Asci)
{
	u8 Result;
	if ( (Copy_u8Asci >= 48) && (Copy_u8Asci <= 57) )
	{
		Result = Copy_u8Asci - 48;
	}

	else
	{
		Result = Copy_u8Asci - 55;
	}

	return Result;
}


void CRC_Check(u8 Copy_u8BufData[])
{
	u8 DigitLow,DigitHigh,CharacterCount,ReceivedCRC;
	u16 Checksum = 0 ;
	u8 RecordData[50] = {0} ;
	u8 DataCounter = 0;
	DigitHigh = AsciToHex(Copy_u8BufData[1]) ;
	DigitLow = AsciToHex(Copy_u8BufData[2]) ;
	CharacterCount = (DigitHigh << 4) | (DigitLow) ;

	for (u16 i=1 ; i<=(CharacterCount + 5) ; i++)
	{
		DigitHigh = AsciToHex (Copy_u8BufData[2*i-1 ]) ;
		DigitLow = AsciToHex (Copy_u8BufData[2*i]) ;

		RecordData[DataCounter] = (DigitHigh << 4) | (DigitLow) ;
		DataCounter++;
	}

	ReceivedCRC = RecordData[CharacterCount + 4] ;
	Checksum = RecordData[0] ;

	for(u16 i = 1 ; i<(CharacterCount + 4) ; i++)
	{
		Checksum += RecordData[i] ;
	}

	/* 2's Complement */
	Checksum = (u8)((~ Checksum) + 1) ;

	if((u8)Checksum != ReceivedCRC)
	{
		CRC_error_Flag = 1 ;
	}
}


void ParseData(u8* Copy_u8BufData)
{
	u8 DigitLow,DigitHigh,CC,i;
	u8 DataDigit0,DataDigit1,DataDigit2,DataDigit3;
	u8 DataCounter = 0;

	/* Hex record CRC check */
	CRC_Check(Copy_u8BufData) ;

	/* Get Character Count */
	DigitHigh = AsciToHex (Copy_u8BufData[1]);
	DigitLow  = AsciToHex (Copy_u8BufData[2]);
	CC        = (DigitHigh<<4) | DigitLow ;

	/* Get Address */
	DataDigit0 = AsciToHex (Copy_u8BufData[3]);
	DataDigit1 = AsciToHex (Copy_u8BufData[4]);
	DataDigit2 = AsciToHex (Copy_u8BufData[5]);
	DataDigit3 = AsciToHex (Copy_u8BufData[6]);

	/* Clear Low Part of Address */
	Address = Address & 0xFFFF0000;
	Address = Address | (DataDigit3) | (DataDigit2 << 4) | (DataDigit1 << 8) | (DataDigit0<<12);

	for (i=0;i<CC/2; i++)
	{
		DataDigit0 = AsciToHex (Copy_u8BufData[4*i+9 ]);
		DataDigit1 = AsciToHex (Copy_u8BufData[4*i+10]);
		DataDigit2 = AsciToHex (Copy_u8BufData[4*i+11]);
		DataDigit3 = AsciToHex (Copy_u8BufData[4*i+12]);
		// 0x5678--->0x7856 because ARM STM32F103C8 is a little endian that means the LSB located in the smallest address.
		Data[DataCounter] = (DataDigit3 << 8) | (DataDigit2 << 12) | (DataDigit1) | (DataDigit0<<4);
		DataCounter++;
	}

	FPEC_voidFlashWrite(Address,Data,CC/2);
}

void ParseUpperAddress(u8* Copy_u8BufData)
{
	/* Hex record CRC check */
	CRC_Check(Copy_u8BufData) ;
//	u8 DataDigit0,DataDigit1,DataDigit2,DataDigit3;
//
//	/* Get Address */
//	DataDigit0 = AsciToHex (Copy_u8BufData[3]);
//	DataDigit1 = AsciToHex (Copy_u8BufData[4]);
//	DataDigit2 = AsciToHex (Copy_u8BufData[5]);
//	DataDigit3 = AsciToHex (Copy_u8BufData[6]);
//
//	/* Clear Low Part of Address */
//	Address = Address & (u32)0x0000FFFF;
//	Address = Address | (u32)((u32)(DataDigit3 << 28) | (u32)(DataDigit2 << 24) | (u32)(DataDigit1 << 20) | (u32)(DataDigit0 << 16));
}

void Parser_voidParseRecord(u8* Copy_u8BufData)
{
	switch (Copy_u8BufData[8])
	{
	case '0': ParseData(Copy_u8BufData); break;
	case '4': ParseUpperAddress(Copy_u8BufData); break;
	}
}
