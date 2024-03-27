/*********************************************************
 * @name : Hossam Emad
 * @date : 1/12/2023
 * @swc: LCD 16*2
 * @version : V1.0
 * @description :
*********************************************************//*lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

/*MCAL layer*/
#include "DIO_interface.h"
#include "EXIT_interface.h"
#include "GIE_INTERFACE.h"


/*HAL layer*/

#include "LED_interface.h"



int main(void)
 {
	/*Initialize DIO */
    DIO_voidInit();
    /*Enable GIE*/
    GIE_voidEnable();
	led_voidInit();
    /*set callback function*/
    EXTI_u8SetCallBack(LED_voidBlueLedTog,EXTI_U8_INDX0);
    /*Enable EXTI 0 */
    EXIT_u8EXITEnable(EXTI_U8_INDX0,EXTI_U8_RISING);
    while(1);

    return 0;
 }



