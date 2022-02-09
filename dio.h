/*
 * dio.h
 *
 *  Created on: Nov 15, 2017
 *      Author: G&N&P&M
 */

#ifndef DIO_H_
#define DIO_H_

#define PORTA   (*(volatile u8 *)0x3B)
#define DDRA    (*(volatile u8 *)0x3A)
#define PINA    (*(volatile u8 *)0x39)

#define PORTB   (*(volatile u8 *)0x38)
#define DDRB    (*(volatile u8 *)0x37)
#define PINB    (*(volatile u8 *)0x36)

#define PORTC   (*(volatile u8 *)0x35)
#define DDRC    (*(volatile u8 *)0x34)
#define PINC    (*(volatile u8 *)0x33)

#define PORTD   (*(volatile u8 *)0x32)   // bnshawr 3la el location hna
#define DDRD    (*(volatile u8 *)0x31)
#define PIND    (*(volatile u8 *)0x30)

#define SREG    (*(volatile u8 *)0x5f)
#define MCUCSR  (*(volatile u8 *)0x54)
#define MCUCR   (*(volatile u8 *)0x55)
#define GICR    (*(volatile u8 *)0x5B)
#define GIFR    (*(volatile u8 *)0x5A)

#define ADMUX   (*(volatile u8 *)0x27)
#define ADCSRA  (*(volatile u8 *)0x26)
#define ADCH    (*(volatile u8 *)0x25)
#define ADCL    (*(volatile u8 *)0x24)

#define TCCR0    (*(volatile u8 *)0x53)
#define TCNT0    (*(volatile u8 *)0x52)
#define TIMSK    (*(volatile u8 *)0x59)
#define TIFR     (*(volatile u8 *)0x58)

#define OCR0     (*(volatile u8 *)0x5C)

#define OSCCAL   (*(volatile u8 *)0x51)
#define OCDR     (*(volatile u8 *)0x51)

#endif /* DIO_H_ */
