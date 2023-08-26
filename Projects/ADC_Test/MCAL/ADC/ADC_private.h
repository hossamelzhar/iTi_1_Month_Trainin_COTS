#ifndef     ADC_PRIVATE_H
#define     ADC_PRIVATE_H


#define     AREF                    0x00
#define     AVCC                    0x01
#define     INTERNAL_2V56           0x03

#define     LEFT_ADJUST_DISABLE         0
#define     LEFT_ADJUST_ENABLE          1

#define     AUTO_TRIGGER_DISABLE        0
#define     AUTO_TRIGGER_ENABLE         1

#define 	INTERRUPT_DISABLE			0
#define 	INTERRUPT_ENABLE			1


#define     SCALER_2                    0x01
#define     SCALER_4                    0x02
#define     SCALER_8                    0x03
#define     SCALER_16                   0x04
#define     SCALER_32                   0x05
#define     SCALER_64                   0x06
#define     SCALER_128                  0x07


#define     CHANNEL_CLEAR_MASK      0x1F

#define     ADC                     (*(volatile u16*) 0x24)
#define     ADCL                    (*(volatile u8*) 0x24)
#define     ADCH                    (*(volatile u8*) 0x25)

#define     ADCSRA                  (*(volatile u8*) 0x26)
#define     ADCSRA_ADPS0            0
#define     ADCSRA_ADPS1            1
#define     ADCSRA_ADPS2            2
#define     ADCSRA_ADIE             3
#define     ADCSRA_ADIF             4
#define     ADCSRA_ADATE            5
#define     ADCSRA_ADSC             6
#define     ADCSRA_ADEN             7

#define     ADMUX                   (*(volatile u8*) 0x27)
#define     ADMUX_MUX0              0
#define     ADMUX_MUX1              1
#define     ADMUX_MUX2              2
#define     ADMUX_MUX3              3
#define     ADMUX_MUX4              4
#define     ADMUX_ADLAR             5
#define     ADMUX_REFS0             6
#define     ADMUX_REFS1             7

#define     ADC_vect        __vector_16


#endif
