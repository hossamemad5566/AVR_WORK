/*include*/
#include "main.h"

void setup (void)
{
    RGB_init();
    Event_init();
    motor_Init();
}

int main(void)
{
	setup();
    while(1)
    {
        if(H_PushButton_U8_PushButtonRead(PUSH_BUTTON_0) == PUSH_BUTTON_PRESSED) 
        {
            RGB_color_on(GRN_PIN);
            motor_F();
        }
        else if(H_PushButton_U8_PushButtonRead(PUSH_BUTTON_1) == PUSH_BUTTON_PRESSED)
        {
            RGB_color_on(BLU_PIN);
            motor_B();
        }
	}    
}
    
    

    



