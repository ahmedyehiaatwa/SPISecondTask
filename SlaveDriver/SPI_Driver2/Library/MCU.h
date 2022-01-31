/*
 * MCU.h
 *
 */ 


#ifndef MCU_H_
#define MCU_H_

#include "STD.h"

// DIO REGISTERS //

#define    PORTA   (*(volatile uint8_t*)0x3B)
#define    DDRA    (*(volatile uint8_t*)0x3A)
#define    PINA    (*(volatile uint8_t*)0x39)

#define    PORTB    (*(volatile uint8_t*)0x38)
#define    DDRB     (*(volatile uint8_t*)0x37)
#define    PINB     (*(volatile uint8_t*)0x36)

#define    PORTC    (*(volatile uint8_t*)0x35)
#define    DDRC     (*(volatile uint8_t*)0x34)
#define    PINC     (*(volatile uint8_t*)0x33)

#define    PORTD    (*(volatile uint8_t*)0x32)
#define    DDRD     (*(volatile uint8_t*)0x31)
#define    PIND     (*(volatile uint8_t*)0x30)


// EXTERNAL INTERRUPTS REGISTERS //


#define SREG   (*(volatile uint8_t*)(0x5F))

#define GICR   (*(volatile uint8_t*)(0x5B))

#define GIFR   (*(volatile uint8_t*)(0x5A))

#define MCUCR  (*(volatile uint8_t*)(0x55))

#define MCUCSR (*(volatile uint8_t*)(0x54))


// ADC REGISTERS //

#define ADMUX           (*(volatile uint8_t *)(0x27))
#define ADCSRA          (*(volatile uint8_t *)(0x26))
#define ADCH            (*(volatile uint8_t *)(0x25))
#define ADCL            (*(volatile uint8_t *)(0x24))
#define ADC_VALUE       (*(volatile uint16_t *)(0x24))


// Timer0 Registers//

#define TCNT0   (*(volatile uint8_t*)(0x52))
#define TCCR0   (*(volatile uint8_t*)(0x53))
#define OCR0    (*(volatile uint8_t*)(0x5C))
#define TIMSK   (*(volatile uint8_t*)(0x59))
#define TIFR    (*(volatile uint8_t*)(0x58)

// Timer1 register //

#define TCCR1A (*(volatile uint8_t*)(0x4F))
#define TCCR1B (*(volatile uint8_t*)(0x4E))
#define OCR1A  (*(volatile uint16_t*)(0x4A))
#define ICR1   (*(volatile uint16_t*)(0x46))

// UART REGISTERS //

#define UBRRH (*((volatile uint8_t*)0x40))
#define UBRRL (*((volatile uint8_t*)0x29))
#define UCSRA (*((volatile uint8_t*)0x2B))
#define UCSRB (*((volatile uint8_t*)0x2A))
#define UCSRC (*((volatile uint8_t*)0x40))
#define UDR (*((volatile uint8_t*)0x2C))

// SPI REGISTERS // 

typedef struct
{
	uint8_t SPCR;
	uint8_t SPSR;
	uint8_t SPDR;
	}SPI_REGS;

#define SPI ((volatile SPI_REGS*)(0x2D))


#endif /* MCU_H_ */