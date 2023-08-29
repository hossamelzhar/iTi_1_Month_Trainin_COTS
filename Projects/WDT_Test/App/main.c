#include <avr/io.h>
#include <avr/interrupt.h>

#include "../01-LIB/STD_TYPES.h"
#include "../01-LIB/BIT_MATH.h"

#define F_CPU		8000000UL
#include <util/delay.h>
#include "../02-MCAL/WDT/WDT.h"
#include "../02-MCAL/01-DIO/DIO.h"



void main(void)
{
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);

	WDT_voidSleep(WDT_SLEEP_0_52_S);
	WDT_voidEnable();
	DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
	_delay_ms(200);
	DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
	WDT_voidDisable();

	while(1);


}

