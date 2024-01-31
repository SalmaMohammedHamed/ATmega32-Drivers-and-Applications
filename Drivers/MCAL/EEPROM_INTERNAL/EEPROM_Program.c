/*
 * EEPROM_Program.cc
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */
#include "EEPROM_Interface.h"
#include "../../Common/Bit_Math.h"

void EEPROM_Write(unsigned short address,unsigned char data)
{
	//set up EEPROM address
	EE_EEARL=(u8)address;
	EE_EEARH=(u8)(address>>8);  //address is 10 bit
	//set up data register
	EE_EEDR=data;
	//enable write operation
	set_bit(EE_EECR,EE_EECR_EEMWE);
	set_bit(EE_EECR,EE_EECR_EEWE);
	//wait until write operation is complete
	while(get_bit(EE_EECR,EE_EECR_EEWE)==0);
}

unsigned char EEPROM_Read(unsigned short address)
{
	//set up EEPROM address
	EE_EEARL=(u8)address;
	EE_EEARH=(u8)(address>>8);  //address is 10 bit
	//enable read operation
	set_bit(EE_EECR,EE_EECR_EERE);
	return EE_EEDR;
}
