/*
 * main.c
 *
 *  Created on: Sep 15, 2023
 *      Author: hisha
 */
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "HAL/Buzzer/Buzzer_Interface.h"
#include "HAL/Led/Led_Interface.h"
#include "HAL/Switch/Switch_Interface.h"
#include "HAL/Lcd/Lcd_Interface.h"
#include "HAL/LM35/LM35_Interface.h"
#include "HAL/LDR/LDR_Interface.h"
#include "HAL/BluetoothModule/BluetoothModule_Interface.h"
#include <util/delay.h>
void led0 (void);
void led1 (void);
void led2 (void);

void main()
{

	EXTI_voidInitINT0(Falling);
	EXTI_voidInitINT1(Falling);
	EXTI_voidInitINT2(Falling);
	GIE_voidEnable();
	LED_voidInit(DIO_GroupA,DIO_Pin0);
	LED_voidInit(DIO_GroupA,DIO_Pin1);
	LED_voidInit(DIO_GroupA,DIO_Pin2);
	SWITCH_voidInit(DIO_GroupD,DIO_Pin2);
	SWITCH_voidInit(DIO_GroupD,DIO_Pin3);
	SWITCH_voidInit(DIO_GroupB,DIO_Pin2);

	EXTI0_CallBack(led0);
	EXTI1_CallBack(led1);
	EXTI2_CallBack(led2);
	while(1)
	{

	}


}

void led0 (void)
{
	LED_voidToggle(DIO_GroupA,DIO_Pin0);
}

void led1 (void)
{
	LED_voidToggle(DIO_GroupA,DIO_Pin1);
}

void led2 (void)
{
	LED_voidToggle(DIO_GroupA,DIO_Pin2);
}







