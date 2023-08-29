/**********************************************************************************/
/**************		Auther	:	 Ahmed Amr         ********************************/
/**************		File  	:	 LCD			   ********************************/
/**************		Date  	:	 9/3/2022          ********************************/
/**************		Ver   	:	 V1                ********************************/
/**************		Desc  	:	                   ********************************/
/**********************************************************************************/

#ifndef LCD_H
#define LCD_H

/*MACROS For Used Ports & Pins*/
#define 	LCD_DATA_PORT 			DIO_PORTA
#define 	LCD_CONTROL_PORT 		DIO_PORTB
#define 	RS 						DIO_PIN0
#define 	RW  					DIO_PIN1
#define 	EN  					DIO_PIN2

/*MACROS For LCD Command*/
#define 	LCD_FUNC_SET 			0b00111000
#define 	LCD_ONOF 				0b00001100
#define  	LCD_CLEAR 				0b00000001

/*MACROS For LCD Line*/
#define 	LCD_U8_LINE1 			1
#define 	LCD_U8_LINE2 			2

/*Functions*/

void	 LCD_voidInit			();
void	 LCD_voidSendCommand 	(u8 Copy_U8Command);
void	 LCD_voidSendChar 		(u8 Copy_U8Data);
void	 LCD_voidSendString 		(u8 *Copy_U8String);
void 	 LCD_voidSendNumber(s32 Copy_s32Number);
void 	 LCD_voidSetLocation 	(u8 Copy_U8LineNum , u8 Copy_U8CharNum);
void 	 LCD_voidDrawSpecialChar (u8 Copy_U8CharAddress , u8 *Copy_U8SpecialChar);
void 	 LCD_voidSendSpecialChar(u8 Copy_U8CharAddress , u8 Copy_U8LineNum , u8 Copy_U8CharNum);

#endif
