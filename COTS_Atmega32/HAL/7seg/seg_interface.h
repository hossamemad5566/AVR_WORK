/******************************************************************
 * @name : Hossam Emad 
 * @date : 1/3/2024
 * @SWC  : 7 seg
 * @vesrion: V1.0
 * ****************************************************************/
#ifndef _SEG_INTERFACE_H_
#define _SEG_INTERFACE_H_

/*7 seg_u8DipLocTime choices */
#define SEG_LOC_1   0
#define SEG_LOC_2   1
#define SEG_LOC_3   2
#define SEG_LOC_4   3




void Seg_voidInint(void);

u8 seg_u8DispDigit(u8 copy_u8digit);

u8 seg_u8DipLocTime(u8 copy_u8loc,u8 copy_u8digit,u16 copy_u16Period);

void seg_voidTurnAllOff(void);

void  seg_u8Disp4digit(u16 copy_u16_4digitnumber);
#endif
