#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"


#include "EXT_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


static void (*INT0FunPtr)(void) = NULL;

void EXTI_voidInterruptEnable(u8 Copy_u8InterruptNumber)
{
    switch (Copy_u8InterruptNumber)
    {
    case EXTI_INT0:
        SET_BIT(GICR, GICR_INT0);
        break;
    case EXTI_INT1:
        SET_BIT(GICR, GICR_INT1);
        break;
    case EXTI_INT2:
        SET_BIT(GICR, GICR_INT2);
        break;
    
    default:
        break;
    }
}
void EXTI_voidInterruptDisable(u8 Copy_u8InterruptNumber)
{
    switch (Copy_u8InterruptNumber)
    {
    case EXTI_INT0:
        CLR_BIT(GICR, GICR_INT0);
        break;
    case EXTI_INT1:
        CLR_BIT(GICR, GICR_INT1);
        break;
    case EXTI_INT2:
        CLR_BIT(GICR, GICR_INT2);
        break;
    
    default:
        break;
    }
}

void EXTI_voidSetTriggerEdge(u8 Copy_u8InterruptNumber, u8 Copy_u8Edge)
{
        switch (Copy_u8InterruptNumber)
    {
    case EXTI_INT0:
        switch (Copy_u8Edge)
        {
            case EXTI_LOW_LEVEL:
                CLR_BIT(MCUCR, MCUCR_ISC00);
                CLR_BIT(MCUCR, MCUCR_ISC01);
                break;
            case EXTI_ANY_CHANGE:
                SET_BIT(MCUCR, MCUCR_ISC00);
                CLR_BIT(MCUCR, MCUCR_ISC01);
                break;
            case EXTI_FALLING_EDGE:
                CLR_BIT(MCUCR, MCUCR_ISC00);
                SET_BIT(MCUCR, MCUCR_ISC01);
                break;
            case EXTI_RISING_EDGE:
                SET_BIT(MCUCR, MCUCR_ISC00);
                SET_BIT(MCUCR, MCUCR_ISC01);
                break;
        
        default:
            break;
        }
        break;
    case EXTI_INT1:
        switch (Copy_u8Edge)
        {
        case EXTI_LOW_LEVEL:
            CLR_BIT(MCUCR, MCUCR_ISC10);
            CLR_BIT(MCUCR, MCUCR_ISC11);
            break;
        case EXTI_ANY_CHANGE:
            SET_BIT(MCUCR, MCUCR_ISC10);
            CLR_BIT(MCUCR, MCUCR_ISC11);
            break;
        case EXTI_FALLING_EDGE:
            CLR_BIT(MCUCR, MCUCR_ISC10);
            SET_BIT(MCUCR, MCUCR_ISC11);
            break;
        case EXTI_RISING_EDGE:
            SET_BIT(MCUCR, MCUCR_ISC10);
            SET_BIT(MCUCR, MCUCR_ISC11);
            break;
        
        default:
            break;
        }
        break;
    case EXTI_INT2:
        switch (Copy_u8Edge)
        {
        case EXTI_FALLING_EDGE:
            CLR_BIT(MCUCSR, MCUCSR_ISC2);
            break;
        case EXTI_RISING_EDGE:
            SET_BIT(MCUCSR, MCUCSR_ISC2);
            break;
        
        default:
            break;
        }
        break;

    default:
        break;
    }
}


u8   EXTI_u8ReadInterruptFlag(u8 Copy_u8InterruptNumber)
{
    u8 Local_u8FlagStatus;

    switch (Copy_u8InterruptNumber)
    {
    case EXTI_INT0:
        Local_u8FlagStatus = GET_BIT(GIFR, GIFR_INTF0);
        break;
    case EXTI_INT1:
        Local_u8FlagStatus = GET_BIT(GIFR, GIFR_INTF1);
        break;
    case EXTI_INT2:
        Local_u8FlagStatus = GET_BIT(GIFR, GIFR_INTF2);
        break;
    
    default:
        break;
    }

    return Local_u8FlagStatus;
}

void EXTI_voidClearInterruptFlag(u8 Copy_u8InterruptNumber)
{
    switch (Copy_u8InterruptNumber)
    {
        case EXTI_INT0:
            SET_BIT(GIFR, GIFR_INTF0);
            break;
        case EXTI_INT1:
            SET_BIT(GIFR, GIFR_INTF1);
            break;
        case EXTI_INT2:
            SET_BIT(GIFR, GIFR_INTF2);
            break;

        default:
            break;
    }
}

void EXTI_voidSetCallBack(u8 Copy_u8InterruptNumber, void (*Notification)(void))
{
    switch (Copy_u8InterruptNumber)
    {
        case EXTI_INT0:
            INT0FunPtr = Notification;
            break;
        case EXTI_INT1:
            
            break;
        case EXTI_INT2:
            
            break;

        default:
            break;
    }
}

//ISR EXTI INT0
ISR(INT0_vect)
{
	//ICU
	//Disable GIE
	
    //CallBackFunction
    if(INT0FunPtr != NULL)
    {
        INT0FunPtr();
    }
    
	//Enable GIE
}
