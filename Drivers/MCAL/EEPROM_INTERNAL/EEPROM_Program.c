/*
 * EEPROM_Program.cc
 *
 *  Created on: ???/???/????
 *      Author: Mohamed
 */

#include "EEPROM_Interface.h"

void EEPROM_voidWriteByte( u8 Address , u8 data)
{
	while(get_bit(EE_EECR,EE_EECR_EEWE));
	EE_EEARL = Address ;
	EE_EEDR  = data ;
	set_bit(EE_EECR,EE_EECR_EEMWE);
	set_bit(EE_EECR,EE_EECR_EEWE);
}
void EEPROM_voidReadByte( u8 Address , u8* data)
{
	while(get_bit(EE_EECR,EE_EECR_EEWE));
	EE_EEARL = Address ;
	set_bit(EE_EECR,EE_EECR_EERE);
	*data = EE_EEDR ;
}

void EEPROM_voidEraseAll(void)
{
	u16 EEPROM_Add ;
	for(EEPROM_Add = 0 ; EEPROM_Add < Max_Array ; EEPROM_Add++)
	{
		EEPROM_voidWriteByte( EEPROM_Add , 0x00 );
	}
}

void EEPROM_voidEraseByte(u8 Address)
{
	EEPROM_voidWriteByte( Address , 0x00 );
}
