/*
 * SPI.h
 *
 *  Author: Ahmed
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "../DIO/DIO.h"

void SPI_Master_Init(void);

void SPI_Slave_Init(void);

void SPI_Master_InitTrans(void);

void SPI_Master_TermTrans(void);

uint8_t SPI_TransSiver(uint8_t data);

uint8_t SPI_receiveByte(void);

void SPI_sendString(const uint8_t * StrMessage);

void SPI_receiveString(uint8_t * StrMessage);


#endif /* SPI_H_ */