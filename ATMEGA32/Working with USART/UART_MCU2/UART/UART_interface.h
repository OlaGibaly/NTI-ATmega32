/*
 * UART_interface.h
 *
 * Created: 7/2/2023 12:03:45 PM
 *  Author: Abdul
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void UART_Init();
void UART_Send(u8 data);
u8   UART_Receive();
void UART_Send_Str(u8* str);
void UART_Receive_Str(u8* str);


#endif /* UART_INTERFACE_H_ */