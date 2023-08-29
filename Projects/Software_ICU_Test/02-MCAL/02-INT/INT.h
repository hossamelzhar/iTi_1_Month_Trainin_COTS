/*********************************************************************************/
/**********		Author 	: Ahmed Amr					******************************/
/**********		SWC 	: INT						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Wednesday, August 23, 2023******************************/
/*********************************************************************************/

#ifndef		INT_H
#define		INT_H

/*Macros for INT Index*/
#define		EXT_INT0				0
#define		EXT_INT1				1
#define		EXT_INT2				2

/*Macros for Edge Index*/
#define		INT_FALLING_EDGE		0
#define		INT_RISING_EDGE			1
#define		INT_ANY_LOGICAL_CHANGE	2
#define		INT_LOW_LEVEL			3


#define 	NULL					((void*)0)


void INT_voidEnable (u8 Copy_u8INTIndex , u8 Copy_u8Edge);
void INT_voidDisable (u8 Copy_u8INTIndex);
void INT_voidSetCallBack (u8 Copy_u8Index , void (*Copy_voidPFNameFunc) (void));

#endif
