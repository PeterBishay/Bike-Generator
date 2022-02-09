/*
 * Relay.c
 *
 *  Created on: Jun 20, 2018
 *      Author: G&N&P&M
 */
#include"type.h"
#include"dio.h"
#include"util.h"
#include"Relay.h"


void RELAY_INIT(void){
	set_bit(DDRD,RELAY_MOBILE); 		// PORTD PIN No.4
	set_bit(DDRD,RELAY_ROUTER); 		// PORTD PIN No.6
	set_bit(DDRD,RELAY_S_LIGHT); 		// PORTD PIN No.5
	set_bit(DDRD,RELAY_FAN); 			// PORTD PIN No.7
	set_bit(DDRD,RELAY_B_LIGHT); 		// PORTD PIN No.8
	set_bit(DDRC,RELAY_INTERNAL_FAN); 	// PORTC PIN No.1
	set_bit(DDRD,RELAY_SW_GENERATOR);	// PORTD PIN No.1
	set_bit(DDRD,RELAY_SW_BATTERY);		// PORTD PIN No.2
	set_bit(DDRD,RELAY_SW_LOADS); 		// PORTD PIN No.3
}

