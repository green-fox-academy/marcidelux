

#ifdef _WIN32

#include "PWM.h"

#include <stdio.h>
#include <string.h>

void pwm_init()
{
	//Set it to fast pwm
	TCCR0A |= FAST_PWM;
	//Set it to non converted mode
	TCCR0A |= CLEAR_OC0A;
	
	// This is the Output Compare 0 A
	DDRD |= 1 << DDRD6; 
	
}

#endif // _WIN32
