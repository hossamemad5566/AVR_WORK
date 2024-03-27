/*DIO*/
#define DIO_PORTB_REG   *((volatile u8*)0X25)
#define DIO_DDRB_REG    *((volatile u8*)0X24)
#define DIO_PINB_REG    *((volatile u8*)0X23)

#define DIO_PORTC_REG   *((volatile u8*)0X28)
#define DIO_DDRC_REG    *((volatile u8*)0X27)
#define DIO_PINC_REG    *((volatile u8*)0X26)

#define DIO_PORTD_REG   *((volatile u8*)0X2B)
#define DIO_DDRD_REG    *((volatile u8*)0X2A)
#define DIO_PIND_REG    *((volatile u8*)0X29)


/*I2C*/
#define I2C_TWSR_REG   *((volatile u8*)0XB9)
#define I2C_TWAR_REG   *((volatile u8*)0XBA)
#define I2C_TWDR_REG   *((volatile u8*)0XBB)
#define I2C_TWCR_REG   *((volatile u8*)0XBC)
#define I2C_TWAMR_REG  *((volatile u8*)0XBD)