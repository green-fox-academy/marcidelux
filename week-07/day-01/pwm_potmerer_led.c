#include <avr/io.h>
#include <util/delay.h>
#include "ADC_driver.h"

void pwm_init()
{
	TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);
	
	TCCR0B |= 0b101;

	DDRD |= 1 << DDRD6;
	
}


int main(void)
{
	pwm_init();
	ADC_init();
	
	uint8_t brightness;

while (1)
{
	OCR0A = ADC_read()/4;
	_delay_ms(100);
}

}