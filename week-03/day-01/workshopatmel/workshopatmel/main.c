#include <avr/io.h>			// This header contains the definitions for the io registers
#include <stdint.h>
#include <stdio.h>
#define F_CPU	16000000	// This definition tells to _delay_ms() that the CPU runs at 16MHz
#include <util/delay.h>		// This header contains the _delay_ms() function
#include <string.h>

void palindrome(void);


void UART_Init()
{
	// Set the baud rate to 9600
	// The CPU clock frequency is 16MHz
	UBRR0H = 103 >> 8;
	UBRR0L = 103;

	// Frame format: 8N1

	// Enable TX and RX
	UCSR0B |= (1<<TXEN0);
	UCSR0B |= (1<<RXEN0);
}

void LED_init() {
	// Set PORTB5 to output
	DDRD |= 1 << DDRD1;
	DDRD |= 1 << DDRD2;
	DDRD |= 1 << DDRD3;
	DDRD |= 1 << DDRD4;
	DDRD |= 1 << DDRD5;

}

void UART_SendCharacter(char character)
{
	// Wait for empty buffer
	while (!( UCSR0A & (1<<UDRE0)));

	// Put data to buffer
	UDR0 = character;
}

char UART_GetCharacter()
{
	// Wait for data received
	while (!(UCSR0A & (1<<RXC0)));
	
	// Get data from buffer
	return UDR0;
}



int main(void)
{
	char buffer[255];

	//Init
	UART_Init();
	LED_init();

	// Setting up STDIO input and output buffer
	//----- START OF STDIO IO BUFFER SETUP
	FILE UART_output = FDEV_SETUP_STREAM(UART_SendCharacter, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_GetCharacter, _FDEV_SETUP_READ);
	stdin = &UART_input;
	//----- END OF STDIO IO BUFFER SETUP

	// wait for an enter -- Linux
	puts("Let it begins");

	// Loop that runs forever
	while (1) {
		
	for (int i=0; i<6; i++)
	{
		_delay_ms(20);
		PIND |= 1<<i;
		_delay_ms(20);
	}

	}
	return 0;
}


