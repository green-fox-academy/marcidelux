/*
 * rtc_test.c
 *
 * Created: 2017. 07. 06. 14:18:35
 * Author : Marci
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#define F_CPU 16000000U

void led_blinker (void);
void init_led(void);

volatile uint16_t cntr = 0;
volatile const uint16_t cntr_max = 1000;
uint16_t x = 50; //overflow num. from current position to 0 position
uint16_t y = 20; //overflow num. to light
uint16_t z = 50; //overflow num. between 2 lines
uint8_t show_line = 3; //num. of lines

ISR(TIMER0_OVF_vect)
{
	if (cntr < cntr_max) {
		cntr++;
		} else {
		cntr = 0;
}
	led_blinker();
	
}

int main(void)
{
	init_led();
	//PORTB |= 1<< PORTB5;
	
    while (1) 
    {

    }
}

void init_led(void)
{
	// init interrupt, timer0
	//PCMSK0 |= 1 << PCINT5; //pcint5 -> pb5 pin
	DDRB |= 1 << DDRB5;
	//PCICR |= 1 << PCIE0; //pin change interrupt 0 is enabled
	TIMSK0 |= 1 << TOIE0;
	TCCR0B |= 1 << CS00;	//timer1 prescaler 256
	sei();
}

void led_blinker (void)
{
	for (int i = 0; i < show_line; i++) {
		if (cntr == (x + (i * y) + (i * z))) {
			PORTB &= ~(1 << PORTB5);
			break;
			} else if (cntr == (x + ((i + 1) * y) + (i * z))) {
			PORTB |= 1 << PORTB5;
			break;
		}
	}
}