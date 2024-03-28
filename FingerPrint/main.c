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
    
    FP_setNewFinger(2);

    FP_CheckMatch(2);

    while(1);
     
}
    
    

    



