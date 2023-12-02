/*
 * TouchSensor_Program.c
 *
 *  Created on: Oct 30, 2023
 *      Author: salma
 */

#include "TouchSensor_Interface.h"

void TouchSensor_voidInit (u8 Group, u8 pin)
{
	DIO_voidSetPinDir(Group,pin,input);
}

u8 TouchSensor_u8GetValue (u8 Group, u8 pin)
{
	u8 TouchSensorState;
	TouchSensorState=DIO_u8ReadPinValue(Group,pin);
	return TouchSensorState;
}
