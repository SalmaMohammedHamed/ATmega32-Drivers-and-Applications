 /******************************************************************************
 *
 * Module: TWI(I2C)
 *
 * File Name: twi.h
 *
 * Description: Source file for the TWI(I2C) AVR driver
 *
 * Author: Youssef Abuzeid
 *
 *******************************************************************************/
 
#include "twi.h"
#include "../../Common/Bit_Math.h"


void TWI_init(const TWI_ConfigType * Config_Ptr)
{
    /* Bit Rate: 400.000 kbps using zero pre-scaler TWPS=00 and F_CPU=8Mhz */
    TWI_TWBR = Config_Ptr->bit_rate;
	TWI_TWSR = 0x00;
	
    /* Two Wire Bus address my address if any master device want to call me (used in case this MC is a slave device)
       General Call Recognition: Off */
    TWI_TWAR = ((Config_Ptr->address)<<1);
	
    TWI_TWCR = (1<<TWI_TWCR_TWEN); /* enable TWI */
}

void TWI_start(void)
{
    /* 
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1 
	 */
	TWI_TWCR = (1 << TWI_TWCR_TWINT) | (1 << TWI_TWCR_TWSTA) | (1 << TWI_TWCR_TWEN);
    
    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
    while(!get_bit(TWI_TWCR,TWI_TWCR_TWINT));
}

void TWI_stop(void)
{
    /* 
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1 
	 */
	TWI_TWCR = (1 << TWI_TWCR_TWINT) | (1 << TWI_TWCR_TWSTO) | (1 << TWI_TWCR_TWEN);
}

void TWI_writeByte(u8 data)
{
    /* Put data On TWI data Register */
    TWI_TWDR = data;
    /* 
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */ 
    TWI_TWCR = (1 << TWI_TWCR_TWINT) | (1 << TWI_TWCR_TWEN);
    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
    while(!get_bit(TWI_TWCR,TWI_TWCR_TWINT));
}

u8 TWI_readByteWithACK(void)
{
	/* 
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1 
	 */ 
    TWI_TWCR = (1 << TWI_TWCR_TWINT) | (1 << TWI_TWCR_TWEN) | (1 << TWI_TWCR_TWEA);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(!get_bit(TWI_TWCR,TWI_TWCR_TWINT));
    /* Read Data */
    return TWI_TWDR;
}

u8 TWI_readByteWithNACK(void)
{
	/* 
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */
	TWI_TWCR = (1 << TWI_TWCR_TWINT) | (1 << TWI_TWCR_TWEN);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(!get_bit(TWI_TWCR,TWI_TWCR_TWINT));
    /* Read Data */
    return TWI_TWDR;
}

u8 TWI_getStatus(void)
{
    u8 status;
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    status = TWI_TWSR & 0xF8;
    return status;
}
