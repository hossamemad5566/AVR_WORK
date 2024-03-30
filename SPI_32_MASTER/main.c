#include "main.h"

void setup(void)
{
    M_DIO_Void_SetPinDirection(PB7_PIN,OUTPUT);
    M_DIO_Void_SetPinDirection(PB5_PIN,OUTPUT);
    M_DIO_Void_SetPinDirection(PB4_PIN,INPUT);
    M_DIO_Void_SetPinDirection(PB6_PIN,INPUT);
    //H_Lcd_Void_LCDInit();
    SPI_MasterInit();
    

}

int main(void)
{
	setup();
    //u8 Local_u8ARR[3]={'H','o','s'};
    while(1)
    {
        
		SPI_MasterTransmit('o');
		_delay_ms(1000);


        
    }

}
