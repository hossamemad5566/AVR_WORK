/******************************************************************
 * @name : Hossam Emad 
 * @date : 9/3/2023
 * @SWC  : EEPROM
 * @vesrion: V1.0
 * ***************************************************************/
/*lib*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/*MCAL*/
#include "I2c_interface.h"
/*HAL*/
#include "EEPROM_private.h"
#include "EEPROM_interface.h"
#include "EEPROM_Config.h"



void EEPROM_voidInit (void) 
{
    I2C_voidMasterInit();
}

u8 EEPROM_u8WriteByte (u16 Copy_u16ByteAddress, u8 Copy_u8DataByte) 
{
    u8 local_u8ErrorState = STD_TYPE_OK;
    I2C_ErrorState local_enumI2CErrorState = I2C_ok;
    /*1- start cond*/
    local_enumI2CErrorState = I2C_enumSendSC();
    /*check if done*/
    local_u8ErrorState = private_u8CheckError(local_enumI2CErrorState);
    /*2- sned SLA +W */
    local_enumI2CErrorState = I2C_enumSendSAWithWrite(Copy_u16ByteAddress);
    

}

u8 EEPROM_u8ReadByte (u16 Copy_u16ByteAddress, u8 * Copy_pu8RecDataByte) 
{

}

static u8 private_u8CheckError(I2C_ErrorState copy_enumErrorState)
{
    u8 local_u8ErrorState = STD_TYPE_OK;
    if (I2C_ok != copy_enumErrorState)
    {
        local_u8ErrorState = STD_TYPE_NOK;
    }
    return local_u8ErrorState;
}

/*=======================================================*/
/**Enhancement*/
/*=======================================================*/
/*
add page def
#define PAGE0  0
#define PAGE1  1
#define PAGE2  2
#define PAGE3  3
#define PAGE4  4
#define PAGE5  5
#define PAGE6  6
#define PAGE7  7
*/
/*
add switch of page
switch (Local_u8Page)
{
    case PAGE0:I2C_enumSendSAWithWrite(0b01010000);break;
    case PAGE1:I2C_enumSendSAWithWrite(0b01010001);break;
    case PAGE2:I2C_enumSendSAWithWrite(0b01010010);break;
    case PAGE3:I2C_enumSendSAWithWrite(0b01010011);break;
    case PAGE4:I2C_enumSendSAWithWrite(0b01010100);break;
    case PAGE5:I2C_enumSendSAWithWrite(0b01010101);break;
    case PAGE6:I2C_enumSendSAWithWrite(0b01010110);break;
    case PAGE7:I2C_enumSendSAWithWrite(0b01010111);break;
}
*/