#ifndef     EXTI_INTERFACE_H
#define     EXTI_INTERFACE_H



#define     EXTI_INT0                   0
#define     EXTI_INT1                   1
#define     EXTI_INT2                   2


#define     EXTI_LOW_LEVEL              0
#define     EXTI_ANY_CHANGE             1
#define     EXTI_FALLING_EDGE           2
#define     EXTI_RISING_EDGE            3


void EXTI_voidInterruptEnable(u8 Copy_u8InterruptNumber);
void EXTI_voidInterruptDisable(u8 Copy_u8InterruptNumber);
void EXTI_voidSetTriggerEdge(u8 Copy_u8InterruptNumber, u8 Copy_u8Edge);
u8   EXTI_u8ReadInterruptFlag(u8 Copy_u8InterruptNumber);
void EXTI_voidClearInterruptFlag(u8 Copy_u8InterruptNumber);

void EXTI_voidSetCallBack(u8 Copy_u8InterruptNumber, void (*Notification)(void));


#endif