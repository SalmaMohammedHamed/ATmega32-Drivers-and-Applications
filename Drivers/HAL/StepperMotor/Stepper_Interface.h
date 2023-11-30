/*
 * Stepper_Interface.h
 *
 *  Created on: Sep 23, 2023
 *      Author: salma
 */

#ifndef HAL_STEPPERMOTOR_STEPPER_INTERFACE_H_
#define HAL_STEPPERMOTOR_STEPPER_INTERFACE_H_

#include "Stepper_Config.h"
#include "Stepper_Private.h"
#include "../../Common/STD_Types.h"
#include "../../Common/Bit_Math.h"
#include "../../Common/definition.h"

void STEPPER_voidInit ();
void STEPPER_voidCW(u16 angle); //0111 1011 1101 1110 //full step 0.17578125
void STEPPER_voidACW(u16 angle); //0111 1110 1101 1011

#endif /* HAL_STEPPERMOTOR_STEPPER_INTERFACE_H_ */
