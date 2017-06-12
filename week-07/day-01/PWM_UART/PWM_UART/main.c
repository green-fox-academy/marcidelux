/*
 * PWM_UART.c
 *
 * Created: 2017. 06. 12. 15:05:03
 * Author : Marci
 */ 

#include "ADC_driver.h"
#include "UART_driver.h"
#include "PWM.h"

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>

void system_init(){
	ADC_init();
	UART_init();
	PWM_init();
	sei();
}


int main(void)
{
	system_init();
	
	char row[5];
	char temp[5];
	int duty;
	
	FILE UART_output = FDEV_SETUP_STREAM(UART_send_character, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_get_character, _FDEV_SETUP_READ);
	stdin = &UART_input;
	
	printf("Startup...\n");
	
    while (1) 
    {
		if (UDR0 != NULL)
		{
			gets(row);
			strcpy(temp, row) ;
			printf("%s%% of 5[V]\n", temp);
			duty = atoi(row);
			set_duty_precent(duty);

		}
    }
}
