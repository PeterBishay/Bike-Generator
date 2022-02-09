/*
 * ADC.h
 *
 *  Created on: Mar 1, 2018
 *      Author: G&N&P&M
 */

#ifndef ADC_H_
#define ADC_H_


//extern void ADC_Init(void);
extern void ADC_Init(void);


u16 analog_read(u8 channel);

//int ADC_Read(char channel);
u8 ADC_Read(void);

int channel_0_volt_Generatorvoltmeter(void);
int channel_1_volt_BattaryVoltmerter(void);
int channel_2_current_ConverterBattery(void);
int channel_3_current_BatteryLoad(void);


#define RATIO  (RES_A+RES_B)/RES_B
#define RES_A  10000
#define RES_B  2200

void G_interrupt_Enable(void);


#endif /* ADC_H_ */
