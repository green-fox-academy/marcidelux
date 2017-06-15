#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "freq_meas.h"

static volatile uint16_t tick_count = 0;
static volatile uint16_t tick_counted = 0;
static volatile uint16_t tick_prev = 0;
static volatile uint16_t tick_now = 0;

// TODO:
// Write the interrupt handlers

ISR(TIMER1_CAPT_vect)
{
	tick_counted = tick_count;
	tick_count = 0;
	tick_prev = tick_now;
	tick_now = ICR1;
}

ISR(TIMER1_OVF_vect)
{
	tick_count++;
}

void freq_meas_init()
{
	/**************
	 * TC1 CONFIG *
	 **************/
	// TODO:
	// Configure the TC1 timer properly :)
	
	//Set prescale to 64
	TCCR1B |= 0b011;
	
	//Enable owerflow interrupt - TIFR1 / TOV1 bit is the flag
	TIMSK1 |= 1 << TOIE1;
	
	//Enable Capture Interupt - TIFR1 / ICF1 bit is the flag
	TIMSK1 |= 1 << ICIE1;
	
	//Enable both interupts
	//TIMSK1 = 0b100001;
	
}

// TODO:
// Write this function. It returns the measured frequency in Hz
float get_freq()
{
	cli();
	uint16_t prev = tick_prev;
	uint16_t now = tick_now;
	uint16_t tick = tick_counted;
	sei();
	
	uint32_t diff = (uint32_t)now - (uint32_t)prev;
	
	uint32_t steps = (uint32_t)tick * 65535 + diff;
	
	float peroid = 0.000004 * (float)steps;
	float freq = 1 / peroid;
	
	return freq;
}