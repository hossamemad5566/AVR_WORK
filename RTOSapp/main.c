#ifndef F_CPU

#define F_CPU 16000000UL // clock speed is 16MHz

#endif

#include "LCD.h"
#include "board.h"
#include "Keypad.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"


//#include <util/delay.h>

void system_int (void);
void T_T1(void *pvParameter);
void T_T2(void *pvParameter);
void T_T3(void *pvParameter);


/*xSemaphoreHandle : DATA TYPE FOR SEMAPHORE*/
xSemaphoreHandle BsEventKeyPressed = NULL;
/*this line to define pointer to the shared event */
 

int main(void)
{
	system_int();
	/*create semaphore for the event */
	BsEventKeyPressed = xSemaphoreCreateBinary();

	xTaskCreate(T_T1,NULL,100,NULL,2,NULL);
	xTaskCreate(T_T2,NULL,100,NULL,3,NULL);
	xTaskCreate(T_T3,NULL,100,NULL,1,NULL);

	vTaskStartScheduler();

	return 0;
}
void system_int (void)
{
	Leds_AllInit();
	LCD_Init();
	LCD_DispStrXY(1,1,"started");
	Key_Init();
}

void T_T1(void *pvParameter)
{
	while(1)
	{
		if(Key_GetKey())
		{
			xSemaphoreGive(BsEventKeyPressed);
		}
		vTaskDelay(50);
	}
}
void T_T2(void *pvParameter)
{
	while(1)
	{
		if(xSemaphoreTake(BsEventKeyPressed,1000000))
		{
			Led_Toggle(LED_BLUE);
		}
		vTaskDelay(1000);

	}
}
void T_T3(void *pvParameter)
{
	while(1)
	{
		Led_Toggle(LED_GREEN);
		vTaskDelay(300);
	}
}
