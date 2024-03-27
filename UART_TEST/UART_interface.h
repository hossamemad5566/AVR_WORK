/*********************************************************
 * @name : Hossam Emad
 * @date : 5/2/2024
 * @swc: UART
 * @version : V1.0
 * @description :
*********************************************************/
#ifndef _UART_INTERFACE_H_
#define _UART_INTERFACE_H_

void UART_voidInit(void);

void UART_u8SendsyncByte(u8 Copy_u8DataByte);

u8 UART_u8ReceivesyncByte(u8 * Copy_Pu8RecDataByte);



#endif
