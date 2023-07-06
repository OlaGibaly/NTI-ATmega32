/*
 * SPI_program.c
 *
 * Created: 7/3/2023 10:29:01 AM
 *  Author: DELL
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_interface.h"


void SPI_Init_Master(){
	SET_BIT(SPCR,5);
	CLR_BIT(SPCR,3);
	CLR_BIT(SPCR,2);
	CLR_BIT(SPSR,0);
	CLR_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	SET_BIT(SPCR,4);
	SET_BIT(SPCR,6);
}

void SPI_Init_Slave(){
	SET_BIT(SPCR,5);
	CLR_BIT(SPCR,3);
	CLR_BIT(SPCR,2);
	CLR_BIT(SPCR,4);
	SET_BIT(SPCR,6);
}

u8 SPI_SendData(u8 data){
	SPDR=data;
	while(!GET_BIT(SPSR, 7));
	return SPDR;

}

