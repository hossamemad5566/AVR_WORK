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
#include "DIO_config.h"

/*HAL layer*/
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

#define LCD_CLEARTEXT "                                        "


int main(void)
 {
	/*DIO init */
	u16 x = 12050;

	DIO_voidInit();
	/*LCD init*/
	LCD_voidInit();
	u8 Local_Au8String[]= "Haneen Ameer";
	LCD_u8GoToXY(LCD_u8_LINE4,0);
	LCD_voidWriteNumber(x);
	LCD_voidWriteString(Local_Au8String);
			
		return 0;
 }

/*temp

	/*local variables */
	/*u8 Local_Au8String[]= "Haneen Ameer";
	u16 x = 12050;

	/*display name *
	LCD_voidWriteChar('H');
	LCD_voidWriteChar('o');
	LCD_voidWriteChar('s');
	LCD_voidWriteChar('s');
	LCD_voidWriteChar('a');
	LCD_voidWriteChar('m');
	LCD_u8GoToXY(LCD_u8_LINE2,0);
	LCD_voidWriteString (Local_Au8String);
	*/
	/*Hossam name in Arabic
	{
	u8 Local_u8charH[8]={	0b00000000,
							0b00000000,
							0b00000000,
							0b00000000,
							0b00000111,
							0b00000001,
							0b00011111,
							0b00000000};
		LCD_u8WriteSpecialChar(LCD_u8_SPECHIAL0,Local_u8charH);
	u8  Local_u8charS[8]={	0b00000000,
							0b00000000,
							0b00000000,
							0b00000000,
							0b00010101,
							0b00010101,
							0b00011111,
							0b00000000};
	LCD_u8WriteSpecialChar(LCD_u8_SPECHIAL1,Local_u8charS);
	u8  Local_u8charA[8]={	0b00000000,
							0b00010000,
							0b00010000,
							0b00010000,
							0b00010000,
							0b00010000,
							0b00011111,
							0b00000000};
	LCD_u8WriteSpecialChar(LCD_u8_SPECHIAL2,Local_u8charA);
	u8  Local_u8charM[8]={	0b00000000,
							0b00000000,
							0b00000000,
							0b00011111,
							0b00010011,
							0b00010000,
							0b00010000,
							0b00000000};
	LCD_u8WriteSpecialChar(LCD_u8_SPECHIAL3,Local_u8charM);
	LCD_u8GoToXY(LCD_u8_LINE1,6);
	LCD_voidWriteChar(0);					 
	LCD_u8GoToXY(LCD_u8_LINE1,5);
	LCD_voidWriteChar(1);					 
	LCD_u8GoToXY(LCD_u8_LINE1,4);
	LCD_voidWriteChar(2);					 
	LCD_u8GoToXY(LCD_u8_LINE1,3);
	LCD_voidWriteChar(3);					 
	LCD_u8GoToXY(LCD_u8_LINE1,7);
	}
	/*print number on lcd 
	LCD_voidWriteNumber(x);

	/*shift data
	while(1)
		{
		LCD_voidWriteCmnd(LCD_u8_SHIFT_LEFT);
		_delay_ms(1000);
		}



*/
