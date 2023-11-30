/*
 * BluetoothModule_Interface.h
 *
 *  Created on: Oct 29, 2023
 *      Author: salma
 */

#ifndef HAL_BLUETOOTHMODULE_BLUETOOTHMODULE_INTERFACE_H_
#define HAL_BLUETOOTHMODULE_BLUETOOTHMODULE_INTERFACE_H_
#include "../../Common/STD_Types.h"
#include "../../Common/definition.h"
#include "../../MCAL/UART/UART_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"

void BluetoothModule_voidInit();
u8 BluetoothModule_u8RecieveData();

#endif /* HAL_BLUETOOTHMODULE_BLUETOOTHMODULE_INTERFACE_H_ */
