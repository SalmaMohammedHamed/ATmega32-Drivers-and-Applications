/*
 * WaterSensor_config.h
 *
 *  Created on: Dec 7, 2023
 *      Author: salma
 */

#ifndef HAL_WATERSENSOR_WATERSENSOR_CONFIG_H_
#define HAL_WATERSENSOR_WATERSENSOR_CONFIG_H_

#include "../../Common/definition.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#define WaterSensorGroup DIO_GroupA  //make sure it is a port with adc
#define WaterSensorPin  DIO_Pin7

#endif /* HAL_WATERSENSOR_WATERSENSOR_CONFIG_H_ */
