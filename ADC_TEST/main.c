/*lib*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*HAL*/

/*MCAL*/
#include "DIO_interface.h"
#include "GIE_INTERFACE.h"
#include "ADC_interface.h"



#define LED1_PIN    DIO_u8_PIN0
#define LED2_PIN    DIO_u8_PIN1
#define LED3_PIN    DIO_u8_PIN2
#define LED_PORT    DIO_u8_PORTB

void App_CallBackFinction (u16 Copy_u16Digitalval);
u16 App_u16DigitalRead = 0xffff;
int main (void)
{
    //u16 DigitalVal = 0;
    u32 AnalogVal  = 0;
    /*DIO initialization*/
    DIO_voidInit();
    /*ADC init*/
    ADC_voidinit();
    /*GIE*/
    GIE_voidEnable();

    while(1)
    {
        ADC_u8GetDigitalValueAsync( ADC_u8_ADC0 , App_CallBackFinction );
        if(App_u16DigitalRead != 0xffff)
        {
            AnalogVal = ((u32)App_u16DigitalRead* 5000UL)/1024;
            if(AnalogVal < 1500)
            {
                DIO_u8SetPinValue(LED_PORT,LED1_PIN,DIO_u8_HIGH);
                DIO_u8SetPinValue(LED_PORT,LED2_PIN,DIO_u8_LOW);
                DIO_u8SetPinValue(LED_PORT,LED3_PIN,DIO_u8_LOW);
            }
            else if((AnalogVal >= 1500) && (AnalogVal <= 3000))
            {
                DIO_u8SetPinValue(LED_PORT,LED1_PIN,DIO_u8_LOW);
                DIO_u8SetPinValue(LED_PORT,LED2_PIN,DIO_u8_HIGH);
                DIO_u8SetPinValue(LED_PORT,LED3_PIN,DIO_u8_LOW);
            }
            else if((AnalogVal > 3000) && (AnalogVal <= 5000))
            {
                DIO_u8SetPinValue(LED_PORT,LED1_PIN,DIO_u8_LOW);
                DIO_u8SetPinValue(LED_PORT,LED2_PIN,DIO_u8_LOW);
                DIO_u8SetPinValue(LED_PORT,LED3_PIN,DIO_u8_HIGH);
            }
            App_u16DigitalRead = 0xffff;
        }
    }
    return 0 ;
}

void App_CallBackFinction (u16 Copy_u16Digitalval)
{
    App_u16DigitalRead = Copy_u16Digitalval;
}
