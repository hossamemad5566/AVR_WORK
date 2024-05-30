/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : Motor
 * @about :
****************************************/

#include "DIO_Interface.h"
#include "Motor_config.h"
#include "Motor_interface.h"


void motor_Init(void)
{
    M_DIO_Void_SetPinDirection(MOTOR_E,OUTPUT);
    M_DIO_Void_SetPinDirection(MOTOR_F,OUTPUT);
    M_DIO_Void_SetPinDirection(MOTOR_B,OUTPUT);
}

void motor_F(void)
{
    M_DIO_Void_SetPinValue(MOTOR_E,HIGH);
    M_DIO_Void_SetPinValue(MOTOR_F,HIGH);
    M_DIO_Void_SetPinValue(MOTOR_B,LOW);
}

void motor_B(void)
{
    M_DIO_Void_SetPinValue(MOTOR_E,HIGH);
    M_DIO_Void_SetPinValue(MOTOR_F,LOW);
    M_DIO_Void_SetPinValue(MOTOR_B,HIGH);
}
