#include "PWM.h"
#include <avr/io.h>
#include <stdint.h>

void PWM_init()
{
	// Set FAST PWM mode, with comparison of OCRA
	TCCR2A |= 1 << WGM21;
	TCCR2A |= 1 << WGM20;

	// Set OC0A pin to high when compare match occures, clear OC0A when counter overflows
	TCCR2A |= 1 << COM2A1;

	// Enable OC0A pin as output
	DDRB |= 1 << DDRB3;

	// Set clock speed to minimum, Tcnt will be 16MHz/1024 / 255 ~ 61Hz (1024 prescaler)
	TCCR2B |= 1 << CS20;
	TCCR2B |= 1 << CS21;
	TCCR2B |= 1 << CS22;

	// Set OCR0A register to generate 50% duty cycle
	OCR0A = 10;	// 255 is max duty cycle
}

void set_duty_precent(int precent)
{
	int duty = (int)(2.55 * precent);
	OCR2A = duty;
}

void set_duty_8bit(uint8_t duty)
{
	OCR2A = duty;
}