/*
 * SPI.c
 */ 
#include "SPI.h"

void SPI_Master_Init(void)
{
	DIO_SetPinDir(DIO_PORTB, DIO_PIN6, DIO_PIN_INPUT);  // MISO
	DIO_SetPinDir(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);  // MOSI
	DIO_SetPinDir(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);  // CLOCK
	DIO_SetPinDir(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT);  // SS
	
	SPI->SPCR |= 0x53; // in binary 01010011
	
	DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH); // SS Pin NO init trans
}

void SPI_Slave_Init(void)
{
		DIO_SetPinDir(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);  // MISO
		DIO_SetPinDir(DIO_PORTB, DIO_PIN5, DIO_PIN_INPUT);  // MOSI
		DIO_SetPinDir(DIO_PORTB, DIO_PIN7, DIO_PIN_INPUT);  // CLOCK
		DIO_SetPinDir(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT);  // SS
		
		SPI->SPCR |= 0x40; // in binary 01000000
}

void SPI_Master_InitTrans(void)
{
	DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_LOW);
}

void SPI_Master_TermTrans(void)
{
	DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH);
}

uint8_t SPI_TransSiver(uint8_t data)
{
	uint8_t rec_data=0;
	
	SPI->SPDR=data;
	
	while(GET_BIT(SPI->SPSR,7)==0);
	
	rec_data= SPI->SPDR;
	
	return rec_data;
}

uint8_t SPI_receiveByte(void)
{
	while(!GET_BIT(SPI->SPSR,7)){} 
	return SPI->SPDR; 
}

void SPI_sendString(const uint8_t * StrMessage)
{
	uint8_t i = 0;

	while(StrMessage[i] != '\0')
	{
		SPI_TransSiver(StrMessage[i]);
		i++;
	}
}

void SPI_receiveString(uint8_t * StrMessage)
{
	uint8_t i = 0;

	StrMessage[i] = SPI_receiveByte();
	while(StrMessage[i] != '#')
	{
		i++;
		StrMessage[i] = SPI_receiveByte();
	}
	StrMessage[i] = '\0';
}