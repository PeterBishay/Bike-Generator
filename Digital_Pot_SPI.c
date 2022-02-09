/*
 * SPI.c
 *
 *  Created on: Dec 2, 2017
 *      Author: G&N&P&M
 */

#include "type.h"
#include "dio.h"
#include "util.h"
#include"avr/delay.h"
#include "Digital_pot_SPI.h"



void SPI_Master_Init(void)
{
	/* SPI Init */

	set_bit(DDRB,4);  // set slave select
	set_bit(DDRB,5);  // set MOSI
	clr_bit(DDRB,6);  // clr MISO
	set_bit(DDRB,7);  // Set SCK


	SPCR=0b01011100;
	clr_bit(SPSR,0);

	/* Enable SPI
	 * Select Master mode
	 * Make Clock Polarity falling / Rising
	 * Make Clock Phase Setup / Sample
	 *  SPI select SCK Ferquency fosc/4
	 */

}

void SPI_Send(u8 data)
{
// save SPDR register data in Data
SPDR=data;
// cheack The flag untill it reach 0
while (get_bit(SPSR,7)!=1);


}

u8 SPI_Recive(void)
{

while (get_bit(SPSR,7)!=1);
	return SPDR;

}

void DigPot_writeVal(char val){
	/* ~CS Work AS input output this bit must clr then send then set again to send data */
	clr_bit(Send_Port,Send_Bit);
    SPI_Send(0x00);
    SPI_Send(val);
    _delay_ms(10);
    set_bit(Send_Port,Send_Bit);
}


