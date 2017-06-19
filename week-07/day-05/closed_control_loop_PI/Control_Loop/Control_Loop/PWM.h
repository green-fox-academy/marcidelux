#ifndef PWM_H_
#define PWM_H_

#include <stdint.h>
void PWM_init();
void set_duty_precent(int precent);
void set_duty_10bit(uint16_t int10);
void set_duty_8bit(uint8_t int8);
void set_duty_rpm(float rpm_in);

#endif /* PWM_H_ */