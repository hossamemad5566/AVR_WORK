/*********************************************************
 * @name : Hossam Emad
 * @date : 5/2/2024
 * @swc: UART
 * @version : V1.0
 * @description :
*********************************************************/
#ifndef _UART_CONFIG_H_
#define _UART_CONFIG_H_

#define UART_BAUD_RATE   UART_SPEED_9600
#define UART_CHAR_SIZE   UART_Frame_8
#define UART_SB_NO       UART_SB_2
#define UART_PB          PB_DISABLE 
#define UART_MODE        UART_ASYNC
 
/*UART Baud Rate*/
 /*
 UART_SPEED_2400           
 UART_SPEED_4800           
 UART_SPEED_9600           
 UART_SPEED_14400          
 UART_SPEED_19200          
 UART_SPEED_28800          
 UART_SPEED_38400          
 UART_SPEED_57600          
 UART_SPEED_76800          
 UART_SPEED_115200         
 UART_SPEED_230400         
 UART_SPEED_250000         
 UART_SPEED_5000000        
 UART_SPEED_10000000   
 */    

/*char size choices*/
/*
 UART_Frame_5    
 UART_Frame_6    
 UART_Frame_7    
 UART_Frame_8    
 UART_Frame_9
 */    

/*stop bits number */
 
 /*
 UART_SB_1       
 UART_SB_2       
 */

/*Parity Bit Choices*/
 
 /*
 PB_DISABLE      
 PB_EVEN         
 PB_ODD          
 */

/*UART MODE Choices*/
/*
 UART_ASYNC      
 UART_SYNC       
 UART_MSPIM      
*/



#endif
