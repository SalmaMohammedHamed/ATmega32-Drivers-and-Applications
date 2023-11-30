/*
 * T1_interface.h
 *
 *  Created on: Nov 26, 2023
 *      Author: salma
 */

#ifndef MCAL_TIMER_TIMER1_T1_INTERFACE_H_
#define MCAL_TIMER_TIMER1_T1_INTERFACE_H_
#include "T1_Private.h"
#include "../../../Common/Bit_Math.h"
#include "../../../Common/STD_Types.h"
#include "../../../Common/definition.h"

/************Normal Mode Functions*************/
void T1_voidNormalModeInit(u8 Prescaller,u8 PreloadValue,u8 InterruptState);
void T1_voidCallBackFuncNormalMode(void (*Normalpf)(void));

/*******************CTC Mode functions**************************/
void T1_voidClearTimerModeInit(u8 Prescaller,u8 CompareUnit,u16 CompareValueA,u16 CompareValueB,u8 Interruptstate,u8 OC1AState ,u8 OC1BState);
void T1_voidCallBackFuncCTCModeA(void (*CTCApf)(void));
void T1_voidCallBackFuncCTCModeB(void (*CTCBpf)(void));

/*************************PWM********************************/
void T1_voidFastPWM(u8 Type,u8 CompareUnit ,u8 PWMMode , u8 DutyCycle, u8 PreScaller );

/**********************servo*****************************/
void T1_voidFastPWMServo(u8 angle);

/**************ICU*************************/
void T1_voidCallBackFuncICUMode(void (*ICUpf)(void));
void T1_voidICUInit(void);
#endif /* MCAL_TIMER_TIMER1_T1_INTERFACE_H_ */
