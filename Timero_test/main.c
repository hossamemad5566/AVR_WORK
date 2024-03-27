/*lib*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"


/*MCAL*/
#include "DIO_interface.h"
#include "GIE_INTERFACE.h"
#include "TIMERS_interface.h"


void app_voidTogLed (void);
int main (void)
{

    DIO_voidInit();
    /*GIE*/
    //GIE_voidEnable();
    /*timer0 initialization*/
    TIMER_voidTimer0Init();
    //TIMER_u8CTCCallBackFunc(app_voidTogLed);
    while(1)
    {
       // for(int i = 0; i <255;i++)
     //  {
        	_delay_ms(10);
        	analogWrite(0);
     //  }
    }
    return 0 ;
}

void app_voidTogLed (void)
{
    DIO_u8TogglePin(DIO_u8_PORTB,DIO_u8_PIN5);
}
