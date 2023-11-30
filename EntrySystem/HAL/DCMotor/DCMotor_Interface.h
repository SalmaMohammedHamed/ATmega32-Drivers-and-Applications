/*
 * DCMotor_Interface.h
 *
 *  Created on: Sep 22, 2023
 *      Author: salma
 */

#ifndef HAL_DCMOTOR_DCMOTOR_INTERFACE_H_
#define HAL_DCMOTOR_DCMOTOR_INTERFACE_H_
#include "DCMotor_Config.h"
#include "DCMotor_Private.h"

void DCMotor_voidInit();
void DCMotor_voidOnMaxSpeed(u8 Dir);
void DCMotor_voidOff();
#endif /* HAL_DCMOTOR_DCMOTOR_INTERFACE_H_ */
