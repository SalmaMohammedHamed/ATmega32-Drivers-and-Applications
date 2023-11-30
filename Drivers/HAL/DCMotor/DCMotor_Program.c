/*
 * DCMotor_Program.c
 *
 *  Created on: Sep 22, 2023
 *      Author: salma
 */

#include "DCMotor_Interface.h"


void DCMotor_voidInit()
{
	DIO_voidSetPinDir(DCMotorGroup,DCMotorB1,Output);
	DIO_voidSetPinDir(DCMotorGroup,DCMotorB2,Output);
	DIO_voidSetPinDir(DCMotorGroup,DCMotorB3,Output);
	DIO_voidSetPinDir(DCMotorGroup,DCMotorB4,Output);
}

void DCMotor_voidOnMaxSpeed(u8 Dir)
{
	if (Dir==clock_wise)
	{
		DIO_voidSetPinValue(DCMotorGroup,DCMotorB1,High);
		DIO_voidSetPinValue(DCMotorGroup,DCMotorB4,High);
		DIO_voidSetPinValue(DCMotorGroup,DCMotorB2,Low);
		DIO_voidSetPinValue(DCMotorGroup,DCMotorB3,Low);
	}
	else if(Dir==anti_clock_wise)
	{
		DIO_voidSetPinValue(DCMotorGroup,DCMotorB1,Low);
		DIO_voidSetPinValue(DCMotorGroup,DCMotorB4,Low);
		DIO_voidSetPinValue(DCMotorGroup,DCMotorB2,High);
		DIO_voidSetPinValue(DCMotorGroup,DCMotorB3,High);
	}
}

void DCMotor_voidOff()
{
	DIO_voidSetPinValue(DCMotorGroup,DCMotorB1,Low);
	DIO_voidSetPinValue(DCMotorGroup,DCMotorB4,Low);
	DIO_voidSetPinValue(DCMotorGroup,DCMotorB2,Low);
	DIO_voidSetPinValue(DCMotorGroup,DCMotorB3,Low);
}
