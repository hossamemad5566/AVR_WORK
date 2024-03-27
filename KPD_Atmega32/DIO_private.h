// /******************************************************************
 * @name : Hossam Emad 
 * @date : 1/3/2024
 * @SWC  : DIO 
 * @vesrion: V1.0
 * ****************************************************************/
#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_
/**************
 * Here we define pointers to the addresses of the registers 
 * of the AVR Micro_controller
 * ========================================================
 * we use volatile to prevent the optimizes from deleting these pointers 
//  * we use explicit casting to tell the compiler that these numbers are addresses
*/
#define DIO_PORTA_REG   *((volatile u8*)0X3B)
#define DIO_DDRA_REG    *((volatile u8*)0X3A)
#define DIO_PINA_REG    *((volatile u8*)0X39)

#define DIO_PORTB_REG   *((volatile u8*)0X38)
#define DIO_DDRB_REG    *((volatile u8*)0X37)
#define DIO_PINB_REG    *((volatile u8*)0X36)

#define DIO_PORTC_REG   *((volatile u8*)0X35)
#define DIO_DDRC_REG    *((volatile u8*)0X34)
#define DIO_PINC_REG    *((volatile u8*)0X33)

#define DIO_PORTD_REG   *((volatile u8*)0X32)
#define DIO_DDRD_REG    *((volatile u8*)0X31)
#define DIO_PIND_REG    *((volatile u8*)0X30)

/*MACROS FOR PIN DIRECTIONS*/
#define DIO_u8_INIT_INPUT   0
#define DIO_u8_INIT_OUTPUT  1

/*MACROS FOR PIN INITIAL VALUES*/
#define DIO_u8_INIT_HIGH        1
#define DIO_u8_INIT_LOW         0
#define DIO_u8_INIT_PULLUP      1
#define DIO_u8_INIT_FLOATING    0

/*functions of the CONC*/
#define      CONC(a7,a6,a5,a4,a3,a2,a1,a0)         CONC_HELP(a7,a6,a5,a4,a3,a2,a1,a0)  
#define CONC_HELP(a7,a6,a5,a4,a3,a2,a1,a0)         (0b##a7##a6##a5##a4##a3##a2##a1##a0)

#endif
