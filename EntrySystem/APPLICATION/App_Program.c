/*
 * App_Program.c
 *
 *  Created on: Sep 25, 2023
 *      Author: salma
 */

#include "App_Program.h"
#include <util/delay.h>
void init ()
{
	KEYPAD_voidInit();
	LCD_voidInit();
	DCMotor_voidInit();
}

void pass_arr()
{
	u32 password_temp=password;
	s8 counter=0;
	for (counter = password_len - 1; counter >= 0; counter--) {
		password_arr[counter] = password_temp % 10;
		password_temp /= 10;
	}
}

void read_password ()
{
	s8 counter=0;
	LCD_voidSetPos(sec_line_pos,0);
	while(1)
	{
		res=KEYPAD_u8GetValue1();
		if (res!=Unpressed)
		{
			scan_password[counter]=res;
			LCD_voidSendData('#');
			_delay_ms(Keypad_delay);
			counter++;
		}
		if(counter>=password_len)
		{
			break;
		}
	}
}

u8 check_password ()
{
	s8 counter=0;
	for (counter=0;counter<password_len;counter++)
	{
		if(scan_password[counter]!=password_arr[counter])
		{
			return wrong;
		}
	}
	return correct;
}
void user_interface ()
{
	pass_arr();   //put the password in an array
	s8 counter=0;
	LCD_voidSetPos(first_line_pos,0);
	LCD_voidSendString("Enter password");
	LCD_voidSetPos(sec_line_pos,0);
	counter=0;
	do
	{
		read_password();
		if (check_password()==correct)
		{
			LCD_voidClear();
			LCD_voidSetPos(first_line_pos,5);
			LCD_voidSendString("HELLO");
			LCD_voidSetPos(sec_line_pos,3);
			LCD_voidSendString("Mr.Hesham");
			DCMotor_voidOnMaxSpeed(clock_wise);
			break;
		}
		else
		{
			LCD_voidClear();
			LCD_voidSetPos(first_line_pos,3);
			LCD_voidSendString("Try again!");
		}
		counter++;
	}while(counter<no_trials);
	if (counter>=no_trials)
	{
		LCD_voidClear();
		LCD_voidSetPos(first_line_pos,4);
		LCD_voidSendString("Wrong");
		u8 customChar[] = {
				0b11011,
				0b11011,
				0b00000,
				0b10001,
				0b11111,
				0b01110,
				0b01110,
				0b00000
		};
		LCD_voidSpecialCharacter(0,customChar,first_line_pos,10);
	}

}

