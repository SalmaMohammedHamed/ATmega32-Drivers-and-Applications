/*
 * SevenSeg_Config.h
 *
 *  Created on: Sep 12, 2023
 *      Author: salma
 */

#ifndef HAL_SEVEN_SEGEMENT_SEVENSEG_CONFIG_H_
#define HAL_SEVEN_SEGEMENT_SEVENSEG_CONFIG_H_
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SevenSeg_Private.h"
#define SevSeg1 DIO_GroupA
#define SevSeg2 DIO_GroupB

#define Anode      1
#define Cathod     2
#define SevSegType Anode
#if(SevSegType==Anode)

#define  SEVSEGVALUE \
{                     \
		An_Zero ,     \
		An_One  ,     \
		An_Two  ,     \
		An_Three,     \
		An_Four ,     \
		An_Five ,     \
		An_Sex  ,     \
		An_Seven,     \
		An_Eight,     \
		An_Nine       \
}
#define OFF   An_OFF
#elif (SevSegType===Cathod)
#define  SEVSEGVALUE \
{                     \
		Ca_Zero ,     \
		Ca_One  ,     \
		Ca_Two  ,     \
		Ca_Three,     \
		Ca_Four ,     \
		Ca_Five ,     \
		Ca_Sex  ,     \
		Ca_Seven,     \
		Ca_Eight,     \
		Ca_Nine       \
}
#define OFF   Ca_OFF
#endif



#endif /* HAL_SEVEN_SEGEMENT_SEVENSEG_CONFIG_H_ */
