#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_Types.h"

#include "../HAL/Seven_Seg/SevenSeg_interface.h"
#include "../MCAL/DIO/DIO_interface.h"

#define F_CPU		8000000UL
#include <util/delay.h>

void main(void)
{
	SSD_t S1;
	S1.Port = DIO_PORTC;
	S1.Common_Type = COMMON_CATHODE;

	SSD_t S2;
	S2.Port = DIO_PORTD;
	S2.Common_Type = COMMON_ANODE;

	SSD_voidInit(&S1);
	SSD_voidInit(&S2);

	u8 Local_u8Counter = 'A';

	while(1)
	{
		SSD_voidDisplayData(&S1, Local_u8Counter);
		SSD_voidDisplayData(&S2, Local_u8Counter);
		Local_u8Counter++;
		if(Local_u8Counter == 10)
		{
			Local_u8Counter = 0;
		}
		else{}
		_delay_ms(1000);
	}
}
