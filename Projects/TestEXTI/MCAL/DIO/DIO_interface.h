#ifndef     DIO_INTERFACE_H
#define     DIO_INTERFACE_H

//Ports Names
#define     DIO_PORTA           0
#define     DIO_PORTB           1
#define     DIO_PORTC           2
#define     DIO_PORTD           3

//Pin Numbers
#define     DIO_PIN0            0
#define     DIO_PIN1            1
#define     DIO_PIN2            2
#define     DIO_PIN3            3
#define     DIO_PIN4            4
#define     DIO_PIN5            5
#define     DIO_PIN6            6
#define     DIO_PIN7            7

//Direction
#define     DIO_INPUT           0
#define     DIO_OUTPUT          1
#define     DIO_IN_PULLUP       2

//Pin Status
#define     DIO_LOW             0
#define     DIO_HIGH            1

void    DIO_SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
void    DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
void    DIO_voidWritePort(u8 Copy_u8Port, u8 Copy_u8PortValue);
void    DIO_voidSetBitsInPort(u8 Copy_u8Port, u8 Copy_u8BitsMask);  
void    DIO_voidClearBitsInPort(u8 Copy_u8Port, u8 Copy_u8BitsMask);
void    DIO_voidWritePin(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinStatus);
u8      DIO_u8ReadPin(u8 Copy_u8Port, u8 Copy_u8Pin);
void    DIO_voidTogglePin(u8 Copy_u8Port, u8 Copy_u8Pin);
void    DIO_voidToggleBitsInPort(u8 Copy_u8Port, u8 Copy_u8BitsMask);

#endif