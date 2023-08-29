/**********************************************************************************/
/**************		Auther	:	 Ahmed Amr         ********************************/
/**************		SWC  	:	 LCD			   ********************************/
/**************		Date  	:	 8/24/2022         ********************************/
/**************		Version   	:	 V1            ********************************/
/**********************************************************************************/

#ifndef		ADC_H
#define		ADC_H

#define		ADC_REG				*((volatile u16*)0x24)

#define		ADC_CHANNEL_RESET	0b11100000

#define		ADC_CHANNEL0		0
#define		ADC_CHANNEL1		1
#define		ADC_CHANNEL2		2
#define		ADC_CHANNEL3		3
#define		ADC_CHANNEL4		4
#define		ADC_CHANNEL5		5
#define		ADC_CHANNEL6		6
#define		ADC_CHANNEL7		7

void ADC_voidInit (void);
u16  ADC_u16GetDigitalValue (u8 Copy_u8ChannelNum);

#endif