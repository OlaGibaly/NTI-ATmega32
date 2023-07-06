/*
 * Password_App.c
 *
 * Created: 7/6/2023 4:40:08 PM
 *  Author: Ola
 */ 
	#if 0
	
	#define F_CPU 16000000UL
	
	#include "../LIB/STD_TYPES.h"
	#include "../LIB/BIT_MATH.h"
	#include "util/delay.h"
	#include "../01 MCAL//DIO_Driver/DIO_interface.h"
	#include "../02 HAL/LCD_Driver/LCD_interface.h"
	
	#include "../02 HAL/KEYPAD_Driver/KEYPAD_interface.h"
	
	
	int main(void)
	{
		LCD_voidInit();
		KPD_voidInit();
	
		LCD_voidWriteString("Plz, Enter Password:");
		_delay_ms(2000);
	
		LCD_voidGoToXY(1, 0);
	
		u8 x[4] = {'1', '9', '9', '9'};
		u8 password[4];
		u8 i = 0, j = 0;
		u8 flag = 0;
	
	
		while (1)
		{
	
			if ((flag == 0)  && (j < 4))
			{
				for (i = 0; i < 4; i++)
				{
					do
					{
						password[i] = KPD_voidGetPressedKey();
					} while (password[i] == 0xFF);
					LCD_voidWriteData('*');
				}
	
				if ((password[0] == x[0]) && (password[1] == x[1]) && (password[2] == x[2]) && (password[3] == x[3]))
				{
					flag = 1;
					LCD_voidClear();
					LCD_voidWriteString("Welcome User ^_^");
					_delay_ms(2000);
	
				}
				else
				{
					LCD_voidClear();
					LCD_voidWriteString("Wrong Password >_<");
					_delay_ms(1000);
					LCD_voidClear();
	
					if(j < 3)
					{
	
						LCD_voidWriteString("Password:");
						LCD_voidGoToXY(1, 0);
					}
					else
					{
						LCD_voidWriteString("LOCKED! :p ");
					}
	
				}
				j++;
	
			}
			
			/*	The loop condition (pass[i] == 0xFF) checks if the value of pass[i] is equal to 0xFF.
				 If the condition is true, indicating that no valid key has been pressed yet, 
				the loop body will be executed again to get another key. This process continues until a valid key is pressed.
				Once a valid key is pressed and the loop condition becomes false, the loop is exited,
				and the program proceeds with the next statement after the do-while loop.
				In summary, the do-while loop ensures that the code waits for a valid key press before proceeding, 
				making it useful for input validation in this password entry scenario.*/
			
			}
	}
	
  #endif