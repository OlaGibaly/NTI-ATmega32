/*
 * Buzzer_program.c
 *
 * Created: 7/1/2023 11:56:39 PM
 *  Author: Ola
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../01 MCAL/DIO_Driver/DIO_interface.h"

#include "Buzzer_interface.h"


void BUZ_voidInit( Buzzer_Type BUZ_Configuration )
{
	
	DIO_voidSetPinDirection( BUZ_Configuration.Port , BUZ_Configuration.Pin , PIN_OUTPUT );
	
}


void BUZ_voidOn  ( Buzzer_Type BUZ_Configuration )
{
	
	if( BUZ_Configuration.Active_State == ACTIVE_HIGH ){
		
		DIO_voidSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , PIN_HIGH );
		
	}else if( BUZ_Configuration.Active_State == ACTIVE_LOW ){
		
		DIO_voidSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , PIN_LOW  );
		
	}
	
}


void BUZ_voidOff ( Buzzer_Type BUZ_Configuration )
{
	
	if( BUZ_Configuration.Active_State == ACTIVE_HIGH ){
		
		DIO_voidSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , PIN_LOW  );
		
	}else if( BUZ_Configuration.Active_State == ACTIVE_LOW ){
		
		DIO_voidSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , PIN_HIGH  );
		
	}
	
}

void BUZ_voidToggle      ( Buzzer_Type BUZ_Configuration )
{
	DIO_voidToggelPin  ( BUZ_Configuration.Port , BUZ_Configuration.Pin );
}
