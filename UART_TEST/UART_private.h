/*********************************************************
 * @name : Hossam Emad
 * @date : 5/2/2024
 * @swc: UART
 * @version : V1.0
 * @description :
*********************************************************/
#ifndef _UART_PRIVATE_H_
#define _UART_PRIVATE_H_

 
#define UART_UDRO     *((volatile u8*)0xC6)
/*for the high and low registers*/
#define UART_UBRROL   *((volatile u16*)0xC4)
#define UART_UCSROC   *((volatile u8*)0xC2)
#define UART_UCSROB   *((volatile u8*)0xC1)
#define UART_UCSROA   *((volatile u8*)0xC0)

/*UART Baud Rate*/
#define UART_SPEED_2400           416
#define UART_SPEED_4800           207
#define UART_SPEED_9600           103
#define UART_SPEED_14400          68
#define UART_SPEED_19200          51
#define UART_SPEED_28800          34
#define UART_SPEED_38400          25
#define UART_SPEED_57600          16
#define UART_SPEED_76800          12
#define UART_SPEED_115200         8
#define UART_SPEED_230400         3
#define UART_SPEED_250000         3
#define UART_SPEED_5000000        1
#define UART_SPEED_10000000       0

/*char size choices*/
#define UART_Frame_5    0
#define UART_Frame_6    1
#define UART_Frame_7    2
#define UART_Frame_8    3
#define UART_Frame_9    4

/*stop bits number */
#define UART_SB_1       0
#define UART_SB_2       1

/*Parity Bit Choices*/
#define PB_DISABLE      0
#define PB_EVEN         1
#define PB_ODD          2

/*UART MODE Choices*/
#define UART_ASYNC      0
#define UART_SYNC       1
#define UART_MSPIM      2


#endif