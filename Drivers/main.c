/*
 * main.c
 *
 *  Created on: Sep 15, 2023
 *      Author: salma
 */

#include "MCAL/TWI/twi.h"
#include "HAL/EEPROM_EXTERNAL/external_eeprom.h"
#include "HAL/Lcd/Lcd_Interface.h"
#include "MCAL/EEPROM_INTERNAL/EEPROM_Interface.h"
#include <util/delay.h>
void main()
{

	LCD_voidInit();
	EEPROM_Write(0x00,'B');
	u8 data;
	data=EEPROM_Read(0);
	LCD_voidSendData(data);
	LCD_voidSendData('a');
	while(1)
	{

	}


}



