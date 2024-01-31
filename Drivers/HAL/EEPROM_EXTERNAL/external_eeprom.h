 /******************************************************************************
 *
 * Module: External EEPROM
 *
 * File Name: external_eeprom.h
 *
 * Description: Header file for the External EEPROM Memory
 *
 * Author: Youssef Abuzied
 *
 *******************************************************************************/


#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_

#include "../../Common/STD_Types.h"
#include "../../MCAL/TWI/twi.h"
/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 0
#define SUCCESS 1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

u8 EEPROM_writeByte(u16 u16addr,u8 u8data);
u8 EEPROM_readByte(u16 u16addr,u8 *u8data);
 
#endif /* EXTERNAL_EEPROM_H_ */
