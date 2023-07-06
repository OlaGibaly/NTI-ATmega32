/*
 * CALCULATOR_App.c
 *
 * Created: 7/5/2023 1:41:14 PM
 *  Author: Ola
 */ 

	
#if 0

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../01 MCAL/DIO_Driver/DIO_interface.h"
#include "../02 HAL/KEYPAD_Driver/KEYPAD_interface.h"
#include "../02 HAL/LCD_Driver/LCD_interface.h"

int main(void)
{
	LCD_voidInit();
	KPD_voidInit();
	s16 Num1 = 0;
	s16 Num2 = 0;
	s16 result = 0;
	s16 calculation = 0;
	s16 temp;

	while (1) 
	{
		s16 key = KPD_voidGetPressedKey();
		switch (key) 
		{
			case 48: //0
			case 49: 
			case 50:
			case 51:
			case 52:
			case 53:
			case 54:
			case 55:
			case 56:
			case 57: //9
			
			temp=48;
			key -= temp;
			
			if (calculation == 0) 
			{ 
				
			
				Num1 = key;
				LCD_voidWriteNumber(Num1);
			} 
				
			else 
			{
			Num2 =  key;
			LCD_voidWriteNumber(Num2);
			}
			break;
			
			case 43:
			calculation = '+';
			LCD_voidWriteData(calculation);
			break;
			case 45:
			calculation = '-';
			LCD_voidWriteData(calculation);
			break;
			case 42:
			calculation = '*';
			LCD_voidWriteData(calculation);
			break;
			case 47:
			calculation = '/';
			LCD_voidWriteData(calculation);
			break;
			case 67:
			LCD_voidClear();
			break;
			//'='
			case 61:
			if (calculation == '+') 
			{
				result = Num1 + Num2;
				LCD_voidWriteData('=');
				LCD_voidWriteNumber(result);
			} 
			else if (calculation == '-') 
			{
				result = Num1 - Num2;
				LCD_voidWriteData('=');
				LCD_voidWriteNumber(result);			
			} 
			else if (calculation == '*') 
			{
				result = Num1 * Num2;
				LCD_voidWriteData('=');
				LCD_voidWriteNumber(result);
			} 
			
			if (calculation == '/') 
			{			
				if (Num2 != 0) 
				{
					result = Num1 / Num2;
					LCD_voidWriteData('=');
					LCD_voidWriteNumber(result);
				
				}
				else if (Num2 == 0) 
				{
					LCD_voidWriteData('=');
					LCD_voidWriteString("MATH ERROR");	
				}
			}
			
			//calculation, Num1, and Num2 reset to initial values
			calculation = 0;
			Num1 = 0;
			Num2 = 0;
			break;
			default:
			break;
		}
	}
}

#endif
