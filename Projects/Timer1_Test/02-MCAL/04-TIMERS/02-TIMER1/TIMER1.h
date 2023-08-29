/*******************************************************************************************/
/**************		Author 	: Ahmed Amr					************************************/
/**************		SWC 	: TIMER1					************************************/
/**************		Version : Version 1					************************************/
/**************		Date 	: Tue, August 29, 2023	************************************/
/*******************************************************************************************/

#ifndef		TIMER1_H
#define 	TIMER1_H

#define NULL		((void*)0)

//Timer1 Modes
#define     TIMER1_NORMAL_MODE                          0
#define     TIMER1_CTC_MODE_TOP_OCR1A                   4
#define     TIMER1_PHASE_CORRECT_MODE_TOP_OCR1A         11
#define     TIMER1_FAST_MODE_TOP_ICR1                   14
#define     TIMER1_FAST_MODE_TOP_OCR1A                  15

//Timer1 Clock Sources
#define     CLK_SRC_CLR_MASK                            0x07
#define     TIMER1_STOP                                 0 //0b0000 0000
#define     TIMER1_NO_SCALER                            1 //0b0000 0001
#define     TIMER1_SCALER_8                             2 //0b0000 0010
#define     TIMER1_SCALER_64                            3
#define     TIMER1_SCALER_256                           4
#define     TIMER1_SCALER_1024                          5
#define     TIMER1_EXTERNAL_FALLING                     6
#define     TIMER1_EXTERNAL_RISING                      7

//Timer1 OC1A Pin
#define     OC1A_CLR_MASK                               0xC0 // 0b1100 0000
#define     TIMER1_OC1A_DISCONNECTED                    0x00 // 0b0000 0000
#define     TIMER1_OC1A_TOGGLE                          0x40 // 0b0100 0000
#define     TIMER1_OC1A_NON_INVERTING                   0x80 // 0b1000 0000
#define     TIMER1_OC1A_INVERTING                       0xC0 // 0b1100 0000
//Timer1 OC1B Pin
#define     OC1B_CLR_MASK                               0x30 // 0b0011 0000
#define     TIMER1_OC1B_DISCONNECTED                    0x00 // 0b0000 0000
#define     TIMER1_OC1B_TOGGLE                          0x10 // 0b0001 0000
#define     TIMER1_OC1B_NON_INVERTING                   0x20 // 0b0010 0000
#define     TIMER1_OC1B_INVERTING                       0x30 // 0b0011 0000


void Timer1_voidInit(u8 Copy_u8Mode, u8 Copy_u8Scaler, u8 Copy_u8OC1A, u8 Copy_u8OC1B);
void Timer1_voidSetPreloadValue(u16 Copy_u16Value);
u16  Timer1_u16ReadValue(void);
void Timer1_voidSetOCR1AValue(u16 Copy_u16Value);
void Timer1_voidSetOCR1BValue(u16 Copy_u16Value);
void Timer1_voidSetICR1Value(u16 Copy_u16Value);
void Timer1_voidOVFInterruptEnable(void);
void Timer1_voidOVFInterruptDisable(void);
void Timer1_voidOC1AInterruptEnable(void);
void Timer1_voidOC1AInterruptDisable(void);
void Timer1_voidOC1BInterruptEnable(void);
void Timer1_voidOC1BInterruptDisable(void);

//SetCallback Functions
void Timer1_voidOVFSetCallBack(void (*Copy_pfNotification)(void));
void Timer1_voidOC1ASetCallBack(void (*Copy_pfNotification)(void));
void Timer1_voidOC1BSetCallBack(void (*Copy_pfNotification)(void));

#endif
