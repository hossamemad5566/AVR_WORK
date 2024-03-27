/*********************************************************
 * @name : Hossam Emad
 * @date : 1/12/2023
 * @swc: LCD 16*2
 * @version : V1.0
 * @description :
*********************************************************/
#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_

#define LCD4BIT 1
#define LCD8BIT 0

/* control pins */
#define LCD_u8_CONTROL_PORT       DIO_u8_PORTA
#define LCD_u8_RS_PIN             DIO_u8_PIN3
#define LCD_u8_RS_PORT            DIO_u8_PORTA
#define LCD_u8_E_PIN              DIO_u8_PIN2
#define LCD_u8_E_PORT             DIO_u8_PORTA
//#define LCD_u8_RW_PIN            DIO_u8_PIN2
/*RW pin is connected to GND as we just write to LCD*/

/* data port */
#define LCD_u8_DATA_PORT           DIO_u8_PORTB
#define LCD_u8_DATA_PIN7           DIO_u8_PIN4
#define LCD_u8_DATA7_PORT          DIO_u8_PORTB
#define LCD_u8_DATA_PIN6           DIO_u8_PIN2
#define LCD_u8_DATA6_PORT          DIO_u8_PORTB
#define LCD_u8_DATA_PIN5           DIO_u8_PIN1
#define LCD_u8_DATA5_PORT          DIO_u8_PORTB
#define LCD_u8_DATA_PIN4           DIO_u8_PIN0
#define LCD_u8_DATA4_PORT          DIO_u8_PORTB






#endif
