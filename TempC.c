/*
 * TempC.c
 *
 *  Created on: May 20, 2018
 *      Author: G&N&P&M
 */
#include"type.h"
#include"dio.h"
#include"util.h"
#include"ADC.h"
#include"TempC.h"

u8  LM35_temp_sens(void){

	u32 analog = 0 ;

	float voltage = 0 ;
	float Temp = 0 ;  // C' Degree

	analog = analog_read(ADC_CH_TEMPC);
	voltage = (analog * 5.0 )/255.0;
	Temp = (voltage - 0.5)* 100 ;

        return Temp ;
}
