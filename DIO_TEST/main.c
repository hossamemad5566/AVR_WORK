 /******************************************************************
 * @name : Hossam Emad
 * @date : 27/11/2023
 * @SWC  : DIO
 * @vesrion: V1.0
 * ****************************************************************/
/*Lobrary layer*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU	16000000UL
#include <util/delay.h>

/*MCAL layer*/
#include "DIO_interface.h"


int main ()
{
	u8 Local_u8Buffer = 0;

	/*pin configuration*/
	DIO_voidInit();

	//DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN5,DIO_u8_OUTPUT);
	while(1)
	{
		DIO_u8GetPinValue(DIO_u8_PORTD,DIO_u8_PIN3,&Local_u8Buffer);

		if(DIO_u8_HIGH == Local_u8Buffer)
		{
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN5,DIO_u8_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN5,DIO_u8_LOW);
		}


	}
	return 0;
}
