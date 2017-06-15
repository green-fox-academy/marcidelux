/*
 * loop_control_open.c
 *
 * Created: 2017. 06. 14. 15:17:38
 * Author : Marci
 */ 

#ifndef F_CPU
#define F_CPU 16000000
#define MAXIMUM_FAN_RPM 5000
#endif

#include "ADC_driver.h"
#include "freq_meas.h"
#include "UART_driver.h"
#include "PWM.h"
#include "AC_driver.h"

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>

// Global variables
float P = 0.5;
int output_max = 255;
int output_min = 0;
float rpm_devider = (float)MAXIMUM_FAN_RPM / 1023;
	
void system_init()
{
	PWM_init();
	ADC_init();
	UART_init();
	freq_meas_init();
	AC_driver_init();
	sei();
}

int output_calculate(float ref, float measured)
{
	float error = ref - measured;
	int temp = (int)(P * error);
	
	if (temp < output_min)
		temp = output_min;
	else if (temp > output_max)
		temp = output_max;
	
	return temp;
}

int main(void)
{
	system_init();
	
	FILE UART_output = FDEV_SETUP_STREAM(UART_send_character, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_get_character, _FDEV_SETUP_READ);
	stdin = &UART_input;
	
	uint16_t adc;
	float ref;
	float output;
	float rpm_measured;
	float P;
	
	

	
    while (1) 
    {
		adc = ADC_read(); 
		rpm_measured = get_rpm();
		ref = (float)adc * rpm_devider;
		output = output_calculate(ref, rpm_measured);
		set_duty_8bit(output);
		//set_duty_rpm(ref);
		
		printf("%0.0f\t%.0f\t%0.0f\n", ref, rpm_measured, output);

		
		_delay_ms(100);
		
    }
}