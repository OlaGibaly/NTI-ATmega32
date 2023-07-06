/*
 * UART_program.c
 *
 * Created: 7/2/2023 12:04:01 PM
 *  Author: Abdul
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

// #include "LCD_interface.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void UART_Init()
{
	u8 temp=0;
	CLR_BIT(temp, 6);
	CLR_BIT(temp, 5);
	CLR_BIT(temp, 4);
	CLR_BIT(temp, 3);
	SET_BIT(temp, 1);
	SET_BIT(temp, 2);
	SET_BIT(temp, 7);
	UCSRC=temp;
	UBRRL=51;
	SET_BIT(UCSRB, 3);
	SET_BIT(UCSRB, 4);
	CLR_BIT(UCSRB, 2);

}
void UART_Send(u8 data)
{
	while(GET_BIT(UCSRA, 5) !=1 );
	UDR=data;
}
u8	 UART_Receive()
{
	while(GET_BIT(UCSRA,7) !=1 );
	return UDR;
}


void UART_Send_Str(u8* str)
{
	while (*str != '\0')
	{
		UART_Send(*str);
		str++;
	}
}

void UART_Receive_Str(u8* str)
{
	u8 receive = 0;
	*str = "";
	while (receive != '\0')
	{
		UART_Receive(&receive);
		_delay_ms(1);
		*str += receive;
	}
}

