/*
 * Buzzer.c
 *
 * Created: 05/04/2015 12:53:32 ص
 *  Author: Ahmed Abdel-Kader
 */ 

#include "Buzzer.h"


void Buzzer_Config(void){
	
	g_buzzer_config.port = Buzzer_Port;
	g_buzzer_config.pin_num = Buzzer_Pin_Num;
	g_buzzer_config.direction = Buzzer_Dir;
	g_buzzer_config.value = LOGIC_LOW;
	
	DIO_Set_Direction(& g_buzzer_config);
	DIO_Write_Pin(& g_buzzer_config);
	
}

void Buzzer_Start (void){
	//DDRC = DDRC | (1<<PC3);
	//PORTC = PORTC & (~(1<<PC3));
	
	
	
	sei();
	Timer0_init_normal();
	while (g_tick != 186){
		//PORTC = PORTC | (1<<PC3);
		g_buzzer_config.value = LOGIC_HIGH;
		DIO_Write_Pin(& g_buzzer_config);
	}
	g_tick = 0;
	//PORTC = PORTC & (~(1<<PC3));
	g_buzzer_config.value = LOGIC_LOW;
	DIO_Write_Pin(& g_buzzer_config);
	
	
}