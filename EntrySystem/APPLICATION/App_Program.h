/*
 * App_Program.h
 *
 *  Created on: Sep 25, 2023
 *      Author: salma
 */

#ifndef APPLICATION_APP_PROGRAM_H_
#define APPLICATION_APP_PROGRAM_H_

#include "../Common/STD_Types.h"
#include "../Common/definition.h"
#include "../HAL/Keypad/Keypad_Interface.h"
#include "../HAL/Lcd/Lcd_Interface.h"
#include "../HAL/DCMotor/DCMotor_Interface.h"
#include "App.Private.h"
#include "App_Config.h"
u8 password_arr[password_len];
u8 scan_password[password_len];
u8 res;
void init ();
void read_password ();
u8 check_password ();
void user_interface();
void pass_arr();

#endif /* APPLICATION_APP_PROGRAM_H_ */
