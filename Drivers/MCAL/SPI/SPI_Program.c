 /******************************************************************************
 *
 * Module: SPI
 *
 * File Name: spi.c
 *
 * Description: Source file for the SPI AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "SPI_Interface.h"



void SPI_voidinit(void)
{
#if SPI_InterrptE==disable
	clear_bit(SPI_SPCR,SPCR_SPIE);
#elif SPI_InterrptE==enable
	set_bit(SPI_SPCR,SPCR_SPIE);
#endif

#if SPI_DataOrder==DataorderLSB
	set_bit(SPI_SPCR,SPCR_DORD);
#elif SPI_DataOrder==DataorderMSB
	clear_bit(SPI_SPCR,SPCR_DORD);
#endif


	set_bit(SPI_SPCR,SPCR_SPE);
#if SPI_State==Master
	set_bit(SPI_SPCR,SPCR_MSTR);
#elif SPI_State==Slave
	clear_bit(SPI_SPCR,SPCR_MSTR);
#endif

#if SPI_ClkPolarity==Rising
	clear_bit(SPI_SPCR,SPCR_CPOL);
#elif SPI_ClkPolarity==Falling
	set_bit(SPI_SPCR,SPCR_CPOL);
#endif

#if SPI_ClkPhase==TxRx
	clear_bit(SPI_SPCR,SPCR_CPHA);
#elif SPI_ClkPhase==RxTx
	set_bit(SPI_SPCR,SPCR_CPHA);
#endif


#if SPI_Frequency==F4
	clear_bit(SPI_SPSR,SPSR_SPI2X);
	clear_bit(SPI_SPCR,SPCR_SPR0);
	clear_bit(SPI_SPCR,SPCR_SPR1);
#elif SPI_Frequency==F16
	clear_bit(SPI_SPSR,SPSR_SPI2X);
	set_bit(SPI_SPCR,SPCR_SPR0);
	clear_bit(SPI_SPCR,SPCR_SPR1);
#elif SPI_Frequency==F64
	clear_bit(SPI_SPSR,SPSR_SPI2X);
	clear_bit(SPI_SPCR,SPCR_SPR0);
	set_bit(SPI_SPCR,SPCR_SPR1);
#elif SPI_Frequency==F128
	clear_bit(SPI_SPSR,SPSR_SPI2X);
	set_bit(SPI_SPCR,SPCR_SPR0);
	set_bit(SPI_SPCR,SPCR_SPR1);
#elif SPI_Frequency==F2
	set_bit(SPI_SPSR,SPSR_SPI2X);
	clear_bit(SPI_SPCR,SPCR_SPR0);
	clear_bit(SPI_SPCR,SPCR_SPR1);
#elif SPI_Frequency==F8
	set_bit(SPI_SPSR,SPSR_SPI2X);
	set_bit(SPI_SPCR,SPCR_SPR0);
	clear_bit(SPI_SPCR,SPCR_SPR1);
#elif SPI_Frequency==F32
	set_bit(SPI_SPSR,SPSR_SPI2X);
	clear_bit(SPI_SPCR,SPCR_SPR0);
	set_bit(SPI_SPCR,SPCR_SPR1);
#endif

}




u8 SPI_u8sendReceiveByte(u8 data)
{
	/* Initiate the communication and send data by SPI */
	SPI_SPDR = data;

	/* Wait until SPI interrupt flag SPIF = 1 (data has been sent/received correctly) */
	while(!get_bit(SPI_SPSR,SPSR_SPIF)){}

	/*
	 * Note: SPIF flag is cleared by first reading SPSR (with SPIF set) which is done in the previous step.
	 * and then accessing SPDR like the below line.
	 */
	return SPI_SPDR;
}

/*
 * Description :
 * Send the required string through SPI to the other SPI device.
 */
void SPI_voidsendString(const u8 *str)
{
	u8 i = 0;
	u8 received_data = 0;

	/* Send the whole string */
	while(str[i] != '\0')
	{
		/*
		 * received_data contains the received data from the other device.
		 * It is a dummy data variable as we just need to send the string to other device.
		 */
		received_data = SPI_u8sendReceiveByte(str[i]);
		i++;
	}
}

/*
 * Description :
 * Receive the required string until the '#' symbol through SPI from the other SPI device.
 */
void SPI_voidreceiveString(u8 *str)
{
	u8 i = 0;

	/* Receive the first byte */
	str[i] = SPI_u8sendReceiveByte(SPI_DEFAULT_DATA_VALUE);

	/* Receive the whole string until the '#' */
	while(str[i] != '#')
	{
		i++;
		str[i] = SPI_u8sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	str[i] = '\0';
}
