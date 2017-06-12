
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "ADC_driver.h"
#include "UART_driver.h"
#include <avr/interrupt.h>
#include <string.h>

	uint8_t brightness = 1;
	char input_str[12];

void pwm_init()
{
	TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);
	
	TCCR0B |= 0b101;

	DDRD |= 1 << DDRD6;
	
}

ISR(USART_RX_vect){
	gets(input_str);
	brightness = atoi(input_str);
}


int main(void)
{
	pwm_init();
	ADC_init();
	UART_init();
	sei();
	
	FILE UART_output = FDEV_SETUP_STREAM(UART_send_character, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_get_character, _FDEV_SETUP_READ);
	stdin = &UART_input;
	
	

while (1)
{
	OCR0A = brightness;
	_delay_ms(10);
	
}

}

