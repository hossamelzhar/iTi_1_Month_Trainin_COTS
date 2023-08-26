#ifndef     LCD_PRIVATE_H
#define     LCD_PRIVATE_H

#define     LCD_8BIT_2LINES             0x38
#define     LCD_ON_OFF_DISPLAY          0x0C
#define     LCD_CLEAR_DISPLAY           0x01


#define     ROW_0                       0
#define     ROW_1                       1
#define     ROW_1_OFFSET_ADDRESS        64
#define     DDRAM_FIRST_ADDRESS         0X80

static void LCD_voidSendCommand(u8 Copy_u8Command);

#endif