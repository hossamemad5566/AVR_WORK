#include "main.h"

#define async  1

void App_CallBackFinction (u8 Copy_u8UARTRecByte);
u8 App_u8UARTRecByte = 0xff;

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
    #if (async==1)
    UART_ReceiveByteAsyncCallBack(App_CallBackFinction);
    #endif
   
}

int main(void)
{
	setup();
    while(1)
    {
        #if (async==0)
        u8 x = UART_ReceiveByteSync();
        if(x == 'B')
        {
            H_LED_Void_LedTog(LED_GRN);
            H_Lcd_Void_LCDWriteCharacter(x);
            H_LED_Void_LedOff(LED_YEL);
        }
        else
        {
        	H_LED_Void_LedOn(LED_YEL);
        }
        #endif
        
        #if ((async==1))
        if(App_u8UARTRecByte != 0xFF)
        {
            if(App_u8UARTRecByte == 'B')
            {
                H_LED_Void_LedTog(LED_GRN);
                H_LED_Void_LedOff(LED_YEL);
            }
            H_Lcd_Void_LCDWriteCharacter(App_u8UARTRecByte);
            App_u8UARTRecByte=0xFF;
        }
        else
        {
        	H_LED_Void_LedOn(LED_YEL);
          
        }
        #endif
    }
}
#if (async==1)
void App_CallBackFinction (u8 Copy_u8UARTRecByte)
{
	App_u8UARTRecByte = Copy_u8UARTRecByte;
}
#endif


