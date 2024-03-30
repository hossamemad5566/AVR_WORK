/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : SPI
 * @about :
****************************************/

#ifndef MCAL_SPI_INTERFACE_H_
#define MCAL_SPI_INTERFACE_H_

/***********************************************
 * set MOSI and SCK output >> ALL others inputs
************************************************/
void SPI_MasterInit(void);


/***********************************************
 * set MISO output >> ALL others inputs
************************************************/
void SPI_SlaveInit(void);

/***********************************************
 * copy_u8Data :  char u need to send
************************************************/
void SPI_MasterTransmit(u8 copy_u8Data);

/***********************************************
 * return the received char data
************************************************/
u8 SPI_SlaveReceive (void);

#endif 
