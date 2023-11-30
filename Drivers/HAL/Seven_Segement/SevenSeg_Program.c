/*
 * SevenSeg_Program.c
 *
 *  Created on: Sep 12, 2023
 *      Author: salma
 */
#include "SevenSeg_Interface.h"
u8 SevSegValue[10]=SEVSEGVALUE;
void SEVSEG_voidInit()
{
	DIO_voidSetPortDir(SevSeg1,0xff);
	DIO_voidSetPortDir(SevSeg2,0xff);
	DIO_voidSetPortValue(SevSeg1,OFF);
	DIO_voidSetPortValue(SevSeg2,OFF);
}

void SEVSEG_voidSetNum(u8 num)
{

	if (num<10)
	{
		DIO_voidSetPortValue(SevSeg1,SevSegValue[num]);
		DIO_voidSetPortValue(SevSeg2,OFF);
	}
	else if (num==10)
	{
		DIO_voidSetPortValue(SevSeg1,SevSegValue[0]);
		DIO_voidSetPortValue(SevSeg2,SevSegValue[1]);
	}
	else
	{
		u8 counter = 0  ;
		while(num>=10)
		{
			counter++;
			num-=10;
		}
		DIO_voidSetPortValue(SevSeg1,SevSegValue[num]);
		DIO_voidSetPortValue(SevSeg2,SevSegValue[counter]);
	}
}
void SEVSEG_voidOff ()
{
	DIO_voidSetPortValue(SevSeg1,OFF);
	DIO_voidSetPortValue(SevSeg2,OFF);
	}
