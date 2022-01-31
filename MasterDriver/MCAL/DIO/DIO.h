/*
 * DIO.h
 *
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Library/BIT_Math.h"
#include "../../Library/STD.h"
#include "../../Library/MCU.h"

#define  DIO_PORTA    0
#define  DIO_PORTB    1
#define  DIO_PORTC    2
#define  DIO_PORTD    3

#define  DIO_PIN0     0
#define  DIO_PIN1     1
#define  DIO_PIN2     2
#define  DIO_PIN3     3
#define  DIO_PIN4     4
#define  DIO_PIN5     5
#define  DIO_PIN6     6
#define  DIO_PIN7     7


#define  DIO_PORT_OUTPUT     0XFF
#define  DIO_PORT_INPUT      0X00

#define  DIO_PIN_OUTPUT      1
#define  DIO_PIN_INPUT       0


#define  DIO_PORT_HIGH     0XFF
#define  DIO_PORT_LOW      0X00

#define  DIO_PIN_HIGH       1
#define  DIO_PIN_LOW        0





void DIO_SetPortDir(uint8_t Port, uint8_t Dir);
void DIO_SetPinDir(uint8_t Port , uint8_t Pin , uint8_t Dir);

void DIO_SetPortValue(uint8_t Port, uint8_t Vlaue);
void DIO_SetPinValue(uint8_t Port , uint8_t Pin , uint8_t Value);

void DIO_ReadPortValue(uint8_t Port, uint8_t* Value);
void DIO_ReadPinValue(uint8_t Port, uint8_t Pin ,uint8_t* Value);

void DIO_TogglePort(uint8_t Port);
void DIO_TogglePin(uint8_t Port, uint8_t Pin);

void DIO_SetPullUp(uint8_t Port, uint8_t Pin);


#endif /* DIO_H_ */