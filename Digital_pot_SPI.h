/*
 * SPI.h
 *
 *  Created on: Dec 2, 2017
 *      Author: G&N&P&M
 */

#ifndef DIGITAL_POT_SPI_H_
#define DIGITAL_POT_SPI_H_

#define SPCR     (*(volatile u8 *)0x2D)       //for SPI serial peripheral Interface
#define SPSR     (*(volatile u8 *)0x2E)
#define SPDR     (*(volatile u8 *)0x2F)


void SPI_Master_Init(void);
void SPI_Send(u8 data);
u8 SPI_Recive(void);


void DigPot_writeVal(char val);

#define Send_Bit  4
#define Send_Port PORTB

#endif /* DIGITAL_POT_SPI_H_ */
