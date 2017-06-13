/*
 * I2P_TC74.c
 *
 * Created: 2017. 06. 07. 10:52:25
 * Author : Marci
 */ 

#include "TC74_driver.h"
#include "UART_driver.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <string.h>


#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/delay.h>

#define LED_DDR			DDRB
#define LED_DDR_POS		DDRB5
#define LED_PIN			PINB
#define LED_PIN_POS		PINB5
#define LED_PORT		PORTB
#define LED_PORT_POS	PORTB5

uint8_t count = 1;
uint8_t max_count = 10;


void system_init()
{
	TWI_init();
	UART_init();
	
	LED_DDR |= 1 << LED_DDR_POS;
	TCCR0B |= 1 << CS02;
}

int main(void)
{
	system_init();
	
	uint8_t temp;
	char temp_char[20];
	
	FILE UART_output = FDEV_SETUP_STREAM(UART_send_character, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_get_character, _FDEV_SETUP_READ);
	stdin = &UART_input;

	while (1) {
		temp = read_temp(TC74A0_ADRESS);
		printf("%d\n", temp);
		LED_PIN |= 1 << LED_PIN_POS;
		_delay_ms(1000);
		//TODO
		//Write the temperature frequently.

		//temp = TC74_Get_Temp(TC74A0_ADRESS);
		
		
		//strcpy(temp_char, data_to_char_Temp(temp));
		
		//printf(temp_char);
		//_delay_ms(1000);
		
		
		//TODO
		//Advanced: Don't use delay, use timer.

		//TODO
		//Blink the led to make sure the code is running
		
	}
	
	
}
