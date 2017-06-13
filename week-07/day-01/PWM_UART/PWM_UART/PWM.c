#include "PWM.h"
#include <avr/io.h>
#include <stdint.h>

void PWM_init()
{
	TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);
		
	TCCR0B |= 0b101;

	//This is the output of the pwm signal
	DDRD |= 1 << DDRD6;
}

void set_duty_precent(int precent)
{
	int duty = (int)(2.55 * precent);
	OCR0A = duty;
}