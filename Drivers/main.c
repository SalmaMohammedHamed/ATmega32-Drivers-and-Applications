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
#include <util/delay.h>



void main()
{
	LCD_voidInit();
	WaterSensor_voidInit();
	ADC_voidInit();
	u16 Water;
	while(1)
	{
		LCD_voidClear();
		WaterSensor_voidRead(&Water);
		LCD_voidSendNumber(Water);
		_delay_ms(1000);
	}


}






