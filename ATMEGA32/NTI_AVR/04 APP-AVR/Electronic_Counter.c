/*
 * Electronic_Counter.c
 *
 * Created: 7/5/2023 3:22:57 PM
 *  Author: Ola
 */ 

#if 0

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../01 MCAL/DIO_Driver/DIO_interface.h"

#include "../01 MCAL/GIE_Driver/GIE_interface.h"
#include "../01 MCAL/EXTI1_Driver/EXTI1_interface.h"

#include "../02 HAL/SEVEN_SEGMENT_Driver/SEV_interface.h"
#include "../02 Hal/KEYPAD_Driver/KEYPAD_interface.h"


u8 i = 0;

void main(void)
{

	SEV_Initialization();
	SEV_Enable1();

	//push button init

	DIO_voidSetPinDirection(PORTD_ID,PIN3,PIN_INPUT);
	DIO_voidSetPinValue(PORTD_ID,PIN3,PIN_HIGH);


	EXTI1_voidInit();
	EXTI1_voidCallBack(SSD_func);
	GIE_voidEnable();

	while(1)
	{

	}
	
}


void SSD_func(void)
{
	SEV_Write_One_Number(i); // Display the current value of i
	if (i == 9) {
		i = 0; // Reset i to 0 when it reaches 9
		} else {
		i++;
	}
}

	#endif