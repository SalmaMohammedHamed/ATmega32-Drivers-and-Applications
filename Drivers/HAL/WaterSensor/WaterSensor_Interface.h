/*
 * WaterSensor_Interface.h
 *
 *  Created on: Dec 7, 2023
 *      Author: salma
 */

#ifndef HAL_WATERSENSOR_WATERSENSOR_INTERFACE_H_
#define HAL_WATERSENSOR_WATERSENSOR_INTERFACE_H_

#include "../../Common/STD_Types.h"
#include "../../Common/Bit_Math.h"
#include "WaterSensor_config.h"

void WaterSensor_voidInit();
void WaterSensor_voidRead(u16 *WaterRead);

#endif /* HAL_WATERSENSOR_WATERSENSOR_INTERFACE_H_ */
