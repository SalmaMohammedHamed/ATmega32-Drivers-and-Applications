/*
 * EEPROM_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */

#ifndef MCAL_EEPROM_INTERNAL_EEPROM_INTERFACE_H_
#define MCAL_EEPROM_INTERNAL_EEPROM_INTERFACE_H_
#include "EEPROM_Private.h"
#include "../../Common/STD_Types.h"
void EEPROM_Write(u16 address,u8 data);
unsigned char EEPROM_Read(u16 address);

#endif /* MCAL_EEPROM_INTERNAL_EEPROM_INTERFACE_H_ */
