/*
 * TouchSensor_Interface.h
 *
 *  Created on: Oct 30, 2023
 *      Author: salma
 */

#ifndef HAL_TOUCHSENSOR_TOUCHSENSOR_INTERFACE_H_
#define HAL_TOUCHSENSOR_TOUCHSENSOR_INTERFACE_H_
#include "TouchSensor_Configration.h"
#include "../../Common/Bit_Math.h"
#include "../../Common/STD_Types.h"
#include "../../Common/definition.h"
void TouchSensor_voidInit (u8 Group, u8 pin);
u8 TouchSensor_u8GetValue (u8 Group, u8 pin);


#endif /* HAL_TOUCHSENSOR_TOUCHSENSOR_INTERFACE_H_ */
