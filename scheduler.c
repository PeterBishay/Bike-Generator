/*
 * scheduler.c
 *
 *  Created on: Feb 9, 2018
 *      Author: G&N&P&M
 */

#include"type.h"
#include "util.h"
#include "CTC.h"
#include"ADC.h"
#include"cheack.h"
#include"scheduler.h"

#define SIZE sizeof(Tasks)/sizeof(OS_Type)

u8 i;
u16 counter=0;
u8 flag =0;
u16 counter_timer=0;



ISR(TIMER0_COMP_vect)

 //void __vector_10(void) __attribute__((signal,__INTR_ATTRS));
 //void __vector_10(void)
 {
 	counter++;
 	counter_timer++;
 	flag=1;
 }

const OS_Type Tasks[]=
{
		{cheack_condition,80,1},
		{channel_0_volt_Generatorvoltmeter,70,3},
		{channel_1_volt_BattaryVoltmerter,70,4},
		{cheack_condition,80,5},
};

void Start_OS(void)
{

	if(1 == flag)
	{
		for(i = 0 ; i < SIZE ; i++)
		{
			if(0==(counter % Tasks[i].peridicty))
			{
				Tasks[i].pf();
			}
		}
		flag = 0 ;
	}


}
