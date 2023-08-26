#ifndef     GIE_INTERFACE_H
#define     GIE_INTERFACE_H

#define     sei()  __asm__ volatile ("sei") //Enable I Bit
#define     cli()  __asm__ volatile ("cli") //Disable I Bit

void GIE_voidEnable(void);
void GIE_voidDisable(void);

#endif