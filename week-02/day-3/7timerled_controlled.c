#include <avr/io.h>
#include <stdint.h>

void init()
{
	// Set the prescaler to 1024 division. See at the TC0 control register in the datasheet!
	// With this you also set the clock source to CLK_io and you will also turn on the timer!
	TCCR0B |= 1 << CS02;
	TCCR0B |= 1 << CS00;

	// Set the PB5 LED pin to output
	DDRB = 1 << DDRB5;
}

int main(void)
{
	uint8_t cunter = 0;				// Create a variable which will be a counter variable, initialize it with 0.
	const uint8_t cntr_max = 2;	// This will be the maximal value of our counter
	init();							// Don't forget to call the init function!

	while (1)
	{
		if ( (TIFR0 & 1<<TOV0) == 1)
		{
			TIFR0 |= 1<<TOV0;
			if (cunter<=cntr_max)
			{
				cunter++;
				}else{
				PINB |= 1<<PINB5;
				cunter=0;
			}
		}
		// Check the TOV0 overflow flag. If an overflow happened do the following:
		//	- clear the overflow flag
		//  - check the counter variable
		//		- if it is smaller than the maximal value, than increment it!
		//		- else set it to 0, and toggle the LED

	}
}

