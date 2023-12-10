/*
 * main.c
 *
 *  Created on: Dec 8, 2023
 *      Author: salma
 */
#include "HAL/ServoMotor/ServoMotor_Interface.h"
#include <util/delay.h>
void main ()
{
	ServoMotor_voidInit();
	//ServoMotor_voidSetAngle(45);
	while(1)
	{
		ServoMotor_voidClockWiseSlow(0,180);
		_delay_ms(500);
		ServoMotor_voidAntiClockWiseSlow(180,0);
		_delay_ms(500);
	}

}
