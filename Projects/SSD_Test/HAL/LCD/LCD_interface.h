#ifndef     LCD_INTERFACE_H
#define     LCD_INTERFACE_H




//Link Time Configurations
typedef struct 
{
    u8 DataPort;
    u8 ControlPort;
    u8 RS;
    u8 RW;
    u8 E;
}LCD_t;


void LCD_voidInit(void);
void LCD_voidSendChar(u8 Copy_u8Char);
void LCD_voidClearDispaly(void);
void LCD_voidSetPosition(u8 Copy_u8PosX, u8 Copy_u8PosY);

#endif