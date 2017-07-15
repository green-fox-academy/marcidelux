#ifndef __ADC_H
#define  __ADC_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "cmsis_os.h"

/* Exported functions ------------------------------------------------------- */
void adc_init();
void led_matrix_delay_adc_thread(void const *argument);

osMessageQId  MsgBox;

#endif /* __ADC_H */
