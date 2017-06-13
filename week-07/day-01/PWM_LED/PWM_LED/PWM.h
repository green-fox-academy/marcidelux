#ifndef PWM
#define PWM

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>

//Set Fast PWM modes
#define FAST_PWM 0b11
#define PHASE_CORRECT 0b01


//PWM etc
#define NORMAL 0 //~(0b11000000)
#define TOGGLE_COMPARE 0b01000000
#define CLEAR_OC0A 0b10000000 // Non inverted mode
#define SET_OC0A 0b11000000	//Inverted mode



void pwm_init();

#ifdef __cplusplus
}
#endif

#endif // PWM
