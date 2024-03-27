/******************************************************************
 * @name : Hossam Emad 
 * @date : 8/3/2023
 * @SWC  : I2C
 * @vesrion: V1.0
 * ****************************************************************/
#ifndef _I2C_PRIVATE_H_
#define _I2C_PRIVATE_H_

#define I2C_SC_STATE                    0x08
#define I2C_RSC_STATE                   0x10
#define I2C_SLA_R_TRNS_ACK_STATE        0x40
#define I2C_SLA_W_TRNS_ACK_STATE        0x18
#define I2C_D_RECIVE_ACK_STATE          0x50
#define I2C_D_SENT_ACK_STATE            0x28




/*I2C*/
#define I2C_TWBR_REG   *((volatile u8*)0XB8)
#define I2C_TWSR_REG   *((volatile u8*)0XB9)
#define I2C_TWAR_REG   *((volatile u8*)0XBA)
#define I2C_TWDR_REG   *((volatile u8*)0XBB)
#define I2C_TWCR_REG   *((volatile u8*)0XBC)
#define I2C_TWAMR_REG  *((volatile u8*)0XBD)

#endif