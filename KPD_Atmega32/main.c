/*********************************************************
 * @name : Hossam Emad
 * @date : 1/12/2023
 * @swc: LCD 16*2
 * @version : V1.0
 * @description :
*********************************************************//*lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

/*MCAL layer*/
#include "DIO_interface.h"

/*HAL layer*/
#include "LCD_interface.h"
#include "KPD_interface.h"

#define LCD_CLEARTEXT "                                        "


int main(void)
 {

	/*DIO init */
	DIO_voidInit();
	/*LCD init*/
	LCD_voidInit();
	/*KPD init*/
	KPD_voidInit();
	
	u8 Local_u8KPDVal = KPD_u8_KEY_NOT_PRESSED;
		KPD_u8GetKey(&Local_u8KPDVal);
		while(1)
		{

			if (Local_u8KPDVal == KPD_u8_KEY_NOT_PRESSED)
			{
				KPD_u8GetKey(&Local_u8KPDVal);
			}
			else
			{
				LCD_u8GoToXY(LCD_u8_LINE1,1);
				LCD_voidWriteChar(Local_u8KPDVal);
				Local_u8KPDVal = KPD_u8_KEY_NOT_PRESSED;
			}

		}
		return 0;
	
	return 0;
 }
