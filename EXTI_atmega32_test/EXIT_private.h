/*************************************
* @name     : Hossam Emad 
* @date     : 13/12/2023
* @SWC      : EXTI external interrupt
* @version  : 1.0
***************************************/
#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

/*Registers of EXIT*/



#define EXTI_MCUCSR      (*(volatile u8*)0x54)
#define EXTI_MCUCR       (*(volatile u8*)0x55)
#define EXTI_GIFR        (*(volatile u8*)0x5A)
#define EXTI_GICR        (*(volatile u8*)0x5B)









/**
- EICRA – External Interrupt Control Register A
>>>> : Interrupt Sense Control BITS (action generate interrupt)
- EIMSK – External Interrupt Mask Register
>>>> :  External Interrupt Request Enable (PIE)
- EIFR – External Interrupt Flag Register 
>>>> : (PIF)
*/
#endif
