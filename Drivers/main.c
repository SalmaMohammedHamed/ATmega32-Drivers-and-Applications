/*
 * main.c
 *
 *  Created on: Sep 15, 2023
 *      Author: hisha
 */
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/EEPROM_INTERNAL/EEPROM_Interface.h"
#include "HAL/Buzzer/Buzzer_Interface.h"
#include "HAL/Led/Led_Interface.h"
#include "HAL/Switch/Switch_Interface.h"
#include "HAL/Lcd/Lcd_Interface.h"
#include "HAL/LM35/LM35_Interface.h"
#include "HAL/LDR/LDR_Interface.h"
#include "HAL/BluetoothModule/BluetoothModule_Interface.h"
#include "HAL/WaterSensor/WaterSensor_Interface.h"
#include "MCAL/Timers/Timer1/T1_interface.h"
#include "MCAL/Timers/Timer0/T0_Interface.h"
#include <util/delay.h>

void led1 ();
void led2 ();
void main()
{
	DIO_voidSetPinDir(DIO_GroupB,DIO_Pin3,output);
	LED_voidInit(DIO_GroupA,DIO_Pin0);
	LED_voidInit(DIO_GroupA,DIO_Pin1);
	T0_voidCallBackFuncNormalMode(led1);
	T1_voidCallBackFuncNormalMode(led2);
	T0_voidCTCModeInit(CTC_OC0_Tog,prescaler8,100,enable);
	//T0_voidPWMModeInit(FastPWM,PWM_OC0_nonInverting,prescaler8,50);
	//T1_voidFastPWMFixedTop(FastPWM_8Bit,prescaler8,NonInverting,75);
	T1_voidNormalModeInit(prescaler8,0,enable);
	GIE_voidEnable();
	while(1)
	{

	}


}


void led1 ()
{
	static u32 couter=0;
	if (couter%2000==0)
	{
		LED_voidToggle(DIO_GroupA,DIO_Pin0);
	}
	couter++;
}

void led2 ()
{
	static u32 couter2=0;
	if (couter2%20==0)
	{
		LED_voidToggle(DIO_GroupA,DIO_Pin1);
	}
	couter2++;
}

