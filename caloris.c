/*
 * calor u8 RPM_With_Ratio = 0 ;
	 u8 RPM = 0 ;
	 u8 calories = 0 ;
is.c
 *
 *  Created on: Jun 21, 2018
 *      Author: G&N&P&M
 */
#include "caloris.h"




void Calculate_caloris(u8 volt)
{
	    u32 RPM_With_Ratio = 0 ;
		 u8 RPM = 0 ;


RPM_With_Ratio = volt / 0.06 ;
RPM = RPM_With_Ratio / 4 ;

if( RPM > 80 &&  RPM < 90 )
{
	LCD_SecondLine();
	u8 c1[19]="burning 13 Cal/min";
	LCD_WriteString(c1);

}

else if(RPM>70 && RPM < 80)
{
	LCD_SecondLine();
	u8 c2[20]="burning 11 Cal/min";
	LCD_WriteString(c2);

}
else if(RPM>60 && RPM < 70)
{
	LCD_SecondLine();
	u8 c3[20]="burning 9 Cal/min";
	LCD_WriteString(c3);
}
else if(RPM > 50 && RPM < 60)
{
	LCD_SecondLine();
	u8 c4[20]="burning 8 Cal/min";
	LCD_WriteString(c4);
}
else{
	LCD_SecondLine();
	u8 c5[20]="No Burning Calorie";
	LCD_WriteString(c5);

}


}
