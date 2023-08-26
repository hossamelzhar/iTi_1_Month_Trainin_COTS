#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

#include "../GIE/GIE_interface.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


volatile u8 ADC_u8Flag = 0;

void ADC_voidInit(void)
{
    //Vlotage Reference
#if VREF == AREF
    CLR_BIT(ADMUX, ADMUX_REFS0);
    CLR_BIT(ADMUX, ADMUX_REFS1);
#elif VREF == AVCC
    SET_BIT(ADMUX, ADMUX_REFS0);
    CLR_BIT(ADMUX, ADMUX_REFS1);
#elif VREF == INTERNAL_2V56
    SET_BIT(ADMUX, ADMUX_REFS0);
    SET_BIT(ADMUX, ADMUX_REFS1);
#else
    #warning  VREF Configrations Error
#endif

    //Left Adjust
#if     LEFT_ADJUST_STATUS == LEFT_ADJUST_DISABLE
    CLR_BIT(ADMUX, ADMUX_ADLAR);
#elif   LEFT_ADJUST_STATUS == LEFT_ADJUST_ENABLE
    SET_BIT(ADMUX, ADMUX_ADLAR);
#else
    #warning LEFT_ADJUST_STATUS Config error

#endif

#if         AUTO_TRIGGER_STATUS == AUTO_TRIGGER_DISABLE
    CLR_BIT(ADCSRA, ADCSRA_ADATE);
#elif       AUTO_TRIGGER_STATUS == AUTO_TRIGGER_ENABLE
    SET_BIT(ADCSRA, ADCSRA_ADATE);
#else
    #warning AUTO_TRIGGER_STATUS Config error
#endif

#if         INTERRUPT_STATUS == INTERRUPT_DISABLE
    CLR_BIT(ADCSRA, ADCSRA_ADIE);
#elif         INTERRUPT_STATUS == INTERRUPT_ENABLE
    SET_BIT(ADCSRA, ADCSRA_ADIE);
#else 
    #warning INTERRUPT_STATUS Config error
#endif

    //Prescaler select
    CLR_BITS_REG(ADCSRA, 0x07);
    SET_BITS_REG(ADCSRA, PRESCALER_SELECT);

#if     ADC_STATUS == ADC_ENABLE
    SET_BIT(ADCSRA, ADCSRA_ADEN);
#elif     ADC_STATUS == ADC_DISABLE
    CLR_BIT(ADCSRA, ADCSRA_ADEN);
#else 
    #warning ADC_STATUS Config error
#endif

}


u8   ADC_u8ReadSynchronous(u8 Copy_u8ChannelNumber)
{
    u8 Local_u8ADCResult;
    //Select channel
    CLR_BITS_REG(ADMUX, CHANNEL_CLEAR_MASK);
    SET_BITS_REG(ADMUX, Copy_u8ChannelNumber);

    //Start Coversion
    SET_BIT(ADCSRA, ADCSRA_ADSC);

    //Wait untill conversion finish
    while(GET_BIT(ADCSRA, ADCSRA_ADIF) == 0);

    //Clear Flag
    SET_BIT(ADCSRA, ADCSRA_ADIF);

#if     LEFT_ADJUST_STATUS == LEFT_ADJUST_DISABLE
    Local_u8ADCResult = ADCL;//ADCL
#elif   LEFT_ADJUST_STATUS == LEFT_ADJUST_ENABLE
    Local_u8ADCResult = ADCH;
#endif

    return Local_u8ADCResult;
}

u16  ADC_u16ReadSynchronous(u8 Copy_u8ChannelNumber)
{
    u16 Local_u16ADCResult;
    //Select channel
    CLR_BITS_REG(ADMUX, CHANNEL_CLEAR_MASK);
    SET_BITS_REG(ADMUX, Copy_u8ChannelNumber);

    //Start Coversion
    SET_BIT(ADCSRA, ADCSRA_ADSC);

    //Wait untill conversion finish
    while(GET_BIT(ADCSRA, ADCSRA_ADIF) == 0);

    //Clear Flag
    SET_BIT(ADCSRA, ADCSRA_ADIF);

    Local_u16ADCResult = ADC;

    return Local_u16ADCResult;
}


u16  ADC_u16ReadAsynchronous(u8 Copy_u8ChannelNumber)
{
    static u8 Local_u8Flag = 0;
    u16 Local_u16ADCResult = RESULT_NOT_READY;

    if(Local_u8Flag == 0)
    {
        //Select channel
        CLR_BITS_REG(ADMUX, CHANNEL_CLEAR_MASK);
        SET_BITS_REG(ADMUX, Copy_u8ChannelNumber);

        //Start Coversion
        SET_BIT(ADCSRA, ADCSRA_ADSC);

        Local_u8Flag = 1;
    }
    else{}//MISRA C

    if(ADC_u8Flag == 1)
    {
        Local_u16ADCResult = ADC;
        ADC_u8Flag = 0;
        Local_u8Flag = 0;
    }
    else{}//MISRA C

    return Local_u16ADCResult;
}


ISR(ADC_vect)
{
    ADC_u8Flag = 1;
}
