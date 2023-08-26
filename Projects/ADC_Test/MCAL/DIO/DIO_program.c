#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void    DIO_SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
	 switch (Copy_u8Port)
	  {
		case DIO_PORTA : DDRA = Copy_u8Direction; break;
		case DIO_PORTB : DDRB = Copy_u8Direction; break;
		case DIO_PORTC : DDRC = Copy_u8Direction; break;
		case DIO_PORTD : DDRD = Copy_u8Direction; break;
	  }
}

void    DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
    switch (Copy_u8Port)
    {
    case DIO_PORTA:
        switch (Copy_u8Direction)
        {
        case DIO_INPUT:
            CLR_BIT(DDRA, Copy_u8Pin);
            break;
        case DIO_OUTPUT:
            SET_BIT(DDRA, Copy_u8Pin);
            break;
        case DIO_IN_PULLUP:
            CLR_BIT(DDRA, Copy_u8Pin);
            SET_BIT(PORTA, Copy_u8Pin);
            break;
        default:
                break;
        }
        break;
    case DIO_PORTB:
        switch (Copy_u8Direction)
            {
            case DIO_INPUT:
                CLR_BIT(DDRB, Copy_u8Pin);
                break;
            case DIO_OUTPUT:
                SET_BIT(DDRB, Copy_u8Pin);
                break;
            case DIO_IN_PULLUP:
                CLR_BIT(DDRB, Copy_u8Pin);
                SET_BIT(PORTB, Copy_u8Pin);
                break;
            default:
                break;
            }
            break;
    case DIO_PORTC:
        switch (Copy_u8Direction)
            {
            case DIO_INPUT:
                CLR_BIT(DDRC, Copy_u8Pin);
                break;
            case DIO_OUTPUT:
                SET_BIT(DDRC, Copy_u8Pin);
                break;
            case DIO_IN_PULLUP:
                CLR_BIT(DDRC, Copy_u8Pin);
                SET_BIT(PORTC, Copy_u8Pin);
                break;
            default:
                break;
            }
            break;
    case DIO_PORTD:
        switch (Copy_u8Direction)
            {
            case DIO_INPUT:
                CLR_BIT(DDRD, Copy_u8Pin);
                break;
            case DIO_OUTPUT:
                SET_BIT(DDRD, Copy_u8Pin);
                break;
            case DIO_IN_PULLUP:
                CLR_BIT(DDRD, Copy_u8Pin);
                SET_BIT(PORTD, Copy_u8Pin);
                break;
            default:
                break;
            }
            break;
        
    
    default:
        break;
    }
}

void DIO_voidSetPortValue (u8 Copy_u8Port , u8 Copy_u8Value)
{
	switch (Copy_u8Port)
		{
			case DIO_PORTA : PORTA = Copy_u8Value ; break ;
			case DIO_PORTB : PORTB = Copy_u8Value ; break ;
			case DIO_PORTC : PORTC = Copy_u8Value ; break ;
			case DIO_PORTD : PORTD = Copy_u8Value ; break ;
		}
}

void    DIO_voidWritePin(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinStatus)
{
    switch (Copy_u8Port)
    {
    case DIO_PORTA:
        switch (Copy_u8PinStatus)
        {
        case DIO_LOW:
            CLR_BIT(PORTA, Copy_u8Pin);
            break;
        case DIO_HIGH:
            SET_BIT(PORTA, Copy_u8Pin);
            break;
        
        default:
            break;
        }
        break;
    case DIO_PORTB:
        switch (Copy_u8PinStatus)
        {
        case DIO_LOW:
            CLR_BIT(PORTB, Copy_u8Pin);
            break;
        case DIO_HIGH:
            SET_BIT(PORTB, Copy_u8Pin);
            break;
        
        default:
            break;
        }
        break;
    case DIO_PORTC:
        switch (Copy_u8PinStatus)
        {
        case DIO_LOW:
            CLR_BIT(PORTC, Copy_u8Pin);
            break;
        case DIO_HIGH:
            SET_BIT(PORTC, Copy_u8Pin);
            break;
        
        default:
            break;
        }
        break;
    case DIO_PORTD:
        switch (Copy_u8PinStatus)
        {
        case DIO_LOW:
            CLR_BIT(PORTD, Copy_u8Pin);
            break;
        case DIO_HIGH:
            SET_BIT(PORTD, Copy_u8Pin);
            break;
        
        default:
            break;
        }
        break;
    
    default:
        break;
    }
}

u8      DIO_u8ReadPin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    u8 Local_u8PinStatus;
    
    switch (Copy_u8Port)
    {
    case DIO_PORTA:
        Local_u8PinStatus = GET_BIT(PINA, Copy_u8Pin);
        break;
    case DIO_PORTB:
        Local_u8PinStatus = GET_BIT(PINB, Copy_u8Pin);
        break;
    case DIO_PORTC:
        Local_u8PinStatus = GET_BIT(PINC, Copy_u8Pin);
        break;
    case DIO_PORTD:
        Local_u8PinStatus = GET_BIT(PIND, Copy_u8Pin);
        break;
    
    default:
        break;
    }

    return Local_u8PinStatus;
}


void    DIO_voidTogglePin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    switch (Copy_u8Port)
    {
    case DIO_PORTA:
        TGL_BIT(PORTA, Copy_u8Pin);
        break;
    case DIO_PORTB:
        TGL_BIT(PORTB, Copy_u8Pin);
        break;
    case DIO_PORTC:
        TGL_BIT(PORTC, Copy_u8Pin);
        break;
    case DIO_PORTD:
        TGL_BIT(PORTD, Copy_u8Pin);
        break;
    
    default:
        break;
    }
}
