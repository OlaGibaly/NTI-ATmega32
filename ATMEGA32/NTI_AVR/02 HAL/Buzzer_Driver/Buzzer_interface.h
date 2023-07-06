/*
 * Buzzer_interface.h
 *
 * Created: 7/1/2023 11:56:59 PM
 *  Author: Ola
 */ 


#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_


// to choose from and use in main

/* 	Buzzer_Type BUZZ1 ={LED_PORTC,LED_PIN6, ACTIVE_HIGH}; */

// Port Defines
#define  BUZ_PORTA  0
#define  BUZ_PORTB  1
#define  BUZ_PORTC  2
#define  BUZ_PORTD  3


// PIN Defines
#define BUZ_PIN0   0
#define BUZ_PIN1   1
#define BUZ_PIN2   2
#define BUZ_PIN3   3
#define BUZ_PIN4   4
#define BUZ_PIN5   5
#define BUZ_PIN6   6
#define BUZ_PIN7   7

#define ACTIVE_HIGH    1
#define ACTIVE_LOW     0

typedef struct{
	
	u8 Port         ;
	u8 Pin          ;
	u8 Active_State ;
	
}Buzzer_Type;


void BUZ_voidInit        ( Buzzer_Type BUZ_Configuration );

void BUZ_voidOn          ( Buzzer_Type BUZ_Configuration );

void BUZ_voidOff         ( Buzzer_Type BUZ_Configuration );

void BUZ_voidToggle      ( Buzzer_Type BUZ_Configuration );




#endif /* BUZZER_INTERFACE_H_ */