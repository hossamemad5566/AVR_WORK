/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : RGB
 * @about :
****************************************/

#include "RGB_interface.h"
#include "DIO_Interface.h"

void RGB_init(void)
{
    M_DIO_Void_SetPinDirection(RED_PIN,OUTPUT);
    M_DIO_Void_SetPinDirection(BLU_PIN,OUTPUT);
    M_DIO_Void_SetPinDirection(GRN_PIN,OUTPUT);
}

void RGB_color_on(char led)
{
    switch (led)
    {
    case RED_PIN:
        M_DIO_Void_SetPinValue(RED_PIN,HIGH);        
        M_DIO_Void_SetPinValue(BLU_PIN,LOW);        
        M_DIO_Void_SetPinValue(GRN_PIN,LOW);        
    break;
    case BLU_PIN:
        M_DIO_Void_SetPinValue(RED_PIN,LOW);        
        M_DIO_Void_SetPinValue(BLU_PIN,HIGH);        
        M_DIO_Void_SetPinValue(GRN_PIN,LOW);        
    break;
    case GRN_PIN:
        M_DIO_Void_SetPinValue(RED_PIN,LOW);        
        M_DIO_Void_SetPinValue(BLU_PIN,LOW);        
        M_DIO_Void_SetPinValue(GRN_PIN,HIGH);        
    break;
    default:
        break;
    }
}