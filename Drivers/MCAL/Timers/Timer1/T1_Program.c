/*
 * T0_Program.c
 *
 *  Created on: Nov 25, 2023
 *      Author:Salma
 */
#include "T1_interface.h"




/****************************Pointers to ISR functions************************************/
static void(*GlobalICUPf)(void)=NULL;
static void(*GlobalOVPf)(void)=NULL;
static void(*GlobalCTCAPf)(void)=NULL;
static void(*GlobalCTCBPf)(void)=NULL;
/***************************************************************************************/



/*******************************Normal Mode Functions*******************************************/
void T1_voidNormalModeInit(u8 Prescaller,u8 PreloadValue,u8 InterruptState)
{
	//select mode
	clear_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
	clear_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
	clear_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
	clear_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
	//Prescaller
	Prescaller&=0x07;
	T1_TCCR1B&=0xF8;
	T1_TCCR1B|=Prescaller;
	T1_TCNT1=PreloadValue;
	if(InterruptState ==enable)
	{
		set_bit(T1_TIMSK,T1_TIMSK_TOIE1);
	}
	else if(InterruptState ==disable)
	{
		clear_bit(T1_TIMSK,T1_TIMSK_TOIE1);
	}

}


void T1_voidCallBackFuncNormalMode(void (*Normalpf)(void))
{
	if(Normalpf!=NULL)
	{
		GlobalOVPf=Normalpf;
	}
}


void __vector_9(void)   __attribute__((signal));
void __vector_9(void)
{

	if (GlobalOVPf!=NULL)
	{
		GlobalOVPf();
	}

}
/***************************************************************************/





/********************************CTC Functions****************************************************/
void T1_voidClearTimerModeInit(u8 Prescaller,u8 CompareUnit,u16 CompareValueA,u16 CompareValueB,u8 Interruptstate,u8 OC1AState ,u8 OC1BState)
{
	//select mode
	clear_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
	clear_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
	set_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
	set_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
	//TCCR1A
	if (CompareUnit==CTC_UnitA)
	{
		T1_OCR1A=CompareValueA;
		if (Interruptstate==enable)
		{
			set_bit(T1_TIMSK,T1_TIMSK_OCIE1A);
		}
		else if (Interruptstate==disable)
		{
			clear_bit(T1_TIMSK,T1_TIMSK_OCIE1A);
		}
		if(OC1AState==CTC_OC1A_Disconnect)
		{//disconnect  pin OC0
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
		}
		else if (OC1AState==CTC_OC1A_Tog)
		{	//Tog Pin OC0
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
		}
		else if (OC1AState==CTC_OC1A_CLr)
		{
			//clr Pin OC0
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
		}
		else if (OC1AState==CTC_OC1A_Set)
		{
			//set Pin OC0
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
		}
	}
	else if (CompareUnit==CTC_UnitB)
	{
		T1_OCR1B=CompareValueB;
		if (Interruptstate==enable)
		{
			set_bit(T1_TIMSK,T1_TIMSK_OCIE1B);
		}
		else if (Interruptstate==disable)
		{
			clear_bit(T1_TIMSK,T1_TIMSK_OCIE1B);
		}
		if(OC1BState==CTC_OC1B_Disconnect)
		{//disconnect  pin OC0
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1B0);
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1B1);
		}
		else if (OC1BState==CTC_OC1B_Tog)
		{	//Tog Pin OC0
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1B0);
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1B1);
		}
		else if (OC1BState==CTC_OC1B_CLr)
		{
			//clr Pin OC0
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1B0);
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1B1);
		}
		else if (OC1BState==CTC_OC1B_Set)
		{
			//set Pin OC0
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1B0);
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1B1);
		}
	}
	else if (CompareUnit==CTC_BothUnits)
	{
		T1_OCR1A=CompareValueA;
		T1_OCR1B=CompareValueB;
		if (Interruptstate==enable)
		{
			set_bit(T1_TIMSK,T1_TIMSK_OCIE1A);
			set_bit(T1_TIMSK,T1_TIMSK_OCIE1B);
		}
		else if (Interruptstate==disable)
		{
			clear_bit(T1_TIMSK,T1_TIMSK_OCIE1A);
			clear_bit(T1_TIMSK,T1_TIMSK_OCIE1B);
		}
		if(OC1AState==CTC_OC1A_Disconnect)
		{//disconnect  pin OC0
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
		}
		else if (OC1AState==CTC_OC1A_Tog)
		{	//Tog Pin OC0
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
		}
		else if (OC1AState==CTC_OC1A_CLr)
		{
			//clr Pin OC0
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
		}
		else if (OC1AState==CTC_OC1A_Set)
		{
			//set Pin OC0
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
		}
		if(OC1BState==CTC_OC1B_Disconnect)
				{//disconnect  pin OC0
					clear_bit(T1_TCCR1A,T1_TCCR1A_COM1B0);
					clear_bit(T1_TCCR1A,T1_TCCR1A_COM1B1);
				}
				else if (OC1BState==CTC_OC1B_Tog)
				{	//Tog Pin OC0
					set_bit(T1_TCCR1A,T1_TCCR1A_COM1B0);
					clear_bit(T1_TCCR1A,T1_TCCR1A_COM1B1);
				}
				else if (OC1BState==CTC_OC1B_CLr)
				{
					//clr Pin OC0
					clear_bit(T1_TCCR1A,T1_TCCR1A_COM1B0);
					set_bit(T1_TCCR1A,T1_TCCR1A_COM1B1);
				}
				else if (OC1BState==CTC_OC1B_Set)
				{
					//set Pin OC0
					set_bit(T1_TCCR1A,T1_TCCR1A_COM1B0);
					set_bit(T1_TCCR1A,T1_TCCR1A_COM1B1);
				}
	}
	Prescaller&=0x07;
	T1_TCCR1B&=0xF8;
	T1_TCCR1B|=Prescaller;
}


