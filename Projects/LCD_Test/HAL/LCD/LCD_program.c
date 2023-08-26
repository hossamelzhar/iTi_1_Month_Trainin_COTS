#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

#include "../../MCAL/DIO/DIO_interface.h"

#define     F_CPU       8000000UL
#include <util/delay.h>

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"


void LCD_voidInit(void)
{
    //Configure DIO Pins
    DIO_SetPortDirection(LCD_DATA_PORT, 0xFF);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, RS, DIO_OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, RW, DIO_OUTPUT);
    DIO_voidSetPinDirection(LCD_CONTROL_PORT, E, DIO_OUTPUT);

    //wait 30ms
    _delay_ms(50);

    LCD_voidSendCommand(LCD_8BIT_2LINES);

    //Wait 1ms
    _delay_ms(1);

    LCD_voidSendCommand(LCD_ON_OFF_DISPLAY);

    //Wait 1ms
    _delay_ms(1);

    LCD_voidSendCommand(LCD_ON_OFF_DISPLAY);
}


static void LCD_voidSendCommand(u8 Copy_u8Command)
{
    //RS
    DIO_voidWritePin(LCD_CONTROL_PORT, RS, DIO_LOW);
    //R/W
    DIO_voidWritePin(LCD_CONTROL_PORT, RW, DIO_LOW);

    //D7 .. D0 
    DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Command);

    //Enable Pulse
    DIO_voidWritePin(LCD_CONTROL_PORT, E, DIO_HIGH);
    _delay_ms(2);
    DIO_voidWritePin(LCD_CONTROL_PORT, E, DIO_LOW);
}

void LCD_voidSendChar(u8 Copy_u8Char)
{
     //RS
    DIO_voidWritePin(LCD_CONTROL_PORT, RS, DIO_HIGH);
    //R/W
    DIO_voidWritePin(LCD_CONTROL_PORT, RW, DIO_LOW);

    //D7 .. D0 
    DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Char);

    //Enable Pulse
    DIO_voidWritePin(LCD_CONTROL_PORT, E, DIO_HIGH);
    _delay_ms(2);
    DIO_voidWritePin(LCD_CONTROL_PORT, E, DIO_LOW);
}

void LCD_voidClearDispaly(void)
{
    LCD_voidSendCommand(LCD_CLEAR_DISPLAY);
}

//DDRAM
void LCD_voidSetPosition(u8 Copy_u8PosX, u8 Copy_u8PosY)
{
    u8 Local_u8Address = 0x80;

    if(Copy_u8PosX == 0)
    {
        Local_u8Address += Copy_u8PosY;
        LCD_voidSendCommand(Local_u8Address);
    }
    else if(Copy_u8PosX == 1)
    {
        Local_u8Address += (64 + Copy_u8PosY);
        LCD_voidSendCommand(Local_u8Address);
    }
}