#ifndef     ADC_INTERFACE_H
#define     ADC_INTERFACE_H

#define     ADC_CH0             0
#define     ADC_CH1             1
#define     ADC_CH2             2
#define     ADC_CH3             3
#define     ADC_CH4             4
#define     ADC_CH5             5
#define     ADC_CH6             6
#define     ADC_CH7             7

#define     RESULT_NOT_READY    0xFFFF

void ADC_Init(void);
u8   ADC_u8ReadSynchronous(u8 Copy_u8ChannelNumber);
u16  ADC_u16ReadSynchronous(u8 Copy_u8ChannelNumber);
u16  ADC_u16ReadAsynchronous(u8 Copy_u8ChannelNumber);


#endif