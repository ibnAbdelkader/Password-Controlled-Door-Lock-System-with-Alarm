/*
 * Motor.c
 *
 * Created: 04/04/2015 05:55:28 م
 *  Author: Ahmed Abdel-Kader
 */ 

#include "Motor.h"



void Motor_config (void){
	
	g_motor_config.direction = Motor_Dir;
	g_motor_config.pin_num = Motor_firstPin_Num;
	g_motor_config.port = Motor_Port;
	g_motor_config.value = LOGIC_LOW;
	
	g_motor_config_1.direction = Motor_Dir;
	g_motor_config_1.pin_num = Motor_secondPin_Num;
	g_motor_config_1.port = Motor_Port;
	g_motor_config_1.value = LOGIC_LOW;
	
	g_motor_config.direction = OUTPUT;
	DIO_Set_Direction(& g_motor_config);
	g_motor_config_1.direction = OUTPUT;
	DIO_Set_Direction(& g_motor_config_1);
	
}

void Clock_Wise (void){
	
	while(g_tick != 31){
		//PORTC = PORTC | (1<<PC0);
		//PORTC = PORTC & (~(1<<PC1));
		g_motor_config.value = LOGIC_HIGH;
		DIO_Write_Pin(& g_motor_config);
		g_motor_config_1.value = LOGIC_LOW;
		DIO_Write_Pin(& g_motor_config_1);
	}
	g_tick = 0;
}

void Anti_Clock_Wise (void){
	while(g_tick != 31){
		//PORTC = PORTC | (1<<PC1);
		//PORTC = PORTC & (~(1<<PC0));
		
		g_motor_config.value = LOGIC_LOW;
		DIO_Write_Pin(& g_motor_config);
		g_motor_config_1.value = LOGIC_HIGH;
		DIO_Write_Pin(& g_motor_config_1);
	}
	g_tick = 0;
}

void Motor_Stop (void){
	while(g_tick != 31){
		//PORTC = PORTC & (~(1<<PC0));
		//PORTC = PORTC & (~(1<<PC1));
		
		g_motor_config.value = LOGIC_LOW;
		DIO_Write_Pin(& g_motor_config);
		g_motor_config_1.value = LOGIC_LOW;
		DIO_Write_Pin(& g_motor_config_1);
	}
	g_tick = 0;
}


void Motor_Start (void){
	
	//DDRB  = DDRB | (1<<PB3); //set OC0 as output pin --> pin where the PWM signal is generated from MC.
	//DDRC  = DDRC | (1<<PC0); 
	//DDRC  = DDRC | (1<<PC1);
	
	

	sei();
	Timer0_init_normal();
	Clock_Wise();
	Motor_Stop();
	Anti_Clock_Wise(); 
	
}