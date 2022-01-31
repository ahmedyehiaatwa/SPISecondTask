/*
 * Timer0.c
 *
 * Created: 30/01/2022 21:32:20
 *  Author: HP
 */ 

#include "Timer0.h"
#define NULL 0

static uint16_t volatile compare;
static uint16_t volatile counter;
static DELAY delay_stat = DELAY_OK;
static void (*delayCallBack)(void); // a pointer to a function that will be called when the delay is finished


/*
* brief: This function is used to initialize Timer 0 to use CTC mode and 64 prescaler
* return: (output) the Error state of the function 0 if an error happens and 1 otherwise
*/
uint8_t TIMER0_u8Init(void){
	TCCR0 = (1 << WGM01) | (1<<CS01) | (1 << CS00);
	return DELAY_OK;
}
/*
* brief: This function is used to initialize an interrupt delay if the Timer isn't busy
* param.: (input) the delay to be set in ms
* param.: (input) a pointer to a function to be called when the delay is over
* return: (output) the Error state of the function 0 if an error happens, 2 if the timer is busy and 1 otherwise
*/
uint8_t TIMER0_u8InterruptDelay(uint16_t delay, void (*fnCallBack)(void)){
	if(delay_stat == DELAY_BUSY){
		return delay_stat;
	}
	delay_stat = DELAY_BUSY;
	compare = delay;
	if(fnCallBack != NULL){
		delayCallBack = fnCallBack;
		OCR0 = (F_CPU / PRESCALER);
		SET_BIT(TIMSK, OCIE0);
		SET_BIT(SREG, I_BIT);
		return DELAY_OK;
	}
	else{
		return DELAY_ERR;
	}
}

/*
* brief: This function is used to initialize a polling delay if the Timer isn't busy
* param.: (input) the delay to be set in ms
* return: (output) the Error state of the function 0 if an error happens, 2 if the timer is busy and 1 otherwise
*/
uint8_t TIMER0_u8PollingDelay(uint16_t delay){
	if(delay_stat == DELAY_BUSY){
		return delay_stat;
	}
	delay_stat = DELAY_BUSY;
	counter = 0;						// reset counter to 0
	compare = delay;
	TIMER0_u8Init();					// initialize timer0
	OCR0 = (F_CPU / PRESCALER);		// set OCR0_REG value
	SET_BIT(TIMSK, OCIE0);			// enable interrupt
	SET_BIT(SREG, I_BIT);
	while (counter <= compare);			// stop if delay not finished
	CLR_BIT(TIMSK, OCIE0);
	delay_stat = DELAY_OK;
	return DELAY_OK;
}
void __vector_10(void){
	counter++;
	if(counter == compare && delayCallBack != NULL){
		counter = 0;
		CLR_BIT(TIMSK, OCIE0);
		delay_stat = DELAY_OK;
		delayCallBack();
	}
}