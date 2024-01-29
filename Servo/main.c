/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include "Common/STD_Types.h"
#include "Common/Bit_Math.h"
#include "Common/definition.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "avr/delay.h"

#define TCCR1A   *((volatile u8*)(0x4F))
#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define FOC1A  3
#define FOC1B  2
#define WGM11  1
#define WGM10  0

#define TCCR1B *((volatile u8*)(0x4E))
#define ICNC1 7
#define ICES1 6
#define WGM13 4
#define WGM12 3
#define CS12  2
#define CS11  1
#define CS10  0

#define TIMSK *((volatile u8*)(0x59))
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2

#define OCR1AH *((volatile u8*)(0x4B))
#define OCR1AL *((volatile u8*)(0x4A))

#define ICR1H *((volatile u8*)(0x47))
#define ICR1L *((volatile u8*)(0x46))

void TIMER1_PWM_INTI (void) ;                                          //to initialize PWM MODE in timer0
void Timer1_VidSETDUTY (u16 duty ) ;                                   //to select specific duty in timer0

void main (){
	DIO_voidSetPinDir(DIO_GroupD,DIO_Pin5,output);
	TIMER1_PWM_INTI();
	while(1){
		for (u16 i =400 ; i<2400 ;i+=5){
			Timer1_VidSETDUTY(i);
			_delay_ms(10);
		}//end for loop
		for (u16 i =2400 ; i>400 ;i-=5){
			Timer1_VidSETDUTY(i);
			_delay_ms(10);
		}//end for loop
	}//end while(1)
}//end main

void TIMER1_PWM_INTI (void){
	//COM1A1/COM1B1 COM1A0/COM1B0  1 0 Clear OC1A/OC1B on compare match, set  OC1A/OC1B at TOP
	TCCR1A = 0b10100000 ;

	/*WGM13 WGM12	WGM11	WGM10	Timer/Counter Mode of Operation TOP Update of OCR1x	TOV1 Flag Set 	on
      1      1       1        0        Fast PWM                      ICR1 TOP TOP*/
	set_bit(TCCR1B,WGM13);
	set_bit(TCCR1B,WGM12);
	set_bit(TCCR1A,WGM11);
	clear_bit(TCCR1A,WGM10);

	//0 1 0 clkI/O/8 (From prescaler)
	clear_bit(TCCR1B,CS12);
	set_bit(TCCR1B,CS11);
	clear_bit(TCCR1B,CS10);

	ICR1H =0b10011000 ;
	ICR1L =0b00100000 ;
}

void Timer1_VidSETDUTY(u16 duty)
{
	OCR1AH = (u8)(duty>>8) ;
	OCR1AL = (u8)duty ;
}

//COM1A1 COM1A0 COM1B1 COM1B0 FOC1A FOC1B WGM11 WGM10 TCCR1A
