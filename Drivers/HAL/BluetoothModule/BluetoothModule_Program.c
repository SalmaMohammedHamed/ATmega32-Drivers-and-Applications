/*
 * BluetoothModule_Program.c
 *
 *  Created on: Oct 29, 2023
 *      Author: salma
 */

#include "BluetoothModule_Interface.h"

void BluetoothModule_voidInit()
{
	DIO_voidSetPinDir(UARTGroup,TX,output);
	DIO_voidSetPinDir(UARTGroup,RX,input);
	UART_voidInit(9600);
}

u8 BluetoothModule_u8RecieveData()
{
	return UART_u8RecieveData();
}
