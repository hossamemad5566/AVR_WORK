/******************************************************************
 * @name : Hossam Emad 
 * @date : 1/3/2024
 * @SWC  : 7 seg
 * @vesrion: V1.0
 * ****************************************************************/
/*lib*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/*mcal*/
#include "DIO_interface.h"
/*hal*/
#include "seg_private.h"
#include "seg_config.h"
#include "seg_interface.h"

#include <util/delay.h>



void Seg_voidInint(void)
{
    DIO_u8SetPinDirection(SEG_A_PORT,SEG_A_PIN,DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(SEG_B_PORT,SEG_B_PIN,DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(SEG_C_PORT,SEG_C_PIN,DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(SEG_D_PORT,SEG_D_PIN,DIO_u8_OUTPUT);

    
    DIO_u8SetPinDirection(SEG1_PORT,SEG1_PIN,DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(SEG2_PORT,SEG2_PIN,DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(SEG3_PORT,SEG3_PIN,DIO_u8_OUTPUT);
    DIO_u8SetPinDirection(SEG4_PORT,SEG3_PIN,DIO_u8_OUTPUT);

    seg_voidTurnAllOff();
}

u8 seg_u8DispDigit(u8 copy_u8digit)
{
    u8 local_u8ReturnState = STD_TYPE_OK;
    if(copy_u8digit <= 9)
    {
    	DIO_u8SetPinValue(SEG_A_PORT,SEG_A_PIN,GET_BIT(copy_u8digit,0));
    	DIO_u8SetPinValue(SEG_B_PORT,SEG_B_PIN,GET_BIT(copy_u8digit,1));
    	DIO_u8SetPinValue(SEG_C_PORT,SEG_C_PIN,GET_BIT(copy_u8digit,2));
    	DIO_u8SetPinValue(SEG_D_PORT,SEG_D_PIN,GET_BIT(copy_u8digit,3));
    }
    else
    {
        local_u8ReturnState = STD_TYPE_NOK;
    }
    return local_u8ReturnState;
}

u8 seg_u8DipLocTime(u8 copy_u8loc,u8 copy_u8digit,u16 copy_u16Period)
{
    u8 local_u8ReturnState = STD_TYPE_OK;

    if(copy_u8loc <= SEG_LOC_4)
    {
    	seg_voidTurnAllOff();
        switch (copy_u8loc)
        {
        case SEG_LOC_1:
            seg_u8DispDigit(copy_u8digit);
            DIO_u8SetPinValue(SEG1_PORT,SEG1_PIN,SEG_ON);
            _delay_ms(copy_u16Period);
            DIO_u8SetPinValue(SEG1_PORT,SEG1_PIN,SEG_OFF);
            break;
        case SEG_LOC_2:
            seg_u8DispDigit(copy_u8digit);
            DIO_u8SetPinValue(SEG2_PORT,SEG2_PIN,SEG_ON);
            _delay_ms(copy_u16Period);
            DIO_u8SetPinValue(SEG2_PORT,SEG2_PIN,SEG_OFF);
            break;
        case SEG_LOC_3:
            seg_u8DispDigit(copy_u8digit);
            DIO_u8SetPinValue(SEG3_PORT,SEG3_PIN,SEG_ON);
            _delay_ms(copy_u16Period);
            DIO_u8SetPinValue(SEG3_PORT,SEG3_PIN,SEG_OFF);
            break;
        case SEG_LOC_4:
            seg_u8DispDigit(copy_u8digit);
            DIO_u8SetPinValue(SEG4_PORT,SEG4_PIN,SEG_ON);
            _delay_ms(copy_u16Period);
            DIO_u8SetPinValue(SEG4_PORT,SEG4_PIN,SEG_OFF);
            break;
        default:
            break;
        }
    }
    else
    {
        local_u8ReturnState = STD_TYPE_NOK;
    }
    return local_u8ReturnState;
}

void seg_voidTurnAllOff(void)
{
    DIO_u8SetPinValue(SEG1_PORT,SEG1_PIN,SEG_OFF);
    DIO_u8SetPinValue(SEG2_PORT,SEG2_PIN,SEG_OFF);
    DIO_u8SetPinValue(SEG3_PORT,SEG3_PIN,SEG_OFF);
    DIO_u8SetPinValue(SEG4_PORT,SEG4_PIN,SEG_OFF);
}

void  seg_u8Disp4digit(u16 copy_u16_4digitnumber)
{
    u8 local_u8Temp = 0;
    local_u8Temp =    (copy_u16_4digitnumber/1000)%10;
    seg_u8DipLocTime(SEG_LOC_4,local_u8Temp,5);
    local_u8Temp =    (copy_u16_4digitnumber/100)%10;
    seg_u8DipLocTime(SEG_LOC_3,local_u8Temp,5);
    local_u8Temp =    (copy_u16_4digitnumber/10)%10;
    seg_u8DipLocTime(SEG_LOC_2,local_u8Temp,5);
    local_u8Temp =    (copy_u16_4digitnumber)%10;
    seg_u8DipLocTime(SEG_LOC_1,local_u8Temp,5);
}
