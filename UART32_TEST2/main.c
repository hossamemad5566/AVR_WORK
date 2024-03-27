#include "main.h"

void setup (void)
{

    GIE_voidEnable();
    M_DIO_Void_SetPinDirection(PD0_PIN,INPUT);
	M_DIO_Void_SetPinDirection(PD1_PIN,OUTPUT);
    M_DIO_Void_SetPinDirection(PA6_PIN,OUTPUT);
    UART_Init();
    H_Lcd_Void_LCDInit();
    H_LED_Void_LedInit(LED_GRN);
    H_LED_Void_LedInit(LED_YEL);

}

int main(void)
{
	setup();
    while(1)
    {
        
    	UART_SendByte('B');
        _delay_ms(1500);

    }
}

