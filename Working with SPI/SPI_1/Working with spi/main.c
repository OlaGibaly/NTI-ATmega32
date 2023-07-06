/*
 * Working with spi.c
 *
 * Created: 7/3/2023 10:27:19 AM
 * Author : DELL
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SPI_interface.h"

//Master

int main(){
	
	DIO_voidSetPinDirection    (PORTB_ID, PIN0, PIN_INPUT); // push button
	DIO_voidSetPinValue        (PORTB_ID, PIN0, PIN_HIGH);
	
	DIO_voidSetPinDirection    (PORTB_ID, PIN5, PIN_OUTPUT);
	DIO_voidSetPinDirection    (PORTB_ID, PIN4, PIN_OUTPUT);
	DIO_voidSetPinDirection    (PORTB_ID, PIN6, PIN_INPUT);
	DIO_voidSetPinDirection    (PORTB_ID, PIN7, PIN_OUTPUT);
	DIO_voidSetPinValue        (PORTB_ID, PIN4, PIN_LOW); //slave select
	SPI_Init_Master();
	
	while(1){
		if(DIO_voidGetBitValue(PORTB_ID, PIN0)!=1){
			SPI_SendData('1')=='1';
		}
		else if(DIO_voidGetBitValue(PORTB_ID, PIN0==1)){
			SPI_SendData('0')=='0';
		}
	}
	return 0;
}
