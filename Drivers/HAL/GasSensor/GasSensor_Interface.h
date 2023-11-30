/*
 * GasSensor_Interface.h
 *
 *  Created on: Oct 26, 2023
 *      Author: salma
 */

#ifndef HAL_GASSENSOR_GASSENSOR_INTERFACE_H_
#define HAL_GASSENSOR_GASSENSOR_INTERFACE_H_

#include "GasSensor_Config.h"
#include "../../Common/STD_Types.h"
#include "../../Common/Bit_Math.h"
#include "../../Common/definition.h"

void GasSensor_voidAnalogInit();
void GasSensor_voidDigitalInit();
void GasSensor_f32ReadAnalog(u16 read);
u8  GasSensor_u8DigitalState();


#endif /* HAL_GASSENSOR_GASSENSOR_INTERFACE_H_ */
