/*
 * Timer.c
 *
 * Created: 2017. 06. 13. 11:32:43
 *  Author: Marci
 */ 

void Timer_init()
{
	// Set the prescaler to 1024 division.
	// With this you also set the clock source to CLK_io and you will also turn on the timer!
	
	TCCR0B |= 1 << CS02;
	TCCR0B |= 1 << CS00;

	// Enable the TC0 overflow interrupt
	TIMSK0 |= 1 << TOIE0;
	TIMSK0 |= 1 << TOIE0;	
}