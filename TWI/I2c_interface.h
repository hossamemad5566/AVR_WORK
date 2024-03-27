/******************************************************************
 * @name : Hossam Emad 
 * @date : 8/3/2023
 * @SWC  : I2C
 * @vesrion: V1.0
 * ****************************************************************/
#ifndef _I2C_INTERFACE_H_
#define _I2C_INTERFACE_H_

typedef enum 
{
    I2C_ok =1,
    I2C_SC_Error,
    I2C_RSC_Error,
    I2C_SLA_W_Error,
    I2C_SLA_OOR_Error,
    I2C_SLA_R_Error,
    I2C_D_SENT_Error,
    I2C_D_RECEIVE_Error,
    I2C_NULL_PTR_Error,

}I2C_ErrorState;

void I2C_voidMasterInit(void);

I2C_ErrorState  I2C_enumSlaveInit(u8 Copy_u8SA);

I2C_ErrorState I2C_enumSendSC(void);

I2C_ErrorState I2C_enumReSendStartC(void);

I2C_ErrorState I2C_enumSendSAWithWrite(u8 Copy_u8SA);

I2C_ErrorState I2C_enumSendSAWithRead (u8 Copy_u8SA);

I2C_ErrorState I2C_enumSendSAWithRead (u8 Copy_u8Data);

I2C_ErrorState I2C_enumReadDByte (u8 *Copy_u8Data);

void I2C_voidReSendStopC(void);



#endif