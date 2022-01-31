/*
 * LCD_CFG.h
 *
 *  Author: Ahmed
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include  "../../MCAL/DIO/DIO.h"

#define     LCD_MODE      4



#define     LCD_4BIT_MODE_CMD_PORT        DIO_PORTA
#define     LCD_4BIT_MODE_DATA_PORT       DIO_PORTA
#define     LCD_4BIT_EPIN                 DIO_PORTB


#define     LCD_RS_PIN                    DIO_PIN1
#define     LCD_RW_PIN                    DIO_PIN2
#define     LCD_E_PIN                     DIO_PIN3

#define     LCD_D0                        DIO_PIN0 
#define     LCD_D1                        DIO_PIN1
#define     LCD_D2                        DIO_PIN2
#define     LCD_D3                        DIO_PIN3
#define     LCD_D4                        DIO_PIN4
#define     LCD_D5                        DIO_PIN5
#define     LCD_D6                        DIO_PIN6
#define     LCD_D7                        DIO_PIN7    


#endif /* LCD_CFG_H_ */