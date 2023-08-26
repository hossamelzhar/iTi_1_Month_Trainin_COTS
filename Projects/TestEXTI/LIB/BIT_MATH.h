#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_REG(Reg) Reg=0xFF
#define CLR_REG(Reg) Reg=0x00
#define TGL_REG(Reg) Reg^=0xFF
#define ASSIGN_REG(Reg,Value) Reg=Value

#define SET_BITS_REG(Reg,Mask) Reg|=(Mask)
#define CLR_BITS_REG(Reg,Mask) Reg=(Reg&(~Mask))	
								
#define SET_BIT(Reg,bit) Reg|=(1<<bit)
#define CLR_BIT(Reg,bit) Reg=(Reg&(~(1<<bit)))
#define TGL_BIT(Reg,bit) Reg^=(1<<bit)
#define GET_BIT(Reg,bit) ((Reg>>bit)&1)

#endif