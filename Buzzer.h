/*
 * Buzzer.h
 *
 * Created: 05/04/2015 12:53:53 ص
 *  Author: Ahmed Abdel-Kader
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#include "Timer.h"
#include "DIO.h"

#define Buzzer_Dir OUTPUT
#define Buzzer_Port 'C'
#define Buzzer_Pin_Num 3

static DIO_Config g_buzzer_config;

void Buzzer_Config(void);

void Buzzer_Start (void);

	

#endif /* BUZZER_H_ */