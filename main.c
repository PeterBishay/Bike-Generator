/*
 * main.c
 *
 *  Created on: Feb 26, 2018
 *      Author: G&N&P&M
 */

#include"util.h"
#include"type.h"
#include"dio.h"
#include"scheduler.h"
#include"Lcd.h"
#include"Ini.h"
#include<stdint.h>
#include"CTC.h"
#include<util/delay.h>


void main(void)
{

INITIO

	while(1)

	{

//		Start_OS();
		u8 greting[20]=" Welcome ";
		 LCD_WriteString(greting);
		 _delay_ms(10);
		 LCD_ClrData();

	}
}
