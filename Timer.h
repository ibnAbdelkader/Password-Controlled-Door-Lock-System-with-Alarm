/*
 * Timer.h
 *
 * Created: 03/04/2015 08:09:42 م
 *  Author: Ahmed Abdel-Kader
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

 
 
volatile uint8 g_tick;

ISR(TIMER0_OVF_vect);


void Timer0_init_normal (void);

void Timer0_init_CTC (uint8 value_to_compare);

void Timer0_init_PWM(uint8 duty_cycle);


#endif /* TIMER_H_ */