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
#include "I2c_interface.h"
/*HAL*/
#include "EEPROM_interface.h"



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

	DIO_voidInit();
	I2C_voidMasterInit();



	while(1)
	{
		

	}
	
	return 0;
}

