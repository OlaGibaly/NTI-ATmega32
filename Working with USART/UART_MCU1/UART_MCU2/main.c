/*
 * UART_MCU2.c
 *
 * Created: 7/2/2023 11:52:43 PM
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
	DIO_voidSetPinDirection(PORTB_ID, PIN0, PIN_INPUT);
	DIO_voidSetPinValue(PORTB_ID, PIN0, PIN_HIGH); // Button pull up
	
	DIO_voidSetPinDirection(PORTD_ID,PIN0 , PIN_INPUT);
	DIO_voidSetPinDirection(PORTD_ID, PIN1, PIN_OUTPUT);
	
	UART_Init();
	
	while (1)
	{
		if(DIO_voidGetBitValue(PORTB_ID,PIN0)!= 1){
			
			UART_Send('1');
			
		}
		
		else if(DIO_voidGetBitValue(PORTB_ID,PIN0)==1) {
			
			UART_Send('0');
			
		}
		
	}
	return 0;
}