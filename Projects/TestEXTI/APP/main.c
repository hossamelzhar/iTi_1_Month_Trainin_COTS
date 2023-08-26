#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_Types.h"


#include "../MCAL/EXTI/EXT_interface.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/GIE/GIE_interface.h"

void ToggleLED(void);

volatile u8 App_Counter = 0;

void main(void)
{
	//Enable Global Interrupt  GIE
	//sei(); //Assembly
	GIE_voidEnable();

	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN2, DIO_IN_PULLUP);
	//Set Sense Control
	EXTI_voidSetTriggerEdge(EXTI_INT0, EXTI_FALLING_EDGE);
	//Set Callback
	EXTI_voidSetCallBack(EXTI_INT0, ToggleLED);
	//Enable INT0 PIE
	EXTI_voidInterruptEnable(EXTI_INT0);
	//Configure PinA0
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);

	while(1)
	{
		//while(EXTI_u8ReadInterruptFlag(EXTI_INT0) == 0);
		//EXTI_voidClearInterruptFlag(EXTI_INT0);
		//DIO_voidTogglePin(DIO_PORTA, DIO_PIN0);

		if(App_Counter == 5)
		{
			GIE_voidDisable();
		}

	}
}


void ToggleLED(void)
{
	DIO_voidTogglePin(DIO_PORTA, DIO_PIN0);
	App_Counter++;
}
