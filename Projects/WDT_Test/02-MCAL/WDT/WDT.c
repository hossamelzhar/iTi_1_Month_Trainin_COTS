/**********************************************************************************/
/**************		Auther	:	 Ahmed Amr         ********************************/
/**************		SWC  	:	 WDT			   ********************************/
/**************		Date  	:	 8/29/2022         ********************************/
/**************		Version   	:	 V1            ********************************/
/**********************************************************************************/

#include <avr/io.h>

#include "../../01-LIB/BIT_MATH.h"
#include "../../01-LIB/STD_TYPES.h"

#include "WDT.h"



void WDT_voidEnable(void)
{
    SET_BIT(WDTCR, WDE);
}

void WDT_voidSleep(u8 Copy_u8Time)
{
    CLR_BITS_IN_REG(WDTCR, CLR_PRESCALE_MASK);
    SET_BITS_IN_REG(WDTCR, Copy_u8Time);
}


void WDT_voidDisable(void)
{
    WDTCR = DISABLE_MASK;
    WDTCR = ZERO;
}