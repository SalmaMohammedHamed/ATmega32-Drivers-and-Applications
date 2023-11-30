/*
 * Stepper_Program.c
 *
 *  Created on: Sep 23, 2023
 *      Author: salma
 */
#include "Stepper_Interface.h"
#include <util/delay.h>

void STEPPER_voidInit ()
{
	DIO_voidSetPinDir(StepperGroup,StepperB1,Output);
	DIO_voidSetPinDir(StepperGroup,StepperB2,Output);
	DIO_voidSetPinDir(StepperGroup,StepperB3,Output);
	DIO_voidSetPinDir(StepperGroup,StepperB4,Output);
}

void STEPPER_voidCW(u16 angle)
{
	u32 NOSteps =(angle/FullStepAngle);
	u16 NOIterations=NOSteps/FUllIteration;
	u16 counter1=0;
	for (counter1=0;counter1<NOIterations;counter1++)
	{
		//step 1
		DIO_voidSetPinValue(StepperGroup,StepperB1,Low);
		DIO_voidSetPinValue(StepperGroup,StepperB2,High);
		DIO_voidSetPinValue(StepperGroup,StepperB3,High);
		DIO_voidSetPinValue(StepperGroup,StepperB4,High);
		_delay_ms(delay);
		//step 2
		DIO_voidSetPinValue(StepperGroup,StepperB1,High);
		DIO_voidSetPinValue(StepperGroup,StepperB2,Low);
		DIO_voidSetPinValue(StepperGroup,StepperB3,High);
		DIO_voidSetPinValue(StepperGroup,StepperB4,High);
		_delay_ms(delay);
		//step 3
		DIO_voidSetPinValue(StepperGroup,StepperB1,High);
		DIO_voidSetPinValue(StepperGroup,StepperB2,High);
		DIO_voidSetPinValue(StepperGroup,StepperB3,Low);
		DIO_voidSetPinValue(StepperGroup,StepperB4,High);
		_delay_ms(delay);
		//step 4
		DIO_voidSetPinValue(StepperGroup,StepperB1,High);
		DIO_voidSetPinValue(StepperGroup,StepperB2,High);
		DIO_voidSetPinValue(StepperGroup,StepperB3,High);
		DIO_voidSetPinValue(StepperGroup,StepperB4,Low);
		_delay_ms(delay);
	}

}

void STEPPER_voidACW(u16 angle)
{

	u16 NOIterations =(angle/FullStepAngle)/FUllIteration;
	u16 counter1=0;
	for (counter1=0;counter1<NOIterations;counter1++)
	{
		//step 1
		DIO_voidSetPinValue(StepperGroup,StepperB1,Low);
		DIO_voidSetPinValue(StepperGroup,StepperB2,High);
		DIO_voidSetPinValue(StepperGroup,StepperB3,High);
		DIO_voidSetPinValue(StepperGroup,StepperB4,High);
		_delay_ms(delay);
		//step 2
		DIO_voidSetPinValue(StepperGroup,StepperB1,High);
		DIO_voidSetPinValue(StepperGroup,StepperB2,High);
		DIO_voidSetPinValue(StepperGroup,StepperB3,High);
		DIO_voidSetPinValue(StepperGroup,StepperB4,Low);
		_delay_ms(delay);
		//step 3
		DIO_voidSetPinValue(StepperGroup,StepperB1,High);
		DIO_voidSetPinValue(StepperGroup,StepperB2,High);
		DIO_voidSetPinValue(StepperGroup,StepperB3,Low);
		DIO_voidSetPinValue(StepperGroup,StepperB4,High);
		_delay_ms(delay);
		//step 4
		DIO_voidSetPinValue(StepperGroup,StepperB1,High);
		DIO_voidSetPinValue(StepperGroup,StepperB2,Low);
		DIO_voidSetPinValue(StepperGroup,StepperB3,High);
		DIO_voidSetPinValue(StepperGroup,StepperB4,High);
		_delay_ms(delay);
	}

}
