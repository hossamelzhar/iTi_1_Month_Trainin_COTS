/**********************************************************************************/
/**************		Auther	:	 Ahmed Amr         ********************************/
/**************		SWC  	:	 WDT			   ********************************/
/**************		Date  	:	 8/29/2022         ********************************/
/**************		Version   	:	 V1            ********************************/
/**********************************************************************************/

#ifndef		WDT_H
#define		WDT_H

#define     CLR_PRESCALE_MASK           0x07

#define     WDT_SLEEP_16_3_MS           0
#define     WDT_SLEEP_32_5_MS           1
#define     WDT_SLEEP_65_MS             2
#define     WDT_SLEEP_0_13_S            3
#define     WDT_SLEEP_0_26_S            4
#define     WDT_SLEEP_0_52_S            5
#define     WDT_SLEEP_1_S               6
#define     WDT_SLEEP_2_1_S             7

#define     DISABLE_MASK        0x18
#define     ZERO                0x00


void WDT_voidEnable(void);
void WDT_voidSleep(u8 Copy_u8Time);
void WDT_voidDisable(void);

#endif