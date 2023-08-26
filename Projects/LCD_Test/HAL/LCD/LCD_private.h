#ifndef     LCD_PRIVATE_H
#define     LCD_PRIVATE_H

#define     LCD_8BIT_2LINES         0x38
#define     LCD_ON_OFF_DISPLAY      0x0C
#define     LCD_CLEAR_DISPLAY       0x01

static void LCD_voidSendCommand(u8 Copy_u8Command);

#endif