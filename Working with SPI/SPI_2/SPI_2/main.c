/*
 * SPI_2.c
 *
 * Created: 7/3/2023 10:37:24 AM
 * Author : DELL
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SPI_interface.h"



int main(){
	DIO_voidSetPinDirection(PORTC_ID, PIN7, PIN_OUTPUT); //LED
	
	DIO_voidSetPinDirection(PORTB_ID, PIN4, PIN_INPUT);
	DIO_voidSetPinDirection(PORTB_ID, PIN5, PIN_INPUT);
	DIO_voidSetPinDirection(PORTB_ID, PIN6, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTB_ID, PIN7, PIN_INPUT);
	
	SPI_Init_Slave();
	
	while(1){
		if(SPI_SendData('1')=='1'){
			DIO_voidSetPinValue(PORTC_ID, PIN7, PIN_HIGH);

		}
		else if(SPI_SendData('0')=='0'){
			DIO_voidSetPinValue(PORTC_ID, PIN7, PIN_LOW);
		}
	}
	return 0;
}
