/*
 * Servo_App.c
 *
 * Created: 7/6/2023 5:33:02 PM
 *  Author: Ola
 */ 

#if 0

#define F_CPU 8000000UL
#include <util/delay.h>

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../02 HAL/SERVO_MOTOR/Servo_Interface.h"

#include "../01 MCAL/DIO_Driver/DIO_Interface.h"


int main(){
	DIO_voidSetPinDirection(PORTD_ID, PIN5, PIN_OUTPUT);
	SET_TOP_Value(20000);
	SET_OCR_Value(1500);
	Timer1_init();
	_delay_ms(2000);
	SET_OCR_Value(1000);
	_delay_ms(2000);
	SET_OCR_Value(2000);
	_delay_ms(2000);
	SET_OCR_Value(1500);
	while(1){

	}
	return 0;
}

#endif