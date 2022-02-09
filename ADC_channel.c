/*
 * ADC_channel.c
 *
 *  Created on: Mar 21, 2018
 *      Author: G&N&P&M
 */

#include"type.h"
#include"dio.h"
#include"util.h"
#include"ADC.h"
#include"Relay.h"


int channel_0_volt_Generatorvoltmeter(void)
{

	RELAY_SW_BATTERY_OFF

    	u32 Digital =0 ;
    	float Analog =0 ;

    	char voltageshow[7];

/********************************************channel 0 for voltameter*********************************/

		// For channel 0 Voltameter
		// sence Motor Voltage
			Digital =analog_read(0);  // use channel 0
			Analog =  (Digital*5*RATIO)/255 ;  ///ADC/18.618;
	        LCD_FourLine(); // write on first line
	        LCD_WriteString("V1=\0 ");
	       // LCD_SetCursor(1,12);

	        dtostrf(Analog,5,2,voltageshow);
	        LCD_WriteString(voltageshow);
	        LCD_WriteString("V");

	        return Analog ;
}


int channel_1_volt_BattaryVoltmerter(void)
{
	RELAY_SW_GENERATOR_OFF


	u32 Digital =0 ;
	float Analog =0 ;

	char voltageshow[7];


	 /*********************************************channel 1 voltameter ****************************************/

	        // For chaneel 1 Voltmeter
		    // sence Battary Voltage
		 Digital =analog_read(1); // write on channel 1
		 Analog =  (Digital*5*RATIO)/255 ;  ///ADC/18.618;
		 // To show on lCD
		 LCD_FourLine();
		 LCD_WriteString("         V2 = \0");
		// LCD_SetCursor(2,12);

		 dtostrf(Analog,5,2,voltageshow);

		 	 //dtostr(double precision value, width, precision, string that will store the numbers);
	        // Value is either a direct value plugged into this place, or a variable to contains a value.
	        //Width that is used with dtostrf is the number of characters in the number that includes the negative sign (-). For instance, if the number is -532.87, the width would be 7 including the negative sign and the decimal point.
	        //Precision is how many numbers would be after the decimal point in the dtostrf usage.
				     LCD_WriteString(voltageshow);
				     LCD_WriteString("V");

				     return Analog;
				     }


/*

int channel_2_current_ConverterBattery(void)
{
	u8  temp=0;
	u16 Factor = 0.106 ; // from equation 0.0264 mA   (0.0264(count -512));
	u32 Digital =0 ;
	float Analog =0 ;

	char voltageshow[7];
	// FOr channel 2 currentmeter
				  //sence converter - battery current
					Digital =analog_read(2);
					Analog = Analog + Digital;
					Analog = Analog + Digital;
					Analog = Analog/3;
					temp = (Analog-128) * Factor ;  // From equation
					Analog = temp/100;

					LCD_ThirdLine();
					LCD_WriteString("con.current=\0");
			//		LCD_SetCursor(3,14);

					dtostrf(Analog,5,2,voltageshow);
					LCD_WriteString(voltageshow);
					LCD_WriteString("A");

return Analog;
}


int channel_3_current_BatteryLoad(void)
{

			int adc =0; // variable to read ADC value
		  int voltage ; // variable to store voltage
		  int Amps; // variable to store Amps value
		  int am1,am2,am3,am4,am5 ;// variable to spilt Amps value intp char
		  while(1){

		  for(int i =0 ; i <20; i++ )
		  {
			  adc = 0;
			  adc=analog_read(2);
			  voltage =adc*19.53125; //calculate the voltage

			  if (voltage >= 2500)// if the current is positive
				  Amps += ((voltage -2500)/18.5);
			  else if(voltage <= 2500) //if the current is negative
				  Amps +=((2500 -voltage)/18.5);
		  }
		  Amps /=20 ; // average of the value that was read 20 time



	  	  am1 = (Amps/10000)%10;
		  am2 = (Amps/1000)%10;
		  am3 = (Amps/100)%10;
		  am4 = (Amps/10)%10;
		  am5 = (Amps/1)%10;


		  LCD_SetCursor(4,0);
		  LCD_WriteString("Current  =\0");
		  LCD_WriteData(am1+'0');
		  LCD_WriteData(am2+'0');
		  LCD_WriteData('.');
		  LCD_WriteData(am3+'0');
		  LCD_WriteData(am4+'0');
		  LCD_WriteData(am5+'0');

		  return Amps;
}


*/


