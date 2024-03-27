#include "main.h"





void setup (void)
{
    H_Lcd_Void_LCDInit();
    H_LED_Void_LedInit(LED_GRN);
    H_LED_Void_LedInit(LED_YEL);
    FP_intit();
    
}

int main(void)
{
	setup();

    u8 x=1;
    /********************************************
    *1- gen img
    *********************************************/
    H_Lcd_Void_LCDWriteString("Place your finger");
    while(x!=0)
    {
        x = FingerPS_genImg();
        FingerPS_Auraked(BREATHING,0xAA,BLUE,1);
    }
    H_Lcd_Void_LCDGoTo(0,0);
    H_Lcd_Void_LCDWriteString("First img generated ");
    x=1;
    /********************************************
    *2- FIRST CHARACTER FILE GENERATION
    *********************************************/
    while(x!=0)
    {
        x = FingerPS_ConvertImg2CharFile(CHAR_BUFFER_2);
        FingerPS_Auraked(BREATHING,0xAA,PURPLE,1);
    }
    H_Lcd_Void_LCDGoTo(1,0);
    H_Lcd_Void_LCDWriteString("1st chr generated   ");
    x=1;
    /********************************************
    *3- Second image generation
    *********************************************/
    while(x!=0)
    {
        x = FingerPS_genImg();
        FingerPS_Auraked(BREATHING,0xAA,BLUE,1);
    }
    H_Lcd_Void_LCDGoTo(1,0);
    H_Lcd_Void_LCDWriteString("1st chr generated   ");
    x=1;
    /********************************************
    *4- SECONED CHAR FILE GENERATED
    *********************************************/
    while(x!=0)
    {
        x = FingerPS_genImg();
        FingerPS_Auraked(BREATHING,0xAA,BLUE,1);
    }
    H_Lcd_Void_LCDGoTo(1,0);
    H_Lcd_Void_LCDWriteString("1st chr generated   ");
    x=1;
    /********************************************
    *5- Generate Tempelate
    *********************************************/
    while(x!=0)
    {
        x = FingerPS_genImg();
        FingerPS_Auraked(BREATHING,0xAA,BLUE,1);
    }
    H_Lcd_Void_LCDGoTo(1,0);
    H_Lcd_Void_LCDWriteString("1st chr generated   ");
    x=1;
    /********************************************
    *6- Tempelate Storing
    *********************************************/
    while(x!=0)
    {
        x = FingerPS_genImg();
        FingerPS_Auraked(BREATHING,0xAA,BLUE,1);
    }
    H_Lcd_Void_LCDGoTo(1,0);
    H_Lcd_Void_LCDWriteString("1st chr generated   ");
    x=1;
    /********************************************
    *7- Generate Image to check one to one match
    *********************************************/
    while(x!=0)
    {
        x = FingerPS_genImg();
        FingerPS_Auraked(BREATHING,0xAA,BLUE,1);
    }
    H_Lcd_Void_LCDGoTo(1,0);
    H_Lcd_Void_LCDWriteString("1st chr generated   ");
    x=1;
    /********************************************
    *8- Generate char from Check Image
    *********************************************/
    while(x!=0)
    {
        x = FingerPS_genImg();
        FingerPS_Auraked(BREATHING,0xAA,BLUE,1);
    }
    H_Lcd_Void_LCDGoTo(1,0);
    H_Lcd_Void_LCDWriteString("1st chr generated   ");
    x=1;
    /********************************************
    *9- Load Char in char file 2
    *********************************************/
    while(x!=0)
    {
        x = FingerPS_genImg();
        FingerPS_Auraked(BREATHING,0xAA,BLUE,1);
    }
    H_Lcd_Void_LCDGoTo(1,0);
    H_Lcd_Void_LCDWriteString("1st chr generated   ");
    x=1;
    /********************************************
    *10- CHECK MATCH
    *********************************************/
    while(x!=0)
    {
        x = FingerPS_genImg();
        FingerPS_Auraked(BREATHING,0xAA,BLUE,1);
    }
    H_Lcd_Void_LCDGoTo(1,0);
    H_Lcd_Void_LCDWriteString("1st chr generated   ");
    x=1;

    while(1)
    {
        
        

    }
}


