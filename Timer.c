/*
 * Timer.c
 *
 * Created: 03/04/2015 08:09:22 م
 *  Author: Ahmed Abdel-Kader
 */ 

#include "Timer.h"


ISR(TIMER0_OVF_vect){
	g_tick ++;
}

void Timer0_init_normal (void){
	TCNT0 = 0;
	TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);
	TIMSK = (1<<TOIE0);
	
}

void Timer0_init_CTC (uint8 value_to_compare){
	TCNT0 = 0;
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<CS00) | (1<<CS02);
	TIMSK = (1<<OCIE0);
	OCR0 = value_to_compare;
	
}

void Timer0_init_PWM(uint8 duty_cycle){
	uint8 value_to_compare;
	value_to_compare = (duty_cycle/100)*256 ; 
	OCR0 = value_to_compare ; 
	TCNT0 = 0;
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01) ;
}