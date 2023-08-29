#include <avr/io.h>
#include <avr/interrupt.h>

#include "../01-LIB/STD_TYPES.h"
#include "../01-LIB/BIT_MATH.h"

#include "../03-HAL/02-LCD/LCD.h"

#include "../02-MCAL/04-TIMERS/02-TIMER1/TIMER1.h"
#include "../02-MCAL/04-TIMERS/01-TIMER0/TIMER0.h"
#include "../02-MCAL/01-DIO/DIO.h"
#include "../02-MCAL/02-INT/INT.h"

void EXTI_Function(void);

volatile u8  App_u8Flag;
volatile u16 App_u16Time1;
volatile u16 App_u16Time2;
volatile u16 App_u16Time3;
volatile u8 App_u8OnTime;
volatile u8 App_u8OffTime;

void main(void)
{

	LCD_voidInit();

	//Global Interrupt
	sei();

	//PWM Configurations  On Time 64us, period Time 256us
	TIMER0_voidSetOCR0Value(99);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);
	TIMER0_voidInit();

	Timer1_voidInit(TIMER1_NORMAL_MODE, TIMER1_SCALER_8, TIMER1_OC1A_DISCONNECTED, TIMER1_OC1B_DISCONNECTED);
	//EXTI Set Callback
	INT_voidSetCallBack(EXT_INT0, EXTI_Function);
	//Config EXTI, Rising Edge
	//EXTI Enable
	INT_voidEnable(EXT_INT0, INT_RISING_EDGE);


	u16 Period = 0;
	while(1)
	{
		while(App_u8Flag != 3);

		Period = App_u8OffTime + App_u8OnTime;
		LCD_voidSetLocation(1, 0);
		LCD_voidSendString("Period ");
		LCD_voidSendNumber(Period);

		LCD_voidSetLocation(2, 0);
		LCD_voidSendString("T_on ");
		LCD_voidSendNumber(App_u8OnTime);

		App_u8Flag = 0;
		INT_voidEnable(EXT_INT0, INT_RISING_EDGE);

	}

}


void EXTI_Function(void)
{
	if(App_u8Flag == 0)
	{
		App_u16Time1 = Timer1_u16ReadValue();

		//Set EXTI Falling Edge
		INT_voidEnable(EXT_INT0, INT_FALLING_EDGE);
		App_u8Flag = 1;
	}
	else if(App_u8Flag == 1)
	{
		App_u16Time2 = Timer1_u16ReadValue();
		INT_voidEnable(EXT_INT0, INT_RISING_EDGE);
		App_u8OnTime = App_u16Time2 - App_u16Time1;
		App_u8Flag = 2;
	}
	else if(App_u8Flag == 2)
	{
		App_u16Time3 = Timer1_u16ReadValue();
		App_u8OffTime = App_u16Time3 - App_u16Time2;
		INT_voidDisable(EXT_INT0);
		App_u8Flag = 3;
	}

}

