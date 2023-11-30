/*
 * LM35_Config.h
 *
 *  Created on: Oct 22, 2023
 *      Author: salma
 */

#ifndef HAL_LM35_LM35_CONFIG_H_
#define HAL_LM35_LM35_CONFIG_H_
#include "LM35_Private.h"
#include "../../Common/definition.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#define LM35Group DIO_GroupA  //make sure it is a port with adc
#define LM35Pin  DIO_Pin3
#define LM35Mode Polling

#define LM35_ADC_AutoTriggerState OFF
#define LM35_ADC_TriggerSource    OFF
#define LM35_ADC_DivisionFactor   Eight





#endif /* HAL_LM35_LM35_CONFIG_H_ */
