/*
 * LM35_Program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: salma
 */

#include "LM35_Interface.h"
#include <util/delay.h>
void LM35_voidInit()
{
	DIO_voidSetPinDir(LM35Group,LM35Pin,Input);
	ADCInformation ADCInformationLM35;
	ADCInformationLM35.AutoTriggerState=LM35_ADC_AutoTriggerState;
	ADCInformationLM35.TriggerSource=LM35_ADC_TriggerSource;
	ADCInformationLM35.DivisionFactor=LM35_ADC_DivisionFactor;
#if LM35Mode==Polling
	ADC_voidInitPolling(ADCInformationLM35);
	_delay_ms(300);
#elif LM35Mode==Interrupt
	ADC_voidInitInterrupt();
#endif
}

void LM35_voidRead(u16 *temp)
{
#if LM35Mode==Polling
	ADC_voidReadResultPolling(LM35Pin,temp);
	*temp=((u32)(*temp)*ADCRefmV)/DACRes; //convert ot equevilant mV
	*temp= (*temp)/10.00;
#elif LM35Mode==Interrupt
#endif
}