void T1_voidCallBackFuncCTCModeA(void (*CTCApf)(void))
{
	if(CTCApf!=NULL)
	{
		GlobalCTCAPf=CTCApf;
	}
}


void __vector_7(void)   __attribute__((signal));
void __vector_7(void)
{

	if (GlobalCTCAPf!=NULL)
	{
		GlobalCTCAPf();
	}
}


void T1_voidCallBackFuncCTCModeB(void (*CTCBpf)(void))
{
	if(CTCBpf!=NULL)
	{
		GlobalCTCBPf=CTCBpf;
	}
}


void __vector_8(void)   __attribute__((signal));
void __vector_8(void)
{

	if (GlobalCTCBPf!=NULL)
	{
		GlobalCTCBPf();
	}
}
/************************************************************************************/




/*******************************Fast PWM*********************************/
void T1_voidFastPWM(u8 Type,u8 CompareUnit ,u8 PWMMode , u8 DutyCycle, u8 PreScaller )
{
	//prescaller
	PreScaller&=0x07;
	T1_TCCR1B&=0xF8;
	T1_TCCR1B|=PreScaller;
	//select mode
	if (Type==FastPWM_8Bit)
	{
		set_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
		clear_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
		set_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
		clear_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
	}
	else if (Type==FastPWM_9Bit)
	{
		clear_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
		set_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
		set_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
		clear_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
	}
	else if (Type==FastPWM_10Bit)
	{
		set_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
		set_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
		set_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
		clear_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
	}
	else if (Type==FastPWM_ICR1)
	{
		clear_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
		set_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
		set_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
		set_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
	}
	else if (Type==FastPWM_OCR1A)
	{
		set_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
		set_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
		set_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
		set_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
	}

	//select compare unit & mode
	if (CompareUnit==PWM_UnitA)
	{
		T1_OCR1A=(65535*DutyCycle)/100;
		if (PWMMode==PWM_OC1A_Disconnect)
		{
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
		}
		else if (PWMMode==PWM_OC1A_Tog)
		{
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
		}
		else if (PWMMode==PWM_OC1A_CLr)
		{
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
		}
		else if (PWMMode==PWM_OC1A_Set)
		{
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1A0);
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1A1);
		}
	}
	if (CompareUnit==PWM_UnitB)
	{
		T1_OCR1B=(65535*DutyCycle)/100;
		if (PWMMode==PWM_OC1B_Disconnect)
		{
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1B0);
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1B1);
		}
		else if (PWMMode==PWM_OC1B_Tog)
		{
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1B0);
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1B1);
		}
		else if (PWMMode==PWM_OC1B_CLr)
		{
			clear_bit(T1_TCCR1A,T1_TCCR1A_COM1B0);
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1B1);
		}
		else if (PWMMode==PWM_OC1B_Set)
		{
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1B0);
			set_bit(T1_TCCR1A,T1_TCCR1A_COM1B1);
		}
	}

}
/**************************************************************************/





/****************************Servo Functions*************************/
void T1_voidFastPWMServo(u8 angle)
{
	u8 Prescaller=prescaler8;
	Prescaller&=0x07;
	T1_TCCR1B&=0xF8;
	T1_TCCR1B|=Prescaller;
	//select mode 14 (ICR1)
	clear_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
	set_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
	set_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
	set_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
	//Set the Top Value
	T1_ICR1=Servo_value;

	//set the angle
	T1_OCR1A=angle;
}
/******************************************************************/





/***********************ICU functions*******************************/
void T1_voidICUInit(void)
{
	u8 Prescaller=prescaler8;
	//NormalMode
	clear_bit(T1_TCCR1A,T1_TCCR1A_WGM10);
	clear_bit(T1_TCCR1A,T1_TCCR1A_WGM11);
	clear_bit(T1_TCCR1B,T1_TCCR1B_WGM12);
	clear_bit(T1_TCCR1B,T1_TCCR1B_WGM13);
	//Prescaller
	Prescaller&=0x07;
	T1_TCCR1B&=0xF8;
	T1_TCCR1B|=Prescaller;
	//Set ICU Bit to Rising
	set_bit(T1_TCCR1B,T1_TCCR1B_ICES1);
	//Enable ICU Interrupt
	set_bit(T1_TIMSK,T1_TIMSK_TICIE1);
	}


void T1_voidCallBackFuncICUMode(void (*ICUpf)(void))
{
	if(ICUpf!=NULL)
	{
		GlobalICUPf=ICUpf;
	}
}


void __vector_6(void)   __attribute__((signal));
void __vector_6(void)
{

	if (GlobalICUPf!=NULL)
	{
		GlobalICUPf();
	}

}
/*********************************************************************/

