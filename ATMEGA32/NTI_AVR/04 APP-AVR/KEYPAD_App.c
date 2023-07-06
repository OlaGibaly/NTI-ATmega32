/*
 * KEYPAD_App.c
 *
 * Created: 6/22/2023 5:00:47 PM
 *  Author: Ola
 */ 


#if 0

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../01 MCAL/DIO_Driver/DIO_interface.h"

#include "../02 HAL/KEYPAD_Driver/KEYPAD_interface.h"
#include "../02 HAL/SEVEN_SEGMENT_Driver/SEV_interface.h"


void LED_Toggle(void);
void BUZZ_Toggle(void);

int main(void)
{
	u8 key; 
	u8 counter=0; 
	KPD_voidInit();
	
	SEV_Initialization();
	SEV_Enable1();

	while(1)
	{
		key = KPD_voidGetPressedKey();
		if(key == 7+48)			/* increment, 48 for the ascii representation */
		{
			//counter++;
			++counter;
			SEV_Write_One_Number(counter);
		}
		else if(key == 8+48)	//decrement
		{
			//counter--;
			--counter;			
			SEV_Write_One_Number(counter);
		}
		else if(key == 9+48)
		{
			BUZZ_Toggle();
		}
		else if(key == 47) /* '/' ascii representation */
		{
			LED_Toggle();	
		}
	}
	return 0;
}


void BUZZ_Toggle(void)
{
	DIO_voidSetPinDirection(PORTC_ID, PIN6, PIN_OUTPUT);
	DIO_voidToggelPin(PORTC_ID, PIN6);
}

void LED_Toggle(void)
{
	DIO_voidSetPinDirection(PORTB_ID, PIN7, PIN_OUTPUT);
	DIO_voidToggelPin(PORTB_ID, PIN7);
}
#endif
