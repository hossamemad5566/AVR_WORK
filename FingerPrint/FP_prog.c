/***************************************
 * @author : Hossam Emad
 * @date : 22/3/2024
 * @SWC : FingerPrint 
 * @about :
****************************************/
#include "BitMath.h"
#include "STD.h"
#include <util/delay.h>

#include "DIO_Interface.h"
#include "GIE_interface.h"
#include "UART_Interface.h"
#include "LCD_Interface.h"

#include "FP_config.h"
#include "FP_private.h"
#include "FP_interface.h"

/*receive*/
u8 App_u8UARTRecPack[50];
u8 ArrIndex=0;
u16 pack_u16Length=0;
u8 Completeflag =0;
typedef union
{
    struct{
        u8 ERR_header :1;
        u8 ERR_add :1;
        u8 ERR_PID :1;
        u8 ERR_PL :1;
        u8 ERR_pac :1;
        u8 ERR_CS :1;
        u8 ERR_6 :1;
        u8 ERR_7 :1;
    }STR;
    u8 ERR_all;
}ERRORS_;

ERRORS_ FP_ERRORS;

/*CHECK INTRO*/
void FP_checkintro(void)
{
    /*reset all errors flags*/
    FP_ERRORS.ERR_all=0;
    /*check header:0,1*/
    if((App_u8UARTRecPack[0]!=0xEF) && (App_u8UARTRecPack[1]!=0x01))   
        {FP_ERRORS.STR.ERR_header=1;}
    /*check add:2>>5*/
    if((App_u8UARTRecPack[2]!=0xFF) && (App_u8UARTRecPack[3]!=0xFF)&&(App_u8UARTRecPack[4]!=0xFF) && (App_u8UARTRecPack[5]!=0xFF))   
        {FP_ERRORS.STR.ERR_add=1;}
}

void UART_CallBackFunction (u8 Copy_u8UARTRecByte)
{
    if(ArrIndex<50)
    {
        App_u8UARTRecPack[ArrIndex] = Copy_u8UARTRecByte;
        /*FOR debugging*/
        //H_Lcd_Void_LCDWriteCharacter(App_u8UARTRecPack[ArrIndex]);
        ArrIndex++;
    }
    else 
    {ArrIndex=0;}     
}

void FP_intit(void)
{
    /*rx and tx i\o */
    M_DIO_Void_SetPinDirection(PD1_PIN,OUTPUT);
    M_DIO_Void_SetPinDirection(PD0_PIN,INPUT);
    _delay_ms(200);
    UART_Init();
    /*receive*/
    GIE_voidEnable();
    UART_ReceiveByteAsyncCallBack(UART_CallBackFunction);
}
  
u8 FPSend(u8 copy_u8PID,u16 Copy_u16PackLength,u8* copy_Pu8Pack)
{
    u8 local_u8RetuenState = STD_NOK;
    u16 Local_u16CS=0;
    u8 arraySize = Copy_u16PackLength-2;//pack length refer to array length + 2 bits check sum
    /*header*/
    UART_SendByte(0xEF);
    UART_SendByte(0x01);
    /*add*/
    UART_SendByte(0xFF);
    UART_SendByte(0xFF);
    UART_SendByte(0xFF);
    UART_SendByte(0xFF);
    /*package identifier*/
    switch (copy_u8PID)
    {
    case CMND_PACK:UART_SendByte(CMND_PACK);   break;
    case DATA_PACK:UART_SendByte(DATA_PACK);   break;
    case ACK_PACK :UART_SendByte(ACK_PACK);    break;
    case END_PACK :UART_SendByte(END_PACK);    break;
    default:                                   break;
    }
    /*PACKAGE LENGTH*/
    UART_SendByte((u8)(Copy_u16PackLength>>8));
    UART_SendByte((u8)Copy_u16PackLength);
    /*package sending*/
    if ((copy_Pu8Pack != NULL)&&(Copy_u16PackLength<=256))
	{
		for(int i =0 ;i<arraySize;i++)
		{
			UART_SendByte(copy_Pu8Pack[i]);
            Local_u16CS += copy_Pu8Pack[i];
		}
	}
	else
	{
		local_u8RetuenState = STD_NOK;
	}
    /*CHECK SUM*/
    Local_u16CS +=(Copy_u16PackLength +(u16)copy_u8PID); 
    UART_SendByte((Local_u16CS>>8));
    UART_SendByte(Local_u16CS);
    return local_u8RetuenState;
}

void FPReceiveACK(u8 copy_u8code)
{
    FP_checkintro();
    /*check PID:6*/
    if(App_u8UARTRecPack[6]!=PID_ACK) 
        {FP_ERRORS.STR.ERR_PID =1;}
    /*check pack length:7,8*/
    if(App_u8UARTRecPack[8]!= 0x03) 
        {FP_ERRORS.STR.ERR_PL =1;}
    /*check ack:9*/
    if(App_u8UARTRecPack[9]!= copy_u8code) 
        {FP_ERRORS.STR.ERR_pac =1;}
    /*CHECKSUM: 10,11*/ 
    if(0x0A !=App_u8UARTRecPack[11] )
         {FP_ERRORS.STR.ERR_CS =1;}
}

