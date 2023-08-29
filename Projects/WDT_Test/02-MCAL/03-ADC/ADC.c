/**********************************************************************************/
/**************		Auther	:	 Ahmed Amr         ********************************/
/**************		SWC  	:	 LCD			   ********************************/
/**************		Date  	:	 8/24/2022         ********************************/
/**************		Version   	:	 V1            ********************************/
/**********************************************************************************/

#include <avr/io.h>

#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"
#include "../01-DIO/DIO.h"
#include "ADC.h"


void ADC_voidInit (void)
{
	/*Enable ADC*/
	SET_BIT(ADCSRA , ADEN);
	
	/*Select V Rer ==> AVCC = 5V */
	SET_BIT (ADMUX , REFS0);
	CLR_BIT (ADMUX , REFS1);
	
	/*Right Adjust*/
	CLR_BIT (ADMUX , ADLAR);
	
	/*Disable Auto Trig*/
	CLR_BIT (ADCSRA , ADATE);
	
	/*Select Prescaler*/
	CLR_BIT (ADCSRA , ADPS0);
	SET_BIT (ADCSRA , ADPS1);
	SET_BIT (ADCSRA , ADPS2);
}
u16  ADC_u16GetDigitalValue (u8 Copy_u8ChannelNum)
{
	/*Select Channel*/
	ADMUX &= ADC_CHANNEL_RESET ;
	ADMUX |= Copy_u8ChannelNum ;
	
	/*Start Conversion*/
	SET_BIT (ADCSRA , ADSC);
	
	/*wait flag = 1*/
	while (GET_BIT(ADCSRA , ADIF) == 0);
	
	/*Clear flag*/
	SET_BIT (ADCSRA , ADIF);
	
	/*Read the digital value*/
	return ADC_REG ;
}
