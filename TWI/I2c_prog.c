/******************************************************************
 * @name : Hossam Emad 
 * @date : 8/3/2023
 * @SWC  : I2C
 * @vesrion: V1.0
 * ****************************************************************/
/*lib*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA328p_memoryMap.h"
/*MCAL*/
#include "I2C_private.h"
#include "I2C_config.h"
#include "I2c_interface.h"


void I2C_voidMasterInit(void)
{
    /*set prescaler : 1 */
    CLR_BIT(I2C_TWSR_REG,1);    CLR_BIT(I2C_TWSR_REG,0);
    /*calculate TWBR value : 200KHZ  */
    I2C_TWBR_REG = 32; 
    /*Enable ACK*/
    SET_BIT(I2C_TWCR_REG,6); 
    /*Enable I2C*/
    SET_BIT(I2C_TWCR_REG,2); 
}

I2C_ErrorState  I2C_enumSlaveInit(u8 Copy_u8SA)
{
    I2C_ErrorState Local_enumErrorState = I2C_ok;
    /*0000000 , 1111xxx limitations*/
    /*2^7 = 128 ,, 1111xxx = min 120  */
    if ((Copy_u8SA < 120)&& (Copy_u8SA >0))
    {
       /*set slave add Most 7 Bits*/
        I2C_TWAR_REG = Copy_u8SA<<1;
        /*Enable I2C*/
        SET_BIT(I2C_TWCR_REG,2); 
    }
    else 
    {
        Local_enumErrorState = I2C_SLA_OOR_Error;
    }
    

    return Local_enumErrorState;
}

I2C_ErrorState I2C_enumSendSC(void)
{
    I2C_ErrorState Local_enumErrorState = I2C_ok;
    u16 Local_u16CNT = 0;/*counter for non blocking*/
    /*start condition*/
    SET_BIT(I2C_TWCR_REG,5);
    /*clear flag */
    SET_BIT(I2C_TWCR_REG,7);
    /*wait for the flag*/
    while(!(GET_BIT(I2C_TWCR_REG,7))&&(Local_u16CNT <5000))
    {
        Local_u16CNT++;
    }
    /*check status code : start cond*/
    if((I2C_TWSR_REG&0xF8)!=I2C_SC_STATE)
    {
        Local_enumErrorState = I2C_SC_Error;
    }
    else
    {
        /*clear start cond*/
        CLR_BIT(I2C_TWCR_REG,5);
    }
    
    return Local_enumErrorState;
}

I2C_ErrorState I2C_enumReSendStartC(void)
{
    I2C_ErrorState Local_enumErrorState = I2C_ok;
    u16 Local_u16CNT = 0;/*counter for non blocking*/
    /*start condition*/
    SET_BIT(I2C_TWCR_REG,5);
    /*clear flag */
    SET_BIT(I2C_TWCR_REG,7);
    /*wait for the flag*/
    while(!(GET_BIT(I2C_TWCR_REG,7))&&(Local_u16CNT <5000))
    {
        Local_u16CNT++;
    }
    /*check status code : R start cond*/
    if((I2C_TWSR_REG&0xF8)!=I2C_RSC_STATE)
    {
        Local_enumErrorState = I2C_RSC_Error;
    }
    else
    {
        /*clear start cond*/
        CLR_BIT(I2C_TWCR_REG,5);
    }
    return Local_enumErrorState;
}


