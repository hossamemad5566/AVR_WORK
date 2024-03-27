/*************************************
* @name     : Hossam Emad 
* @date     : 29/12/2023
* @SWC      : TIMER
* @version  : 1.0
***************************************/
#ifndef _TIMERS_INTERFACE_H
#define _TIMERS_INTERFACE_H

void TIMER_voidTimer0Init(void);

u8 TIMER_u8CallBackFunc (void (*Pf)(void));

u8 TIMER_u8CTCCallBackFunc (void (*Pf)(void));

void analogWrite(u8 val);

#endif 