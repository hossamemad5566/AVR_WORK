#include "main.h"

void setup(void)
{
    M_DIO_Void_SetPinDirection(PB6_PIN,OUTPUT);
    M_DIO_Void_SetPinDirection(PB7_PIN,INPUT);
    M_DIO_Void_SetPinDirection(PB5_PIN,INPUT);
    M_DIO_Void_SetPinDirection(PB4_PIN,INPUT);
    
   // H_Lcd_Void_LCDInit();
    SPI_SlaveInit();
    H_LED_Void_LedInit(LED_YEL);
    H_LED_Void_LedInit(LED_GRN);

}

int main(void)
{
	setup();
	u8 x =0;
    while(1)
    {
       // H_Lcd_Void_LCDWriteCharacter(SPI_SlaveReceive());
    	x=SPI_SlaveReceive();
        if('o'==x)
        {
            H_LED_Void_LedTog(LED_GRN);
        }
        H_LED_Void_LedTog(LED_YEL);
        _delay_ms(500);
       // _delay_ms(10);
    }

}