I2C_ErrorState I2C_enumSendSAWithWrite(u8 Copy_u8SA)
{
    u16 Local_u16CNT = 0;/*counter for non blocking*/
    I2C_ErrorState Local_enumErrorState = I2C_ok;
    /*check slave add within range*/
    if ((Copy_u8SA < 120)&& (Copy_u8SA >0))
    {
       /*set in TWDR = slave add + 0 */
        I2C_TWDR_REG = (Copy_u8SA<<1);
        /*clear flag */
        SET_BIT(I2C_TWCR_REG,7);
        /*wait for the flag*/
        while(!(GET_BIT(I2C_TWCR_REG,7))&&(Local_u16CNT <5000))
        {
            Local_u16CNT++;
        }
        /*check status code :SA + W*/
        if((I2C_TWSR_REG&0xF8)!=I2C_SLA_W_TRNS_ACK_STATE)
        {
            Local_enumErrorState = I2C_SLA_W_Error;
        } 
    }
    else 
    {
        Local_enumErrorState = I2C_SLA_OOR_Error;
    }
    return Local_enumErrorState;

}

I2C_ErrorState I2C_enumSendSAWithRead (u8 Copy_u8SA)
{
    u16 Local_u16CNT = 0;/*counter for non blocking*/
    I2C_ErrorState Local_enumErrorState = I2C_ok;
    /*check slave add within range*/
    if ((Copy_u8SA < 120)&& (Copy_u8SA >0))
    {
       /*set in TWDR = slave add + 0 */
        I2C_TWDR_REG = (Copy_u8SA<<1);
        SET_BIT(I2C_TWDR_REG,0);
        /*clear flag */
        SET_BIT(I2C_TWCR_REG,7);
        /*wait for the flag*/
        while(!(GET_BIT(I2C_TWCR_REG,7))&&(Local_u16CNT <5000))
        {
            Local_u16CNT++;
        }
        /*check status code :SA + W*/
        if((I2C_TWSR_REG&0xF8)!=I2C_SLA_R_TRNS_ACK_STATE)
        {
            Local_enumErrorState = I2C_SLA_R_Error;
        } 
    }
    else 
    {
        Local_enumErrorState = I2C_SLA_OOR_Error;
    }
    return Local_enumErrorState;

}

I2C_ErrorState I2C_enumSendSAWithRead (u8 Copy_u8Data)
{
    u16 Local_u16CNT = 0;/*counter for non blocking*/
    I2C_ErrorState Local_enumErrorState = I2C_ok;
    /*set in TWDR = Data */
    I2C_TWDR_REG = (Copy_u8Data<<1);
    /*clear flag */
    SET_BIT(I2C_TWCR_REG,7);
    /*wait for the flag*/
    while(!(GET_BIT(I2C_TWCR_REG,7))&&(Local_u16CNT <5000))
    {
        Local_u16CNT++;
    }
    /*check status code :SA + W*/
    if((I2C_TWSR_REG&0xF8)!= I2C_D_SENT_ACK_STATE)
    {
        Local_enumErrorState = I2C_D_SENT_Error;
    } 
    return Local_enumErrorState;
}


I2C_ErrorState I2C_enumReadDByte (u8 *Copy_u8Data)
{
    u16 Local_u16CNT = 0;/*counter for non blocking*/
    I2C_ErrorState Local_enumErrorState = I2C_ok;
    /*check pointer*/
    if (Copy_u8Data == NULL)
    {
        /*clear flag */
        SET_BIT(I2C_TWCR_REG,7);
        /*wait for the flag*/
        while(!(GET_BIT(I2C_TWCR_REG,7))&&(Local_u16CNT <5000))
        {
            Local_u16CNT++;
        }
        /* check Status code => Data  RECEIVE */
        if((I2C_TWSR_REG&0xF8)!= I2C_D_RECIVE_ACK_STATE)
        {
            Local_enumErrorState = I2C_D_RECEIVE_Error;
        } 
        else
        {
            /*read data from TWDR*/
            *Copy_u8Data = I2C_TWDR_REG;
        }
    
    }
    else
    {
        Local_enumErrorState = I2C_NULL_PTR_Error;
    }
    return Local_enumErrorState;
}

void I2C_voidReSendStopC(void)
{
    /*send stop condition*/
    SET_BIT(I2C_TWCR_REG,4);
    /*clear flag */
    SET_BIT(I2C_TWCR_REG,7);
}