#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_Types.h"


#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/GIE/GIE_interface.h"

#define F_CPU	8000000UL
#include <util/delay.h>


void main(void)
{

	u16 Local_u16ADCResult;

	sei();

	ADC_voidInit();

	DIO_SetPortDirection(DIO_PORTB, 0xFF);

	while(1)
	{
		Local_u16ADCResult = ADC_u16ReadAsynchronous(ADC_CH0);
		if(Local_u16ADCResult != RESULT_NOT_READY)
		{
			DIO_voidSetPortValue(DIO_PORTB, Local_u16ADCResult);
		}
		else{}

	}
}
