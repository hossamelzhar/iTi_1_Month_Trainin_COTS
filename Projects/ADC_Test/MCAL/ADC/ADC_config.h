#ifndef     ADC_CONFIG_H
#define     ADC_CONFIG_H


/*Options:
        AREF         
        AVCC         
        INTERNAL_2V56
*/
#define     VREF        AVCC


/*Options:
        LEFT_ADJUST_DISABLE
        LEFT_ADJUST_ENABLE 
*/
#define     LEFT_ADJUST_STATUS     LEFT_ADJUST_DISABLE 

/*Options:
        AUTO_TRIGGER_DISABLE
        AUTO_TRIGGER_ENABLE 
*/
#define     AUTO_TRIGGER_STATUS     AUTO_TRIGGER_DISABLE

/*Options:
        INTERRUPT_DISABLE
        INTERRUPT_ENABLE 
*/
#define     INTERRUPT_STATUS        INTERRUPT_ENABLE

/*Options:
        SCALER_2
        SCALER_4
        SCALER_8
        SCALER_16
        SCALER_32
        SCALER_64
        SCALER_128
*/
#define     PRESCALER_SELECT        SCALER_128

/*Options:
        ADC_DISABLE
        ADC_ENABLE 
*/
#define     ADC_STATUS              ADC_ENABLE

#endif
