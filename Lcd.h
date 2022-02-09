/*
 * Lcd.h
 *
 *  Created on: Feb 26, 2018
 *      Author: G&N&P&M
 */

#ifndef LCD_H_
#define LCD_H_

#include"util.h"
#include"type.h"
#include"dio.h"
#include"stdlib.h"
#include<avr/delay.h>

#define RS    1
#define RW    2
#define EN    3
#define D4  4
#define D5  5
#define D6  6
#define D7  7
#define The_PORT      PORTA
#define The_PORT2     PORTB
#define The_PORT_DDR  DDRA
#define The_PORT_DDR2 DDRB

#define FIRST_LINE		1
#define SECOND_LINE		2
#define THIRD_LINE		3
#define FORTH_LINE		4



void LCD_Init(void);

void LCD_WriteCommand(u8 command);
void LCD_WriteData(u8 data);
void LCD_ClrData(void);


void LCD_WriteString(u8 *str);

void LCD_FirstLine(void);
void LCD_SecondLine(void);
void LCD_ThirdLine(void);
void LCD_FourLine(void);

void LCD_SetCursor(char a, char b);

void LCD_ShiftRight(void);
void LCD_ShiftLeft(void);



void LCD_WriteChar(u8 line,f32 data);




#endif /* LCD_H_ */