u8 FingerPS_handShake(void)
{
    u8 pack_content[1] = {0x40};
    u8 pack_ACK = 0x00;

    /*send*/
    FPSend(PID_CMND,3,pack_content);
    /*receive*/
    while(ArrIndex <12);/*TODO: need to be enhanced*/
    Completeflag =1;
    //test();
    FPReceiveACK(pack_ACK);
    Completeflag =0;
    ArrIndex=0;
    return FP_ERRORS.ERR_all;
}

u8 FingerPS_genImg(void)
{
    u8 pack_content[1] = {0x01};
    u8 pack_ACK = 0x00;
    /*send*/
    FPSend(PID_CMND,3,pack_content);
    /*receive*/
    while(ArrIndex <12);/*TODO: need to be enhanced*/
    Completeflag =1;
    FPReceiveACK(pack_ACK);
    Completeflag =0;
    ArrIndex=0;
    return FP_ERRORS.ERR_all;
}

u8 FingerPS_genTemplate(void)
{
    u8 pack_content[1] = {0x05};
    u8 pack_ACK = 0x00;
    /*send*/
    FPSend(PID_CMND,3,pack_content);
    /*receive*/
    while(ArrIndex <12);/*TODO: need to be enhanced*/
    Completeflag =1;
    FPReceiveACK(pack_ACK);
    Completeflag =0;
    ArrIndex=0;
    return FP_ERRORS.ERR_all;
}

u8 FingerPS_ConvertImg2CharFile(u8 Copy_u8bufferID)
{
    u8 pack_content[2] = {0x02,Copy_u8bufferID};
    u8 pack_ACK = 0x00;
    /*send*/
    FPSend(PID_CMND,4,pack_content);
    /*receive*/
    while(ArrIndex <12);/*TODO: need to be enhanced*/
    Completeflag =1;
    FPReceiveACK(pack_ACK);
    Completeflag =0;
    ArrIndex=0;
    return FP_ERRORS.ERR_all;
}

u8 FingerPS_LoadCharFile(u8 Copy_u8bufferID,u8 Copy_u8PageID)
{
    u8 pack_content[4] = {0x07,Copy_u8bufferID,Copy_u8PageID};
    u8 pack_ACK = 0x00;
    /*send*/
    FPSend(PID_CMND,6,pack_content);
    /*receive*/
    while(ArrIndex <12);/*TODO: need to be enhanced*/
    Completeflag =1;
    FPReceiveACK(pack_ACK);
    Completeflag =0;
    ArrIndex=0;
    return FP_ERRORS.ERR_all;
}

u8 FingerPS_Match(void)
{
    u8 pack_content[1] = {0x03};
    u8 pack_ACK = 0x00;
    /*send*/
    FPSend(PID_CMND,3,pack_content);
    /*receive*/
    while(ArrIndex <14);/*TODO: need to be enhanced*/
    Completeflag =1;
    /*different in receiving*/
    FP_checkintro();
    if(0x0C !=App_u8UARTRecPack[13] )
         {FP_ERRORS.STR.ERR_CS =1;}
    Completeflag =0;
    ArrIndex=0;
    return FP_ERRORS.ERR_all;
}

u8 FingerPS_Auraked(u8 copy_u8Control,u8 copy_u8Speed,u8 copy_u8Color,u8 copy_u8Cycles)
{
    u8 pack_content[5] = {0x35,copy_u8Control,copy_u8Speed,copy_u8Color,copy_u8Cycles};
    u8 pack_ACK = 0x00;
    /*send*/
    FPSend(PID_CMND,7,pack_content);
    /*receive*/
    while(ArrIndex <12);/*TODO: need to be enhanced*/
    Completeflag =1;
    FPReceiveACK(pack_ACK);
    Completeflag =0;
    ArrIndex=0;
    return FP_ERRORS.ERR_all;
}



#if 0
void test (void)
{
    if(Completeflag ==1)
    {
        /*reset all errors flags*/
        FP_ERRORS.ERR_all=0;
        /*check header*/
        if((App_u8UARTRecPack[0]!=0X5A) && (App_u8UARTRecPack[1]!=0X58))   
            {FP_ERRORS.STR.ERR_header=1;}
        /*check add*/
        if((App_u8UARTRecPack[2]!=0X43) && (App_u8UARTRecPack[3]!=0X43)&&(App_u8UARTRecPack[4]!=0X43) && (App_u8UARTRecPack[5]!=0X43))   
            {FP_ERRORS.STR.ERR_add=1;}
        /*check PID*/
        if(App_u8UARTRecPack[6]!=0X37) 
            {FP_ERRORS.STR.ERR_PID =1;}
        /*check pack length */
        if(App_u8UARTRecPack[8]!= 0X37) 
            {FP_ERRORS.STR.ERR_PL =1;}
        /*check ack*/
        if(App_u8UARTRecPack[9]!= 0X37) 
            {FP_ERRORS.STR.ERR_pac =1;}
    }
    /*frame: ZXCCCC7777*/
}
#endif
