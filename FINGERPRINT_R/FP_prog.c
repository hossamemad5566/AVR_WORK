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
        u8 ERR_5 :1;
        u8 ERR_6 :1;
        u8 ERR_7 :1;
    }STR;
    u8 ERR_all;
}ERRORS_;

ERRORS_ FP_ERRORS;

void UART_CallBackFunction (u8 Copy_u8UARTRecByte)
{
    if (ArrIndex <50)
	{
        App_u8UARTRecPack[ArrIndex] = Copy_u8UARTRecByte;
        ArrIndex++;
        // if(ArrIndex==9)
        // {
        //     // Combine the content of index 7 and index 8 into pack_u16Length
        //     pack_u16Length = (u16)((App_u8UARTRecPack[7] << 8) | App_u8UARTRecPack[8]); 
        //     if((pack_u16Length+9) > (u16)ArrIndex)
        //     {Completeflag=1; ArrIndex =0;}
        // }
        if (ArrIndex>=10)
        {Completeflag=1; ArrIndex =0;   pack_u16Length=3;}

    }
    else
    {
    	ArrIndex = 0;
    }
}

void FP_intit(void)
{
    /*rx and tx i\o */
    M_DIO_Void_SetPinDirection(PD1_PIN,OUTPUT);
    M_DIO_Void_SetPinDirection(PA6_PIN,OUTPUT);
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

#if 0
void FPReceiveACK(u16 copy_u8PackLength ,u8* copy_Pu8ACKarrPack)
{
    u8 Local_u8ReturnState =STD_OK;
    u16 local_u16counter =0;
    while((local_u16counter < 5000)&&(Completeflag ==0))
    {
        local_u16counter ++;
    }
    while((local_u16counter < 5000)&&(Completeflag ==0))
    {
        local_u16counter ++;
    }
    Completeflag =0;
    /*reset all errors flags*/
    FP_ERRORS.ERR_all=0;
    /*check header*/
    if((App_u8UARTRecPack[0]!=0xEF) && (App_u8UARTRecPack[1]!=0x01))   
        {FP_ERRORS.STR.ERR_header=1;}
    /*check add*/
    if((App_u8UARTRecPack[2]!=0xFF) && (App_u8UARTRecPack[3]!=0xFF)&&(App_u8UARTRecPack[4]!=0xFF) && (App_u8UARTRecPack[5]!=0xFF))   
        {FP_ERRORS.STR.ERR_add=1;}
    /*check PID*/
    if(App_u8UARTRecPack[6]!=PID_ACK) 
        {FP_ERRORS.STR.ERR_PID =1;}
    /*check pack length */
    if(pack_u16Length != copy_u8PackLength) 
        {FP_ERRORS.STR.ERR_PL =1;}
    for(int i=0;i<copy_u8PackLength;i++)
    {
        if(App_u8UARTRecPack[i+9] !=  copy_Pu8ACKarrPack[i])
        {FP_ERRORS.STR.ERR_pac =1;break;}
    }
}
#endif

void FPReceiveACK(u8 copy_u8code)
{
    if(Completeflag ==1)
    {
        Completeflag =0;
        /*reset all errors flags*/
        FP_ERRORS.ERR_all=0;
        /*check header*/
        if((App_u8UARTRecPack[0]!=0xEF) && (App_u8UARTRecPack[1]!=0x01))   
            {FP_ERRORS.STR.ERR_header=1;}
        /*check add*/
        if((App_u8UARTRecPack[2]!=0xFF) && (App_u8UARTRecPack[3]!=0xFF)&&(App_u8UARTRecPack[4]!=0xFF) && (App_u8UARTRecPack[5]!=0xFF))   
            {FP_ERRORS.STR.ERR_add=1;}
        /*check PID*/
        if(App_u8UARTRecPack[6]!=PID_ACK) 
            {FP_ERRORS.STR.ERR_PID =1;}
        /*check pack length */
        if(App_u8UARTRecPack[8]!= 0x03) 
            {FP_ERRORS.STR.ERR_PL =1;}
        /*check ack*/
        if(App_u8UARTRecPack[9]!= copy_u8code) 
            {FP_ERRORS.STR.ERR_pac =1;}
    }
}

u8 ShakeHand(void)
{
    u8 pack_content[1] = {0x40};
    u8 pack_ACK = 0x00;

    /*send*/
    FPSend(PID_CMND,3,pack_content);
    /*receive*/
    while(Completeflag==0);
    test();
    return FP_ERRORS.ERR_all;
}



void test (void)
{
    if(Completeflag ==1)
    {
        Completeflag =0;
        /*reset all errors flags*/
        FP_ERRORS.ERR_all=0;
        /*check header*/
        if((App_u8UARTRecPack[0]!='Z') && (App_u8UARTRecPack[1]!='X'))   
            {FP_ERRORS.STR.ERR_header=1;}
        /*check add*/
        if((App_u8UARTRecPack[2]!='C') && (App_u8UARTRecPack[3]!='C')&&(App_u8UARTRecPack[4]!='C') && (App_u8UARTRecPack[5]!='C'))   
            {FP_ERRORS.STR.ERR_add=1;}
        /*check PID*/
        if(App_u8UARTRecPack[6]!='7') 
            {FP_ERRORS.STR.ERR_PID =1;}
        /*check pack length */
        if(App_u8UARTRecPack[8]!= '7') 
            {FP_ERRORS.STR.ERR_PL =1;}
        /*check ack*/
        if(App_u8UARTRecPack[9]!= '7') 
            {FP_ERRORS.STR.ERR_pac =1;}
    }
}

