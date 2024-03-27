/*LIB LAYER*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*MCAL*/
#include "TIMERS_interface.h"
#include "TIMERS_config.h"
#include "TIMERS_private.h"

 
static void (*POVFFunc)(void)=NULL;
static void (*PCTCFunc)(void)=NULL;

u8 TIMER_u8CallBackFunc (void (*Pf)(void))
{
    u8 Local_u8ReturnState =STD_TYPE_OK;
    if(Pf != NULL)
    {
        POVFFunc =Pf;
    }
    else
    {
        Local_u8ReturnState =STD_TYPE_NOK;
    }
    return Local_u8ReturnState;
}

u8 TIMER_u8CTCCallBackFunc (void (*Pf)(void))
{
    u8 Local_u8ReturnState =STD_TYPE_OK;
    if(Pf != NULL)
    {
        PCTCFunc =Pf;
    }
    else
    {
        Local_u8ReturnState =STD_TYPE_NOK;
    }
    return Local_u8ReturnState;
}


void TIMER_voidTimer0Init(void)
{
    /*normal*/
    #if 0
        /* 1 - select mode*/
        CLR_BIT(TIMER_U8_TCCR0B,3); CLR_BIT(TIMER_U8_TCCR0A,1); CLR_BIT(TIMER_U8_TCCR0A,0);
        /* 2 - set preload value*/
        TIMER_U8_TCNT0 = 112;
        /* 3 - set PIE*/
        SET_BIT(TIMER_U8_TIMSK0,0);
        /* 4 - set prescaler: 64 when it set timer start to count*/
        CLR_BIT(TIMER_U8_TCCR0B,2); SET_BIT(TIMER_U8_TCCR0B,1); SET_BIT(TIMER_U8_TCCR0B,0);
    #endif
    /*CTC mode is adjusted for 1ms for each ovF  */
    #if 0
    /*1-CTC*/
    CLR_BIT(TIMER_U8_TCCR0B,3); SET_BIT(TIMER_U8_TCCR0A,1); CLR_BIT(TIMER_U8_TCCR0A,0);
    /*2-Top Value of OCR0A*/
    TIMER_U8_OCR0A =Timer0_OCR0A_TopVal;
    /* 3 - set PIE*/
    SET_BIT(TIMER_U8_TIMSK0,1);
    /* 4 - set prescaler: 64 when it set timer start to count*/
    CLR_BIT(TIMER_U8_TCCR0B,2); SET_BIT(TIMER_U8_TCCR0B,1); SET_BIT(TIMER_U8_TCCR0B,0);
    #endif
    /*code for counter mode with CTC mode*/
    #if 0
    /*1-CTC*/
    CLR_BIT(TIMER_U8_TCCR0B,3); SET_BIT(TIMER_U8_TCCR0A,1); CLR_BIT(TIMER_U8_TCCR0A,0);
    /*2-Top Value of OCR0A*/
    TIMER_U8_OCR0A = 5;
    /* 3 - set PIE*/
    SET_BIT(TIMER_U8_TIMSK0,1);
    /* 4 - set prescaler: Ext clk on To pin rising edge*/
    SET_BIT(TIMER_U8_TCCR0B,2); SET_BIT(TIMER_U8_TCCR0B,1); SET_BIT(TIMER_U8_TCCR0B,0);
    #endif
    /*fast PWM mode*/
    #if 1
        /*1-choose mode : fast PWM*/
    	CLR_BIT(TIMER_U8_TCCR0B,3); SET_BIT(TIMER_U8_TCCR0A,1); SET_BIT(TIMER_U8_TCCR0A,0);
        /*2-PWM mode : nonInverting mode on OC0A pin*/
        CLR_BIT(TIMER_U8_TCCR0A,6); SET_BIT(TIMER_U8_TCCR0A,7);
        /*3-set Value of OCR0A*/
        TIMER_U8_OCR0A = 50;
        /*2-PWM mode : nonInverting mode on OC0A pin*/
		CLR_BIT(TIMER_U8_TCCR0A,4); SET_BIT(TIMER_U8_TCCR0A,5);
		/*3-set Value of OCR0A*/
		TIMER_U8_OCR0B = 150;
        /* 4 - set prescaler: 64 when it set timer start to count*/
        CLR_BIT(TIMER_U8_TCCR0B,2); SET_BIT(TIMER_U8_TCCR0B,1); SET_BIT(TIMER_U8_TCCR0B,0);

        #endif
}

void analogWrite(u8 val)
{
    TIMER_U8_OCR0A =val;
    TIMER_U8_OCR0B =255-val;

}



/*interrupt function if we want to use the T0 as a timer in Normal Mode OVF mode*/
#if 0
void __vector_16 (void)  __attribute__((signal));
void __vector_16 (void)
{
    static u16 Local_u16Counter = 0;
    Local_u16Counter ++;
    if(976 == Local_u16Counter)
    {
        /*initial value for next iteration*/
        TIMER_U8_TCNT0 = Timer0_initial_val;
        /*reset counter*/
        Local_u16Counter =0;
        POVFFunc();
    }
  
}
#endif
/*interrupt function if we want to use the T0 as a timer in CTC mode*/
#if 0
void __vector_14 (void)  __attribute__((signal));
void __vector_14 (void)
{
    static u16 Local_u16Counter = 0;
    Local_u16Counter ++;
    if(5000 == Local_u16Counter)
    {
        /*initial value for next iteration*/
        TIMER_U8_TCNT0 = Timer0_initial_val;
        /*reset counter*/
        Local_u16Counter =0;
        PCTCFunc();
    }
  
}
#endif
/*interrupt function if we want to use the T0 pin as a counter with CTC mode*/
#if 0
void __vector_14 (void)  __attribute__((signal));
void __vector_14 (void)
{
    static u16 Local_u16Counter = 0;
    Local_u16Counter ++;
    if(1 == Local_u16Counter)
    {
        /*initial value for next iteration*/
        TIMER_U8_TCNT0 = Timer0_initial_val;
        /*reset counter*/
        Local_u16Counter =0;
        PCTCFunc();
    }

}
#endif
