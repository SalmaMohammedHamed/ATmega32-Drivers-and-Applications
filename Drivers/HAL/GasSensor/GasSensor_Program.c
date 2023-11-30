/*
 * GasSensor_Program.c
 *
 *  Created on: Oct 26, 2023
 *      Author: salma
 */

#include "GasSensor_Interface.h"

void GasSensor_voidAnalogInit()
{
	DIO_voidSetPinDir(GasSensorGroup,GasSensorPin,Input);
	ADCInformation ADCInformationGasSensor;
	ADCInformationGasSensor.AutoTriggerState=GasSensor_ADC_AutoTriggerState;
	ADCInformationGasSensor.TriggerSource=GasSensor_ADC_TriggerSource;
	ADCInformationGasSensor.DivisionFactor=GasSensor_ADC_DivisionFactor;
#if GasSensorMode==Polling
	ADC_voidInitPolling(ADCInformationGasSensor);
#elif GasSensorMode==Interrupt
	ADC_voidInitInterrupt();
#endif
}

void GasSensor_voidDigitalInit()
{
	DIO_voidSetPinDir(GasSensorGroup,GasSensorPin,Input);
}

void GasSensor_f32ReadAnalog(u16 read)
{


}

u8 GasSensor_u8DigitalState()
{
	return DIO_u8ReadPinValue(GasSensorGroup,GasSensorPin);
}
