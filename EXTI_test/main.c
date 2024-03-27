/*************************************
* @name     : Hossam Emad 
* @date     : 13/12/2023
* @SWC      : EXTI external interrupt
* @version  : 1.0
***************************************/
/*Library*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "util/delay.h"
/*MCAL*/
#include "EXIT_interface.h"
#include "DIO_interface.h"
#include "GIE_INTERFACE.h"

void tog_led(void);



int main ()
{
    /*Initialize DIO */
    DIO_voidInit();
    /*Enable GIE*/
    GIE_voidEnable();
    /*set callback function*/
    EXTI_u8SetCallBack(tog_led,EXTI_U8_INDX1);
    /*Enable EXTI 0 */
    EXIT_u8EXITEnable(EXTI_U8_INDX1,EXTI_U8_RISING);


    while(1);

    return 0;
}


void tog_led(void)
{
    DIO_u8TogglePin(DIO_u8_PORTB,DIO_u8_PIN5);
}
