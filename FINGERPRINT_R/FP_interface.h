/***************************************
 * @author : Hossam Emad
 * @date : 22/3/2024
 * @SWC : FingerPrint 
 * @about :
****************************************/
#ifndef _FP_INTERFACE_H_
#define _FP_INTERFACE_H_
#include "FP_private.h"

#define PID_CMND    CMND_PACK
#define PID_DATA    DATA_PACK
#define PID_ACK     ACK_PACK
#define PID_END     END_PACK


/****************************************
*1- u need to config the uart in 57600 
*2- set stop bits to one  
****************************************/
void FP_intit(void);

/*************************************************************
*1- copy_u8PID : PID_CMND   PID_DATA   PID_ACK    PID_END
*2- Copy_u16PackLength: array size (0>>256) (array + 2"check sum bits")
*3- copy_Pu8Pack : address of the message array
**************************************************************/
u8 FPSend(u8 copy_u8PID,u16 Copy_u16PackLength,u8* copy_Pu8Pack);

/*************************************************************
*1- copy_u8PackLength : array size (0>>256) (array + 2"check sum bits")
*2- copy_Pu8ACKarrPack : address of the message array and CS bits 
**************************************************************/
void FPReceiveACK(u8 copy_u8code);


u8 ShakeHand(void);

void test (void);

#endif
