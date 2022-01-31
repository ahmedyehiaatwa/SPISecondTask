/*
 * LCD.h
 *
 *  Author: Ahmed
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_CFG.h"
#include "../../MCAL/Timers/Timer0.h"

void LCD_Init(void);

void LCD_WriteCommand(uint8_t cmd);

void LCD_WriteChar(uint8_t data);

void LCD_WriteString(uint8_t* str);

void LCD_WriteInteger(uint16_t  num);

void LCD_GoToLocation(uint8_t row , uint8_t col);

void LCD_Clear(void);



#endif /* LCD_H_ */