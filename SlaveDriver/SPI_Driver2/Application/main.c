/*
 * SPI_Driver.c
 *
 * Created: 03/06/2021 11:12:15
 * Author : Ahmed
 */ 

#include "../MCAL/SPI/SPI.h"
#include "../MCAL/Timers/Timer0.h"
#include "../ECUAL/LED/LED.h"
#define F_CPU 16000000



int main(void)
{
   uint8_t tx_data=0;
   uint8_t rx_data=0;
   
   
   LED1_Init();
   SPI_Slave_Init();
   LED0_Init();
   LED1_Init();
   
   
   while (1)
   {
	   rx_data = SPI_TransSiver(tx_data);
	   
	   switch (rx_data)
	   {
		   case 49:
		   LED0_On();
		   break;
		   
		   case 50:
		   LED0_Off();
		   break;
		   
		   case 51:
		   LED1_On();
		   break;
		   
		   case 52:
		   LED1_Off();
		   break;
		   
		   default:
		   break;
	   }
	   
   }
}

