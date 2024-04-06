#include "main.h"

void setup (void)
{
    H_Lcd_Void_LCDInit();
    H_LED_Void_LedInit(LED_GRN);
    H_LED_Void_LedInit(LED_YEL);
    FP_intit();
    H_PushButton_Void_PushButtonInit(PUSH_BUTTON_0);
    H_PushButton_Void_PushButtonInit(PUSH_BUTTON_1);
    H_Lcd_Void_LCDGoTo(3,0);
    H_Lcd_Void_LCDWriteString("1:ADD   2:Match");
    
}

int main(void)
{
	setup();
    


    while(1)
    {
		if(H_PushButton_U8_PushButtonRead(PUSH_BUTTON_0)==PUSH_BUTTON_PRESSED)
		{FP_setNewFinger(2);}
		else if(H_PushButton_U8_PushButtonRead(PUSH_BUTTON_1)==PUSH_BUTTON_PRESSED)
		{FP_CheckMatch(2);}
	}
     
}
    
    

    



