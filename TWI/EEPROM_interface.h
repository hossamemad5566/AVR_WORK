/******************************************************************
 * @name : Hossam Emad 
 * @date : 9/3/2023
 * @SWC  : EEPROM
 * @vesrion: V1.0
 * ****************************************************************/
#ifndef _EEPROM_INTERFACE_H_
#define _EEPROM_INTERFACE_H_



void EEPROM_voidInit (void) ;

u8 EEPROM_u8WriteByte (u16 Copy_u16ByteAddress, u8 Copy_u8DataByte) ;

u8 EEPROM_u8ReadByte (u16 Copy_u16ByteAddress, u8 * Copy_pu8RecDataByte) ;

#endif