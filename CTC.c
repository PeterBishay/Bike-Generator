/*
 * Timer0.c
 *
 *  Created on: Nov 15, 2017
 *      Author: G&N&P&M
 */

#include "type.h"
#include "util.h"
#include "dio.h"

#include "avr\delay.h"


extern void _CTC_Init(void)
{

	// enable Timer
	// prescaler
	set_bit(TCCR0,0);
	clr_bit(TCCR0,1);
	clr_bit(TCCR0,2);
	//  compare output mode
	clr_bit(TCCR0,4);
	clr_bit(TCCR0,5);
	// enable interrupt  for compare match CTC
	clr_bit(TIMSK,0);
	set_bit(TIMSK,1);
	// set mode to over flow
	clr_bit(TCCR0,6);
	set_bit(TCCR0,3);
	OCR0=200;

}


void G_interrupt_Enable(void)
{
	set_bit(SREG,7);

}
