/*
 * SevenSeg_Interface.h
 *
 *  Created on: Sep 12, 2023
 *      Author: salma
 */

#ifndef HAL_SEVEN_SEGEMENT_SEVENSEG_INTERFACE_H_
#define HAL_SEVEN_SEGEMENT_SEVENSEG_INTERFACE_H_
#include "../../Common/Bit_Math.h"
#include "../../Common/STD_Types.h"
#include "../../Common/definition.h"
#include "SevenSeg_Private.h"
#include "SevenSeg_Config.h"
u8 SevSegValue [10];



void SEVSEG_voidInit();
void SEVSEG_voidSetNum(u8 num);
void SEVSEG_voidOff ();


#endif /* HAL_SEVEN_SEGEMENT_SEVENSEG_INTERFACE_H_ */
