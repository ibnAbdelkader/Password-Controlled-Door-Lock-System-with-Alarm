/*
 * Motor.h
 *
 * Created: 04/04/2015 05:54:42 م
 *  Author: Ahmed Abdel-Kader
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "Timer.h"
#include "DIO.h"
#define Motor_Dir OUTPUT
#define Motor_Port 'C'
#define Motor_firstPin_Num 0
#define Motor_secondPin_Num 1

static DIO_Config g_motor_config;
static DIO_Config g_motor_config_1;




void Motor_config (void);

void Clock_Wise (void);

void Anti_Clock_Wise (void);

void Motor_Stop (void);

void Motor_Start (void);



#endif /* MOTOR_H_ */