#ifndef F_CPU

#define F_CPU 16000000UL // clock speed is 16MHz

#endif
#include "uart.h"
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
xSemaphoreHandle BmUART = NULL;
/*this line to define pointer to the shared event */
 

int main(void)
{
	system_int();
	/*create semaphore for the event */
	BmUART = xSemaphoreCreateMutex();

	xTaskCreate(T_T1,NULL,100,NULL,2,NULL);
	xTaskCreate(T_T2,NULL,100,NULL,3,NULL);
	xTaskCreate(T_T3,NULL,100,NULL,1,NULL);

	vTaskStartScheduler();

	return 0;
}
void system_int (void)
{
	Uart_Init(9600);
	Leds_AllInit();
	LCD_Init();
	LCD_DispStrXY(1,1,"started");
	Key_Init();
	Uart_SendStr("Res App:");
}

void T_T1(void *pvParameter)
{
	while(1)
	{
		if(xSemaphoreTake(BmUART,portMAX_DELAY));
		{
			Uart_SendStr("AT+SMS1\r\n");
			Uart_SendStr("AT+SMS2\r\n");
			xSemaphoreGive(BmUART);
		}
		
	}
}
void T_T2(void *pvParameter)
{
	while(1)
	{
		if(xSemaphoreTake(BmUART,portMAX_DELAY));
		{
			Uart_SendStr("AT+Server1\r\n");
			Uart_SendStr("AT+Server2\r\n");
			xSemaphoreGive(BmUART);
		}
		vTaskDelay(5);
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
