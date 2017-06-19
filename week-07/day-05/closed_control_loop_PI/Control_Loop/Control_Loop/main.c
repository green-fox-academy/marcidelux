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
float P = 0.05;
float I = 0.01;
float sum_err = 0;
float prev_err = 0;
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

int output_calculate_P(float ref, float measured)
{
	float error = ref - measured;
	int temp = (int)(P * error);
	
	if (temp < output_min)
		temp = output_min;
	else if (temp > output_max)
		temp = output_max;
	
	return temp;
}

int output_calculate_PI(float ref, float measured)
{
	float error = ref - measured;
	sum_err += error;
	float Propotional = P * error;
	float Integral = I * sum_err;
	int temp  = (int)(Propotional + Integral);
	
	if (temp < output_min) {
		temp = output_min;
		sum_err -= error;
	} else if (temp > output_max) {
		temp = output_max;
		if(error >= 0) {
			sum_err -= error;
		} 
	}
	
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
	uint8_t output;
	uint8_t output_print;
	float rpm_measured;
	float freq;
	
	uint16_t rpm_print;
	uint16_t ref_print;
	
    while (1) 
    {
		adc = ADC_read(); 
		rpm_measured = get_rpm();
		ref = (float)adc * rpm_devider;
		//output = output_calculate_P(ref, rpm_measured);
		output = output_calculate_PI(ref, rpm_measured);
		set_duty_8bit(output);
		
		rpm_print = (uint16_t)rpm_measured;
		ref_print = (uint16_t)ref;
		output_print = (int)(output / 2.55);
		
		printf("%d\t%d\t%d\n", ref_print, rpm_print, output_print);
		
		_delay_ms(100);
		
    }
}