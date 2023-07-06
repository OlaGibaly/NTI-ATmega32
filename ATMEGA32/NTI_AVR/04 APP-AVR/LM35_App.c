/*
 * LM35_App.c
 *
 * Created: 6/22/2023 8:58:22 PM
 *  Author: Ola
 */ 

#if 0

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../01 MCAL/DIO_Driver/DIO_interface.h"

#include "../01 MCAL/ADC_Driver/ADC_interface.h"

#include "../02 HAL/LCD_Driver/LCD_interface.h"

u16 DigitalValue = 0;
u16 AnalogValueMV = 0;
u16 Temperature = 0;


int main(void)
{

	DIO_voidSetPinDirection (PORTA_ID, PIN0, PIN_INPUT);
	
	LCD_voidInit();
	LCD_voidWriteString("Temperature is:");

	ADC_voidInit();
	ADC_voidEnable();

	while(1)
	{

		AnalogValueMV = ADC_u16GetDigitalValue(ADC_u8_CHANNEL_0);

		DigitalValue = (AnalogValueMV * 5000UL) / 1024;
		
		Temperature = DigitalValue /100;
		

		LCD_voidGoToXY(1, 0);
		LCD_voidWriteNumber(Temperature);
		LCD_voidGoToXY(1, 3);
		LCD_voidWriteData('C');

	}
	return 0;
}

#endif
