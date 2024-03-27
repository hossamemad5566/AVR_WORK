/******************************************************************
 * @name : Hossam Emad 
 * @date : 20/2/2024
 * @SWC  : SPI 
 * @vesrion: V1.0
 * ****************************************************************/
#include "STD_TYPES.h"
#include"BIT_MATH.h"

/* MCAL layer */
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_voidInint (void)
{
    #if ((SPI_MODE==SPI_U8_MASRER_MODE))
    /*master / slave select: master*/
    SET_BIT(SPI_U8_SPCR,4);
    /*SPI clock select */
    #if(SPI_CLK == SPI_SPEED_FOSC_4)
    CLR_BIT(SPI_U8_SPSR,0);    CLR_BIT(SPI_U8_SPCR,1);    CLR_BIT(SPI_U8_SPCR,0);
    #elif(SPI_CLK == SPI_SPEED_FOSC_16)
    CLR_BIT(SPI_U8_SPSR,0);    CLR_BIT(SPI_U8_SPCR,1);    SET_BIT(SPI_U8_SPCR,0);
    #elif(SPI_CLK == SPI_SPEED_FOSC_64)
    CLR_BIT(SPI_U8_SPSR,0);    SET_BIT(SPI_U8_SPCR,1);    CLR_BIT(SPI_U8_SPCR,0);
    #elif(SPI_CLK == SPI_SPEED_FOSC_128)
    CLR_BIT(SPI_U8_SPSR,0);    SET_BIT(SPI_U8_SPCR,1);    SET_BIT(SPI_U8_SPCR,0);
    #elif(SPI_CLK == SPI_SPEED_FOSC_2)
    SET_BIT(SPI_U8_SPSR,0);    CLR_BIT(SPI_U8_SPCR,1);    CLR_BIT(SPI_U8_SPCR,0);
    #elif(SPI_CLK == SPI_SPEED_FOSC_8)
    SET_BIT(SPI_U8_SPSR,0);    SET_BIT(SPI_U8_SPCR,1);    CLR_BIT(SPI_U8_SPCR,0);
    #elif(SPI_CLK == SPI_SPEED_FOSC_32)
    SET_BIT(SPI_U8_SPSR,0);    SET_BIT(SPI_U8_SPCR,1);    SET_BIT(SPI_U8_SPCR,0);
    #endif
    #elif(SPI_MODE==SPI_U8_SLAVE_MODE)
    /*master / slave select: slave*/
    CLR_BIT(SPI_U8_SPCR,4);
    #endif
    
    /*Data Order : MSB*/
    #if (SPI_DATA_ORDER == SPI_MSB)
    CLR_BIT(SPI_U8_SPCR,5);
    #elif (SPI_DATA_ORDER == SPI_LSB)
    SET_BIT(SPI_U8_SPCR,5);
    #endif

    
    /*choose clk polarity:Falling*/
    SET_BIT(SPI_U8_SPCR,3);
    /*choose clk phase: setup/sample */
    SET_BIT(SPI_U8_SPCR,2);
    /*enable SPI*/
    SET_BIT(SPI_U8_SPCR,6);
}

u8 SPI_u8SendReceiveByte(u8 copy_u8DataByte , u8 *copy_u8ReceiveByte)
{
    u8 local_u8ReturnType =STD_TYPE_OK;
    /*send byte*/
    if(copy_u8ReceiveByte != NULL)
    {
        /*write data*/
        u16 local_u16Counter = 0;
        SPI_U8_SPDR = copy_u8DataByte;
        /*CHECK Flag*/
        while ((local_u16Counter++ <5000 ) && !(GET_BIT(SPI_U8_SPSR,7)));
        /*read data*/
        *copy_u8ReceiveByte = SPI_U8_SPDR;   
    }
    else
    {
        local_u8ReturnType = STD_TYPE_NOK;
    }
    return local_u8ReturnType;
}

u8 SPI_u8SendByte(u8 copy_u8DataByte)
{
    SPI_U8_SPDR = copy_u8DataByte;
}

u8 SPI_u8ReceiveByte(u8 *copy_u8ReceiveByte)
{
     u8 local_u8ReturnType =STD_TYPE_OK;
    /*send byte*/
    if(copy_u8ReceiveByte != NULL)
    {
        /*write data*/
        u16 local_u16Counter = 0;
        /*CHECK Flag*/
        while ((local_u16Counter++ <5000 ) && !(GET_BIT(SPI_U8_SPSR,7)));
        /*read data*/
        *copy_u8ReceiveByte = SPI_U8_SPDR;   
    }
    else
    {
        local_u8ReturnType = STD_TYPE_NOK;
    }
    return local_u8ReturnType;
}