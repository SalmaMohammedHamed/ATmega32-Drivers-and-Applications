/*
 * ADC_Config.h
 *
 *  Created on: Oct 7, 2023
 *      Author: salma
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_
#include "ADC_Private.h"

/*Trigger Sources*/
/*
 * 	FreeRunning
	AnalogComparator
	EXTI0
	TimerCounter0CM
	TimerCounter0OV
	TimerCounter1CM
	TimerCounter1OV
	TimerCounter1CE
 */
#define ReferenceSelect  BothExternal
#define DataAdjustmant   Right



#endif /* MCAL_ADC_ADC_CONFIG_H_ */
