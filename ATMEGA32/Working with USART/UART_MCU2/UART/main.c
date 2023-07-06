/*
 * UART.c
 *
 * Created: 7/2/2023 11:48:35 PM
 * Author : DELL
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "UART_interface.h"

int main()
{
	DIO_voidSetPinDirection(PORTC_ID, PIN7, PIN_OUTPUT);
	
	DIO_voidSetPinDirection(PORTD_ID,PIN0 , PIN_INPUT);
	DIO_voidSetPinDirection(PORTD_ID, PIN1, PIN_OUTPUT);
	
	UART_Init();
	
	while (1)
	{
		if(UART_Receive()=='1'){
			
			DIO_voidSetPinValue(PORTC_ID, PIN7, PIN_HIGH);
		}
		
		else if(UART_Receive()=='0') {
			
			DIO_voidSetPinValue(PORTC_ID,PIN7, PIN_LOW);
			
		}
		
	}
	return 0;
}

