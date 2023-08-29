/**********************************************************************************/
/**************		Auther	:	 Ahmed Amr         ********************************/
/**************		File  	:	 LCD			   ********************************/
/**************		Date  	:	 9/3/2022          ********************************/
/**************		Ver   	:	 V1                ********************************/
/**************		Desc  	:	                   ********************************/
/**********************************************************************************/

#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

#include "../../02-MCAL/01-DIO/DIO.h"
#include "LCD.h"

#include <util/delay.h>

void LCD_voidSendCommand (u8 Copy_U8Command)
{
	DIO_voidSetPinValue	(LCD_CONTROL_PORT , RS , DIO_LOW);
	DIO_voidSetPinValue	(LCD_CONTROL_PORT , RW , DIO_LOW);
	DIO_voidSetPortValue	(LCD_DATA_PORT , Copy_U8Command);
	DIO_voidSetPinValue	(LCD_CONTROL_PORT , EN , DIO_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue	(LCD_CONTROL_PORT , EN , DIO_LOW);
}


void LCD_voidSendChar    (u8 Copy_U8Char)
{
	DIO_voidSetPinValue(LCD_CONTROL_PORT , RS , DIO_HIGH);
	DIO_voidSetPinValue(LCD_CONTROL_PORT , RW , DIO_LOW);
	DIO_voidSetPortValue(LCD_DATA_PORT , Copy_U8Char);
	DIO_voidSetPinValue(LCD_CONTROL_PORT , EN , DIO_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT , EN , DIO_LOW);
}

void LCD_voidSendString  (u8 *Copy_U8String)
{
	u8 Local_U8Counter ;
	for (Local_U8Counter = 0 ; Copy_U8String[Local_U8Counter] != '\0' ; Local_U8Counter++)
		LCD_voidSendChar(Copy_U8String[Local_U8Counter]);
}

void LCD_voidSendNumber(s32 Copy_s32Number)
{
	u32 Local_u32Counter=1 ;
	u8 Local_u32Digit=0 ;

	/* print (-) if the number is negative */
	if(Copy_s32Number < 0)
	{
		LCD_voidSendChar('-');
		/* return the number to positive */
		Copy_s32Number = -Copy_s32Number;
	}
	if (Copy_s32Number == 0)
		LCD_voidSendChar('0');
	else
	{
		while (Copy_s32Number/Local_u32Counter != 0)
		{
			Local_u32Counter *= 10;
		}
		Local_u32Counter /=10;

		while (Local_u32Counter != 0)
		{
			Local_u32Digit = Copy_s32Number/Local_u32Counter;

			LCD_voidSendChar(Local_u32Digit + '0');

			Copy_s32Number = Copy_s32Number%Local_u32Counter;

			Local_u32Counter /= 10;
		}
	}
}

void LCD_voidSetLocation (u8 Copy_U8LineNum , u8 Copy_U8CharNum)
{
	switch (Copy_U8LineNum)
	{
		case LCD_U8_LINE1 : LCD_voidSendCommand (0x80+Copy_U8CharNum) ; break ;
		
		case LCD_U8_LINE2 : LCD_voidSendCommand (0xc0+Copy_U8CharNum) ; break ;
	}
}

void LCD_voidInit (void )
{
	/*Set Data Port Output*/
	DIO_voidSetPortDirection(LCD_DATA_PORT , 0xff);
	
	/*Set Pins of Control Port Output*/
	DIO_voidSetPinDirection(LCD_CONTROL_PORT , RS , DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT , RW , DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT , EN , DIO_OUTPUT);
	
	/*Waiting after VDD rises to 4.5V*/
	_delay_ms(35);

	/*Function  Set*/
	LCD_voidSendCommand (LCD_FUNC_SET) ;
	_delay_ms(1);
	
	/*ON/OFF Control*/
	LCD_voidSendCommand (LCD_ONOF);
	_delay_ms(1);

	/*Function Clear*/
	LCD_voidSendCommand (LCD_CLEAR);
	_delay_ms(1);

}

void LCD_voidDrawSpecialChar (u8 Copy_U8CharAddress , u8 *Copy_U8SpecialChar)
{
	LCD_voidSendCommand(0b01000000+(Copy_U8CharAddress * 8));
	_delay_us(40);
	u8 LCD_U8Counter ;
	for (LCD_U8Counter=0 ; LCD_U8Counter<8 ; LCD_U8Counter++)
	{
		LCD_voidSendChar(Copy_U8SpecialChar[LCD_U8Counter]);
	}
}

void LCD_voidSendSpecialChar(u8 Copy_U8CharAddress , u8 Copy_U8LineNum , u8 Copy_U8CharNum)
{
	LCD_voidSetLocation(Copy_U8LineNum , Copy_U8CharNum);
	LCD_voidSendChar(Copy_U8CharAddress);
}
