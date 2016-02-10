/*
 * finalpro.c
 *
 * Created: 20/03/2015 11:10:21 ص
 *  Author: Ahmed Abdel-Kader
 */ 


#include "External_EEPROM.h"
#include "Motor.h"
#include "UART.h"
#include "Buzzer.h"


int main(void)
{
	uint8 entered_passwd = 0;
	uint8 saved_passwd = 0;
	uint8 iteration = 0;
	
	DDRB  = 0xFF;
	PORTB = 0x00;

	EEPROM_Init();
	UART_init();
	Motor_config();
	Buzzer_Config();

	entered_passwd = UART_recieveByte(); //Receive Byte from Terminal1
	
	//EEPROM_Read_Byte(0x0311, &saved_passwd); // Read 0xFF from the external EEPROM
	//_delay_ms(10);
	
	EEPROM_Write_Byte(0x0311, entered_passwd); // Write 0xFF in the external EEPROM
	
	
	
	
	while(1)
	{
		//PORTB = saved_passwd; // out the read value from the external EEPROM
		entered_passwd = UART_recieveByte(); //Receive Byte from Terminal1
		
		EEPROM_Read_Byte(0x0311, &saved_passwd); // Read 0xFF from the external EEPROM
		
		while(entered_passwd != saved_passwd)
		{
			entered_passwd = UART_recieveByte(); //Receive Byte from Terminal1
			iteration ++;
			
			if(iteration == 2)
			{
				break;
			}
		}
		
		if(entered_passwd == saved_passwd)
		{
			Motor_Start();
			iteration = 0;
		}
		
		else
		{
			Buzzer_Start();
			iteration = 0;
		}
		
		
	}

}