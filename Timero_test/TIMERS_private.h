/*************************************
* @name     : Hossam Emad 
* @date     : 29/12/2023
* @SWC      : TIMER
* @version  : 1.0
***************************************/
#ifndef _TIMERS_PRIVATE_H
#define _TIMERS_PRIVATE_H



#define TIMER_U8_TCCR0A     (*(volatile u8*)0X44)
#define TIMER_U8_TCCR0B     (*(volatile u8*)0X45)
#define TIMER_U8_TCNT0      (*(volatile u8*)0X46)
#define TIMER_U8_OCR0A      (*(volatile u8*)0X47)
#define TIMER_U8_OCR0B      (*(volatile u8*)0X48)
#define TIMER_U8_TIMSK0     (*(volatile u8*)0X6E)
#define TIMER_U8_TIFR0      (*(volatile u8*)0X35)



#endif 
