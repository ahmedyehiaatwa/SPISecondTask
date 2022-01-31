/*
 * UART.c
 *
 *  Author: Ahmed
 */ 

#include "UART.h"

void UART_Init(void)
{
	uint32_t UBBR_Val=0;
	
	SET_BIT(DDRD,1); // Tx pin output
	CLR_BIT(DDRD,0); // Rx pin output
	
	SET_BIT(UCSRB,4); // Enable Tx
	SET_BIT(UCSRB,3); // Enable Rx
	
	UCSRC |= 0x86;
	
	UBBR_Val=(160000) / (16*96) - 1; // Set Baud rate
	UBRRL= UBBR_Val;
	
}

void UART_Tx(uint8_t data)  // Send data
{
	UDR = data;
	while(GET_BIT(UCSRA,5)==0);
	
}

void UART_TxString (uint8_t* str)  // send string
{
	uint8_t i=0;
	
	while (str[i] != '\0')
	{
		UART_Tx(str[i]);
		i++;
	}
}

uint8_t UART_Rx(uint8_t * data)   // Receive data
{
	while (GET_BIT(UCSRA,7)==0);
	
	*data = UDR;
	
	return data;	
}

uint8_t UART_RxString(uint8_t *str)  // Receive string
{
	uint8_t i=0;
	UART_Rx(&str[i]);
	while(str[i] != '\n' && str[i] != '\r')
	{
		i++;
		UART_Rx(&str[i]);
	}
	str[i]= '\0';
}
