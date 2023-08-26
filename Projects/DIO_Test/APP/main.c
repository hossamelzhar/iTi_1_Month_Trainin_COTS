#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_Types.h"


#include "../MCAL/DIO/DIO_interface.h"

#define 	F_CPU		8000000UL
#include <util/delay.h>



void main(void)
{
	u8 Local_u8Counter = 0;

	//Pin Dir
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN4, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC, DIO_PIN5, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN7, DIO_OUTPUT);

	DIO_voidSetPinDirection(DIO_PORTC, DIO_PIN0, DIO_IN_PULLUP);

	DIO_voidWritePin(DIO_PORTA, DIO_PIN0, DIO_HIGH);
	DIO_voidWritePin(DIO_PORTB, DIO_PIN4, DIO_HIGH);
	DIO_voidWritePin(DIO_PORTC, DIO_PIN5, DIO_HIGH);
	DIO_voidWritePin(DIO_PORTD, DIO_PIN7, DIO_HIGH);

	while(1)
	{
		if(DIO_u8ReadPin(DIO_PORTC, DIO_PIN0) == 0)
		{
			while(DIO_u8ReadPin(DIO_PORTC, DIO_PIN0) == 0);
			
			DIO_voidTogglePin(DIO_PORTA, DIO_PIN0);
			DIO_voidTogglePin(DIO_PORTB, DIO_PIN4);
			DIO_voidTogglePin(DIO_PORTC, DIO_PIN5);
			DIO_voidTogglePin(DIO_PORTD, DIO_PIN7);

			
		}else{}

	}
}
