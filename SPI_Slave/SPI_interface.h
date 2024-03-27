/******************************************************************
 * @name : Hossam Emad 
 * @date : 20/2/2024
 * @SWC  : SPI 
 * @vesrion: V1.0
 * ****************************************************************/
#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_

void SPI_voidInint (void);

u8 SPI_u8SendReceiveByte(u8 copy_u8DataByte , u8 *copy_u8ReceiveByte);

u8 SPI_u8SendByte(u8 copy_u8DataByte);

u8 SPI_u8ReceiveByte(u8 *copy_u8ReceiveByte);


#endif