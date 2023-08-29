#include <avr/io.h>
#include <avr/interrupt.h>

#include "../01-LIB/STD_TYPES.h"
#include "../01-LIB/BIT_MATH.h"

#include "../02-MCAL/04-TIMERS/02-TIMER1/TIMER1.h"
#include "../02-MCAL/01-DIO/DIO.h"


void ToggleLED(void);

void main(void)
{

	Timer1_voidSetICR1Value(19999);
	Timer1_voidSetOCR1AValue(4999);
	Timer1_voidSetOCR1BValue(4999);

	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN4, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);

	Timer1_voidInit(TIMER1_FAST_MODE_TOP_ICR1, TIMER1_SCALER_8, TIMER1_OC1A_NON_INVERTING, TIMER1_OC1B_INVERTING);

	while(1);

}


void ToggleLED(void)
{
	static u8 Local_u8Counter = 0;

	Local_u8Counter++;

	if(Local_u8Counter == 20)
	{
		DIO_voidTogglePin(DIO_PORTA, DIO_PIN0);
		Local_u8Counter = 0;
	}
}


