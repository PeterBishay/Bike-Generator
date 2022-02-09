/*
 * Lcd.c
 *
 *  Created on: Feb 26, 2018
 *      Author: G&N&P&M
 */

#include"Lcd.h"


void LCD_Init(void)
{

    set_bit(The_PORT_DDR,D4);
    set_bit(The_PORT_DDR,D5);
    set_bit(The_PORT_DDR,D6);
    set_bit(The_PORT_DDR,D7);
    set_bit(The_PORT_DDR2,RS);
    set_bit(The_PORT_DDR2,RW);
    set_bit(The_PORT_DDR2,EN);


    set_bit(The_PORT,D4);
    set_bit(The_PORT,D5);
    set_bit(The_PORT,D6);
    set_bit(The_PORT,D7);
    set_bit(The_PORT2,RS);
    set_bit(The_PORT2,RW);
    set_bit(The_PORT2,EN);

    _delay_ms(32);
	// 0b0011
	  LCD_WriteCommand(0x03);
      _delay_ms(40);
      //0b0010
      //N(0:1- line display)F(0:5*8 dot character font)XX
      LCD_WriteCommand(0x02);
      LCD_WriteCommand(0x08);
      _delay_ms(40);
      LCD_WriteCommand(0x02);
      LCD_WriteCommand(0x08);
      _delay_ms(40);
    //command 0x01  clr screen
      // no Curse no blinking
      LCD_WriteCommand(0x00);
      LCD_WriteCommand(0x0c);
      _delay_ms(40);
      LCD_WriteCommand(0x00);
      LCD_WriteCommand(0x01);
      _delay_ms(1.53);
}

void LCD_WriteCommand(u8 command)
{
	//Clr RS
	clr_bit(The_PORT2,RS);
	//Clr R/W to make it write
 	clr_bit(The_PORT2,RW);


	/* Here we get The High Nipple The high for bit  PORTA = PORTA & (0b00001111) then put the high nipple in THe command by | (command&(0b11110000)>>4*16)
       * Assign_Nibble_High(PORTA,(Get_Nibble_High(command)));
       * OR The_PORT = (The_PORT&(0b00001111)) | (command&(0b11110000)>>4*16);*/


 	assain_bit(The_PORT,D4,get_bit(command,4));
 	assain_bit(The_PORT,D5,get_bit(command,5));
 	assain_bit(The_PORT,D6,get_bit(command,6));
 	assain_bit(The_PORT,D7,get_bit(command,7));


	//Enable
      set_bit(The_PORT2,EN);
      _delay_ms(20);
     //Disable
      clr_bit(The_PORT2,EN);
      _delay_ms(50);

  	//Clr RS
  	clr_bit(The_PORT2,RS);
  	//Clr R/W to make it write
  	clr_bit(The_PORT2,RW);
  	/* Here we get The High Nipple The high for bit  PORTA = PORTA & (0b00001111) then put the LOW nipple in THe command by | (command&(0b00001111)*16)
  	  *  Assign_Nibble_High(The_PORT,(Get_Nibble_Low(command)));
  	 *  OR The_PORT = (The_PORT&(0b00001111)) | (command&(0b00001111)*16);*/

 	assain_bit(The_PORT,D4,get_bit(command,0));
 	assain_bit(The_PORT,D5,get_bit(command,1));
 	assain_bit(The_PORT,D6,get_bit(command,2));
 	assain_bit(The_PORT,D7,get_bit(command,3));

  	//Enable
  	set_bit(The_PORT2,EN);
  	_delay_ms(20);
  	//Disable
  	clr_bit(The_PORT2,EN);
  	_delay_ms(50);

}

void LCD_WriteData(u8 data)
{
	//set RS
	set_bit(The_PORT2,RS);
	//Clr R/W to make it read
 	clr_bit(The_PORT2,RW);


	/* Here we get The High Nipple The high for bit  PORTA = PORTA & (0b00001111) then put the high nipple in THe command by | (command&(0b11110000)>>4*16)
      * Assign_Nibble_High(PORTA,(Get_Nibble_High(data)));
 	 * OR The_PORT = (The_PORT&(0b00001111)) | (data&(0b11110000)>>4*16); */

 	assain_bit(The_PORT,D4,get_bit(data,4));
 	assain_bit(The_PORT,D5,get_bit(data,5));
 	assain_bit(The_PORT,D6,get_bit(data,6));
 	assain_bit(The_PORT,D7,get_bit(data,7));



	//Enable
      set_bit(The_PORT2,EN);
      _delay_us(20);
     //Disable
      clr_bit(The_PORT2,EN);
      _delay_us(100);

  	//set RS
  	set_bit(The_PORT2,RS);
  	//Clr R/W to make it write
  	clr_bit(The_PORT2,RW);

  	/* Here we get The High Nipple The high for bit  PORTA = PORTA & (0b00001111) then put the LOW nipple in THe command by | (command&(0b00001111)*16)
  	  * Assign_Nibble_High(The_PORT,(Get_Nibble_Low(data)));
  	  * The_PORT = (The_PORT&(0b00001111)) | (data&(0b00001111)*16);*/

 	assain_bit(The_PORT,D4,get_bit(data,0));
 	assain_bit(The_PORT,D5,get_bit(data,1));
 	assain_bit(The_PORT,D6,get_bit(data,2));
 	assain_bit(The_PORT,D7,get_bit(data,3));

  	//Enable
  	set_bit(The_PORT2,EN);
  	_delay_us(20);
  	//Disable
  	clr_bit(The_PORT2,EN);
  	_delay_us(100);


}

void LCD_WriteString(u8  *str)
{
// This function to write string
	for(int x=0; str[x] !='\0' ; x++)
	{
	LCD_WriteData(str [x]);
	//_delay_us(10);
	}
}

void LCD_ClrData(void)
{
	LCD_WriteCommand(0x01);
}

void LCD_FirstLine(void)
{
	LCD_WriteCommand(0x80);
}
void LCD_SecondLine(void)
{
	LCD_WriteCommand(0xC0);
}
void LCD_ThirdLine(void)
{
	LCD_WriteCommand(0x94);
}
void LCD_FourLine(void)
{
	LCD_WriteCommand(0xD4);
}


void LCD_SetCursor(char a, char b)
{
	char temp;
	if(a == 1)
	{
		temp = 0x80 + b;
		LCD_WriteCommand(temp);


	}
	else if(a == 2)
	{
		temp = 0xC0 + b;
		LCD_WriteCommand(temp);

	}
	else if(a== 3)
	{
		temp = 0x94 + b;
		LCD_WriteCommand(temp);

	}
	else if(a == 4)
	{
		temp = 0xD4 + b;
		LCD_WriteCommand(temp);

	}
}


void LCD_ShiftLeft(void)
{
	LCD_WriteCommand(0x18);
}
void LCD_ShiftRight(void)
{
	LCD_WriteCommand(0x1C);
}


void LCD_WriteChar(u8 line,f32 data){
	switch(line){
	case 1 : LCD_FirstLine();
			break;
	case 2 : LCD_SecondLine();
			break;
	case 3 : LCD_ThirdLine();
			break;
	case 4 : LCD_FourLine();
			break;
	}

	char screen[16];
	dtostrf(data,6,2,screen);
	LCD_WriteString((u8*)screen);
}


