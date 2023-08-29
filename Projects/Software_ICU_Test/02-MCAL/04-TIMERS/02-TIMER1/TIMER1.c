/*******************************************************************************************/
/**************		Author 	: Ahmed Amr					************************************/
/**************		SWC 	: TIMER1					************************************/
/**************		Version : Version 1					************************************/
/**************		Date 	: Tue, August 29, 2023	************************************/
/*******************************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>

#include "../../../01-LIB/STD_TYPES.h"
#include "../../../01-LIB/BIT_MATH.h"

#include "TIMER1.h"


static void (*Timer_ptrFunc[4])(void) = {NULL};


void Timer1_voidInit(u8 Copy_u8Mode, u8 Copy_u8Scaler, u8 Copy_u8OC1A, u8 Copy_u8OC1B)
{
    //Select Timer1 Mode
    switch (Copy_u8Mode)
    {
    case TIMER1_NORMAL_MODE:
        CLR_BIT(TCCR1A, WGM10);
        CLR_BIT(TCCR1A, WGM11);
        CLR_BIT(TCCR1B, WGM12);
        CLR_BIT(TCCR1B, WGM13);
        break;
    case TIMER1_CTC_MODE_TOP_OCR1A:
        CLR_BIT(TCCR1A, WGM10);
        CLR_BIT(TCCR1A, WGM11);
        SET_BIT(TCCR1B, WGM12);
        CLR_BIT(TCCR1B, WGM13);
        break;
    case TIMER1_PHASE_CORRECT_MODE_TOP_OCR1A:
        SET_BIT(TCCR1A, WGM10);
        SET_BIT(TCCR1A, WGM11);
        CLR_BIT(TCCR1B, WGM12);
        SET_BIT(TCCR1B, WGM13);
        break;
    case TIMER1_FAST_MODE_TOP_ICR1:
        CLR_BIT(TCCR1A, WGM10);
        SET_BIT(TCCR1A, WGM11);
        SET_BIT(TCCR1B, WGM12);
        SET_BIT(TCCR1B, WGM13);
        break;
    case TIMER1_FAST_MODE_TOP_OCR1A:
        SET_BIT(TCCR1A, WGM10);
        SET_BIT(TCCR1A, WGM11);
        SET_BIT(TCCR1B, WGM12);
        SET_BIT(TCCR1B, WGM13);
        break;
    
    default:
        break;
    }
  
    
    //Config Action OC1A PIN
    CLR_BITS_IN_REG(TCCR1A, OC1A_CLR_MASK);
    SET_BITS_IN_REG(TCCR1A, Copy_u8OC1A);

    //Config Action OC1B PIN
    CLR_BITS_IN_REG(TCCR1A, OC1B_CLR_MASK);
    SET_BITS_IN_REG(TCCR1A, Copy_u8OC1B);

    //Select Clock Source
    //Clear CS12:10
    CLR_BITS_IN_REG(TCCR1B, CLK_SRC_CLR_MASK);
    //Set Clock source
    SET_BITS_IN_REG(TCCR1B, Copy_u8Scaler);
 
}



void Timer1_voidSetPreloadValue(u16 Copy_u16Value)
{
    TCNT1 = Copy_u16Value;
}


u16  Timer1_u16ReadValue(void)
{
    return TCNT1;
}

void Timer1_voidSetOCR1AValue(u16 Copy_u16Value)
{
    OCR1A = Copy_u16Value;
}

void Timer1_voidSetOCR1BValue(u16 Copy_u16Value)
{
    OCR1B = Copy_u16Value;
}

void Timer1_voidSetICR1Value(u16 Copy_u16Value)
{
    ICR1 = Copy_u16Value;
}

void Timer1_voidOVFInterruptEnable(void)
{
    SET_BIT(TIMSK, TOIE1);
}

void Timer1_voidOVFInterruptDisable(void)
{
    CLR_BIT(TIMSK, TOIE1);
}

void Timer1_voidOC1AInterruptEnable(void)
{
    SET_BIT(TIMSK, OCIE1A);
}

void Timer1_voidOC1AInterruptDisable(void)
{
    CLR_BIT(TIMSK, OCIE1A);
}

void Timer1_voidOC1BInterruptEnable(void)
{
    SET_BIT(TIMSK, OCIE1B);
}

void Timer1_voidOC1BInterruptDisable(void)
{
    CLR_BIT(TIMSK, OCIE1B);
}



void Timer1_voidOVFSetCallBack(void (*Copy_pfNotification)(void))
{
    Timer_ptrFunc[0] = Copy_pfNotification;
}

void Timer1_voidOC1ASetCallBack(void (*Copy_pfNotification)(void))
{
    Timer_ptrFunc[1] = Copy_pfNotification;
}

void Timer1_voidOC1BSetCallBack(void (*Copy_pfNotification)(void))
{
    Timer_ptrFunc[2] = Copy_pfNotification;
}

ISR(TIMER1_OVF_vect)
{
    if(Timer_ptrFunc[0] != NULL)
    {
        Timer_ptrFunc[0]();
    }
}

ISR(TIMER1_COMPA_vect)
{
    if(Timer_ptrFunc[1] != NULL)
    {
        Timer_ptrFunc[1]();
    }
}

ISR(TIMER1_COMPB_vect)
{
    if(Timer_ptrFunc[2] != NULL)
    {
        Timer_ptrFunc[2]();
    }
}
