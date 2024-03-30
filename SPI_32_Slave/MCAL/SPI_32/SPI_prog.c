/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : SPI
 * @about :
****************************************/



/****************************************
 ************** INCLUSION ***************
*****************************************/
#include "../../LIB/BitMath.h"
#include "../../LIB/STD.h"

#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"


/***********************************************
 * set MOSI and SCK output >> ALL others inputs
************************************************/
void SPI_MasterInit(void)
{
    /*enable SPI*/
    SPCR_REG.SPE=1;
    /*enable MASTER*/
    SPCR_REG.MSTR=1;
    /*setCLK: 16*/
    SPCR_REG.SPR1=1;
}

/***********************************************
 * copy_u8Data :  char u need to send
************************************************/
void SPI_MasterTransmit(u8 copy_u8Data)
{
    SPDR_REG.AllReg =copy_u8Data;
    /*wait for interrupt flag*/
     while(!(GET_BIT(SPSR_REG.AllReg,7)));
}

/***********************************************
 * set MISO output >> ALL others inputs
************************************************/
void SPI_SlaveInit(void)
{
    /*enable SPI*/
    SPCR_REG.SPE=1;
}

/***********************************************
 * return the received char data
************************************************/
u8 SPI_SlaveReceive (void)
{
    /*wait for interrupt flag*/
    while(!(GET_BIT(SPSR_REG.AllReg,7)));
    return SPDR_REG.AllReg;
}


