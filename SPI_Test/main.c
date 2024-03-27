/*********************************************************
 * @name : Hossam Emad
 * @date : 20/2/2024
 * @swc: SPI
 * @version : V1.0
 * @description :
*********************************************************//*lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

/*MCAL layer*/
#include "DIO_interface.h"
#include "DIO_config.h"
#include "SPI_interface.h"

#define SPI_MOSI_PIN	DIO_u8_PIN3
#define SPI_MOSI_PORT	DIO_u8_PORTB

#define SPI_MISO_PIN	DIO_u8_PIN4
#define SPI_MISO_PORT	DIO_u8_PORTB

#define SPI_CLK_PIN		DIO_u8_PIN5
#define SPI_CLK_PORT	DIO_u8_PORTB

#define SPI_SS_PIN		DIO_u8_PIN2
#define SPI_SS_PORT		DIO_u8_PORTB

#define LED_PIN			DIO_u8_PIN2
#define LED_PORT		DIO_u8_PORTD



int main(void)
{
	u8 local_u8Data;
	DIO_voidInit();
	SPI_voidInint();
	
	DIO_u8SetPinDirection(LED_PORT,LED_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(SPI_MOSI_PORT,SPI_MOSI_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(SPI_MISO_PORT,SPI_MISO_PIN,DIO_u8_INPUT);
	DIO_u8SetPinDirection(SPI_CLK_PORT,SPI_CLK_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(SPI_SS_PORT,SPI_SS_PIN,DIO_u8_INPUT);

	while(1)
	{
		SPI_u8SendReceiveByte(7,&local_u8Data);
		if(local_u8Data == 5)
		{
			/*turn on led*/
			DIO_u8SetPinValue(LED_PORT,LED_PIN,DIO_u8_HIGH);
			
		}
		else 
		{
			/*turn off led*/
			DIO_u8SetPinValue(LED_PORT,LED_PIN,DIO_u8_LOW);
			
		}
		_delay_ms(500);
		

	}
	
	return 0;
}

