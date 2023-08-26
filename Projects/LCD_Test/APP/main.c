#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_Types.h"

#include "../HAL/LCD/LCD_interface.h"
#include "../MCAL/DIO/DIO_interface.h"

#define F_CPU		8000000UL
#include <util/delay.h>

void main(void)
{

	LCD_voidInit();
	//LCD_voidInit(&LCD2);


	while(1)
	{
		LCD_voidSetPosition(0, 0);
		LCD_voidSendChar('H');
		LCD_voidSetPosition(1, 2);
		LCD_voidSendChar('O');
		LCD_voidSetPosition(0, 4);
		LCD_voidSendChar('S');
		LCD_voidSetPosition(1, 6);
		LCD_voidSendChar('S');
		LCD_voidSetPosition(0, 8);
		LCD_voidSendChar('A');
		LCD_voidSetPosition(1, 10);
		LCD_voidSendChar('M');
		_delay_ms(200);
		LCD_voidClearDispaly();
		LCD_voidSetPosition(1, 0);
		LCD_voidSendChar('H');
		LCD_voidSetPosition(0, 2);
		LCD_voidSendChar('O');
		LCD_voidSetPosition(1, 4);
		LCD_voidSendChar('S');
		LCD_voidSetPosition(0, 6);
		LCD_voidSendChar('S');
		LCD_voidSetPosition(1, 8);
		LCD_voidSendChar('A');
		LCD_voidSetPosition(0, 10);
		LCD_voidSendChar('M');
		_delay_ms(200);
		LCD_voidClearDispaly();
	}
}
