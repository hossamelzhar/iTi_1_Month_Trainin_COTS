#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"


#include "GIE_interface.h"
#include "GIE_private.h"




void GIE_voidEnable(void)
{
    SET_BIT(SREG, SREG_I_BIT);
}
void GIE_voidDisable(void)
{
    CLR_BIT(SREG, SREG_I_BIT);
}