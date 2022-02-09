/*
 * cheack.c
 *
 *  Created on: Mar 21, 2018
 *      Author: G&N&P&M
 */

#include"type.h"
#include"dio.h"
#include"util.h"
#include"ADC.h"
#include"Relay.h"
#include"Lcd.h"
#include"cheack.h"
#include"avr/delay.h"

void cheack_condition(void)
{
	u8 percent = 0 ;
	RELAY_INIT();
	percent = ((channel_1_volt_BattaryVoltmerter()-12.3)/0.7)*100 ;
// in case of the both limt less than needed
	 if(channel_0_volt_Generatorvoltmeter()<Limit_genrator && channel_1_volt_BattaryVoltmerter()<Limit_Battary)
	 {
		RELAY_SW_GENERATOR_OFF
		RELAY_SW_BATTERY_OFF

		LCD_SecondLine();
		u8 w1[10]="Run Faster";
		LCD_WriteString(w1);
        LCD_ThirdLine();
        LCD_WriteData(percent);
    	u8 s1[1]="%";
    	LCD_WriteString(s1);
    		 }


// in case of genrator biger than limit and battry less than limit
	 if(channel_0_volt_Generatorvoltmeter()>Limit_genrator && channel_1_volt_BattaryVoltmerter()<Limit_Battary)
	 {
	    RELAY_SW_BATTERY_ON
		RELAY_SW_GENERATOR_ON
		LCD_FirstLine();
		u8 w2[8]="Charging";
		LCD_WriteString(w2);
		LCD_SecondLine();
		u8 w3[8]="Load_OFF";
		LCD_WriteString(w3);
        LCD_ThirdLine();
        LCD_WriteData(percent);
    	u8 s2[1]="%";
    	LCD_WriteString(s2);

	 }



// in case of the generator less than limit and battary biger than limit
	if(channel_0_volt_Generatorvoltmeter() < Limit_genrator && channel_1_volt_BattaryVoltmerter() > Limit_Battary)
	{
            RELAY_SW_BATTERY_OFF
			RELAY_SW_GENERATOR_OFF
			if(percent > 90)
			{
				LCD_FirstLine();
				u8 w4[8]="charged";
				LCD_WriteString(w4);
				LCD_ThirdLine();
				LCD_WriteData(percent);
				u8 s2[1]="%";
				LCD_WriteString(s2);

			}
			else if(percent > 20 && percent <= 90){
				LCD_ThirdLine();
				LCD_WriteData(percent);
				u8 s1[1]="%";
				LCD_WriteString(s1);

			}
			else{
				LCD_FirstLine();
				u8 w5[11] ="low_Battary";
				LCD_WriteString(w5);
				LCD_ThirdLine();
				LCD_WriteData(percent);
				u8 s3[1]="%";
				LCD_WriteString(s3);

			}


	}



//IN case of both the two limit biger than asked
	 if(channel_0_volt_Generatorvoltmeter()>Limit_genrator && channel_1_volt_BattaryVoltmerter()>Limit_Battary)
	 {
        RELAY_SW_BATTERY_ON
		RELAY_SW_GENERATOR_ON
		if(percent > 90){
			LCD_FirstLine();
			u8 w6[8]="charged";
			LCD_WriteString(w6);
			LCD_ThirdLine();
			LCD_WriteData(percent);
			u8 s4[1]="%";
			LCD_WriteString(s4);
		}
		else{
			LCD_FirstLine();
			u8 w9[8]="Charging";
			LCD_WriteString(w9);
			LCD_ThirdLine();
			u8 s5[1]="%";
			LCD_WriteString(s5);
				}

	 }
		if(percent >= 60){
				RELAY_MOBILE_ON
				RELAY_ROUTER_OFF
				RELAY_S_LIGHT_OFF
				RELAY_FAN_OFF
				RELAY_B_LIGHT_OFF}
					if(percent >= 70){
						RELAY_ROUTER_ON
						RELAY_S_LIGHT_OFF
						RELAY_FAN_OFF
						RELAY_B_LIGHT_OFF}
							if(percent >= 80){
								RELAY_S_LIGHT_ON
								RELAY_FAN_OFF
								RELAY_B_LIGHT_OFF}
									if(percent >= 90){
										RELAY_FAN_ON
										RELAY_B_LIGHT_OFF}
											if(percent >= 95){
												RELAY_B_LIGHT_ON}

_delay_ms(200);
Calculate_caloris(channel_0_volt_Generatorvoltmeter());
_delay_ms(200);
}
