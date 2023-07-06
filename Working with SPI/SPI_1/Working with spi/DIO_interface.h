/*
 * DIO_interface.h
 *
 * Created: 6/11/2023 1:46:47 PM
 *  Author: Abdul
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#define PORTA_ID        0
#define PORTB_ID        1
#define PORTC_ID        2
#define PORTD_ID        3

/*
 * Pin ID Macros
 */
#define PIN0         0
#define PIN1         1
#define PIN2         2
#define PIN3         3
#define PIN4         4
#define PIN5         5
#define PIN6         6
#define PIN7         7




/*
 * Direction Macros
 */
#define PIN_OUTPUT         1
#define PIN_INPUT          0

#define PIN_HIGH           1
#define PIN_LOW            0

#define ALL_PORT_OUTPUT    (0XFF)
#define ALL_PORT_INPUT     (0x00)

#define ALL_PORT_HIGH      (0XFF)
#define ALL_PORT_LOW       (0x00)

/*Prototypes*/
void    DIO_voidSetPortDirection(u8 copy_u8PortID,u8 copy_u8PortDir );
void    DIO_voidSetPortValue(u8 copy_u8PortID,u8 copy_u8PortVal )    ;

void	DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDir);
void    DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue);


u8 DIO_voidGetBitValue(u8 copy_u8PortID , u8 copy_PinID );
//void    DIO_voidGetPinValue(u8 copy_u8PortID , u8 copy_PinID ,u8 *copy_u8PinVal );


void DIO_voidToggelPin(u8 copy_u8PortID,u8 copy_u8PinID) ;


#endif /* DIO_INTERFACE_H_ */