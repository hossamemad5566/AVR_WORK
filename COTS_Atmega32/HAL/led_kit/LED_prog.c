/******************************************************************
 * @name : Hossam Emad 
 * @date : 1/3/2023
 * @SWC  : led 
 * @vesrion: V1.0
 * ****************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "LED_config.h"
#include "LED_private.h"
#include "LED_interface.h"


void led_voidInit(void)
{
    DIO_u8SetPinDirection(LED_PORT_RED,LED_PIN_RED,DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LED_PORT_GREEN,LED_PIN_GREEN,DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LED_PORT_BLUE,LED_PIN_BLUE,DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(LED_PORT_YELLOW,LED_PIN_YELLOW,DIO_u8_OUTPUT);

    DIO_u8SetPinValue(LED_PORT_RED,LED_PIN_RED,DIO_u8_LOW);
    DIO_u8SetPinValue(LED_PORT_YELLOW,LED_PIN_YELLOW,DIO_u8_LOW);
    DIO_u8SetPinValue(LED_PORT_BLUE,LED_PIN_BLUE,DIO_u8_LOW);
    DIO_u8SetPinValue(LED_PORT_GREEN,LED_PIN_GREEN,DIO_u8_LOW);
}

void LED_voidRedLedOn(void)
{
    DIO_u8SetPinValue(LED_PORT_RED,LED_PIN_RED,DIO_u8_HIGH);
}
void LED_voidYellowLedOn(void)
{
    DIO_u8SetPinValue(LED_PORT_YELLOW,LED_PIN_YELLOW,DIO_u8_HIGH);
}
void LED_voidBlueLedOn(void)
{
    DIO_u8SetPinValue(LED_PORT_BLUE,LED_PIN_BLUE,DIO_u8_HIGH);    
}
void LED_voidGreenLedOn(void)
{
    DIO_u8SetPinValue(LED_PORT_GREEN,LED_PIN_GREEN,DIO_u8_HIGH);

}

void LED_voidRedLedOff(void)
{
    DIO_u8SetPinValue(LED_PORT_RED,LED_PIN_RED,DIO_u8_LOW);
}
void LED_voidYellowLedOff(void)
{
    DIO_u8SetPinValue(LED_PORT_YELLOW,LED_PIN_YELLOW,DIO_u8_LOW);

}
void LED_voidBlueLedOff(void)
{
    DIO_u8SetPinValue(LED_PORT_BLUE,LED_PIN_BLUE,DIO_u8_LOW);

}
void LED_voidGreenLedOff(void)
{
    DIO_u8SetPinValue(LED_PORT_GREEN,LED_PIN_GREEN,DIO_u8_LOW);

}

void LED_voidRedLedTog(void)
{
    DIO_u8TogglePin(LED_PORT_RED,LED_PIN_RED);

}
void LED_voidYellowLedTog(void)
{
    DIO_u8TogglePin(LED_PORT_YELLOW,LED_PIN_YELLOW);

}
void LED_voidBlueLedTog(void)
{
    DIO_u8TogglePin(LED_PORT_BLUE,LED_PIN_BLUE);

}
void LED_voidGreenLedTog(void)
{
    DIO_u8TogglePin(LED_PORT_GREEN,LED_PIN_GREEN);

}