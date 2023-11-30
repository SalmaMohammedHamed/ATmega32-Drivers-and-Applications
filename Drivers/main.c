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
//void led ();

void main()
{
	LM35_voidInit();
	LCD_voidInit();
	LDR_voidInit();

u16 temp;
	while(1)
	{
		LM35_voidRead(&temp);
		LCD_voidClear();
		LCD_voidSendNumber(temp);
		_delay_ms(1000);
	}


}

/*void led ()
{
	LED_voidOn(led0_pin);
	}*/










