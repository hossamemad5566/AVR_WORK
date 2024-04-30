#include "main.h"

u8 App_u8UARTRecPack[4];
u8 ArrIndex=0;
u16 pack_u16Length=0;
u8 Completeflag =0;
void UART_CallBackFunction (u8 Copy_u8UARTRecByte);

void setup (void)
{
    H_Lcd_Void_LCDInit();

    H_LED_Void_LedInit(LED_GRN);
    H_LED_Void_LedInit(LED_YEL);

    H_PushButton_Void_PushButtonInit(PUSH_BUTTON_0);
    H_PushButton_Void_PushButtonInit(PUSH_BUTTON_1);
    
    /*tx and rx */
    M_DIO_Void_SetPinDirection(PD1_PIN,OUTPUT);
    M_DIO_Void_SetPinDirection(PD0_PIN,INPUT);
    _delay_ms(200);
    
    /*uart init */
    UART_Init();
    
    /*receive*/
    GIE_voidEnable();
    UART_ReceiveByteAsyncCallBack(UART_CallBackFunction);
}

int main(void)
{
    u8 f1 = 0;
    u8 arr1[4]={0x71,0x01,0xAA,0x00};
    u8 arr2[3]={0x7F,0x31,0x11};
	setup();

    while(1)
    {

		if(ArrIndex >=1)
		{
            if((App_u8UARTRecPack[0]==0x10) && (App_u8UARTRecPack[1]==0x02) && f1==0 )
            {
                f1 =1;
                H_Lcd_Void_LCDGoTo(0,0);
                H_Lcd_Void_LCDWriteString("ok1");
                ArrIndex=0;
            }
            if((App_u8UARTRecPack[0]==0x31) && (App_u8UARTRecPack[1]==0x01) && (App_u8UARTRecPack[2]==0xAA) && (App_u8UARTRecPack[3]==0x00))
            {
                ArrIndex=0;
                if((f1==1))
                {
                    H_Lcd_Void_LCDGoTo(1,0);
                    H_Lcd_Void_LCDWriteString("ok2");

                    H_LED_Void_LedOn(LED_GRN);
                    UART_SendString(arr1,4);
                }
                else 
                {
                    H_Lcd_Void_LCDGoTo(2,0);
                    H_Lcd_Void_LCDWriteString("ok3");
                    H_LED_Void_LedOff(LED_GRN);
                    UART_SendString(arr2,4);
                    
                }
            }
            else
            {
                H_Lcd_Void_LCDGoTo(3,0);
                H_Lcd_Void_LCDWriteString("ok4");   
            }
        }
		
	}
     
}
    
    

    



void UART_CallBackFunction (u8 Copy_u8UARTRecByte)
{
    if(ArrIndex<4)
    {
        App_u8UARTRecPack[ArrIndex] = Copy_u8UARTRecByte;
        /*FOR debugging*/
        //H_Lcd_Void_LCDWriteCharacter(App_u8UARTRecPack[ArrIndex]);
        ArrIndex++;
    }
    else 
    {ArrIndex=0;}     
}
