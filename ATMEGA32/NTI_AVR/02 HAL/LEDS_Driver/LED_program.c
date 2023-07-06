/*
 * LED_program.c
 *
 * Created: 7/1/2023 10:42:13 PM
 *  Author: Ola
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../01 MCAL/DIO_Driver/DIO_Interface.h"

#include "LED_interface.h"



void LED_voidInit( LED_Type LED_Configuration )
{
	
	DIO_voidSetPinDirection( LED_Configuration.Port , LED_Configuration.Pin , PIN_OUTPUT );
	
}


void LED_voidOn  ( LED_Type LED_Configuration )
{
	
	if( LED_Configuration.Active_State == ACTIVE_HIGH ){
		
		DIO_voidSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , PIN_HIGH );
		
	}else if( LED_Configuration.Active_State == ACTIVE_LOW ){
		
		DIO_voidSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , PIN_LOW  );
		
	}
	
}


void LED_voidOff ( LED_Type LED_Configuration )
{
	
	if( LED_Configuration.Active_State == ACTIVE_HIGH ){
		
		DIO_voidSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , PIN_LOW  );
		
	}else if( LED_Configuration.Active_State == ACTIVE_LOW ){
		
		DIO_voidSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , PIN_HIGH  );
		
	}
	
}

void LED_voidToggle      ( LED_Type LED_Configuration )
{
	DIO_voidToggelPin  ( LED_Configuration.Port , LED_Configuration.Pin );
}