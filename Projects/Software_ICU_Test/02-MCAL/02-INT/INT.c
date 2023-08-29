/*********************************************************************************/
/**********		Author 	: Ahmed Amr					******************************/
/**********		SWC 	: INT						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Wednesday, August 23, 2023******************************/
/*********************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>

#include <util/delay.h>

#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

#include "../01-DIO/DIO.h"
#include "INT.h"

static void (*INT_voidPFCall[3]) (void) = {0} ;

void INT_voidEnable (u8 Copy_u8INTIndex , u8 Copy_u8Edge)
{
	switch (Copy_u8INTIndex)
	{
		case EXT_INT0 :
			/*Edge Select*/
			switch (Copy_u8Edge)
			{
				case INT_FALLING_EDGE 		: 
					CLR_BIT (MCUCR , ISC00);
					SET_BIT (MCUCR , ISC01);
					break ;
				case INT_RISING_EDGE  		:
					SET_BIT (MCUCR , ISC00);
					SET_BIT (MCUCR , ISC01);
					break ;
				case INT_ANY_LOGICAL_CHANGE :
					SET_BIT (MCUCR , ISC00);
					CLR_BIT (MCUCR , ISC01);
					break ;
				case INT_LOW_LEVEL 			:
					CLR_BIT (MCUCR , ISC00);
					CLR_BIT (MCUCR , ISC01);
					break ;
			}
			/*INT0 Enable*/
			SET_BIT (GICR , INT0);
			break ;
		case EXT_INT1 :
			/*Edge Select*/
			switch (Copy_u8Edge)
			{
				case INT_FALLING_EDGE 		: 
					CLR_BIT (MCUCR , ISC10);
					SET_BIT (MCUCR , ISC11);
					break ;
				case INT_RISING_EDGE  		:
					SET_BIT (MCUCR , ISC10);
					SET_BIT (MCUCR , ISC11);
					break ;
				case INT_ANY_LOGICAL_CHANGE :
					SET_BIT (MCUCR , ISC10);
					CLR_BIT (MCUCR , ISC11);
					break ;
				case INT_LOW_LEVEL 			:
					CLR_BIT (MCUCR , ISC10);
					CLR_BIT (MCUCR , ISC11);
					break ;
			}
			/*INT1 Enable*/
			SET_BIT (GICR , INT1);
			break ;
		case EXT_INT2 :
			/*Edge Select*/
			switch (Copy_u8Edge)
			{
			case INT_FALLING_EDGE 		: 
				CLR_BIT(MCUCSR , ISC2);
				break ;
			case INT_RISING_EDGE  		:
				SET_BIT(MCUCSR , ISC2);
				break ;
			}
			/*INT2 Enable*/
			SET_BIT(GICR , INT2);
			break ;
	}
}


void INT_voidDisable (u8 Copy_u8INTIndex)
{
	switch (Copy_u8INTIndex)
	{
		case EXT_INT0 :  CLR_BIT (GICR , INT0) ; break ;
		case EXT_INT1 :  CLR_BIT (GICR , INT1) ; break ;
		case EXT_INT2 :  CLR_BIT (GICR , INT2) ; break ;
		
	}
}

void INT_voidSetCallBack (u8 Copy_u8Index , void (*Copy_voidPFNameFunc) (void))
{
	INT_voidPFCall[Copy_u8Index] = Copy_voidPFNameFunc ;
}

ISR(INT0_vect)
{
	if (INT_voidPFCall[0] != NULL)
	INT_voidPFCall[0]();
}

ISR(INT1_vect)
{
	if (INT_voidPFCall[1] != NULL)
	INT_voidPFCall[1]();
}
ISR(INT2_vect)
{
	if (INT_voidPFCall[2] != NULL)
	INT_voidPFCall[2]();
}


