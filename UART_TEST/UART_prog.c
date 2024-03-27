#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_private.h"
#include "UART_config.h"
#include "UART_interface.h"

#define NONBLOCKONG_TIME_OUT    5000

void UART_voidInit(void)
{
    u8 local_u8Temp =0;

    /*set Baud rate :9600*/
    UART_UBRROL =(u16)UART_BAUD_RATE;

    /*normal speed*/
    //CLR_BIT(local_u8Temp,1);
    /*this line is because bit 2 , 3 & 4 must be zero when we write to this reg*/
    UART_UCSROA=local_u8Temp;

    /*data frame size */
    #if   (UART_CHAR_SIZE == UART_Frame_5)
    CLR_BIT(UART_UCSROB,2);     CLR_BIT(UART_UCSROC,2);     CLR_BIT(UART_UCSROC,1);
    #elif (UART_CHAR_SIZE == UART_Frame_6)
    CLR_BIT(UART_UCSROB,2);     CLR_BIT(UART_UCSROC,2);     SET_BIT(UART_UCSROC,1);
    #elif (UART_CHAR_SIZE == UART_Frame_7)
    CLR_BIT(UART_UCSROB,2);     SET_BIT(UART_UCSROC,2);     CLR_BIT(UART_UCSROC,1);
    #elif (UART_CHAR_SIZE == UART_Frame_8)
    CLR_BIT(UART_UCSROB,2);     SET_BIT(UART_UCSROC,2);     SET_BIT(UART_UCSROC,1);
    #elif (UART_CHAR_SIZE == UART_Frame_9)
    SET_BIT(UART_UCSROB,2);     SET_BIT(UART_UCSROC,2);     SET_BIT(UART_UCSROC,1);

    #endif
    /*enable EX and RX*/
    SET_BIT(UART_UCSROB,3);
    SET_BIT(UART_UCSROB,4);

    /*select async operation*/
    #if  (UART_MODE == UART_ASYNC)
    CLR_BIT(UART_UCSROC,7);     CLR_BIT(UART_UCSROC,6);
    #elif (UART_MODE == UART_SYNC)
    CLR_BIT(UART_UCSROC,7);     SET_BIT(UART_UCSROC,6);
    #elif (UART_MODE == UART_MSPIM)
    SET_BIT(UART_UCSROC,7);     SET_BIT(UART_UCSROC,6);
    #endif

    /*parity bit*/
    #if(UART_PB == PB_DISABLE)
    CLR_BIT(UART_UCSROC,5);     CLR_BIT(UART_UCSROC,4);
    #elif(UART_PB == PB_EVEN)
    SET_BIT(UART_UCSROC,5);     CLR_BIT(UART_UCSROC,4);
    #elif(UART_PB == PB_ODD)
    SET_BIT(UART_UCSROC,5);     SET_BIT(UART_UCSROC,4);
    #endif
    
    /*enable 2 stop bits*/
    #if(UART_SB_NO == UART_SB_2)
    SET_BIT(UART_UCSROC,3);
    #elif(UART_SB_NO == UART_SB_1)
    CLR_BIT(UART_UCSROC,3);
    #endif

}

void UART_u8SendsyncByte(u8 Copy_u8DataByte)
{

    u16 Local_u8_TUpCnt = 0;
    /*check that TX is empty :  UDRE bit*/
    while((GET_BIT(UART_UCSROA,5)==0)&& (Local_u8_TUpCnt<NONBLOCKONG_TIME_OUT) )
    {
        Local_u8_TUpCnt++;
    }
    /*write data to TX reg*/
    UART_UDRO = Copy_u8DataByte;

}

u8 UART_u8ReceivesyncByte(u8 * Copy_Pu8RecDataByte)
{

    u8 local_u8ReturnState = STD_TYPE_OK;
    u16 Local_u8_TUpCnt = 0;
    if (Copy_Pu8RecDataByte != NULL)
    {
        /*check that USART Receive Complete :  RXCn bit*/
        while((GET_BIT(UART_UCSROA,7)==0)&& (Local_u8_TUpCnt<NONBLOCKONG_TIME_OUT) )
        {
            Local_u8_TUpCnt++;
        }
        /*read the received data*/
        *Copy_Pu8RecDataByte = UART_UDRO ;
    }
    else
    {
        local_u8ReturnState = STD_TYPE_NOK;
    }
    return local_u8ReturnState;
}

