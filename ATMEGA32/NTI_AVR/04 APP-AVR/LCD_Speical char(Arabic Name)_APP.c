/*
 * LCD_Specialchar_App.c
 *
 * Created: 6/22/2023 2:53:20 PM
 *  Author: Ola
 */ 


#if 0

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../02 HAL/LCD_Driver/LCD_interface.h"



//printing my name using special characters


int main()
{
	LCD_voidInit();
	

	u8 customChar0[] = {  0x00,
		0x00,
		0x07,
		0x04,
		0x04,
		0x1F,
		0x00,
		0x00
	}; //?

	u8 customChar1[] = {  0x00,
		0x02,
		0x12,
		0x0A,
		0x06,
		0x1F,
		0x00,
		0x00
	}; //??

	
	u8 customChar2[] = {
		0x00,
		0x00,
		0x1B,
		0x1F,
		0x1F,
		0x0E,
		0x04,
		0x00
	}; //
	
	LCD_voidClear();
	
	LCD_voidWriteSpecialCharToCGRAM(customChar0, 0, 1, 10);
	LCD_voidWriteSpecialCharToCGRAM(customChar1, 1, 1, 9);
	LCD_voidWriteSpecialCharToCGRAM(customChar2, 2, 1, 8);
	
	
	while(1)

	{

	}

	return 0 ;
}

#endif