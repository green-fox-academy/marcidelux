/*
 * AC_driver.c
 *
 * Created: 2017. 06. 13. 16:04:13
 *  Author: Marci
 */ 

#include <avr/io.h>
#include "AC_driver.h"
#include "freq_meas.h"
#include "freq_meas.h"

volatile float rpm;

void AC_driver_init()
{
	/*************
	 * AC CONFIG *
	 *************/
	// TODO:
	// Disable the digital input buffers on AN0 and AN1 to reduce power consumption.
	// See the DIDR1 register description for more info.
	DIDR1 |= 0b11;

	// TODO:
	// Connect the AC output to the AC0 pin.
	// The datasheet if screwed up. It says "Analog Comparator Control and Status Register C", meanwhile the name of this register is "ACSR0",
	// but in the avr/io.g header this register can be reached with the "ACSRB" macro.
	ACSRB = 1;

	// TODO:
	// Configure the rest settings properly :)
	// AC output connected to TC1 input capture
	
	//Set it to analog comparator
	ADCSRB |= 1;
	
	//Analog comparator Input Capture Enable
	ACSR |= 1 << ACIC;
	
	
}

// TODO:
// Write this function. It returns the measured rotation speed in RPM
float get_rpm()
{
	rpm = 60 / 7 * get_freq();
	return rpm;
}