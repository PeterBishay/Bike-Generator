/*
 * ADC.c

 *
 *  Created on: Feb 26, 2018
 *      Author: G&N&P&M
 */

#include"type.h"
#include"util.h"
#include"dio.h"
#include"avr/delay.h"


extern void ADC_Init(void)
{

	set_bit(ADCSRA,7); // To Enable ADC

	//To Select ADC prescaler To Division factor 1600000000/128=125000
	set_bit(ADCSRA,0);
	set_bit(ADCSRA,1);
	set_bit(ADCSRA,2);

	//Disable INteruppt
	clr_bit(ADCSRA,3);

	//AVCC with external capacitor at AREF pin
	clr_bit(ADMUX,7);
	set_bit(ADMUX,6);

	//set left alyment
	set_bit(ADMUX,5);

	//to set Triger Enable
     set_bit(ADCSRA,6);


 	// inti DIO for ADC make it output
 	       clr_bit(DDRA,0);
 	       clr_bit(DDRA,1);
// 	       clr_bit(DDRA,2);
 //	       clr_bit(DDRA,3);
 	//       clr_bit(DDRA,4);
 	  //     clr_bit(DDRA,5);
 	    //   clr_bit(DDRA,6);


}

u16 analog_read(u8 channel)
{
	ADMUX = (ADMUX & 0xF8) | (channel & 0b00000111);
	/*This delay was adding after reading*/
	/*a post of the tutorial from this forum*/
	_delay_ms(200);
	// start conversion
	set_bit(ADCSRA,6);
	//check THis flag until it become 0
	while(get_bit(ADCSRA,4)==0);
	//clr flag this flag  clr when we put 1
	set_bit(ADCSRA,4);

return (ADCH);

}
/*
int ADC_Read(char channel)
{
	int Ain,AinLow;
  //Set input channel to read
	ADMUX = ADMUX|(channel & 0x0f);
   // To Start conversion
	set_bit(ADCSRA,6);
	//check THis flag until it become 0
	while(get_bit(ADCSRA,4)==0);
	//clr flag this flag  clr when we put 1
	set_bit(ADCSRA,4);

	_delay_us(10);
	AinLow = (int)ADCL;		// Read lower byte  another reaslution
	Ain = (int)ADCH*256;		// Read higher 2 bits and
//	Multiply with weight
	Ain = Ain + AinLow;
	return(Ain);			// Return digital value
}
*/
u8 ADC_Read(void)    //we can write u8 if there is meny channel
{

	//channel 0
	clr_bit(ADMUX,0);
	clr_bit(ADMUX,1);
	clr_bit(ADMUX,2);
	clr_bit(ADMUX,3);
	clr_bit(ADMUX,4);

	// start conversion
	set_bit(ADCSRA,6);
	while(get_bit(ADCSRA,4)==0);
	//clr flag
	set_bit(ADCSRA,4);


	return ADCH;

}



/*
extern void ADC_Intit(void)
{
	//enable ADC
	set_bit(ADCSRA,7);
	//clock division
	set_bit(ADCSRA,0);
	set_bit(ADCSRA,1);
	set_bit(ADCSRA,2);
	//disable interrupt
	clr_bit(ADCSRA,3);

	//0>>5
	clr_bit(ADMUX,7);
	set_bit(ADMUX,6);
    // left alynment
	set_bit(ADMUX,5);

}
*/
