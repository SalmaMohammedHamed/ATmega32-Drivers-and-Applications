/*
 * DCMotor_Config.h
 *
 *  Created on: Sep 22, 2023
 *      Author: salma
 */

#ifndef HAL_DCMOTOR_DCMOTOR_CONFIG_H_
#define HAL_DCMOTOR_DCMOTOR_CONFIG_H_

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../Common/Bit_Math.h"
#include "../../Common/STD_Types.h"
#include "../../Common/definition.h"
//connect transistor 1&3 with the down pin of the motor to get the correct directions
#define DCMotorGroup DIO_GroupA
#define DCMotorB1    DIO_Pin3
#define DCMotorB2    DIO_Pin4
#define DCMotorB3    DIO_Pin5
#define DCMotorB4    DIO_Pin6

#endif /* HAL_DCMOTOR_DCMOTOR_CONFIG_H_ */
