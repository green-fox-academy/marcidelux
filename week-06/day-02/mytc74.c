#include <avr/io.h>
#include <string.h>
#include <stdint.h>
#include "TC74_driver.h"

void TWI_init(void)
{
	// TODO:
	// Set Prescaler to 4
	TWSR |= 1 << TWPS0;
	TWSR &= ~(1 << TWPS1);

	// TODO:
	// Set SCL frequency = 16000000 / (16 + 2 * 48 * 4) = 40Khz
	//So set the correct register to 0x30
	
	TWBR = 0x30;
	
	// TODO
	//Enable TWI
	TWCR |= 1 << TWEN;

}

void TWI_start(void)
{
	//TODO
	//Send start signal
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	// TODO:
	// Wait for TWINT Flag set. This indicates that
	//the START condition has been transmitted.
	while (!(TWCR & (1 << TWINT)));

}

void TWI_stop(void)
{
	//TODO
	//Send stop signal
	
	TWCR = (1 << TWEN) | (1 << TWSTO); // (1 << TWINT) | <- deleted
}

uint8_t TWI_read_ack(void)
{
	//TODO
	//Read byte with ACK
	//Wait for TWINT Flag set. This indicates that
	//the DATA has been transmitted, and ACK/
	//NACK has been received.
	
	TWCR |= (1 << TWINT) | (1 <<TWEA); //  | (1 << TWEN) <-deleted
	while (!(TWCR & (1 << TWINT)));
	
	return TWDR;

}


uint8_t TWI_read_nack(void)
{
	//TODO
	//Read byte with NACK
	//Wait for TWINT Flag set. This indicates that
	//the DATA has been transmitted, and ACK/
	//NACK has been received.
	TWCR |= 1 << TWINT; //  | (1 << TWEN) <- deleted
	
	while (!(TWCR & (1 << TWINT)));
	
	return TWDR;
	
}

void TWI_write(uint8_t u8data)
{
	//TODO
	//Load DATA into TWDR Register. Clear TWINT
	//bit in TWCR to start transmission of data.
	TWDR = u8data;
	
	TWCR |= (1 << TWINT) | (1 << TWEN);
	
	//Wait for TWINT Flag set. This indicates that
	//the DATA has been transmitted, and ACK/
	//NACK has been received.
	while (!(TWCR & (1 << TWINT)));
}

//TODO
//Write a function that communicates with the TC74A0.
//The function need to be take the address of the ic as a parameter.
//datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/21462D.pdf
//And returns with the temperature.

uint8_t TC74_Get_Temp(uint8_t adress)
{
	uint8_t data;
	uint8_t rw_adress = adress << 1;;
	
	// Send the start signal
	TWI_start();
	
	//Add write bit to the adress then send it. 
	TWI_write(rw_adress);
	
	// Set mode to 00 - RTR - Read temperature
	TWI_write(0x00);
	
	//Start again
	TWI_start();
	
	//Add read bit to adress then send it.
	rw_adress |= 0x01;
	TWI_write(rw_adress);
	
	// Load data 
	data = TWI_read_nack();
	
	//Stop
	TWI_stop();
	
	return data;
}


//TODO Advanced:
//Calculate the average of the last 16 data, and returns with that.
//TODO Advanced+:
//Select the outstanding (false data) before average it.
//These data don't needed, mess up your datas, get rid of it.