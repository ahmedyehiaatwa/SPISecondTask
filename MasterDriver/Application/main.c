/*
 * SPI_Driver.c
 *
 * Author : Ahmed
 */ 

#include "../MCAL/SPI/SPI.h"
#define F_CPU 16000
#include "../MCAL/Timers/Timer0.h"
#include "../ECUAL/LCD/LCD.h"


int main(void)
{
	uint8_t data = 0;
	
	UART_Init();
	
	LCD_Init();
	
	SPI_Master_Init();
	SPI_Master_InitTrans();
	TIMER0_u8PollingDelay(1000);	
	
	while (1)
	{
		data= UART_Rx();
		
		if(data)
		{
			LCD_WriteChar(data);
			SPI_TransSiver(data);
			data=0;
			
		}
		
	}
}

