/******************************************************************
 * @name : Hossam Emad 
 * @date : 20/2/2024
 * @SWC  : SPI 
 * @vesrion: V1.0
 * ****************************************************************/
#ifndef _SPI_PRIVATE_H_
#define _SPI_PRIVATE_H_

#define SPI_U8_SPCR         *((volatile u8*)0x4C)
#define SPI_U8_SPDR         *((volatile u8*)0x4E)
#define SPI_U8_SPSR         *((volatile u8*)0x4D)

/*mode*/
#define SPI_U8_MASRER_MODE      1
#define SPI_U8_SLAVE_MODE       2

/*freq*/
#define SPI_SPEED_FOSC_4        0
#define SPI_SPEED_FOSC_16       1
#define SPI_SPEED_FOSC_64       2
#define SPI_SPEED_FOSC_128      3
#define SPI_SPEED_FOSC_2        4
#define SPI_SPEED_FOSC_8        5
#define SPI_SPEED_FOSC_32       6

#define SPI_LSB       0
#define SPI_MSB       0



#endif