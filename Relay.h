/*
 * Relay.h
 *
 *  Created on: Jun 20, 2018
 *      Author: G&N&P&M
 */

#ifndef RELAY_H_
#define RELAY_H_


#define RELAY_MOBILE			5 // PORTD PIN No.4
#define RELAY_ROUTER			1 // PORTD PIN No.6
#define RELAY_S_LIGHT			4 // PORTD PIN No.5
#define RELAY_FAN				3 // PORTD PIN No.7
#define RELAY_B_LIGHT			2 // PORTD PIN No.8
#define RELAY_INTERNAL_FAN		0 // PORTC PIN No.1

#define RELAY_SW_GENERATOR		6 // PORTD PIN No.1
#define RELAY_SW_BATTERY		7 // PORTD PIN No.2
#define RELAY_SW_LOADS			0 // PORTC PIN No.0   **************


#define RELAY_MOBILE_ON			clr_bit(PORTD,RELAY_MOBILE); 		// PORTD PIN NC.4
#define RELAY_ROUTER_ON			clr_bit(PORTD,RELAY_ROUTER); 		// PORTD PIN NC.6
#define RELAY_S_LIGHT_ON		clr_bit(PORTD,RELAY_S_LIGHT); 		// PORTD PIN NC.5
#define RELAY_FAN_ON			clr_bit(PORTD,RELAY_FAN); 			// PORTD PIN NC.7
#define RELAY_B_LIGHT_ON		clr_bit(PORTD,RELAY_B_LIGHT); 		// PORTD PIN NC.8
#define RELAY_INTERNAL_FAN_ON	clr_bit(PORTD,RELAY_INTERNAL_FAN); 	// PORTC PIN NC.1



#define RELAY_MOBILE_OFF			set_bit(PORTD,RELAY_MOBILE); 		// PORTD PIN NC.4
#define RELAY_ROUTER_OFF			set_bit(PORTD,RELAY_ROUTER); 		// PORTD PIN NC.6
#define RELAY_S_LIGHT_OFF			set_bit(PORTD,RELAY_S_LIGHT); 		// PORTD PIN NC.5
#define RELAY_FAN_OFF				set_bit(PORTD,RELAY_FAN); 			// PORTD PIN NC.7
#define RELAY_B_LIGHT_OFF			set_bit(PORTD,RELAY_B_LIGHT); 		// PORTD PIN NC.8
#define RELAY_INTERNAL_FAN_OFF		set_bit(PORTD,RELAY_INTERNAL_FAN); 	// PORTC PIN NC.1


#define RELAY_SW_GENERATOR_ON		clr_bit(PORTD,RELAY_SW_GENERATOR);	// PORTD PIN NC.1  NO
#define RELAY_SW_BATTERY_ON			clr_bit(PORTD,RELAY_SW_BATTERY); 	// PORTD PIN NC.2  NO
#define RELAY_SW_LOADS_ON			clr_bit(PORTC,RELAY_SW_LOADS); 		// PORTD PIN NC.3  NO


#define RELAY_SW_GENERATOR_OFF		set_bit(PORTD,RELAY_SW_GENERATOR);	// PORTD PIN NC.1  NO
#define RELAY_SW_BATTERY_OFF		set_bit(PORTD,RELAY_SW_BATTERY);	// PORTD PIN NC.2  NO
#define RELAY_SW_LOADS_OFF			set_bit(PORTC,RELAY_SW_LOADS); 		// PORTD PIN NC.3  NO Normaly closed




void RELAY_INIT(void);





#endif /* RELAY_H_ */
