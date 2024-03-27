/*********************************************************
 * @name : Hossam Emad
 * @date : 6/2/2024
 * @swc: USART
 * @version : V1.0
 * @description :
*********************************************************//*lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

/*MCAL layer*/
#include "DIO_interface.h"
#include "DIO_config.h"
#include "UART_interface.h"



int main(void)
{
	u8 uartdata=0;
	/*initialize peripherals*/
	DIO_voidInit();
	/* RX is i/p pin and TX is O/p pin*/
	UART_voidInit();

	while(1)
	{
		//UART_u8SendsyncByte('a');
		//_delay_ms(1000);
#if 1
		UART_u8ReceivesyncByte(&uartdata);
		if(uartdata == 'a' )
		{
			DIO_u8TogglePin(DIO_u8_PORTB,DIO_u8_PIN5);
			//_delay_ms(1000);
		}
#endif
	}
	return 0;
}

