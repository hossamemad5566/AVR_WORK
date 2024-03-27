/******************************************************************
 * @name : Hossam Emad 
 * @date : 20/2/2024
 * @SWC  : SPI 
 * @vesrion: V1.0
 * ****************************************************************/
#ifndef _SPI_CONFIG_H_
#define _SPI_CONFIG_H_

#define SPI_MOSI_PIN	DIO_u8_PIN3
#define SPI_MOSI_PORT	DIO_u8_PORTB

#define SPI_MISO_PIN	DIO_u8_PIN4
#define SPI_MISO_PORT	DIO_u8_PORTB

#define SPI_CLK_PIN		DIO_u8_PIN5
#define SPI_CLK_PORT	DIO_u8_PORTB

/*preuse steps:
1- set i/o pins used in SPI
2- set SPI config 
3- use SPI functions 
*/

/*  SPI mode :
1-  SPI_U8_SLAVE_MODE
2-  SPI_U8_MASRER_MODE
*/
#define SPI_MODE SPI_U8_SLAVE_MODE
/*SPI SPEED:
 SPI_SPEED_FOSC_4
 SPI_SPEED_FOSC_16
 SPI_SPEED_FOSC_64
 SPI_SPEED_FOSC_128
 SPI_SPEED_FOSC_2
 SPI_SPEED_FOSC_8
 SPI_SPEED_FOSC_32
 */
#define SPI_CLK SPI_SPEED_FOSC_64

/*DATA ORDER:
SPI_LSB
SPI_MSB
*/
#define SPI_DATA_ORDER  SPI_MSB



#endif