/*
 * Ohmeter_APP.c
 *
 * Created: 7/6/2023 4:40:08 PM
 *  Author: Ola
 */ 
#if 0

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../01 MCAL//DIO_Driver/DIO_interface.h"
#include "../01 MCAL/ADC_Driver/ADC_interface.h"

#include "../02 HAL/KEYPAD_Driver/KEYPAD_interface.h"
#include "../02 HAL/LCD_Driver/LCD_interface.h"


int main (void){
	u16 Analogue = 0;
	u16 Digital = 0;
	u16 Resistance = 0;
	u8 Key = 0xFF;
	
	DIO_voidSetPinDirection(PORTA_ID, PIN0, PIN_INPUT);

	ADC_voidInit();
	ADC_voidEnable();
	LCD_voidInit();
	KPD_voidInit();
	
	LCD_voidGoToXY(1, 0);
	LCD_voidWriteString(" For Ohmeter, press 1:");
	
	do
	{
		Key = KPD_voidGetPressedKey();
	}
	while(Key != 0xFF);

	while (1)
	{
		Key = KPD_voidGetPressedKey();
		
		if(Key==49){
			LCD_voidClear();
			while(1){
				LCD_voidGoToXY(0, 0);
				LCD_voidWriteString("Resistance=");
				LCD_voidGoToXY(1, 0);

				Analogue = ADC_u16GetDigitalValue(ADC_u8_CHANNEL_0);
				Digital = (Analogue * 5000UL) / 1023;
				Resistance = (Digital / 40);
				_delay_ms(1500);

				LCD_voidWriteNumber(Resistance);
			}
			break;
		}
		
	}
}

#endif