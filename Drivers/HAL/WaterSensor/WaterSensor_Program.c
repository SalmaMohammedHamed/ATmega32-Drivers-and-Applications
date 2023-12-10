/*
 * WaterSensor_Program.c
 *
 *  Created on: Dec 7, 2023
 *      Author: salma
 */

#include "WaterSensor_Interface.h"
void WaterSensor_voidInit()
{
	DIO_voidSetPinDir(WaterSensorGroup,WaterSensorPin,Input);
}
void WaterSensor_voidRead(u16 *WaterRead)
{
	ADC_voidReadResultPolling(WaterSensorPin,WaterRead);
	*WaterRead=((u32)(*WaterRead)*ADCRefmV)/DACRes; //convert out equivalent mV
	*WaterRead= (*WaterRead)/10.00;
	}
